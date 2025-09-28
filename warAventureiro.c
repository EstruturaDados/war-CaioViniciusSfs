#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

// Função para exibir territórios
void exibirTerritorios(struct Territorio *territorios, int qtd) {
    printf("\n*** ESTADO ATUAL DO MAPA ***\n");
    for (int i = 0; i < qtd; i++) { // loop para exibir cada território
        printf("TERRITORIO %d:", i + 1);
        printf(" %s (Exercito %s, Tropas: %d)\n", territorios[i].nome, territorios[i].cor, territorios[i].tropas);
    }
}

// Função para simular batalha entre dois territórios
void simularBatalha(struct Territorio *territorios, int atacante, int defensor) {
    if (territorios[atacante].tropas <= 0) {
        printf("O território atacante não possui tropas suficientes!\n");
        return;
    }
    if (territorios[defensor].tropas <= 0) {
        printf("O território defensor não possui tropas para defender!\n");
        return;
    }

    int dadoAtaque = (rand() % 6) + 1;  // valor entre 1 e 6
    int dadoDefesa = (rand() % 6) + 1;

    printf("\n DADO DE ATAQUE: %d", dadoAtaque);
    printf("\n  DADO DE DEFESA: %d\n", dadoDefesa);

    if (dadoAtaque >= dadoDefesa) {
        printf(" O atacante venceu! O defensor perde 1 tropa.\n");
        territorios[defensor].tropas--;

        if (territorios[defensor].tropas <= 0) {// defensor perde todas as tropas
            printf(" Território %s foi conquistado por %s!\n",
                   territorios[defensor].nome,
                   territorios[atacante].nome);
            territorios[defensor].tropas = 1; // transfere 1 tropa do atacante
            territorios[atacante].tropas--;
        }
    } else {
        printf(" O defensor venceu! O atacante perde 1 tropa.\n");
        territorios[atacante].tropas--;
    }
}

int main() {
    int qtdTerritorios = 5;
    struct Territorio *territorios;

    // alocação dinâmica com calloc
    territorios = (struct Territorio *)calloc(qtdTerritorios, sizeof(struct Territorio));
    if (territorios == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    srand(time(NULL)); // inicializa gerador de números aleatórios

    printf("**** CADASTRE OS TERRITORIOS ****\n");
    for (int i = 0; i < qtdTerritorios; i++) {
        printf("Digite o nome do territorio %d: ", i + 1);
        scanf("%s", territorios[i].nome);
        printf("Digite a cor do territorio %d: ", i + 1);
        scanf("%s", territorios[i].cor);
        printf("Digite a quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);
    }

    int opcao, atacante, defensor;
    do {// loop principal do jogo
        exibirTerritorios(territorios, qtdTerritorios);
        printf("\nEscolha o territorio ATACANTE (1 a 5) ou 0 para sair: ");
        scanf("%d", &atacante);
        if (atacante == 0) break;
        
        printf("Escolha o territorio DEFENSOR (1 a 5): ");
        scanf("%d", &defensor);

        if (atacante < 1 || atacante > qtdTerritorios ||
            defensor < 1 || defensor > qtdTerritorios ||
            atacante == defensor) {
            printf(" Escolha inválida! Tente novamente.\n");
            continue;
        }

        simularBatalha(territorios, atacante - 1, defensor - 1);// ajusta índices para 0

    } while (1);

    free(territorios);
    printf("\nJogo encerrado. Obrigado por jogar!\n");

    return 0;
}