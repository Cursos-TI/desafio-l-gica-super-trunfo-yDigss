#include <stdio.h>
#include <string.h>

int main() {
    char estado1, estado2;
    char codigo1[4], codigo2[4];
    char cidade1[100], cidade2[100];
    unsigned long populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int pontos1, pontos2;

    printf("===========================================================================\n");
    printf("                         Super Trunfo - Cartas\n");
    printf("===========================================================================\n");

    printf("Insira uma letra de 'A' a 'H' para representar o primeiro estado. \nEstado: ");
    scanf(" %c", &estado1);

    printf("\nInsira a letra do estado, ja fornecida anteriormente seguida de um numero de 01 a 04 ex:(a01). \nCodigo: ");
    scanf("%3s", codigo1);

    getchar();
    printf("\nInsira o nome da primeira cidade: \nCidade: ");
    fgets(cidade1, sizeof(cidade1),stdin);
    cidade1[strcspn(cidade1, "\n")] = 0;

    printf("\nInsira a quantidade de Habitantes da cidade. \nHabitantes: ");
    scanf("%lu", &populacao1);

    printf("\nInsira a area da cidade em km2. \nArea: ");
    scanf("%f", &area1);

    printf("\nInsira o Produto Interno Bruto da cidade. \nPIB: ");
    scanf("%f", &pib1);

    printf("\nInsira a quantidade de pontos turisticos da cidade. \nPontos Turisticos: ");
    scanf("%d", &pontos1);

    printf("===========================================================================\n");
    printf("                       Insira os Dados para a Carta 2\n");
    printf("===========================================================================\n");

    printf("Insira uma letra de 'A' a 'H' para representar o segundo estado. \nEstado: ");
    scanf(" %c", &estado2);

    printf("\nInsira a letra do estado, ja fornecida anteriormente seguida de um numero de 01 a 04 ex:(a01). \nCodigo: ");
    scanf("%3s", codigo2);

    getchar();
    printf("\nInsira o nome da segunda cidade. \nCidade: ");
    fgets(cidade2, sizeof(cidade2),stdin);
    cidade2[strcspn(cidade2, "\n")] = 0;

    printf("\nInsira a quantidade de Habitantes da cidade. \nHabitantes: ");
    scanf("%lu", &populacao2);

    printf("\nInsira a area da cidade em km2. \nArea: ");
    scanf("%f", &area2);

    printf("\nInsira o Produto Interno Bruto da cidade. \nPIB: ");
    scanf("%f", &pib2);

    printf("\nInsira a quantidade de pontos turisticos da cidade. \nPontos Turisticos: ");
    scanf("%d", &pontos2);

    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;
    float pibPC1 = (pib1 * 1000000000) / populacao1;
    float pibPC2 = (pib2 * 1000000000) / populacao2;
    float superPoder1 = (1.0f / densidade1) + populacao1 + area1 + pib1 + pontos1 + pibPC1;
    float superPoder2 = (1.0f / densidade2) + populacao2 + area2 + pib2 + pontos2 + pibPC2;

    printf("\n===========================================================================\n");
    printf("                                  Carta 1\n");
    printf("===========================================================================\n");

    printf("\nEstado: %c", estado1);
    printf("\nCodigo: %s", codigo1);
    printf("\nCidade: %s", cidade1);
    printf("\nPopulacao: %lu", populacao1);
    printf("\nArea: %.2f", area1);
    printf("\nPIB: %.2f", pib1);
    printf("\nNumero de Pontos Turisticos: %d", pontos1);
    printf("\nDensidade populacional: %.2f", densidade1);
    printf("\nPIB per Capita: %.2f", pibPC1);
    printf("\nSuper Poder 1: %.2f\n", superPoder1);

    printf("\n===========================================================================\n");
    printf("                                  Carta 2\n");
    printf("===========================================================================\n");

    printf("\nEstado: %c", estado2);
    printf("\nCodigo: %s", codigo2);
    printf("\nCidade: %s", cidade2);
    printf("\nPopulacao: %lu", populacao2);
    printf("\nArea: %.2f", area2);
    printf("\nPIB: %.2f", pib2);
    printf("\nNumero de Pontos Turisticos: %d", pontos2);
    printf("\nDensidade populacional: %.2f", densidade2);
    printf("\nPIB per Capita: %.2f", pibPC2);
    printf("\nSuper Poder 2: %.2f\n", superPoder2);

    printf("\n===========================================================================\n");
    printf("                             Comparacao de Cartas\n");
    printf("===========================================================================\n");

    // --- Comparação de cartas ---
    int escolha, escolha2;
    printf("\nEscolha o PRIMEIRO atributo que deseja comparar:\n");
    printf("1 - Populacao\n2 - Area\n3 - PIB\n4 - Numero de pontos turisticos\n5 - Densidade demografica\n6 - PIB per capita\n7 - Super poder\nEscolha: ");
    scanf("%d", &escolha);

    printf("\nEscolha o SEGUNDO atributo que deseja comparar:\n");
    printf("1 - Populacao\n2 - Area\n3 - PIB\n4 - Numero de pontos turisticos\n5 - Densidade demografica\n6 - PIB per capita\n7 - Super poder\nEscolha: ");
    scanf("%d", &escolha2);
    
    if (escolha2 == escolha) {
    printf("\nVocê não pode escolher o mesmo atributo da primeira escolha.\n");
    escolha2 = 0; // Define como inválido
    }

printf("\n========== RESULTADO DA COMPARACAO ==========\n");

// Calculando a pontuação somando os dois atributos escolhidos
float pontuacao1 = 0;
float pontuacao2 = 0;

// Primeiro atributo
switch (escolha) {
    case 1: pontuacao1 += populacao1; pontuacao2 += populacao2; break;
    case 2: pontuacao1 += area1; pontuacao2 += area2; break;
    case 3: pontuacao1 += pib1; pontuacao2 += pib2; break;
    case 4: pontuacao1 += pontos1; pontuacao2 += pontos2; break;
    case 5: pontuacao1 += 1.0 / densidade1; pontuacao2 += 1.0 / densidade2; break;
    case 6: pontuacao1 += pibPC1; pontuacao2 += pibPC2; break;
    case 7: pontuacao1 += superPoder1; pontuacao2 += superPoder2; break;
}

// Segundo atributo
switch (escolha2) {
    case 1: pontuacao1 += populacao1; pontuacao2 += populacao2; break;
    case 2: pontuacao1 += area1; pontuacao2 += area2; break;
    case 3: pontuacao1 += pib1; pontuacao2 += pib2; break;
    case 4: pontuacao1 += pontos1; pontuacao2 += pontos2; break;
    case 5: pontuacao1 += 1.0 / densidade1; pontuacao2 += 1.0 / densidade2; break;
    case 6: pontuacao1 += pibPC1; pontuacao2 += pibPC2; break;
    case 7: pontuacao1 += superPoder1; pontuacao2 += superPoder2; break;
}

// Mostrando resultado mantendo seu estilo
printf("\n===========================================================================\n");
printf("                             Pontuacao Final\n");
printf("===========================================================================\n");
printf("Carta 1 - %s => %.2f\n", cidade1, pontuacao1);
printf("Carta 2 - %s => %.2f\n", cidade2, pontuacao2);

if (pontuacao1 > pontuacao2)
    printf("=> Carta 1 (%s) venceu!\n", cidade1);
else if (pontuacao2 > pontuacao1)
    printf("=> Carta 2 (%s) venceu!\n", cidade2);
else
    printf("=> Empate!\n");
printf("===========================================================================\n");
    return 0;
}