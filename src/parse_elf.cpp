#include <algorithm>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <iostream>

const unsigned int EI_MAG_LENGTH = 4;
const char EI_MAG[EI_MAG_LENGTH] = {0x7F, 'E', 'L', 'F'};

const unsigned int EI_CLASS_OFFSET = 0x04, EI_DATA_OFFSET = 0x05;
const std::uint8_t EI_CLASS_32 = 1, EI_CLASS_64 = 2;
const std::uint8_t EI_DATA_LITTLE_ENDIAN = 1, EI_DATA_BIG_ENDIAN = 2;
const unsigned int E_SHOFF_OFFSET_32 = 0x20, E_SHOFF_OFFSET_64 = 0x28;
const unsigned int E_SHENTSIZE_OFFSET_32 = 0x2E, E_SHENTSIZE_OFFSET_64 = 0x3A;
const unsigned int E_SHNUM_OFFSET_32 = 0x30, E_SHNUM_OFFSET_64 = 0x3C;

const unsigned int SH_FLAGS_OFFSET = 0x08;
const unsigned int SHF_EXECINSTR = 0x4;
const unsigned int SH_OFFSET_OFFSET_32 = 0x10, SH_OFFSET_OFFSET_64 = 0x18;
const unsigned int SH_SIZE_OFFSET_32 = 0x14, SH_SIZE_OFFSET_64 = 0x20;

const unsigned int BUFFER_LENGTH = 8192;
char buffer[BUFFER_LENGTH];

