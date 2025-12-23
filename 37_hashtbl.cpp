#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HashTable {
private:
    vector<string> table;
    int size;

    int hashFunction(const string& key) {
        int hashValue = 0;
        for (size_t i = 0; i < key.length(); ++i) {
            hashValue += (key[i] * (i + 1));
        }
        return hashValue % size;
    }

public:
    HashTable(int s = 2069) : size(s), table(s, "") {}

    void insertLinearProbing(const string& key) {
        int index = hashFunction(key);
        while (!table[index].empty()) {
            if (table[index] == key) return;
            index = (index + 1) % size;
        }
        table[index] = key;
    }

    void insertQuadraticProbing(const string& key) {
        int index = hashFunction(key);
        int i = 0;
        while (!table[index].empty()) {
            if (table[index] == key) return;
            i++;
            index = (index + i * i) % size;
        }
        table[index] = key;
    }

    void insertDoubleHashing(const string& key) {
        int index = hashFunction(key);
        
        auto secondaryHash = [](const string& k) {
            int sum = 0;
            for (char c : k) sum += c;
            return 7 - (sum % 7);
        };

        int stepSize = secondaryHash(key);
        
        while (!table[index].empty()) {
            if (table[index] == key) return;
            index = (index + stepSize) % size;
        }
        table[index] = key;
    }

    bool search(const string& key) {
        int index = hashFunction(key);
        
        while (!table[index].empty()) {
            if (table[index] == key) return true;
            index = (index + 1) % size;
        }
        
        return false;
    }

    void display() const {
        for (int i = 0; i < size; ++i) {
            if (!table[i].empty()) {
                cout << "Index " << i << ": " << table[i] << endl;}}
    }
};
int main() {
    HashTable hashTable;
    vector<string> keysToInsert = {"abcdef", "bcdefa", "cdefab", "defabc", "efabcd", "fabcde"};
    cout << "Inserting keys using Linear Probing:" << endl;
    for (const auto& key : keysToInsert) {
        hashTable.insertLinearProbing(key);    }    
    cout << "\nHash Table after Linear Probing:" << endl;
    hashTable.display();
    HashTable quadraticHashTable;
    cout << "\nInserting keys using Quadratic Probing:" << endl;
    for (const auto& key : keysToInsert) {
        quadraticHashTable.insertQuadraticProbing(key);
    }
    cout << "\nHash Table after Quadratic Probing:" << endl;
    quadraticHashTable.display();
    HashTable doubleHashTable;
    cout << "\nInserting keys using Double Hashing:" << endl;
    for (const auto& key : keysToInsert) {
        doubleHashTable.insertDoubleHashing(key);
    }
    cout << "\nHash Table after Double Hashing:" << endl;
    doubleHashTable.display();
    vector<string> searchKeys = {"abcdef", "xyzabc"};
    for (const auto& searchKey : searchKeys) {
        bool found = doubleHashTable.search(searchKey);
        cout << "Searching for '" << searchKey << "': " 
             << (found ? "Found" : "Not Found") << endl;
    }
    return 0;
}
