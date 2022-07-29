#include "manipulamatriz.cpp"

using namespace std;

int main()
{
    int altura_matriz, largura_matriz, pesquisas;

    cin >> altura_matriz >> largura_matriz;

    string matriz[altura_matriz];

    preenchematriz(matriz, altura_matriz);
    cin >> pesquisas;
    dimensoes mesa[pesquisas];
    mesas(pesquisas, mesa);

    int **matriz_numeros;

    matriz_numeros = new int *[altura_matriz];

    for (int i = 0; i < altura_matriz; i++)
        matriz_numeros[i] = new int[largura_matriz];

    transforma_matriz(matriz, matriz_numeros, altura_matriz, largura_matriz);
    processamatriz(matriz_numeros, altura_matriz, largura_matriz, mesa, pesquisas);
}