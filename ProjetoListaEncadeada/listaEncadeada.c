#include "listaEncadeada.h"

// Criar um novo nó
No* criar_no(int valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro de alocacao de memoria!\n");
        exit(1);
    }
    novo_no->valor = valor;
    novo_no->proximo = NULL;
    return novo_no;
}
// Inserir no inicio
void inserir_inicio(No** lista, int valor) {
    No* novo_no = criar_no(valor);
    novo_no->proximo = *lista;
    *lista = novo_no;
}

// Inserir no final
void inserir_final(No** lista, int valor) {
    No* novo_no = criar_no(valor);
    if (*lista == NULL) {
        *lista = novo_no;
        return;
    }
    No* atual = *lista;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    atual->proximo = novo_no;
}

// Inserir em posição
void inserir_em_posicao(No** lista, int valor, int posicao) {
    if (posicao < 0) return;
    if (posicao == 0) {
        inserir_inicio(lista, valor);
        return;
    }
    No* novo_no = criar_no(valor);
    No* atual = *lista;
    int i = 0;
    while (atual != NULL && i < posicao - 1) {
        atual = atual->proximo;
        i++;
    }
    if (atual == NULL) {
        free(novo_no);
        printf("Posicao invalida.\n");
        return;
    }
    novo_no->proximo = atual->proximo;
    atual->proximo = novo_no;
}

// Remover do inicio 
void remover_inicio(No** lista) {
    if (*lista == NULL) return;
    No* temp = *lista;
    *lista = (*lista)->proximo;
    free(temp);
}

// Remover do final
void remover_final(No** lista) {
    if (*lista == NULL) return;
    if ((*lista)->proximo == NULL) {
        free(*lista);
        *lista = NULL;
        return;
    }
    No* atual = *lista;
    while (atual->proximo->proximo != NULL) {
        atual = atual->proximo;
    }
    free(atual->proximo);
    atual->proximo = NULL;
}

// Remover de posição
void remover_de_posicao(No** lista, int posicao) {
    if (*lista == NULL || posicao < 0) return;
    if (posicao == 0) {
        remover_inicio(lista);
        return;
    }
    No* atual = *lista;
    No* anterior = NULL;
    int i = 0;
    while (atual != NULL && i < posicao) {
        anterior = atual;
        atual = atual->proximo;
        i++;
    }
    if (atual == NULL) {
        printf("Posicao invalida.\n");
        return;
    }
    anterior->proximo = atual->proximo;
    free(atual);
}

// Buscar por valor
int buscar_por_valor(No* lista, int valor) {
    No* atual = lista;
    int pos = 0;
    while (atual != NULL) {
        if (atual->valor == valor) {
            return pos;
        }
        atual = atual->proximo;
        pos++;
    }
    return -1; 
}

// Buscar por posição
int buscar_por_posicao(No* lista, int posicao) {
    if (posicao < 0) return INT_MIN;
    No* atual = lista;
    int i = 0;
    while (atual != NULL && i < posicao) {
        atual = atual->proximo;
        i++;
    }
    if (atual == NULL) {
        return INT_MIN;
    }
    return atual->valor;
}

// Verificar se está vazia
bool esta_vazia(No* lista) {
    return lista == NULL;
}

// Obter tamanho
int obter_tamanho(No* lista) {
    int tamanho = 0;
    No* atual = lista;
    while (atual != NULL) {
        tamanho++;
        atual = atual->proximo;
    }
    return tamanho;
}

// Imprimir lista
void imprimir_lista(No* lista) {
    if (esta_vazia(lista)) {
        printf("Lista: []\n");
        return;
    }
    printf("Lista: [");
    No* atual = lista;
    while (atual != NULL) {
        printf("%d", atual->valor);
        if (atual->proximo != NULL) {
            printf(", ");
        }
        atual = atual->proximo;
    }
    printf("]\n");
}

