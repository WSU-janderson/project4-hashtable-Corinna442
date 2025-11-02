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
HashTable::HashTable(size_t initCapacity) : capacity(initCapacity), count(0) {
        table.resize(capacity); // Creates vector of buckets
    }

/**
 * Insert a new key-value pair into the table. Duplicate keys are not allowed.
 * The method should return true if the insertion was successful. If the insertion was
 * unsuccessful, such as when a duplicate is attempted to be inserted, the method
 * should return false.
 */
bool HashTable::insert(const std::string& key, const size_t& value) {

    size_t index = std::hash<std::string>{}(key) % capacity;

    // Linear probing loop
    for (size_t i = 0; i < capacity; i++) {

        // Probe sequence
        // Goes through each index in the capacity
        size_t probeIndex = (index + i) % capacity;

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
    size_t index = std::hash<std::string>{}(key) % capacity;

    for (size_t i = 0; i < capacity; i++) {
        size_t probeIndex = (index + i) % capacity;
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

    size_t index = std::hash<std::string>{}(key) % capacity;

    // Linear probing loop
    for (size_t i = 0; i < capacity; i++) {

        // Probe sequence
        // Goes through each index in the capacity
        size_t probeIndex = (index + i) % capacity;

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
    size_t index = std::hash<std::string>{}(key) % capacity;

    // Linear probing loop
    for (size_t i = 0; i < capacity; i++) {

        // Probe sequence
        // Goes through each index in the capacity
        size_t probeIndex = (index + i) % capacity;

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