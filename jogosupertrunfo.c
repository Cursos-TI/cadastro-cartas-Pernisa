#include <stdio.h>

#define NUM_ESTADOS 8
#define NUM_CIDADES 4

// Estrutura que representa uma cidade
struct Cidade {
    char nome[50];
    unsigned long int populacao; // Usando unsigned long int para população
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
};

// Função para cadastrar as cartas (Nível Novato)
void cadastrarCartas(struct Cidade cartas[NUM_ESTADOS][NUM_CIDADES]) {
    for (int i = 0; i < NUM_ESTADOS; i++) {
        for (int j = 0; j < NUM_CIDADES; j++) {
            printf("Cadastro da Cidade %c%02d\n", 'A' + i, j + 1);
            printf("Nome da Cidade: ");
            scanf(" %49[^\n]", cartas[i][j].nome); // Lê o nome da cidade
            printf("População: ");
            scanf("%lu", &cartas[i][j].populacao); // Lê a população como unsigned long int
            printf("Área (em km²): ");
            scanf("%f", &cartas[i][j].area);
            printf("PIB (em bilhões): ");
            scanf("%f", &cartas[i][j].pib);
            printf("Número de Pontos Turísticos: ");
            scanf("%d", &cartas[i][j].pontos_turisticos);
            printf("\n");
        }
    }
}

// Função para calcular a densidade populacional e o PIB per Capita (Nível Aventureiro)
void calcularPropriedades(struct Cidade cartas[NUM_ESTADOS][NUM_CIDADES]) {
    for (int i = 0; i < NUM_ESTADOS; i++) {
        for (int j = 0; j < NUM_CIDADES; j++) {
            // Calcula a densidade populacional
            cartas[i][j].densidade_populacional = (float)cartas[i][j].populacao / cartas[i][j].area;
            // Calcula o PIB per Capita
            cartas[i][j].pib_per_capita = cartas[i][j].pib / cartas[i][j].populacao;
            // Calcula o super poder (soma de todas as propriedades)
            cartas[i][j].super_poder = cartas[i][j].populacao + cartas[i][j].area + cartas[i][j].pib + cartas[i][j].pontos_turisticos
                                        + cartas[i][j].pib_per_capita + (1 / cartas[i][j].densidade_populacional);
        }
    }
}

// Função para exibir as cartas cadastradas (Nível Novato)
void exibirCartas(struct Cidade cartas[NUM_ESTADOS][NUM_CIDADES]) {
    for (int i = 0; i < NUM_ESTADOS; i++) {
        for (int j = 0; j < NUM_CIDADES; j++) {
            printf("Cidade %c%02d:\n", 'A' + i, j + 1);
            printf("Nome: %s\n", cartas[i][j].nome);
            printf("População: %lu\n", cartas[i][j].populacao);
            printf("Área: %.2f km²\n", cartas[i][j].area);
            printf("PIB: R$ %.2f bilhões\n", cartas[i][j].pib);
            printf("Pontos Turísticos: %d\n", cartas[i][j].pontos_turisticos);
            printf("Densidade Populacional: %.2f pessoas por km²\n", cartas[i][j].densidade_populacional);
            printf("PIB per Capita: R$ %.2f\n", cartas[i][j].pib_per_capita);
            printf("Super Poder (soma das propriedades): %.2f\n\n", cartas[i][j].super_poder);
        }
    }
}

// Função para comparar duas cartas (Nível Mestre)
void compararCartas(struct Cidade carta1, struct Cidade carta2) {
    printf("Comparação de Cartas:\n");

    // Comparação de População (maior valor vence)
    printf("População: Carta 1 venceu (%d)\n", carta1.populacao > carta2.populacao);
    
    // Comparação de Área (maior valor vence)
    printf("Área: Carta 1 venceu (%d)\n", carta1.area > carta2.area);
    
    // Comparação de PIB (maior valor vence)
    printf("PIB: Carta 1 venceu (%d)\n", carta1.pib > carta2.pib);
    
    // Comparação de Pontos Turísticos (maior valor vence)
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", carta1.pontos_turisticos > carta2.pontos_turisticos);
    
    // Comparação de Densidade Populacional (menor valor vence)
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", carta1.densidade_populacional < carta2.densidade_populacional);
    
    // Comparação de PIB per Capita (maior valor vence)
    printf("PIB per Capita: Carta 1 venceu (%d)\n", carta1.pib_per_capita > carta2.pib_per_capita);
    
    // Comparação de Super Poder (maior valor vence)
    printf("Super Poder: Carta 1 venceu (%d)\n", carta1.super_poder > carta2.super_poder);
}

int main() {
    struct Cidade cartas[NUM_ESTADOS][NUM_CIDADES];
    
    // Preencher algumas cidades manualmente para testes
    cartas[0][0] = (struct Cidade){"Cidade A01", 100000, 500.0, 10.5, 5, 0, 0, 0};
    cartas[0][1] = (struct Cidade){"Cidade A02", 150000, 600.0, 12.5, 6, 0, 0, 0};
    
    // Cadastro das cartas
    cadastrarCartas(cartas);
    
    // Cálculo das propriedades
    calcularPropriedades(cartas);
    
    // Exibição das cartas cadastradas
    exibirCartas(cartas);

    // Comparação de duas cartas
    printf("Escolha duas cidades para comparar:\n");
    int estado1, cidade1, estado2, cidade2;
    printf("Digite o estado (0-7) e a cidade (1-4) da primeira carta (exemplo: 0 1): ");
    scanf("%d %d", &estado1, &cidade1);
    printf("Digite o estado (0-7) e a cidade (1-4) da segunda carta (exemplo: 1 2): ");
    scanf("%d %d", &estado2, &cidade2);

    // Comparar as cartas selecionadas
    compararCartas(cartas[estado1][cidade1 - 1], cartas[estado2][cidade2 - 1]);
    
    return 0;
}
