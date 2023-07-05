/**
 * @file Board.h
 * @brief Declaração da classe Board
 */

#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include "Issue.h"

/**
 * @class Board
 * @brief Classe que representa um quadro de tarefas
*/

class Board{
private:
    std::vector<Issue> backlogIssues; /**< vetor de tarefas do backlog */
    std::vector<Issue> emAnaliseIssues; /**< vetor de tarefas em análise */
    std::vector<Issue> testandoIssues; /**< vetor de tarefas em teste */
    std::vector<Issue> emPilotoIssues; /**< vetor de tarefas em piloto */
    std::vector<Issue> entregueIssues; /**< vetor de tarefas entregues */

public:
    /**
     * @brief Construtor da classe Board
     */
    void createIssue(int id, std::string title, std::string description, int priority, int difficult, std::string date, std::string board);
    
    template <typename T>
    void addIssue(Issue &issue, T &vector);
    template <typename T>
    void removeIssue(int id, T &vector);
    void apagaIssue(int id);
    void editaIssue(int id, int opcao);
    void detalhaIssue(int id);
    template <typename T>
    int buscaBinaria(int id, T &vector, int left, int right);
    template <typename T>
    void bubbleSort(std::vector<Issue> &vector, T compareFn);
    template <typename T>
    void insertionSort(std::vector<Issue> &vector, T compareFn);
    void organizeByPriority();
    void organizeByDifficulty();
    void mudaBoard();
    int alteraPropriedadeBoard(int id, std::string novaBoard);
    void printBoard();
    void salvaBoard();
    int carregaBoard();
};

#endif
