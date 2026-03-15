#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <map>
#include <set>

class Graph {
private:
    std::map<std::string, std::vector<std::string>> adjacencyList;
    std::set<std::string> vertices;

public:
    Graph();

    void addVertex(const std::string& vertex);
    void addEdge(const std::string& vertex1, const std::string& vertex2);
    std::vector<std::string> getNeighbors(const std::string& vertex) const;
    std::vector<std::string> getVertices() const;
    bool hasVertex(const std::string& vertex) const;

    void findSecondDegreeContacts(const std::string& startVertex) const;
    bool depthFirstSearch(const std::string& start, const std::string& target) const;

    void display() const;
};

#endif
