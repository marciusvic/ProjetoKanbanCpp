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
    std::vector<Issue> fazendoIssues; /**< vetor de tarefas em andamento */
    std::vector<Issue> emAnaliseIssues; /**< vetor de tarefas em análise */
    std::vector<Issue> testandoIssues; /**< vetor de tarefas em teste */
    std::vector<Issue> emPilotoIssues; /**< vetor de tarefas em piloto */
    std::vector<Issue> entregueIssues; /**< vetor de tarefas entregues */

public:
    /**
     * @brief Função responsável por criar uma tarefa
     */
    void createIssue(int id, std::string title, std::string description, int priority, int difficult, std::string date, std::string board);
    /**
     * @brief Função responsável por adicionar uma tarefa a um board.
     */
    template <typename T>
    void addIssue(Issue &issue, T &vector);
    /**
     * @brief Função responsável por remover uma tarefa de um board.
     */
    template <typename T>
    void removeIssue(int id, T &vector);
    /**
     * @brief Função responsável por apagar uma tarefa de um board.
     */
    void apagaIssue(int id);
    /**
     * @brief Função responsável por editar uma tarefa de um board.
     */
    void editaIssue(int id, int opcao);
    /**
     * @brief Função responsável por detalhar uma tarefa de um board.
     */
    void detalhaIssue(int id);
    /**
     * @brief Função de busca binária (recursiva) para encontrar uma tarefa em um board.
    */
    template <typename T>
    int buscaBinaria(int id, T &vector, int left, int right);
    /**
     * @brief Função de ordenação bubbleSort para organizar as tarefas por prioridade ou dificuldade.
    */
    template <typename T>
    void bubbleSort(std::vector<Issue> &vector, T compareFn);
    /**
     * @brief Função de ordenação insertionSort para organizar as tarefas por prioridade ou dificuldade.
    */
    template <typename T>
    void insertionSort(std::vector<Issue> &vector, T compareFn);
    /** 
     * @brief Função responsável por organizar as tarefas por prioridade.
     */
    void organizeByPriority();
    /** 
     * @brief Função responsável por organizar as tarefas por dificuldade.
     */
    void organizeByDifficulty();
    /**
     * @brief função responsável por mudar uma tarefa de board.
    */
    void mudaBoard();
    /**
     * @brief função responsável por alterar a propriedade de uma tarefa, para muda-la de board.
    */
    int alteraPropriedadeBoard(int id, std::string novaBoard);
    /**
     * @brief função responsável por imprimir o board.
    */
    void printBoard();
    /**
     * @brief Função responsável por salvar o board em um arquivo txt, ele salva primeiro o tamanho de cada vector, e após isso salva os dados em sequencia.
    */
    void salvaBoard();
    /**
     * @brief Função responsável por carregar o board de um arquivo txt, ele carrega primeiro o tamanho de cada vector, e após isso carrega os dados em sequencia.
    */
    int carregaBoard();
};

#endif
