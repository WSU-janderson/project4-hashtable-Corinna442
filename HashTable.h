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


    std::vector<size_t> table;
    size_t capacity;
    size_t count;



};

#endif