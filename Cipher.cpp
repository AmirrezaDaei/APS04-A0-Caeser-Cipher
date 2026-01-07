#include <iostream>
using namespace std;

string decrypt(string message, int key);
string encrypt(string message, int key);

int main() {
    string message, output, operation;
    int key;
    cin >> message;
    cin >> key >> operation;
    if(operation == "Encrypt") {
        cout << encrypt(message, key);
    }
    else if(operation == "Decrypt") {
        cout << decrypt(message, key);
    }
}

string encrypt(string message, int key) {
    for(int i = 0; i < message.length(); i++) {
        if(int(message[i]) >= 65 && int(message[i]) <= 90) {
            message[i] = char((message[i] + key - 65) % 26 + 65);
        }
        else if(int(message[i]) >= 97 && int(message[i]) <= 122) {
            message[i] = char((message[i] + key - 97) % 26 + 97);
        }
    }
    return message;
}

string decrypt(string message, int key) {
    message = encrypt(message, 26 - key);
    return message;
}
