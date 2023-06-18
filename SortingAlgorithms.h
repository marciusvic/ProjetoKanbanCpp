#ifndef SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_H

/**
 * @file SortingAlgorithms.h
 * @brief Declaração das funções SortingAlgorithms
 * Algoritmo de ordenação por seleção (Selection Sort).
 * Ordena um array utilizando o algoritmo de ordenação por seleção.
 * @param arr O array a ser ordenado.
 * @param size O tamanho do array.
 */
template <typename T>
void selectionSort(T arr[], T size);

/**
 * Algoritmo de ordenação por bolha (Bubble Sort).
 * 
 * Ordena um array utilizando o algoritmo de ordenação por bolha.
 * 
 * @param arr O array a ser ordenado.
 * @param size O tamanho do array.
 */
template <typename T>
void bubbleSort(T arr[], T size);

#endif
