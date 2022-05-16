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
    cout << "2. View All Users" << endl;
    cout << "3. View Users" << endl;
    cout << "4. Update Users" << endl;
    cout << "5. Delete Users" << endl;
    cout << "Enter Choice: ";
}

void VirtualGroceriesStore::distributorMenuOptions() {
    cout << "\nPlease choose an option (enter -1 to go back):  " << endl;
    cout << "1. Insert Distributor" << endl;
    cout << "2. View All Distributor" << endl;
    cout << "3. View Distributor" << endl;
    cout << "4. Update Distributor" << endl;
    cout << "5. Delete Distributor" << endl;
    cout << "Enter Choice: ";
}

void VirtualGroceriesStore::orderMenuOptions() {
    cout << "\nPlease choose an option (enter -1 to go back):  " << endl;
    cout << "1. Insert Order" << endl;
    cout << "2. View All Orders" << endl;
    cout << "3. View Order" << endl;
    cout << "4. Update Order" << endl;
    cout << "5. Delete Order" << endl;
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
    int i = 1, choice;
    cout << left;
    printf("\nSelect a distributor\n");
    Distributor* distributors = getAllDistributors();
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
    Distributor selectedDistributor = distributors[choice];
    Product newProduct = Product();
    newProduct.name = productInfo[productProperties[0]];
    newProduct.price = stod(productInfo[productProperties[1]]);
    newProduct.weight = stod(productInfo[productProperties[2]]);
    newProduct.distributor = to_string(selectedDistributor.ID);

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
void VirtualGroceriesStore::insertProduct(Product product) {
    string query = "INSERT INTO Product(name, price, distributorID, weight) "\
    "VALUES(" + product.name + "," + to_string(product.price) + "," + product.distributor + "," + to_string(product.weight) + ");";
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
        printf("Created order for product: %s\n",product.name.c_str());
    }
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
    string query = "INSERT INTO Category(name) "\
    "VALUES(" + category.name + ");";
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
        printf("Created category for named: %s\n", category.name.c_str());
    }
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
    "WHERE Category.categoryID=" + to_string(category.ID) + ";";
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
    string userProperties[3] = {"username", "first-name", "last-name"};
    map<string, string> userInfo;
    for (auto &i : userProperties) {
        printf("\nEnter user-%s: ", i.c_str());
        cin >> userInfo[i];
    }
    User newUser = User();
    newUser.userName = userInfo[userProperties[0]];
    newUser.firstName = userInfo[userProperties[1]];
    newUser.lastName = userInfo[userProperties[2]];
    insertUser(newUser);
}

void VirtualGroceriesStore::viewAllUsers() {
    User* users = getAllUsers();
    delete[] users;
}

void VirtualGroceriesStore::viewUser() {
    int ID;
    printf("\nEnter user ID: ");
    cin >> ID;
    User user = getUserByID(ID);
}

void VirtualGroceriesStore::updateUser() {
    int i = 1, choice;
    cout << left;
    printf("Select a category to update\n");
    User* users = getAllUsers();
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
    User selectedUser = users[choice];
    string userProperties[3] = {"Username", "firstName", "lastName"};
    map<string, string> userInfo;
    
    for (auto &i : userProperties) {
        printf("\nEnter new product-%s: ", i.c_str());
        cin >> userInfo[i];
    }
    
    User updatedUser = User();
    updatedUser.ID = selectedUser.ID;
    updatedUser.userName = userInfo[userProperties[0]];
    updatedUser.firstName = userInfo[userProperties[1]];
    updatedUser.lastName = userInfo[userProperties[2]];
    updatedUser.creationDate = selectedUser.creationDate;

    updateUser(updatedUser);
    delete[] users;
}

void VirtualGroceriesStore::deleteUser() {
    int i = 1, choice;
    cout << left;
    printf("Select a user to delete\n");
    User* users = getAllUsers();
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
    User selectedUser = users[choice];
    deleteUser(selectedUser.ID);
}

void VirtualGroceriesStore::insertUser(User user) {
    string query = "INSERT INTO User(username, creationDate, firstName, lastName) "\
    "VALUES(" + user.userName + ",04/16/2022," + user.firstName + "," + user.userName + ");";
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
        printf("Created user with username: %s\n", user.userName.c_str());
    }
}

