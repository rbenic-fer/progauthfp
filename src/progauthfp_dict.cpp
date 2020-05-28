#include <cmath>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class BitString {
public:
    std::vector<char> bytes;
    int bitIndex;

    BitString(): bytes(0), bitIndex(8) {}

    void addBit(int bit) {
        if(bitIndex == 8) {
            bytes.push_back(0);
            bitIndex = 0;
        }
        if(bit & 1)
            (*bytes.rbegin()) ^= (1 << bitIndex);
        bitIndex++;
    }

    int getBit(int idx) const {
        return (bytes[idx >> 3] >> (idx & 7)) & 1;
    }

    std::size_t size() const {
        return ((bytes.size() - 1) << 3) + bitIndex;
    }
};

bool operator==(const BitString &s1, const BitString &s2) {
    if(s1.bytes.size() != s2.bytes.size())
        return false;
    if(s1.bitIndex != s2.bitIndex)
        return false;
    for(std::size_t i = 0; i < s1.bytes.size(); i++)
        if(s1.bytes[i] != s2.bytes[i])
            return false;
    return true;
}

bool operator!=(const BitString &s1, const BitString &s2) {
    if(s1.bytes.size() != s2.bytes.size())
        return true;
    if(s1.bitIndex != s2.bitIndex)
        return true;
    for(std::size_t i = 0; i < s1.bytes.size(); i++)
        if(s1.bytes[i] != s2.bytes[i])
            return true;
    return false;
}

std::ostream &operator<<(std::ostream &stream, const BitString &s) {
    std::size_t n = s.size();
    for(std::size_t i = 0; i < n; i++)
        stream << s.getBit(i);
    return stream;
}

class BitStringHash {
public:
    std::size_t operator()(const BitString &bitString) const {
        std::size_t n = bitString.size(), sol = 0;
        for(std::size_t i = 0; i < n; i++)
            sol = 10007 * sol + bitString.getBit(i);
        return sol;
    }
};

typedef std::unordered_map<BitString, int, BitStringHash> BitStringMap;

class BinaryInstruction {
public:
    BitString opCode;
    std::vector<BitString> arguments;

    void addArgument(const BitString &argument) {
        arguments.push_back(argument);
    }
};

class BinaryInstructionFormat {
public:
    std::string str;

    BinaryInstructionFormat() {}

    BinaryInstructionFormat(const std::string &_str): str(_str) {}

    std::size_t size() const {
        return str.size();
    }

    bool match(const BitString &bitString) const {
        if(bitString.size() != str.size())
            return false;
        for(std::size_t i = 0; i < str.size(); i++) {
            int bit = bitString.getBit(i);
            if((!bit && (str[i] == '1' || str[i] == '+'))
               || (bit && (str[i] == '0' || str[i] == '-')))
                return false;
        }
        return true;
    }

    bool matchString(const std::string &str2) const {
        if(str2.size() != str.size())
            return false;
        for(std::size_t i = 0; i < str.size(); i++)
            if(((str[i] == '0' || str[i] == '-') && (str2[i] == '1' || str2[i] == '+'))
               || ((str[i] == '1' || str[i] == '+') && (str2[i] == '0' || str2[i] == '-')))
                return false;
        return true;
    }

    BinaryInstruction parseInstruction(const BitString &bitString) const {
        BinaryInstruction sol;
        int argIndex = -1;
        for(std::size_t i = 0; i < str.size(); i++) {
            int bit = bitString.getBit(i);
            if(str[i] == '0' || str[i] == '1')
                sol.opCode.addBit(bit);
            else if(str[i] != '-' && str[i] != '+') {
                if(!i || str[i - 1] != str[i]) {
                    sol.addArgument(BitString());
                    argIndex++;
                }
                sol.arguments[argIndex].addBit(bit);
            }
        }
        return sol;
    }
};

class SimplifiedInstruction {
public:
    int opCode;
    std::vector<int> arguments;

    void addArgument(int argument) {
        arguments.push_back(argument);
    }
};

bool operator!=(const SimplifiedInstruction &i1, const SimplifiedInstruction &i2) {
    if(i1.opCode != i2.opCode)
        return true;
    if(i1.arguments.size() != i2.arguments.size())
        return true;
    for(std::size_t i = 0; i < i1.arguments.size(); i++)
        if(i1.arguments[i] != i2.arguments[i])
            return true;
    return false;
}

