//
//  sort.cpp
//  CS2Final
//
//  Created by Samantha-Jo Cunningham on 5/7/18.
//  Copyright © 2018 Samantha-Jo Cunningham. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include<string>
#include<algorithm>
#include<fstream>
#include<iomanip>
#include "sort.h"
using namespace std;

template<typename T,typename A>
void Sort::SelectionSort(vector<T, A> const& obj) {
    int i;
    int j;
    T temp;
    int indexSmallest;
    int vector_size = obj.size();
    cout << "*** SELECTION SORT ***" << endl << endl;
    for (i = 0; i < vector_size; ++i) {
        
        // Find index of smallest remaining element
        indexSmallest = i;
        for (j = i + 1; j < vector_size; ++j) {
            
            if (obj.at(j) < obj.at(indexSmallest)) {
                indexSmallest = j;
            }
        }
        // Swap numbers[i] and numbers[indexSmallest]
        temp = obj.at(i);
        obj.at(i) = obj.at(indexSmallest);
        obj.at(indexSmallest) = temp;
        cout <<  "After iteration " << i + 1 << ":" << '\t';
        cout << "i = " << obj.at(i) << '\t';
        //cout << "j = " << obj.at[j] << '\t';
        cout << "indexSmallest = " << indexSmallest << '\t';
        cout << "temp = " << temp << endl << "New List: ";
        for (int t = 0; t < vector_size; ++t) {
            cout << obj.at(t) << " ";
        }
        cout << endl << endl;
        
    }
};
