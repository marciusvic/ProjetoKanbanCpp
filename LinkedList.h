#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h" // Incluindo o arquivo de definição da classe Node

/**
 * @file LinkedList.h
 * @brief Declaração da classe LinkedList.
 */

class LinkedList {
private:
    Node* head; // Ponteiro para o primeiro nó da lista

public:
    /**
     * Construtor da classe LinkedList.
     */
    LinkedList();

    /**
     * Destrutor da classe LinkedList.
     */
    ~LinkedList();

    /**
     * Insere um valor na lista.
     * 
     * @param value O valor a ser inserido.
     */
    void insert(int value);

    /**
     * Remove um valor da lista.
     * 
     * @param value O valor a ser removido.
     */
    void remove(int value);

    /**
     * Verifica se um valor está na lista.
     * 
     * @param value O valor a ser verificado.
     * @return true se o valor está na lista, false caso contrário.
     */
    bool search(int value);

    /**
     * Verifica se a lista está vazia.
     * 
     * @return true se a lista está vazia, false caso contrário.
     */
    bool isEmpty();

    /**
     * Retorna o tamanho da lista.
     * 
     * @return O tamanho da lista.
     */
    int getSize();
};

#endif
