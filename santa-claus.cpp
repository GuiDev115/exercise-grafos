#include <vector>
#include <queue>
#include <functional>
#include <iostream>
#include <algorithm>


using namespace std;

#define MAXIMO_VERTICES 500050
#define MAXIMO_aresta 500000

struct Aresta {
    int start, end, weight;
};

Aresta aresta[MAXIMO_aresta];
int pai[MAXIMO_VERTICES];

int comparearesta(const Aresta& a, const Aresta& b) {
    return a.weight < b.weight;
}

int findComponent(int vertex) {
    if (vertex == pai[vertex])
        return vertex;
    return pai[vertex] = findComponent(pai[vertex]);
}

int kruskal(int ArestaCount) {
    int totalWeight = 0;
    for (int i = 0; i < ArestaCount; ++i) {
        int startComponent = findComponent(aresta[i].start);
        int endComponent = findComponent(aresta[i].end);
        if (startComponent != endComponent) {
            pai[startComponent] = endComponent;
            totalWeight += aresta[i].weight;
        }
    }
    return totalWeight;
}

int main() {
    int numArestas, numeroVertices;

    while (cin >> numeroVertices >> numArestas, numeroVertices && numArestas) {
        fill(aresta, aresta + numArestas, Aresta());
        fill(pai, pai + numeroVertices + 1, 0);

        for (int i = 0; i < numArestas; ++i)
            cin >> aresta[i].start >> aresta[i].end >> aresta[i].weight;

        sort(aresta, aresta + numArestas, comparearesta);

        for (int i = 1; i <= numeroVertices; ++i)
            pai[i] = i;

        cout << kruskal(numArestas) << endl;
    }

    return 0;
}