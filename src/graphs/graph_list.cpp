#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

class Graph
{
private:
    std::vector<std::list<int>> vertices;       // adjacency list
public:
    Graph(unsigned int size);                   // constructor (no default constructor)
    void addEdge(int i, int j);                 // Number starting at 0!
    std::list<int> getNeighbours(int i) const;  // return the Neigbours of a vertex
    bool isConnected(int i, int j) const;       // return wether two vertices are connected
    unsigned int size() const;                  // return the size of the vector
};

Graph::Graph(unsigned int size) {
    if (size < 1) {  // graph requires at least two vertices
        std::cerr << "WARNING: Empty graph created." << std::endl;
    } else {        // get space for the vertices:
        vertices.resize(size); 
    }
}

void Graph::addEdge(int i, int j) {
    if (i < 0 || j < 0 || i >= vertices.size() || j >= vertices.size()) {
        std::cerr << "invalid vertex index" << std::endl;
        return;
    }
    vertices[i].push_back(j); // add j to the neighbor list of vertex i
    vertices[j].push_back(i); // add i to the neighbor list of vertex j
}

std::list<int> Graph::getNeighbours(int i) const {
    if (i < 0 || i >= vertices.size()) {
        std::cerr << "invalid vertex index" << std::endl;
        return std::list<int>();
    }
    return vertices[i]; // copy it
}

bool Graph::isConnected(int i, int j) const {
    if (i < 0 || j < 0 || i >= vertices.size() || j >= vertices.size()) {
        std::cerr << "invalid vertex index" << std::endl;
        return false;
    }
    // try to find j in the neighbors of vertex i
    auto p = std::find(vertices[i].begin(), vertices[i].end(), j);
    return p != vertices[i].end();
}

unsigned int Graph::size() const {
    return vertices.size();
}



int main(){
    Graph mygraph (3);

    mygraph.addEdge(0,1);
    mygraph.addEdge(0,2);

    std::cout << mygraph.isConnected(0,1) << " " << mygraph.isConnected(1,2) << std::endl;
    // output: 1 0

    auto tmp_list = mygraph.getNeighbours(0);
    for(auto v : tmp_list){
        std::cout << v << " ";
    }
    std::cout << std::endl;
    // output : 1 2

    return EXIT_SUCCESS;
}