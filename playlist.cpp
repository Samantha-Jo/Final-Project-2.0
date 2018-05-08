//
//  playlist.cpp
//  CS2Final
//
//  Created by Samantha-Jo Cunningham on 5/7/18.
//  Copyright © 2018 Samantha-Jo Cunningham. All rights reserved.
//

#include <sstream>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <ios>
#include <ctime>
#include "playlist.h"
#include "song.h"
#include "sort.h"

using namespace std;

string Playlist::playlistName(string nameofPlaylist) {
    cout << "Name your playlist: ";
    cin >> nameofPlaylist;
    cout << endl;
    return nameofPlaylist;
}

void Playlist::loadPlaylist(){
    ifstream inFS; //create an input file
    vector<string> playlist;
    
    inFS.open("playlist.txt"); //opens the input file  playlist.txt
    
    // checks to see if the input file opens and if it did not it lets the user knows it could not opened
    if (!inFS.is_open()) {
        cout << "Could not open file playlist.txt" << endl;
        return;
    }
    //create variables
    string artist;
    string title;
    string duration;
    string genre;
    string likes;
    //About to load the entire playlist in whatever order is in the file
    while (!inFS.eof()){ //loops through the file until it gets to the end of the file
        
        getline (inFS, likes, '\t');//gets the complete string that is followed by a tab
        playlist.push_back(likes);
        getline (inFS, artist, '\t');
        playlist.push_back(artist);
        getline (inFS, title, '\t');
        playlist.push_back(title);
        getline (inFS, duration, '\t');
        playlist.push_back(duration);
        getline (inFS, genre, '\n'); //gets the complete string that is followed by the end of the line
        playlist.push_back(genre);       
    }
    cout << endl;
    cout << "Playlist loaded" << endl;
    return;

}

void Playlist::playPlaylist(){
    ifstream inFS; //create an input file
    vector<string> playlist;
    song playlistSongs;
    
    inFS.open("playlist.txt"); //opens the input file  playlist.txt
    
    // checks to see if the input file opens and if it did not it lets the user knows it could not opened
    if (!inFS.is_open()) {
        cout << "Could not open file playlist.txt" << endl;
        return;
    }
    //create variables
    string artist;
    string title;
    string duration;
    string genre;
    string likes="";
    /*
    Errors:
        Needs to play them in order of the likes (descending order)
    */
   
    getline (inFS, likes, '\t');//gets the complete string that is followed by the end of the line
    playlistSongs.SetLikes(likes);

    getline (inFS, artist, '\t');
    playlistSongs.SetArtist(artist);
        
    getline (inFS, title, '\t');
    playlistSongs.SetTitle(title);
        
    getline (inFS, duration, '\t');
    playlistSongs.SetDuration(duration);
        
    getline (inFS, genre, '\n'); //gets the complete string that is followed by the end of the line
    playlistSongs.SetGenre(genre);  
    
    while (!inFS.eof()){ //loops through the file until it gets to the end of the file
        //outputs to file file class_songs.txt
        cout << playlistSongs.GetLikes() << ". " << playlistSongs.GetTitle() << " by " << playlistSongs.GetArtist() << " with a duration of " <<  playlistSongs.GetDuration() << " and genre of " << playlistSongs.GetGenre() << endl;

        getline (inFS, likes, '\t');//gets the complete string that is followed by the end of the line
        playlistSongs.SetLikes(likes);

        getline (inFS, artist, '\t');
        playlistSongs.SetArtist(artist);
        
        getline (inFS, title, '\t');
        playlistSongs.SetTitle(title);
        
        getline (inFS, duration, '\t');
        playlistSongs.SetDuration(duration);
        
        getline (inFS, genre, '\n'); //gets the complete string that is followed by the end of the line
        playlistSongs.SetGenre(genre);   
    }
}

void Playlist::AddNewSong(int max_likes){
    string artist, dummy;
    string title;
    string duration;
    string genre;
    int likes;
    cout << "\tSong Addition\n\n";
    getline(cin, dummy);
    cout << "Song Name: "; getline(cin,title); cout << endl;
    cout << "Song Artist: "; getline(cin,artist); cout << endl;
    cout << "Song Duration: "; getline(cin,duration); cout << endl;
    cout << "Song Genre: "; getline(cin, genre); cout << endl;
    likes = max_likes + 1;
    
    //Printing new song to the file
    ofstream file;
    file.open("playlist.txt",ios_base::app);
    file << "\n" << likes << "\t" << artist << "\t" << title << "\t" << duration << "\t" << genre << "\n";
    file.close();
    //Now to write the new song data to the playlist file
    //suggest to user to reload playlist
}
