//ex2-aula2

#include<stdio.h>
#define TOT 256

int main(int argc, char** argv){

    FILE *file;
    int k, freq[TOT]; //cont é contador e arr é array de contadores

    if(argc != 2){
        fprintf(stderr, "Erro na chamada do sistema\n");
        fprintf(stderr, "Use %s [ARQUIVO DE LEITURA]\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "rb");

    if(!file){
        fprintf(stderr, "Erro ao abrir arquivo %s", argv[1]);
        return 1;
    }

    for(int i = 0; i < TOT; i++){
            freq[i] = 0;
    } 

    k = fgetc(file);

    while (k != EOF){
        freq[k]++;
        k = fgetc(file);
    }
    
    for(int i = 0; i < TOT; i++){        
        fprintf(stdout, "Simbolo: %c \tASCII(dec): %d \tcontagem: %d\n", i, i, freq[i]);
    }

    fclose(file);
    return 0;
}