class SimplifiedInstructionHash {
public:
    std::size_t operator()(const SimplifiedInstruction &inst) const {
        std::size_t sol = inst.opCode;
        for(std::size_t i = 0; i < inst.arguments.size(); i++)
            sol = 10007 * sol + inst.arguments[i];
        return sol;
    }
};

std::vector<BitString> opCodes;
BitStringMap opCodeMap;

std::ostream &operator<<(std::ostream &stream, const SimplifiedInstruction &inst) {
    stream << opCodes[inst.opCode];
    for(std::size_t i = 0; i < inst.arguments.size(); i++)
        stream << ' ' << inst.arguments[i];
    return stream;
}

class InstructionPattern {
public:
    std::vector<SimplifiedInstruction> instructions;

    InstructionPattern(): instructions() {}

    InstructionPattern(const std::vector<BinaryInstruction> &arr, int st, int en):
        instructions()
    {
        BitStringMap argMap;
        int argCount = 0;
        for(int i = st; i < en; i++) {
            instructions.push_back(SimplifiedInstruction());

            BitStringMap::iterator mapEntry = opCodeMap.find(arr[i].opCode);
            if(mapEntry == opCodeMap.end()) {
                opCodeMap[arr[i].opCode] = opCodes.size();
                (*instructions.rbegin()).opCode = opCodes.size();
                opCodes.push_back(arr[i].opCode);
            }
            else
                (*instructions.rbegin()).opCode = mapEntry -> second;

            for(std::size_t j = 0; j < arr[i].arguments.size(); j++) {
                mapEntry = argMap.find(arr[i].arguments[j]);
                if(mapEntry == argMap.end()) {
                    argMap[arr[i].arguments[j]] = argCount;
                    (*instructions.rbegin()).addArgument(argCount);
                    argCount++;
                }
                else
                    (*instructions.rbegin()).addArgument(mapEntry -> second);
            }
        }
    }

    std::size_t size() const {
        return instructions.size();
    }

    bool match(std::vector<BinaryInstruction> arr, std::size_t st) const {
        if(arr.size() - st < instructions.size())
            return false;

        std::vector<BitString> args;
        for(std::size_t i = 0; i < instructions.size(); i++) {
            BitStringMap::iterator mapEntry = opCodeMap.find(arr[st + i].opCode);
            if(mapEntry == opCodeMap.end() || (mapEntry -> second) != instructions[i].opCode)
                return false;

            for(std::size_t j = 0; j < instructions[i].arguments.size(); j++) {
                if(args.size() <= (std::size_t)instructions[i].arguments[j])
                    args.resize(instructions[i].arguments[j] + 1);

                if(args[instructions[i].arguments[j]] == BitString())
                    args[instructions[i].arguments[j]] = arr[st + i].arguments[j];
                else if(args[instructions[i].arguments[j]] != arr[st + i].arguments[j])
                    return false;
            }
        }
        return true;
    }
};

bool operator<(const InstructionPattern &p1, const InstructionPattern &p2) {
    return p1.instructions.size() < p2.instructions.size();
}

bool operator==(const InstructionPattern &p1, const InstructionPattern &p2) {
    if(p1.instructions.size() != p2.instructions.size())
        return false;
    for(std::size_t i = 0; i < p1.instructions.size(); i++)
        if(p1.instructions[i] != p2.instructions[i])
            return false;
    return true;
}

std::ostream &operator<<(std::ostream &stream, const InstructionPattern &pat) {
    for(std::size_t i = 0; i < pat.instructions.size(); i++)
        stream << pat.instructions[i] << '\n';
    return stream;
}

typedef std::unordered_map<char, int> CharMap;

