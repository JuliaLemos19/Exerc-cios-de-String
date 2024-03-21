#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string transformarParaCitacao(const string& nome) {
    
    stringstream ss(nome);
    vector<string> partes;
    string parte;
    while (ss >> parte) {
        partes.push_back(parte);
    }

    string citacao;
    if (!partes.empty()) {
        
        citacao = partes.back();
        transform(citacao.begin(), citacao.end(), citacao.begin(), ::toupper);
        citacao += ", ";
        for (size_t i = 0; i < partes.size() - 1; ++i) {
            if (i > 0) {
                citacao += " ";
            }
            citacao += toupper(partes[i][0]);
            citacao += ". ";
        }
        citacao.pop_back();
        citacao += ".";
    }
    return citacao;
}

int main() {
    ifstream arquivoEntrada("nomes.txt");
    ofstream arquivoSaida("nomes_citacao.txt");

    if (!arquivoEntrada.is_open()) {
        cout << "Erro ao abrir o arquivo de entrada." << endl;
        return 1;
    }

    if (!arquivoSaida.is_open()) {
        cout << "Erro ao abrir o arquivo de saída." << endl;
        return 1;
    }

    string nome;
    while (getline(arquivoEntrada, nome)) {
        string nomeCitacao = transformarParaCitacao(nome);
        arquivoSaida << nomeCitacao << endl;
    }

    arquivoEntrada.close();
    arquivoSaida.close();

    cout << "Nomes transformados com sucesso." << endl;

    return 0;
}
