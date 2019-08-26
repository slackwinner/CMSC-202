/*
File: driver.cpp
Project: CMSC 202 Project 4, Spring 2018
Author: Dane Magbuhos
Date: 4/22/18
E-mail: mag4@umbc.edu

Description: This project contains the main driver for project 4.
This program reads in mail information, sorts/stores each mail item 
into their designated carriers, outputs the delivered mail, and calculates
the total cost of the delivery for each carrier.

*/
#include <iomanip>

using namespace std;

#include "MailHouse.h"

int failed(){
    cout << "Failed. Exitting..." << endl << endl;
    return 0;
}

int main(int argv, char* argc[]){
  // Outputs error message if text file path is not valid
    if(argv != 2){
        cout << "Invalid number of parameters..." << endl;
        return -1;
    }

    MailHouse m;

    // Loads in mail from valid path
    cout << "Loading file: " << argc[1] << endl << endl;
    if(!m.loadMail(argc[1])){
        m.cleanUp();
        return failed();
    }
    cout << "SUCCESS" << endl << endl;

    // Populates mail objects in each carrier
    cout << "Filling carriers...." << endl << endl;
    if(!m.fillCarriers()){
        m.cleanUp();
        return failed();
    }
    cout << "SUCCESS" << endl << endl;

    // Outputs mail that has been delivered and calculates delivery cost
    cout << "Delivering...." << endl << endl;
    if(!m.deliverMail()){
        m.cleanUp();
        return failed();
    }
    cout << "SUCCESS" << endl << endl;

    cout << "Cleaning up the carriers....." << endl << endl;
    m.cleanUp();

    cout << "Simulation success. Have a nice day!" << endl;
    return 0;
}
