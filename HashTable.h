/**
 * HashTable.h
 */

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <string>
#include <optional>
#include <vector>

#include "HashTableBucket.h"

class HashTable {
    public:

    HashTable(size_t initCapacity = 8);
    bool insert(const std::string& key, const size_t& value);
    bool remove(const std::string& key);
    bool contains(const std::string& key) const;

    std::optional<size_t> get(const std::string& key) const;
    std::size_t& operator[](const std::string& key);
    std::vector<std::string> keys() const;

    double alpha() const;
    size_t capacity() const;
    size_t size() const;

    friend std::ostream& operator<<(std::ostream& os, const HashTable& hashTable);

    private:


    std::vector<HashTableBucket> table;
    size_t tableCapacity;
    size_t count;



};

#endif