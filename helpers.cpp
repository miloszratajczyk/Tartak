#include "helpers.h"

/// Returns a lowercase version of given string
std::string toLowercase(const std::string &inputString) {
    std::string outputString;
    for (auto c: inputString)
        outputString += tolower(c);
    return outputString;
}

/// Returns user input string with optional message
std::string readString(const std::string &message, std::istream &in) {
    std::cout << message;
    std::string input;
    in >> input;
    return input;
}

/// Returns line of user input  with optional message
std::string readLine(const std::string &message, std::istream &in) {
    std::cout << message;
    std::string input;
    in.clear();
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(in, input);
    return input;
}

/// Returns user input bool with optional message
bool readYesOrNo(const std::string &message, std::istream &in) {
    std::cout << message;
    char input;
    in >> input;
    return tolower(input) == 'y';
}