#ifndef TARTAK_HELPERS_H
#define TARTAK_HELPERS_H

#include <iostream>
#include <limits>


std::string toLowercase(const std::string &inputString);

std::string readString(const std::string &message = "", std::istream &in = std::cin);

bool readYesOrNo(const std::string &message = "", std::istream &in = std::cin);

#endif //TARTAK_HELPERS_H
