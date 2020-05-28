#include <algorithm>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <iostream>

const unsigned int E_MAGIC_LENGTH = 2;
const char E_MAGIC[E_MAGIC_LENGTH] = {'M', 'Z'};

const unsigned int E_LFANEW_OFFSET = 0x3C;

const unsigned int M_MAGIC_LENGTH = 4;
const char M_MAGIC[M_MAGIC_LENGTH] = {'P', 'E', '\0', '\0'};

const unsigned int M_NUM_SECTIONS_OFFSET = 0x06, M_OPT_H_SIZE_OFFSET = 0x14;
const unsigned int PE_HEADER_SIZE = 24;

const unsigned int SECTION_HEADER_SIZE = 40;
const unsigned int M_DATA_SIZE_OFFSET = 0x10, M_DATA_PTR_OFFSET = 0x14, M_CNT_OFFSET = 0x24;
const unsigned int IMAGE_SCN_CNT_CODE = 0x20;

const unsigned int BUFFER_LENGTH = 8192;
char buffer[BUFFER_LENGTH];

bool bigEndian() {
    unsigned int a = 1;
    std::uint8_t *ap = (std::uint8_t *)(void *)&a;
    if(((int)*ap) == 1)
        return false;
    return true;
}

void reverseBytesN(void *data, int n) {
    std::uint8_t *bp = (std::uint8_t *)data;
    for(int i = 0; i < n / 2; i++)
        std::swap(bp[i], bp[n - i - 1]);
}

void reverseBytes16(std::uint16_t &n) {
    reverseBytesN(&n, 2);
}

void reverseBytes32(std::uint32_t &n) {
    reverseBytesN(&n, 4);
}

void reverseBytes64(std::uint64_t &n) {
    reverseBytesN(&n, 8);
}

std::string inputFile, outputFile;
std::ifstream inputStream;
std::ofstream outputStream;
bool quiet = false, reverseBytes = false;

void help(std::ostream &stream, const std::string programName) {
    stream << "Usage: " << programName << " [options] file\n\n";

    stream << "Options:\n";
    stream << "--help,         -h      - Display this help and exit.\n";
    stream << "--output=file,  -o file - Specify output file.\n";
    stream << "--quiet,        -q      - Quiet mode (no standard output).\n";
}

