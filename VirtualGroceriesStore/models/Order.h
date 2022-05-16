//
//  Order.h
//  VirtualGroceriesStore
//
//  Created by Mwai Banda on 5/16/22.
//

#ifndef Order_h
#define Order_h

#include "User.h"

struct Order {
    int ID;
    User user;
    double total;
    std::string creationDate;
    std::string description;
};

#endif /* Order_h */
