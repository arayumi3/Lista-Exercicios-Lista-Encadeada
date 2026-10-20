#include "listaEncadeada.h"
#include <stdio.h>
#include <stdlib.h> 

void imprimir_menu() {
    printf("\n--- MENU DE OPERACOES ---\n");
    printf(" 1. Inserir no inicio\n");
    printf(" 2. Inserir no final\n");
    printf(" 3. Inserir em posicao especifica\n");
    printf(" 4. Remover do inicio\n");
    printf(" 5. Remover do final\n");
    printf(" 6. Remover de posicao especifica\n");
    printf(" 7. Buscar por valor (retorna primeira posicao)\n");
    printf(" 8. Buscar por posicao (retorna valor)\n");
    printf(" 9. Verificar se a lista esta vazia\n");
    printf("10. Obter tamanho da lista\n");
    printf("11. Imprimir todos os elementos (da lista ativa)\n");
    printf("12. Substituir elemento em posicao\n");
    printf("13. Contar ocorrencias de um valor\n");
    printf("14. Obter primeira ocorrencia de um valor\n");
    printf("15. Obter ultima ocorrencia de um valor\n");
    printf("16. Inverter a lista\n");
    printf("17. Concatenar lista principal com a secundaria\n");
    printf("18. Comparar lista principal com a secundaria\n");
    printf("19. Verificar se a lista (ativa) eh palindromo\n");
    printf("20. Remover todas as ocorrencias de um valor\n");
    printf("21. Inserir em ordem (mantem a lista ordenada)\n");
    printf("22. Verificar se a lista (ativa) esta ordenada\n");
    printf("23. Encontrar o maior elemento\n");
    printf("24. Encontrar o menor elemento\n");
    printf("25. Remover elementos em posicoes pares\n");
    printf("26. Intercalar principal com secundaria (ambas devem estar ordenadas)\n");
    printf("27. Clonar lista principal para a secundaria\n");
    printf("28. Rotacionar a lista para a esquerda\n");
    printf("29. Rotacionar a lista para a direita\n");
    printf("30. Remover os N maiores elementos\n");
    printf("\n--- GERENCIAMENTO ---\n");
    printf("40. Alternar para gerenciar a LISTA SECUNDARIA\n");
    printf("41. Alternar para gerenciar a LISTA PRINCIPAL\n");
    printf("\n 0. Sair\n");
    printf("---------------------------------------------\n");
    printf("Escolha uma opcao: ");
}

