#include <iostream>
#include <vector>

class Ullmann {
private:
    std::vector<std::vector<int>> G, M, P;
    int n, m;

    // Prüft, ob die aktuelle Matrix P eine gültige Zuordnung darstellt
    bool isValid(int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (P[i][col] == 1) return false;
        }
        return true;
    }

    // Überprüft, ob die aktuelle Zuordnung isomorph ist
    bool checkIsomorphism() {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                if (M[i][j] == 1) {
                    int u = -1, v = -1;
                    for (int k = 0; k < n; ++k) {
                        if (P[i][k] == 1) u = k;
                        if (P[j][k] == 1) v = k;
                    }
                    if (G[u][v] != 1) return false;
                }
            }
        }
        return true;
    }

    // Rekursive Backtracking-Suche
    bool backtrack(int row) {
        if (row == m) return checkIsomorphism();

        for (int col = 0; col < n; ++col) {
            if (M[row][row] <= G[col][col] && isValid(row, col)) {
                P[row][col] = 1;
                if (backtrack(row + 1)) return true;
                P[row][col] = 0;
            }
        }
        return false;
    }

public:
    Ullmann(std::vector<std::vector<int>> graph, std::vector<std::vector<int>> pattern)
        : G(graph), M(pattern), n(graph.size()), m(pattern.size()) {
        P = std::vector<std::vector<int>>(m, std::vector<int>(n, 0));
    }

    bool findSubgraph() {
        return backtrack(0);
    }
};

void print_matrix (std::vector<std::vector<int>> matrix){
    for (auto vec : matrix) {
        for (auto v : vec) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
}

int getNeighbors (std::vector<std::vector<int>> &matrix, int vertex) {
    int sum = 0;
    for (auto m : matrix[vertex]) {
        if (m > 0) ++sum; 
    }
    return sum;
}

bool ullmann (std::vector<std::vector<int>> &graph, std::vector<std::vector<int>> &pattern){

    int n_graph = graph.size();
    int n_pattern = pattern.size();

    // bool matrix with n_pattern rows and n_graph columns
    std::vector<std::vector<int>> M(n_pattern, std::vector<int>(n_graph, 0));

    // initial possible-corresponents matrix M_0
    for (int i = 0; i < n_pattern; ++i){
        for (int j = 0; j < n_graph; ++j){
            if (getNeighbors(graph, j) >= getNeighbors(pattern, i)) M[i][j] = 1;
        }
    }
    print_matrix(M);

    // loop over pattern vertices
    for (int i = 0; i < n_pattern; ++i) {
        for (int j = 0; j < n_graph; ++j){
            if (graph[i][j] == 1) {
                for (int k = 0; k < n_graph; k++){
                    if (M[i][j] != 0) M[i][k] = 1;  
                }
            }
        }
    }

    print_matrix(M);

    return 1;
}


int main() {

    std::vector<std::vector<int>> Molecule = {
        {0,1,0,0,0,0,0},
        {1,0,1,0,0,0,0},
        {0,1,0,1,0,0,0},
        {0,0,1,0,1,1,0},
        {0,0,0,1,0,0,0},
        {0,0,0,1,0,0,1},
        {0,0,0,0,0,1,0}
    };

    //print_matrix(Molecule);
    
    std::vector<std::vector<int>> Query = {
        {0,1,0,0,0},
        {1,0,1,1,0},
        {0,1,0,0,0},
        {0,1,0,0,1},
        {0,0,0,1,0}
    };
    
    std::cout << ullmann(Molecule, Query) << std::endl;

   //Ullmann ullmann(Molecule, Query);
    
    
   // if (ullmann.findSubgraph()) {
   //     std::cout << "Ein isomorpher Teilgraph wurde gefunden!" << std::endl;
   // } else {
   //     std::cout << "Kein isomorpher Teilgraph gefunden." << std::endl;
   // }
    
    return EXIT_SUCCESS;
}