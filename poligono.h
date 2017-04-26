#ifndef POLIGONO_H
#define POLIGONO_H
#include "ponto.h"
#define TAM 100

/** @brief A classe Poligono serve para a declaração e manipulação de polígonos, bem como para a obtenção de suas informações
*
* A classe Polígono providencia o armazenamento de até 100 pontos para a declaração de polígonos. Ela possibilita adicionar seus vértices,
* verificar se formam um polígono convexo e exibi-los. Também, há métodos para a obtenção da área, número de vértices do polígono e para
* manipulá-los por meio de funções para sua rotação e translação.
*/
class Poligono
{
protected:
    Ponto vertices[TAM];
    int n=0;
public:
    /** @brief Poligono é o construtor padrão da classe Polígono
    */
    Poligono();
    /** @brief Adiciona um vértice ao polígono
    * @param x Coordenada x do vértice a ser adicionado
    * @param y Coordenada y do vértice a ser adicionado
    */
    void adcVertice(float x, float y);
    /** @brief Serve para verificar se o polígono é convexo
    */
    bool verifPoligono(void);
    /** @brief Recupera o número de vértices do polígono
    *   @return Número de vértices do polígono
    */
    int nVertices(void);
    /** @brief Calcula a área do polígono
    *   @return Área do polígono
    */
    float areaPoligono(void);
    /** @brief Translada o polígono para uma nova posição
    *   @param a Distância que o poligono irá se mover no eixo x
    *   @param b Distância que o poligono irá se mover no eixo y
    */
    void translada(float a, float b);
    /** @brief Rotaciona o polígono em torno de um ponto
    *   @param x_origem Coordenada x do eixo de rotação do polígono
    *   @param y_origem Coordenada y do eixo de rotação do polígono
    *   @param theta Ângulo, em graus, que o polígono irá rotacionar
    */
    void rotaciona(float x_origem, float y_origem, float theta);
    /** @brief Exibe os pontos que formam os vértices do polígono
    */
    void imprime(void);
    /** @brief Apaga o polígono
    */
    void resetPoligono(void);
};

#endif // POLIGONO_H
