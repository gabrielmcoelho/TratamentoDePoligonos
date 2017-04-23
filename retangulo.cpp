#include "retangulo.h"

Retangulo::Retangulo()
{
    // Construtor
}

Retangulo::~Retangulo()
{
    // Destrutor
}

Retangulo::Retangulo (float x, float y, float largura, float altura)
{
    this->adcVertice(x, y);
    this->adcVertice(x, y-altura);
    this->adcVertice(x+largura, y-altura);
    this->adcVertice(x+largura, y);
}

void Retangulo::operator()(float x, float y, float largura, float altura)
{
    this->adcVertice(x, y);
    this->adcVertice(x, y-altura);
    this->adcVertice(x+largura, y-altura);
    this->adcVertice(x+largura, y);
}
