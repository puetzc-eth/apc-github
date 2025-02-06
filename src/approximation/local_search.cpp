#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

typedef std::vector<int> intvec;
typedef std::queue<std::pair<int, int>> pqueue;

const int NUM = 5;

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
    intvec::iterator pi = std::find(newtour.begin(), newtour.end(),exchanges.front().first);
    intvec::iterator pj = std::find(newtour.begin(), newtour.end(),exchanges.front().second);
    // exchange
    std::iter_swap(pi, pj);
    // remove pair from queue
    exchanges.pop();
    return newtour;
}

int localSearch(std::vector<intvec> &dist, intvec &tour)
{
    int minpath = calculateCost(dist, tour);
    pqueue exchanges; // list of possible exchanges

    for (int i = 0; i < NUM - 1; ++i)
    {
        for (int j = i + 1; j < NUM; ++j)
        {
            exchanges.push(std::make_pair(i, j));
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

int main()
{
    // distance matrix
    std::vector<std::vector<int>> dist = {{0,4,7,7,5},
                                          {4,0,10,9,6},
                                          {7,10,0,3,7},
                                          {7,9,3,0,4},
                                          {5,6,7,4,0}};

    std::vector<int> tour;
    tour.resize(NUM);

    // TSP
    int minpath = localSearch(dist, tour);
    
    std::cout << minpath << std::endl;
    // output: 24

    for (auto t : tour) {
        std::cout << t << " ";
    }

    return EXIT_SUCCESS;
}
