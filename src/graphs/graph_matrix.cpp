#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

class Graph
{
private:
    std::vector<std::vector<int>> matrix;       // adjacency matrix
public:
    Graph(unsigned int size);                   // constructor (no default constructor)
    void addEdge(int i, int j);                 // Number starting at 0!
    std::list<int> getNeighbours(int i) const;  // return the Neigbours of a vertex
    bool isConnected(int i, int j) const;       // return wether two vertices are connected
    unsigned int size() const;                  // return the size of the vector
};

Graph::Graph(unsigned int size) {
    if (size < 1) {  
        std::cerr << "WARNING: Empty graph created." << std::endl;
    } else {        // resize and set all matrix values to 0
        matrix.resize(size, std::vector<int>(size, 0)); 
    }
}

void Graph::addEdge(int i, int j) {
    if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix.size()) {
        std::cerr << "invalid vertex index" << std::endl;
        return;
    }
    matrix[i][j] = matrix[j][i] = 1; 
}

std::list<int> Graph::getNeighbours(int i) const {
    if (i < 0 || i >= matrix.size()) {
        std::cerr << "invalid vertex index" << std::endl;
        return std::list<int>();
    }
    std::list<int> nbrs;
    for (int j = 0u; j < matrix.size(); ++j) {
        if (matrix[i][j] > 0){
            nbrs.push_back(j);
        }
    }
    return nbrs; 
}

bool Graph::isConnected(int i, int j) const {
    if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix.size()) {
        std::cerr << "invalid vertex index" << std::endl;
        return false;
    }
    return matrix[i][j];
}

unsigned int Graph::size() const {
    return matrix.size();
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