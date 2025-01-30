#include <iostream>
#include <vector>
#include <queue>

// edge stores weight of edge between u & v <weight, <u, v> >
using edge = std::pair<int, std::pair<int, int>>;
// vector of edges
using pvec = std::vector<edge>;
// priority queue: [value type, container type, order]
// order = greater<edge> --> the smallest element gets highest priority
using min_pqueue = std::priority_queue<edge, pvec, std::greater<edge>>;

void print_route(const edge &A);
pvec mst_kruskal(unsigned int N, min_pqueue &mqueue);

int main()
{

    std::cout << "test" << std::endl;

    return EXIT_SUCCESS;
}

pvec mst_kruskal(unsigned int N, min_pqueue &mqueue)
{
    pvec mst_routes;
    std::vector<int> parents(N);
    for (unsigned int i = 0; i < N; ++i)
    {
        parents[i] = i;
    }
    while (!mqueue.empty())
    {
        const auto &top_edge = mqueue.top();
        auto u = top_edge.second.first;
        auto v = top_edge.second.second;
        auto parent_u = parents[u];
        auto parent_v = parents[v];
        if (parent_u != parent_v)
        { // if u and v are not connected by a path.
            mst_routes.push_back(top_edge);
            for (unsigned int i = 0; i < N; ++i)
            { // UNION(u,v)
                if (parents[i] == parent_v)
                {
                    parents[i] = parent_u;
                }
                std::cout << parents[i] << " ";
            }
            std::cout << std::endl;
        }
        mqueue.pop();
    }
    return mst_routes;
}