User* VirtualGroceriesStore::getAllUsers() {
    User* users = new User[5];
    string query = "SELECT * FROM User;";
    string errorMsg;
    int count = 0;
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &pRes, NULL) != SQLITE_OK) {
        errorMsg = sqlite3_errmsg(db);
        sqlite3_finalize(pRes);
        cout << "There was an error: " << errorMsg << endl;
    } else {
        cout << endl;
        while (sqlite3_step(pRes) == SQLITE_ROW) {
            cout  << count + 1 << ". " << sqlite3_column_text(pRes, 1);
            cout << endl;
            User user = User();
            user.ID = sqlite3_column_int(pRes, 0);
            user.userName = reinterpret_cast<const char*>(sqlite3_column_text(pRes, 1));
            user.creationDate = reinterpret_cast<const char*>(sqlite3_column_text(pRes, 2));
            user.firstName = reinterpret_cast<const char*>(sqlite3_column_text(pRes, 3));
            user.lastName = reinterpret_cast<const char*>(sqlite3_column_text(pRes, 4));
            users[count] = user;
            count++;
        }
        
        sqlite3_reset(pRes);
    }
    return users;
}

User VirtualGroceriesStore::getUserByID(int ID) {
    User user = User();
    string query = "SELECT * "\
    "FROM User "\
    "WHERE User.userID=" + to_string(ID) + ";";
    string errorMsg;
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &pRes, NULL) != SQLITE_OK) {
        errorMsg = sqlite3_errmsg(db);
        sqlite3_finalize(pRes);
        cout << "There was an error: " << errorMsg << endl;
    } else {
        cout << endl;
        while (sqlite3_step(pRes) == SQLITE_ROW) {
            cout  << 1 << ". " << sqlite3_column_text(pRes, 1);
            cout << endl;
            user.ID = sqlite3_column_int(pRes, 0);
            user.userName = reinterpret_cast<const char*>(sqlite3_column_text(pRes, 1));
            user.creationDate = reinterpret_cast<const char*>(sqlite3_column_text(pRes, 2));
            user.firstName = reinterpret_cast<const char*>(sqlite3_column_text(pRes, 3));
            user.lastName = reinterpret_cast<const char*>(sqlite3_column_text(pRes, 4));
        }
        
    }
    return user;
}
void VirtualGroceriesStore::updateUser(User user) {
    string query = "UPDATE User "\
    "SET userID=" + user.userName + ", firstName=" + user.firstName + ", lastname=" + user.lastName + " "\
    "WHERE User.userID=" + to_string(user.ID) + ";";
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
        printf("Updated User with ID: %i\n", user.ID);
    }
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
    string distributorProperties[2] = {"name", "location"};
    map<string, string> distributorInfo;
    for (auto &i : distributorProperties) {
        printf("\nEnter distributor-%s: ", i.c_str());
        cin >> distributorInfo[i];
    }
    Distributor newDistributor = Distributor();
    newDistributor.name = distributorInfo[distributorProperties[0]];
    newDistributor.city = distributorInfo[distributorProperties[1]];
    insertDistributor(newDistributor);
}

void VirtualGroceriesStore::viewAllDistributors() {
    Distributor* distributors = getAllDistributors();
    delete[] distributors;
}

void VirtualGroceriesStore::viewDistributor() {
    int ID;
    printf("\nEnter distributor ID: ");
    cin >> ID;
    Distributor distributor = getDistributorByID(ID);
}

void VirtualGroceriesStore::updateDistributor() {
    int i = 1, choice;
    cout << left;
    printf("Select a order to update\n");
    Distributor* distributors = getAllDistributors();
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
    Distributor selectedDistributor = distributors[choice];
    string userProperties[2] = {"Name", "City"};
    map<string, string> userInfo;
    
    for (auto &i : userProperties) {
        printf("\nEnter new distributor-%s: ", i.c_str());
        cin >> userInfo[i];
    }
    
    Distributor updatedDistributor = Distributor();
    updatedDistributor.ID = selectedDistributor.ID;
    updatedDistributor.name = userInfo[userProperties[0]];
    updatedDistributor.city = userInfo[userProperties[1]];
    
    updateDistributor(updatedDistributor);
    delete[] distributors;
}

