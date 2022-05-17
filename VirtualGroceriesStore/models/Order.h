//
//  Order.h
//  VirtualGroceriesStore
//
//  Created by Mwai Banda on 5/16/22.
//  Purpose: Model Order

#ifndef Order_h
#define Order_h


struct Order {
    int ID;
    int userID;
    double total;
    std::string creationDate;
    std::string description;
};

#endif /* Order_h */
