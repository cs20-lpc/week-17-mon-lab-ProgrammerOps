#include "GraphMatrix.hpp"

GraphMatrix::GraphMatrix(int numV, GType type) 
: Graph(numV, 0, type), adjMatrix(nullptr)  // call Graph constructor (v=numV, e=0, type=type)
{
    // TODO
   // Allocate the "rows" (an array of bool pointers)
    adjMatrix = new bool*[v];

    // For each row, allocate the "columns" (a bool array of size v)
    for (int i = 0; i < v; i++) {
        adjMatrix[i] = new bool[v];

        // Initialize every entry to false (no edges yet)
        for (int j = 0; j < v; j++) {
            adjMatrix[i][j] = false;
        }
    }
}

GraphMatrix::~GraphMatrix() {
    // TODO
// Delete each row first
    for (int i = 0; i < v; i++) {
        delete[] adjMatrix[i];
    }

    // Then delete the array of row pointers
    delete[] adjMatrix;

    adjMatrix = nullptr;

}

bool GraphMatrix::isEdge(int i, int j) const {
    // TODO
// Check vertex numbers are valid
    if (i < 0 || i >= v || j < 0 || j >= v)
        throw runtime_error("Invalid vertex");

    return adjMatrix[i][j];

}

ostream& GraphMatrix::print(ostream& os) const {
    os << "    ";
    for (int i = 0; i < v; i++) {
        os << i << ' ';
    }
    os << endl;

    os << "---";
    for (int i = 0; i < v; i++) {
        os << "--";
    }
    os << endl;

    for (int i = 0; i < v; i++) {
        os << i << " | ";
        for (int j = 0; j < v; j++) {
            os << adjMatrix[i][j] << ' ';
        }
        os << endl;
    }

    return os;
}

void GraphMatrix::toggleEdge(int i, int j) {
    // TODO
// Check vertex numbers are valid
    if (i < 0 || i >= v || j < 0 || j >= v)
        throw runtime_error("Invalid vertex");

    bool currentlyExists = adjMatrix[i][j];

    // Flip the edge
    adjMatrix[i][j] = !currentlyExists;

    // If undirected and not a self-loop, mirror it
    if (graphType == UNDIRECTED && i != j) {
        adjMatrix[j][i] = adjMatrix[i][j];

}

 // Update edge count (ONLY once, even for undirected)
    if (!currentlyExists)
        e++;   // we just turned an edge ON
    else
        e--;   // we just turned an edge OFF
}





