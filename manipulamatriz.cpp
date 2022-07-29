#include "encontraretangulos.cpp"

using namespace std;

void preenchematriz(string *matriz, int altura_matriz)
{
    int i = 0;

    for (i = 0; i < altura_matriz; i++)
    {
        cin >> matriz[i];
    }
}

bool comparamesa(dimensoes mesaA,dimensoes mesaB)
{
    if((mesaA.comprimento*mesaA.largura)>(mesaB.comprimento*mesaB.largura))
    {
        return 1;
    }
    else if(((mesaA.comprimento*mesaA.largura)==(mesaB.comprimento*mesaB.largura))&&(mesaA.largura>mesaB.largura))
    {
        return 1;
    }
    else 
        return 0;

}

void mesas(int pesquisas, dimensoes *mesa)
{
    int i = 0;

    while (i < pesquisas)
    {

        cin >> mesa[i].comprimento >> mesa[i].largura;

        i++;
    }

    sort(mesa,mesa+pesquisas,comparamesa);
}

void transforma_matriz(string *matriz, int **matriz_numeros, int altura_matriz, int largura_matriz)
{
    for (int i = 0; i < altura_matriz; i++)
    {
        for (int j = 0; j < largura_matriz; j++)
        {
            if (matriz[i][j] == '.')
            {
                matriz_numeros[i][j] = 1;
            }
            if (matriz[i][j] == '#')
            {
                matriz_numeros[i][j] = 0;
            }
        }
    }
}