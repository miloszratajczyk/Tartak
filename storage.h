#ifndef TARTAK_STORAGE_H
#define TARTAK_STORAGE_H

#include <vector>
#include <fstream>
#include <regex>

#include "product.h"

class Storage {
    // Path to a file used to load and save data
    string fileName;
    // List of all products in store
    vector<Product> products;
    // Objects with sets of available categories
    Categories productCategories;
    Categories woodCategories;

    // Checks if there are products in store
    // prints message if not
    bool noProducts(const string &message = "=== BRAK PRODUKTÓW ===");

    // Tries to load data from given file
    // or creates objects if file not found
    void loadData();

    // Tries to save data to given file
    // or creates the file if not found
    void saveData();

    // Shows available options and executes selected command
    void showMenu();

    // Prints all products with their data
    // or just the name if `concise` is true
    void print(bool concise = false);

    // Displays all products containing inputted phrase
    void search();

    // Creates a new products and fills it with data
    void create();

    // Allows user to select a product and then fill it with new data
    void edit();

    // Allows user to select a product and then removes it
    void remove();

    // Displays all products matching inputted regex pattern
    void regexSearch();

public:
    /// Starts the storage
    /// Loads the data, waits for the whole program to run and then saves data
    void start();
};

#endif //TARTAK_STORAGE_H
