#include <stdio.h>
#include <stdlib.h>
//realizar o cadastro de 5 territórios, cada território deve conter nome, cor e quantidade de tropas. Após o cadastro, exibir os dados dos territórios.
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};


int main() {
    //declaração do vetor de estruturas
    struct Territorio territorios[5];

    printf("****CADASTRE OS TERRITORIOS****\n");
    //loop para cadastrar 5 territórios
    for(int i = 0; i <= 4; i++) {
        printf("Digite o nome do territorio %d: ", i + 1);
        scanf("%s", territorios[i].nome);
        printf("Digite a cor do territorio %d: ", i + 1);
        scanf("%s", territorios[i].cor);
        printf("Digite a quantidade de tropas: ", i + 1);
        scanf("%d", &territorios[i].tropas);
    }
    //exibir os dados dos territórios cadastrados
    printf("***Territorios cadastrados***\n");
        for(int i = 0; i <= 4; i++) {
            printf("TERRITORIO %d:\n", i + 1);
            printf(" - Nome: %s\n", territorios[i].nome);
            printf(" - Cor: %s\n", territorios[i].cor);
            printf(" - Tropas: %d\n\n", territorios[i].tropas);
        }
        //finalização do programa
        return 0;
}


