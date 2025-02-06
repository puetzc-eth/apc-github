#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include <algorithm>

struct node
{
    int parent;
    int color;
};

void DFS_visit(Graph &g, unsigned int u, node dfs_list[]);
void DFS(Graph &g, node dfs_list[]);

using nblist = std::list<std::pair<unsigned int, unsigned int>>;

class Graph
{
private:
    struct atom
    {
        char symbol;
        bool aromatic;
        int ring;
        nblist neighbors;
        atom(char s, bool a, int r) : symbol(s), aromatic(a), ring(r) {};
    };
    std::vector<atom> atoms;

public:
    // Graph(); // constructor
    void addAtom(char s, bool a, int r);
    void addEdge(unsigned int i, unsigned int j,
                 int unsigned w); // Number start at 0!
    nblist getNeighbours(unsigned int i) const;
    char getSymbol(unsigned int i) const;
    bool isAromatic(unsigned int i) const;
    int getRing(unsigned int i) const;
    unsigned int size() const;
};

// add atom
void Graph::addAtom(char s, bool a, int r)
{
    atom atm(s, a, r);
    atoms.push_back(atm);
}

// set edge
void Graph::addEdge(unsigned int i, unsigned int j, unsigned int w)
{
    if (i < atoms.size() && j < atoms.size())
    {
        atoms[i].neighbors.push_back(std::make_pair(j, w));
        atoms[j].neighbors.push_back(std::make_pair(i, w));
    }
    else
    {
        std::cerr << "Bond between " << i << " and " << j << " could not be added."
                  << std::endl;
    }
}

nblist Graph::getNeighbours(unsigned int i) const
{
    nblist n(atoms[i].neighbors); // copy it
    return n;
}

unsigned int Graph::size() const
{
    return atoms.size();
}

void DFS(Graph &g, node dfs_list[])
{
    for (unsigned int i = 0; i < g.size(); ++i)
    { // set all adj_list to white
        dfs_list[i].color = 0;
        dfs_list[i].parent = -1;
    }
    // loop over all atoms
    for (unsigned int i = 0; i < g.size(); ++i)
    {
        if (dfs_list[i].color == 0)
        {
            DFS_visit(g, i, dfs_list);
        }
    }
    std::cout << std::endl;
}

void DFS_visit(Graph &g, unsigned int u, node dfs_list[])
{
    dfs_list[u].color = 1; // set to gray
    printAtom(g, u);
    const auto &nb = g.getNeighbours(u);
    for (auto p = nb.begin(); p != nb.end(); ++p)
    {
        auto v = p->first;
        if (dfs_list[v].color == 0)
        {
            bool branch = false;
            if (nb.size() > 2 && p != (--nb.end()))
            { // branch
                std::cout << "(";
                branch = true;
            }
            if (p->second == 2)
            { // double bond
                std::cout << "=";
            }
            else if (p->second == 3)
            { // triple bond
                std::cout << "#";
            }
            dfs_list[v].parent = u;
            DFS_visit(g, v, dfs_list);
            if (branch)
            { // close branch
                std::cout << ")";
                branch = false;
            }
        }
    }
    dfs_list[u].color = 2; // set to black
}

// NOTE: in a real SMILES writer we'd have to worry about
// implicit Hs, charges, chirality, radicals, etc.
void printAtom(Graph &g, unsigned int i)
{
    auto s = g.getSymbol(i);
    if (s == 'N' && g.isAromatic(i))
    {
        std::cout << "n";
    }
    else if (s == 'C' && g.isAromatic(i))
    {
        std::cout << "c";
    }
    else
    {
        std::cout << s;
    }
    int r = g.getRing(i);
    if (r > -1)
    {
        std::cout << r;
    }
}

int main()
{

    std::cout << "Test" << std::endl;

    return EXIT_SUCCESS;
}