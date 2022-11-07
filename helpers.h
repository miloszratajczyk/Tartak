#ifndef TARTAK_HELPERS_H
#define TARTAK_HELPERS_H

#include <iostream>
#include <limits>

/// Returns a lowercase version of given string
std::string toLowercase(const std::string &inputString);

/// Returns user input string with optional message
std::string readString(const std::string &message = "", std::istream &in = std::cin);

/// Returns line of user input  with optional message
std::string readLine(const std::string &message = "", std::istream &in = std::cin);

/// Returns user input bool with optional message
bool readYesOrNo(const std::string &message = "", std::istream &in = std::cin);

#endif //TARTAK_HELPERS_H
