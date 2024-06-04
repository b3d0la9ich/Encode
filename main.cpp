#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include "mainHeader.h"

using namespace std;
const char* SYSTEM_CLEAR = "cls";

int main() {
    SetConsoleCP(1251);        
    SetConsoleOutputCP(1251);

    char pick;
    bool exit = true;
    string passenter = "323565", pass1 = "112200", pass2 = "181818", passcheck, userName;
    cout << "The EncoderPro welcomes you! What's your name?" << endl;
    cin >> userName;

    cout << userName + ", please, input password authorization: ";
    cin >> passcheck;
    while (passenter != passcheck) {
        cout << "Wrong password authorization" << endl;
        cout << userName + ", please, input password authorization: ";
        cin >> passcheck;
    }

    while (exit) {
        try {
            system(SYSTEM_CLEAR);
            cout << "\nList of ciphers\t" << endl
                << "--------------------------------------" << endl
                << "|  <1> Gibberish Cryption            |" << endl
                << "|  <2> Cipher Atbash                 |" << endl
                << "|  <3> Cipher Skitala                |" << endl
                << "|  <4> Exit                          |" << endl
                << "--------------------------------------\n" << endl;
            cin >> pick;
            if (cin.peek() != '\n') {
                throw runtime_error("You have entered a string!");
            }
            if (pick != '1' && pick != '2' && pick != '3' && pick != '4') {
                throw runtime_error("\nYou entered the wrong command!\n");
            }
            switch (pick) {
            case '1': {
                system(SYSTEM_CLEAR);
                cout << "\nList of ciphers\t" << endl
                    << "--------------------------------------" << endl
                    << "|  <1> Gibberish Cryption(*)         |" << endl
                    << "|  <2> Cipher Atbash                 |" << endl
                    << "|  <3> Cipher Skitala                |" << endl
                    << "|  <4> Exit                          |" << endl
                    << "--------------------------------------\n" << endl;
                GibberishCryption(pass1, pass2);
                break;
            } case '2': {
                system(SYSTEM_CLEAR);
                cout << "\nList of ciphers\t" << endl
                    << "--------------------------------------" << endl
                    << "|  <1> Gibberish Cryption            |" << endl
                    << "|  <2> Cipher Atbash(*)              |" << endl
                    << "|  <3> Cipher Skitala                |" << endl
                    << "|  <4> Exit                          |" << endl
                    << "--------------------------------------\n" << endl;
                AtbashCipher(pass1, pass2);
                break;
            } case '3': {
                system(SYSTEM_CLEAR);
                cout << "\nList of ciphers\t" << endl
                    << "--------------------------------------" << endl
                    << "|  <1> Gibberish Cryption            |" << endl
                    << "|  <2> Cipher Atbash                 |" << endl
                    << "|  <3> Cipher Skitala(*)             |" << endl
                    << "|  <4> Exit                          |" << endl
                    << "--------------------------------------\n" << endl;
                ScytaleCipher(pass1, pass2);
                break;
            } case '4': {
                system(SYSTEM_CLEAR);
                cout << "\nList of ciphers\t" << endl
                    << "--------------------------------------" << endl
                    << "|  <1> Gibberish Cryption            |" << endl
                    << "|  <2> Cipher Atbash                 |" << endl
                    << "|  <3> Cipher Skitala                |" << endl
                    << "|  <4> Exit(*)                       |" << endl
                    << "--------------------------------------\n" << endl;
                cout << "Exiting..." << endl;
                exit = false;
            }
            }
        }
        catch (const runtime_error& ex) {
            cerr << ex.what();
            cin.clear();
            cin.ignore(256, '\n');
        }
    }
}