int main(int argc, char **argv) {
    bool parseOptions = true;

    for(int i = 1; i < argc; i++) {
        if(parseOptions) {
            if(!std::strcmp(argv[i], "--")) {
                parseOptions = false;
                continue;
            }
            if(!std::strncmp(argv[i], "--output", 8)) {
                if(outputFile != "") {
                    std::cerr << argv[0] << ": duplicate option: --output/-o\n\n";
                    return -1;
                }
                if(argv[i][8] != '=' || argv[i][9] == '\0') {
                    std::cerr << argv[0] << ": option --output requires a value\n\n";
                    help(std::cerr, argv[0]);
                    return -1;
                }
                outputFile = argv[i] + 9;
                continue;
            }
            if(!(std::strcmp(argv[i], "--help") && std::strcmp(argv[i], "-h"))) {
                help(std::cout, argv[0]);
                return 0;
            }
            if(!std::strcmp(argv[i], "-o")) {
                if(outputFile != "") {
                    std::cerr << argv[0] << ": duplicate option: --output/-o\n\n";
                    return -1;
                }
                if(i == argc - 1) {
                    std::cerr << argv[0] << ": option -o requires a value\n\n";
                    help(std::cerr, argv[0]);
                    return -1;
                }
                outputFile = argv[++i];
                continue;
            }
            if(!(std::strcmp(argv[i], "--quiet") && std::strcmp(argv[i], "-q"))) {
                quiet = true;
                continue;
            }
            if(argv[i][0] == '-') {
                std::cerr << argv[0] << ": unknown option: " << argv[i] << "\n\n";
                help(std::cerr, argv[0]);
                return -1;
            }
        }

        if(inputFile != "") {
            std::cerr << argv[0] << ": too many arguments\n\n";
            help(std::cerr, argv[0]);
            return -1;
        }
        inputFile = argv[i];
    }

    if(inputFile == "") {
        std::cout << "Please enter the name/path of the input file\n";
        do {
            std::cout << "> ";
            std::getline(std::cin, inputFile);
        }
        while(inputFile == "");
    }
    if(outputFile == "")
        outputFile = argv[0] + (std::string)".out";

    inputStream = std::ifstream(inputFile, std::ios::binary);
    outputStream = std::ofstream(outputFile, std::ios::binary);

    if(!quiet)
        std::cout << std::showbase;

    char e_magic_in[E_MAGIC_LENGTH];
    inputStream.read(e_magic_in, E_MAGIC_LENGTH);
    if(std::strncmp(e_magic_in, E_MAGIC, E_MAGIC_LENGTH)) {
        std::cerr << argv[0] << ": unknown file format\n";
        inputStream.close();
        outputStream.close();
        return -1;
    }

    inputStream.seekg(E_LFANEW_OFFSET);
    std::uint32_t e_lfanew;
    inputStream.read((char *)&e_lfanew, 4);

    reverseBytes = bigEndian();

    char m_magic_in[M_MAGIC_LENGTH];
    inputStream.seekg(e_lfanew);
    inputStream.read(m_magic_in, M_MAGIC_LENGTH);
    if(std::strncmp(m_magic_in, M_MAGIC, M_MAGIC_LENGTH)) {
        std::cerr << argv[0] << ": unknown file format\n";
        inputStream.close();
        outputStream.close();
        return -1;
    }

    if(!quiet)
        std::cout << "File " << inputFile << " is in PE32/PE64 format" << std::endl;

    std::uint16_t m_num_sections;
    inputStream.seekg(e_lfanew + M_NUM_SECTIONS_OFFSET);
    inputStream.read((char *)&m_num_sections, 2);
    if(reverseBytes)
        reverseBytes16(m_num_sections);

    std::uint16_t m_opt_h_size;
    inputStream.seekg(e_lfanew + M_OPT_H_SIZE_OFFSET);
    inputStream.read((char *)&m_opt_h_size, 2);
    if(reverseBytes)
        reverseBytes16(m_opt_h_size);

    if(!quiet)
        std::cout << std::endl << "File " << inputFile << " contains " << m_num_sections
                  << " sections" << std::endl << std::endl;

    int sec = 0;
    for(std::uint64_t i = 0; i < m_num_sections; i++) {
        std::uint32_t m_data_size;
        inputStream.seekg(e_lfanew + PE_HEADER_SIZE + m_opt_h_size + i * SECTION_HEADER_SIZE
                                   + M_DATA_SIZE_OFFSET);
        inputStream.read((char *)&m_data_size, 8);
        if(reverseBytes)
            reverseBytes32(m_data_size);

        std::uint32_t m_data_ptr;
        inputStream.seekg(e_lfanew + PE_HEADER_SIZE + m_opt_h_size + i * SECTION_HEADER_SIZE
                                   + M_DATA_PTR_OFFSET);
        inputStream.read((char *)&m_data_ptr, 8);
        if(reverseBytes)
            reverseBytes32(m_data_ptr);

        std::uint32_t m_cnt;
        inputStream.seekg(e_lfanew + PE_HEADER_SIZE + m_opt_h_size + i * SECTION_HEADER_SIZE
                                   + M_CNT_OFFSET);
        inputStream.read((char *)&m_cnt, 8);
        if(reverseBytes)
            reverseBytes32(m_cnt);

        if(!(m_cnt & IMAGE_SCN_CNT_CODE)) {
            if(!quiet)
                std::cout << "Section " << std::dec << i << ": not executable" << std::endl;
            continue;
        }

        if(!quiet)
            std::cout << "Section " << std::dec << i << ": executable, offset=" << std::hex
                      << m_data_ptr << ", size=" << m_data_size << std::endl;
        sec++;

        inputStream.seekg(m_data_ptr);
        while(m_data_size > BUFFER_LENGTH) {
            inputStream.read(buffer, BUFFER_LENGTH);
            outputStream.write(buffer, BUFFER_LENGTH);
            m_data_size -= BUFFER_LENGTH;
        }
        inputStream.read(buffer, m_data_size);
        outputStream.write(buffer, m_data_size);
    }

    if(!quiet)
        std::cout << std::endl << "Found " << std::dec << sec
                  << " sections containing executable code" << std::endl;

    inputStream.close();
    outputStream.close();
    return 0;
}