int main() {
    No* lista_principal = NULL;
    No* lista_secundaria = NULL;

    No** lista_ativa = &lista_principal; 

    int opcao, valor, posicao, resultado, n;

    do {
        
        system("clear"); 
        
        if (lista_ativa == &lista_principal) {
            printf("LISTA PRINCIPAL\n\n");
        } else {
            printf("LISTA SECUNDARIA\n\n");
        }

        printf("Estado Atual das Listas:\n");
        printf("  Principal:   ");
        imprimir_lista(lista_principal);
        printf("  Secundaria:  ");
        imprimir_lista(lista_secundaria);

        imprimir_menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor para inserir no inicio: ");
                scanf("%d", &valor);
                inserir_inicio(lista_ativa, valor);
                break;
            case 2:
                printf("Digite o valor para inserir no final: ");
                scanf("%d", &valor);
                inserir_final(lista_ativa, valor);
                break;
            case 3:
                printf("Digite o valor: "); scanf("%d", &valor);
                printf("Digite a posicao: "); scanf("%d", &posicao);
                inserir_em_posicao(lista_ativa, valor, posicao);
                break;
            case 4:
                remover_inicio(lista_ativa);
                printf("Elemento do inicio da lista ativa removido.\n");
                break;
            case 5:
                remover_final(lista_ativa);
                printf("Elemento do final da lista ativa removido.\n");
                break;
            case 6:
                printf("Digite a posicao a remover: "); scanf("%d", &posicao);
                remover_de_posicao(lista_ativa, posicao);
                break;
            case 7:
                printf("Digite o valor a buscar: "); scanf("%d", &valor);
                resultado = buscar_por_valor(*lista_ativa, valor);
                if (resultado != -1) printf("Valor %d encontrado na posicao %d.\n", valor, resultado);
                else printf("Valor %d nao encontrado.\n", valor);
                break;
            case 8:
                printf("Digite a posicao a buscar: "); scanf("%d", &posicao);
                resultado = buscar_por_posicao(*lista_ativa, posicao);
                if (resultado != INT_MIN) printf("O valor na posicao %d eh %d.\n", posicao, resultado);
                else printf("Posicao invalida.\n");
                break;
            case 9:
                if (esta_vazia(*lista_ativa)) printf("A lista ativa esta vazia.\n");
                else printf("A lista ativa NAO esta vazia.\n");
                break;
            case 10:
                printf("Tamanho da lista ativa: %d\n", obter_tamanho(*lista_ativa));
                break;
            case 11:
                printf("Imprimindo a lista ativa novamente:\n");
                imprimir_lista(*lista_ativa);
                break;
            case 12:
                printf("Digite a posicao para substituir: "); scanf("%d", &posicao);
                printf("Digite o novo valor: "); scanf("%d", &valor);
                substituir_em_posicao(*lista_ativa, posicao, valor);
                break;
            case 13:
                printf("Digite o valor para contar: "); scanf("%d", &valor);
                printf("O valor %d aparece %d vez(es) na lista ativa.\n", valor, contar_ocorrencias(*lista_ativa, valor));
                break;
            case 14:
                printf("Digite o valor a buscar: "); scanf("%d", &valor);
                resultado = obter_primeira_ocorrencia(*lista_ativa, valor);
                if (resultado != -1) printf("Primeira ocorrencia de %d esta na posicao %d.\n", valor, resultado);
                else printf("Valor %d nao encontrado.\n", valor);
                break;
            case 15:
                printf("Digite o valor a buscar: "); scanf("%d", &valor);
                resultado = obter_ultima_ocorrencia(*lista_ativa, valor);
                if (resultado != -1) printf("Ultima ocorrencia de %d esta na posicao %d.\n", valor, resultado);
                else printf("Valor %d nao encontrado.\n", valor);
                break;
            case 16:
                inverter_lista(lista_ativa);
                printf("Lista ativa invertida.\n");
                break;
            case 17:
                if (esta_vazia(lista_secundaria)) {
                    printf("A lista secundaria esta vazia. Nao ha nada para concatenar.\n");
                } else {
                    concatenar_listas(&lista_principal, &lista_secundaria);
                    printf("Lista principal concatenada com a secundaria. A secundaria foi esvaziada.\n");
                }
                break;
            case 18:
                if (comparar_listas(lista_principal, lista_secundaria))
                    printf("As listas sao IGUAIS.\n");
                else
                    printf("As listas sao DIFERENTES.\n");
                break;
            case 19:
                if (eh_palindromo(*lista_ativa)) printf("A lista ativa eh um palindromo.\n");
                else printf("A lista ativa NAO eh um palindromo.\n");
                break;
            case 20:
                printf("Digite o valor a ser removido completamente: "); scanf("%d", &valor);
                remover_ocorrencias(lista_ativa, valor);
                break;
            case 21:
                printf("Digite o valor para inserir em ordem: "); scanf("%d", &valor);
                inserir_em_ordem(lista_ativa, valor);
                break;
            case 22:
                if (esta_ordenada(*lista_ativa)) printf("A lista ativa esta ordenada.\n");
                else printf("A lista ativa NAO esta ordenada.\n");
                break;
            case 23:
                resultado = encontrar_maior(*lista_ativa);
                if (resultado != INT_MIN) printf("O maior elemento na lista ativa eh: %d\n", resultado);
                else printf("A lista ativa esta vazia.\n");
                break;
            case 24:
                resultado = encontrar_menor(*lista_ativa);
                if (resultado != INT_MAX) printf("O menor elemento na lista ativa eh: %d\n", resultado);
                else printf("A lista ativa esta vazia.\n");
                break;
            case 25:
                remover_posicoes_pares(lista_ativa);
                printf("Elementos em posicoes pares removidos da lista ativa.\n");
                break;
            case 26:
                if (!esta_ordenada(lista_principal) || !esta_ordenada(lista_secundaria)) {
                    printf("ERRO: Ambas as listas (principal e secundaria) devem estar ordenadas para esta operacao.\n");
                } else {
                    No* lista_intercalada = intercalar_listas_ordenadas(lista_principal, lista_secundaria);
                    lista_principal = lista_intercalada;
                    lista_secundaria = NULL;
                    printf("Listas intercaladas. O resultado esta na lista principal.\n");
                }
                break;
            case 27:
                liberar_lista(&lista_secundaria);
                lista_secundaria = clonar_lista(lista_principal);
                printf("Lista principal clonada para a lista secundaria.\n");
                break;
            case 28:
                rotacionar_esquerda(lista_ativa);
                printf("Lista ativa rotacionada para a esquerda.\n");
                break;
            case 29:
                rotacionar_direita(lista_ativa);
                printf("Lista ativa rotacionada para a direita.\n");
                break;
            case 30:
                printf("Digite o numero (N) de maiores elementos a remover: "); scanf("%d", &n);
                remover_n_maiores(lista_ativa, n);
                break;
            case 40:
                lista_ativa = &lista_secundaria;
                break;
            case 41:
                lista_ativa = &lista_principal;
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }

        if (opcao != 0) {
            printf("\nPressione Enter para continuar...");
            while(getchar() != '\n'); 
            getchar();
        }

    } while (opcao != 0);

    // Libera a memória alocada
    liberar_lista(&lista_principal);
    liberar_lista(&lista_secundaria);

    return 0;
}