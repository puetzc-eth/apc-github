#include <vector>
#include <iostream>

const int MAXDIST = 200;

class Graph
{
private:
    std::vector<std::vector<int>> matrix; // adjacency matrix
public:
    Graph(unsigned int size); // constructor
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

void dijkstra(const Graph &g, std::vector<int> &paths, int source)
{
    auto n = g.size(); // get the number of vertices
    paths.resize(n);
    for (auto i = 0u; i < n; ++i)
    { // fill in the direct edges
        paths[i] = g.getEdgeWeight(source, i);
    }

    std::vector<int> considered(n, 0); // keep track of which vertices have been considered
    considered[source] = 1; 

    // loop over vertices
    auto k = 0u;
    for (auto i = 0u; i < n - 1; ++i)
    {
        int mindist = MAXDIST; 
        for (auto j = 0u; j < n; ++j)
        { // find the vertex j with the shortest distance in the path vector that has not been considered yet
            if (!considered[j] && paths[j] < mindist) 
            { 
                mindist = paths[j];
                k = j;
            }
        }
        considered[k] = 1; // now k was considered

        for (auto j = 0u; j < n; ++j)
        { // adjust distances of the path vector for all vertices that has not been considered yet
            if (!considered[j]) 
            { 
                int md = mindist + g.getEdgeWeight(k, j);
                paths[j] = std::min(paths[j], md);
            }
        }
    }
}

void print_vector (std::vector<int> &vec) 
{
    for(auto v : vec)
    {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<std::vector<int>> mymatrix = {{0,10,MAXDIST,30,100},
                                              {MAXDIST,0,50,MAXDIST,MAXDIST},
                                              {MAXDIST,MAXDIST,0,MAXDIST,10},
                                              {MAXDIST,MAXDIST,20,0,60},
                                              {MAXDIST,MAXDIST,MAXDIST,MAXDIST,0}};

    Graph mygraph(mymatrix); // matrix-constructor

    std::vector<int> mypaths0, mypaths1, mypaths2; // vector for the paths

    dijkstra(mygraph, mypaths0, 0);
    print_vector(mypaths0);
    // output: 0 10 50 30 60

    dijkstra(mygraph, mypaths1, 1);
    print_vector(mypaths1);
    // output: 200 0 50 200 60

    dijkstra(mygraph, mypaths2, 2);
    print_vector(mypaths2);
    // output: 200 200 0 200 10

    return EXIT_SUCCESS;
}