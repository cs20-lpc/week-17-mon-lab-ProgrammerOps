#include "GraphMatrix.hpp"

void createGraph(Graph*&);
void checkGraphType(Graph*);
void displayNumV(Graph*);
void displayNumE(Graph*);
void checkEdge(Graph*);
void toggleEdge(Graph*&);
void printGraph(Graph*);

int main() {
    // variables
    const int EXIT_VALUE = 8;
    Graph*    gPtr       = nullptr;
    int       userChoice = 0;

    // menu loop
    do {
        cout << endl;
        cout << "1. Create a new graph\n";
        cout << "2. Check if the graph is undirected or directed\n";
        cout << "3. Find the number of vertices\n";
        cout << "4. Find the number of edges\n";
        cout << "5. Check if an edge exists\n";
        cout << "6. Toggle an edge\n";
        cout << "7. Print the graph\n";
        cout << "8. Exit\n\n";

        cout << "Enter your choice: ";
        cin  >> userChoice;
        cout << endl;

        switch (userChoice) {
            case 1:
                createGraph(gPtr);
                break;

            case 2:
                checkGraphType(gPtr);
                break;

            case 3:
                displayNumV(gPtr);
                break;

            case 4:
                displayNumE(gPtr);
                break;

            case 5:
                checkEdge(gPtr);
                break;

            case 6:
                toggleEdge(gPtr);
                break;

            case 7:
                printGraph(gPtr);
                break;

            case 8:
                delete gPtr;
                gPtr = nullptr;
                break;
        }
    } while (userChoice != EXIT_VALUE);

    // terminate
    return 0;
}

void createGraph(Graph*& gPtr) {
    bool b    = false;
    int  numV = 0;

    do {
        cout << "Enter how many vertices are in the graph: ";
        cin  >> numV;
    } while (numV <= 0);

    cout << "Enter 0 for undirected or 1 for directed: ";
    cin  >> b;

    delete gPtr;
    gPtr = new GraphMatrix(numV, static_cast<Graph::GType>(b));
}

void checkGraphType(Graph* gPtr) {
    if (gPtr == nullptr) {
        cout << "You must create a graph first!\n";
    }
    else if (gPtr->getGraphType() == Graph::UNDIRECTED) {
        cout << "The graph is undirected\n";
    }
    else if (gPtr->getGraphType() == Graph::DIRECTED) {
        cout << "The graph is directed\n";
    }
    else {
        cout << "The graph is unknown :(\n";
    }
}

void displayNumV(Graph* gPtr) {
    if (gPtr == nullptr) {
        cout << "You must create a graph first!\n";
    }
    else {
        cout << "Number of vertices: ";
        cout << gPtr->numVertices() << endl;
    }
}

void displayNumE(Graph* gPtr) {
    if (gPtr == nullptr) {
        cout << "You must create a graph first!\n";
    }
    else {
        cout << "Number of edges: ";
        cout << gPtr->numEdges() << endl;
    }
}

void checkEdge(Graph* gPtr) {
    if (gPtr == nullptr) {
        cout << "You must create a graph first!\n";
        return;
    }

    int v1 = 0, v2 = 0;

    cout << "Enter the first vertex: ";
    cin  >> v1;

    cout << "Enter the second vertex: ";
    cin  >> v2;

    if (gPtr->isEdge(v1, v2)) {
        cout << "The edge from " << v1
             << " to " << v2 << " exists!\n";
    }
    else {
        cout << "The edge from " << v1
             << " to " << v2 << " does not exist.\n";
    }
}

void toggleEdge(Graph*& gPtr) {
    if (gPtr == nullptr) {
        cout << "You must create a graph first!\n";
        return;
    }

    int v1 = 0, v2 = 0;

    cout << "Enter the first vertex: ";
    cin  >> v1;

    cout << "Enter the second vertex: ";
    cin  >> v2;

    gPtr->toggleEdge(v1, v2);
}

void printGraph(Graph* gPtr) {
    if (gPtr == nullptr) {
        cout << "You must create a graph first!\n";
    }
    else {
        cout << *gPtr;
    }
}
