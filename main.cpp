#include <iostream>
#include <string>
#include "playDeSong.h"

using namespace std;

int main(){
    listLibrary library;
    daftarPlaylist playlists;
    adrPlaylist pl;
    adrSinger s;
    adrSong sg;
    int choice, songYear, songDur;
    string login, password, nama, songTitle, songAlbum, songId;

    createNewLibrary(library);
    createNewPlaylist(playlists);
    pl = createElementPlaylist("PLFAV", "Fav_Songs");
    addPlaylist(playlists, pl);


    cout << "=============== Welcome to xxx ===============" << endl;
    cout << "Log in required before you enter the app!" << endl;
    cout << "Login as: ";
    cin >> login;
    cout << "Enter your password: ";
    cin >> password;
    cout << endl;
    cout << "Please wait while we check your identity." << endl;

    if (login == "admin" && password == "playDeSongAdm"){
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
        menuUser();
    }
}
