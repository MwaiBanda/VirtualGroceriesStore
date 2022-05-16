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

/* Models */
#include "Product.h"
#include "Category.h"

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
    
    //  Product CRUD Functionality:
    /*
        CREATE:
            void insertProduct(Product product);
        READ:
            Product* getAllProducts();
            Product getProductByID(int ID);
        UPADATE:
            void updateProduct(Product product);
        DELETE:
            void deleteProduct(int ID);
     */
    void insertProduct();
    void viewAllProducts();
    void viewProduct();
    void updateProduct();
    void deleteProduct();

    void insertProduct(Product product);
    Product* getAllProducts();
    Product getProductByID(int ID);
    void updateProduct(Product product);
    void deleteProduct(int ID);
    
    //  Category CRUD Functionality:
    /*
        CREATE:
            void insertCategory(Category category);
        READ:
            Category* getAllCategories();
            Category getCategoryByID(int ID);
        UPADATE:
            void updateCategory(Category category);;
        DELETE:
            void deleteCategory(int ID);
     */
    void insertCategory();
    void viewAllCategories();
    void viewCategory();
    void updateCategory();
    void deleteCategory();

    void insertCategory(Category category);
    Category* getAllCategories();
    Category getCategoryByID(int ID);
    void updateCategory(Category category);
    void deleteCategory(int ID);
    
};

#endif /* VirtualGroceriesStore_hpp */
