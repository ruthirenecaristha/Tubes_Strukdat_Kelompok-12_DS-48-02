#include <iostream>
#include <string>
#include "playDeSong.h"

using namespace std;

int main(){
    listLibrary library;
    daftarPlaylist playlists;
    stackH history;
    adrPlaylist pl;
    adrSinger s;
    adrSong sg;
    int choice, songYear, songDur;
    string login, password, nama, songTitle, songAlbum, songId, kodePL, namaPL;

    createNewLibrary(library);
    createNewPlaylist(playlists);
    pl = createElementPlaylist("PLFAV", "Fav_Songs");
    addPlaylist(playlists, pl);

    createStackH(history);
    dummyData(library, playlists);


    cout << "=============== Welcome to PlayDeSong ===============" << endl;
    cout << "Log in required before you enter the app!" << endl;
    cout << "Login as (admin/user): ";
    cin >> login;
    cout << "Enter your password: ";
    cin >> password;
    cout << endl;
    cout << "Please wait while we check your identity." << endl;

    if (login == "admin" && password == "playDeSongAdm"){
        cout << "You logged in as Admin." << endl;
        do {
            cout << "---------- ADMIN DASHBOARD ----------" << endl;
            mainMenuAdmin();
            cout << "Choose menu (1-5): ";
            cin >> choice;
            cout << endl;

            switch (choice){
                // Add Singer to Library
                case 1:{
                    cout << "Enter new singer name: ";
                    cin.ignore();
                    getline(cin, nama);
                    s = createElementSinger(nama);
                    addSingertoLibrary(library, s);
                    cout << s->namaArtis << " has been added to library." << endl << endl;
                    displayLibrary(library);
                    cout << endl;
                    break; // REVISI: Tambahkan break
                }
                // Add Song to Singer List
                case 2:{
                    cout << "Who's the singer? ";
                    cin.ignore();
                    getline(cin, nama);
                    s = searchSinger(library, nama);
                    if (s != nullptr){
                        cout << "Enter the Song ID: ";
                        cin >> songId;
                        cout << "Enter the song title: ";
                        cin.ignore();
                        getline(cin, songTitle);
                        cout << "Enter the song album: ";
                        getline(cin, songAlbum); // Hapus cin.ignore() kedua jika berurutan getline
                        cout << "Year: ";
                        cin >> songYear;
                        cout << "Song Duration (in seconds): ";
                        cin >> songDur;
                        sg = createElementSong(songId, songTitle, nama, songAlbum, songYear, songDur, false);
                        addSongtoSinger(s, sg);
                        cout << "The song has been added to singer list." << endl << endl;
                        displayAllSongfromASinger(s);
                        cout << endl;
                    } else {
                        cout << "Singer named " << nama << " is not found." << endl << endl;
                    }
                    break; // REVISI: Tambahkan break
                }
                // Delete Song
                case 3:{
                    cout << "Enter the singer name: ";
                    cin.ignore();
                    getline(cin, nama);
                    cout << "Enter the song title: ";
                    // Hapus cin.ignore disini jika sebelumnya getline, tapi aman pakai ignore jika ragu sisa buffer
                    getline(cin, songTitle);
                    deleteSongsfromAll(library, playlists, songTitle, nama);
                    displayLibrary(library);
                    break; // REVISI: Tambahkan break
                }
                // Update song
                case 4:{
                    cout << "Song Title that you want to edit: ";
                    cin.ignore();
                    getline(cin, songTitle);
                    s = searchSinger(library, (searchSong(library, songTitle)->info.artis));
                    updateSongsfromAll(library, playlists, songTitle);
                    displayAllSongfromASinger(s);
                    break; // REVISI: Tambahkan break
                }
                // Exit
                case 5:{
                    cout << "Logged you out. c u, admin ;)" << endl << endl;
                    break; // REVISI: Tambahkan break
                }
                default:{
                    cout << "Invalid input." << endl;
                    break;
                }
            }
        } while (choice != 5);
    } else if (login == "user" && password == "musicGeeks"){
        cout << "You logged in as User." << endl;
        do {
            cout << "---------- USER DASHBOARD ----------" << endl;
            menuUser();
            cout << "Choose menu (1-9): ";
            cin >> choice;
            cout << endl;

            switch (choice){
                // Display Favourite Songs
                case 1:{
                    adrPlaylist pFav = searchPlaylist(playlists, "PLFAV");
                    if (pFav != nullptr){
                        displayAllSongfromAPlaylist(pFav);
                        cout << endl;
                    } else {
                        cout << "Error: You don't have any liked songs yet." << endl;
                    }
                    break; // REVISI
                }
                // Display A Playlist
                case 2:{
                    cout << "Enter a playlist code: ";
                    cin >> kodePL;
                    adrPlaylist pl = searchPlaylist(playlists, kodePL);
                    if (pl != nullptr){
                        displayAllSongfromAPlaylist(pl);
                        cout << "--- OPTION ---" << endl;
                        cout << "1. Play Song from this playlist" << endl;
                        cout << "2. Exit" << endl;
                        cout << "Choose option (1/2): ";
                        int subChoice; // Ganti nama variabel biar aman
                        cin >> subChoice;

                        if (subChoice == 1){
                            if (pl->firstSong != nullptr){
                                controlMusicPlayer(pl->firstSong, nullptr, pl, history);
                            } else {
                                cout << "Playlist is empty." << endl;
                            }
                        } else if (subChoice == 2){
                            cout << "Exit playlist." << endl;
                        } else {
                            cout << "Invalid Input." << endl;
                        }
                    } else {
                        cout << "Playlist not found." << endl;
                    }
                    break; // REVISI
                }
                // Display All Songs From Library
                case 3:{
                    displayLibrary(library);
                    cout << endl;
                    break; // REVISI
                }
                // Search Playlist
                case 4:{
                    cout << "Enter the playlist code: ";
                    cin >> kodePL;
                    adrPlaylist pl = searchPlaylist(playlists, kodePL);
                    if (pl != nullptr){
                        cout << "Playlist found: " << pl->info.namaPlaylist << endl;
                    } else {
                        cout << "Playlist is not found." << endl;
                    }
                    break; // REVISI
                }
                // Search Song
                case 5:{
                    cout << "Enter your song title: ";
                    cin.ignore();
                    getline(cin, songTitle);
                    sg = searchSong(library, songTitle);
                    if (sg != nullptr){
                        cout << "Song found!" << endl;
                        cout << sg->info.judul << " by " << sg->info.artis << endl << endl;

                        cout << "===== Song Option =====" << endl;
                        cout << "1. Play Song" << endl;
                        cout << "2. Add/Remove Favourite Songs" << endl;
                        cout << "3. Back" << endl;
                        cout << "Choose option (1-3): ";
                        int subChoice;
                        cin >> subChoice;

                        if (subChoice == 1){
                            s = searchSinger(library, sg->info.artis);
                            controlMusicPlayer(sg, s, nullptr, history);
                        } else if (subChoice == 2){
                            songFlagStatus(library, playlists, sg->info.judul);
                        } else if (subChoice == 3){
                            cout << "Exit this page." << endl;
                        } else {
                            cout << "Invalid input." << endl;
                        }
                    } else {
                        cout << "Song not found." << endl;
                    }
                    break; // REVISI
                }
                // Edit Playlist
                case 6:{
                    cout << "========= OPTION =========" << endl;
                    cout << "1. Add New Playlist" << endl;
                    cout << "2. Delete Playlist" << endl;
                    cout << "3. Add Song to Playlist" << endl;
                    cout << "4. Delete Song From A Playlist" << endl;
                    cout << "5. Exit" << endl;
                    cout << "Choose option (1-4): ";
                    int subChoice;
                    cin >> subChoice;

                    switch (subChoice){
                        //Add New Playlist
                        case 1:{
                            cout << "Enter new playlist code: ";
                            cin >> kodePL;
                            cout << "Enter new playlist's name: ";
                            cin.ignore();
                            getline(cin, namaPL);
                            pl = createElementPlaylist(kodePL, namaPL);
                            addPlaylist(playlists, pl);
                            cout << endl;
                            break;
                        }
                        //Delete Playlist
                        case 2:{
                            cout << "Enter the code of a playlist you want to delete: ";
                            cin >> kodePL;
                            deletePlaylist(playlists, kodePL);
                            cout << endl;
                            break;
                        }
                        //Add Song to a New Playlist
                        case 3:{
                            cout << "The playlist code: ";
                            cin >> kodePL;
                            pl = searchPlaylist(playlists, kodePL);
                            if (pl != nullptr){
                                cout << "Song Title you want to add: ";
                                cin.ignore();
                                getline(cin, songTitle);
                                sg = searchSong(library, songTitle);
                                if (sg != nullptr){
                                    // REVISI PENTING: JANGAN MASUKKAN SG LANGSUNG
                                    // Buat element baru berdasarkan data sg
                                    adrSong newSongForPL = createElementSong(sg->info.idLagu, sg->info.judul, sg->info.artis, sg->info.album, sg->info.year, sg->info.durasi, sg->info.fav);
                                    addSongtoPlaylist(pl, newSongForPL);
                                    cout << "Successfully added to the playlist." << endl << endl;
                                } else {
                                    cout << "Song not found." << endl << endl;
                                }
                            } else {
                                cout << "Playlist not found." << endl;
                            }
                            break;
                        }
                        // Delete Song from A Playlist
                        case 4:{
                            cout << "Enter the playlist code: ";
                            cin >> kodePL;
                            pl = searchPlaylist(playlists, kodePL);
                            if (pl != nullptr) {
                                cout << "Enter the song title you want to delete from this playlist: ";
                                cin.ignore();
                                getline(cin, songTitle);
                                bool found = false;
                                adrSong sg = pl->firstSong;
                                // REVISI: Logika Loop diperbaiki
                                while (sg != nullptr && !found){
                                    if (sg->info.judul == songTitle){
                                        found = true;
                                    } else {
                                        sg = sg->next;
                                    }
                                }
                                if (found) {
                                    deleteSongElement(pl, sg);
                                    cout << "Song deleted." << endl;
                                    cout << endl;
                                } else {
                                    cout << "Song not found in this playlist." << endl;
                                }
                            } else {
                                cout << "Playlist not found." << endl;
                            }
                            break;
                        }
                        case 5:{
                            cout << "Exiting from this page..." << endl << endl;
                            break;
                        }
                        default:{
                            cout << "Invalid input." << endl << endl;
                            break;
                        }
                    }
                    break; // REVISI: Break untuk case 6 utama
                }
                //Display All Songs from A Singer
                case 7:{
                    cout << "Enter singer name: ";
                    cin.ignore();
                    getline(cin, nama);
                    s = searchSinger(library, nama);
                    if (s != nullptr){
                        displayAllSongfromASinger(s);
                    } else {
                        // Perbaikan akses pointer, s mungkin null di sini
                        cout << "There's no singer named " << nama << endl <<endl;
                    }
                    cout << endl;
                    break; // REVISI
                }
                //View History and Listening Time
                case 8:{
                    showHistory(history);
                    listeningTime(history);
                    cout << endl;
                    break; // REVISI
                }
                //Exit
                case 9:{
                    cout << "Logged you out. c u, user ;)" << endl << endl;
                    break; // REVISI
                }
                default:{
                    cout << "Invalid input." << endl;
                    break;
                }
            }
        } while (choice != 9);
    } else {
        cout << "Login failed. Wrong username or password." << endl;
    }
    return 0;
}
