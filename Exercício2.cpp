#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;

bool isPalindromo(const string& mensagem) {
  
    string mensagemSemEspacos = mensagem;
    mensagemSemEspacos.erase(remove_if(mensagemSemEspacos.begin(), mensagemSemEspacos.end(), ::isspace), mensagemSemEspacos.end());

    string reverso = mensagemSemEspacos;
    reverse(reverso.begin(), reverso.end());

    return mensagemSemEspacos == reverso;
}

int main() {
    string mensagem;

    cout << "Digite uma mensagem: ";
    getline(cin, mensagem);

    if (isPalindromo(mensagem)) {
        cout << "A mensagem é um palíndromo." << endl;
    } else {
        cout << "A mensagem não é um palíndromo." << endl;
    }

    return 0;
}
