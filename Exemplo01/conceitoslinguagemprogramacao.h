#ifndef CONCEITOSLINGUAGEMPROGRAMACAO_H
#define CONCEITOSLINGUAGEMPROGRAMACAO_H

class conceitosLinguagemProgramacao
{
public:
    conceitosLinguagemProgramacao();
    int setVetor( int nElementos );
    int setPonteiro( int nElementos );
    int setMatriz( int nLinhas, int nColunas );
    int setMatrizErr( int nLinhas, int nColunas );
private:
    int i;
    int j;
    int c;
    int result;
};

#endif // CONCEITOSLINGUAGEMPROGRAMACAO_H
