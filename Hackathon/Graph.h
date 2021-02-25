//
// Created by Timofey Dankevich on 29/12/2020.
//

#ifndef RELIABILITY_HAKATON_GRAPH_H
#define RELIABILITY_HAKATON_GRAPH_H
#include <vector>
#include <list>
using namespace std;

class Graph {
public:
    Graph(int V, int E);
    void showMatrix();
    void showEdges();
    void showGraph();
    void showVisited();
    void addConnection(const int& node_1, const int& node_2, const int& edge);
    void removeConnection(const int& node_1, const int& node_2, const int& edge);
    void removeConnection(const int& edge);
    void removeAllConnection();
//        bool existConnection();
    void DFS(const int& start);
    void BFS(int start);
    bool checkNode(int node);
    void clearVisit();
    int getV();
    int getE();
private:
    int V;
    int E;
    int EN = E;
    vector<vector<int>> matrix;
    vector<int> edges;
    vector<int> visited;
    void initializeMatrix(vector<vector<int>>& matrixVector, int& length);
    void initializeEdges(vector<int>& edgeVector, int& length);
    void initializeVisit(vector<int>& visitedVector, int& length);
    bool checkConnection();
    void addNode(int node);
    void createQueue(int node, list<int>& queue);
//    void deleteQueue(list<int>& queue);
};


#endif //RELIABILITY_HAKATON_GRAPH_H
