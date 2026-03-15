#ifndef HASHMAP_H
#define HASHMAP_H

#include <string>
#include <vector>
#include "Planet.h"

struct RecordType {
    int key;
    Planet planet;
    RecordType* next;

    RecordType() : key(0), next(nullptr) {}
    RecordType(int k, const Planet& p) : key(k), planet(p), next(nullptr) {}
};

class HashMap {
private:
    static const int TABLE_SIZE = 10007;
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
