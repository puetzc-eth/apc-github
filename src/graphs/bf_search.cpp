#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>

// start graph implementation

enum BFSColor
{
    White = 0,
    Gray = 1,
    Black = 2
};

struct node
{
    int parent;
    int color;
    int distance;
    node() : parent(0), color(White), distance(0) {};
    void setValues(int p, int c, int d)
    {
        parent = p;
        color = c;
        distance = d;
    }
};

class Graph
{
private:
    std::vector<std::vector<int>> matrix; // adjacency matrix
public:
    Graph(unsigned int size);                  // constructor (no default constructor)
    Graph(std::vector<std::vector<int>> &m);   // constructor (with adjacency matrix)
    void addEdge(int i, int j);                // Number starting at 0!
    std::list<int> getNeighbours(int i) const; // return the Neigbours of a vertex
    bool isConnected(int i, int j) const;      // return wether two vertices are connected
    unsigned int size() const;                 // return the size of the vector
};

Graph::Graph(unsigned int size)
{
    if (size < 1)
    {
        std::cerr << "WARNING: Empty graph created." << std::endl;
    }
    else
    { // resize and set all matrix values to 0
        matrix.resize(size, std::vector<int>(size, 0));
    }
}

Graph::Graph(std::vector<std::vector<int>> &m)
{
    if (m.size() < 1)
    {
        std::cerr << "WARNING: Empty graph created." << std::endl;
    }
    else
    { // resize and set all matrix values to 0
        matrix = m;
    }
}

void Graph::addEdge(int i, int j)
{
    if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix.size())
    {
        std::cerr << "invalid vertex index" << std::endl;
        return;
    }
    matrix[i][j] = matrix[j][i] = 1;
}

std::list<int> Graph::getNeighbours(int i) const
{
    if (i < 0 || i >= matrix.size())
    {
        std::cerr << "invalid vertex index" << std::endl;
        return std::list<int>();
    }
    std::list<int> nbrs;
    for (int j = 0u; j < matrix.size(); ++j)
    {
        if (matrix[i][j] > 0)
        {
            nbrs.push_back(j);
        }
    }
    return nbrs;
}

bool Graph::isConnected(int i, int j) const
{
    if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix.size())
    {
        std::cerr << "invalid vertex index" << std::endl;
        return false;
    }
    return matrix[i][j];
}

unsigned int Graph::size() const
{
    return matrix.size();
}

// end graph implementation

// #include "graph.cpp"

void BFS(const Graph &g, int s, std::vector<node> &bfs_tree)
{
    std::cout << "Breadth-first search starting from vertex " << s << std::endl;
    // set all vertices except root to white
    for (auto &tnd : bfs_tree)
    {
        tnd.setValues(-1, BFSColor::White, 0);
    }

    // set the root
    bfs_tree[s].color = BFSColor::Gray;
    std::queue<int> Q; // queue to store gray vertices
    Q.push(s);         // add root to the queue
    // run as long as there are gray vertices
    while (!Q.empty())
    {
        auto k = Q.front(); // get the first element
        Q.pop();
        for (auto i = 0; i < g.size(); ++i) // loop über die ganze graph matrix um alle vertices zu prüfen ob sie connected sind
        {   // überprüfen, ob gray element k mit den matrix-elementen i des loops connected ist und noch nicht entdeckt wurde
            if (g.isConnected(k, i) && bfs_tree[i].color == BFSColor::White)
            {   // nachbarn "entdecken" k=parent, color= gray, distance = ursprüngl. dist. + 1
                bfs_tree[i].setValues(k, BFSColor::Gray, bfs_tree[k].distance + 1);
                Q.push(i); // graue vertices in die queue pushen
            }
        }
        bfs_tree[k].color = BFSColor::Black; 
    }
}

int main()
{
    std::vector<std::vector<int>> mymatrix = {{0,1,1,0},
                                              {1,0,1,1},
                                              {1,1,0,0},
                                              {0,1,0,0}};

    std::vector<node> mynodevec;
    mynodevec.resize(mymatrix.size());   

    Graph mygraph(mymatrix);                               

    BFS(mygraph, 0, mynodevec);

    for (auto v : mynodevec) {
        std::cout << v.color << " ";
    }
    std::cout << std::endl;
    // output: 2 2 2 2

    for (auto myvec : mymatrix) {
        for ( auto v : myvec) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}