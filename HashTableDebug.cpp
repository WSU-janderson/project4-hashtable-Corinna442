/**
 * HashTableDebug.cpp
 *
 * Write your tests in this file
 */
#include <iostream>
#include "HashTable.h"

using namespace std;

int main() {
    HashTable hashTable(8); // Start with 8 capacity

    cout << "---INSERT---\n";
    cout << hashTable.insert("Red", 10) << endl;
    cout << hashTable.insert("Green", 20) << endl;
    cout << hashTable.insert("Red", 99) << endl;

    cout << "---CONTAINS---\n";
    cout << hashTable.contains("Red") << endl;
    cout << hashTable.contains("Green") << endl;
    cout << hashTable.contains("Blue") << endl;

    cout << "---OPERATOR---\n";
    cout << "green old: " << hashTable["Green"] << "\n";
    hashTable["Green"] = 25;
    cout << "green now: " << hashTable["Green"] << "(should be 25)\n";

    cout << "---REMOVE---\n";
    cout << hashTable.remove("Red") << " (should be true)\n";
    cout << hashTable.contains("Red") << " 0 now?\n";

    cout << "---INSERT IN EAR---\n";
    cout << hashTable.insert("purple", 52) << " 1\n";
    cout << hashTable.get("purple").value() << " 52\n";

    cout << "---KEYS---\n";
    // Print out each key
    // Use for loop and obj reference**
    vector<string> key = hashTable.keys();
    for (auto& k : key) {
        cout << k << " \n";
    }

    cout << "---SIZE, ALPHA, CAPACITY---\n";
    cout << "size: " << hashTable.size() << "\n";
    cout << "alpha: " << hashTable.alpha() << "\n";
    cout << "capacity: " << hashTable.capacity() << "\n";


    cout << hashTable << endl;
}