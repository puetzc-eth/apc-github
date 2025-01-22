#include <iostream>
#include <vector>

void selectionsort (std::vector<int> &arr_func){
    // loop over every element of arr_func (last element not necessary)
    for(int i = 0u; i < arr_func.size() - 1; i++){
        int min_index = i;
        // check if there is a smaller element in the rest of the array
        for(int j = i + 1; j < arr_func.size(); j++){
            if(arr_func[j] < arr_func[min_index]){
                min_index = j;
            }
        }
        // swap the smallest element with the considered element i        
        std::swap(arr_func[min_index], arr_func[i]);
   }
}

void mergesort (std::vector<int> &arr_func, std::vector<int> &b, unsigned int left, unsigned int right){
   
}

int main(){

    std::vector<int> arr = {5,2,4,7,1,3,2,6};

    for(auto a : arr){
        std::cout << a << " ";
    }
    std::cout << std::endl;

    mergesort(arr);

    for(auto a : arr){
        std::cout << a << " ";
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}