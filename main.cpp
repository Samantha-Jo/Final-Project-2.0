//
//  main.cpp
//  CS2Final
//
//  Created by Samantha-Jo Cunningham on 5/6/18.
//  Copyright © 2018 Samantha-Jo Cunningham. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include "song.h"
#include "playlist.h"
#include "user.h"
#include "sort.h"
#include <vector>
string Find_Max_Likes();
using namespace std;

int main() {
    cout << "WELCOME TO YOUR MUSIC PLAYER\n" << endl;
    string max_likes, nameofUser;
    User::userName(nameofUser);
    int selection;
    string nameofPlaylist;
    do {
        cout << "*********MENU*********\n";
        cout << "1. Load & name playlist\n";
        cout << "2. Play playlist\n";
        cout << "3. Update user information\n";
        cout << "4. Add Song to playlist\n";
        cout << "5. Quit\n";
        cout << "Make a menu selection 1-5: " << endl;
        cin >> selection;
        cout << endl;
    
        switch (selection)
        {
            case 1:
                Playlist::loadPlaylist();
                nameofPlaylist = Playlist::playlistName(nameofPlaylist);
                break;
                
            case 2:
                cout << "Now playing your playlist: " << nameofPlaylist << endl;
                Playlist::playPlaylist();
                cout << endl;
                break;
                
            case 3:
                User::userName(nameofUser);
                break;
            
            case 4:
                
                max_likes = Find_Max_Likes();
                Playlist::AddNewSong(max_likes);
                break;

            case 5:
                cout << "Have a Good Day!";
                break;
                
            default:
                cout << "Invalid menu option. Please choose again\n";
                break;
        }
    }
    while (selection != 5);
    
    return 0;    
}
string Find_Max_Likes(){
    //loop(getline,find space,.substr() for likes num(check for max each time))
    ifstream myfile;
    string max_likes="", line="",previous="", like="";
    int space_index;
    myfile.open("playlist.txt");
    /*
    Looping until end of file:
        reads the line
        finds the first tab
        cuts out the first set of data(the likes for that song)
        and updates the highest num of likes encountered thus far.
    */
    while(!myfile.eof()){
        getline(myfile,line);
        space_index = line.find("   ");
        like = line.substr(0,space_index);
        if(like > previous){
            max_likes = like;
        }
        previous = like;
    }
    
    return max_likes;
}
