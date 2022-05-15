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
            case 2: users(); break;
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
    cout << "1. View All Products" << endl;
    cout << "2. View Product" << endl;
    cout << "3. Update Product" << endl;
    cout << "4. Delete Product" << endl;
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

void VirtualGroceriesStore::printSubMenuOptions(MenuOption option) {
    switch (option) {
        case PRODUCTS:
            productMenuOptions();
            break;
        case CATEGORIES:
            categoryMenuOptions();
            break;
        case USERS:
            break;
        case DISTRIBUTOR:
            break;
        case ORDERS:
            break;
    }
}
int VirtualGroceriesStore::products() {
    int choice = subMenu(MenuOption::PRODUCTS);
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
        choice = subMenu(MenuOption::PRODUCTS);
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


