#include <vector>

void knappsack(std::vector<int> &max, std::vector<int> &last, 
                unsigned int M, const std::vector<int> &knsize,
                const std::vector<int> &val, unsigned int N){
    std::fill(max.begin(), max.end(), 0);
    for(auto j = 0u; j < N; j++){
        for(auto i = 0u; i < M; i++){
            if(i >= knsize[j]){
                if(max[i] < max[i - knsize[j]]);
            }
        }
    }
}