#ifndef STACK_H
#define STACK_H

#include <vector>

/**
 * @file Stack.h
 * @brief Declaração da classe Stack.
 */
class Stack {
private:
    std::vector<int> elements; // Vetor para armazenar os elementos da pilha

public:
    /**
     * Empilha um elemento na pilha.
     * 
     * @param value O valor a ser empilhado.
     */
    void push(int value);

    /**
     * Desempilha o elemento do topo da pilha.
     */
    void pop();

    /**
     * Retorna o elemento do topo da pilha sem removê-lo.
     * 
     * @return O elemento do topo da pilha.
     */
    int top() const;

    /**
     * Verifica se a pilha está vazia.
     * 
     * @return true se a pilha estiver vazia, false caso contrário.
     */
    bool isEmpty() const;

    /**
     * Retorna o tamanho da pilha.
     * 
     * @return O número de elementos na pilha.
     */
    int size() const;
};

#endif
