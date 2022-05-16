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
#include "Distributor.h"
/* Order & User Models because an Order contains a User thus imports User */
#include "Order.h"


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
    
    //  User CRUD Functionality:
    /*
        CREATE:
            void insertUser(User user);
        READ:
            User* getAllUsers();
            User getUserByID(int ID);
        UPADATE:
            void updateUser(User user);
        DELETE:
            void deleteUser(int ID);
     */
    void insertUser();
    void viewAllUsers();
    void viewUser();
    void updateUser();
    void deleteUser();

    void insertUser(User user);
    User* getAllUsers();
    User getUserByID(int ID);
    void updateUser(User user);
    void deleteUser(int ID);
    
    //  Distributor CRUD Functionality:
    /*
        CREATE:
            void insertDistributor(Distributor distributor);
        READ:
            Distributor* getAllDistributor();
            Distributor getDistributorByID(int ID);
        UPADATE:
            void updateDistributor(User user);
        DELETE:
            void deleteDistributor(int ID);
     */
    void insertDistributor();
    void viewAllDistributors();
    void viewDistributor();
    void updateDistributor();
    void deleteDistributor();

    void insertDistributor(Distributor distributor);
    Distributor* getAllDistributors();
    Distributor getDistributorByID(int ID);
    void updateDistributor(User user);
    void deleteDistributor(int ID);
    
    //  Order CRUD Functionality:
    /*
        CREATE:
            void insertUser(User user);
        READ:
            Order* getAllUsers();
            Order getUserByID(int ID);
        UPADATE:
            void updateOrder(Order order);
        DELETE:
            void deleteOrder(int ID);
     */
    void insertOrder();
    void viewAllOrders();
    void viewOrder();
    void updateOrder();
    void deleteOrder();

    void insertOrder(Order order);
    Order* getAllOrders();
    Order getOrderByID(int ID);
    void updateOrder(Order order);
    void deleteOrder(int ID);
};
    
#endif /* VirtualGroceriesStore_hpp */
