/**
 * @file Issue.h
 * @brief Declaração da classe Issue
*/

#ifndef ISSUE_H
#define ISSUE_H

#include "semiIssue.h"

/**
 * @class Issue
 * @brief Classe que representa uma tarefa completa
 * @details Esta classe herda da classe semiIssue e representa uma tarefa completa com ID, título, descrição, prioridade, dificuldade, data e quadro de tarefas.
 */

class Issue : public semiIssue {
private:
    int priority; /**< prioridade da tarefa */
    int difficult; /**< dificuldade da tarefa */
    std::string date; /**< data da tarefa */
    std::string board; /**< quadro de tarefas da tarefa */

public:
    /**
     * @brief Construtor da classe Issue
     * @param id id da tarefa
     * @param title título da tarefa
     * @param description descrição da tarefa
     * @param priority prioridade da tarefa
     * @param difficult dificuldade da tarefa
     * @param date data da tarefa
     * @param board quadro de tarefas da tarefa
     */
    Issue(int id, std::string title, std::string description, int priority, int difficult, std::string date, std::string board);
    /**
     * @brief getter da prioridade da tarefa
     */
    int getPriority();
    /**
     * @brief getter da dificuldade da tarefa
     */
    int getDifficult();
    /**
     * @brief getter da data da tarefa
     */
    std::string getDate();
    /**
     * @brief getter do quadro de tarefas da tarefa
     */
    std::string getBoard();
    /**
     * @brief setter da prioridade da tarefa
     * @param priority nova prioridade da tarefa
     */
    void setPriority(int priority);
    /**
     * @brief setter da dificuldade da tarefa
     * @param difficult nova dificuldade da tarefa
     */
    void setDifficult(int difficult);
    /**
     * @brief setter da data da tarefa
     * @param date nova data da tarefa
     */
    void setDate(std::string date);
    /**
     * @brief setter do quadro de tarefas da tarefa
     * @param board novo quadro de tarefas da tarefa
     */
    void setBoard(std::string board);
    /**
     * @brief função que imprime os dados da tarefa, herdado da classe semiIssue.
     */
    void printIssue();
};

#endif
