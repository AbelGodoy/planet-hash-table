#ifndef PLANET_H
#define PLANET_H

#include <string>
#include <iostream>

class Planet {
private:
    std::string name;
    int numStars;
    int numPlanets;
    std::string discoveryMethod;
    int discoveryYear;
    std::string discoveryFacility;
    double orbitalPeriod;
    double planetMass;
    double stellarTemp;
    double stellarRadius;
    double stellarMass;
    double stellarGravity;
    double distance;

public:
    Planet();
    Planet(const std::string& name, int numStars, int numPlanets,
           const std::string& discoveryMethod, int discoveryYear,
           const std::string& discoveryFacility, double orbitalPeriod,
           double planetMass, double stellarTemp, double stellarRadius,
           double stellarMass, double stellarGravity, double distance);

    std::string getName() const;
    int getNumStars() const;
    int getNumPlanets() const;
    std::string getDiscoveryMethod() const;
    int getDiscoveryYear() const;
    std::string getDiscoveryFacility() const;
    double getOrbitalPeriod() const;
    double getPlanetMass() const;
    double getStellarTemp() const;
    double getStellarRadius() const;
    double getStellarMass() const;
    double getStellarGravity() const;
    double getDistance() const;

    void display() const;
};

#endif