InstructionPattern parsePattern(const std::vector<std::string> strings,
                                const std::vector<BinaryInstructionFormat> &formats)
{
    InstructionPattern sol;
    CharMap charMap;
    for(std::size_t i = 0; i < strings.size(); i++) {
        sol.instructions.push_back(SimplifiedInstruction());
        for(std::size_t j = 0; j < formats.size(); j++)
            if(formats[j].matchString(strings[i])) {
                int argIndex = 0;
                BitString opCode;

                for(std::size_t k = 0; k < formats[j].str.size(); k++) {
                    if(formats[j].str[k] == '0')
                        opCode.addBit(0);
                    else if(formats[j].str[k] == '1')
                        opCode.addBit(1);
                    else if(formats[j].str[k] != '-' && formats[j].str[k] != '+'
                            && (!k || formats[j].str[k - 1] != formats[j].str[k]))
                    {
                        CharMap::const_iterator mapEntry = charMap.find(strings[i][k]);
                        if(mapEntry == charMap.end()) {
                            charMap[strings[i][k]] = argIndex;
                            (*sol.instructions.rbegin()).addArgument(argIndex);
                            argIndex++;
                        }
                        else
                            (*sol.instructions.rbegin()).addArgument(mapEntry -> second);
                    }
                }

                BitStringMap::iterator mapEntry = opCodeMap.find(opCode);
                if(mapEntry == opCodeMap.end()) {
                    opCodeMap[opCode] = opCodes.size();
                    (*sol.instructions.rbegin()).opCode = opCodes.size();
                    opCodes.push_back(opCode);
                }
                else
                    (*sol.instructions.rbegin()).opCode = mapEntry -> second;
                break;
            }
    }
    return sol;
}

class InstructionPatternHash {
public:
    SimplifiedInstructionHash instructionHash;

    std::size_t operator()(const InstructionPattern &pattern) const {
        std::size_t sol = 0;
        for(std::size_t i = 0; i < pattern.instructions.size(); i++)
            sol = 10007 * sol + instructionHash(pattern.instructions[i]);
        return sol;
    }
};

typedef std::unordered_map<InstructionPattern, int, InstructionPatternHash>
        InstructionPatternMap;

class InstructionPatternFrequencyMap {
public:
    InstructionPatternMap m;
    int n = 0;

    void add(const InstructionPattern &element) {
        m[element]++;
        n++;
    }
};

class BitInputStream {
public:
    std::ifstream inputStream;
    char byte;
    int bitIndex;

    BitInputStream(const std::string &fileName): inputStream(fileName, std::ios::binary),
                                                 byte(0), bitIndex(0)
    {}

    int getBit() {
        if(!bitIndex) {
            if(!inputStream.read((char *)&byte, 1))
                return -1;
            bitIndex = 8;
        }
        return (byte >> (--bitIndex)) & 1;
    }
};

std::vector<BinaryInstructionFormat> parseFormats(const std::string &fileName) {
    std::ifstream inputFile(fileName);
    std::vector<BinaryInstructionFormat> sol;
    while(!inputFile.eof()) {
        std::string str;
        std::getline(inputFile, str);
        if(str != "")
            sol.push_back(BinaryInstructionFormat(str));
    }
    return sol;
}

std::vector<InstructionPattern> parseDictionary(
    const std::string &fileName, const std::vector<BinaryInstructionFormat> &formats)
{
    std::ifstream inputFile(fileName);
    std::vector<InstructionPattern> sol;
    std::vector<std::string> strings;
    while(!inputFile.eof()) {
        std::string str;
        std::getline(inputFile, str);
        if(str.empty()) {
            sol.push_back(parsePattern(strings, formats));
            strings = std::vector<std::string>();
        }
        else
            strings.push_back(str);
    }
    if(!strings.empty())
        sol.push_back(parsePattern(strings, formats));
    return sol;
}

std::vector<BinaryInstruction> parseInstructions(
    std::string fileName, const std::vector<BinaryInstructionFormat> &formats)
{
    BitInputStream inputStream(fileName);
    std::vector<BinaryInstruction> sol;
    BitString bitString;
    int bit = inputStream.getBit();
    while(bit != -1) {
        bitString.addBit(bit);
        for(std::size_t i = 0; i < formats.size(); i++)
            if(formats[i].match(bitString)) {
                sol.push_back(formats[i].parseInstruction(bitString));
                bitString = BitString();
            }
        bit = inputStream.getBit();
    }
    return sol;
}

InstructionPatternFrequencyMap mapDictionaryPatterns(
    const std::vector<BinaryInstruction> &code, const std::vector<InstructionPattern> &dict)
{
    InstructionPatternFrequencyMap sol;
    std::size_t i = 0;
    while(i < code.size()) {
        for(std::size_t j = 0; j < dict.size(); j++)
            if(dict[j].match(code, i)) {
                sol.add(dict[j]);
                i += dict[j].size() - 1;
                break;
            }
        i++;
    }
    return sol;
}

