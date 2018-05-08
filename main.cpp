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
int Find_Max_Likes();
using namespace std;

int main() {
    cout << "WELCOME TO YOUR MUSIC PLAYER\n" << endl;
    string nameofUser="", nameofPlaylist="";
    nameofUser = User::userName(nameofUser);
    int max;
    int selection;
    do {
        cout << "*********MENU*********\n";
        cout << "1. Load & name playlist\n";
        cout << "2. Play playlist\n";
        cout << "3. Update user information\n";
        cout << "4. Add Song to playlist\n";
        cout << "5. Quit\n";
        cout << "Pick a menu selection 1-5: " << endl;
        cin >> selection;
        cout << endl;
    
        switch (selection)
        {
            case 1:
                try {
                    Playlist::loadPlaylist();
                    nameofPlaylist = Playlist::playlistName(nameofPlaylist);
                    if (nameofPlaylist == "") {
                        throw runtime_error("Invalid PlaylistName");
                    }
                }
                catch (runtime_error& excpt){
                    cout << excpt.what() << endl;
                    cout << "Cannot load playlist." << endl;
                }
                break;
                
            case 2:
                try {
                    cout << "Now playing your playlist: " << nameofPlaylist << endl;
                    Playlist::playPlaylist();
                    cout << endl;
                }
                catch (runtime_error& excpt){
                    cout << excpt.what() << endl;
                    cout << "Playlist cannot be played" << endl;
                }
                break;
                
            case 3:
               try {
                    cout << "Update User Information" << endl;
                    nameofUser = User::userName(nameofUser);
                }
                catch (runtime_error& excpt){
                    cout << excpt.what() << endl;
                    cout << "Cannot update user information" << endl;
                }
                break;
            
            case 4:
                try{
                    max = Find_Max_Likes();
                    Playlist::AddNewSong(max);
                    cout << "We suggest you reload the playlist\n";
                }
                catch (runtime_error& excpt){
                    cout << excpt.what() << endl;
                    cout << "Cannot Add song to Playlist" << endl;
                }
                break;

            case 5:
                cout << "Good Bye :(.. See You Soon!" << endl;
                break;
                
            default:
                cout << "Invalid menu option. Please choose again\n";
                break;
        }
    }
    while (selection != 5);
    
    return 0;
        
}

int Find_Max_Likes(){
    
    //GETLINE IN WHOLE THING INTO A VECTOR
    //AND USE SIZE OF VECTOR AS MAX_LIKES
    
    ifstream myfile; string line;
    int count=0;
    myfile.open("playlist.txt");
    
    if(!myfile.is_open()){
        cout << "Couldn't open playlist.txt" <<endl;
    }
    /*Looping until end of file:
        uses getline to move line by line
        meanwhile we are counting each line to get max likes
        Assumtption: max likes == total # of songs in playlist
     */
    while(!myfile.eof()){
        getline(myfile,line);
        if(line!=""){
            count++;
        }
        line="";
    }
    myfile.close();
    return count;
}
