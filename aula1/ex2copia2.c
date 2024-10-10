#include<stdio.h>

#define TAM 256

int main(int argc, char** argv){

    FILE *file;
    int cont = 0, x;
    char mem[TAM], arr[TAM];

    if(argc != 2){
        fprintf(stderr, "Erro na chamada do sistema.\n");
        fprintf(stderr, "Use %s [NOME_ARQUIVO]\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "rb");
    if(!file){
        fprintf(stderr, "Erro ao abrir arquivo %s para leitura.\n", argv[1]);
        return 1;
    }

    x = fread(mem, 1, TAM, file);
    while(x > 0){
        if(mem[cont] == cont){
            arr[cont]++;
            cont++;
        }
        x = fread(mem, 1, TAM, file);
    }

    for (int i = 0; i < TAM; i++){
        fprintf(stdout, "Caracter: %c\tASCII(dec): %d\tFrequencia: %d\n", i, i, arr[i]);
    }
    
    fclose(file);
    return 0;
}