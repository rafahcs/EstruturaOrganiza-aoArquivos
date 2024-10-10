#include<stdio.h>
//teste de fwrite
//fread(<nome_memória>, <sizeof(tipo_memória)>, <quantos_dados>, <arquivo_origem>);
//fwrite(<nome_memória>, <sizeof(tipo_memória)>, <quantos_dados>, <arquivo_destino>);

int main(int argc, char** argv){

    FILE *entrada, *saida;
    int qtd;

    struct Carro{
        char nome[10];
        int ano;
        float preco;
    };

    struct Carro uno[100];

    qtd = fread(uno, sizeof(struct Carro), 100, entrada);

    fwrite(uno, sizeof(struct Carro), qtd, saida);

    /*int v[1000]
    fwrite(v, sizeof(v), 1000, saida)*/
    return 0;
}

