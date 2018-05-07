//
//  sort.cpp
//  CS2Final
//
//  Created by Samantha-Jo Cunningham on 5/7/18.
//  Copyright © 2018 Samantha-Jo Cunningham. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<iomanip>
#include "sort.h"
using namespace std;

template<typename TheType>
void Sort::SelectionSort(TheType arrList[], int arr_Length) {
    int i;
    int j;
    TheType temp;
    int indexSmallest;
    cout << "*** SELECTION SORT ***" << endl << endl;
    for (i = 0; i < arr_Length; ++i) {
        
        // Find index of smallest remaining element
        indexSmallest = i;
        for (j = i + 1; j < arr_Length; ++j) {
            
            if (arrList[j] < arrList[indexSmallest]) {
                indexSmallest = j;
            }
        }
        // Swap numbers[i] and numbers[indexSmallest]
        temp = arrList[i];
        arrList[i] = arrList[indexSmallest];
        arrList[indexSmallest] = temp;
        cout <<  "After iteration " << i + 1 << ":" << '\t';
        cout << "i = " << arrList[i] << '\t';
        //cout << "j = " << arrList[j] << '\t';
        cout << "indexSmallest = " << indexSmallest << '\t';
        cout << "temp = " << temp << endl << "New List: ";
        for (int t = 0; t < arr_Length; ++t) {
            cout << arrList[t] << " ";
        }
        cout << endl << endl;
        
    }
};
