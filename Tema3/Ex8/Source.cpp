#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void read_products(const string& filename, vector<unordered_set<string>>& stores) {
    ifstream input(filename);
    if (!input.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return;
    }

    string line;
    while (getline(input, line)) {
        stores.emplace_back();
        istringstream ss(line);
        string product;
        while (ss >> product) {
            stores.back().insert(product);
        }
    }
}

void find_most_exclusive_store(const vector<unordered_set<string>>& stores) {
    unordered_map<string, unordered_set<int>> product_stores;
    for (int i = 0; i < stores.size(); ++i) {
        for (const auto& product : stores[i]) {
            product_stores[product].insert(i);
        }
    }

    int max_exclusive_count = 0;
    int max_exclusive_store = -1;
    for (auto it = product_stores.begin(); it != product_stores.end(); ++it) {
        const auto& product = it->first;
        const auto& store_set = it->second;
        if (store_set.size() == 1) {
            int exclusive_store = *store_set.begin();
            int exclusive_count = stores[exclusive_store].count(product);
            if (exclusive_count > max_exclusive_count) {
                max_exclusive_count = exclusive_count;
                max_exclusive_store = exclusive_store;
            }
        }
    }

    if (max_exclusive_store == -1) {
        cout << "No exclusive products found.\n";
    }
    else {
        cout << "Store with the most exclusive products is Store " << max_exclusive_store << ".\n";
        cout << "Exclusive products: ";
        for (const auto& product : stores[max_exclusive_store]) {
            if (product_stores[product].size() == 1) {
                cout << product << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    vector<unordered_set<string>> stores;
    read_products("store.txt", stores);
    find_most_exclusive_store(stores);
    return 0;
}
