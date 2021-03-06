//
//  main.cpp
//  VirtualGroceriesStore
//
//  Created by Mwai Banda on 5/15/22.
//  Purpose: Products CRUD, Category CRUD, Distributor CRUD, Order CRUD & User CRUD

#include <iostream>
#include "sqlite3.h"
#include "VirtualGroceriesStore.hpp"

int main(int argc, const char * argv[]) {
    sqlite3 *db;
    int rc;
    rc = sqlite3_open("/Users/mwaibanda/Repository/Main Projects/Command Line Projects/VirtualGroceriesStore/VirtualGroceriesStore/virtualgroceries.db", &db);
    
    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(1);
    } else {
        fprintf(stderr, "Opened database successfully\n");
        VirtualGroceriesStore store = VirtualGroceriesStore(db);
        store.initMenu();
    }
    return 0;
}
