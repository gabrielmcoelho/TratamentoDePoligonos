#ifndef PONTO_H
#define PONTO_H

/** @brief A classe Ponto serve para a declaração e manipulação de pontos no plano cartesiano
* bem como para a obtenção de algumas de suas informações
*
* A classe Ponto providencia a declaração, obtenção e exibição das coordenadas x e y de cada ponto. Também permite
* fazer adição e subtração com outros pontos, deslocá-los e obter a distância entre o ponto e a origem do eixo de
* coordenadas
*/
class Ponto
{
private:
    float x;
    float y;
public:
    /** @brief Construtor padrão da classe Ponto
    */
    Ponto();
    /** @brief Atribui valores à coordenada x do ponto
    *   @param x1 Valor que será atribuído à coordenada x do ponto
    */
    void setX(float x1);
    /** @brief Atribui valores à coordenada y do ponto
    *   @param y1 Valor que será atribuído à coordenada y do ponto
    */
    void setY(float y1);
    /** @brief Atribui valores às coordenadas x e y do ponto simultaneamente
    *   @param x1 Valor que será atribuído à coordenada x do ponto
    *   @param y1 Valor que será atribuído à coordenada y do ponto
    */
    void setXY(float x1, float y1);
    /** @brief Recupera o valor da coordenada x do ponto
    *   @return Coordenada x do ponto
    */
    float getX(void);
    /** @brief Recupera o valor da coordenada y do ponto
    *   @return Coordenada y do ponto
    */
    float getY(void);
    /** @brief Executa a adição das coordenadas de dois pontos
    *   @param p1 Ponto contendo as coordenadas que irão somar-se aos estados da classe
    *   @return Ponto resultante da adição
    */
    Ponto soma(Ponto p1);
    /** @brief Executa a subtração de pontos
    *   @param p1 Ponto contendo as coordenadas que irão subtrair-se aos estados da classe
    *   @return Ponto resultante da subtração
    */
    Ponto sub(Ponto p1);
    /** @brief Informa a distância entre o ponto e a origem do eixo de coordenadas
    *   @return Distância do ponto até a origem
    */
    float norma(void);
    /** @brief Desloca o ponto para uma nova posição no plano cartesiano
        @param a Valor que será somado à coordenada x do ponto
        @param b Valor que será somado à coordenada y do ponto
    */
    void translada(float a, float b);
    /** @brief Exibe as coordenadas x e y do ponto no formato <i>(x, y)</i>
    */
    void imprime(void);
};

#endif // PONTO_H
