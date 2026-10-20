#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <limits.h> 

// Nó da lista
typedef struct No {
    int valor;
    struct No* proximo;
} No;

// Inserir elemento no início
void inserir_inicio(No** lista, int valor);

// Inserir elemento no final
void inserir_final(No** lista, int valor);

// Inserir elemento em posição específica
void inserir_em_posicao(No** lista, int valor, int posicao);

// Remover elemento do início
void remover_inicio(No** lista);

// Remover elemento do final
void remover_final(No** lista);

// Remover elemento de posição específica
void remover_de_posicao(No** lista, int posicao);

// Buscar elemento por valor
int buscar_por_valor(No* lista, int valor);

// Buscar elemento por posição
int buscar_por_posicao(No* lista, int posicao);

// Verificar se a lista está vazia
bool esta_vazia(No* lista);

// Obter o tamanho da lista
int obter_tamanho(No* lista);

// Imprimir todos os elementos
void imprimir_lista(No* lista);

// Substituir elemento em posição específica
void substituir_em_posicao(No* lista, int posicao, int novo_valor);

// Contar quantas vezes um valor aparece
int contar_ocorrencias(No* lista, int valor);

// Obter a posição da primeira ocorrência de um valor
int obter_primeira_ocorrencia(No* lista, int valor);

// Obter a posição da última ocorrência de um valor
int obter_ultima_ocorrencia(No* lista, int valor);

// Inverter a lista
void inverter_lista(No** lista);

// Concatenar duas listas
void concatenar_listas(No** lista1, No** lista2);

// Comparar duas listas
bool comparar_listas(No* lista1, No* lista2);

// Verificar se a lista é palíndromo
bool eh_palindromo(No* lista);

// Remover todas as ocorrências de um valor
void remover_ocorrencias(No** lista, int valor);

// Inserir elementos em ordem crescente
void inserir_em_ordem(No** lista, int valor);

// Verificar se a lista está ordenada
bool esta_ordenada(No* lista);

// Encontrar o maior elemento
int encontrar_maior(No* lista);

// Encontrar o menor elemento
int encontrar_menor(No* lista);

// Remover os elementos em posições pares
void remover_posicoes_pares(No** lista);

// Intercalar duas listas ordenadas
No* intercalar_listas_ordenadas(No* lista1, No* lista2);

// Clonar la lista
No* clonar_lista(No* lista);

// Rotacionar a lista à esquerda
void rotacionar_esquerda(No** lista);

// Rotacionar a lista à direita
void rotacionar_direita(No** lista);

// Remover os N maiores elementos da lista
void remover_n_maiores(No** lista, int n);

// Liberar a memória da lista
void liberar_lista(No** lista);

#endif