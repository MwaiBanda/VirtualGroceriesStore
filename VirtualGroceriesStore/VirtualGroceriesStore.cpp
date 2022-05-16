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
            case 3: users(); break;
            case 4: distributors(); break;
            case 5: orders(); break;
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
    cout << "Welcome to Virtual Groceries DB Data, choose an option (enter -1 to quit):  " << endl;
    cout << "1. Products" << endl;
    cout << "2. Categories" << endl;
    cout << "3. Users" << endl;
    cout << "4. Distributors" << endl;
    cout << "5. Orders" << endl;
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
    cout << "1. Insert Category " << endl;
    cout << "2. View All Categories" << endl;
    cout << "3. View Category" << endl;
    cout << "4. Update Category" << endl;
    cout << "5. Delete Category" << endl;
    cout << "Enter Choice: ";
}

void VirtualGroceriesStore::userMenuOptions() {
    cout << "\nPlease choose an option (enter -1 to go back):  " << endl;
    cout << "1. Insert User" << endl;
    cout << "1. View All Users" << endl;
    cout << "2. View Users" << endl;
    cout << "3. Update Users" << endl;
    cout << "4. Delete Users" << endl;
    cout << "Enter Choice: ";
}

void VirtualGroceriesStore::distributorMenuOptions() {
    cout << "\nPlease choose an option (enter -1 to go back):  " << endl;
    cout << "1. Insert Distributor" << endl;
    cout << "1. View All Distributor" << endl;
    cout << "2. View Distributor" << endl;
    cout << "3. Update Distributor" << endl;
    cout << "4. Delete Distributor" << endl;
    cout << "Enter Choice: ";
}

void VirtualGroceriesStore::orderMenuOptions() {
    cout << "\nPlease choose an option (enter -1 to go back):  " << endl;
    cout << "1. Insert Order" << endl;
    cout << "1. View All Orders" << endl;
    cout << "2. View Order" << endl;
    cout << "3. Update Order" << endl;
    cout << "4. Delete Order" << endl;
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
            case 4: updateProduct(); break;
            case 5: deleteProduct(); break;

            case -1: return 0;
            default: cout << "That is not a valid choice." << endl;
        }
        cout << "\n\n";
        choice = subMenu(MenuOption::PRODUCTS);
    }
}

int VirtualGroceriesStore::categories() {
    int choice = subMenu(MenuOption::CATEGORIES);
    while (true)
    {
        switch (choice)
        {
            case 1: insertCategory(); break;
            case 2: viewAllCategories(); break;
            case 3: viewCategory(); break;
            case 4: updateCategory(); break;
            case 5: deleteCategory(); break;
            case -1: return 0;
            default: cout << "That is not a valid choice." << endl;
        }
        cout << "\n\n";
        choice = subMenu(MenuOption::CATEGORIES);
    }
}


int VirtualGroceriesStore::users() {
    int choice = subMenu(MenuOption::USERS);
    while (true)
    {
        switch (choice)
        {
            case 1: insertUser(); break;
            case 2: viewAllUsers(); break;
            case 3: viewUser(); break;
            case 4: updateUser(); break;
            case 5: deleteUser(); break;
            case -1: return 0;
            default: cout << "That is not a valid choice." << endl;
        }
        cout << "\n\n";
        choice = subMenu(MenuOption::USERS);
    }
}

int VirtualGroceriesStore::distributors() {
    int choice = subMenu(MenuOption::DISTRIBUTOR);
    while (true)
    {
        switch (choice)
        {
            case 1: insertDistributor(); break;
            case 2: viewAllDistributors(); break;
            case 3: viewDistributor(); break;
            case 4: updateDistributor(); break;
            case 5: deleteDistributor(); break;
            case -1: return 0;
            default: cout << "That is not a valid choice." << endl;
        }
        cout << "\n\n";
        choice = subMenu(MenuOption::DISTRIBUTOR);
    }
}

int VirtualGroceriesStore::orders() {
    int choice = subMenu(MenuOption::ORDERS);
    while (true)
    {
        switch (choice)
        {
            case 1: insertOrder(); break;
            case 2: viewAllOrders(); break;
            case 3: viewOrder(); break;
            case 4: updateOrder(); break;
            case 5: deleteOrder(); break;
            case -1: return 0;
            default: cout << "That is not a valid choice." << endl;
        }
        cout << "\n\n";
        choice = subMenu(MenuOption::ORDERS);
    }
}

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

