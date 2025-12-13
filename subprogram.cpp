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

void displayLibrary(listLibrary library){
    if (!isEmptyLibrary(library)){
        adrSinger s = library.first;
        while (s != nullptr){
            displayAllSongfromASinger(s);
            cout << endl;
            s = s->next;
        }
    } else {
        cout << "No singer recorded in library." << endl;
    }
}

void displayPlaylist(daftarPlaylist playlists){
    if (!isEmptyPlaylist(playlists)){
        adrPlaylist pl = playlists.first;
        while (pl != nullptr){
            displayAllSongfromAPlaylist(pl);
            cout << endl;
            pl = pl->next;
        }
    } else {
        cout << "You don't have any playlist. Let's make one!" << endl;
    }
}

void deleteSongsfromAll(listLibrary &library, daftarPlaylist &playlists, string judul, string namaArtis){
    adrSinger s = searchSinger(library, namaArtis);
    if (s == nullptr){
        cout << "Artis tidak ditemukan." << endl;
    } else {
        adrSong sg = s->firstSong;
        bool found = false;
        while (!found){
            if (sg->info.judul == judul){
                found = true;
            }
            sg = sg->next;
        }

        if (!found){
            cout << "Lagu tidak ditemukan." << endl;
        } else {
            string iDsong = sg->info.idLagu;
            adrPlaylist pl = playlists.first;
            while (pl != nullptr){
                adrSong spl = pl->firstSong;
                while (spl != nullptr){
                    adrSong temp = spl->next;
                    if (spl->info.idLagu == iDsong){
                        deleteSongElement(pl, spl);
                    }
                    spl = temp;
                }
                pl = pl->next;
            }
            deleteSongLibrary(s, sg);
            cout << "Lagu " << judul << " berhasil dihapus dari Library dan seluruh Playlist." << endl;
        }
    }
}

void deleteSongElement(adrPlaylist &pl, adrSong spl){
    adrSong first = pl->firstSong;
    adrSong last = pl->lastSong;
    if (spl == first){
        first = first->next;
        first->prev = nullptr;
    } else if (spl == last){
        last = last->prev;
        last->next = nullptr;
    } else if (spl == first && spl == last){
        first = nullptr;
        last = nullptr;
    } else {
        spl->prev->next = spl->next;
        spl->next->prev = spl->prev;
    }
}

void deleteSongLibrary(adrSinger &s, adrSong sg){
    adrSong first = s->firstSong;
    adrSong last = s->lastSong;
    if (sg == first){
        first = first->next;
        first->prev = nullptr;
    } else if (sg == last){
        last = last->prev;
        last->next = nullptr;
    } else if (sg == first && sg == last){
        first = nullptr;
        last = nullptr;
    } else {
        sg->prev->next = sg->next;
        sg->next->prev = sg->prev;
    }
}

void deletePlaylist(daftarPlaylist &playlists, string kodePL){
    adrPlaylist foundPL = searchPlaylist(playlists, kodePL);
    if (foundPL == nullptr){
        cout << "Playlist not found." << endl;
    } else {
        while (foundPL->firstSong !=nullptr){
            adrSong spl = foundPL->firstSong;
            deleteSongElement(foundPL, spl);
        }
        if (foundPL == playlists.first && foundPL == playlists.last){
            playlists.first = nullptr;
            playlists.last = nullptr;
        } else if (foundPL == playlists.first){
            playlists.first = foundPL->next;
            playlists.first->prev = nullptr;
        } else if (foundPL == playlists.last){
            playlists.last = foundPL->prev;
            playlists.last->next = nullptr;
        } else {
            foundPL->prev->next = foundPL->next;
            foundPL->next->prev = foundPL->prev;
        }
        cout << "Playlist " << foundPL->info.namaPlaylist << " has been deleted." << endl;
    }
}

void createStackH(stackH &history){
    history.top = -1;
}

void push(stackH &history, adrSong sg){
    if (history.top < 100){
        history.top = history.top + 1;
        history.info[history.top] = sg;
    } else {
        cout << "Your history is full. Aren't you listening too much songs?" << endl;
    }
}

void showHistory(stackH history){
    int i;
    cout << "========== History ==========" << endl;
    if (history.top == -1){
        cout << "You haven't listened to any songs." << endl;
    } else {
        for (i = history.top; i > -1; i--){
            if (history.info[i] != nullptr){
                cout << "- " << history.info[i]->info.judul << " by " << history.info[i]->info.artis <<  endl;
            }
        }
    }
}

void listeningTime(stackH history){
    int total = 0;
    int i, minutes, secs;
    for (i = history.top; i > -1; i--){
        if (history.info[i] != nullptr){
            total = total + history.info[i]->info.durasi;
        }
    }

    minutes = total / 60;
    secs = total % 60;

    cout << "You listened to songs for " << minutes << " minutes and " << secs << " seconds." << endl;
}

void playSong(stackH &history, adrSong sg){
    if (sg != nullptr){
        cout << sg->info.judul << " by " << sg->info.artis << " is playing." << endl;
        cout << "Duration: " << sg->info.durasi << " detik." << endl;
        push(history, sg);
    }
}

void stopSong(){
    cout << "The song is stopped." << endl;
}

adrSinger findSingerbyElemSong(listLibrary library, adrSong sg){
    adrSinger s = library.first;
    adrSong tempSg;

    while (s != nullptr){
        tempSg = s->firstSong;
        while (tempSg != nullptr){
            if (tempSg == sg){
                return s;
            }
            tempSg = tempSg->next;
        }
        s = s->next;
    }
    return nullptr;
}

void nextSong(adrSong &sg, adrSinger s, adrPlaylist pl){
    if (pl != nullptr){
        if (sg->next != nullptr){
            sg = sg->next;
        } else {
            cout << "The first song in the playlist will be played." << endl;
            sg = pl->firstSong;
        }
    } else if (s != nullptr){
        if (sg->next != nullptr){
            sg = sg->next;
        } else {
            sg = s->firstSong;
        }
    }
    cout << "Next song: " << sg->info.judul << " by " << sg->info.artis << endl;
}

void prevSong(adrSong &sg, adrSinger s, adrPlaylist pl){
    if (pl != nullptr){
        if (sg->prev != nullptr){
            sg = sg->prev;
        } else {
            cout << "The first song in the playlist will be played." << endl;
            sg = pl->lastSong;
        }
    } else if (s != nullptr){
        if (sg->prev != nullptr){
            sg = sg->prev;
        } else {
            sg = s->lastSong;
        }
    }
    cout << "Previus song: " << sg->info.judul << " by " << sg->info.artis << endl;
}

