#include "graph.hpp"
#include <iostream>
#include <bits/stdc++.h>


using namespace std;

Graph::Graph(int num_vertices) {
    this->num_vertices = num_vertices;
    this->adjacencia = vector<vector<pair<int, int>>>(num_vertices);
}

void Graph::criarGrafo(int arestas, vector<pair<pair<int, int>, int>> listaArestas) {
    for (int i = 0; i < arestas; i++) {
        int origem = listaArestas[i].first.first;
        int destino = listaArestas[i].first.second;
        int peso = listaArestas[i].second;

        adicionarAresta(origem, destino, peso);
    }
}

void Graph::adicionarAresta(int origem, int destino, int peso) {
    adjacencia[origem].push_back(make_pair(destino, peso));
}

vector<int> Graph::dijkstra(int vertice1) {
    vector<int> distancia(num_vertices, numeric_limits<int>::max());
    distancia[vertice1] = 0; // distância inicial é 0

    set<pair<int, int>> prioridade; // conjunto de prioridades
    prioridade.insert(make_pair(0, vertice1));

    //enquanto não estiver vazio
    while (!prioridade.empty()) {
        int u = prioridade.begin()->second; //pega o vértice com menor distância
        prioridade.erase(prioridade.begin()); //tira ele do conjunto de prioridades

        //para cada aresta que sai de u até v
        for (auto i = adjacencia[u].begin(); i != adjacencia[u].end(); ++i) {
            int v = (*i).first;
            int peso = (*i).second;

            //checa se a distância atual é maior que distância + peso
            if (distancia[v] > distancia[u] + peso) {
                prioridade.erase(make_pair(distancia[v], v)); // remove o par antigo
                distancia[v] = distancia[u] + peso; // atualiza a distância
                prioridade.insert(make_pair(distancia[v], v)); // insere o novo par
            }
        }
    }

    return distancia;
}