void VirtualGroceriesStore::insertProduct() {
    string productProperties[5] = {"Name", "Price", "Weight"};
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
void VirtualGroceriesStore::updateProduct() {

    int i = 1, choice;
    cout << left;
    printf("Select a product to update\n");
    Product* products = getAllProducts();
        do
    {
        if (!cin)
        {
            cin.clear();
            cin.ignore(1000, '\n');
        }
        printf("Enter choice: ");
        cin >> choice;
        if (!cin || choice < 1 || choice > i)
            cout << "That is not a valid choice! Try Again!" << endl;
    } while (!cin);
    
    choice--;
    Product selectedProduct = products[choice];
    string productProperties[5] = {"Name", "Price", "Weight"};
    map<string, string> productInfo;
    
    for (auto &i : productProperties) {
        printf("\nEnter new product-%s: ", i.c_str());
        cin >> productInfo[i];
    }
    
    Product updatedProduct = Product();
    updatedProduct.ID = selectedProduct.ID;
    updatedProduct.name = productInfo[productProperties[0]];
    updatedProduct.price = stod(productInfo[productProperties[1]]);
    updatedProduct.distributor = selectedProduct.distributor;
    updatedProduct.weight = stod(productInfo[productProperties[2]]);
    updateProduct(updatedProduct);
    delete[] products;
}
void VirtualGroceriesStore::deleteProduct() {
    int i = 1, choice;
    cout << left;
    printf("Select a product to delete\n");
    Product* products = getAllProducts();
        do
    {
        if (!cin)
        {
            cin.clear();
            cin.ignore(1000, '\n');
        }
        printf("Enter choice: ");
        cin >> choice;
        if (!cin || choice < 1 || choice > i)
            cout << "That is not a valid choice! Try Again!" << endl;
    } while (!cin);
    
    choice--;
    Product selectedProduct = products[choice];
    deleteProduct(selectedProduct.ID);
    delete[] products;
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

void VirtualGroceriesStore::updateProduct(Product product) {
    string query = "UPDATE Product "\
    "SET name=" + product.name + ", price=" + to_string(product.ID) + ",  weight=" + to_string(product.weight) + " "\
    "WHERE Product.productID=" + to_string(product.ID) + ";";
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
        printf("Deleted product with ID: %i\n", product.ID);
    }
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

void VirtualGroceriesStore::insertCategory() {
    string categoryProperties[1] = {"Name"};
    map<string, string> categoryInfo;
    for (auto &i : categoryProperties) {
        printf("\nEnter category-%s: ", i.c_str());
        cin >> categoryInfo[i];
    }
}

void VirtualGroceriesStore::viewAllCategories() {
    Category* categories = getAllCategories();
    delete[] categories;
}

void VirtualGroceriesStore::viewCategory() {
    int ID;
    printf("\nEnter category ID: ");
    cin >> ID;
    Category category = getCategoryByID(ID);
}

void VirtualGroceriesStore::updateCategory() {
    int i = 1, choice;
    cout << left;
    printf("Select a category to update\n");
    Category* categories = getAllCategories();
        do
    {
        if (!cin)
        {
            cin.clear();
            cin.ignore(1000, '\n');
        }
        printf("Enter choice: ");
        cin >> choice;
        if (!cin || choice < 1 || choice > i)
            cout << "That is not a valid choice! Try Again!" << endl;
    } while (!cin);
    
    choice--;
    Category selectedCategory = categories[choice];
    string categoryProperties[1] = {"Name"};
    map<string, string> categoryInfo;
    
    for (auto &i : categoryProperties) {
        printf("\nEnter new product-%s: ", i.c_str());
        cin >> categoryInfo[i];
    }
    
    Category updatedCategory = Category();
    updatedCategory.ID = selectedCategory.ID;
    updatedCategory.name = categoryInfo[categoryProperties[0]];
    updateCategory(updatedCategory);
    delete[] categories;
}

void VirtualGroceriesStore::deleteCategory() {
    int i = 1, choice;
    cout << left;
    printf("Select a product to delete\n");
    Category* categories = getAllCategories();
        do
    {
        if (!cin)
        {
            cin.clear();
            cin.ignore(1000, '\n');
        }
        printf("Enter choice: ");
        cin >> choice;
        if (!cin || choice < 1 || choice > i)
            cout << "That is not a valid choice! Try Again!" << endl;
    } while (!cin);
    
    choice--;
    Category selectedCategory = categories[choice];
    deleteCategory(selectedCategory.ID);
    delete[] categories;
}

void VirtualGroceriesStore::insertCategory(Category category) {
    
}

Category* VirtualGroceriesStore::getAllCategories() {
    Category* categories = new Category[5];
    string query = "SELECT * FROM Category;";
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
            Category category = Category();
            category.ID = sqlite3_column_int(pRes, 0);
            category.name = reinterpret_cast<const char*>(sqlite3_column_text(pRes, 1));
            categories[count] = category;
            count++;
        }
        
        sqlite3_reset(pRes);
    }
    return categories;
}

