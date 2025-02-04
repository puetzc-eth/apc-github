#include <iostream>
#include <vector>

const int MAXDIST = 20;

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

void floyd_warshall(const Graph &g, std::vector<std::vector<int>> &d)
{
    auto n = g.size(); // get the number of vertices
    d.resize(n);

    // set direct edges so that g.matrix = d;
    for (auto i = 0u; i < n; ++i)
    {
        d[i].resize(n);
        for (auto j = 0u; j < n; ++j)
        {
            d[i][j] = g.getEdgeWeight(i, j);
        }
    }

    // do the 3 loops
    for (auto k = 0u; k < n; ++k)
    {
        for (auto i = 0u; i < n; ++i)
        {
            for (auto j = 0u; j < n; ++j)
            {   // check whether path over vertex k is shorter than direct path
                d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
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

int main()
{
    std::vector<std::vector<int>> mymatrix = {{0,3,8,4,-4},
                                              {MAXDIST,0,MAXDIST,1,7},
                                              {MAXDIST,4,0,5,11},
                                              {2,5,-5,0,-2},
                                              {MAXDIST,MAXDIST,MAXDIST,6,0}};

    Graph mygraph(mymatrix); // matrix-constructor

    std::vector<std::vector<int>> mydist; // vector for the paths

    floyd_warshall(mygraph, mydist);
    print_matrix(mydist);

    return EXIT_SUCCESS;
}