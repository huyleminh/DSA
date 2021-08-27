#include "Graph.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

Graph::Graph(const vector<vector<bool>>& adjMaxtix) {
    _adjacencyMatrix = adjMaxtix;
    _vertices = (int)_adjacencyMatrix.size();
}

Graph::Graph(const Graph& graph) {
    _adjacencyMatrix = graph._adjacencyMatrix;
    _vertices = (int)_adjacencyMatrix.size();
}

Graph::Graph(const vector<vector<int>>& edges, const int& nVertices) {
    if (nVertices < 0) {
        _vertices = 0;
        return;
    }
    
    //Initial state of adjacent matrix
    _adjacencyMatrix.resize(nVertices, vector<bool>(nVertices, false));
    this->_vertices = nVertices;

    for (size_t i = 0; i < edges.size(); ++i) {
        _adjacencyMatrix[edges[i][0] - 1][edges[i][1] - 1] = true;
    }
}

//-------------------------------------------------------------------------------
//protected methods

void Graph::DFT(vector<bool>& visit, const int& vertex) {
    if (vertex < 0 || vertex > _vertices - 1 || (size_t)_vertices != visit.size()) {
        cout << "ERROR vertex." << endl;
        return;
    }
    //Mark vertex as visited
    cout << vertex + 1 << " ";
    visit[vertex] = true;

    for (int u = 0; u < _vertices; u++) {
        if (_adjacencyMatrix[vertex][u] && !visit[u])
            this->DFT(visit, u);
    }
}

void Graph::BFT(vector<bool>& visit, const int& vertex) {
    if (vertex < 0 || vertex > _vertices - 1 || (size_t)_vertices != visit.size()) {
        cout << "ERROR vertex." << endl;
        return;
    }

    queue<int> q;

    if (visit[vertex])
        return;
    
    q.push(vertex);
    visit[vertex] = true;

    while (q.size() != 0) {
        int v = q.front();
        q.pop();
        cout << v + 1 << " ";
        for (int i = 0; i < _vertices; i++) {
            if (_adjacencyMatrix[v][i] && !visit[i]) {
                q.push(i);
                visit[i] = true;
            }
        }
    }
}

void Graph::DFS(vector<bool>& visit, vector<vector<int>>& spTree, const int& vertex) {
    if (vertex < 0 || vertex > _vertices - 1 || (size_t)_vertices != visit.size()) {
        cout << "ERROR vertex." << endl;
        return;
    }

    if (visit[vertex])
        return;
    stack<int> st;
    st.push(vertex);
    visit[vertex] = true;
    
    while (!st.empty()) {
        int v = st.top();
        bool check = 0;

        for (int i = 0; i < _vertices; i++) {
            if (_adjacencyMatrix[v][i] && !visit[i]) {
                check = true;
                st.push(i);
                visit[i] = true;
                spTree.push_back({ v + 1, i + 1 });
                break;
            }
        }
        if (!check)
            st.pop();
    }
}

void Graph::BFS(vector<bool>& visit, vector<vector<int>>& spTree, const int& vertex) {
    if (vertex < 0 || vertex > _vertices - 1 || (size_t)_vertices != visit.size()) {
        cout << "ERROR vertex." << endl;
        return;
    }

    if (visit[vertex])
        return;
    queue<int> q;
   
    q.push(vertex);
    visit[vertex] = true;

    while (q.size() != 0) {
        int v = q.front();
        q.pop();
        
        for (int i = 0; i < _vertices; i++) {
            if (_adjacencyMatrix[v][i] && !visit[i]) {
                q.push(i);
                visit[i] = true;
                spTree.push_back({v + 1, i + 1});
            }
        }
    }
}

//-------------------------------------------------------------------------------
//public methods

void Graph::depthFirstTraversal(vector<bool> visit) {
    for (int i = 0; i < _vertices; i++)
        if (!visit[i])
            DFT(visit, i);
}

void Graph::breathFirstTraversal(vector<bool> visit) {
    for (int i = 0; i < _vertices; i++)
        if (!visit[i])
            BFT(visit, i);
}

vector<vector<int>> Graph::depthFirstSearch(vector<bool> visit) {
    vector<vector<int>> spTree;

    for (int i = 0; i < _vertices; i++)
        if (!visit[i])
            DFS(visit, spTree, i);
    return spTree;
}

vector<vector<int>> Graph::breathFirstSearch(vector<bool> visit) {
    vector<vector<int>> spTree;

    for (int i = 0; i < _vertices; i++)
        if (!visit[i])
            BFS(visit, spTree, i);
    return spTree;
}