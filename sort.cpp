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


void Sort::SelectionSort(vector <int> PlaylistVect, int VectSize) {
    int i;
    int j;
    int temp;
    int indexSmallest;
    cout << "*** SELECTION SORT ***" << endl << endl;
    for (i = 0; i < VectSize; ++i) {
        
        // Find index of smallest remaining element
        indexSmallest = i;
        for (j = i + 1; j < VectSize; ++j) {
            
            if (PlaylistVect[j] < PlaylistVect[indexSmallest]) {
                indexSmallest = j;
            }
        }
        // Swap numbers[i] and numbers[indexSmallest]
        temp = PlaylistVect[i];
        PlaylistVect[i] = PlaylistVect[indexSmallest];
        PlaylistVect[indexSmallest] = temp;
        cout <<  "After iteration " << i + 1 << ":" << '\t';
        cout << "i = " << PlaylistVect[i] << '\t';
        //cout << "j = " << arrList[j] << '\t';
        cout << "indexSmallest = " << indexSmallest << '\t';
        cout << "temp = " << temp << endl << "New List: ";
        for (int t = 0; t < VectSize; ++t) {
            cout << PlaylistVect[t] << " ";
        }
        cout << endl << endl;
        
    }
};
