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

Sort::Sort(){}
void Sort::SelectionSort(vector <int> PlaylistVect) {
    int i;
    int j;
    int temp;
    int indexSmallest;
    int VectSize = PlaylistVect.size();
    
    cout << "*** SELECTION SORT ***" << endl << endl;
    for (i = 0; i < VectSize; ++i) {
      
      // Find index of smallest remaining element
      indexSmallest = i;
      for (j = i + 1; j < VectSize; ++j) {
         
         if ( PlaylistVect.at(j) < PlaylistVect.at(indexSmallest) ) {
            indexSmallest = j;
         }
      }
      
      //Swap PlaylistVect.at(i) and PlaylistVect.at(indexSmallest)
      temp = PlaylistVect.at(i);
      PlaylistVect.at(i) = PlaylistVect.at(indexSmallest);
      PlaylistVect.at(indexSmallest) = temp;
   }
}
Sort::~Sort(){}
