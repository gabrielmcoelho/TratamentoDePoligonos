#include "poligono.h"
#include <cmath>
#include <iostream>

using namespace std;

Poligono::Poligono()
{

}

void Poligono::adcVertice(float x, float y)
{
    vertices[n].setXY(x, y);
    n++;
}

bool Poligono::verifPoligono()
{
    Ponto origem, t, u;
    float x;

    for(int i=1;i<=n;i++)
    {
        if(i<n-1)
        {
            origem.setXY(vertices[i].getX(), vertices[i].getY());
            u=vertices[i-1].sub(origem);
            t=vertices[i+1].sub(origem);
        }
        else
        {
            if(i==n-1)
            {
                origem.setXY(vertices[i].getX(), vertices[i].getY());
                u=vertices[i-1].sub(origem);
                t=vertices[0].sub(origem);
            }
            else
            {
                origem.setXY(vertices[0].getX(), vertices[0].getY());
                u=vertices[n-1].sub(origem);
                t=vertices[1].sub(origem);
            }
        }

        //Diferença de angulo entre dois vetore: /http://stackoverflow.com/questions/21483999/using-atan2-to-find-angle-between-two-vectors
        x=atan2(u.getY(), u.getX()) - atan2(t.getY(), t.getX());

        //transformando angulos para o intervalo de 0 a 2pi
        if(x < 0)
        {
            x += 2*M_PI;
        }

        //Se o angulo interno for maior que 180 graus
        if(x-M_PI>0.001)
        {
            return false;
        }
    }
    return true;
}

int Poligono::nVertices()
{
    return(n);
}

float Poligono::areaPoligono()
{
    //http://pt.wikihow.com/Calcular-a-%C3%81rea-de-um-Pol%C3%ADgono
    float xy=0, yx=0, s;
    for(int i=0;i<n;i++)
    {
        if(i!=n-1)
        {
            xy+=vertices[i].getX()*vertices[i+1].getY();
            yx+=vertices[i].getY()*vertices[i+1].getX();
        }
        else
        {
            xy+=vertices[i].getX()*vertices[0].getY();
            yx+=vertices[i].getY()*vertices[0].getX();
        }
    }

    if(xy>yx)
    {
        s=abs((xy-yx)/2);
    }
    else
    {
        s=abs((yx-xy)/2);
    }
    return(s);
}

void Poligono::translada(float a, float b)
{
    for(int i=0;i<n;i++)
    {
        vertices[i].translada(a, b);
    }
}

//rotaciona em torno de um vertice
void Poligono::rotaciona(float x_origem, float y_origem, float theta)
{
    float ang;
    Ponto origem, p;
    origem.setXY(x_origem, y_origem);
    theta*=(M_PI/180);   //trasformando o angulo de graus p/ rad
    for(int i=0;i<n;i++)
    {
        if(vertices[i].getX()!=x_origem||vertices[i].getY()!=y_origem)
        {
            p=vertices[i].sub(origem);
            ang=atan2(p.getY(), p.getX()); //atan2 descobre o angulo em qualquer quadrante, atan não
            ang+=theta;
            vertices[i].setX(p.norma()*cos(ang) + x_origem);
            vertices[i].setY(p.norma()*sin(ang) + y_origem);
        }
    }
}

void Poligono::imprime()
{
    for(int i=0;i<n;i++)
    {
        vertices[i].imprime();
        if(i!=n-1)
            cout << " -> ";
    }
    cout << endl << endl;
}

void Poligono::resetPoligono()
{
    n=0;
}
