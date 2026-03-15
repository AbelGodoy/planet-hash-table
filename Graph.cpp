#include "Graph.h"
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

Graph::Graph() {}

void Graph::addVertex(const std::string& vertex) {
    if (vertices.find(vertex) == vertices.end()) {
        vertices.insert(vertex);
        adjacencyList[vertex] = std::vector<std::string>();
    }
}

void Graph::addEdge(const std::string& vertex1, const std::string& vertex2) {
    addVertex(vertex1);
    addVertex(vertex2);

    if (std::find(adjacencyList[vertex1].begin(), adjacencyList[vertex1].end(), vertex2) 
        == adjacencyList[vertex1].end()) {
        adjacencyList[vertex1].push_back(vertex2);
    }

    if (std::find(adjacencyList[vertex2].begin(), adjacencyList[vertex2].end(), vertex1) 
        == adjacencyList[vertex2].end()) {
        adjacencyList[vertex2].push_back(vertex1);
    }
}

std::vector<std::string> Graph::getNeighbors(const std::string& vertex) const {
    auto it = adjacencyList.find(vertex);
    if (it != adjacencyList.end()) {
        return it->second;
    }
    return std::vector<std::string>();
}

std::vector<std::string> Graph::getVertices() const {
    return std::vector<std::string>(vertices.begin(), vertices.end());
}

bool Graph::hasVertex(const std::string& vertex) const {
    return vertices.find(vertex) != vertices.end();
}

void Graph::findSecondDegreeContacts(const std::string& startVertex) const {
    if (!hasVertex(startVertex)) {
        std::cout << "Vertex '" << startVertex << "' not found in graph.\n";
        return;
    }

    std::map<std::string, int> degree;
    std::queue<std::string> bfsQueue;
    std::set<std::string> visited;

    degree[startVertex] = 0;
    visited.insert(startVertex);
    bfsQueue.push(startVertex);

    std::cout << "\n=== BFS from " << startVertex << " ===\n";
    std::cout << "Starting vertex: " << startVertex << " (degree 0)\n\n";

    std::cout << "First Degree Contacts:\n";

    while (!bfsQueue.empty()) {
        std::string current = bfsQueue.front();
        bfsQueue.pop();

        for (const std::string& neighbor : getNeighbors(current)) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                degree[neighbor] = degree[current] + 1;

                if (degree[neighbor] == 1) {
                    std::cout << "  - " << neighbor << "\n";
                }

                if (degree[neighbor] < 2) {
                    bfsQueue.push(neighbor);
                }
            }
        }
    }

    std::cout << "\nSecond Degree Contacts:\n";
    for (const auto& pair : degree) {
        if (pair.second == 2) {
            std::cout << "  - " << pair.first << "\n";
        }
    }
    std::cout << "==============================\n";
}

bool Graph::depthFirstSearch(const std::string& start, const std::string& target) const {
    if (!hasVertex(start)) {
        std::cout << "Start vertex '" << start << "' not found in graph.\n";
        return false;
    }

    std::cout << "\n=== DFS from " << start << " to " << target << " ===\n";
    std::cout << "Path visited:\n";

    std::set<std::string> visited;
    std::stack<std::string> dfsStack;

    dfsStack.push(start);

    while (!dfsStack.empty()) {
        std::string current = dfsStack.top();
        dfsStack.pop();

        if (visited.find(current) != visited.end()) {
            continue;
        }

        visited.insert(current);
        std::cout << "  -> " << current << "\n";

        if (current == target) {
            std::cout << "\nTarget '" << target << "' found!\n";
            std::cout << "==============================\n";
            return true;
        }

        std::vector<std::string> neighbors = getNeighbors(current);
        for (auto it = neighbors.rbegin(); it != neighbors.rend(); ++it) {
            if (visited.find(*it) == visited.end()) {
                dfsStack.push(*it);
            }
        }
    }

    std::cout << "\nTarget '" << target << "' not found.\n";
    std::cout << "==============================\n";
    return false;
}

void Graph::display() const {
    std::cout << "\n=== Graph Adjacency List ===\n";
    for (const std::string& vertex : vertices) {
        std::cout << vertex << " -> ";
        const std::vector<std::string>& neighbors = adjacencyList.at(vertex);
        for (size_t i = 0; i < neighbors.size(); i++) {
            std::cout << neighbors[i];
            if (i < neighbors.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "\n";
    }
    std::cout << "============================\n";
}
