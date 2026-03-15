#include "HashMap.h"
#include <iostream>
#include <algorithm>
#include <cctype>

static std::string toLower(const std::string& s) {
    std::string result = s;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return result;
}

HashMap::HashMap() : itemCount(0) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = nullptr;
    }
}

HashMap::~HashMap() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        RecordType* current = table[i];
        while (current != nullptr) {
            RecordType* temp = current;
            current = current->next;
            delete temp;
        }
    }
}

int HashMap::polynomialHash(const std::string& key) const {
    const int BASE = 31;
    const long long MOD = TABLE_SIZE;
    std::string lowerKey = toLower(key);
    long long hashValue = 0;
    long long power = 1;

    for (size_t i = 0; i < lowerKey.length(); i++) {
        hashValue = (hashValue + (lowerKey[i] * power) % MOD) % MOD;
        power = (power * BASE) % MOD;
    }

    return static_cast<int>(hashValue);
}

void HashMap::insert(const std::string& name, const Planet& planet) {
    int index = polynomialHash(name);
    int key = index;

    RecordType* newRecord = new RecordType(key, planet);

    if (table[index] == nullptr) {
        table[index] = newRecord;
    } else {
        RecordType* current = table[index];
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newRecord;
    }

    itemCount++;
}

std::vector<Planet> HashMap::search(const std::string& name) const {
    std::vector<Planet> results;
    int index = polynomialHash(name);
    std::string lowerName = toLower(name);

    RecordType* current = table[index];
    while (current != nullptr) {
        if (toLower(current->planet.getName()) == lowerName) {
            results.push_back(current->planet);
        }
        current = current->next;
    }

    return results;
}

int HashMap::getItemCount() const {
    return itemCount;
}

int HashMap::getTableSize() const {
    return TABLE_SIZE;
}

void HashMap::displayStats() const {
    int usedBuckets = 0;
    int maxChainLength = 0;
    int totalChainLength = 0;

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] != nullptr) {
            usedBuckets++;
            int chainLength = 0;
            RecordType* current = table[i];
            while (current != nullptr) {
                chainLength++;
                current = current->next;
            }
            totalChainLength += chainLength;
            if (chainLength > maxChainLength) {
                maxChainLength = chainLength;
            }
        }
    }

    std::cout << "\n=== Hash Table Statistics ===\n";
    std::cout << "Table Size: " << TABLE_SIZE << "\n";
    std::cout << "Total Items: " << itemCount << "\n";
    std::cout << "Used Buckets: " << usedBuckets << "\n";
    std::cout << "Load Factor: " << (double)itemCount / TABLE_SIZE << "\n";
    std::cout << "Max Chain Length: " << maxChainLength << "\n";
    if (usedBuckets > 0) {
        std::cout << "Average Chain Length: " << (double)totalChainLength / usedBuckets << "\n";
    }
    std::cout << "=============================\n\n";
}
