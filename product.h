#ifndef TARTAK_PRODUCT_H
#define TARTAK_PRODUCT_H

#include <vector>

#include "categories.h"
#include "helpers.h"

using namespace std;

class Product {
    // Product fields
    std::string name;
    std::string productCategory;
    std::string woodCategory;
    std::string color;
    std::string deliveryDate;
    int numberOfItems = -1;
    float price = -1;
    float pricePerMeter = -1;
public:
    /// Allows user to input all product data with validation
    /// when `isEditing` is set to true it will ask which fields to edit
    void fill(Categories *productCategories, Categories *woodCategories, bool isEditing);

    /// Returns product name for display
    string headingString();

    ///  Wraps product fields to a string that can be displayed
    string displayString();

    /// Wraps product fields to a string that can be saved
    string toDataString();

    /// Fills product fields from a single wrapped string with data
    void fromDataString(string data);

    /// Checks if any of product fields contain the given phrase
    bool containsPhrase(string givenPhrase);
};

#endif //TARTAK_PRODUCT_H
