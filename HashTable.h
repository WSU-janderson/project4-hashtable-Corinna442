/**
 * HashTable.h
 */

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <string>
#include <cstddef> // For size_t
#include <stdexcept> // exceptions
#include <vector>

class HashTable {
    public:

    HashTable(size_t initCapacity = 8);
    bool insert(const std::string& key, const size_t& value);
    bool remove(const std::string& key);
    bool contains(const std::string& key) const;

    private:

    struct Entry {
        std::string key;
        size_t value;
        bool occupied = false;
        bool deleted = false;
    };

    std::vector<Entry> table;
    size_t capacity;
    size_t count;

    // first index where key should go
    size_t hash(const std::string& key) const;

    // step size for psuedo-random probing
    size_t secondHash(const std::string& key) const;

    // Run probing to locate index where the key should be stored
    //size_t findInsertIndex(const std::string& key) const;



};

#endif