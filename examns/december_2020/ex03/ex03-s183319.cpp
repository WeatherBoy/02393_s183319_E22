#include <iostream>
#include <algorithm>
#include "ex03-library.h"
using namespace std;

// Do not modify
SongDatabase::SongDatabase() {
    this->songs.push_back("Penny Lane");
    this->songsInfo["Penny Lane"] = {"https://youtu.be/S-rB0pHI9fU", 8};

    this->songs.push_back("Trololo");
    this->songsInfo["Trololo"] = {"https://youtu.be/oavMtUWDBTM", 10};

    this->songs.push_back("Ob-La-Di, Ob-La-Da");
    this->songsInfo["Ob-La-Di, Ob-La-Da"] = {"https://youtu.be/_J9NpHKrKMw", 2};

    this->songs.push_back("Don't Worry, Be Happy");
    this->songsInfo["Don't Worry, Be Happy"] = {"https://youtu.be/d-diB65scQU", 3};

    this->songs.push_back("Leave My Kitten Alone");
    this->songsInfo["Leave My Kitten Alone"] = {"https://youtu.be/7BKsy9-Bvok", 5};
}

// Task 3(a).  Implement this method
void SongDatabase::display() {
    for(auto song: this->songs) {
        if(this->songsInfo.find(song) != this->songsInfo.end()) {
            // Looping over every song in songs
            Info song_info = this->songsInfo[song];
            cout << "title=" << song << "; ";
            cout << "url=" << song_info.url << "; ";
            cout << "score=" << song_info.score << endl;

        }        
    }
}

// Task 3(b).  Implement this method
bool SongDatabase::addSong(string title, string url, unsigned int score) {
    int const max_score = 10;
    if(find(this->songs.begin(), this->songs.end(), title) == this->songs.end()) {
        // We need to make sure that the title doesn't already recide within
        // the songs vector (we do this by using the find() function).
        if (score <= max_score) {
            // only if score is less than or equal to max_score, do we proceed.
            this->songs.push_back(title);
            this->songsInfo[title] = {url, score};
            return true;
        }
    }

    return false;
}

// Task 3(c).  Implement this method
void SongDatabase::searchSongs(string howGood) {
    for(auto song: this->songs) {
        // Looping over all the songs in the database
        if(this->songsInfo.find(song) != this->songsInfo.end()) {
            // renaming for easier access
            Info song_info = this->songsInfo[song];

            // if the song is in songInfo we do this weird-ass
            // if-statement
            if ((howGood == "abysmal" && song_info.score < 3) ||
                (howGood == "lousy" && 3 <= song_info.score && song_info.score < 5) ||
                (howGood == "meh" && 5 <= song_info.score && song_info.score < 7) ||
                (howGood == "cool" && 7 <= song_info.score && song_info.score < 9) ||
                (howGood == "OMG" && song_info.score > 9)) {
                    cout << "title=" << song << "; ";
                    cout << "url=" << song_info.url << "; ";
                    cout << "score=" << song_info.score << endl;

            }
        }
    }
}
