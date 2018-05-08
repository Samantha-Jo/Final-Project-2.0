//
//  song.cpp
//  CS2Final
//
//  Created by Samantha-Jo Cunningham on 5/6/18.
//  Copyright © 2018 Samantha-Jo Cunningham. All rights reserved.
//

#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

#include "song.h"

song::song(){

}

song::song(string artist, string title, string duration, string genre, string likes){
    this->artist = artist;
    this->title = title;
    this->duration = duration;
    this->genre = genre;
    this->likes = likes;
}

void song::SetArtist(string songArtist) {
    artist = songArtist;
    return;
};

void song::SetTitle(string songTitle) {
    title = songTitle;
    return;
    
}

void song::SetDuration(string songDuration) {
    duration = songDuration;
    return;
}

void song::SetGenre(string songGenre) {
    genre = songGenre;
    return;
}

void song::SetLikes(string songLikes) {
    likes = songLikes;
    return;
}

string song::GetArtist() const {
    return artist;
}

string song::GetTitle() const {
    return title;
}

string song::GetDuration() const {
    return duration;
}

string song::GetGenre() const {
    return genre;
}

string song::GetLikes() const {
    return likes;
}
song::~song(){}