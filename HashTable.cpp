/**
 * HashTable.cpp
 */

#include "HashTable.h"
#include <iostream>
#include <stdexcept>
using namespace std;


/**
 * A single constructor that takes an initial capacity for the table. If no
 * capacity is given, then it defaults to 8 initially.
 *
 */
HashTable::HashTable(size_t initCapacity) {

}

/**
 * Insert a new key-value pair into the table. Duplicate keys are not allowed.
 * The method should return true if the insertion was successful. If the insertion was
 * unsuccessful, such as when a duplicate is attempted to be inserted, the method
 * should return false.
 */
bool HashTable::insert(const std::string& key, const size_t& value) {

}

/**
 * If the key is in the table, remove will "erase" the key-value pair from
 * the table. This might just be marking a bucket as empty-after-remove
 */
bool HashTable::remove(const std::string& key) {}

/**
 * returns true if the key is in the table and false if the key is not in the table
 */
bool HashTable::contains(const std::string& key) const {

}