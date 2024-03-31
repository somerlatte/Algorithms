#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <bits/stdc++.h>
#include <iostream>


class Graph {
    public:
        int num_vertices, arestas, origem, destino, peso, vertice1;

        // lista de adjacência para grafo
        std::vector<std::vector<std::pair<int, int>>> adjacencia;

        Graph(int num_vertices);
        
        // constrói o grafo dada a lista de adjacência e as arestas
        void criarGrafo(int arestas, std::vector<std::pair<std::pair<int, int>, int>> listaArestas);
        
        void adicionarAresta(int origem, int destino, int peso);

        //Dijkstra para caminhos mais curtos 
        std::vector<int> dijkstra(int vertice1);
};

#endif // GRAPH_HPP