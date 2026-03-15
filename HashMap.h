#ifndef HASHMAP_H
#define HASHMAP_H

#include <iostream>
#include <string>
#include <vector>
#include "Planet.h"

class HashMap {
private:
    static const int TABLE_SIZE = 1009;

    struct RecordType {
        int key;
        Planet planet;
        RecordType* next;

        RecordType(int k, const Planet& p) : key(k), planet(p), next(nullptr) {}
    };

    RecordType* table[TABLE_SIZE];
    int itemCount;

    int polynomialHash(const std::string& key) const;

public:
    HashMap();
    ~HashMap();

    void insert(const std::string& name, const Planet& planet);
    std::vector<Planet> search(const std::string& name) const;
    int getItemCount() const;
    int getTableSize() const;
    void displayStats() const;
};

#endif
