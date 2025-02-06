#include <iostream>
#include <vector>

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
    std::vector<std::vector<int>> dist = {{0,4,7,7,5},
                                          {4,0,10,9,6},
                                          {7,10,0,3,7},
                                          {7,9,3,0,4},
                                          {5,6,7,4,0}};

    // TSP
    int minpath = calculateCost(dist,0);

    std::cout << minpath << std::endl;
    // output: 24

    return EXIT_SUCCESS;
}