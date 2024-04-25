
#include "GraphT.h"

template<class T>
GraphT<T>::GraphT() {
    //nothing to set up
}

template<class T>
void GraphT<T>::AddVertex(string vertex) {
   vertices.insert(vertex);
}

template<class T>
void GraphT<T>::AddEdge(string vertexA, string vertexB, T weight) {

    if (vertices.count(vertexA) == 0 || vertices.count(vertexB) == 0){
        throw VertexNotFound();
    }

    pair<string, T> vertexWeightPair;
    vertexWeightPair.first = vertexB;
    vertexWeightPair.second = weight;
    graph[vertexA].insert(vertexWeightPair);
}

template<class T>
T* GraphT<T>::GetWeight(string vertexA, string vertexB) {
    if (vertices.count(vertexA) == 0 || vertices.count(vertexB) == 0){
        throw VertexNotFound();
    }

    //check if vertexB exists in vertexA map
    if (graph[vertexA].count(vertexB) == 0){
        return nullptr;
    }

//    T* weight = new T;
//    *weight = graph[vertexA][vertexB];
//    return weight;

    return new T(graph[vertexA][vertexB]); //assuming copy constructor is implemented.
}

template<class T>
queue<string> GraphT<T>::GetToVertices(string vertex) {
    queue<string> adjacentVerticies;

    for (auto it = graph[vertex].begin(); it != graph[vertex].end(); ++it){
        // it->first   vertex
        // it->second  weight
        adjacentVerticies.push(it->first);
    }

    return adjacentVerticies;
}
