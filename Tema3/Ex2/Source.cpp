#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

using namespace std;

bool isPermutation(string str1, string str2) {
    if (str1.length() != str2.length()) {
        return false;
    }

    unordered_set<char> chars;

    for (char c : str1) {
        chars.insert(c);
    }

    for (char c : str2) {
        if (chars.find(c) == chars.end()) {
            return false;
        }
    }

    return true;
}

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cout << "Failed to open input file." << endl;
    }

    string str1, str2;
    inputFile >> str1 >> str2;
    inputFile.close();

    if (isPermutation(str1, str2)) {
        cout << str2 << " is a permutation of " << str1 << endl;
    }
    else {
        cout << str2 << " is not a permutation of " << str1 << endl;
    }
}
