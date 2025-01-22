#include <vector>

void selectionsort (std::vector<int> &a){
    // loop over every element of vector a (last element not necessary)
    for(int i = 0u; i < a.size() - 1; i++){
        int min_index = i;
        // check if there is a smaller element in the rest of the array
        for(int j = i + 1; j < a.size(); j++){
            if(a[j] < a[min_index]){
                min_index = j;
            }
        }
        // swap the smallest element with the considered element i        
        std::swap(a[min_index], a[i]);
   }
}