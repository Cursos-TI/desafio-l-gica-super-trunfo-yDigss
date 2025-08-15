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

    // --- Dados Carta 1 ---
    printf("Insira uma letra de 'A' a 'H' para representar o primeiro estado. \nEstado: ");
    scanf(" %c", &estado1);

    printf("\nInsira a letra do estado seguida de um numero de 01 a 04 ex:(a01). \nCodigo: ");
    scanf("%3s", codigo1);

    getchar();
    printf("\nInsira o nome da primeira cidade: \nCidade: ");
    fgets(cidade1, sizeof(cidade1), stdin);
    cidade1[strcspn(cidade1, "\n")] = 0;

    printf("\nInsira a quantidade de Habitantes da cidade. \nHabitantes: ");
    scanf("%lu", &populacao1);

    printf("\nInsira a area da cidade em km2. \nArea: ");
    scanf("%f", &area1);

    printf("\nInsira o Produto Interno Bruto da cidade (em milhões). \nPIB: ");
    scanf("%f", &pib1);

    printf("\nInsira a quantidade de pontos turisticos da cidade. \nPontos Turisticos: ");
    scanf("%d", &pontos1);

    // --- Dados Carta 2 ---
    printf("===========================================================================\n");
    printf("                       Insira os Dados para a Carta 2\n");
    printf("===========================================================================\n");

    printf("Insira uma letra de 'A' a 'H' para representar o segundo estado. \nEstado: ");
    scanf(" %c", &estado2);

    printf("\nInsira a letra do estado seguida de um numero de 01 a 04 ex:(a01). \nCodigo: ");
    scanf("%3s", codigo2);

    getchar();
    printf("\nInsira o nome da segunda cidade. \nCidade: ");
    fgets(cidade2, sizeof(cidade2), stdin);
    cidade2[strcspn(cidade2, "\n")] = 0;

    printf("\nInsira a quantidade de Habitantes da cidade. \nHabitantes: ");
    scanf("%lu", &populacao2);

    printf("\nInsira a area da cidade em km2. \nArea: ");
    scanf("%f", &area2);

    printf("\nInsira o Produto Interno Bruto da cidade (em milhões). \nPIB: ");
    scanf("%f", &pib2);

    printf("\nInsira a quantidade de pontos turisticos da cidade. \nPontos Turisticos: ");
    scanf("%d", &pontos2);

    // --- Cálculos ---
    float densidade1 = (area1 != 0.0f) ? ((float)populacao1 / area1) : 0.0f;
    float densidade2 = (area2 != 0.0f) ? ((float)populacao2 / area2) : 0.0f;

    float pibPC1 = (populacao1 != 0) ? (pib1 * 1000000.0f) / populacao1 : 0.0f;
    float pibPC2 = (populacao2 != 0) ? (pib2 * 1000000.0f) / populacao2 : 0.0f;

    float superPoder1 = (densidade1 != 0.0f ? 1.0f / densidade1 : 0.0f) + populacao1 + area1 + (pib1 * 1000000.0f) + pontos1 + pibPC1;
    float superPoder2 = (densidade2 != 0.0f ? 1.0f / densidade2 : 0.0f) + populacao2 + area2 + (pib2 * 1000000.0f) + pontos2 + pibPC2;

    // --- Exibição das Cartas ---
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

    // --- Comparação ---
    printf("\n===========================================================================\n");
    printf("                             Comparacao de Cartas\n");
    printf("===========================================================================\n");

    int escolha, escolha2;
    printf("\nEscolha o PRIMEIRO atributo que deseja comparar:\n");
    printf("1 - Populacao\n2 - Area\n3 - PIB\n4 - Numero de pontos turisticos\n5 - Densidade demografica\n6 - PIB per capita\n7 - Super poder\nEscolha: ");
    scanf("%d", &escolha);

    printf("\nEscolha o SEGUNDO atributo que deseja comparar (diferente do primeiro):\n");
    printf("1 - Populacao\n2 - Area\n3 - PIB\n4 - Numero de pontos turisticos\n5 - Densidade demografica\n6 - PIB per capita\n7 - Super poder\nEscolha: ");
    scanf("%d", &escolha2);

    if (escolha2 == escolha) {
        printf("\nErro: Você não pode escolher o mesmo atributo da primeira escolha.\n");
        printf("Segundo atributo será ignorado na comparação.\n");
        escolha2 = 0; // marca como inválido
    }

    int vencedorAtr1 = 0; // 1: Carta1, 2: Carta2, 0: Empate
    int vencedorAtr2 = 0;

    // --- Comparação Primeiro Atributo ---
    switch (escolha) {
        case 1: if(populacao1 > populacao2) vencedorAtr1 = 1;
                else if(populacao2 > populacao1) vencedorAtr1 = 2;
                else vencedorAtr1 = 0;
                break;
        case 2: if(area1 > area2) vencedorAtr1 = 1;
                else if(area2 > area1) vencedorAtr1 = 2;
                else vencedorAtr1 = 0;
                break;
        case 3: if(pib1 > pib2) vencedorAtr1 = 1;
                else if(pib2 > pib1) vencedorAtr1 = 2;
                else vencedorAtr1 = 0;
                break;
        case 4: if(pontos1 > pontos2) vencedorAtr1 = 1;
                else if(pontos2 > pontos1) vencedorAtr1 = 2;
                else vencedorAtr1 = 0;
                break;
        case 5: if(densidade1 < densidade2) vencedorAtr1 = 1; // menor densidade vence
                else if(densidade2 < densidade1) vencedorAtr1 = 2;
                else vencedorAtr1 = 0;
                break;
        case 6: if(pibPC1 > pibPC2) vencedorAtr1 = 1;
                else if(pibPC2 > pibPC1) vencedorAtr1 = 2;
                else vencedorAtr1 = 0;
                break;
        case 7: if(superPoder1 > superPoder2) vencedorAtr1 = 1;
                else if(superPoder2 > superPoder1) vencedorAtr1 = 2;
                else vencedorAtr1 = 0;
                break;
    }

    // --- Comparação Segundo Atributo (se válido) ---
    if (escolha2 != 0) {
        switch (escolha2) {
            case 1: if(populacao1 > populacao2) vencedorAtr2 = 1;
                    else if(populacao2 > populacao1) vencedorAtr2 = 2;
                    else vencedorAtr2 = 0;
                    break;
            case 2: if(area1 > area2) vencedorAtr2 = 1;
                    else if(area2 > area1) vencedorAtr2 = 2;
                    else vencedorAtr2 = 0;
                    break;
            case 3: if(pib1 > pib2) vencedorAtr2 = 1;
                    else if(pib2 > pib1) vencedorAtr2 = 2;
                    else vencedorAtr2 = 0;
                    break;
            case 4: if(pontos1 > pontos2) vencedorAtr2 = 1;
                    else if(pontos2 > pontos1) vencedorAtr2 = 2;
                    else vencedorAtr2 = 0;
                    break;
            case 5: if(densidade1 < densidade2) vencedorAtr2 = 1;
                    else if(densidade2 < densidade1) vencedorAtr2 = 2;
                    else vencedorAtr2 = 0;
                    break;
            case 6: if(pibPC1 > pibPC2) vencedorAtr2 = 1;
                    else if(pibPC2 > pibPC1) vencedorAtr2 = 2;
                    else vencedorAtr2 = 0;
                    break;
            case 7: if(superPoder1 > superPoder2) vencedorAtr2 = 1;
                    else if(superPoder2 > superPoder1) vencedorAtr2 = 2;
                    else vencedorAtr2 = 0;
                    break;
        }
    }

    // --- Resultado Final ---
    printf("\n===========================================================================\n");
    printf("                             Resultado Final\n");
    printf("===========================================================================\n");

    if (vencedorAtr1 == 1 && vencedorAtr2 == 1)
        printf("=> Carta 1 (%s) venceu em ambos os atributos!\n", cidade1);
    else if (vencedorAtr1 == 2 && vencedorAtr2 == 2)
        printf("=> Carta 2 (%s) venceu em ambos os atributos!\n", cidade2);
    else
        printf("=> Empate! Nenhuma carta venceu em ambos os atributos.\n");

    printf("===========================================================================\n");
    return 0;
}
