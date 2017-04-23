#include "poligono.h"
#include <iostream>
#include <cmath>

using namespace std;

Poligono::Poligono()
{
    // Construtor
}

Poligono::~Poligono()
{
    // Destrutor
}

void Poligono::adcVertice(float vx, float vy){
    v[n].setXY(vx, vy);
    n++;
}

int Poligono::getN(void){
    return n;
}

void Poligono::resetPoligono(void){
    n=0;
}

float Poligono::calcArea(void){
    float soma2 = 0, soma1 = 0, area;
    for(int i=0; i<n; i++){
        if(i==(n-1)){
            soma2 += v[n-1].getX()*v[0].getY();
            soma1 += v[n-1].getY()*v[0].getX();
        }
        else{
            soma2 += v[i].getX()*v[i+1].getY();
            soma1 += v[i].getY()*v[i+1].getX();
        }
    }
    if(soma2>soma1){
        area = abs((soma2 - soma1)/2);
    }
    else{
        area = abs((soma1 - soma2)/2);
    }
    return area;
}

void Poligono::translada(float a, float b)
{
    for(int i=0; i<n; i++){
        v[i].translada(a, b);
    }
}

void Poligono::rotaciona(float ang, float x_origem, float y_origem){
    Ponto origem, aux;
    float theta;
    origem.setXY(x_origem, y_origem);
    ang *= (M_PI/180);
    for(int i=0; i<n; i++){
        if(v[i].getX()!=x_origem||v[i].getY()!=y_origem){
            aux = v[i].sub(origem);
            theta = atan2(aux.getY(), aux.getX()) + ang;
            v[i].setX(aux.norma()*cos(theta) + x_origem);
            v[i].setY(aux.norma()*sin(theta) + y_origem);
        }
    }
}

void Poligono::imprime()
{
    for(int i=0; i<n; i++)
    {
        cout << "(" << v[i].getX() << "," << v[i].getY() << ") -> ";
    }
    cout << endl << endl;
}

bool Poligono::verifPoligono()
{
    Ponto origem, t, u;
    float x;
    for(int i=1;i<=n;i++) {
        if(i<n-1){
            origem.setXY(v[i].getX(), v[i].getY());
            u=v[i-1].sub(origem);
            t=v[i+1].sub(origem);
        }
        else if(i==n-1){
            origem.setXY(v[i].getX(), v[i].getY());
            u=v[i-1].sub(origem);
            t=v[0].sub(origem);
        }
        else{
            origem.setXY(v[0].getX(), v[0].getY());
            u=v[n-1].sub(origem);
            t=v[1].sub(origem);
        }
        x=atan2(u.getY(), u.getX()) - atan2(t.getY(), t.getX());
        if(x < 0){
            x += 2*M_PI;
        }
        if(x-M_PI>0.001) {
            return false;
        }
    }
    return true;
}
