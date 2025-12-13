#include <iostream>
#include "playDeSong.h"
using namespace std;

void createNewPlaylist(daftarPlaylist &playlists){
    playlists.first = nullptr;
    playlists.last = nullptr;
}

void createNewLibrary(listLibrary &library){
    library.first = nullptr;
    library.last = nullptr;
}

adrSinger createElementSinger(string nama){
    adrSinger s = new elementSinger;
    s->firstSong = nullptr;
    s->lastSong = nullptr;
    s->namaArtis = nama;
    s->next = nullptr;
    s->prev = nullptr;
    return s;
}

adrPlaylist createElementPlaylist(string kodePL, string namaPlaylist){
    adrPlaylist pl = new elementPlaylist;
    pl->info.kodePL = kodePL;
    pl->info.namaPlaylist = namaPlaylist;
    pl->firstSong = nullptr;
    pl->lastSong = nullptr;
    pl->next = nullptr;
    pl->prev = nullptr;
    return pl;
}

adrSong createElementSong(string idLagu, string judul, string artis, string album, int year, int durasi, bool fav){
    adrSong sg = new elementSong;
    sg->info.album = album;
    sg->info.artis = artis;
    sg->info.durasi = durasi;
    sg->info.fav = fav;
    sg->info.idLagu = idLagu;
    sg->info.judul = judul;
    sg->info.year = year;
    sg->next = nullptr;
    sg->prev = nullptr;
    return sg;
}

bool isEmptyLibrary(listLibrary library){
    return (library.first == nullptr && library.last == nullptr);
}

bool isEmptyPlaylist(daftarPlaylist playlists){
    return (playlists.first == nullptr && playlists.last == nullptr);
}

void addSingertoLibrary(listLibrary &library, adrSinger s){
//I.S Ada kemungkinan list kosong (perlu insertFirst). Jika list tidak kosong, data dimasukkan paling akhir//
    if (isEmptyLibrary(library)){
        library.first = s;
        library.last = s;
    } else {
        library.last->next = s;
        s->prev = library.last;
        library.last = s;
    }
}

void addPlaylist(daftarPlaylist &playlists, adrPlaylist pl){
//I.S Ada kemungkinan list kosong (perlu insertFirst). Jika list tidak kosong, data dimasukkan paling akhir//
    if (isEmptyPlaylist(playlists)){
        playlists.first = pl;
        playlists.last = pl;
    } else {
        playlists.last->next = pl;
        pl->prev=playlists.last;
        playlists.last = pl;
    }
}

void addSongtoSinger(adrSinger &s, adrSong sg){
    if (s->firstSong == nullptr && s->lastSong == nullptr){
        s->firstSong = sg;
        s->lastSong = sg;
    } else {
        s->lastSong->next = sg;
        sg->prev = s->lastSong;
        s->lastSong = sg;
    }
}

void addSongtoPlaylist(adrPlaylist &pl, adrSong sg){
    if (pl->firstSong == nullptr && pl->lastSong == nullptr){
        pl->firstSong = sg;
        pl->lastSong = sg;
    } else {
        pl->lastSong->next = sg;
        sg->prev = pl->lastSong;
        pl->lastSong = sg;
    }
}

adrPlaylist searchPlaylist(daftarPlaylist playlists, string kodePL){
    if (isEmptyPlaylist(playlists)){
        return nullptr;
    } else {
        adrPlaylist pl = playlists.first;
        while (pl != nullptr){
            if (pl->info.kodePL == kodePL){
                return pl;
            }
            pl = pl->next;
        }
        return nullptr;
    }
}

adrSinger searchSinger(listLibrary library, string namaArtis){
    if (isEmptyLibrary(library)){
        return nullptr;
    } else {
        adrSinger s = library.first;
        while (s != nullptr){
            if (s->namaArtis == namaArtis){
                return s;
            }
            s = s->next;
        }
        return nullptr;
    }
}

adrSong searchSong(listLibrary library, string judul){
    if(isEmptyLibrary(library)){
        return nullptr;
    } else {
        adrSinger s = library.first;
        while (s != nullptr){
            adrSong sg = s->firstSong;
            while (sg != nullptr){
                if (sg->info.judul == judul){
                    return sg;
                }
                sg = sg->next;
            }
            s = s->next;
        }
        return nullptr;
    }
}

void displayAllSongfromASinger(adrSinger s){
    adrSong sg = s->firstSong;
    cout << "Songs list by: " << s->namaArtis << endl;
    if (sg != nullptr){
        while (sg != nullptr){
            cout << "ID Lagu: " << sg->info.idLagu << endl;
            cout << "Judul: " << sg->info.judul << endl;
            cout << "Album: " << sg->info.album << endl;
            cout << "Tahun rilis: " << sg->info.year << endl;
            cout << "Durasi (dalam detik): " << sg->info.durasi << endl;
            if (sg->info.fav){
                cout << "Lagu berada di dalam list lagu favorit." << endl;
            } else {
                cout << "Lagu tidak berada di dalam list lagu favorit." << endl;
            }
            sg = sg->next;
        }
    } else {
        cout << s->namaArtis << " belum memiliki lagu." << endl;
    }
}

void displayAllSongfromAPlaylist(adrPlaylist pl){
    adrSong sg = pl->firstSong;
    cout << "Lagu dalam playlist " << pl->info.namaPlaylist << endl;
    if (sg != nullptr){
        while (sg != nullptr){
            cout << "ID Lagu: " << sg->info.idLagu << endl;
            cout << "Judul: " << sg->info.judul << endl;
            cout << "Artis: " << sg->info.artis << endl;
            cout << "Album: " << sg->info.album << endl;
            cout << "Tahun dirilis: " << sg->info.year << endl;
            cout << "Durasi (dalam detik): " << sg->info.durasi << endl;
            if (sg->info.fav){
                cout << "Lagu berada di dalam list lagu favorit." << endl;
            } else {
                cout << "Lagu tidak berada di dalam list lagu favorit." << endl;
            }
            sg = sg->next;
        }
    } else {
        cout << "Tidak ada lagu di dalam playlist " << pl->info.namaPlaylist << endl;
    }
}

void deleteSongsfromAll(listLibrary &library, daftarPlaylist &playlists, string judul){

}
