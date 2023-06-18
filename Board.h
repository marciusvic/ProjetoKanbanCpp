#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Issue.h"

/**
 * @file Board.h
 * @brief Declaração da classe Board.
 */

class Board {
private:
    std::vector<Issue> issues;  // Coleção de Issues no quadro

public:
    /**
     * Construtor padrão da classe Board.
     */
    Board();

    /**
     * Adiciona uma nova Issue ao quadro.
     * 
     * @param issue A Issue a ser adicionada.
     */
    void addIssue(const Issue& issue);

    /**
     * Remove uma Issue do quadro com base no seu ID.
     * 
     * @param id O ID da Issue a ser removida.
     */
    void removeIssue(int id);

    /**
     * Organiza as Issues no quadro por prioridade.
     */
    void organizeByPriority();

    /**
     * Organiza as Issues no quadro por dificuldade.
     */
    void organizeByDifficulty();

    /**
     * Imprime o conteúdo do quadro, exibindo todas as Issues.
     */
    void printBoard();
};

#endif
