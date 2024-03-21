#include <iostream>
#include <string>
#include <cstdlib> 

using namespace std;

int main() {
    string mensagem;
    cout << "Digite uma mensagem: ";
    getline(cin, mensagem);
    
    system("clear");

    int espacosAntes = (80 - mensagem.length()) / 2;

    for (int i = 0; i < espacosAntes; ++i) {
        cout << " ";
    }
    cout << mensagem << endl;

    for (int linha = 6; linha <= 20; ++linha) {
        system("clear");

        for (int i = 0; i < espacosAntes; ++i) {
            cout << " ";
        }
        for (int i = 0; i < mensagem.length(); ++i) {
            if (linha >= i + 5) {
                cout << mensagem[i];
            } else {
                cout << " ";
            }
        }
        cout << endl;

    return 0;
}


