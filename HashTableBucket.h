//
// Created by Corinna Green on 11/1/2025.
//

#ifndef HASHTABLE_HASHTABLEBUCKET_H
#define HASHTABLE_HASHTABLEBUCKET_H

#include <iostream>
#include <cstddef>
#include <string>

enum class BucketType {NORMAL, ESS, EAR};

class HashTableBucket {
    private:

    std::string key;
    size_t value;
    BucketType type;

    public:

    // Default constructor, will assign with ESS
    HashTableBucket() : key(""), value(0), type(BucketType::ESS) {}

    // Parameter constructor, will assign with NORMAL
    HashTableBucket(const std::string& k, const size_t& v) : key(k), value(v), type(BucketType::NORMAL) {}

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

    // Added for operator method in HashTable
    size_t& getValueRef() {
        return value;
    }

    // Mark as empty after removal (EAR)
    void makeEAR() {
        type = BucketType::EAR;
        key = "";
        value = 0;
    }

    // Mutables
    void makeNormal() {
        type = BucketType::NORMAL;
    }

    void makeESS() {
        type = BucketType::ESS;
    }

    // Getters for Bucket Types
    bool isEmptySinceStart() const {
        return type == BucketType::ESS;
    }

    bool isEmptyAfterRemove() const {
        return type == BucketType::EAR;
    }

    bool isNormal() const {
        return type == BucketType::NORMAL;
    }

    // Just check if bucket is empty (either ESS or EAR)
    bool isEmpty() const {
        return type == BucketType::ESS || type == BucketType::EAR;
    }

    // Print out hash table
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