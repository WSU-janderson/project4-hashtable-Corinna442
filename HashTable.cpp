/**
 * HashTable.cpp
 */

#include "HashTable.h"
#include <iostream>
#include <optional>
#include <stdexcept>

#include "HashTableBucket.h"
using namespace std;


/**
 * A single constructor that takes an initial capacity for the table. If no
 * capacity is given, then it defaults to 8 initially.
 *
 */
HashTable::HashTable(size_t initCapacity) : tableCapacity(initCapacity), count(0) {
        table.resize(tableCapacity); // Creates vector of buckets
    }

/**
 * Insert a new key-value pair into the table. Duplicate keys are not allowed.
 * The method should return true if the insertion was successful. If the insertion was
 * unsuccessful, such as when a duplicate is attempted to be inserted, the method
 * should return false.
 */
bool HashTable::insert(const std::string& key, const size_t& value) {

    size_t index = std::hash<std::string>{}(key) % tableCapacity;

    // Linear probing loop
    for (size_t i = 0; i < tableCapacity; i++) {

        // Probe sequence
        // Goes through each index in the capacity
        size_t probeIndex = (index + i) % tableCapacity;

        // Reference object of the bucket
        HashTableBucket& bucket = table[probeIndex];

        // Check if key already exists
        if (bucket.isNormal() && bucket.getKey() == key) {
            // A key is already stored in normal bucket
            return false; // NO key duplicates
        }

        // Check if the bucket is empty
        // ESS or EAR
        if (bucket.isEmpty()) {
            bucket.load(key, value); // store new key val pair
            count++;                 // update table count
            return true;             // insert successful
        }
    }

    return false; // if table is full and no available bucket

}

/**
 * If the key is in the table, remove will "erase" the key-value pair from
 * the table. This might just be marking a bucket as empty-after-remove
 */
bool HashTable::remove(const std::string& key) {
    size_t index = std::hash<std::string>{}(key) % tableCapacity;

    for (size_t i = 0; i < tableCapacity; i++) {
        size_t probeIndex = (index + i) % tableCapacity;
        HashTableBucket& bucket = table[probeIndex];

        if (bucket.isEmptySinceStart()) {
            return false;
        }

        // if the key is there and a normal bucket, just mark it as EAR
        if (bucket.getKey() == key && bucket.isNormal()) {
            bucket.makeEAR();
            count--;
            return true;
        }

        // Otherwise keep probing
    }

    return false; // Key not found
}

/**
 * returns true if the key is in the table and false if the key is not in the table
 */
bool HashTable::contains(const std::string& key) const {

    size_t index = std::hash<std::string>{}(key) % tableCapacity;

    // Linear probing loop
    for (size_t i = 0; i < tableCapacity; i++) {

        // Probe sequence
        // Goes through each index in the capacity
        size_t probeIndex = (index + i) % tableCapacity;

        // Reference object of the bucket
        const HashTableBucket& bucket = table[probeIndex];

        // If we get to ESS bucket, then key does not exist
        if (bucket.isEmptySinceStart()) {
            // A key is already stored in normal bucket
            return false; // NO key duplicates
        }

        if (bucket.isNormal() && bucket.getKey() == key) {
            return true;
        }
    }

    return false; // if table is full and no available bucket
}

/**
*
* If the key is found in the table, find will return the value associated with
* that key. If the key is not in the table, find will return something called
* nullopt, which is a special value in C++. The find method returns an
* optional<int>, which is a way to denote a method might not have a valid value
* to return. This approach is nicer than designating a special value, like -1, to
* signify the return value is invalid. It's also much better than throwing an
* exception if the key is not found.
*
* Why we use this method: optional<size_t> can represent either a real value or nullopt
* (no value exists)
*
 * @param key
 * @return
 */
optional<size_t> HashTable::get(const std::string& key) const {
    size_t index = std::hash<std::string>{}(key) % tableCapacity;

    // Linear probing loop
    for (size_t i = 0; i < tableCapacity; i++) {

        // Probe sequence
        // Goes through each index in the capacity
        size_t probeIndex = (index + i) % tableCapacity;

        // Reference object of the bucket
        const HashTableBucket& bucket = table[probeIndex];

        // If we get to a bucket that was never used, then the key is not there
        if (bucket.isEmptySinceStart()) {
            return std::nullopt;
        }

        // if bucket has matching key, return the value with that key
        if (bucket.isNormal() && bucket.getKey() == key) {
            return bucket.getValue();
        }
    }

    return std::nullopt; // if table is full and no available bucket
}

size_t& HashTable::operator[](const std::string& key) {
    size_t index = std::hash<std::string>{}(key) % tableCapacity;

    // Linear probing loop
    for (size_t i = 0; i < tableCapacity; i++) {

        // Probe sequence
        // Goes through each index in the capacity
        size_t probeIndex = (index + i) % tableCapacity;

        // Reference object of the bucket
        HashTableBucket& bucket = table[probeIndex];

        // If key is found, return the reference to its value**
        if (bucket.isNormal() && bucket.getKey() == key) {
            return bucket.getValueRef();
        }

        // If ESS, then key cannot exist (undefined)
        if (bucket.isEmptySinceStart()) {
            throw std::runtime_error("Attempt to access key that does not exist");
        }
    }

}

/**
 * Returns a string containing all keys still stored, with the vector size being
 * the same as the table's capacity.
 *
 * @return result
 */
vector<std::string> HashTable::keys() const {

    std::vector<std::string> result; // Make a list of only key values

    // for each loop-examines each bucket in capacity
    for (const auto& bucket : table) {
        if (bucket.isNormal())
            result.push_back(bucket.getKey()); // ESS and EAR skipped, keys copied into result
    }
    return result; // Return completed list
}

double HashTable::alpha() const {
    return static_cast<double>(count) / static_cast<double>(tableCapacity);
}

size_t HashTable::capacity() const {
    return tableCapacity;
}

size_t HashTable::size() const {
    return count;
}

std::ostream& operator<<(std::ostream& os, const HashTable& hashTable) {
    os << "---Hash Table---" << std::endl;
    for (size_t i = 0; i < hashTable.size(); i++) {
        os << i << ": " << hashTable.table[i] << std::endl;
    }
    return os;
}