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
                    cout << s->namaArtis << " has been added to library." << endl;
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
                        cin.ignore();
                        getline(cin, songAlbum);
                        cout << "Year: ";
                        cin >> songYear;
                        cout << "Song Duration (in seconds): ";
                        cin >> songDur;
                        sg = createElementSong(songId, songTitle, nama, songAlbum, songYear, songDur, false);
                        addSongtoSinger(s, sg);
                        cout << "The song has been added to singer list." << endl << endl;
                    } else {
                        cout << "Singer named " << nama << " is not found." << endl << endl;
                    }
                }
                // Delete Song
                case 3:{
                    cout << "Enter the singer name: ";
                    cin.ignore();
                    getline(cin, nama);
                    cout << "ENter the song title: ";
                    cin.ignore();
                    getline(cin, songTitle);
                    deleteSongsfromAll(library, playlists, songTitle, nama);
                }
                // Update song
                case 4:{
                    cout << "Song Title that you want to edit: ";
                    cin.ignore();
                    getline(cin, songTitle);
                    updateSongsfromAll(library, playlists, songTitle);
                }
                // Exit
                case 5:{
                    cout << "Logged you out. c u, admin ;)" << endl << endl;
                }
                default:{
                    cout << "Invalid input." << endl;
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
                    } else {
                        cout << "Error: You don't have any liked songs yet." << endl;
                    }
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
                        cin >> choice;

                        if (choice == 1){
                            if (pl->firstSong != nullptr){
                                controlMusicPlayer(pl->firstSong, nullptr, pl, history);
                            }
                        } else if (choice == 2){
                            cout << "Exit playlist." << endl;
                        } else {
                            cout << "Invalid Input." << endl;
                        }
                    }
                }\
                // Display All Songs From Library
                case 3:{
                    displayLibrary(library);
                }
                // Search Playlist
                case 4:{
                    cout << "Enter the playlist code: ";
                    cin >> kodePL;
                    adrPlaylist pl = searchPlaylist(playlists, kodePL);
                    if (pl != nullptr){
                        cout << "Playlist found: " << pl->info.namaPlaylist;
                    } else {
                        cout << "Playlist is not found." << endl;
                    }
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
                        cin >> choice;

                        if (choice == 1){
                            s = searchSinger(library, sg->info.artis);
                            controlMusicPlayer(sg, s, nullptr, history);
                        } else if (choice == 2){
                            songFlagStatus(library, playlists, sg->info.judul);
                        } else if (choice == 3){
                            cout << "Exit this page." << endl;
                        } else {
                            cout << "Invalid input." << endl;
                        }
                    }
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
                    cin >> choice;

                    switch (choice){
                        //Add New Playlist
                        case 1:{
                            cout << "Enter new playlist code: ";
                            cin >> kodePL;
                            cout << "Enter new playlist's name: ";
                            cin.ignore();
                            getline(cin, namaPL);
                            pl = createElementPlaylist(kodePL, namaPL);
                            addPlaylist(playlists, pl);
                        }
                        //Delete Playlist
                        case 2:{
                            cout << "Enter the code of a playlist you want to delete: ";
                            cin >> kodePL;
                            deletePlaylist(playlists, kodePL);
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
                                    addSongtoPlaylist(pl, sg);
                                    cout << "Successfully added to the playlist." << endl << endl;
                                } else {
                                    cout << "Song not found." << endl << endl;
                                }
                            }
                        }
                        // Delete Song from A Playlist
                        case 4:{
                            cout << "Enter the playlist code: ";
                            cin >> kodePL;
                            pl = searchPlaylist(playlists, kodePL);
                            cout << "Enter the song title you want to delete from this plyaylist: ";
                            cin.ignore();
                            getline(cin, songTitle);
                            bool found = false;
                            adrSong sg = pl->firstSong;
                            while (sg != nullptr && found){
                                if (sg->info.judul == songTitle){
                                    found = true;
                                }
                                sg = sg->next;
                            }
                            deleteSongElement(pl, sg);
                        }
                        case 5:{
                            cout << "Exiting from this page..." << endl << endl;
                        }
                        default:{
                            cout << "Invalid input." << endl << endl;
                        }
                    }
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
                        cout << "There's no singer named " << s->namaArtis << endl <<endl;
                    }
                }
                //View History and Listening Time
                case 8:{
                    showHistory(history);
                    listeningTime(history);
                }
                //Exit
                case 9:{
                    cout << "Logged you out. c u, user ;)" << endl << endl;
                }
                default:{
                    cout << "Invalid input." << endl;
                }
            }
        } while (choice != 9);
    }
}