std::uint8_t endianness() {
    unsigned int a = 1;
    std::uint8_t *ap = (std::uint8_t *)(void *)&a;
    if(((int)*ap) == 1)
        return EI_DATA_LITTLE_ENDIAN;
    return EI_DATA_BIG_ENDIAN;
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

void main32() {
    if(!quiet)
        std::cout << "File " << inputFile << " is in 32-bit ELF format" << std::endl;

    std::uint32_t e_shoff;
    inputStream.seekg(E_SHOFF_OFFSET_32);
    inputStream.read((char *)&e_shoff, 4);
    if(reverseBytes)
        reverseBytes32(e_shoff);

    std::uint16_t e_shentsize;
    inputStream.seekg(E_SHENTSIZE_OFFSET_32);
    inputStream.read((char *)&e_shentsize, 2);
    if(reverseBytes)
        reverseBytes16(e_shentsize);

    std::uint16_t e_shnum;
    inputStream.seekg(E_SHNUM_OFFSET_32);
    inputStream.read((char *)&e_shnum, 2);
    if(reverseBytes)
        reverseBytes16(e_shnum);

    if(!quiet)
        std::cout << std::endl << "File " << inputFile << " contains " << e_shnum << " sections"
                  << std::endl << std::endl;

    int sec = 0;
    for(std::uint64_t i = 0; i < e_shnum; i++) {
        std::uint32_t sh_flags;
        inputStream.seekg(e_shoff + i * e_shentsize + SH_FLAGS_OFFSET);
        inputStream.read((char *)&sh_flags, 4);
        if(reverseBytes)
            reverseBytes32(sh_flags);

        if(!(sh_flags & SHF_EXECINSTR)) {
            if(!quiet)
                std::cout << "Section " << std::dec << i << ": not executable" << std::endl;
            continue;
        }

        std::uint32_t sh_offset;
        inputStream.seekg(e_shoff + i * e_shentsize + SH_OFFSET_OFFSET_32);
        inputStream.read((char *)&sh_offset, 4);
        if(reverseBytes)
            reverseBytes32(sh_offset);

        std::uint32_t sh_size;
        inputStream.seekg(e_shoff + i * e_shentsize + SH_SIZE_OFFSET_32);
        inputStream.read((char *)&sh_size, 4);
        if(reverseBytes)
            reverseBytes32(sh_size);

        if(!quiet)
            std::cout << "Section " << std::dec << i << ": executable, offset=" << std::hex
                      << sh_offset << ", size=" << sh_size << std::endl;
        sec++;

        inputStream.seekg(sh_offset);
        while(sh_size > BUFFER_LENGTH) {
            inputStream.read(buffer, BUFFER_LENGTH);
            outputStream.write(buffer, BUFFER_LENGTH);
            sh_size -= BUFFER_LENGTH;
        }
        inputStream.read(buffer, sh_size);
        outputStream.write(buffer, sh_size);
    }

    if(!quiet)
        std::cout << std::endl << "Found " << std::dec << sec
                  << " sections containing executable code" << std::endl;
}

void main64() {
    if(!quiet)
        std::cout << "File " << inputFile << " is in 64-bit ELF format" << std::endl;

    std::uint64_t e_shoff;
    inputStream.seekg(E_SHOFF_OFFSET_64);
    inputStream.read((char *)&e_shoff, 8);
    if(reverseBytes)
        reverseBytes64(e_shoff);

    std::uint16_t e_shentsize;
    inputStream.seekg(E_SHENTSIZE_OFFSET_64);
    inputStream.read((char *)&e_shentsize, 2);
    if(reverseBytes)
        reverseBytes16(e_shentsize);

    std::uint16_t e_shnum;
    inputStream.seekg(E_SHNUM_OFFSET_64);
    inputStream.read((char *)&e_shnum, 2);
    if(reverseBytes)
        reverseBytes16(e_shnum);

    if(!quiet)
        std::cout << std::endl << "File " << inputFile << " contains " << e_shnum << " sections"
                  << std::endl << std::endl;

    int sec = 0;
    for(std::uint64_t i = 0; i < e_shnum; i++) {
        std::uint64_t sh_flags;
        inputStream.seekg(e_shoff + i * e_shentsize + SH_FLAGS_OFFSET);
        inputStream.read((char *)&sh_flags, 8);
        if(reverseBytes)
            reverseBytes64(sh_flags);

        if(!(sh_flags & SHF_EXECINSTR)) {
            if(!quiet)
                std::cout << "Section " << std::dec << i << ": not executable" << std::endl;
            continue;
        }

        std::uint64_t sh_offset;
        inputStream.seekg(e_shoff + i * e_shentsize + SH_OFFSET_OFFSET_64);
        inputStream.read((char *)&sh_offset, 8);
        if(reverseBytes)
            reverseBytes64(sh_offset);

        std::uint64_t sh_size;
        inputStream.seekg(e_shoff + i * e_shentsize + SH_SIZE_OFFSET_64);
        inputStream.read((char *)&sh_size, 8);
        if(reverseBytes)
            reverseBytes64(sh_size);

        if(!quiet)
            std::cout << "Section " << std::dec << i << ": executable, offset=" << std::hex
                      << sh_offset << ", size=" << sh_size << std::endl;
        sec++;

        inputStream.seekg(sh_offset);
        while(sh_size > BUFFER_LENGTH) {
            inputStream.read(buffer, BUFFER_LENGTH);
            outputStream.write(buffer, BUFFER_LENGTH);
            sh_size -= BUFFER_LENGTH;
        }
        inputStream.read(buffer, sh_size);
        outputStream.write(buffer, sh_size);
    }

    if(!quiet)
        std::cout << std::endl << "Found " << std::dec << sec
                  << " sections containing executable code" << std::endl;
}

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

    char ei_mag_in[EI_MAG_LENGTH];
    inputStream.read(ei_mag_in, EI_MAG_LENGTH);
    if(std::strncmp(ei_mag_in, EI_MAG, EI_MAG_LENGTH)) {
        std::cerr << argv[0] << ": unknown file format\n";
        inputStream.close();
        outputStream.close();
        return -1;
    }

    inputStream.seekg(EI_CLASS_OFFSET);
    std::uint8_t ei_class;
    inputStream.read((char *)&ei_class, 1);

    inputStream.seekg(EI_DATA_OFFSET);
    std::uint8_t ei_data;
    inputStream.read((char *)&ei_data, 1);

    reverseBytes = (ei_data != endianness());

    switch(ei_class) {
    case EI_CLASS_32:
        main32();
        break;
    case EI_CLASS_64:
        main64();
        break;
    default:
        std::cerr << argv[0] << ": error: invalid EI_CLASS\n";
        inputStream.close();
        outputStream.close();
        return -1;
    }

    inputStream.close();
    outputStream.close();
    return 0;
}