typedef std::unordered_map<InstructionPattern, double, InstructionPatternHash>
        AuthorFingerprint;

AuthorFingerprint getFingerprint(const InstructionPatternFrequencyMap &map1) {
    AuthorFingerprint sol;
    for(auto it = map1.m.cbegin(); it != map1.m.cend(); it++)
        sol[it -> first] = (it -> second) / (double)map1.n;
    return sol;
}

double sampleMean(const std::vector<double> &sample) {
    double sum = 0.;
    for(std::size_t i = 0; i < sample.size(); i++)
        sum += sample[i];
    return sum / sample.size();
}

double sqr(double x) {
    return x * x;
}

double sampleVariance(const std::vector<double> &sample, double mean) {
    double sum = 0.;
    for(std::size_t i = 0; i < sample.size(); i++)
        sum += sqr(sample[i] - mean);
    return sum / (sample.size() - 1);
}

AuthorFingerprint aggregate(const std::vector<AuthorFingerprint> &v, unsigned int maxElements,
                            double minFreq, double maxFreq, double maxVariance)
{
    if(v.size() == 1)
        return v[0];

    std::priority_queue<std::pair<double, std::pair<InstructionPattern, double>>> q;
    for(std::size_t i = 0; i < v.size(); i++)
        for(auto it = v[i].cbegin(); it != v[i].cend(); it++) {
            std::size_t j;
            for(j = 0; j < i; j++)
                if(v[j].find(it -> first) != v[j].end())
                    break;

            if(j < i)
                continue;

            std::vector<double> sample(i, 0.);
            sample.push_back(it -> second);
            for(j = i + 1; j < v.size(); j++) {
                auto it2 = v[j].find(it -> first);
                if(it2 != v[j].end())
                    sample.push_back(it2 -> second);
            }

            double m = sampleMean(sample), var = sampleVariance(sample, m);
            if(m >= minFreq && m <= maxFreq && var < maxVariance) {
                q.push(std::make_pair(var, std::make_pair(it -> first, m)));
                if(q.size() > maxElements)
                    q.pop();
            }
        }

    AuthorFingerprint sol;
    while(!q.empty()) {
        std::pair<InstructionPattern, double> v = q.top().second;
        sol[v.first] = v.second;
        q.pop();
    }
    return sol;
}

std::ostream &operator<<(std::ostream &stream, const AuthorFingerprint &fp) {
    for(auto it = fp.cbegin(); it != fp.cend(); it++)
        stream << (it -> first) << (it -> second) << "\n\n";
    return stream;
}

void help(std::ostream &stream, const std::string programName) {
    stream << "Usage: " << programName << " [options] file1 file2 ... fileN\n\n";

    stream << "Options:\n";
    stream << "--dict=file,    -d file - Specify dictionary file.\n";
    stream << "--elements=num, -e num  - Limit the maximum number of output elements.\n";
    stream << "--formats=file, -f file - Specify instruction format description file.\n";
    stream << "--freq-max=x,   -R x    - Limit the maximum element frequency.\n";
    stream << "--freq-min=x,   -r x    - Limit the minimum element frequency.\n";
    stream << "--help,         -h      - Display this help and exit.\n";
    stream << "--output=file,  -o file - Specify output file.\n";
    stream << "--quiet,        -q      - Quiet mode (no standard output).\n";
    stream << "--variance=x,   -v x    - Limit the maximum frequency variance.\n";
}

const double DEFAULT_MIN_FREQ = 0., DEFAULT_MAX_FREQ = 1., DEFAULT_MAX_VARIANCE = 1.;
const unsigned int DEFAULT_MAX_ELEMENTS = (unsigned int)-1;

