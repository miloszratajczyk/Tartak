#ifndef TARTAK_CATEGORIES_H
#define TARTAK_CATEGORIES_H

#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

class Categories {

    // Set of available  categories
    set<string> categories;

    // Adds inputted category to `categories` set
    void addCategory();

    // Removes inputted category from `categories` set
    void removeCategory();

    // Capitalizes only the first letter to avoid repetition
    static string toCategoryFormat(string givenName);

public:
    /// Returns a category selected by the user
    /// with ability to add and remove categories
    string selectCategory();

    /// Returns a string with all data
    /// used for saving and loading
    string toDataString();

    /// Adds all categories from given string
    void fromDataString(const string &data);
};


#endif //TARTAK_CATEGORIES_H
