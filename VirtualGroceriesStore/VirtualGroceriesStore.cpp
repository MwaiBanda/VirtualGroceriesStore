//
//  VirtualGroceriesStore.cpp
//  VirtualGroceriesStore
//
//  Created by Mwai Banda on 5/15/22.
//

#include "VirtualGroceriesStore.hpp"

VirtualGroceriesStore::VirtualGroceriesStore(sqlite3 *db) {
    this->db = db;
}
VirtualGroceriesStore::~VirtualGroceriesStore(){ }

int VirtualGroceriesStore::initMenu() {
    int choice = mainMenu();
    while (true)
    {
        switch (choice)
        {
            case 1: products(); break;
            case 2: categories(); break;
            case 3: orders(); break;
            case 4: users(); break;
            case 5: distributors(); break;
            case -1: return 0;
            default: cout << "That is not a valid choice." << endl;
        }
        cout << "\n\n";
        choice = mainMenu();
    }
}

int VirtualGroceriesStore::mainMenu(){
    int choice = 0;
    printMainMenuOptions();
    cin >> choice;
    while ((!cin || choice < 1 || choice > 6) && choice  != -1)
    {
        if (!cin)
        {
            cin.clear();
            cin.ignore(1000,'\n');
        }
        cout << "That is not a valid choice." << endl << endl;
        printMainMenuOptions();
        cin >> choice;
    }
    return choice;
}

int VirtualGroceriesStore::subMenu(MenuOption option) {
    int choice = 0;
    printSubMenuOptions(option);
    cin >> choice;
    while ((!cin || choice < 1 || choice > 6) && choice  != -1)
    {
        if (!cin)
        {
            cin.clear();
            cin.ignore(1000,'\n');
        }
        cout << "That is not a valid choice." << endl << endl;
        printSubMenuOptions(option);
        cin >> choice;
    }
    return choice;
}

void VirtualGroceriesStore::printMainMenuOptions() {
    cout << "Welcome to the Please choose an option (enter -1 to quit):  " << endl;
    cout << "1. Products" << endl;
    cout << "2. Categories" << endl;
    cout << "3. Orders" << endl;
    cout << "4. Users" << endl;
    cout << "5. Distributors" << endl;
    cout << "Enter Choice: ";
}
void VirtualGroceriesStore::productMenuOptions() {
    cout << "\nPlease choose an option (enter -1 to go back):  " << endl;
    cout << "1. Insert Product" << endl;
    cout << "2. View All Products" << endl;
    cout << "3. View Product" << endl;
    cout << "4. Update Product" << endl;
    cout << "5. Delete Product" << endl;
    cout << "Enter Choice: ";
}

void VirtualGroceriesStore::categoryMenuOptions() {
    cout << "\nPlease choose an option (enter -1 to go back):  " << endl;
    cout << "1. View All Categories" << endl;
    cout << "2. View Category" << endl;
    cout << "3. Update Category" << endl;
    cout << "4. Delete Category" << endl;
    cout << "Enter Choice: ";
}

void VirtualGroceriesStore::userMenuOptions() {
    cout << "\nPlease choose an option (enter -1 to go back):  " << endl;
    cout << "1. View All Categories" << endl;
    cout << "2. View Category" << endl;
    cout << "3. Update Category" << endl;
    cout << "4. Delete Category" << endl;
    cout << "Enter Choice: ";
}

void VirtualGroceriesStore::distributorMenuOptions() {
    cout << "\nPlease choose an option (enter -1 to go back):  " << endl;
    cout << "1. View All Categories" << endl;
    cout << "2. View Category" << endl;
    cout << "3. Update Category" << endl;
    cout << "4. Delete Category" << endl;
    cout << "Enter Choice: ";
}

void VirtualGroceriesStore::orderMenuOptions() {
    cout << "\nPlease choose an option (enter -1 to go back):  " << endl;
    cout << "1. View All Categories" << endl;
    cout << "2. View Category" << endl;
    cout << "3. Update Category" << endl;
    cout << "4. Delete Category" << endl;
    cout << "Enter Choice: ";
}

void VirtualGroceriesStore::printSubMenuOptions(MenuOption option) {
    switch (option) {
        case PRODUCTS:
            productMenuOptions();
            break;
        case CATEGORIES:
            categoryMenuOptions();
            break;
        case USERS:
            userMenuOptions();
            break;
        case DISTRIBUTOR:
            distributorMenuOptions();
            break;
        case ORDERS:
            orderMenuOptions();
            break;
    }
}
int VirtualGroceriesStore::products() {
    int choice = subMenu(MenuOption::PRODUCTS);
    while (true)
    {
        switch (choice)
        {
            case 1: insertProduct(); break;
            case 2: viewAllProducts(); break;
            case 3: viewProduct(); break;
            case 4: deleteProduct(); break;

            case -1: return 0;
            default: cout << "That is not a valid choice." << endl;
        }
        cout << "\n\n";
        choice = subMenu(MenuOption::PRODUCTS);
    }
}

int VirtualGroceriesStore::categories() {
    int choice = subMenu(MenuOption::USERS);
    while (true)
    {
        switch (choice)
        {
            case 1: cout << "1" << endl; break;
            case 2: cout << "2" << endl; break;
            case -1: return 0;
            default: cout << "That is not a valid choice." << endl;
        }
        cout << "\n\n";
        choice = subMenu(MenuOption::USERS);
    }
}


