#include<stdio.h>

#define TOT 8192

int main(int argc, char** argv){

    FILE *origem, *destino;
    char buffer[TOT];
    int qtd;

    if(argc != 3){
        fprintf(stderr, "Erro na chamada do sistema\n");
        fprintf(stderr, "Use %s [ARQUIVO ORIGEM] [ARQUIVO DESTINO]\n", argv[0]);
        return 1;
    }

    origem = fopen(argv[1], "rb");
    if(!origem){
        fprintf(stderr, "Erro ao abrir arquivo %s para leitura\n", argv[1]);
        return 1;
    }

    destino = fopen(argv[2], "wb");
    if(!destino){
        fclose(origem);
        fprintf(stderr, "Erro ao abrir arquivo %s para escrita\n", argv[2]);
        return 1;
    }

    qtd = fread(buffer, sizeof(char), TOT, origem);
    while (qtd > 0){
        fwrite(buffer, 1, qtd, destino);
        qtd = fread(buffer, 1, TOT, origem);
    }
    
    fclose(origem);
    fclose(destino);
    return 0;
}