#include <iostream>
#include "Graph.h"
using namespace std;


int main() {
    // vector<vector<bool>> adj = {
    //     {0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    //     {1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0},
    //     {0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0},
    //     {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1},
    //     {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0},
    //     {1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
    //     {0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
    //     {0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
    //     {0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0}
    // };
    vector<vector<bool>> adj = {
        {0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0}
    };

    Graph gr(adj);

    vector<bool> visit(12, false);
    vector<vector<int>> tree;
    // cout << "DFS: ";
    // gr.depthFirstTraversal(visit);
    // cout << endl;

    // cout << "BFS: ";
    // gr.breathFirstTraversal(visit);
    // cout << endl;

    tree = gr.depthFirstSearch(visit);

    for (int i = 0; i < tree.size(); i++) {
        for (int j = 0; j < tree[i].size(); j++)
            cout << tree[i][j] << " ";
        cout << endl;
    }

    return 0;
}