#include "retangulo.h"

Retangulo::Retangulo()
{

}

Retangulo::Retangulo (float x, float y, float largura, float altura)
{
    adcVertice(x, y-altura);
    adcVertice(x+largura, y-altura);
    adcVertice(x+largura, y);
    adcVertice(x, y);
}

void Retangulo::operator()(float x, float y, float largura, float altura)
{
    adcVertice(x, y-altura);
    adcVertice(x+largura, y-altura);
    adcVertice(x+largura, y);
    adcVertice(x, y);
}
