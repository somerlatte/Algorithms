#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct Par {
    string pessoa;
    string vaga;
};

bool findMatching(const string& pessoa, unordered_map<string, vector<string>>& grafo, unordered_map<string, string>& matching, unordered_set<string>& visitado);

// Algoritmo guloso para encontrar um emparelhamento máximo
int greedyAlgorithm(const vector<Par>& qualificacao) {
    unordered_set<string> pessoas;
    unordered_set<string> vagas;

    // Coleta todas as pessoas e vagas
    for (const Par& par : qualificacao) {
        pessoas.insert(par.pessoa);
        vagas.insert(par.vaga);
    }

    unordered_set<string> vagasAtribuidas;
    int maxPares = 0;

    // Percorre cada pessoa e atribui a primeira vaga disponível para ela
    for (const string& pessoa : pessoas) {
        for (const Par& par : qualificacao) {
            if (par.pessoa == pessoa && vagasAtribuidas.count(par.vaga) == 0) {
                vagasAtribuidas.insert(par.vaga);
                maxPares++;
                break;
            }
        }
    }

    return maxPares;
}

// Algoritmo exato usando o algoritmo de Hopcroft-Karp para encontrar um emparelhamento máximo
int exactAlgorithm(const vector<Par>& qualificacao) {
    unordered_map<string, vector<string>> grafo;

    // Constrói um grafo bipartido conectando pessoas qualificadas às vagas
    for (const Par& par : qualificacao) {
        grafo[par.pessoa].push_back(par.vaga);
    }

    unordered_map<string, string> matching;
    unordered_set<string> visitado;

    int emparelhamentosMaximos = 0;

    for (const auto& no : grafo) {
        visitado.clear();


        if (matching.count(no.first) == 0 && findMatching(no.first, grafo, matching, visitado)) {
            emparelhamentosMaximos++;
        }
    }

    return emparelhamentosMaximos;
}


// Função recursiva para encontrar um emparelhamento
bool findMatching(const string& pessoa, unordered_map<string, vector<string>>& grafo, unordered_map<string, string>& matching, unordered_set<string>& visitado) {
    if (visitado.count(pessoa)) {
        return false;
    }

    visitado.insert(pessoa);

    // Percorre todas as vagas associadas à pessoa
    for (const string& vaga : grafo[pessoa]) {
        if (matching.count(vaga) == 0 || findMatching(matching[vaga], grafo, matching, visitado)) {
            matching[vaga] = pessoa;
            return true;
        }
    }

    return false;
}

int main() {
    int num_pessoas, num_vagas, quali;
    cin >> num_pessoas >> num_vagas >> quali;

    vector<Par> qualificacao;

    // Lê as qualificações das pessoas e vagas
    for (int i = 0; i < quali; i++) {
        string pessoa, vaga;
        cin >> pessoa >> vaga;
        qualificacao.push_back({pessoa, vaga});
    }

    // Executa o algoritmo guloso 
    int greedyResult = greedyAlgorithm(qualificacao);

    // Executa o algoritmo exato 
    int exactResult = exactAlgorithm(qualificacao);

    // Resultados
    cout << "Guloso: " << greedyResult << endl;
    cout << "Exato: " << exactResult << endl;

    return 0;
}
