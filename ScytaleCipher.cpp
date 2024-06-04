#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "mainHeader.h"

using namespace std;
extern const char* SYSTEM_CLEAR;

string cleanOutput(const string& output) {
	string cleanedOutput = output;
	cleanedOutput.erase(remove(cleanedOutput.begin(), cleanedOutput.end(), '_'), cleanedOutput.end());
	return cleanedOutput;
}


string encodeScytale(string& message, int diameter) {
	int length = message.length();
	int height = (length + diameter - 1) / diameter;

	vector<vector<char>> grid(height, vector<char>(diameter, '_'));

	int index = 0;
	for (int j = 0; j < diameter; j++) {
		for (int i = 0; i < height; i++) {
			if (index < length) {
				if (message[index] == '\n') {
					grid[i][j] = '@'; 
				}
				else {
					grid[i][j] = message[index];
				}
				index++;
			}
		}
	}

	string encodedMessage = "";
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < diameter; j++) {
			encodedMessage += grid[i][j];
		}
	}
	encodedMessage = encodedMessage.substr(0, encodedMessage.length() - 1);
	return encodedMessage;
}

string decodeScytale(string& encodedMessage, int diameter) {
	int length = encodedMessage.length();
	int height = (length + diameter - 1) / diameter;

	vector<vector<char>> grid(height, vector<char>(diameter, '_'));

	int index = 0;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < diameter; j++) {
			if (index < length) {
				grid[i][j] = encodedMessage[index++];
			}
		}
	}

	string decodedMessage = "";
	for (int j = 0; j < diameter; j++) {
		for (int i = 0; i < height; i++) {
			if (grid[i][j] == '@') { 
				decodedMessage += '\n'; 
			}
			else {
				decodedMessage += grid[i][j];
			}
		}
	}
	decodedMessage = decodedMessage.substr(0, decodedMessage.length() - 1);
	return decodedMessage;
}


void ScytaleCipher(string& password1, string& password2)
{
	system("chcp 1251 > nul");
	int pick, diametr1, diametr2, pickencode;
	string pass1, pass2, message, filename;
	while (true) {
		try {
			cout << "----Scytale Cipher-----" << endl
				<< "| Select an action:    |" << endl
				<< "| <1> Encrypt          |" << endl
				<< "| <2> Decrypt          |" << endl
				<< "| <3> Exit             |" << endl
				<< "------------------------\n" << endl;
			cin >> pick;
			while (cin.fail() || cin.peek()!='\n') {
				throw logic_error("Input error!");
				cin >> pick;
			}
			if (pick != 1 && pick != 2 && pick != 3) {
				throw logic_error("You entered the wrong command!");
			}

			if (pick == 1) {
				system(SYSTEM_CLEAR);
				cout << "----Scytale Cipher-----" << endl
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
						throw logic_error("You entered the wrong command!");
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
						cout << "Enter the diameter Scytale: ";
						cin >> diametr1;
						if (cin.fail() || cin.peek() != '\n') {
							throw logic_error("Input error!");
						}
						WriteIntoFile("skytale.txt", message);
						string encodedText2 = ReadFromFile("skytale.txt");
						string encoded2 = encodeScytale(encodedText2, diametr1);
						string cleanedEncoded2 = cleanOutput(encoded2);
						
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

						cout << "Enter the diameter Scytale: ";
						cin >> diametr2;

						if (cin.fail() || cin.peek() != '\n') {
							throw logic_error("Input error!");
						}

						string encodedText1 = ReadFromFile(filename);
						string encoded1 = encodeScytale(encodedText1, diametr2);
						string cleanedEncoded2 = cleanOutput(encoded1);
						cout << "Encrypted text: " << encoded1 << endl;
						
						WriteIntoFile("decoded.txt", encoded1);
					}

				}
				else {
					throw logic_error("Invalid decoding password");
				}
			}
			else if (pick == 2) {
				system(SYSTEM_CLEAR);
				cout << "----Scytale Cipher-----" << endl
					<< "| Select an action:    |" << endl
					<< "| <1> Encrypt          |" << endl
					<< "| <2> Decrypt(*)       |" << endl
					<< "| <3> Exit             |" << endl
					<< "------------------------\n" << endl;
				cout << "Enter the decoding password: " << endl;
				cin >> pass2;

				if (pass2 == password2) {
					cout << "Enter the diameter Skitala: ";
					cin >> diametr2;

					if (cin.fail() || cin.peek() != '\n') {
						throw logic_error("Input error!");
					}

					string encodedText1 = ReadFromFile("decoded.txt");
					string decoded1 = decodeScytale(encodedText1, diametr2);
					string cleanedDecoded1 = cleanOutput(decoded1);
					cout << "The decrypted text: " << cleanedDecoded1 << endl;

					WriteIntoFile("decoded1.txt", cleanedDecoded1);
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
		catch (const exception& e) {
			cerr << "Error: " << e.what() << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
	}
}