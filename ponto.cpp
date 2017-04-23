#include "ponto.h"
#include <iostream>
#include <cmath>

using namespace std;

Ponto::Ponto()
{
    // Construtor
}

Ponto::~Ponto()
{
    // Destrutor
}

void Ponto::setX(float mx)
{
    x = mx;
}

void Ponto::setY(float my)
{
    y = my;
}

void Ponto::setXY(float mx, float my)
{
    x = mx;
    y = my;
}

float Ponto::getX(void)
{
    return x;
}

float Ponto::getY(void)
{
    return y;
}

Ponto Ponto::add(Ponto p2)
{
    Ponto p3;
    p3.x = x + p2.x;
    p3.y = y + p2.y;
    return p3;
}

Ponto Ponto::sub(Ponto p2)
{
    Ponto p3;
    p3.x = x - p2.x;
    p3.y = y - p2.y;
    return p3;
}

float Ponto::norma(void)
{
    float norma;
    norma = pow(x,2) + pow(y,2);
    norma = sqrt(norma);
    return norma;
}

void Ponto::translada(float a, float b)
{
    x = x+a;
    y = y+b;
}

void Ponto::imprime(void)
{
    cout << "(" << x << "," << y << ")";
}
