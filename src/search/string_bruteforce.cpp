#include <string>
#include <iostream>

int bfsearch(const std::string &text, const std::string &patt)
{
    int M = patt.length();
    int N = text.length();
    int i, j;
    for (i = 0, j = 0; i < N && j < M; ++i, ++j)
    {
        while (text[i] != patt[j] && i < N)
        {               // while mismatch
            i -= j - 1; // back-up i
            j = 0;      // back-up j
        }
    }
    if (j == M)
    {
        return i - M; // match
    }
    else
    {
        return -1; // mismatch
    }
}

int main(){

    std::string text = "Hallo, mein Name ist Connor";

    std::string patt = "Connor";

    std::cout << text << " | " << patt << std::endl;

    int search = bfsearch(text, patt);

    //std::cout << bfsearch(text, patt);

    std::cout << text[bfsearch(text, patt)];

    return EXIT_SUCCESS;
}