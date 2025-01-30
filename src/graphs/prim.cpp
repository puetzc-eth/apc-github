#include <iostream>
#include <vector>
#include <list>
#include <queue>

// methoden von graph müssen noch gemacht werden!!!!

using nodepair = std::pair<int, int>;
// edge stores weight of edge between u & v <weight, <u, v> >
using edge = std::pair<int, nodepair>;
using pvec = std::vector<edge>;
// priority queue: [value type, container type, order]
using min_pqueue = std::priority_queue<edge, pvec, std::greater<edge>>;

class Graph
{
private:
    std::vector<std::list<nodepair>> vertices; // adjacency list
public:
    Graph(unsigned int size);               // constructor
    void addEdge(int i, int j, int weight); // Number start at 0!
    std::list<nodepair> getNeighbours(int i) const;
    bool isConnected(int i, int j) const;
    unsigned int size() const;
};

void Graph::addEdge(int i, int j, int weight)
{
    vertices[i].push_back(std::make_pair(weight, j));
    vertices[j].push_back(std::make_pair(weight, i));
}
void addEdgesToPQueue(min_pqueue &pq, int i,
                      const std::list<nodepair> &neighbours,
                      std::vector<bool> &used)
{
    for (const auto &p : neighbours)
    {
        int v = p.second;
        if (!used[v])
        {
            pq.push(std::make_pair(p.first, std::make_pair(i, v)));
        }
    }
}

pvec mst_prim(const Graph &g, int s)
{
    std::cout << "Prim's algorithm starting at node " << s << std::endl;
    pvec mst_routes;
    std::vector<bool> used(g.size(), false);
    used[s] = true;
    min_pqueue mqueue;
    addEdgesToPQueue(mqueue, s, g.getNeighbours(s), used);
    while (!mqueue.empty())
    {
        auto u = mqueue.top().second.second;
        if (!used[u])
        {
            mst_routes.push_back(mqueue.top());
            used[u] = true;
            mqueue.pop();
            addEdgesToPQueue(mqueue, u, g.getNeighbours(u), used);
        }
        else
        {
            mqueue.pop();
        }
    }
    return mst_routes;
}

int main()
{

    std::cout << "test" << std::endl;

    return EXIT_SUCCESS;
}