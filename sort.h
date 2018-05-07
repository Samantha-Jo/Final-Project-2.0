//
//  sort.h
//  CS2Final
//
//  Created by Samantha-Jo Cunningham on 5/7/18.
//  Copyright © 2018 Samantha-Jo Cunningham. All rights reserved.
//

#ifndef sort_h
#define sort_h

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <vector>
#include <string.h>
using namespace std;

class Sort { //sort class
public:
    template<typename T,typename A>
    static void SelectionSort(vector<T, A> const& obj);
};

#endif /* sort_h */
