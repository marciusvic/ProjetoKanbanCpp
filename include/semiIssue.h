/**
 * @file semiIssue.h
 * @brief Declaração da classe semiIssue
 * 
*/
#ifndef SEMIISSUE_H
#define SEMIISSUE_H

#include <string>

/**
 * @class semiIssue
 * @brief Classe que representa uma tarefa parcial
*/

class semiIssue {
private:
    int id; /**< id da tarefa */
    std::string title; /**< título da tarefa */
    std::string description; /**< descrição da tarefa */

public:
    /**
     * @brief Construtor da classe semiIssue
     * @param id id da tarefa
     * @param title título da tarefa
     * @param description descrição da tarefa
    */
    semiIssue(int id, std::string title, std::string description);
    /**
     * @brief getter do id da tarefa
    */
    int getId();
    /**
     * @brief getter do título da tarefa
    */
    std::string getTitle();
    /**
     * @brief getter da descrição da tarefa
    */
    std::string getDescription();
    /**
     * @brief setter do título da tarefa
     * @param newTitle novo título da tarefa
    */
    void setTitle(std::string title);
    /**
     * @brief setter da descrição da tarefa
     * @param newDescription nova descrição da tarefa
    */
    void setDescription(std::string description);
    /**
     * @brief função que imprime os dados da tarefa, e pode ser passado para classe filha.
    */
    virtual void printIssue();
};

#endif
