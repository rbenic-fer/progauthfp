#include <cmath>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
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

    void clear() {
        bytes.clear();
        bitIndex = 8;
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

std::istream &operator>>(std::istream &stream, BitString &s) {
    s.clear();
    char ch;
    while((stream >> ch) && (ch == '0' || ch == '1'))
        s.addBit(ch - '0');
    return stream;
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

    void clearArguments() {
        arguments.clear();
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

std::istream &operator>>(std::istream &stream, SimplifiedInstruction &inst) {
    inst.clearArguments();

    std::string opCodeStr;
    stream >> opCodeStr;

    std::istringstream strIn(opCodeStr);
    BitString opCode;
    strIn >> opCode;

    BitStringMap::iterator mapEntry = opCodeMap.find(opCode);
    if(mapEntry == opCodeMap.end()) {
        opCodeMap[opCode] = opCodes.size();
        inst.opCode = opCodes.size();
        opCodes.push_back(opCode);
    }
    else
        inst.opCode = mapEntry -> second;

    int arg;
    while(stream >> arg)
        inst.addArgument(arg);
    return stream;
}

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

    void addInstruction(const SimplifiedInstruction &inst) {
        instructions.push_back(inst);
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

AuthorFingerprint parseFingerprint(const std::string &fileName) {
    std::ifstream inputFile(fileName);
    AuthorFingerprint sol;

    if(inputFile.eof())
        return sol;

    InstructionPattern ip;
    std::string s1;
    std::getline(inputFile, s1);
    while(!inputFile.eof()) {
        std::string s2;
        std::getline(inputFile, s2);

        std::istringstream inputString(s1);
        if(s2 == "") {
            double freq;
            inputString >> freq;
            sol[ip] = freq;

            ip = InstructionPattern();

            std::getline(inputFile, s1);
            if(inputFile.eof())
                return sol;
        }
        else {
            SimplifiedInstruction inst;
            inputString >> inst;
            ip.addInstruction(inst);

            s1 = s2;
        }
    }
    return sol;
}

AuthorFingerprint getFingerprint(const std::vector<InstructionPatternFrequencyMap> &maps) {
    AuthorFingerprint sol;
    for(std::size_t i = 0; i < maps.size(); i++)
        for(auto it = maps[i].m.cbegin(); it != maps[i].m.cend(); it++)
            sol[it -> first] = (it -> second) / (double)maps[i].n;
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

std::ostream &operator<<(std::ostream &stream, const AuthorFingerprint &fp) {
    for(auto it = fp.cbegin(); it != fp.cend(); it++)
        stream << (it -> first) << (it -> second) << "\n\n";
    return stream;
}

double fingerprintDistanceDict(const AuthorFingerprint &fp,
                               const InstructionPatternFrequencyMap &map1)
{
    double sumErrors = 0., sum = 0.;
    for(auto fpit = fp.cbegin(); fpit != fp.cend(); fpit++) {
        auto mit = map1.m.find(fpit -> first);
        if(mit == map1.m.end()) {
            sumErrors += sqr(fpit -> second);
            sum += sqr(fpit -> second);
        }
        else {
            double mfreq = (mit -> second) / (double)map1.n;

            sumErrors += sqr((fpit -> second) - mfreq);
            sum += sqr(fpit -> second) + sqr(mfreq);
        }
    }
    return sqrt(sumErrors / (fp.size() * sum));
}

void help(std::ostream &stream, const std::string programName) {
    stream << "Usage: " << programName << " [options] file\n\n";

    stream << "Options:\n";
    stream << "--confidence=x, -c x    - Specify maximum confidence threshold.\n";
    stream << "--dict=file,    -d file - Specify dictionary file.\n";
    stream << "--formats=file, -f file - Specify instruction format description file.\n";
    stream << "--help,         -h      - Display this help and exit.\n";
    stream << "--program=file, -p file - Specify program file.\n";
    stream << "--quiet,        -q      - Quiet mode (reduced amount of standard output).\n";
}

const int DEFAULT_MAX_CONFIDENCE = 0.05;

int main(int argc, char **argv) {
    std::string formatsFile = "", dictFile = "", fingerprintFile = "", programFile = "";
    double maxConfidence = -1.;
    int quiet = 0;
    bool parseOptions = true;

    for(int i = 1; i < argc; i++) {
        if(parseOptions) {
            if(!std::strcmp(argv[i], "--")) {
                parseOptions = false;
                continue;
            }
            if(!std::strncmp(argv[i], "--confidence", 12)) {
                if(maxConfidence != -1.) {
                    std::cerr << argv[0] << ": duplicate option: --confidence/-c\n\n";
                    return -1;
                }
                if(argv[i][12] != '=' || argv[i][13] == '\0') {
                    std::cerr << argv[0] << ": option --confidence requires a value\n\n";
                    help(std::cerr, argv[0]);
                    return -1;
                }
                maxConfidence = std::stod(argv[i] + 13);
                continue;
            }
            if(!std::strcmp(argv[i], "-c")) {
                if(maxConfidence != -1.) {
                    std::cerr << argv[0] << ": duplicate option: --confidence/-c\n\n";
                    return -1;
                }
                if(i == argc - 1) {
                    std::cerr << argv[0] << ": option -c requires a value\n\n";
                    help(std::cerr, argv[0]);
                    return -1;
                }
                maxConfidence = std::stod(argv[++i]);
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
            if(!(std::strcmp(argv[i], "--help") && std::strcmp(argv[i], "-h"))) {
                help(std::cout, argv[0]);
                return 0;
            }
            if(!std::strncmp(argv[i], "--program", 9)) {
                if(programFile != "") {
                    std::cerr << argv[0] << ": duplicate option: --program/-p\n\n";
                    return -1;
                }
                if(argv[i][9] != '=' || argv[i][10] == '\0') {
                    std::cerr << argv[0] << ": option --program requires a value\n\n";
                    help(std::cerr, argv[0]);
                    return -1;
                }
                programFile = argv[i] + 10;
                continue;
            }
            if(!std::strcmp(argv[i], "-p")) {
                if(programFile != "") {
                    std::cerr << argv[0] << ": duplicate option: --program/-p\n\n";
                    return -1;
                }
                if(i == argc - 1) {
                    std::cerr << argv[0] << ": option -p requires a value\n\n";
                    help(std::cerr, argv[0]);
                    return -1;
                }
                programFile = argv[++i];
                continue;
            }
            if(!(std::strcmp(argv[i], "--quiet") && std::strcmp(argv[i], "-q"))) {
                quiet++;
                continue;
            }
            if(!(std::strcmp(argv[i], "--quiet=2") && std::strcmp(argv[i], "-q2")
                 && std::strcmp(argv[i], "-qq"))) {
                quiet += 2;
                continue;
            }
            if(argv[i][0] == '-') {
                std::cerr << argv[0] << ": unknown option: " << argv[i] << "\n\n";
                help(std::cerr, argv[0]);
                return -1;
            }
        }

        fingerprintFile = argv[i];
    }

    if(maxConfidence == -1.)
        maxConfidence = DEFAULT_MAX_CONFIDENCE;
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
    if(fingerprintFile == "") {
        std::cout << "Please enter the name/path of the fingerprint file\n";

        do {
            std::cout << "> ";
            std::getline(std::cin, fingerprintFile);
        }
        while(fingerprintFile == "");
    }
    if(programFile == "") {
        std::cout << "Please enter the name/path of the program file\n";

        do {
            std::cout << "> ";
            std::getline(std::cin, programFile);
        }
        while(programFile == "");
    }

    std::vector<BinaryInstructionFormat> formats = parseFormats(formatsFile);
    std::vector<InstructionPattern> dict = parseDictionary(dictFile, formats);
    double conf = fingerprintDistanceDict(
                      parseFingerprint(fingerprintFile),
                      mapDictionaryPatterns(parseInstructions(programFile, formats), dict));

    if(!quiet) {
        std::cout << "Fingerprint " << fingerprintFile << " and program " << programFile;
        if(conf <= maxConfidence)
            std::cout << " belong to the same author\n\n";
        else
            std::cout << " belong to different authors\n\n";
        std::cout << "Confidence value: ";
    }
    if(quiet < 2)
        std::cout << conf << std::endl;

    if(conf <= maxConfidence)
        return 0;
    return 1;
}
