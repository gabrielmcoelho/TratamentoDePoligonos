#ifndef PONTO_H
#define PONTO_H

class Ponto
{
private:
    float x, y;
public:
    Ponto();
    ~Ponto();
    void setX(float mx);
    void setY(float my);
    void setXY(float mx, float my);
    float getX(void);
    float getY(void);
    Ponto add(Ponto p2);
    Ponto sub(Ponto p2);
    float norma(void);
    void translada(float a, float b);
    void imprime(void);
};

#endif // PONTO_H
