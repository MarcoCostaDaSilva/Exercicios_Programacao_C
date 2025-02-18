#include <stdio.h>   // Biblioteca para entrada e sa�da padr�o
#include <string.h>  // Biblioteca para manipula��o de strings

int main() {
    char nome[100];  // Vari�vel para armazenar o nome do aluno
    float P1, P2, listas, media;

    // Solicita os dados do aluno
    printf("Informe o nome do aluno: ");
    scanf(" %[^\n]", nome);  // L� o nome completo do aluno

    printf("Informe a nota da P1: ");
    scanf("%f", &P1);

    printf("Informe a nota da P2: ");
    scanf("%f", &P2);

    printf("Informe a pontua��o das listas (m�ximo 5 pontos): ");
    scanf("%f", &listas);

    // Calcula a m�dia inicial com a equa��o fornecida
    media = ((P1 * 35) / 100) + ((P2 * 35) / 100) + listas;

    // Exibe a m�dia inicial
    printf("O aluno %s est� com m�dia %.2f\n", nome, media);

    // Verifica se o aluno foi aprovado ou precisa da prova substitutiva
    if (media >= 6) {
        printf("Aluno aprovado direto!\n");
    } else {
        printf("Aluno em recupera��o.\n");

        // Determina a menor nota para permitir a prova substitutiva
        float menorNota;
        char provaSubs[3];

        if (P1 < P2) {
            menorNota = P1;
            strcpy(provaSubs, "P1");  // Copia "P1" para a string
        } else {
            menorNota = P2;
            strcpy(provaSubs, "P2");  // Copia "P2" para a string
        }

        // Solicita a nova nota da prova de menor valor
        float novaNota;
        printf("Informe a nova nota para %s: ", provaSubs);
        scanf("%f", &novaNota);

        // Atualiza a m�dia com a nova nota
        if (strcmp(provaSubs, "P1") == 0) {
            P1 = novaNota;
        } else {
            P2 = novaNota;
        }

        media = ((P1 * 35) / 100) + ((P2 * 35) / 100) + listas;

        // Exibe a nova m�dia e o resultado final
        printf("Nova m�dia de %s: %.2f\n", nome, media);

        if (media >= 6) {
            printf("Aluno aprovado ap�s prova subs!\n");
        } else {
            printf("Aluno reprovado com subs!\n");
        }
    }

    return 0;
}

