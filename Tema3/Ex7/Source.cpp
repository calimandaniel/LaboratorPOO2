#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>

using namespace std;

bool has_close_duplicates(vector<double> values, int dist) {
    unordered_set<double> seen_values;
    for (int i = 0; i < values.size(); i++) {
        if (i > dist) {
            seen_values.erase(values[i - dist - 1]);
        }
        if (seen_values.find(values[i]) != seen_values.end()) {
            return true;
        }
        seen_values.insert(values[i]);
    }
    return false;
}

int main() {
    ifstream infile("input.txt");
    if (!infile.is_open()) {
        cout << "Failed to open input file." << endl;
    }
    vector<double> values;
    double value;
    while (infile >> value) {
        values.push_back(value);
    }
    int dist = 5;
    if (has_close_duplicates(values, dist)) {
        cout << "There are close duplicates within a distance of " << dist << endl;
    }
    else {
        cout << "There are no close duplicates within a distance of " << dist << endl;
    }
}
