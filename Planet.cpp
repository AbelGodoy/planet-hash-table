#include "Planet.h"
#include <iomanip>

Planet::Planet() : name(""), numStars(0), numPlanets(0), discoveryMethod(""),
                   discoveryYear(0), discoveryFacility(""), orbitalPeriod(0),
                   planetMass(0), stellarTemp(0), stellarRadius(0),
                   stellarMass(0), stellarGravity(0), distance(0) {}

Planet::Planet(const std::string& name, int numStars, int numPlanets,
               const std::string& discoveryMethod, int discoveryYear,
               const std::string& discoveryFacility, double orbitalPeriod,
               double planetMass, double stellarTemp, double stellarRadius,
               double stellarMass, double stellarGravity, double distance)
    : name(name), numStars(numStars), numPlanets(numPlanets),
      discoveryMethod(discoveryMethod), discoveryYear(discoveryYear),
      discoveryFacility(discoveryFacility), orbitalPeriod(orbitalPeriod),
      planetMass(planetMass), stellarTemp(stellarTemp), stellarRadius(stellarRadius),
      stellarMass(stellarMass), stellarGravity(stellarGravity), distance(distance) {}

std::string Planet::getName() const { return name; }
int Planet::getNumStars() const { return numStars; }
int Planet::getNumPlanets() const { return numPlanets; }
std::string Planet::getDiscoveryMethod() const { return discoveryMethod; }
int Planet::getDiscoveryYear() const { return discoveryYear; }
std::string Planet::getDiscoveryFacility() const { return discoveryFacility; }
double Planet::getOrbitalPeriod() const { return orbitalPeriod; }
double Planet::getPlanetMass() const { return planetMass; }
double Planet::getStellarTemp() const { return stellarTemp; }
double Planet::getStellarRadius() const { return stellarRadius; }
double Planet::getStellarMass() const { return stellarMass; }
double Planet::getStellarGravity() const { return stellarGravity; }
double Planet::getDistance() const { return distance; }

void Planet::display() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "----------------------------------------\n";
    std::cout << "Planet Name: " << name << "\n";
    std::cout << "Number of Stars: " << numStars << "\n";
    std::cout << "Number of Planets: " << numPlanets << "\n";
    std::cout << "Discovery Method: " << discoveryMethod << "\n";
    std::cout << "Discovery Year: " << discoveryYear << "\n";
    std::cout << "Discovery Facility: " << discoveryFacility << "\n";
    std::cout << "Orbital Period (days): " << orbitalPeriod << "\n";
    std::cout << "Planet Mass (Earth Mass): " << planetMass << "\n";
    std::cout << "Stellar Temperature (K): " << stellarTemp << "\n";
    std::cout << "Stellar Radius (Solar Radius): " << stellarRadius << "\n";
    std::cout << "Stellar Mass (Solar Mass): " << stellarMass << "\n";
    std::cout << "Stellar Surface Gravity (log10): " << stellarGravity << "\n";
    std::cout << "Distance (pc): " << distance << "\n";
    std::cout << "----------------------------------------\n";
}
