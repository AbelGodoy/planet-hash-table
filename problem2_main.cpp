#include <iostream>
#include "Graph.h"

void setupContactsGraph(Graph& graph) {
    graph.addEdge("Amy Lyn", "Juan Jimenez");
    graph.addEdge("Amy Lyn", "Antonio Banderas");
    graph.addEdge("Amy Lyn", "Marilyn Wright");
    graph.addEdge("Juan Jimenez", "Victoria Lopez");
    graph.addEdge("Victoria Lopez", "Rishi Devi");
    graph.addEdge("Antonio Banderas", "Julieta Venegas");
    graph.addEdge("Antonio Banderas", "Greg Grayson");
    graph.addEdge("Julieta Venegas", "Rishi Devi");
    graph.addEdge("Greg Grayson", "Ryan Smith");
    graph.addEdge("Ryan Smith", "Rishi Devi");
}

void setupMapGraph(Graph& graph) {
    graph.addEdge("Start", "River");
    graph.addEdge("Start", "Lake");
    graph.addEdge("Start", "Forest");
    graph.addEdge("River", "Boat");
    graph.addEdge("River", "Forest");
    graph.addEdge("Boat", "Exit: Tree path");
    graph.addEdge("Lake", "Forest");
    graph.addEdge("Forest", "Cave");
    graph.addEdge("Forest", "Cottage");
    graph.addEdge("Cave", "Exit: Tree path");
    graph.addEdge("Cave", "Map");
    graph.addEdge("Cottage", "Map");
}

int main() {
    std::cout << "===========================================\n";
    std::cout << "         Graph Algorithms Demo\n";
    std::cout << "===========================================\n";

    std::cout << "\n--- Problem 2A: Second Degree Contacts ---\n";
    std::cout << "(Using BFS to find contacts for Antonio Banderas)\n";

    Graph contactsGraph;
    setupContactsGraph(contactsGraph);

    std::cout << "\nContacts Graph Structure:";
    contactsGraph.display();

    contactsGraph.findSecondDegreeContacts("Antonio Banderas");

    std::cout << "\n--- Problem 2B: Path Finding with DFS ---\n";
    std::cout << "(Finding path from Start to Exit)\n";

    Graph mapGraph;
    setupMapGraph(mapGraph);

    std::cout << "\nMap Graph Structure:";
    mapGraph.display();

    mapGraph.depthFirstSearch("Start", "Exit: Tree path");

    std::cout << "\n===========================================\n";
    std::cout << "         End of Graph Algorithms Demo\n";
    std::cout << "===========================================\n";

    return 0;
}
