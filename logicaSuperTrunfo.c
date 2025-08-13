#include <stdio.h>

int main(){
    
    // definição das variaveis da carta 1 e 2
    char estado1, estado2;
    char codigo1[4], codigo2[4];
    char cidade1[100], cidade2[100];
    unsigned long populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int pontos1, pontos2;


    printf("Carta 1 - Cadastro\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);
    printf("Codigo da Carta (ex: A01): ");
    scanf(" %3s", codigo1);
    printf("Nome da Cidade: ");
    scanf(" %99[^\n]", cidade1);
    printf("Populacao (numero inteiro): ");
    scanf("%lu", &populacao1);
    printf("Area (km2, usar ponto para decimal - ex: 1521.11): ");
    scanf("%f", &area1);
    printf("PIB ( em bilhoes, ex: 699.28):");
    scanf("%f", &pib1);
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontos1);


    //leitura e cadastro da carta 2
    printf("Carta 2 - Cadastro\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);
    printf("Codigo da Carta (ex: A01): ");
    scanf(" %3s", codigo2);
    printf("Nome da Cidade: ");
    scanf(" %99[^\n]", cidade2);
    printf("Populacao (numero inteiro): ");
    scanf("%lu", &populacao2);
    printf("Area (km2, usar ponto para decimal - ex: 1521.11): ");
    scanf("%f", &area2);
    printf("PIB ( em bilhoes, ex: 699.28):");
    scanf("%f", &pib2);
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontos2);


    float densidade1 = populacao1 / area1; // calculo de densidade adicionado 
    float densidade2 = populacao2 / area2;
    float pibPC1 = (pib1 * 1000000000) / populacao1; // calculado de pib per capita adicionado
    float pibPC2 = (pib2 * 1000000000) / populacao2; // foi utilizado "* 1000000000" para converter para bilhoes e evitar erros
    float superPoder1 = (1.0f / densidade1) + populacao1 + area1 + pib1 + pontos1 + pibPC1; // calculando o super poder da carta
    float superPoder2 = (1.0f / densidade2) + populacao2 + area2 + pib2 + pontos2 + pibPC2;


    // exibição dos dados
    printf("\n\nCarta 1:\n\n");
    printf("Estado: %c\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", cidade1);
    printf("Populacao: %lu\n", populacao1);
    printf("Area: %.2f km2\n", area1);
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf("Numero de Pontos Turisticos: %d\n", pontos1);
    printf("Densidade populacional: %.2f hab/km2\n", densidade1);
    printf("PIB per Capita: %.2f\n", pibPC1);

    printf("\n\nCarta 2:\n\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("Populacao: %lu\n", populacao2);
    printf("Area: %.2f km2\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Numero de Pontos Turisticos: %d\n", pontos2);
    printf("Densidade populacional: %.2f hab/km2\n", densidade2);
    printf("PIB per Capita: %.2f\n", pibPC2);


    // comparaçao usando if else

    if (populacao1 > populacao2){
        printf("Carta 1 venceu! com a populacao de %lu\n", populacao1);
    }
    else{
        printf("Carta 2 venceu! com a populacao de %lu\n", populacao2);
    }

    if (area1 > area2){
        printf("Carta 1 venceu! com a area de %f\n", area1);
    }
    else{
        printf("Carta 2 venceu! com a area de %f\n", area2);
    }

    if (pib1 > pib2){
        printf("Carta 1 venceu! com o pib de %f\n", pib1);
    }
    else{
        printf("Carta 2 venceu! com o pib de %f\n", pib2);
    }

    if (pontos1 > pontos2){
        printf("Carta 1 venceu! com %d pontos turisticos\n", pontos1);
    }
    else{
        printf("Carta 2 venceu! com %d pontos turisticos\n", pontos2);
    }

    if (densidade1 > densidade2){
        printf("Carta 1 venceu! com densidade de %f", densidade1);
    }
    else{
        printf("Carta 2 venceu! com densidade de %f", densidade2);
    }

    if (pibPC1 > pibPC2){
        printf("Carta 1 venceu! com %f de Pib per Capita\n", pibPC1);
    }
    else{
        printf("Carta 2 venceu! com %f de Pib per Capita\n", pibPC2);
    }

    if (superPoder1 > superPoder2){
        printf("Carta 1 venceu! com super poder de %f", superPoder1);
    }
    else{
        printf("Carta 2 venceu! com super poder de %f", superPoder2);
    }

    return 0;

}