void VirtualGroceriesStore::deleteDistributor() {
    int i = 1, choice;
    cout << left;
    printf("Select a user to delete\n");
    Distributor* distributors = getAllDistributors();
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
    Distributor selectedDistributor = distributors[choice];
    deleteUser(selectedDistributor.ID);
}

void VirtualGroceriesStore::insertDistributor(Distributor distributor) {
    string query = "INSERT INTO Distributor(name, location) "\
    "VALUES(" + distributor.name + "," + distributor.city +  ");";
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
        printf("Created distributor named: %s\n", distributor.name.c_str());
    }
}

Distributor* VirtualGroceriesStore::getAllDistributors() {
    Distributor* distributors = new Distributor[3];
    string query = "SELECT * FROM Distributor;";
    string errorMsg;
    int count = 0;
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &pRes, NULL) != SQLITE_OK) {
        errorMsg = sqlite3_errmsg(db);
        sqlite3_finalize(pRes);
        cout << "There was an error: " << errorMsg << endl;
    } else {
        cout << endl;
        while (sqlite3_step(pRes) == SQLITE_ROW) {
            cout  << count + 1 << ". " << sqlite3_column_text(pRes, 1);
            cout << endl;
            Distributor distributor = Distributor();
            distributor.ID = sqlite3_column_int(pRes, 0);
            distributor.name = reinterpret_cast<const char*>(sqlite3_column_text(pRes, 1));
            distributor.city = reinterpret_cast<const char*>(sqlite3_column_text(pRes, 2));
            distributors[count] = distributor;
            count++;
        }
        
        sqlite3_reset(pRes);
    }
    return distributors;
}

Distributor VirtualGroceriesStore::getDistributorByID(int ID) {
    Distributor distributor = Distributor();
    string query = "SELECT * "\
    "FROM Distributor "\
    "WHERE Distributor.distributorID=" + to_string(ID) + ";";
    string errorMsg;
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &pRes, NULL) != SQLITE_OK) {
        errorMsg = sqlite3_errmsg(db);
        sqlite3_finalize(pRes);
        cout << "There was an error: " << errorMsg << endl;
    } else {
        cout << endl;
        while (sqlite3_step(pRes) == SQLITE_ROW) {
            cout  << 1 << ". " << sqlite3_column_text(pRes, 1);
            cout << endl;
            distributor.ID = sqlite3_column_int(pRes, 0);
            distributor.name = reinterpret_cast<const char*>(sqlite3_column_text(pRes, 1));
            distributor.city = reinterpret_cast<const char*>(sqlite3_column_text(pRes, 2));
         
        }
        
        sqlite3_reset(pRes);
    }
    return distributor;
}
void VirtualGroceriesStore::updateDistributor(Distributor distributor){
    string query = "UPDATE Distributor "\
    "SET name=" + distributor.name + ", location=" + distributor.city + " "\
    "WHERE Distributor.distributorID=" + to_string(distributor.ID) + ";";
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
        printf("Updated Distributor with ID: %i\n", distributor.ID);
    }
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
    string orderProperties[5] = {"total", "description"};
    map<string, string> orderInfo;
    for (auto &i : orderProperties) {
        printf("\nEnter user-%s: ", i.c_str());
        cin >> orderInfo[i];
    }
    int i = 1, choice;
    cout << left;
    printf("\nSelect the User the Order belongs to:\n");
    User* users = getAllUsers();
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
    User selectedUser = users[choice];
    Order newOrder = Order();
    newOrder.user  = selectedUser;
    newOrder.total = stod(orderInfo[orderProperties[0]]);
    newOrder.description = orderInfo[orderProperties[1]];
    insertOrder(newOrder);
    delete [] users;
}

void VirtualGroceriesStore::viewAllOrders() {
    Order * orders = getAllOrders();
    delete [] orders;
}

void VirtualGroceriesStore::viewOrder() {
    int ID;
    printf("\nEnter order ID: ");
    cin >> ID;
    Order order = getOrderByID(ID);
}

