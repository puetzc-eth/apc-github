#include <iostream>
#include <vector>
#include <algorithm>

const int NUM = 5;                            // number of nodes
typedef std::vector<std::vector<int>> matrix; // to hold the distance matrix
double minpath = INT_MAX;

// recursive helper function
void TSPrec(const matrix &dist, std::vector<bool> &visited, matrix &sd,
            int weight, int n, std::vector<int> &path)
{
    if (n == NUM)
    {                    // LEAFS
        printPath(path); // print path
        int curr_res = weight + dist[path[n - 1]][path[0]];
        if (curr_res < minpath)
        {
            minpath = curr_res;
            std::cout << "new shortest path: " << curr_res << std::endl;
        }
        return;
    }
    for (unsigned int i = 0; i < NUM; ++i)
    { // NOT LEAF: loop over nodes
        if (path[n - 1] != i && visited[i] == false)
        {
            int d = dist[path[n - 1]][i];
            weight += d; // add distance to weight
            std::vector<int>::iterator p = std::find(sd[path[n - 1]].begin(),
                                                     sd[path[n - 1]].end(), d);
            sd[path[n - 1]].erase(p); // remove distance
            p = std::find(sd[i].begin(), sd[i].end(), d);
            sd[i].erase(p);   // remove distance
            double lbnew = 0; // re-calculate lower bound
            for (unsigned int j = 0; j < NUM; ++j)
            {
                if (sd[j].size() == NUM - 1)
                { // no edge selected yet
                    lbnew += sd[j][0] + sd[j][1];
                }
                else if (sd[j].size() == NUM - 2)
                { // 1 edge selected
                    lbnew += sd[j][0];
                }
            }
            lbnew *= 0.5;
            lbnew += weight;
            if (lbnew < minpath)
            { // explore the node further
                path[n] = i;
                visited[i] = true;
                TSPrec(dist, visited, sd, weight, n + 1, path); // call next
            }
            // else : prune the node and backtrack
            weight -= d;
            sd[path[n - 1]].push_back(d);
            std::sort(sd[path[n - 1]].begin(), sd[path[n - 1]].end());
            sd[i].push_back(d);
            std::sort(sd[i].begin(), sd[i].end());
            visited[i] = false;
        }
    }
}

void printPath(const std::vector<int> &path)
{ // print path
    std::cout << "Path = ";
    for (unsigned int i = 0; i < NUM; ++i)
    {
        std::cout << path[i] << " - ";
    }
    std::cout << "0" << std::endl; // add origin at end
}

void calculateCost(const matrix &dist)
{                                          // start function for backtracking
    std::vector<bool> visited(NUM, false); // keep track of visited nodes
    std::vector<int> path(NUM, -1);        // keep track of visited nodes
    matrix srtdist(NUM);                   // sorted distances
    for (unsigned int i = 0; i < NUM; ++i)
    {
        std::vector<int> tmp(dist[i].begin(), dist[i].end());
        std::sort(tmp.begin(), tmp.end()); // sort the distances
        tmp.erase(tmp.begin());            // remove zero (i=i)
        srtdist[i] = tmp;
    }
    // calculate initial lower bound
    double lb = 0;
    for (unsigned int i = 0; i < NUM; ++i)
    {
        lb += srtdist[i][0] + srtdist[i][1]; // 2 shortest
    }
    lb *= 0.5;
    std::cout << "initial lower bound: " << lb << std::endl;
    // start at vertex = 0
    visited[0] = true;
    path[0] = 0;
    // call to TSPRec for weight = 0 and level = 1
    TSPrec(dist, visited, srtdist, 0, 1, path);
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
    calculateCost(dist);
    std::cout << "The shortest path has length " << minpath << std::endl;

    return EXIT_SUCCESS;
}