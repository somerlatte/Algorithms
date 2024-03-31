#include <iostream>
#include <vector>
#include <limits>

#define INF 0x3f3f3f3f

using namespace std;

vector<int> ligas;

int minLigas(int demanda) {
    vector<int> demanda_max(demanda + 1, INF); // Vetor para armazenar a demanda máxima com o menor número de ligas
    demanda_max[0] = 0;

    for (int i = 1; i <= demanda; i++) {
        for (size_t j = 0; j < ligas.size(); j++) {
            if (ligas[j] <= i && demanda_max[i - ligas[j]] < INF) {
                demanda_max[i] = min(demanda_max[i], demanda_max[i - ligas[j]] + 1); // Atualiza o número mínimo de ligas necessário
            }
        }
    }

    return demanda_max[demanda];
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, W;
        cin >> N >> W;

        ligas.resize(N); // Redimensiona o vetor ligas para o tamanho N

        for (int i = 0; i < N; i++) {
            cin >> ligas[i];
        }

        int resultado = minLigas(W);
        cout << resultado << endl;
    }

    return 0;
}
