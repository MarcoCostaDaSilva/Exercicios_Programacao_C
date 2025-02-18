# Exercícios de Programação em Linguagem C

## 🔹 Exercício 01
📌 Enunciado: Cálculo da Média Final de um Aluno
Desenvolva um programa em C++ que solicite ao usuário:

- Nome do aluno.
- Nota da Prova 1 (P1)
- A nota da Prova 2 (P2)
- Pontuação obtida nas listas de exercícios (máximo de 5 pontos)
  
O programa calculará a média final do aluno utilizando a seguinte fórmula:

![Nova-Imagem](https://github.com/user-attachments/assets/396884bd-2e73-4094-871a-5e96404e65bd)


### Regras de aprovação:
- Se a média final for maior ou igual a 6, exibir: "Aluno aprovado direto!"
- Caso contrário, identificar a menor nota entre P1 e P2, permitir ao aluno refazer essa prova e recalcular a média.
- Exibir a nova média e a decisão final:
- Se a média final continuar abaixo de 6, exibir: "Aluno reprovado com subs!"

### Código em C:

## Cálculo da Média com Substitutiva

Este programa em C solicita o nome do aluno e suas notas de P1, P2 e listas. Se a média for menor que 6, permite refazer a menor prova.

```c
#include <stdio.h>   // Biblioteca para entrada e saída padrão
#include <string.h>  // Biblioteca para manipulação de strings

int main() {
    char nome[100];  // Variável para armazenar o nome do aluno
    float P1, P2, listas, media;

    // Solicita os dados do aluno
    printf("Informe o nome do aluno: ");
    scanf(" %[^\n]", nome);  // Lê o nome completo do aluno

    printf("Informe a nota da P1: ");
    scanf("%f", &P1);

    printf("Informe a nota da P2: ");
    scanf("%f", &P2);

    printf("Informe a pontuação das listas (máximo 5 pontos): ");
    scanf("%f", &listas);

    // Calcula a média inicial com a equação fornecida
    media = ((P1 * 35) / 100) + ((P2 * 35) / 100) + listas;

    // Exibe a média inicial
    printf("O aluno %s está com média %.2f\n", nome, media);

    // Verifica se o aluno foi aprovado ou precisa da prova substitutiva
    if (media >= 6) {
        printf("Aluno aprovado direto!\n");
    } else {
        printf("Aluno em recuperação.\n");

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

        // Atualiza a média com a nova nota
        if (strcmp(provaSubs, "P1") == 0) {
            P1 = novaNota;
        } else {
            P2 = novaNota;
        }

        media = ((P1 * 35) / 100) + ((P2 * 35) / 100) + listas;

        // Exibe a nova média e o resultado final
        printf("Nova média de %s: %.2f\n", nome, media);

        if (media >= 6) {
            printf("Aluno aprovado após prova subs!\n");
        } else {
            printf("Aluno reprovado com subs!\n");
        }
    }

    return 0;
}
```
