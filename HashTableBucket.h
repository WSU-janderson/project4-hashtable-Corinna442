//
// Created by Corinna Green on 11/1/2025.
//

#ifndef HASHTABLE_HASHTABLEBUCKET_H
#define HASHTABLE_HASHTABLEBUCKET_H

#include <iostream>
#include <cstddef>
#include <string>

/**
 * This represents three states of a bucket in the hash table:
 *
 * NORMAL: has a key-value pair
 * ESS: is empty from start
 * EAR: is empty after removal
 *
 */
enum class BucketType {NORMAL, ESS, EAR};

/**
 * Represents one bucket in a hash table. This stores a key, value, bucket state.
 */
class HashTableBucket {
    private:

    std::string key; // Stored key
    size_t value; // Stored value
    BucketType type; // state of bucket

    public:

    /**
     * Default constructor, initializes bucket with ESS.
     */
    HashTableBucket() : key(""), value(0), type(BucketType::ESS) {}

    // Parameter constructor, will assign with NORMAL
    /**
     * Parameterized constructor. This loads a new key/value pair and marks slot as NORMAL.
     *
     * @param k key reference
     * @param v value reference
     */
    HashTableBucket(const std::string& k, const size_t& v) : key(k), value(v), type(BucketType::NORMAL) {}

    /**
     * Overwrites bucket with a key/value pair and marks it as NORMAL.
     * This is used when inserting.
     *
     * @param k  key reference
     * @param v value reference
     */
    void load(const std::string& k, const size_t& v) {
        key = k;
        value = v;
        type = BucketType::NORMAL;
    }

    // Getters for key and value
    const std::string& getKey() const {
        return key;
    }

    size_t getValue() const {
        return value;
    }

    /**
     * @return value a mutable reference to value
     */
    size_t& getValueRef() {
        return value;
    }

    /**
     * Mark as empty after removal (EAR)
     */
    void makeEAR() {
        type = BucketType::EAR;
        key = "";
        value = 0;
    }

    // Mutables
    /**
     * mark as NORMAL
     */
    void makeNormal() {
        type = BucketType::NORMAL;
    }

    /**
     * mark as ESS
     */
    void makeESS() {
        type = BucketType::ESS;
    }

    // Getters for Bucket Types
    /**
     *
     * @return true if bucket is ESS
     */
    bool isEmptySinceStart() const {
        return type == BucketType::ESS;
    }

    /**
     *
     * @return true if bucket is EAR
     */
    bool isEmptyAfterRemove() const {
        return type == BucketType::EAR;
    }

    /**
     *
     * @return true if bucket has a valid key-pair
     */
    bool isNormal() const {
        return type == BucketType::NORMAL;
    }

    /**
     * will use during probing to find insertion slots
     * @return true for either ESS or EAR
     */
    bool isEmpty() const {
        return type == BucketType::ESS || type == BucketType::EAR;
    }

    /**
     *
     * @param os used to print out list
     * @param bucket a slot in the table to print out
     * @return os to print out list
     */
    friend std::ostream& operator<<(std::ostream& os, const HashTableBucket& bucket) {
        if (bucket.type == BucketType::NORMAL) {
            os << bucket.getKey() << " " << bucket.getValue();
        }
        else if (bucket.type == BucketType::ESS) {
            os << "Empty from start";
        }
        else {
            os << "Empty after removal";
        }
        return os;
    }
};


#endif //HASHTABLE_HASHTABLEBUCKET_H