Category VirtualGroceriesStore::getCategoryByID(int ID) {
    Category category = Category();
    string query = "SELECT *"\
    "FROM Category "\
    "WHERE Category.categoryID=" + to_string(ID) + ";";
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
        while (sqlite3_step(pRes) == SQLITE_ROW)
        {
            cout  << 1 << ". " << sqlite3_column_text(pRes, 1);
            cout << endl;
            category.ID = sqlite3_column_int(pRes, 0);
            category.name = reinterpret_cast<const char*>(sqlite3_column_text(pRes, 1));
           
        }
        
        sqlite3_reset(pRes);
    }
    return category;
}

void VirtualGroceriesStore::updateCategory(Category category) {
    string query = "UPDATE Category "\
    "SET name=" + category.name + " "\
    "WHERE Category.category=" + to_string(category.ID) + ";";
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
        printf("Deleted product with ID: %i\n", category.ID);
    }
}
void VirtualGroceriesStore::deleteCategory(int ID){
    string query = "DELETE "\
    "FROM Category "\
    "WHERE Category.categoryID=" + to_string(ID) + ";";
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
        printf("Deleted category with ID: %i\n", ID);
    }
}

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


void VirtualGroceriesStore::insertUser() {
    
}

void VirtualGroceriesStore::viewAllUsers() {
    
}

void VirtualGroceriesStore::viewUser() {
    
}

void VirtualGroceriesStore::updateUser() {
    
}

void VirtualGroceriesStore::deleteUser() {
    
}

void VirtualGroceriesStore::insertUser(User user) {
    
}

User* VirtualGroceriesStore::getAllUsers() {
    User* user = new User[5];
    return user;
}

User VirtualGroceriesStore::getUserByID(int ID) {
    User user = User();
    return user;
}
void VirtualGroceriesStore::deleteUser(int ID) {
    string query = "DELETE "\
    "FROM User "\
    "WHERE User.userID=" + to_string(ID) + ";";
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
        printf("Deleted category with ID: %i\n", ID);
    }
}
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

void VirtualGroceriesStore::insertDistributor() {
    
}

void VirtualGroceriesStore::viewAllDistributors() {
    
}

void VirtualGroceriesStore::viewDistributor() {
    
}

void VirtualGroceriesStore::updateDistributor() {
    
}

void VirtualGroceriesStore::deleteDistributor() {
    
}

void VirtualGroceriesStore::insertDistributor(Distributor distributor) {
    
}

Distributor* VirtualGroceriesStore::getAllDistributors() {
    Distributor* distributors = new Distributor[5];
    return distributors;
}

Distributor VirtualGroceriesStore::getDistributorByID(int ID) {
    Distributor distributor = Distributor();
    return distributor;
}

void VirtualGroceriesStore::deleteDistributor(int ID){
    string query = "DELETE "\
    "FROM Distributor "\
    "WHERE Distributor.distributorID=" + to_string(ID) + ";";
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
        printf("Deleted category with ID: %i\n", ID);
    }
}

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

void VirtualGroceriesStore::insertOrder() {
    
}

void VirtualGroceriesStore::viewAllOrders() {
    
}

void VirtualGroceriesStore::viewOrder() {
    
}

void VirtualGroceriesStore::updateOrder() {
    
}

void VirtualGroceriesStore::deleteOrder() {
    
}

void VirtualGroceriesStore::insertOrder(Order order) {
    
}

Order* VirtualGroceriesStore::getAllOrders() {
    Order* distributors = new Order[5];
    return distributors;
}

Order VirtualGroceriesStore::getOrderByID(int ID) {
    Order order = Order();
    return order;
}

void VirtualGroceriesStore::deleteOrder(int ID){
    string query = "DELETE "\
    "FROM Order "\
    "WHERE Order.orderID=" + to_string(ID) + ";";
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
        printf("Deleted category with ID: %i\n", ID);
    }
}
