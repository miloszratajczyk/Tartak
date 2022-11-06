#include "categories.h"

// Adds inputted category to `categories` set
void Categories::addCategory() {
    cout << "Podaj nazwe nowej kategori: ";
    string categoryName;
    cin >> categoryName;
    categories.insert(toCategoryFormat(categoryName));
}

// Removes inputted category from `categories` set
void Categories::removeCategory() {
    cout << "Podaj nazwe kategori do usunięcia: ";
    string categoryName;
    cin >> categoryName;
    categories.erase(toCategoryFormat(categoryName));
}


// Capitalizes only the first letter to avoid repetition
string Categories::toCategoryFormat(string givenName) {
    string categoryName;
    categoryName += static_cast<char>(toupper(givenName[0]));
    for (int i = 1; i < givenName.length(); i++)
        categoryName += static_cast<char>(tolower(givenName[i]));
    return categoryName;
}

/// Returns a category selected by the user
/// with ability to add and remove categories
string Categories::selectCategory() {
    while (true) {
        int count = 1;
        cout << "\t-1. Usuń kategorię" << endl;
        cout << "\t0. Dadaj nową kategorię" << endl;
        for (const auto &category: categories)
            cout << "\t" << count++ << " " << category << endl;

        string choice;
        cin >> choice;
        int id = -100;
        try { id = stoi(choice); }
        catch (invalid_argument) { continue; }
        if (id == 0) addCategory();
        else if (id == -1) removeCategory();
        else if (id <= categories.size()) return *std::next(categories.begin(), id - 1);
    }
}

/// Returns a string with all data
/// used for saving and loading
string Categories::toDataString() {
    string result;
    for (const auto &category: categories)
        result += category + ';';
    return result;
}

/// Adds all categories from given string
void Categories::fromDataString(const string &data) {
    string t;
    for (auto c: data) {
        if (c == ';' && !t.empty()) {
            categories.insert(toCategoryFormat(t));
            t = "";
        } else { t += c; }
    }
}




