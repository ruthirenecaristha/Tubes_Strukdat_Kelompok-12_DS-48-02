#ifndef PLAYDESONG_H_INCLUDED
#define PLAYDESONG_H_INCLUDED

#include <iostream>
using namespace std;

struct record {
    string idLagu;
    string judul;
    string artis;
    string album;
    int durasi;
    bool fav;
};

struct infoPlaylist {
    string kodePL;
    string namaPlaylist;
};

typedef struct elementSinger *adrSinger;
typedef struct elementSong *adrSong;
typedef struct elementPlaylist *adrPlaylist;

struct elementSinger {
    string namaArtis;
    adrSinger next;
    adrSinger prev;
    adrSong firstSong;
    adrSong lastSong;
};

struct elementPlaylist {
    infoPlaylist info;
    adrPlaylist next;
    adrPlaylist prev;
    adrSong firstSong;
    adrSong lastSong;
};

struct elementSong {
    record info;
    adrSong prev;
    adrSong next;
};

struct listLibrary {
    adrSinger first;
    adrSinger last;
};

struct daftarPlaylist {
    adrPlaylist first;
    adrPlaylist last;
};

void createNewLibrary(listLibrary &library);
void createNewPlaylist(daftarPlaylist &playlists);
adrSinger createElementSinger(string nama);
adrSong createElementSong(string idLagu, string judul, string artis, string album, int durasi, bool fav);
adrPlaylist createElementPlaylist(string kodePL, string namaPlaylist);
bool isEmptyLibrary(listLibrary library);
bool isEmptyPlaylist(daftarPlaylist playlists);
void addSingertoLibrary(listLibrary &library, adrSinger s);
void addSongtoSinger(adrSinger &s, adrSong sg);
void addSongtoPlaylist(adrPlaylist &pl, adrSong sg);
void addPlaylist(daftarPlaylist &playlist, adrPlaylist pl);
adrPlaylist searchPlaylist(daftarPlaylist playlists, string kodePL);
adrSinger searchSinger(listLibrary library, string namaArtis);
adrSong searchSong(listLibrary library, string judul);
void displayAllSongfromASinger(adrSinger s);
void displayAllSongfromAPlaylist(adrPlaylist pl);


#endif // PLAYDESONG_H_INCLUDED
