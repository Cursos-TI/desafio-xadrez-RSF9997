#include <stdio.h>

// Movimento recursivo da Torre:
void movertorre(int casas){
    if (casas > 0) {
        printf("Direita\n");
        movertorre(casas - 1);
    }
}

// Movimento recursivo da Rainha:
void moverrainha(int casas){
    if (casas > 0) {
        printf("Cima\n");
        moverrainha(casas - 1);
    }
}

// Movimento recursivo do Bispo: para cada casa vertical, anda uma casa para a direita
// Loop interno controla o movimento horizontal (aqui fixo 1)
// Recursão controla o movimento vertical
void moverbispo(int casas){
    if (casas > 0) {
        for (int j = 0; j < 1; j++) {
            printf("Direita\n");
        }

        printf("Cima\n");
        // Próxima chamada, para próxima casa vertical
        moverbispo(casas - 1);
    }
}

// Movimento complexo do Cavalo usando loops aninhados e controle com break/continue
// Movimento: duas casas para cima e uma para direita ou esquerda por "L"
void movercavalo(char direcao, int movimentos) {
    for (int m = 0; m < movimentos; m++) {
        for (int passo = 0; passo < 3; passo++) {
            if (passo < 2) {
                printf("Cima\n"); // Dois passos para cima
            } else {
                // Último passo, vai para o lado
                if (direcao == 'D' || direcao == 'd') {
                    printf("Direita\n");
                } else if (direcao == 'E' || direcao == 'e') {
                    printf("Esquerda\n");
                } else {
                    printf("Direção inválida\n");
                    break; 
                }
                continue; // Continua para próximo movimento
            }
        }
    }
}

int main(){
    printf("\nMovimentação da Torre\n");
    movertorre(5);

    printf("\nMovimentação do Bispo\n");
    moverbispo(6);

    printf("\nMovimentação da Rainha\n");
    moverrainha(6);

    int mov = 1;
    char escolha;

    printf("\nPara qual lado o cavalo vai virar? D para direita e E para esquerda \n");
    scanf(" %c",&escolha);

    printf("\nMovimentação do Cavalo\n");
    movercavalo(escolha, mov);

    return 0;
}