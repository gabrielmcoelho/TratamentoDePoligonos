#include "ponto.h"
#include <iostream>
#include <cmath>

using namespace std;

Ponto::Ponto()
{

}

Ponto Ponto::soma(Ponto p1)
{
    Ponto p2;
    p2.x=x+p1.x;
    p2.y=y+p1.y;
    return(p2);
}

Ponto Ponto::sub(Ponto p1)
{
    Ponto p2;
    p2.x=x-p1.x;
    p2.y=y-p1.y;
    return(p2);
}

void Ponto::imprime(void)
{
    cout << "(" << x << ", " << y << ")";
}

float Ponto::getX(void)
{
    return x;
}

void Ponto::setX(float x1)
{
    x=x1;
}

float Ponto::getY(void)
{
    return y;
}

void Ponto::setY(float y1)
{
    y=y1;
}

void Ponto::setXY(float x1, float y1)
{
    x=x1;
    y=y1;
}

float Ponto::norma()
{
    float t;
    t=sqrt(pow(x, 2)+pow(y, 2));
    return(t);
}

void Ponto::translada(float a, float b)
{
    x+=a;
    y+=b;
}
