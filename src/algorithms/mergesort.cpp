#include <vector>

void mergesort(std::vector<int> &a, std::vector<int> &b, 
                unsigned int left, unsigned int right){
    // Cancel dividing: left > right if only vectors with one entry are present
    if(left < right){
        // DIVIDE the vector in the middle into two parts 
        // and perform the algorithm for the two subparts
        auto middle = (left + right) / 2;
        mergesort(a, b, left, middle);
        mergesort(a, b, middle + 1, right);
        // CONQUER
        unsigned int i, j, k;
        for(i = middle + 1; i > left; i--){
            b[i - 1] = a[i - 1];
        }
        for(j = middle; j < right; j++){
            b[right + middle - j] = a [j + 1];
        }
        // COMBINE
        for(k = left; k <= right; k++){
            if(b[i] <= b[j]){
                a[k] = b[i++];
            } else {
                a[k] = b[j--];
            }
        }
    }
}