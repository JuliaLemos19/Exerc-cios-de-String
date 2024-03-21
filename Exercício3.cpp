#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


string transformarParaAgenda(const string& nome) {
    
    size_t lastSpace = nome.find_last_of(" ");
    if (lastSpace == string::npos) {
      
        return nome;
    }
  
    string ultimoSobrenome = nome.substr(lastSpace + 1);
    
    string nomesRestantes = nome.substr(0, lastSpace);
    
    return ultimoSobrenome + ", " + nomesRestantes;
}

int main() {
    ifstream arquivoEntrada("nomes.txt");
    ofstream arquivoSaida("nomes_agenda.txt");

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
        
        string nomeAgenda = transformarParaAgenda(nome);
        
        arquivoSaida << nomeAgenda << endl;
    }

    arquivoEntrada.close();
    arquivoSaida.close();

    cout << "Nomes transformados com sucesso." << endl;

    return 0;
}
