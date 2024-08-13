#include <iostream>
#include <cstring>
#include <cstdlib> // for malloc and free
#pragma warning (disable:4996)
#define TABLE_SIZE 127

struct Parcel {
    char* destination;
    int weight;
    float valuation;
    Parcel* left;
    Parcel* right;
};

struct HashTable {
    Parcel* buckets[TABLE_SIZE];
};

// djb2 hash function
unsigned long hashFunction(const char* str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash % TABLE_SIZE;
}

