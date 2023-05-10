#include <iostream>
#include <list>
#include <vector>
#include <utility>
#include <fstream>

using namespace std;

class HashTable {
private:
    vector<list<pair<int, string>>> table;
    int capacity;
    int size;
    const double loadFactor = 1.0;

    void rehash() {
        int oldCapacity = capacity;
        capacity *= 2;
        size = 0;
        vector<list<pair<int, string>>> newTable(capacity);

        for (int i = 0; i < oldCapacity; i++) {
            for (auto& pair : table[i]) {
                int index = hash(pair.first);
                newTable[index].push_back(pair);
                size++;
            }
        }

        table = newTable;
    }

    int hash(int key) {
        return key % capacity;
    }

public:
    HashTable(int capacity) {
        this->capacity = capacity;
        size = 0;
        table.resize(capacity);
    }

    void insert(int key, string value) {
        int index = hash(key);
        table[index].push_back(make_pair(key, value));
        size++;

        if ((double)size / capacity > loadFactor) {
            rehash();
        }
    }

    bool contains(int key) {
        int index = hash(key);

        for (auto& pair : table[index]) {
            if (pair.first == key) {
                return true;
            }
        }

        return false;
    }

    string get(int key) {
        int index = hash(key);

        for (auto& pair : table[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }

        return "";
    }

    bool remove(int key) {
        int index = hash(key);

        for (auto it = table[index].begin(); it != table[index].end(); it++) {
            if (it->first == key) {
                table[index].erase(it);
                size--;
                return true;
            }
        }

        return false;
    }

    void display() {
        for (int i = 0; i < capacity; i++) {
            cout << i << ": ";
            for (auto& pair : table[i]) {
                cout << "<" << pair.first << ", " << pair.second << "> ";
            }
            cout << endl;
        }
    }
};

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cout << "Failed to open input file." << endl;
        return 0;
    }

    int n;
    inputFile >> n;
    HashTable table(n);
    int key;
    string value;
    for (int i = 0; i < n; i++) {
        inputFile >> key >> value;
        table.insert(key, value);
    }
    inputFile.close();

    while (true) {
        cout << "Select an operation:" << endl;
        cout << "1. Search element" << endl;
        cout << "2. Add element" << endl;
        cout << "3. Delete element" << endl;
        cout << "4. Display elements" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cin >> choice;
        if (choice == 1) {
            cout << "Enter key to search: ";
            cin >> key;
            if (table.contains(key)) {
                cout << "Element found: " << table.get(key) << endl;
            }
            else {
                cout << "Element not found." << endl;
            }
        }
        else if (choice == 2) {
            cout << "Enter key-value pair to add: ";
            cin >> key >> value;
            table.insert(key, value);
            cout << "Element added." << endl;
        }
        else if (choice == 3) {
            cout << "Enter key to delete: ";
            cin >> key;
            if (table.contains(key)) {
                table.remove(key);
                cout << "Element deleted." << endl;
            }
            else {
                cout << "Element not found." << endl;
            }
        }
        else if (choice == 4) {
            cout << "Displaying elements:" << endl;
            table.display();
        }
        else if (choice == 5) {
            break;
        }
        else {
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
