#include<stdio.h>

//cabeçalho da main

int main(int argc, char** argv){

    for(int i = 0; i < argc; i++){
        printf("São %d arquivos assim: %s", i, argv[i]);
    }
    return 0;
}