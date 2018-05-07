//
//  main.cpp
//  CS2Final
//
//  Created by Samantha-Jo Cunningham on 5/6/18.
//  Copyright © 2018 Samantha-Jo Cunningham. All rights reserved.
//

#include <iostream>
#include "song.h"
#include "playlist.h"
#include "user.h"
#include <vector>
using namespace std;

int main() {
    cout << "WELCOME TO YOUR MUSIC PLAYER\n" << endl;
    string nameofUser;
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
            
            case 4:
                cout << "I just want to talk to my friends.";
                break;

            case 5:
                cout << "I just want to talk to my friends.";
                break;
                
            default:
                cout << "Invalid menu option. Please choose again\n";
                break;
        }
    }
    while (selection != 5);
    
        
}
