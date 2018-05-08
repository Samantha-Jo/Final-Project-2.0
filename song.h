//
//  song.h
//  CS2Final
//
//  Created by Samantha-Jo Cunningham on 5/6/18.
//  Copyright © 2018 Samantha-Jo Cunningham. All rights reserved.
//

#ifndef song_h
#define song_h

#include <string>
using namespace std;

class song { //create the song class
    //create public variables
public:
    //mutators
    void SetArtist(string songArtist);
    void SetTitle(string songTitle);
    void SetDuration(string songDuration);
    void SetGenre(string songGenre);
    void SetLikes(string songLikes);
    
    //accessors
    string GetArtist() const;
    string GetTitle() const;
    string GetDuration() const;
    string GetGenre() const;
    string GetLikes() const;
    
    //creats private variables
private:
    string artist;
    string title;
    string duration;
    string genre;
    string likes;
    
};

#endif /* song_h */
