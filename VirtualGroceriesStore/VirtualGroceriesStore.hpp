//
//  VirtualGroceriesStore.hpp
//  VirtualGroceriesStore
//
//  Created by Mwai Banda on 5/15/22.
//

#ifndef VirtualGroceriesStore_hpp
#define VirtualGroceriesStore_hpp

#include <stdio.h>
#include <iostream>
#include "sqlite3.h"
#include <list>
#include <map>

#include "Product.h"

using namespace std;

class VirtualGroceriesStore {
public:
    VirtualGroceriesStore(sqlite3 *db);
    ~VirtualGroceriesStore();
    int initMenu();
    
private:
    sqlite3* db;
    sqlite3_stmt *pRes;
    enum MenuOption {
        PRODUCTS,
        CATEGORIES,
        USERS,
        DISTRIBUTOR,
        ORDERS
    };
    
    int mainMenu();
    int subMenu(MenuOption option);
    void printMainMenuOptions();
    void printSubMenuOptions(MenuOption option);
    
    void productMenuOptions();
    void categoryMenuOptions();
    void userMenuOptions();
    void distributorMenuOptions();
    void orderMenuOptions();
    
    int products();
    int categories();
    int users();
    int distributors();
    int orders();
    
    void insertProduct();
    void viewAllProducts();
    void viewProduct();
    void updateProduct();
    void deleteProduct();

    void insertProduct(Product product);
    Product* getAllProducts();
    Product getProductByID(int ID);
    void updateProductByID(int ID);
    void deleteProduct(int ID);
    
    
};

#endif /* VirtualGroceriesStore_hpp */