// Substituir em posição
void substituir_em_posicao(No* lista, int posicao, int novo_valor) {
    No* atual = lista;
    int i = 0;
    while (atual != NULL && i < posicao) {
        atual = atual->proximo;
        i++;
    }
    if (atual != NULL) {
        atual->valor = novo_valor;
    } else {
        printf("Posicao invalida.\n");
    }
}

// Contar ocorrências
int contar_ocorrencias(No* lista, int valor) {
    int cont = 0;
    No* atual = lista;
    while (atual != NULL) {
        if (atual->valor == valor) {
            cont++;
        }
        atual = atual->proximo;
    }
    return cont;
}

// Obter primeira ocorrência
int obter_primeira_ocorrencia(No* lista, int valor) {
    return buscar_por_valor(lista, valor);
}

// Obter última ocorrência
int obter_ultima_ocorrencia(No* lista, int valor) {
    int pos = -1;
    int i = 0;
    No* atual = lista;
    while (atual != NULL) {
        if (atual->valor == valor) {
            pos = i;
        }
        atual = atual->proximo;
        i++;
    }
    return pos;
}

// Inverter lista
void inverter_lista(No** lista) {
    No* anterior = NULL;
    No* atual = *lista;
    No* proximo = NULL;
    while (atual != NULL) {
        proximo = atual->proximo;
        atual->proximo = anterior;
        anterior = atual;
        atual = proximo;
    }
    *lista = anterior;
}

// Concatenar duas listas
void concatenar_listas(No** lista1, No** lista2) {
    if (*lista1 == NULL) {
        *lista1 = *lista2;
    } else {
        No* atual = *lista1;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = *lista2;
    }
    *lista2 = NULL;
}

// Comparar duas listas
bool comparar_listas(No* lista1, No* lista2) {
    No* atual1 = lista1;
    No* atual2 = lista2;
    while (atual1 != NULL && atual2 != NULL) {
        if (atual1->valor != atual2->valor) {
            return false;
        }
        atual1 = atual1->proximo;
        atual2 = atual2->proximo;
    }
    return atual1 == NULL && atual2 == NULL;
}

// Verificar se é palíndromo
bool eh_palindromo(No* lista) {
    if (lista == NULL) return true;
    No* clone = clonar_lista(lista);
    inverter_lista(&clone);
    bool resultado = comparar_listas(lista, clone);
    liberar_lista(&clone);
    return resultado;
}

// Remover todas as ocorrências de um valor
void remover_ocorrencias(No** lista, int valor) {
    No* atual = *lista;
    No* anterior = NULL;
    while (atual != NULL) {
        if (atual->valor == valor) {
            No* temp = atual;
            if (anterior == NULL) { 
                *lista = atual->proximo;
                atual = *lista;
            } else {
                anterior->proximo = atual->proximo;
                atual = atual->proximo;
            }
            free(temp);
        } else {
            anterior = atual;
            atual = atual->proximo;
        }
    }
}

// Inserir em ordem
void inserir_em_ordem(No** lista, int valor) {
    No* novo_no = criar_no(valor);
    if (*lista == NULL || (*lista)->valor >= valor) {
        novo_no->proximo = *lista;
        *lista = novo_no;
        return;
    }
    No* atual = *lista;
    while (atual->proximo != NULL && atual->proximo->valor < valor) {
        atual = atual->proximo;
    }
    novo_no->proximo = atual->proximo;
    atual->proximo = novo_no;
}

// Verificar se está ordenada
bool esta_ordenada(No* lista) {
    if (lista == NULL || lista->proximo == NULL) {
        return true;
    }
    No* atual = lista;
    while (atual->proximo != NULL) {
        if (atual->valor > atual->proximo->valor) {
            return false;
        }
        atual = atual->proximo;
    }
    return true;
}

