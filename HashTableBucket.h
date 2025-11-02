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
    HashTableBucket(const std::string& key, const size_t& value) : key(key), value(value), type(BucketType::NORMAL) {}

    // Getters for key and value
    const std::string& getKey() const {
        return key;
    }

    size_t getValue() const {
        return value;
    }

    // Getters for Bucket Types
    bool isESS() const {
        return type == BucketType::ESS;
    }

    bool isEAR() const {
        return type == BucketType::EAR;
    }

    bool isNormal() const {
        return type == BucketType::NORMAL;
    }

    // Check if bucket is empty (either ESS or EAR)
    bool isEmpty() const {
        return type == BucketType::ESS || type == BucketType::EAR;
    }

};


#endif //HASHTABLE_HASHTABLEBUCKET_H