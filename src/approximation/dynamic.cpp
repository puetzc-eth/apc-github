#include <iostream>
#include <vector>

const int NUM = 5;

int calculateCost (std::vector<std::vector<int>> &costs, std::vector<std::vector<int>> &dist, int index, int mask)
{
    if (mask == (1 << NUM) - 1)
    { // we’re at a leaf
        return dist[index][0];
    }

    if (costs[index][mask] != -1)
    { // cost is already calculated
        return costs[index][mask];
    }

    costs[index][mask] = INT_MAX;
    
    for (int i = 0; i < NUM; ++i)
    {
        if (!(mask & (1 << i)))
        {                                                                  // AND
            int new_cost = calculateCost(costs, dist, i, mask ^ (1 << i)); // XOR
            costs[index][mask] = std::min(costs[index][mask],
                                     new_cost + dist[index][i]); // minimum
        }
    }
    return costs[index][mask];
}

int main()
{
    // distance matrix
    std::vector<std::vector<int>> dist = {{0,4,7,7,5},
                                          {4,0,10,9,6},
                                          {7,10,0,3,7},
                                          {7,9,3,0,4},
                                          {5,6,7,4,0}};

    // matrix to store the costs
    std::vector<std::vector<int>> costs(NUM, std::vector<int>((1 << NUM), -1));

    for (auto vec : costs) {
        for (auto v : vec) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }

    std::cout << costs[1].size() << std::endl;

    std::cout << (1 << NUM) << std::endl;

    // TSP
    int minpath = calculateCost(costs, dist, 0, 1);
    
    std::cout << minpath << std::endl;
    // output: 24

    return EXIT_SUCCESS;
}
