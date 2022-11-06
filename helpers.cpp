#include "helpers.h"

std::string toLowercase(const std::string &inputString) {
    std::string outputString;
    for (auto c: inputString)
        outputString += tolower(c);
    return outputString;
}

std::string readString(const std::string &message, std::istream &in) {
    std::cout << message;
    std::string input;
    in >> input;
    return input;
}

bool readYesOrNo(const std::string &message, std::istream &in) {
    std::cout << message;
    char input;
    in >> input;
    return tolower(input) == 'y';
}