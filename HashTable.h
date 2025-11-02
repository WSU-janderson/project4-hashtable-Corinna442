/**
 * HashTable.h
 */

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <string>
#include <cstddef> // For size_t
#include <optional>
#include <stdexcept> // exceptions
#include <vector>

#include "HashTableBucket.h"

class HashTable {
    public:

    HashTable(size_t initCapacity = 8);
    bool insert(const std::string& key, const size_t& value);
    bool remove(const std::string& key);
    bool contains(const std::string& key) const;

    std::optional<size_t> HashTable::get(const std::string& key) const;
    std::size_t& HashTable::operator[](const std::string& key);
    std::vector<std::string> HashTable::keys() const;


    private:


    std::vector<HashTableBucket> table;
    size_t capacity;
    size_t count;



};

#endif