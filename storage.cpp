#include "storage.h"

// Checks if there are products in store
// prints message if not
bool Storage::noProducts(const string &message) {
    bool isEmpty = products.empty();
    if (isEmpty) cout << message << endl;
    return isEmpty;
}

// Tries to load data from given file
// or creates objects if file not found
void Storage::loadData() {
    ifstream dataFile;
    dataFile.open(fileName);
    if (dataFile.good()) {
        // File exists
        cout << "Wczytuje dane z pliku." << endl;

        // Load `productCategories` data
        string productCategoriesData;
        getline(dataFile, productCategoriesData, '\n');
        productCategories.fromDataString(productCategoriesData);

        // Load `woodCategories` data
        string woodCategoriesData;
        getline(dataFile, woodCategoriesData, '\n');
        woodCategories.fromDataString(woodCategoriesData);

        // Load `products` data
        string line;
        while (getline(dataFile, line)) {
            products.emplace_back();
            products.back().fromDataString(line);
        }
    } else {
        // File doesn't exist
        cout << "Tworze dane dla nowego pliku." << endl;

        // Create empty objects for later use
        productCategories = Categories();
        woodCategories = Categories();
    }
    dataFile.close();
}

// Tries to save data to given file
// or creates the file if not found
void Storage::saveData() {
    ofstream dataFile;
    dataFile.open(fileName);
    if (dataFile.good()) {
        // File exists or created
        // Save `productCategories` and `woodCategories` data
        dataFile << productCategories.toDataString() << endl;
        dataFile << woodCategories.toDataString() << endl;
        // Save `products` data
        for (Product product: products) dataFile << product.toDataString() << endl;
    } else {
        // Couldn't read or create file
        cout << "Wystąpił błąd przy zapisywaniu danych." << endl;
    }
    dataFile.close();
}

// Shows available options and executes selected command
void Storage::showMenu() {
    while (true) {
        cout << endl;
        cout << "\tTARTAK" << endl;
        cout << endl;
        cout << "0.\tZapisz i wyjdź z programu" << endl;
        cout << "1.\tWyświetl produkty" << endl;
        cout << "2.\tWyszukaj produkt" << endl;
        cout << "3.\tDodaj produkt" << endl;
        cout << "4.\tEdytuj produkt" << endl;
        cout << "5.\tUsuń produkt" << endl;
        cout << "6.\tWyszukiwanie zaawansowane" << endl;


        string choice = readString();
        if (choice == "0") break;
        else if (choice == "1") print();
        else if (choice == "2") search();
        else if (choice == "3") create();
        else if (choice == "4") edit();
        else if (choice == "5") remove();
        else if (choice == "6") regexSearch();
    }
}

// Prints all products with their data
// or just the name if `concise` is true
void Storage::print(bool concise) {
    if (noProducts()) return;
    for (int i = 0; i < products.size(); i++) {
        if (concise) cout << i + 1 << ".\t" << products[i].headingString() << endl;
        else cout << endl << i + 1 << ".\t" << products[i].displayString() << endl;
    }
}

// Displays all products containing inputted phrase
void Storage::search() {
    if (noProducts()) return;
    string phrase = readLine("Podaj fraze której chcesz szukać: ");
    cout << "Produkty które zawierają szukaną frazę: " << endl;
    int id = 0;
    for (Product product: products) {
        if (product.containsPhrase(phrase))
            cout << ++id << ".\t" << product.displayString() << endl;
    }
    if (id == 0) cout << "=== BRAK PRODUKTÓW ===" << endl;
}

// Creates a new products and fills it with data
void Storage::create() {
    products.emplace_back();
    products.back().fill(&productCategories, &woodCategories, false);
}

// Allows user to select a product and then fill it with new data
void Storage::edit() {
    if (noProducts()) return;

    while (true) {
        cout << "Podaj indeks produktu który chcesz edytować:" << endl;
        cout << "0.\tAnuluj" << endl;
        print(true);

        string choice = readString();
        int id;
        try { id = stoi(choice); }
        catch (invalid_argument) { continue; }
        if (id == 0) { break; }
        else if (id <= products.size()) {
            products[id - 1].fill(&productCategories, &woodCategories, true);
            break;
        }
    }
}

// Allows user to select a product and then removes it
void Storage::remove() {
    if (noProducts()) return;

    while (true) {
        cout << "Podaj indeks produktu który chcesz usunąć:" << endl;
        cout << "0.\tAnuluj" << endl;
        print(true);

        string choice = readString();
        int id;
        try { id = stoi(choice); }
        catch (invalid_argument) { continue; }
        if (id == 0) { break; }
        else if (id <= products.size()) {
            products.erase(products.begin() + id - 1);
            break;
        }
    }
}


// Displays all products matching inputted regex pattern
void Storage::regexSearch() {
    if (noProducts()) return;
    string pattern = readLine("Podaj wyrażenie regex według którego chcesz szukać: ");
    cout << "Produkty które są zgodne z szablonem: " << endl;
    int id = 0;
    for (Product product: products) {
        if (regex_search(product.toDataString(), regex(pattern)))
            cout << ++id << ".\t" << product.displayString() << endl;
    }
    if (id == 0) cout << "=== BRAK PRODUKTÓW ===" << endl;
}


/// Starts the storage
/// Loads the data, waits for the whole program to run and then saves data
void Storage::start() {
    fileName = readString("Podaj nazwę pliku którego program ma użyć do wczytywania i zapisywnia danych: ");

    loadData();
    showMenu();
    saveData();
}
