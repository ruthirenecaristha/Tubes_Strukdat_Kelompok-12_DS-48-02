#ifndef PLAYDESONG_H_INCLUDED
#define PLAYDESONG_H_INCLUDED

#include <iostream>
using namespace std;

struct record {
    string idLagu;
    string judul;
    string artis;
    string album;
    int year;
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

struct stackH {
    adrSong info[100];
    int top;
};

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
adrSong createElementSong(string idLagu, string judul, string artis, string album, int year, int durasi, bool fav);
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
adrSinger findSingerbyElemSong(listLibrary library, adrSong sg);

void displayAllSongfromASinger(adrSinger s);
void displayAllSongfromAPlaylist(adrPlaylist pl);
void displayLibrary(listLibrary library);
void displayPlaylist(daftarPlaylist playlists);

void deleteSongsfromAll(listLibrary &library, daftarPlaylist &playlists, string judul, string namaArtis);
void updateSongsfromAll(listLibrary &library, daftarPlaylist &playlists, string judul);
void deletePlaylist(daftarPlaylist &playlists, string kodePL);
void deleteSongElement(adrPlaylist &pl, adrSong spl);
void deleteSongLibrary(adrSinger &s, adrSong sg);

void mainMenuAdmin();
void menuUser();

void createStackH(stackH &history);
void push(stackH &history, adrSong sg);
void pop(stackH &history, adrSong sg);
void showHistory(stackH history);
void listeningTime(stackH history);

void playSong(stackH &history, adrSong sg);
void stopSong();
void nextSong(adrSong &sg, adrSinger s, adrPlaylist pl);
void prevSong(adrSong &sg, adrSinger s, adrPlaylist pl);

void songFlagStatus(listLibrary &library, daftarPlaylist &playlists, string judul);
void controlMusicPlayer(adrSong sg, adrSinger s, adrPlaylist pl, stackH &history);
void dummyData(listLibrary &library, daftarPlaylist &playlists);

#endif // PLAYDESONG_H_INCLUDED
