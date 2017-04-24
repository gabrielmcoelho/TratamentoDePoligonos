#include <iostream>
#include <cstdlib>
#include "poligono.h"
#include "retangulo.h"

using namespace std;

Poligono polig;
Retangulo ret;

int Menu1();
int Menu2();
bool CriarPol();
void CriarRet();

int main()
{
    int opcao;
    float a, b, ang, x_origem, y_origem;
    bool PolCriado = false, RetCriado = false;
    while(PolCriado==false && RetCriado==false){
        opcao = Menu1();
        switch(opcao){
        case 1:
            PolCriado = CriarPol();
            break;
        case 2:
            CriarRet();
            RetCriado = true;
            break;
        default:
            cout << "Ate logo o/" << endl;
            return(0);
        }
    }
    while(true){
        opcao = Menu2();
        switch (opcao) {
        case 1:
            if(RetCriado)
                cout << "Seu retangulo possui " << ret.getN() << " vertices" << endl;
            else
                cout << "Seu poligono possui " << polig.getN() << " vertices" << endl;
            break;
        case 2:
            if(RetCriado)
                cout << "A area do seu retangulo eh " << ret.calcArea() << " u.a" << endl;
            else
                cout << "A area do seu poligno eh " << polig.calcArea() << " u.a" << endl;
            break;
        case 3:
            cout << "Digite os valores de a e b: ";
            cin >> a >> b;
            if(RetCriado){
                ret.translada(a, b);
                cout << "Retangulo transladado em (" << a << "," << b << ") com sucesso!" << endl;
            }
            else{
                polig.translada(a, b);
                cout << "Poligono transladado em (" << a << "," << b << ") com sucesso!" << endl;
            }
            break;
        case 4:
            cout << "Digite o angulo (entre 0 e 360 graus) a ser rotacionado: ";
            cin >> ang;
            while(ang<=0||ang>=360){
                cout << "Valor invalido, digite novamente: ";
                cin >> ang;
            }
            cout << "Digite a coordenada x do ponto tomado como base: ";
            cin >> x_origem;
            cout << "Digite a coordenada y do ponto tomado como base: ";
            cin >> y_origem;
            if(RetCriado){
                ret.rotaciona(ang, x_origem, y_origem);
                cout << "Retangulo rotacionado em " << ang << " graus em torno do ponto (" << x_origem << "," << y_origem << ") com sucesso!";
            }
            else{
                polig.rotaciona(ang, x_origem, y_origem);
                cout << "Poligono rotacionado em " << ang << " graus em torno do ponto (" << x_origem << "," << y_origem << ") com sucesso!";
            }
            break;
        case 5:
            if(RetCriado)
                ret.imprime();
            else
                polig.imprime();
            break;
        default:
            cout << "Ate logo o/" << endl;
            return(0);
        }
    }
    return 0;
}

int Menu1(){
    int opcao;
    cout << endl << endl;
    system("Pause");
    system("cls");
    cout << "Bem-vindo ao tratamento de poligonos!" << endl << endl
         << "1 - Criar poligono" << endl
         << "2 - Criar retângulo" << endl
         << "3 - Sair" << endl << endl
         << "O que deseja fazer?" << endl
         << "Digite aqui: ";
    cin >> opcao;
    while(opcao<1||opcao>3){
        cout << "Valor invalido, digite novamente: ";
        cin >> opcao;
    }
    cout << endl << endl;
    system("pause");
    system("cls");
    return opcao;
}

int Menu2(){
    int opcao;
    cout << endl << endl;
    system("Pause");
    system("cls");
    cout << "O que deseja fazer com o seu poligono?" << endl << endl
         << "1 - Recuperar a quantidade de vertices do poligono" << endl
         << "2 - Calcular a area do poligono" << endl
         << "3 - Transladar o poligono" << endl
         << "4 - Rotacionar o poligono" << endl
         << "5 - Imprimir o poligono" << endl
         << "6 - Sair" << endl << endl;
    cout << "Digite aqui: ";
    cin >> opcao;
    while(opcao<1||opcao>6){
        cout << "Valor invalido, digite novamente: ";
        cin >> opcao;
    }
    cout << endl << endl;
    system("pause");
    system("cls");
    return opcao;
}

bool CriarPol(){
    int i=2;
    float vxi, vyi, vx, vy;
    polig.resetPoligono();
    cout << "=OBSERVACOES=" << endl
         << "Insira os vertices do poligono no sentido anti-horario" << endl
         << "Insira o vertice inicial novamente quando quiser finalizar o processo" << endl
         << "O poligono deve ter no minimo 3 e no maximo 100 vertices e deve ser convexo!" << endl << endl;
    cout << "Insira a coordenada x do vertice inicial: ";
    cin >> vxi;
    cout << "Insira a coordenada y do vertice inicial: ";
    cin >> vyi;
    polig.adcVertice(vxi, vyi);
    while(i<=100){
        cout << endl << "~Vertice " << i << "~" << endl;
        cout << "Insira a coordenada x do vertice: ";
        cin >> vx;
        cout << "Insira a coordenada y do vertice: ";
        cin >> vy;
        if(vx==vxi && vy==vyi){
            break;
        }
        polig.adcVertice(vx, vy);
        i++;
    }
    if(!polig.verifPoligono()||i<4)
    {
        cout << endl << "Poligono invalido, a operacao sera cancelada!";
        return false;
    }
    else{
        cout << endl << "Poligono criado com sucesso!";
        return true;
    }
}

void CriarRet(){
    float altura, largura, vx, vy;
    polig.resetPoligono();
    cout << "Digite o vertice superior esquerdo do retangulo: " << endl;
    cout << "coordenada x do vertice: ";
    cin >> vx;
    cout << "coordenada y do vertice: ";
    cin >> vy;
    cout << "Digite a altura e a largura do retangulo: " << endl;
    cout << "Altura: ";
    cin >> altura;
    cout << "Largura: ";
    cin >> largura;
    ret(vx, vy, largura, altura);
    return;
}
