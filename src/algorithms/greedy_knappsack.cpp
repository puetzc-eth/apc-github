#include <vector>

void greedy_knapsack(const std::vector<unsigned int> &knsize,
                     const std::vector<int> &val,
                     const std::vector<double> &vps, unsigned int M,
                     std::vector<double> &used_frac)
{
    auto current_size = M;
    auto maxi = 0u;
    while (current_size > 0)
    {
        // take as much as possible
        if (knsize[maxi] > current_size)
        { // take a fraction
            auto fraction = current_size / double(knsize[maxi]);
            used_frac.push_back(fraction);
            current_size = 0;
        }
        else
        { // take all
            used_frac.push_back(1.0);
            current_size -= knsize[maxi];
        }
        ++maxi;
    } // while
} // greedy knapsack