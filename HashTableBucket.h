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

    void load(const std::string& key, const size_t& value) {
        key = key;
        value = value;
        type = BucketType::NORMAL;
    }
    // Getters for key and value
    const std::string& getKey() const {
        return key;
    }

    size_t getValue() const {
        return value;
    }

    // Mark as empty after removal (EAR)
    void makeEAR() const {
        type == BucketType::EAR;
    }

    void makeNormal() const {
        type == BucketType::NORMAL;
    }

    void makeESS() const {
        type == BucketType::ESS;
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
        if (type == BucketType::NORMAL) {
            os << bucket.getKey() << " " << bucket.getValue();
        }
        else if (type == BucketType::ESS) {
            os << "Empty from start";
        }
        else {
            os << "Empty after removal";
        }
        return os;
    }
};


#endif //HASHTABLE_HASHTABLEBUCKET_H