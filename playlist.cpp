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
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <ctime>
#include "playlist.h"
#include "song.h"
#include <algorithm>
#include "sort.h"

using namespace std;

string Playlist::playlistName(string nameofPlaylist) {
    cout << "Name your playlist: ";
    cin.get();
    getline(cin, nameofPlaylist);
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
    cout << "Playlist loaded" << endl;
    return;

}

void Playlist::playPlaylist(){
    ifstream inFS; //create an input file
    ifstream inFS2; //create an input file

    ofstream outFS;
    vector<string> MyPlaylist;
    vector<int> Songlikes;
    song playlistSongs;
    
    inFS.open("playlist.txt"); //opens the input file  playlist.txt
    
    // checks to see if the input file opens and if it did not it lets the user knows it could not opened
    if (!inFS.is_open()) {
        cout << "Could not open file playlist.txt" << endl;
        return;
    }
    outFS.open("sortedPlaylist.txt"); //create a output file to store the sorted playlist
    if (!outFS.is_open()) {
        cout << "Could not open file sortedPlaylist.txt" << endl;
        return;
    }

    //create variables
    string artist;
    string playlists;
    string songs;
    string title;
    string duration;
    string genre;
    string likes;
    while (!inFS.eof()){ //loops through the file until it gets to the end of the file
        

        getline (inFS, playlists, '\n'); //push everysong into the MyPlaylist vector
        MyPlaylist.push_back(playlists);
        
    }
    unsigned long int Playlistsize = MyPlaylist.size();
    sort(MyPlaylist.rbegin(), MyPlaylist.rend() ); //sort the playlist in descending order
    for(int i = 0; i < Playlistsize; i++){
        outFS << MyPlaylist.at(i) <<'\n'; //Store the sorted playlist in an output file
    }
    outFS.close(); //closes the output file
    inFS2.open("sortedPlaylist.txt"); //opens the input file  sortedPlaylist.txt
    
    // checks to see if the input file opens and if it did not it lets the user knows it could not opened
    if (!inFS2.is_open()) {
        cout << "Could not open file sortedPlaylist.txt" << endl;
        return;
    }
    //while (!inFS2.eof()){ //loops through the file until it gets to the end of the file
    for (int j = 0 ; j < Playlistsize - 1; j++) {
        getline (inFS2, likes, '\t');
        playlistSongs.SetLikes(likes);; //gets the complete string that is followed by a tab
        
        getline (inFS2, artist, '\t');
        playlistSongs.SetArtist(artist);
        
        getline (inFS2, title, '\t');
        playlistSongs.SetTitle(title);
        
        getline (inFS2, duration, '\t');
        playlistSongs.SetDuration(duration);
        
        getline (inFS2, genre, '\n');//gets the complete string that is followed by the end of the line
        playlistSongs.SetGenre(genre);
        //outputs to file file class_songs.txt
        cout << playlistSongs.GetLikes() << ". " << "\"" << playlistSongs.GetTitle() << "\" by " << playlistSongs.GetArtist() << " with a duration of " <<  playlistSongs.GetDuration() << " and genre of " << playlistSongs.GetGenre() << endl;
        if(inFS2.eof()){
            break;
        };
    }

    inFS.close(); //closes the playlist.txt input file
    inFS2.close(); //closes the playlist.txt input file
    
}

void Playlist::AddNewSong(int max_likes){
    string artist, dummy;
    string title;
    string duration;
    string genre;
    int likes;
    cout << "\tSong Addition\n\n";
    cin.get();
    getline(cin, dummy);
    try {
        cout << "Song Name: ";
        cin.get();
        getline(cin,title); cout << endl;
        if (title == "") {
            throw runtime_error("Invalid Title");
        }
    }
    catch (runtime_error& excpt){
        cout << excpt.what() << endl;
        cout << "Enter a valid title" << endl;
        
    }
    try {
        cout << "Song Artist: ";
        cin.get();
        getline(cin,artist); cout << endl;
        if (artist == "") {
            throw runtime_error("Invalid Artist");
        }
    }
    catch (runtime_error& excpt){
        cout << excpt.what() << endl;
        cout << "Enter a valid title" << endl;
    }
    try {
        cout << "Song Duration: ";
        cin.get();
        getline(cin,duration); cout << endl;
        if (duration == "") {
            throw runtime_error("Invalid Duration");
        }
    }
    catch (runtime_error& excpt){
        cout << excpt.what() << endl;
        cout << "Enter a valid duration" << endl;
    }
    try {
    cout << "Song Genre: ";
    cin.get();
    getline(cin, genre); cout << endl;
        if (artist == "") {
            throw runtime_error("Invalid Genre");
        }
    }
    catch (runtime_error& excpt){
        cout << excpt.what() << endl;
        cout << "Enter a valid Genre" << endl;
    }

    likes = max_likes + 1;
    
    //Printing new song to the file
    ofstream file;
    file.open("playlist.txt",ios_base::app);
    file << "\n" << likes << "\t" << artist << "\t" << title << "\t" << duration << "\t" << genre << "\n";
    file.close();
    //Now to write the new song data to the playlist file
    //suggest to user to reload playlist
}
