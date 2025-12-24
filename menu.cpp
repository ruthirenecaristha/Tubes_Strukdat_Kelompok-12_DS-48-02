#include "playDeSong.h"
#include <string>
#include <iostream>
using namespace std;

void mainMenuAdmin(){
    cout << "Welcome Admin. What do you want to do?" << endl;
    cout << "1. Add New Singer" << endl;
    cout << "2. Add New Song to Singer" << endl;
    cout << "3. Delete Song" << endl;
    cout << "4. Update Song" << endl;
    cout << "5. Exit" << endl;;
}

void menuUser(){
    cout << "Welcome User. What do you want to do?"<< endl;
    cout << "1. Display Favourite Songs" << endl;
    cout << "2. Display All Playlist" << endl;
    cout << "3. Display All Song from Library" << endl;
    cout << "4. Search your Playlist" << endl;
    cout << "5. Search Song" << endl;
    cout << "6. Edit Playlist" << endl;
    cout << "7. Display All Songs from A Singer" << endl;
    cout << "8. View History and Listening Time" << endl;
    cout << "9. Exit" << endl;
}

void dummyData(listLibrary &library, daftarPlaylist &playlists){
    adrSinger s;
    adrPlaylist pl;

    s = createElementSinger("Laufey");
    addSingertoLibrary(library, s);
    addSongtoSinger(s, createElementSong("A01", "Like the Movies", "Laufey", "Typical of Me", 2021, 163, false));
    addSongtoSinger(s, createElementSong("A02", "Let You Break My Heart Again", "Laufey", "Let You Break My Heart Again", 2021, 269, false));
    addSongtoSinger(s, createElementSong("A03", "Valentine", "Laufey", "Everything I Know About Love", 2022, 169, false));
    addSongtoSinger(s, createElementSong("A04", "Falling Behind", "Laufey", "Everything I Know About Love", 2022, 174, false));
    addSongtoSinger(s, createElementSong("A05", "The Christmas Waltz", "Laufey", "A Very Laufey Holiday", 2022, 168, false));
    addSongtoSinger(s, createElementSong("A06", "From The Start", "Laufey", "Bewitched", 2023, 170, false));
    addSongtoSinger(s, createElementSong("A07", "Promise", "Laufey", "Bewitched", 2023, 234, false));

    s = createElementSinger("Bruno Mars");
    addSingertoLibrary(library, s);
    addSongtoSinger(s, createElementSong("B01", "Die With A Smile", "Bruno Mars", "Die With A Smile", 2024, 252, false));
    addSongtoSinger(s, createElementSong("B02", "That's What I Like", "Bruno Mars", "24K Magic", 2016, 207, false));
    addSongtoSinger(s, createElementSong("B03", "When I Was Your Man", "Bruno Mars", "Unorthodox Jukebox", 2012, 214, false));
    addSongtoSinger(s, createElementSong("B04", "Just The Way You Are", "Bruno Mars", "Doo-Woops & Hooligans", 2010, 221, false));
    addSongtoSinger(s, createElementSong("B05", "Locked Out of Heaven", "Bruno Mars", "Unorthodox Jukebox", 2012, 233, false));
    addSongtoSinger(s, createElementSong("B06", "Versace on the Floor", "Bruno Mars", "24K Magic", 2016, 261, false));

    s = createElementSinger("Nadin Amizah");
    addSingertoLibrary(library, s);
    addSongtoSinger(s, createElementSong("C01", "Semua Aku Dirayakan", "Nadin Amizah", "Semua Aku Dirayakan", 2023, 311, false));
    addSongtoSinger(s, createElementSong("C02", "Bertaut", "Nadin Amizah", "Selamat Ulang Tahun", 2020, 316, false));
    addSongtoSinger(s, createElementSong("C03", "Sorai", "Nadin Amizah", "Sorai", 2019, 278, false));
    addSongtoSinger(s, createElementSong("C04", "Di Akhir Perang", "Nadin Amizah", "Untuk Dunia, Cinta, dan Kotornya", 2023, 238, false));
    addSongtoSinger(s, createElementSong("C05", "Tapi Diterima", "Nadin Amizah", "Untuk Dunia, Cinta, dan Kotornya", 2023, 332, false));

    s = createElementSinger("James Arthur");
    addSingertoLibrary(library, s);
    addSongtoSinger(s, createElementSong("D01", "Can I Be Him", "James Arthur", "Back From the Edge", 2016, 247, false));
    addSongtoSinger(s, createElementSong("D02", "Say You Won't Let Go", "James Arthur", "Back From the Edge", 2016, 211, false));

    s = createElementSinger("Ariana Grande");
    addSingertoLibrary(library, s);
    addSongtoSinger(s, createElementSong("E01", "Into You", "Ariana Grande", "Dangerous Woman", 2016, 244, false));
    addSongtoSinger(s, createElementSong("E02", "Bloodline", "Ariana Grande", "thank u, next", 2019, 217, false));

    s = createElementSinger("Taylor Swift");
    addSingertoLibrary(library, s);
    addSongtoSinger(s, createElementSong("TS01", "Love Story", "Taylor Swift", "Fearless", 2008, 235, false));
    addSongtoSinger(s, createElementSong("TS02", "Blank Space", "Taylor Swift", "1989", 2014, 231, false));
    addSongtoSinger(s, createElementSong("TS03", "Anti-Hero", "Taylor Swift", "Midnights", 2022, 200, false));
    addSongtoSinger(s, createElementSong("TS04", "Cruel Summer", "Taylor Swift", "Lover", 2019, 178, false));
    addSongtoSinger(s, createElementSong("TS05", "Style", "Taylor Swift", "1989", 2014, 231, false));

    s = createElementSinger("Queen");
    addSingertoLibrary(library, s);
    addSongtoSinger(s, createElementSong("QN01", "Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 354, false));
    addSongtoSinger(s, createElementSong("QN02", "Don't Stop Me Now", "Queen", "Jazz", 1978, 209, false));
    addSongtoSinger(s, createElementSong("QN03", "We Will Rock You", "Queen", "News of the World", 1977, 121, false));
    addSongtoSinger(s, createElementSong("QN04", "Radio Ga Ga", "Queen", "The Works", 1984, 343, false));
    addSongtoSinger(s, createElementSong("QN05", "Another One Bites the Dust", "Queen", "The Game", 1980, 215, false));

    s = createElementSinger("Tulus");
    addSingertoLibrary(library, s);
    addSongtoSinger(s, createElementSong("TL01", "Hati-Hati di Jalan", "Tulus", "Manusia", 2022, 242, false));
    addSongtoSinger(s, createElementSong("TL02", "Sepatu", "Tulus", "Gajah", 2014, 230, false));
    addSongtoSinger(s, createElementSong("TL03", "Monokrom", "Tulus", "Monokrom", 2016, 214, false));
    addSongtoSinger(s, createElementSong("TL04", "Gajah", "Tulus", "Gajah", 2014, 240, false));
    addSongtoSinger(s, createElementSong("TL05", "Interaksi", "Tulus", "Manusia", 2022, 170, false));

    pl = createElementPlaylist("PL001", "Sad Songs to Cry in mi Room");
    addPlaylist(playlists, pl);
    addSongtoPlaylist(pl, createElementSong("A02", "Let You Break My Heart Again", "Laufey", "Let You Break My Heart Again", 2021, 269, false));
    addSongtoPlaylist(pl, createElementSong("D02", "Say You Won't Let Go", "James Arthur", "Back From the Edge", 2016, 211, false));

    pl = createElementPlaylist("PL002", "Morning Coffee");
    addPlaylist(playlists, pl);
    addSongtoPlaylist(pl, createElementSong("TL03", "Monokrom", "Tulus", "Monokrom", 2016, 214, false));
    addSongtoPlaylist(pl, createElementSong("TS01", "Love Story", "Taylor Swift", "Fearless", 2008, 235, false));
    addSongtoPlaylist(pl, createElementSong("TL02", "Sepatu", "Tulus", "Gajah", 2014, 230, false));
    addSongtoPlaylist(pl, createElementSong("TS05", "Style", "Taylor Swift", "1989", 2014, 231, false));

    pl = createElementPlaylist("PL003", "Funk the beat");
    addPlaylist(playlists, pl);
    addSongtoPlaylist(pl, createElementSong("QN02", "Don't Stop Me Now", "Queen", "Jazz", 1978, 209, false));
    addSongtoPlaylist(pl, createElementSong("TS04", "Cruel Summer", "Taylor Swift", "Lover", 2019, 178, false));
    addSongtoPlaylist(pl, createElementSong("QN05", "Another One Bites the Dust", "Queen", "The Game", 1980, 215, false));
    addSongtoPlaylist(pl, createElementSong("TS02", "Blank Space", "Taylor Swift", "1989", 2014, 231, false));
}

void controlMusicPlayer(adrSong sg, adrSinger s, adrPlaylist pl, stackH &history){
    int choice;
    bool isPlaying = true;

    playSong(history, sg);
    while (isPlaying && sg != nullptr){
        cout << "===== Menu Player =====" << endl;
        cout << "1. Play Next Song" << endl;
        cout << "2. Play Previous Song" << endl;
        cout << "3. Stop & Exit Menu" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        if (choice == 1){
            nextSong(sg, s, pl);
            playSong(history, sg);
        } else if (choice == 2){
            prevSong(sg, s, pl);
            playSong(history, sg);
        } else if (choice == 3){
            stopSong();
            isPlaying = false;
        } else {
            cout << "Your choice is not valid." << endl << endl;
        }
    }
}