int main(int argc, char **argv) {
    std::vector<std::string> programFiles;
    std::string formatsFile = "", dictFile = "", outputFile = "";
    double minFreq = -1., maxFreq = -1., maxVariance = -1.;
    unsigned int maxElements = 0;
    bool quiet = false, parseOptions = true;

    for(int i = 1; i < argc; i++) {
        if(parseOptions) {
            if(!std::strcmp(argv[i], "--")) {
                parseOptions = false;
                continue;
            }
            if(!std::strncmp(argv[i], "--dict", 6)) {
                if(dictFile != "") {
                    std::cerr << argv[0] << ": duplicate option: --dict/-d\n\n";
                    return -1;
                }
                if(argv[i][6] != '=' || argv[i][7] == '\0') {
                    std::cerr << argv[0] << ": option --dict requires a value\n\n";
                    help(std::cerr, argv[0]);
                    return -1;
                }
                dictFile = argv[i] + 7;
                continue;
            }
            if(!std::strcmp(argv[i], "-d")) {
                if(dictFile != "") {
                    std::cerr << argv[0] << ": duplicate option: --dict/-d\n\n";
                    return -1;
                }
                if(i == argc - 1) {
                    std::cerr << argv[0] << ": option -d requires a value\n\n";
                    help(std::cerr, argv[0]);
                    return -1;
                }
                dictFile = argv[++i];
                continue;
            }
            if(!std::strncmp(argv[i], "--elements", 10)) {
                if(maxElements) {
                    std::cerr << argv[0] << ": duplicate option: --elements/-e\n\n";
                    return -1;
                }
                if(argv[i][10] != '=' || argv[i][11] == '\0') {
                    std::cerr << argv[0] << ": option --elements requires a value\n\n";
                    help(std::cerr, argv[0]);
                    return -1;
                }
                maxElements = std::stoul(argv[i] + 11);
                continue;
            }
            if(!std::strcmp(argv[i], "-e")) {
                if(maxElements) {
                    std::cerr << argv[0] << ": duplicate option: --elements/-e\n\n";
                    return -1;
                }
                if(i == argc - 1) {
                    std::cerr << argv[0] << ": option -e requires a value\n\n";
                    help(std::cerr, argv[0]);
                    return -1;
                }
                maxElements = std::stoul(argv[++i]);
                continue;
            }
            if(!std::strncmp(argv[i], "--formats", 9)) {
                if(formatsFile != "") {
                    std::cerr << argv[0] << ": duplicate option: --formats/-f\n\n";
                    return -1;
                }
                if(argv[i][9] != '=' || argv[i][10] == '\0') {
                    std::cerr << argv[0] << ": option --formats requires a value\n\n";
                    help(std::cerr, argv[0]);
                    return -1;
                }
                formatsFile = argv[i] + 10;
                continue;
            }
            if(!std::strcmp(argv[i], "-f")) {
                if(formatsFile != "") {
                    std::cerr << argv[0] << ": duplicate option: --formats/-f\n\n";
                    return -1;
                }
                if(i == argc - 1) {
                    std::cerr << argv[0] << ": option -f requires a value\n\n";
                    help(std::cerr, argv[0]);
                    return -1;
                }
                formatsFile = argv[++i];
                continue;
            }
            if(!std::strncmp(argv[i], "--freq-max", 10)) {
                if(maxFreq != -1.) {
                    std::cerr << argv[0] << ": duplicate option: --freq-max/-R\n\n";
                    return -1;
                }
                if(argv[i][10] != '=' || argv[i][11] == '\0') {
                    std::cerr << argv[0] << ": option --freq-max requires a value\n\n";
                    help(std::cerr, argv[0]);
                    return -1;
                }
                maxFreq = std::stod(argv[i] + 11);
                continue;
            }
            if(!std::strcmp(argv[i], "-R")) {
                if(maxFreq != -1.) {
                    std::cerr << argv[0] << ": duplicate option: --freq-max/-R\n\n";
                    return -1;
                }
                if(i == argc - 1) {
                    std::cerr << argv[0] << ": option -R requires a value\n\n";
                    help(std::cerr, argv[0]);
                    return -1;
                }
                maxFreq = std::stod(argv[++i]);
                continue;
            }
            if(!std::strncmp(argv[i], "--freq-min", 10)) {
                if(minFreq != -1.) {
                    std::cerr << argv[0] << ": duplicate option: --freq-min/-r\n\n";
                    return -1;
                }
                if(argv[i][10] != '=' || argv[i][11] == '\0') {
                    std::cerr << argv[0] << ": option --freq-min requires a value\n\n";
                    help(std::cerr, argv[0]);
                    return -1;
                }
                minFreq = std::stod(argv[i] + 11);
                continue;
            }
            if(!std::strcmp(argv[i], "-r")) {
                if(minFreq != -1.) {
                    std::cerr << argv[0] << ": duplicate option: --freq-min/-r\n\n";
                    return -1;
                }
                if(i == argc - 1) {
                    std::cerr << argv[0] << ": option -r requires a value\n\n";
                    help(std::cerr, argv[0]);
                    return -1;
                }
                minFreq = std::stod(argv[++i]);
                continue;
            }
            if(!(std::strcmp(argv[i], "--help") && std::strcmp(argv[i], "-h"))) {
                help(std::cout, argv[0]);
                return 0;
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
            if(!std::strncmp(argv[i], "--variance", 10)) {
                if(maxVariance != -1.) {
                    std::cerr << argv[0] << ": duplicate option: --variance/-v\n\n";
                    return -1;
                }
                if(argv[i][10] != '=' || argv[i][11] == '\0') {
                    std::cerr << argv[0] << ": option --variance requires a value\n\n";
                    help(std::cerr, argv[0]);
                    return -1;
                }
                maxVariance = std::stod(argv[i] + 11);
                continue;
            }
            if(!std::strcmp(argv[i], "-v")) {
                if(maxVariance != -1.) {
                    std::cerr << argv[0] << ": duplicate option: --variance/-v\n\n";
                    return -1;
                }
                if(i == argc - 1) {
                    std::cerr << argv[0] << ": option -v requires a value\n\n";
                    help(std::cerr, argv[0]);
                    return -1;
                }
                maxVariance = std::stod(argv[++i]);
                continue;
            }
            if(argv[i][0] == '-') {
                std::cerr << argv[0] << ": unknown option: " << argv[i] << "\n\n";
                help(std::cerr, argv[0]);
                return -1;
            }
        }

        programFiles.push_back(argv[i]);
    }

    if(!maxElements)
        maxElements = DEFAULT_MAX_ELEMENTS;
    if(minFreq == -1.)
        minFreq = DEFAULT_MIN_FREQ;
    if(maxFreq == -1.)
        maxFreq = DEFAULT_MAX_FREQ;
    if(maxVariance == -1.)
        maxVariance = DEFAULT_MAX_VARIANCE;
    if(formatsFile == "") {
        std::cout << "Please enter the name/path of the instruction format description file\n";
        do {
            std::cout << "> ";
            std::getline(std::cin, formatsFile);
        }
        while(formatsFile == "");
    }
    if(dictFile == "") {
        std::cout << "Please enter the name/path of the dictionary file\n";
        do {
            std::cout << "> ";
            std::getline(std::cin, dictFile);
        }
        while(dictFile == "");
    }
    if(outputFile == "")
        outputFile = argv[0] + (std::string)".out";
    if(programFiles.empty()) {
        std::cout << "Please enter the names/paths of program binary files (one per line)\n";
        std::cout << "At least one file is required. Blank line for end of input\n";

        std::string fileName = "";
        do {
            std::cout << "> ";
            std::getline(std::cin, fileName);
        }
        while(fileName == "");

        do {
            programFiles.push_back(fileName);
            std::cout << "> ";
            std::getline(std::cin, fileName);
        }
        while(fileName != "");
    }

    std::vector<BinaryInstructionFormat> formats = parseFormats(formatsFile);
    std::vector<InstructionPattern> dict = parseDictionary(dictFile, formats);
    std::vector<AuthorFingerprint> fingerprints;
    std::size_t total = 0;
    for(auto it = programFiles.begin(); it != programFiles.end(); it++) {
        AuthorFingerprint afp;
        afp = getFingerprint(mapDictionaryPatterns(parseInstructions(*it, formats), dict));
        fingerprints.push_back(afp);
        total += afp.size();
        if(!quiet)
            std::cout << (*it) << ": mapped " << afp.size() << " elements (dictionary patterns)"
                      << std::endl;
    }

    if(!quiet)
        std::cout << std::endl << "Total: " << total << std::endl;

    AuthorFingerprint sol = aggregate(fingerprints, maxElements, minFreq, maxFreq, maxVariance);

    if(!quiet)
        std::cout << std::endl << "Selected " << sol.size()
                  << " elements as stylistically significant" << std::endl;

    std::ofstream outputStream(outputFile);
    outputStream << sol;
    return 0;
}
