//
//  user.h
//  CS2Final
//
//  Created by Samantha-Jo Cunningham on 5/7/18.
//  Copyright © 2018 Samantha-Jo Cunningham. All rights reserved.
//

#ifndef user_h
#define user_h


#include <string>
#include <vector>
#include "song.h"

using namespace std;

class User{ //create the song class
    //create public variables
public:
    User(); //Constructors
    //mutators
    static string userName();
    ~User(); //Destructors
};

#endif /* user_h */
