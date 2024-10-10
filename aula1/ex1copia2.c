#include<stdio.h>
#define TOT 1024

int main(int argc, char** argv){

    FILE *file;
    char arr[TOT];
    int qtd , cont = 0;

    if(argc != 2){
        fprintf(stderr, "Erro na chamada do sistema\n");
        fprintf(stderr, "Use %s [NOME_ARQUIVO]\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "rb");
    if(!file){
        fprintf(stderr, "Erro ao abrir arquivo %s para leitura\n", argv[1]);
        return 1;
    }

    qtd = fread(arr, sizeof(char), TOT, file);
    while(qtd > 0){
        for(int i = 0; i < qtd; i++){
            if(arr[i] == 10){
                cont++;
            }
        }
        qtd = fread(arr, 1, TOT, file);       
    }
    
    fprintf(stdout, "Quantidade de linhas de %s: %d", argv[1], cont);
    fclose(file);
    return 0;
}