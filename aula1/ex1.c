//ex1-aula1
#include<stdio.h>

int main(int argc, char** argv){
    FILE *arq;
    int cont = 0, c;

    if(argc != 2){
        fprintf(stderr, "Erro na chamada do sistema");
        fprintf(stderr, "Use %s [ARQUIVO LEITURA]", argv[0]);
        return 1;
    }

    arq = fopen(argv[1], "rb");

    if(!arq){
        fprintf(stderr, "Erro ao abrir arquivo %s", argv[1]);
        return 1;
    }
    
    c = fgetc(arq);

    while(c != EOF){
        if(c == 10){
            cont++;
        }
        c = fgetc(arq);
    }

    fprintf(stdout, "Quantidade de linhas= %d", cont);

    fclose(arq);
    return 0;
}