#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>

#include "graph.cpp"

enum DFSColor
{
    White = 0,
    Gray = 1,
    Black = 2
};

struct node
{
    int parent;
    int color;
    int dtime;
    int ftime;
};

void DFS_visit(const Graph &g, int u, int &time, std::vector<node> &dfs_list)
{
    dfs_list[u].dtime = ++time;
    dfs_list[u].color = DFSColor::Gray; // set to gray
    std::list<int> nb = g.getNeighbours(u);
    for (auto v : nb)
    {
        if (dfs_list[v].color == DFSColor::White)
        {
            dfs_list[v].parent = u;
            DFS_visit(g, v, time, dfs_list);
        }
    }
    dfs_list[u].color = DFSColor::Black; // set to black
    dfs_list[u].ftime = ++time;
}

void DFS(const Graph &g, std::vector<node> &dfs_list)
{
    int time = -1;
    for (auto i = 0; i < g.size(); ++i)
    { // set all vertices to white
        dfs_list[i].color = DFSColor::White;
        dfs_list[i].parent = -1;
    }
    // loop over all vertices
    for (auto i = 0; i < g.size(); ++i)
    {
        if (dfs_list[i].color == DFSColor::White)
        {
            DFS_visit(g, i, time, dfs_list);
        }
    }
}

int main()
{
    std::vector<std::vector<int>> mymatrix = {{0, 1, 1, 0},
                                              {1, 0, 1, 1},
                                              {1, 1, 0, 0},
                                              {0, 1, 0, 0}};

    std::vector<node> mynodevec;
    mynodevec.resize(mymatrix.size());

    Graph mygraph(mymatrix);

    DFS(mygraph, mynodevec);

    for (auto v : mynodevec)
    {
        std::cout << v.color << " ";
    }
    std::cout << std::endl;
    // output: 2 2 2 2

    for (auto myvec : mymatrix)
    {
        for (auto v : myvec)
        {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}