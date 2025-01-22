#include <vector>

void add_queen(std::vector<unsigned int> &cols_queen,
               std::vector<unsigned int> &cols_free,
               std::vector<unsigned int> &rising_free,
               std::vector<unsigned int> &falling_free, unsigned int i)
{
    auto N = cols_queen.size(); // number of queens
    for (auto j = 0u; j < N; ++j)
    { // loop over columns
        // check if the field is free
        auto n2Idx = N + i - j - 1;
        if (cols_free[j] && falling_free[n2Idx] && rising_free[i + j])
        {
            cols_queen[i] = j; // add queen
            // indicate guarded positions
            cols_free[j] = 0;
            falling_free[n2Idx] = 0;
            rising_free[i + j] = 0;
            if (i == (N - 1))
            { // check if we're done
                // print_conf(cols_queen);
            }
            else
            { // go to next row
                add_queen(cols_queen, cols_free, rising_free, falling_free, i + 1);
            }
            // backtrack
            cols_free[j] = 1;
            falling_free[n2Idx] = 1;
            rising_free[i + j] = 1;
        }
    }
}