#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#include "../graphs/graph.cpp"

const int NUM = 5;
typedef std::vector<int> intvec;
typedef std::queue<std::pair<int, int>> pqueue;
int localSearch(std::vector<intvec> &dist, intvec &tour)
{
    int minpath = calculateCost(dist, tour);
    pqueue exchanges; // list of possible exchanges
    for (int i = 0; i < NUM - 1; ++i)
    {
        for (int j = i + 1; j < NUM; ++j)
        {
            exchanges.push(make_pair(i, j));
        }
    }
    while (!exchanges.empty())
    { // try to improve
        intvec newtour = exchangeNodes(tour, exchanges);
        int newpath = calculateCost(dist, newtour);
        if (newpath < minpath)
        { // new path lenght is better
            minpath = newpath;
            tour = newtour;
        }
    }
    return minpath;
}

int calculateCost(std::vector<intvec> &dist, intvec &tour)
{
    int cost = dist[tour[NUM - 1]][tour[0]];
    for (int i = 1; i < NUM; ++i)
    {
        cost += dist[tour[i - 1]][tour[i]];
    }
    return cost;
}
intvec exchangeNodes(intvec &tour, pqueue &exchanges)
{
    intvec newtour(tour); // copy current tour
    intvec::iterator pi = std::find(newtour.begin(), newtour.end(),
                                    exchanges.front().first);
    intvec::iterator pj = std::find(newtour.begin(), newtour.end(),
                                    exchanges.front().second);
    // exchange
    std::iter_swap(pi, pj);
    // remove pair from queue
    exchanges.pop();
    return newtour;
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