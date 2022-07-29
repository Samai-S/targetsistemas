#include <bits/stdc++.h>
#include "struct.hpp"

using namespace std;

void processalinha(int *linha, int tamanho_linha, dimensoes *mesa, int *tamanho_pesquisa, int *comprimento, int *largura)
// função resposável por processar a área para cada linha da matriz principal
// função calcula área para cada coluna baseado no índice no momento atual * o valor linha acrescido anteriormente
{
    // declaração de variáveis
    int AreaMaxima = 0, i = 0, area = 0, valorMax = 0;
    dimensoes aux;
    stack<int> valor;

    aux.comprimento = 0;
    aux.largura = 0;

    //iteração para cada elemento da linha
    for (i = 0; i < tamanho_linha;)
    {
        //se a pilha de valores indices estiver vazia ou linha na posição do topo da pilha for maior que linha[i];
        //atualiza o valor no topo da pilha;
        if (valor.empty() || linha[valor.top()] <= linha[i])
        {
            valor.push(i++);
        }

        else
        {
            //caso for menor calcule a área multiplicando o topo da pilha e o valor i e remova a posição do topo da pilha
            valorMax = linha[valor.top()];
            area = valorMax * i;
            valor.pop();
            //enquanto a pilha não estiver vazia calcule a área entre valor max (posição da linha)* soma dos valores armazenados para cada elemento
            //da linha
            if (!valor.empty())
            {
                area = valorMax * (i - valor.top() - 1);
                AreaMaxima = max(area, AreaMaxima);
            }

            // se a área nova for maior que a área antiga entre na condição
            if (comprimento[0] * largura[0] < valorMax * (i - 1 - valor.top()))
            {

                // se inicia um loop para cara elemento do vetor mesas
                for (int j = 0; j < tamanho_pesquisa[0]; j++)
                {   
                    // se mesa for menor igual ao valor max nas suas dimensoes normalmente ou rotacionada entre na condição
                    if (((mesa[j].comprimento <= valorMax) && (mesa[j].largura <= (i - 1 - valor.top()))) || ((mesa[j].comprimento <= (i - 1 - valor.top())) && (mesa[j].largura <= valorMax)))
                    {
                        //atualiza novo comprimento e nova largura
                        aux.comprimento = valorMax;
                        aux.largura = (i - 1 - valor.top());
                        //atualiza novo tamanho de pesquisa para diminuir o tamanho de iterações
                        tamanho_pesquisa[0] = j;
                        //atualiza o tamanho do comprimento
                        comprimento[0] = mesa[j].comprimento;
                        //atualiza tamanho da largura
                        largura[0] = mesa[j].largura;
                        break;
                    }
                }
            }
        }
    }
}

void processamatriz(int **matriz, int comprimento_matriz, int largura_matriz, dimensoes *mesa, int tamanhopesquisa)
// função responsável por atualizar os valores da matriz binária incrementando o valor dela baseado no anterior
// essa função soma o valor do elemento baseado no elemento anterior
{
    //declaração das variáveis 
    int indice[1];
    int comprimento[1];
    int largura[1];
    comprimento[0] = 0;
    largura[0] = 0;
    indice[0] = tamanhopesquisa;

    //for que incrementa o valor da matriz na posição i,j baseado no elemento anterior
    for (int i = 0; i < comprimento_matriz; i++)
    {
        for (int j = 0; j < largura_matriz; j++)
        {

            if (matriz[i][j])
                matriz[i][j] = matriz[i][j] + matriz[i - 1][j];
        }
        //realiza o processa linha para cada elemento da matriz
        processalinha(matriz[i], largura_matriz, mesa, indice, comprimento, largura);
        //se o elemento encontrado for o maior elemento do vetor de mesas termine o programa
        if (comprimento[0] == mesa[0].comprimento && largura[0] == mesa[0].largura)
        {
            break;
        }
    }
    cout << comprimento[0] << " " << largura[0] << endl;
}