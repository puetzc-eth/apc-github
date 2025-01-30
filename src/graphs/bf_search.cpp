#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>

#include "graph.cpp"

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
    void setValues(int p, int c, int d)
    {
        parent = p;
        color = c;
        distance = d;
    }
};

void BFS(const Graph &g, int s, std::vector<node> &bfs_tree)
{
    std::cout << "Breadth-first search starting from vertex " << s << std::endl;
    // set all vertices except root to white
    for (auto &tnd : bfs_tree)
        tnd.setValues(-1, BFSColor::White, 0);
    // set the root
    bfs_tree[s].color = BFSColor::Gray;
    std::queue<int> Q; // queue to store gray vertices
    Q.push(s);         // add root to the queue
    // run as long as there are gray vertices
    while (!Q.empty())
    {
        auto k = Q.front(); // get the first element
        Q.pop();
        for (auto i = 0; i < g.size(); ++i)
        {
            if (g.isConnected(k, i) && bfs_tree[i].color == BFSColor::White)
            {
                bfs_tree[i].setValues(k, BFSColor::Gray,
                                      bfs_tree[k].distance + 1);
                Q.push(i);
            }
        }
        bfs_tree[k].color = BFSColor::Black;
    }
}

int main()
{
    Graph mygraph(3);

    node mynode;
    mynode.setValues(1, White, 1);

    mygraph.addEdge(0, 1);
    mygraph.addEdge(0, 2);

    BFS(mygraph, 0, mynode);

    return EXIT_SUCCESS;
}