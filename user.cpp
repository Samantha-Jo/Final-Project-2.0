//
//  user.cpp
//  CS2Final
//
//  Created by Samantha-Jo Cunningham on 5/7/18.
//  Copyright © 2018 Samantha-Jo Cunningham. All rights reserved.
//

#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

#include "user.h"

User::User(){}

string User::userName(string nameofUser) {
     try {
    cout << "Username: ";
    //cin.get();
    getline(cin, nameofUser);
    cout << endl;
        if (nameofUser == "") {
            throw runtime_error("Invalid Username");
        }
    }
    catch (runtime_error& excpt){
        cout << excpt.what() << endl;
        cout << "Please enter a valid username" << endl;
    }
    
    return nameofUser;
}

User::~User(){}