void VirtualGroceriesStore::updateOrder() {
    int i = 1, choice;
    cout << left;
    printf("Select a category to update\n");
    Order* orders = getAllOrders();
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
    Order selectedOrder = orders[choice];
    
    string orderProperties[2] = {"Total", "Description"};
    map<string, string> orderInfo;
    
    for (auto &i : orderProperties) {
        printf("\nEnter new order-%s: ", i.c_str());
        cin >> orderInfo[i];
    }
    
    Order updatedOrder = Order();
    updatedOrder.ID = selectedOrder.ID;
    updatedOrder.userID = selectedOrder.userID;
    updatedOrder.total = stod(orderInfo[orderProperties[0]]);
    updatedOrder.description = orderInfo[orderProperties[1]];
    updatedOrder.creationDate = selectedOrder.creationDate;

    updateOrder(updatedOrder);
    delete[] orders;
}

void VirtualGroceriesStore::deleteOrder() {
    int i = 1, choice;
    cout << left;
    printf("Select a category to delete\n");
    Order* orders = getAllOrders();
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
    Order selectedOrder = orders[choice];
    getOrderByID(selectedOrder.ID);
}


void VirtualGroceriesStore::insertOrder(Order order) {
    string query = "INSERT INTO UserOrder(userID, total, creationDate, description) "\
    "VALUES(" + to_string(order.userID) + "," + to_string(order.total) + "04/16/2022," + order.description + ");";
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
        printf("Created order: %s\n", order.description.c_str());
    }
}

Order* VirtualGroceriesStore::getAllOrders() {
    Order* orders = new Order[5];
    string query = "SELECT * FROM UserOrder;";
    string errorMsg;
    int count = 0;
    
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &pRes, NULL) != SQLITE_OK) {
        errorMsg = sqlite3_errmsg(db);
        sqlite3_finalize(pRes);
        cout << "There was an error: " << errorMsg << endl;
    } else {
        cout << endl;
        while (sqlite3_step(pRes) == SQLITE_ROW) {
            Order order = Order();

            order.ID = sqlite3_column_int(pRes, 0);
            order.userID = sqlite3_column_int(pRes, 1);
            order.total = sqlite3_column_double(pRes, 2);
            order.description = reinterpret_cast<const char*>(sqlite3_column_text(pRes, 4));
            cout  << 1 <<  order.description << " costing " << order.total ;
            cout << endl;
            orders[count] = order;
            count++;
        }
        
        sqlite3_reset(pRes);
    }

    return orders;
}

Order VirtualGroceriesStore::getOrderByID(int ID) {
    Order order = Order();
    string query = "SELECT * "\
    "FROM UserOrder "\
    "WHERE UserOrder.orderID=" + to_string(ID) + ";";
    string errorMsg;
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &pRes, NULL) != SQLITE_OK) {
        errorMsg = sqlite3_errmsg(db);
        sqlite3_finalize(pRes);
        cout << "There was an error: " << errorMsg << endl;
    } else {
        cout << endl;
        while (sqlite3_step(pRes) == SQLITE_ROW) {
           
            order.ID = sqlite3_column_int(pRes, 0);
            order.userID = sqlite3_column_int(pRes, 1);
            order.total = sqlite3_column_double(pRes, 2);
            order.creationDate = reinterpret_cast<const char*>(sqlite3_column_text(pRes, 2));
            order.description = reinterpret_cast<const char*>(sqlite3_column_text(pRes, 2));
            cout  << 1 << ". Ordered = " << order.description << " costing " << order.total ;
            cout << endl;
        }
        
        sqlite3_reset(pRes);
    }

    return order;
}
void VirtualGroceriesStore::updateOrder(Order order) {
    string query = "UPDATE UserOrder "\
    "SET total=" + to_string(order.total) + ", description=" + order.description + " "\
    "WHERE UserOrder.orderID=" + to_string(order.ID) + ";";
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
        printf("Updated Distributor with ID: %i\n", order.ID);
    }
}
void VirtualGroceriesStore::deleteOrder(int ID){
    string query = "DELETE "\
    "FROM UserOrder "\
    "WHERE UserOrder.orderID=" + to_string(ID) + ";";
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
