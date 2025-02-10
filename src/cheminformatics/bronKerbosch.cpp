#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class BronKerbosch {
private:
    vector<vector<int>> graph;
    int n;

    void bronKerbosch(vector<int> R, unordered_set<int> P, unordered_set<int> X) {
        if (P.empty() && X.empty()) {
            cout << "Maximale Clique gefunden: ";
            for (int v : R) cout << v << " ";
            cout << endl;
            return;
        }
        
        unordered_set<int> P_copy = P;
        for (int v : P_copy) {
            vector<int> R_new = R;
            R_new.push_back(v);
            
            unordered_set<int> P_new, X_new;
            for (int w : P) if (graph[v][w]) P_new.insert(w);
            for (int w : X) if (graph[v][w]) X_new.insert(w);
            
            bronKerbosch(R_new, P_new, X_new);
            P.erase(v);
            X.insert(v);
        }
    }

public:
    BronKerbosch(vector<vector<int>> adjacencyMatrix) : graph(adjacencyMatrix), n(adjacencyMatrix.size()) {}

    void findCliques() {
        unordered_set<int> P, X;
        for (int i = 0; i < n; i++) P.insert(i);
        bronKerbosch({}, P, X);
    }
};

int main() {
    vector<vector<int>> graph = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };
    
    BronKerbosch bk(graph);
    bk.findCliques();
    
    return 0;
}