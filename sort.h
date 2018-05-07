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
    template<typename TheType>
    static void SelectionSort(TheType arrList[], int arr_Length);
};

#endif /* sort_h */
