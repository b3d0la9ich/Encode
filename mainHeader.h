#pragma once
void GibberishCryption(std::string& password1, std::string& password2);
void AtbashCipher(std::string& password1, std::string& password2);
void ScytaleCipher(std::string& password1, std::string& password2);
bool WriteIntoFile(const std::string& fname, const std::string& text);
std::string ReadFromFile(const std::string& fname);
bool exist(std::string& filename);