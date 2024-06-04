#include <iostream>
#include <string>
#include <fstream>
#include "mainHeader.h"
using namespace std;
extern const char* SYSTEM_CLEAR;
string encode(string& text) {
    string result;
    for (int i = 0; i < text.size(); i++) {
        if (text[i] >= 97 && text[i] <= 122)
            result += char(122 - static_cast<int>(text[i]) + 97);
        else if (text[i] >= 65 && text[i] <= 90)
            result += char(90 - static_cast<int>(text[i]) + 65);
        else if (text[i] >= 33 && text[i] <= 64)
            result += char(64 - static_cast<int>(text[i]) + 33);
        else if (text[i] >= -64 && text[i] <= -33)
            result += char((-33) - static_cast<int>(text[i]) + (-64));
        else if (text[i] >= -32 && text[i] <= -1)
            result += char((-1) - static_cast<int>(text[i]) + (-32));
        else if (text[i] == 32)
            result += " ";
        else if (text[i] == '\n')
            result += '\n';
    }
    return result;
}

void AtbashCipher(string& password1, string& password2)
{
    string message, pass1, pass2, filename;
    int pick, pickencode;

    while (true)
    {
        try {
			cout << "-----Atbash Cipher-----" << endl
				<< "| Select an action:    |" << endl
				<< "| <1> Encrypt          |" << endl
				<< "| <2> Decrypt          |" << endl
				<< "| <3> Exit             |" << endl
				<< "------------------------\n" << endl;
            cin >> pick;
			while (cin.fail() || cin.peek() != '\n') {
				throw logic_error("Input error!");
				cin >> pick;
			}
			if (pick != 1 && pick != 2 && pick != 3) {
				throw logic_error("You entered the wrong command!\n");
			}

			if (pick == 1) {
				system(SYSTEM_CLEAR);
				cout << "-----Atbash Cipher-----" << endl
					<< "| Select an action:    |" << endl
					<< "| <1> Encrypt(*)       |" << endl
					<< "| <2> Decrypt          |" << endl
					<< "| <3> Exit             |" << endl
					<< "------------------------\n" << endl;
				cout << "Enter the encoding password: ";
				cin >> pass1;
				if (pass1 == password1) {
					system(SYSTEM_CLEAR);
					cout << "--------------Choose action--------------" << endl
						<< "| <1> Enter text from the console        |" << endl
						<< "| <2> Read text from a file              |" << endl
						<< "------------------------------------------\n" << endl;
					cin >> pickencode;
					if (cin.fail() || cin.peek() != '\n') {
						throw logic_error("Input error!");
					}
					if (pickencode != 1 && pickencode != 2) {
						throw logic_error("You entered the wrong command!\n");
					}
					if (pickencode == 1) {
						system(SYSTEM_CLEAR);
						cout << "--------------Choose action--------------" << endl
							<< "| <1> Enter text from the console(*)     |" << endl
							<< "| <2> Read text from a file              |" << endl
							<< "------------------------------------------\n" << endl;
						cout << "Input text: ";
						cin.ignore();
						getline(cin, message);

						WriteIntoFile("atbash.txt", message);
						string encodedText2 = ReadFromFile("atbash.txt");
						string encoded2 = encode(encodedText2);

						cout << "Encrypted text: " << encoded2 << endl;
						WriteIntoFile("decoded.txt", encoded2);
					}
					if (pickencode == 2) {
						system(SYSTEM_CLEAR);
						cout << "--------------Choose action--------------" << endl
							<< "| <1> Enter text from the console        |" << endl
							<< "| <2> Read text from a file(*)           |" << endl
							<< "------------------------------------------\n" << endl;
						cout << "Enter the name of the file with the extension: ";
						cin >> filename;

						if (exist(filename) == false)
							throw logic_error("There is no such file or it cannot be opened!");

						string encodedText1 = ReadFromFile(filename);
						string encoded1 = encode(encodedText1);
						cout << "Encrypted text: " << encoded1 << endl;

						WriteIntoFile("decoded.txt", encoded1);
					}
				}
				else {
					throw logic_error("Invalid encoding password");
				}

			}
			else if (pick == 2) {
				system(SYSTEM_CLEAR);
				cout << "-----Atbash Cipher-----" << endl
					<< "| Select an action:    |" << endl
					<< "| <1> Encrypt          |" << endl
					<< "| <2> Decrypt(*)       |" << endl
					<< "| <3> Exit             |" << endl
					<< "------------------------\n" << endl;
				cout << "Enter the decoding password: ";
				cin >> pass2;
				if (pass2 == password2) {
					
					string encodedText1 = ReadFromFile("decoded.txt");
					string decoded1 = encode(encodedText1);
					WriteIntoFile("decoded1.txt", decoded1);

					cout << "The decrypted text: " << decoded1 << endl;
				}
				else {
					throw logic_error("Invalid decoding password");
				}
                
            }
			else if (pick == 3) {
				system(SYSTEM_CLEAR);
				break;
			}
        }
        catch (const exception& e)
        {
            cerr << e.what() << endl;
            cin.clear();
            cin.ignore(256, '\n');
        }
    }
}
