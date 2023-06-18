#ifndef SEARCHALGORITHMS_H
#define SEARCHALGORITHMS_H

/**
 * @file SearchAlgorithms.h
 * @brief Declaração das funções SearchAlgorithms
 * Função de busca binária recursiva.
 * Realiza uma busca binária recursiva em um array ordenado, procurando por um determinado valor.
 * @param arr O array no qual a busca será realizada.
 * @param target O valor a ser buscado.
 * @param left O índice esquerdo do intervalo de busca.
 * @param right O índice direito do intervalo de busca.
 * @return O índice do elemento encontrado, ou -1 se o elemento não for encontrado.
 */
template <typename T>
int recursiveBinarySearch(T arr[], T target, int left, int right);

/**
 * Função de busca binária iterativa.
 * 
 * Realiza uma busca binária iterativa em um array ordenado, procurando por um determinado valor.
 * 
 * @param arr O array no qual a busca será realizada.
 * @param target O valor a ser buscado.
 * @param left O índice esquerdo do intervalo de busca.
 * @param right O índice direito do intervalo de busca.
 * @return O índice do elemento encontrado, ou -1 se o elemento não for encontrado.
 */
template <typename T>
int iterativeBinarySearch(T arr[], T target, int left, int right);

#endif
