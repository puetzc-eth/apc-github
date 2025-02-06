#include <iostream>
#include <vector>

const int MAXDIST = 999;

class Graph
{
private:
    std::vector<std::vector<int>> matrix; // adjacency matrix
public:
    Graph(unsigned int size);                // constructor
    Graph(std::vector<std::vector<int>> &m); // constructor
    void addEdge(int i, int j, int w);
    int getEdgeWeight(int i, int j) const;
    unsigned int size() const;
};

Graph::Graph(unsigned int size)
{
    if (size < 1)
    {
        std::cerr << "WARNING: Empty graph created." << std::endl;
    }
    else
    {
        // resize and set all elements to max. distance
        matrix.resize(size, std::vector<int>(size, MAXDIST));
        // set (i,i) element to zero
        for (unsigned int i = 0; i < size; ++i)
        {
            matrix[i][i] = 0;
        }
    }
}

// matrix constructor
Graph::Graph(std::vector<std::vector<int>> &m)
{
    if (m.size() < 1)
    {
        std::cerr << "WARNING: Empty graph created." << std::endl;
    }
    else
    {
        matrix = m;
    }
}

// set edge
void Graph::addEdge(int i, int j, int w)
{
    matrix[i][j] = w; // directed, weighted edge
}

int Graph::getEdgeWeight(int i, int j) const
{
    return matrix[i][j];
}

unsigned int Graph::size() const
{
    return matrix.size();
}

void print_vector (std::vector<int> &vec) 
{
    for (auto v : vec)
    {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

void print_matrix (std::vector<std::vector<int>> &mat) 
{
    for (auto vec : mat)
    {
        for (auto v : vec){
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}