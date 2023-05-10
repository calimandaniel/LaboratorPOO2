#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void printDuplicateCompetitors(const vector<pair<string, string>>& competitors) {
    unordered_map<string, int> competitorCount;
    for (const auto& competitor : competitors) {
        string fullName = competitor.first + " " + competitor.second;
        competitorCount[fullName]++;
    }

    bool foundDuplicate = false;
    for (const auto& pair : competitorCount) {
        if (pair.second > 1) {
            cout << pair.first << " participated in " << pair.second << " competitions." << endl;
            foundDuplicate = true;
        }
    }

    if (!foundDuplicate) {
        cout << "No duplicate competitors found." << endl;
    }
}

int main() {
    ifstream inputFile("competitors.txt");
    if (!inputFile.is_open()) {
        cout << "Failed to open input file." << endl;
        return 0;
    }

    vector<pair<string, string>> competitors;
    string firstName, lastName;
    while (inputFile >> firstName >> lastName) {
        competitors.emplace_back(firstName, lastName);
    }

    inputFile.close();

    printDuplicateCompetitors(competitors);

    return 0;
}
