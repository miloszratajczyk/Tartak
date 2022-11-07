#include <iostream>
#include "product.h"
#include "categories.h"

using namespace std;

/// Allows user to input all product data with validation
/// when `isEditing` is set to true it will ask which fields to edit
void Product::fill(Categories *productCategories, Categories *woodCategories, bool isEditing) {
    // Inputting `name` with validation
    if (!isEditing || readYesOrNo("Nazwa produktu: " + name + " Czy edytować? y/n : ")) {
        while (true) {
            name = readLine("Podaj nazwe produktu: ");
            if (cin.fail()) cout << "Błędne dane." << endl;
            else if (name.empty()) cout << "Podaj dane." << endl;
            else break;
        }
    }

    // Inputting `productCategory`
    if (!isEditing || readYesOrNo("Kategoria produktu: " + productCategory + " Czy edytować? y/n : ")) {
        cout << "Wybierz kategorie produktu: " << endl;
        productCategory = productCategories->selectCategory();
    }

    // Inputting `woodCategory`
    if (!isEditing || readYesOrNo("Kategoria drewna: " + woodCategory + " Czy edytować? y/n : ")) {
        cout << "Wybierz kategorie drewna: " << endl;
        woodCategory = woodCategories->selectCategory();
    }

    // Inputting `color`
    if (!isEditing || readYesOrNo("Kolor produktu: " + color + " Czy edytować? y/n : ")) {
        while (true) {
            color = readLine("Podaj kolor produktu: ");
            if (cin.fail()) cout << "Błędne dane." << endl;
            else if (color.empty()) cout << "Podaj dane." << endl;
            else break;
        }
    }

    // Inputting `deliveryDate`
    if (!isEditing || readYesOrNo("Data dostawy: " + deliveryDate + " Czy edytować? y/n : ")) {
        while (true) {
            deliveryDate = readString("Podaj date dostawy w formacie rrrr-mm-dd: ");
            int year = 0, month = 0, day = 0;
            try {
                year = stoi(deliveryDate.substr(0, 4));
                month = stoi(deliveryDate.substr(5, 2));
                day = stoi(deliveryDate.substr(8, 2));
            }
            catch (invalid_argument) { continue; }

            if (cin.fail()) cout << "Błędne dane." << endl;
            else if (deliveryDate.size() != 10) cout << "Błędna długośc daty" << endl;
            else if (deliveryDate[4] != '-' || deliveryDate[7] != '-') cout << "Brakuje myślnika" << endl;
            else if (year < 2000) cout << "Błędny rok." << endl;
            else if (month < 1 || month > 12) cout << "Błędny miesiąc." << endl;
            else if (day < 1 || day > 31) cout << "Błędny dzień." << endl;
            else break;

        }
    }

    // Inputting `numberOfItems` with validation
    if (!isEditing || readYesOrNo("Liczba sztuk: " + to_string(numberOfItems) + " Czy edytować? y/n : ")) {
        while (true) {
            cout << "Podaj liczbę sztuk produktu: " << endl;
            cin >> numberOfItems;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (cin.fail()) cout << "Błędne dane." << endl;
            else if (numberOfItems <= 0) cout << "Liczba sztuk musi być dodatnia." << endl;
            else break;
        }
    }

    // Inputting `price` with validation
    if (!isEditing || readYesOrNo("Cena jednostkowa: " + to_string(price) + " Czy edytować? y/n : ")) {
        while (true) {
            cout << "Podaj cene jednostkową produktu (lub zero jeśli nie dotyczy): " << endl;
            cin >> price;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (cin.fail()) cout << "Błędne dane." << endl;
            else if (price < 0) cout << "Cena musi być dodatnia." << endl;
            else break;
        }
    }

    // Inputting `pricePerMeter` with validation
    if (!isEditing || readYesOrNo("Cena za metr: " + to_string(pricePerMeter) + " Czy edytować? y/n : ")) {
        while (true) {
            cout << "Podaj cene za metr produktu (lub zero jeśli nie dotyczy): " << endl;
            cin >> pricePerMeter;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (cin.fail()) cout << "Błędne dane." << endl;
            else if (pricePerMeter < 0) cout << "Cena musi być dodatnia." << endl;
            else break;
        }
    }
}

/// Returns product name for display
string Product::headingString() {
    return name;
}

///  Wraps product fields to a string that can be displayed
string Product::displayString() {
    return name +
           "\n\tszczegóły: " + productCategory + ", " + woodCategory + ", " + color +
           "\n\tsztuk w magazynie: " + to_string(numberOfItems) + "\t data dostawy: " + deliveryDate +
           "\n" + (price == 0.0 ? "" : ("\tcena: " + to_string(price))) +
           (pricePerMeter == 0.0 ? "" : ("\tcena za metr: " + to_string(pricePerMeter)));
}

/// Wraps product fields to a string that can be saved
string Product::toDataString() {
    return name + ';' + productCategory + ';' + woodCategory + ';' + color + ';' + deliveryDate + ';' +
           to_string(numberOfItems) + ';' + to_string(price) + ';' + to_string(pricePerMeter) + ';';
}

/// Fills product fields from a single wrapped string with data
void Product::fromDataString(const string &data) {
    // Split string by ';'
    vector<string> dataVector;
    string t;
    for (auto c: data) {
        if (c == ';' && t != "") {
            dataVector.push_back(t);
            t = "";
        } else {
            t += c;
        }
    }
    // Assign data to fields
    name = dataVector[0];
    productCategory = dataVector[1];
    woodCategory = dataVector[2];
    color = dataVector[3];
    deliveryDate = dataVector[4];
    numberOfItems = stoi(dataVector[5]);
    price = stof(dataVector[6]);
    pricePerMeter = stof(dataVector[7]);
}

/// Checks if any of product fields contain the given phrase
bool Product::containsPhrase(const string &givenPhrase) {
    return toLowercase(toDataString()).find(toLowercase(givenPhrase)) != string::npos;
}
