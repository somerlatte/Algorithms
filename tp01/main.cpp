#include <iostream>
#include "graph.hpp"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int num_cidades, num_caminhos;
    cin >> num_cidades >> num_caminhos;

    // grafo bipartido
    int grafo_bipartido = 2 * num_cidades + 1;
    Graph Grafo(grafo_bipartido);

    for (int i = 0; i < num_caminhos; i++) {
        int saida, chegada, tamanho_estrada;
        cin >> saida >> chegada >> tamanho_estrada;

        if (tamanho_estrada % 2 == 0) { //detalhe do Steve de que o caminho deve ter peso par
            Grafo.adicionarAresta(saida, chegada + num_cidades, tamanho_estrada);
            Grafo.adicionarAresta(chegada + num_cidades, saida, tamanho_estrada);
            Grafo.adicionarAresta(saida + num_cidades, chegada , tamanho_estrada);
            Grafo.adicionarAresta(chegada, saida + num_cidades, tamanho_estrada);
        }
    }

    vector<int> caminhoCurto = Grafo.dijkstra(1);

    if (caminhoCurto[num_cidades] == numeric_limits<int>::max()) {
        cout << -1 << endl;
    } else {
        cout << caminhoCurto[num_cidades] << endl;
    }
    return 0;
}