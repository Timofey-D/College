//
// Created by Timofey Dankevich on 16/12/2020.
//

#ifndef RELIABILITY_NETWORK_GRAPH_H
#define RELIABILITY_NETWORK_GRAPH_H
#include <vector>
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
        void findPath(const int& start);
        bool checkNode(int node);
        void clearVisit();
        int getV();
        int getE();
        void stateOfEdges();
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
        bool checkEdge(const vector<int>& turnOnEdges, int edge);
};


#endif //RELIABILITY_NETWORK_GRAPH_H
