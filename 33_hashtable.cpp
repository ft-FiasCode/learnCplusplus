#include <iostream>
using namespace std;

class Item {
private:
    int data;
public:    
    Item(int d) : data(d) {}

    int getdata() {
        return data;
    }
    
    void deleteite() {
        data = -1;
    }
};

class Hashtable {
private:
    Item* hashArray[10];
    int tableSize = 10;

public:
    Hashtable() {
        for (int i = 0; i < tableSize; i++) {
            hashArray[i] = new Item(-1);
        }
    }

    ~Hashtable() {
        for (int i = 0; i < tableSize; i++) {
            delete hashArray[i];
        }
    }

    int hashFunc(int data) {
        return (data % tableSize);     
    }
        
    void insert(Item* i) {
        int data = i->getdata();
        int hashvalue = hashFunc(data);
        int probe = 0;

        while (hashArray[hashvalue]->getdata() != -1 && probe < tableSize) {
            probe++;
            hashvalue++;
            hashvalue %= tableSize;
        }

        if (probe < tableSize) {
            hashArray[hashvalue] = i;
            cout << "Item " << data << " inserted after " << probe << " probes" << endl;
        } else {
            cout << "Hash table is full, cannot insert item " << data << endl;
            delete i; // Avoid memory leak
        }
    }
    
    Item* find(int key) {
        int hashval = hashFunc(key);
        int probe = 0;

        while (hashArray[hashval]->getdata() != -1 && probe < tableSize) {
            if (hashArray[hashval]->getdata() == key) {
                cout << "Item found after " << probe << " probes" << endl;
                return hashArray[hashval];
            }
            hashval++;
            probe++;
            hashval %= tableSize;
        }
        
        cout << "Key not found" << endl;
        return NULL;
    }   
    
    bool deleteItem(int key) {
        int hashval = hashFunc(key);
        int probe = 0;

        while (hashArray[hashval]->getdata() != -1 && probe < tableSize) {
            if (hashArray[hashval]->getdata() == key) {
                cout << "Item deleted after " << probe << " probes" << endl;
                hashArray[hashval]->deleteite();
                return true;
            }
            hashval++;
            probe++;
            hashval %= tableSize;
        }
        
        cout << "Key not found" << endl;
        return false;
    }   
};

int main() {
    Hashtable* ht = new Hashtable();
    
    ht->insert(new Item(53));
    ht->insert(new Item(54));
    ht->insert(new Item(89));
    ht->insert(new Item(23));
    ht->insert(new Item(26));
    
    Item* i = ht->find(23);
    if (i != NULL)
        cout << "Item found: " << i->getdata() << endl;

    bool v = ht->deleteItem(23);
    if (v)
        cout << "Item deleted" << endl;

    delete ht; // Clean up the hashtable
    return 0;    
}

