#include <iostream>
#include <vector>

#include "../graphs/graph.cpp"

const int NUM = 5;
int calculateCost(std::vector<std::vector<int>> &dist, int source)
{
    int minpath = 0;
    std::vector<int> considered(NUM, 0); // keep track of considered nodes
    considered[source] = 1;
    int current = source;
    for (int i = 1; i < NUM; ++i)
    { // loop over nodes
        int minedge = INT_MAX;
        int minnode = current;
        for (int j = 0; j < NUM; ++j)
        { // loop over edges
            if (!considered[j] && (dist[current][j] < minedge))
            {
                minedge = dist[current][j];
                minnode = j;
            }
        }
        minpath += minedge;      // add edge to path
        considered[minnode] = 1; // add node to considered set
        current = minnode;
    }
    minpath += dist[current][source]; // close cycle
    return minpath;
}

int main()
{
    // distance matrix

    // std::vector<std::vector<int>> dist äää;

    std::vector<std::vector<int>> dist(NUM, std::vector<int>(NUM, 0));
    dist[0][1] = 4;
    dist[0][2] = 7;
    dist[0][3] = 7;
    dist[0][4] = 5;
    dist[1][0] = 4;
    dist[1][2] = 10;
    dist[1][3] = 9;
    dist[1][4] = 6;
    dist[2][0] = 7;
    dist[2][1] = 10;
    dist[2][3] = 3;
    dist[2][4] = 7;
    dist[3][0] = 7;
    dist[3][1] = 9;
    dist[3][2] = 3;
    dist[3][4] = 4;
    dist[4][0] = 5;
    dist[4][1] = 6;
    dist[4][2] = 7;
    dist[4][3] = 4;
    // matrix to store the costs
    std::vector<std::vector<int>> costs(NUM, std::vector<int>((1 << NUM), -1));
    // TSP
    int minpath = calculateCost(costs, dist);
    std::cout << "The shortest path has length " << minpath << std::endl;
    return 0;
}