#include <vector>
#include <iostream>

void selectionsort(std::vector<int> &a)
{
    // first loop over elements
    for (unsigned int i = 0; i < a.size() - 1; ++i)
    {
        int min = i;
        // second loop over elements
        for (unsigned int j = i + 1; j < a.size(); ++j)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        // swapelements
        int t = a[min];
        a[min] = a[i];
        a[i] = t;
    }
} // selectionsort

void print_vector(std::vector<int> vec)
{
    for (auto v : vec)
    {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> test = {1, 3, 5, 7, 9, 2, 4, 6, 8};

    print_vector(test);

    selectionsort(test);

    print_vector(test);

    return EXIT_SUCCESS;
}