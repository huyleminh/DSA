/**
 *
 * Graph.h
 *
 * Created by Huy Le Minh on 2020-12-26
 *
 * Visit my github: https://github.com/huyleminh/
 * Contact me: leminhhuy.hcmus@gmail.com
 *
 *
 * File description: Implement unweighted Graph
*/


#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <vector>
#include <stack>
using namespace std;

class Graph {
private:
    int _vertices;
    vector<vector<bool>> _adjacencyMatrix;

protected:
    void DFT(vector<bool>& visit, const int& vertex);
    void BFT(vector<bool>& visit, const int& vertex);

    void DFS(vector<bool>& visit, vector<vector<int>>& spTree, const int& vertex);
    void BFS(vector<bool>& visit, vector<vector<int>>& spTree, const int& vertex);
public:
    Graph() : _vertices(0) {}
    Graph(const vector<vector<bool>>& adjMaxtix);
    Graph(const Graph& graph);

    Graph(const vector<vector<int>>& edges, const int& nVertices);

    //Traversal
    void depthFirstTraversal(vector<bool> visit);
    void breathFirstTraversal(vector<bool> visit);

    vector<vector<int>> depthFirstSearch(vector<bool> visit);
    vector<vector<int>> breathFirstSearch(vector<bool> visit);
};

#endif