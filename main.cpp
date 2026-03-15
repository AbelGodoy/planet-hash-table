//Abel Godoy Jr
//date: 12/14/2025
//Description: allows the user to pick threw various planets and shows information like numbers of stars, mass, year discovered, temperature, and diameters.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "HashMap.h"
#include "Planet.h"

double parseDouble(const std::string& str) {
    if (str.empty()) return 0.0;
    try {
        return std::stod(str);
    } catch (...) {
        return 0.0;
    }
}

int parseInt(const std::string& str) {
    if (str.empty()) return 0;
    try {
        return std::stoi(str);
    } catch (...) {
        return 0;
    }
}

bool loadPlanetsFromCSV(const std::string& filename, HashMap& hashMap) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return false;
    }

    std::string line;
    int lineCount = 0;
    int planetsLoaded = 0;

    while (std::getline(file, line)) {
        lineCount++;

        if (line.empty() || line[0] == '#') {
            continue;
        }

        if (line.find("pl_name") != std::string::npos) {
            continue;
        }

        std::stringstream ss(line);
        std::string fields[13];

        for (int i = 0; i < 12; i++) {
            std::getline(ss, fields[i], ',');
        }
        std::getline(ss, fields[12]);

        std::string name = fields[0];
        int numStars = parseInt(fields[1]);
        int numPlanets = parseInt(fields[2]);
        std::string discoveryMethod = fields[3];
        int discoveryYear = parseInt(fields[4]);
        std::string discoveryFacility = fields[5];
        double orbitalPeriod = parseDouble(fields[6]);
        double planetMass = parseDouble(fields[7]);
        double stellarTemp = parseDouble(fields[8]);
        double stellarRadius = parseDouble(fields[9]);
        double stellarMass = parseDouble(fields[10]);
        double stellarGravity = parseDouble(fields[11]);
        double distance = parseDouble(fields[12]);

        Planet planet(name, numStars, numPlanets, discoveryMethod, discoveryYear,
                      discoveryFacility, orbitalPeriod, planetMass, stellarTemp,
                      stellarRadius, stellarMass, stellarGravity, distance);

        hashMap.insert(name, planet);
        planetsLoaded++;
    }

    file.close();
    std::cout << "Successfully loaded " << planetsLoaded << " planet records.\n";
    return true;
}

int main() {
    HashMap planetMap;

    std::cout << "===========================================\n";
    std::cout << "     NASA Exoplanet Search System\n";
    std::cout << "===========================================\n\n";

    std::cout << "Loading exoplanet data from CSV file...\n";
    if (!loadPlanetsFromCSV("exoplanets.csv", planetMap)) {
        return 1;
    }

    planetMap.displayStats();

    std::string searchName;
    char continueSearch = 'y';

    while (continueSearch == 'y' || continueSearch == 'Y') {
        std::cout << "Enter a planet name to search: ";
        std::getline(std::cin, searchName);

        std::vector<Planet> results = planetMap.search(searchName);

        if (results.empty()) {
            std::cout << "\nNo planets found with name: " << searchName << "\n";
        } else {
            std::cout << "\nFound " << results.size() << " record(s) for '" << searchName << "':\n";
            for (const Planet& planet : results) {
                planet.display();
            }
        }

        std::cout << "\nWould you like to search for another planet? (y/n): ";
        std::cin >> continueSearch;
        std::cin.ignore();
    }

    std::cout << "\nThank you for using the Exoplanet Search System!\n";
    return 0;
}
