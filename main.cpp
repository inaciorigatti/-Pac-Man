#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <stdio.h>

using namespace std;

//Declaração das funções
void menu();
int verificador(int escolha);
int escolhaMenu(int escolha);
void apagarTela();
void sobre();

int main(){
    menu();
}

void menu(){
    cout<<"-=* PAC-MAN *=-"<<endl;
    cout<<"1. Jogar"    <<endl;
    cout<<"2. Ranking"  <<endl;
    cout<<"3. Sobre"    <<endl; //lore do jogo
    cout<<"4. Sair"     <<endl;

    int escolha;
    cin>>escolha;
    verificador(escolha);

}

int verificador(int escolha) {
    if (escolha <= 0 || escolha > 4) {
        cout << "Opcao invalida, tente novamente: " << endl;
        cin >> escolha;
        return verificador(escolha); // Chamada recursiva para corrigir a escolha
    }
    apagarTela();
    return escolhaMenu(escolha); // Chama a função escolhaMenu com a escolha válida
}

int escolhaMenu(int escolha) {
    switch (escolha) {
        case 1:
            cout<<"c";
            break;
        case 2:
            cout<<"b";
            break;
        case 3:
            sobre();
            break;
        case 4:
            cout << "Saindo do jogo..." << endl;
            //Sleep(2000);
            exit(0);
            break;
        default:
            return 0;
        }
    return escolha;
}

void apagarTela() {
    system("cls");
}

void sobre() {
    printf("\033[1;31mPac-Man, conhecido no Japao como Puckman. E um jogo iconico. O jogo foi distribuído nos Estados Unidos pela Midway Games e lançado em 22 de maio de 1980. A ideia do design peculiar do Pac-Man surgiu durante um jantar entre amigos, quando o criador viu uma pizza com uma fatia faltando, o que lhe lembrou uma boca aberta.\033[0m\n");
}


