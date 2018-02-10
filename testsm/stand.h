/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   stand.h
 * Author: udichje
 *
 * Created on March 6, 2017, 9:09 AM
 */
#include "standmanager.h"
#ifndef STAND_H
#define STAND_H

//Cake stand class
class Stand{
private:
    int inventoryNumber;
    double cost;
    bool checkedOut;
    std::string description;
    double income;
    
public:
    int getInventoryNumber();
    double getCost();
    bool getCheckedOut();
    std::string getDescription();
    double getIncome();
    void setCheckedOut(bool status);
    void setInventoryNumber(int invNumber);
    void setCost(double standcost);
    void setDescription(std::string newDescription);
    void setIncome(double amount);
    
    
    Stand();
    ~Stand(){};
};
#endif /* STAND_H */

