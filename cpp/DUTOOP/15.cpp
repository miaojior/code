#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Encryptor{
private:
    char encryptionMap[26];  // Maps 'a' to 'z'
    char encryptionMapUpper[26];  // Maps 'A' to 'Z'
public:
    Encryptor(string key);
    string encrypt(string text);
};

int main() {
    string key, text;
    getline(cin, key);
    Encryptor encryptor(key);
    getline(cin, text);
    string encryptedText = encryptor.encrypt(text);
    cout << encryptedText << endl;
    return 0;
}

Encryptor::Encryptor(string key){
    string uniqueKey;
    for(char c : key)
        if(uniqueKey.find(c) == string::npos)
            uniqueKey += c;
    reverse(uniqueKey.begin(), uniqueKey.end());
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for (char c : uniqueKey)
        alphabet.erase(remove(alphabet.begin(), alphabet.end(), c), alphabet.end());
    string finalKey = uniqueKey + string(alphabet.rbegin(), alphabet.rend());
    for (int i = 0; i < 26; ++i){
        encryptionMap[i] = finalKey[i];
        encryptionMapUpper[i] = toupper(finalKey[i]);
    }
}
string Encryptor::encrypt(string text){
    string encryptedText = text;
    for (char &c : encryptedText) {
        if (islower(c))
            c = encryptionMap[c - 'a'];
        else if (isupper(c))
            c = encryptionMapUpper[c - 'A'];
    }
    return encryptedText;
}