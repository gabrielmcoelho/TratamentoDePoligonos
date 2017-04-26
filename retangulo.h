#ifndef RETANGULO_H
#define RETANGULO_H
#include "poligono.h"

/** @brief A classe Retangulo serve para a declaração de retângulos
*/
class Retangulo : public Poligono
{
public:
    /** @brief Construtor padrão da classe Retangulo
    */
    Retangulo();
    /** @brief Construtor com argumentos da classe Retangulo
    * @param x Coordenada x do ponto superior esquerdo do retângulo a ser declarado
    * @param y Coordenada y do ponto superior esquerdo do retângulo a ser declarado
    * @param largura Largura do retângulo a ser declarado
    * @param altura Altura do retângulo a ser declarado
    */
    Retangulo(float x, float y, float largura, float altura);

    /** @brief operator() serve para declarar os atributos de um retângulo
    * @param x Coordenada x do ponto superior esquerdo do retângulo a ser declarado
    * @param y Coordenada y do ponto superior esquerdo do retângulo a ser declarado
    * @param largura Largura do retângulo a ser declarado
    * @param altura Altura do retângulo a ser declarado
    */
    void operator()(float x, float y, float largura, float altura);
};

#endif // RETANGULO_H
