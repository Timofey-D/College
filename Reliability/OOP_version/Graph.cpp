//
// Created by Timofey Dankevich on 16/12/2020.
//
#include <iostream>
#include "Graph.h"
#include <Utilities.h>
#include <algorithm>
#include <Random.h>
using namespace std;


Graph::Graph(int V, int E) {
    Graph::V = V;
    Graph::E = E;
    Graph::EN = Graph::E;
    Graph::initializeMatrix(Graph::matrix, Graph::V);
    Graph::initializeEdges(Graph::edges, Graph::E);
    Graph::initializeVisit(Graph::visited, Graph::V);
}


void Graph::showGraph() {

}


void Graph::showMatrix() {
    for (auto & mat : Graph::matrix) {
        for (auto & val : mat)
            printf("%4d", val);
        cout << endl;
    }
}


void Graph::showEdges() {
    for (auto & e : Graph::edges)
        cout << e << " ";
    cout << endl;
};


void Graph::showVisited() {
    for (auto & node : Graph::visited)
        cout << node << " ";
    cout << endl;
}


void Graph::addConnection(const int &node_1, const int &node_2, const int& edge) {
    if (!checkConnection() && Graph::matrix[node_1 - 1][node_2 - 1] == 0) {
        Graph::matrix[node_1 - 1][node_2 - 1] = edge;
        Graph::matrix[node_2 - 1][node_1 - 1] = edge;
        Graph::edges[edge - 1] = 1;
        Graph::EN--;
    }
}


void Graph::removeConnection(const int& node_1, const int& node_2, const int& edge) {
    if (Graph::matrix[node_1 - 1][node_2 - 1] != 0) {
        int removeEdge = Graph::matrix[node_1 - 1][node_2 - 1];
        Graph::matrix[node_1 - 1][node_2 - 1] = 0;
        Graph::matrix[node_2 - 1][node_1 - 1] = 0;
        Graph::edges[removeEdge - 1] = 0;
        Graph::EN++;
    }
}


void Graph::removeConnection(const int& edge) {
    for (int line = 0; line < Graph::matrix.size(); line++) {
        for (int col = 0; col < Graph::matrix[line].size(); col++) {
            if (Graph::matrix[line][col] == edge) {
                Graph::matrix[line][col] = 0;
                Graph::matrix[col][line] = 0;
                Graph::edges[edge - 1] = 0;
                Graph::EN++;
            }
        }
    }
}


void Graph::removeAllConnection() {
    Graph::EN = Graph::E;
    Graph::matrix.clear();
    Graph::edges.clear();
    initializeMatrix(Graph::matrix, Graph::V);
    initializeEdges(Graph::edges, Graph::E);
}

bool Graph::checkConnection() {
    return Graph::EN == 0;
}


void Graph::initializeMatrix(vector<vector<int>>& matrixVector, int& length) {
    matrixVector.resize(length);
    for (int line = 0; line < length; line++) {
        for (int col = 0; col < length; col++)
            matrixVector[line].push_back(0);
    }
}


void Graph::initializeEdges(vector<int>& edgeVector, int& length) {
    edgeVector.resize(length);
    for (int i = 0; i < length; i++)
        edgeVector[i] = 1;
};


void Graph::initializeVisit(vector<int>& visitedVector, int& length) {
    visitedVector.resize(length);
    for (int pos = 0; pos < length; pos++)
        visitedVector[pos] = 0;
};


bool Graph::checkNode(int node) {
    for (int pos = 0; pos < Graph::V; pos++)  {
        if (Graph::visited[pos] == node)
            return true;
    }
    return false;
}


void Graph::addNode(int node) {
    if (checkNode(node))
        return;
    for (int pos = 0; pos < Graph::V; pos++)  {
        if (Graph::visited[pos] == 0) {
            Graph::visited[pos] = node;
            break;
        }
    }
}


void Graph::findPath(const int& start) {
    addNode(start);
    for (int i = 0; i < Graph::matrix[start - 1].size(); i++) {
        if (Graph::matrix[start - 1][i] != 0 && !checkNode(i + 1))
            Graph::findPath(i + 1);
    }
}


void Graph::experiment(const int& start) {
    addNode(start);
    vector<int> queue;
    for (int i = 0; i < Graph::matrix[start - 1].size(); i++) {
        if (Graph::matrix[start - 1][i] != 0 && queue.size() != 3)
            queue.push_back(i);
    }
    int edge;
    for (int i = 0; i < Graph::matrix[start - 1].size(); i++) {
        int random = Random::randomIntegerRange(0, queue.size());
        if (!queue.empty() && random < queue.size())
            edge = queue[random];
        else
            edge = i;
        if (Graph::matrix[start - 1][edge] != 0 && !checkNode(edge + 1))
            Graph::findPath(edge + 1);
    }
}

void Graph::clearVisit() {
    Graph::visited.clear();
    initializeVisit(Graph::visited, Graph::V);
}


int Graph::getV() {
    return Graph::V;
}


int Graph::getE() {
    return Graph::E;
}


bool Graph::checkEdge(const vector<int>& turnOnEdges, int edge) {
    for (auto & e : turnOnEdges) {
        if (e == edge)
            return true;
    }
    return false;
}


void Graph::stateOfEdges() {
    vector<int> turnOnEdges(0);
    for (auto & connection : Graph::matrix) {
        for (auto & edge : connection) {
            if (edge != 0 && !checkEdge(turnOnEdges, edge))
                turnOnEdges.push_back(edge);
        }
    }
    sort(turnOnEdges.begin(), turnOnEdges.end());
    Utilities::showVector(turnOnEdges, false);
}