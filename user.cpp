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

string User::userName() {
    string name_User;
    cout << "Username: ";
    cin.get();
    getline(cin, name_User);
    cout << endl;
    
    return name_User;
}

User::~User(){}
