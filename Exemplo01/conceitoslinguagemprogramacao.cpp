#include <iostream>
#include <new>

#include "conceitoslinguagemprogramacao.h"

conceitosLinguagemProgramacao::conceitosLinguagemProgramacao()
{
    i = 0;
    j = 0;
    c = 0;
    result = 0;
}

int conceitosLinguagemProgramacao::setVetor( int nElementos )
{
    int *vTemp;
    result = 0;

    vTemp = new (std::nothrow) int[nElementos];

    if ( vTemp == 0 )
    {
        std::cout << "Error: memory could not be allocated" << std::endl;

        return -1;
    }
    else
    {
        for ( i = 0; i < nElementos; i++ )
            vTemp[i] = i;

        for ( i = 0; i < nElementos; i++ )
            result += vTemp[i];

        delete []vTemp;

        return result;
    }
}

int conceitosLinguagemProgramacao::setPonteiro( int nElementos )
{
    int *vTemp;
    int *vTempPtr;

    result = 0;

    vTemp = new int[nElementos];
    vTempPtr = new int[nElementos];
    vTempPtr = &vTemp[0];

    if ( vTemp == 0 )
    {
        std::cout << "Error: memory could not be allocated" << std::endl;

        return -1;
    }
    else
    {
        for ( i = 0; i < nElementos; i++ )
            *vTempPtr++ = i;

        vTempPtr = &vTemp[0];
        for ( i = 0; i < nElementos; i++ )
            result += *vTempPtr++;

        delete []vTemp;

        return result;
    }
}

int conceitosLinguagemProgramacao::setMatriz( int nLinhas, int nColunas )
{
    int **vTemp;
    result = 0;
    c = 0;

    vTemp = new int*[nLinhas];
    if ( vTemp == 0 )
    {
        std::cout << "Error: memory could not be allocated" << std::endl;

        return -1;
    }
    else
    {
        for ( i = 0; i < nLinhas; i++ )
            vTemp[i] = new int[nColunas];

        for ( i = 0; i < nLinhas; i++ )
            for ( j = 0; j < nColunas; j++ )
                vTemp[i][j] = c++;

        for ( i = 0; i < nLinhas; i++ )
            for ( j = 0; j < nColunas; j++ )
                result += vTemp[i][j];

        for ( i = 0; i < nLinhas; i++ )
            delete []vTemp[i];

        delete []vTemp;

        return result;
    }
}

int conceitosLinguagemProgramacao::setMatrizErr( int nLinhas, int nColunas )
{
    int **vTemp;
    result = 0;
    c = 0;

    vTemp = new int*[nLinhas];
    if ( vTemp == 0 )
    {
        std::cout << "Error: memory could not be allocated" << std::endl;

        return -1;
    }
    else
    {
        for ( i = 0; i < nLinhas; i++ )
            vTemp[i] = new int[nColunas];

        for ( i = 0; i < nLinhas; i++ )
            for ( j = 0; j < nColunas; j++ )
                vTemp[i][j] = c++;

        for ( j = 0; j < nColunas; j++ )
            for ( i = 0; i < nLinhas; i++ )
                result += vTemp[i][j];

        for ( i = 0; i < nLinhas; i++ )
            delete []vTemp[i];

        delete []vTemp;

        return result;
    }
}
