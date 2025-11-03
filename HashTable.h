/**
 * HashTable.h
 */

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <string>
#include <optional>
#include <vector>

#include "HashTableBucket.h"

/**
 * This uses a linear probing hash table. Each bucket in the table is a HAshTableBucket
 *  which could be the types, NORMAL, ESS, or EAR.
 */
class HashTable {
    public:


    HashTable(size_t initCapacity = 8); // Constructor that initializes table with 8 capacity
    bool insert(const std::string& key, const size_t& value); // Inserts a key/val pair in table
    bool remove(const std::string& key); // Removes a key from the hash table
    bool contains(const std::string& key) const; //Returns true if key exists and false if not

    std::optional<size_t> get(const std::string& key) const; // Returns optional with the value pointing to the key
    std::size_t& operator[](const std::string& key); // if key exists, return stored value. If no key, insert key with val 0
    std::vector<std::string> keys() const; // Returns a vector containing all keys in table

    double alpha() const; // load factor = size / capacity, runs in O(1)
    size_t capacity() const; // Returns number of buckets, O(1)
    size_t size() const; // Return number of key/val pairs, O(1)
    void resize(); // Doubles capacity, rehashes keys into new table and rebuilds probing sequence

    // Prints the whole table
    friend std::ostream& operator<<(std::ostream& os, const HashTable& hashTable);

    private:


    std::vector<HashTableBucket> table; // Bucket vector
    size_t tableCapacity; // current table size
    size_t count; // number of NORMAL buckets



};

#endif