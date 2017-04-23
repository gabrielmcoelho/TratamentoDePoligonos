#ifndef POLIGONO_H
#define POLIGONO_H
#include "ponto.h"

class Poligono
{
protected:
    Ponto v[100];
    int n=0;
public:
    Poligono();
    ~Poligono();
    void adcVertice (float vx, float vy);
    int getN (void);
    void resetPoligono (void);
    float calcArea (void);
    void translada (float a, float b);
    void rotaciona(float ang, float x_origem, float y_origem);
    bool verifPoligono(void);
    void imprime(void);
};

#endif // POLIGONO_H
