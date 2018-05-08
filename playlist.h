//
//  playlist.h
//  CS2Final
//
//  Created by Samantha-Jo Cunningham on 5/6/18.
//  Copyright © 2018 Samantha-Jo Cunningham. All rights reserved.
//

#ifndef playlist_h
#define playlist_h

#include <string>
#include <vector>
#include "song.h"

using namespace std;

class Playlist { //create the song class
    //create public variables
public:
    //mutators
    static string playlistName(string nameofPlaylist);
    static void loadPlaylist();
    static void playPlaylist();
    static void AddNewSong(int max_likes);
};

#endif /* playlist_h */