int VirtualGroceriesStore::users() {
    int choice = subMenu(MenuOption::USERS);
    while (true)
    {
        switch (choice)
        {
            case 1: cout << "1" << endl; break;
            case 2: cout << "2" << endl; break;
            case -1: return 0;
            default: cout << "That is not a valid choice." << endl;
        }
        cout << "\n\n";
        choice = subMenu(MenuOption::USERS);
    }
}

int VirtualGroceriesStore::distributors() {
    int choice = subMenu(MenuOption::USERS);
    while (true)
    {
        switch (choice)
        {
            case 1: cout << "1" << endl; break;
            case 2: cout << "2" << endl; break;
            case -1: return 0;
            default: cout << "That is not a valid choice." << endl;
        }
        cout << "\n\n";
        choice = subMenu(MenuOption::USERS);
    }
}

int VirtualGroceriesStore::orders() {
    int choice = subMenu(MenuOption::USERS);
    while (true)
    {
        switch (choice)
        {
            case 1: cout << "1" << endl; break;
            case 2: cout << "2" << endl; break;
            case -1: return 0;
            default: cout << "That is not a valid choice." << endl;
        }
        cout << "\n\n";
        choice = subMenu(MenuOption::USERS);
    }
}


void VirtualGroceriesStore::insertProduct() {
    string productProperties[5] = {"ID", "Name", "Price", "Distributor", "Weight"};
    map<string, string> productInfo;
    for (auto &i : productProperties) {
        printf("\nEnter product-%s: ", i.c_str());
        cin >> productInfo[i];
    }
    
}
    
void VirtualGroceriesStore::viewAllProducts() {
    Product* products = getAllProducts();
    delete[] products;
}

void VirtualGroceriesStore::viewProduct() {
    int ID;
    printf("\nEnter product ID: ");
    cin >> ID;
    Product product = getProductByID(ID);
}

void VirtualGroceriesStore::deleteProduct() {
    
}

Product* VirtualGroceriesStore::getAllProducts(){
    Product* products = new Product[10];
    string query = "SELECT Product.productID, Product.name, Product.price, Distributor.name, Product.weight "\
    "From Product "\
    "JOIN Distributor "\
    "ON Distributor.distributorID = Product.distributorID ";
    string errorMsg;
    int count = 0;
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &pRes, NULL) != SQLITE_OK)
    {
        errorMsg = sqlite3_errmsg(db);
        sqlite3_finalize(pRes);
        cout << "There was an error: " << errorMsg << endl;
    }
    else
    {
        cout << endl;
        while (sqlite3_step(pRes) == SQLITE_ROW)
        {
            cout  << count + 1 << ". " << sqlite3_column_text(pRes, 1);
            cout << endl;
            Product product = Product();
            product.ID = sqlite3_column_int(pRes, 0);
            product.name = reinterpret_cast<const char*>(sqlite3_column_text(pRes, 1));
            product.price = sqlite3_column_double(pRes, 2);
            product.distributor = reinterpret_cast<const char*>(sqlite3_column_text(pRes, 3));
            product.weight = sqlite3_column_double(pRes, 4);
            products[count] = product;
            count++;
        }
        
        sqlite3_reset(pRes);
    }
    return products;
}

Product VirtualGroceriesStore::getProductByID(int ID){
    Product product = Product();
    string query = "SELECT Product.productID, Product.name, Product.price, Distributor.name, Product.weight "\
    "From Product "\
    "JOIN Distributor "\
    "ON Distributor.distributorID = Product.distributorID "\
    "WHERE Product.productID=" + to_string(ID) + ";";
    string errorMsg;
    int count = 0;
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &pRes, NULL) != SQLITE_OK)
    {
        errorMsg = sqlite3_errmsg(db);
        sqlite3_finalize(pRes);
        cout << "There was an error: " << errorMsg << endl;
    }
    else
    {
        cout << endl;
        while (sqlite3_step(pRes) == SQLITE_ROW)
        {
            cout  << count + 1 << ". " << sqlite3_column_text(pRes, 1);
            cout << endl;
            product.ID = sqlite3_column_int(pRes, 0);
            product.name = reinterpret_cast<const char*>(sqlite3_column_text(pRes, 1));
            product.price = sqlite3_column_double(pRes, 2);
            product.distributor = reinterpret_cast<const char*>(sqlite3_column_text(pRes, 3));
            product.weight = sqlite3_column_double(pRes, 4);
        }
        
        sqlite3_reset(pRes);
    }
    return product;
}

void VirtualGroceriesStore::updateProductByID(int ID) {
    
}

void VirtualGroceriesStore::deleteProduct(int ID) {
    string query = "DELETE "\
    "FROM Product "\
    "WHERE Product.productID=" + to_string(ID) + ";";
    string errorMsg;
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &pRes, NULL) != SQLITE_OK)
    {
        errorMsg = sqlite3_errmsg(db);
        sqlite3_finalize(pRes);
        cout << "There was an error: " << errorMsg << endl;
    }
    else
    {
        cout << endl;
        printf("Deleted product with ID: %i\n", ID);
    }
}
