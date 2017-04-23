#ifndef RETANGULO_H
#define RETANGULO_H
#include "poligono.h"

class Retangulo : public Poligono
{
public:
    Retangulo();
    ~Retangulo();
    Retangulo(float x, float y, float largura, float altura);
    void operator()(float x, float y, float largura, float altura);
};

#endif // RETANGULO_H