// 23. Encontrar maior elemento
int encontrar_maior(No* lista) {
    if (esta_vazia(lista)) return INT_MIN;
    int maior = lista->valor;
    No* atual = lista->proximo;
    while (atual != NULL) {
        if (atual->valor > maior) {
            maior = atual->valor;
        }
        atual = atual->proximo;
    }
    return maior;
}

// Encontrar menor elemento
int encontrar_menor(No* lista) {
    if (esta_vazia(lista)) return INT_MAX;
    int menor = lista->valor;
    No* atual = lista->proximo;
    while (atual != NULL) {
        if (atual->valor < menor) {
            menor = atual->valor;
        }
        atual = atual->proximo;
    }
    return menor;
}

// Remover posições pares
void remover_posicoes_pares(No** lista) {
    if (*lista == NULL) return;
    int i = 0;
    No* atual = *lista;
    No* anterior = NULL;
    while (atual != NULL) {
        if (i % 2 == 0) {
            No* temp = atual;
            if (anterior == NULL) { 
                *lista = atual->proximo;
                atual = *lista;
            } else {
                anterior->proximo = atual->proximo;
                atual = atual->proximo;
            }
            free(temp);
        } else {
            anterior = atual;
            atual = atual->proximo;
        }
        i++;
    }
}

// Intercalar duas listas ordenadas
No* intercalar_listas_ordenadas(No* lista1, No* lista2) {
    No* resultado = NULL;
    No** cauda_resultado = &resultado;

    while (lista1 != NULL && lista2 != NULL) {
        if (lista1->valor <= lista2->valor) {
            *cauda_resultado = lista1;
            lista1 = lista1->proximo;
        } else {
            *cauda_resultado = lista2;
            lista2 = lista2->proximo;
        }
        cauda_resultado = &((*cauda_resultado)->proximo);
    }

    if (lista1 != NULL) {
        *cauda_resultado = lista1;
    } else if (lista2 != NULL) {
        *cauda_resultado = lista2;
    }

    return resultado;
}


// Clonar lista
No* clonar_lista(No* lista) {
    if (lista == NULL) return NULL;
    No* nova_lista = NULL;
    No* cauda_nova_lista = NULL;
    No* atual = lista;
    while (atual != NULL) {
        No* novo_no = criar_no(atual->valor);
        if (nova_lista == NULL) {
            nova_lista = novo_no;
            cauda_nova_lista = novo_no;
        } else {
            cauda_nova_lista->proximo = novo_no;
            cauda_nova_lista = novo_no;
        }
        atual = atual->proximo;
    }
    return nova_lista;
}

// Rotacionar à esquerda
void rotacionar_esquerda(No** lista) {
    if (*lista == NULL || (*lista)->proximo == NULL) return;
    No* primeiro = *lista;
    *lista = (*lista)->proximo; 
    primeiro->proximo = NULL;

    No* atual = *lista;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    atual->proximo = primeiro;
}

// Rotacionar à direita
void rotacionar_direita(No** lista) {
    if (*lista == NULL || (*lista)->proximo == NULL) return;
    No* atual = *lista;
    No* anterior = NULL;
    while (atual->proximo != NULL) {
        anterior = atual;
        atual = atual->proximo;
    }
    anterior->proximo = NULL; 
    atual->proximo = *lista; 
    *lista = atual;
}

// Remover N maiores
void remover_n_maiores(No** lista, int n) {
    if (*lista == NULL || n <= 0) return;
    int tamanho = obter_tamanho(*lista);
    if (n >= tamanho) {
        liberar_lista(lista);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (*lista == NULL) break;
        int maior = encontrar_maior(*lista);
        int pos_maior = buscar_por_valor(*lista, maior);
        remover_de_posicao(lista, pos_maior);
    }
}

// Liberar memória
void liberar_lista(No** lista) {
    No* atual = *lista;
    No* proximo_no;
    while (atual != NULL) {
        proximo_no = atual->proximo;
        free(atual);
        atual = proximo_no;
    }
    *lista = NULL;
}
