#ifndef ISSUE_H
#define ISSUE_H

#include <string>

/**
 * @file Issue.h
 * @brief Declaração da classe Issue.
 */

class Issue {
private:
    int id;                     // ID da Issue
    std::string title;          // Título da Issue
    std::string description;    // Descrição da Issue
    int priority;               // Prioridade da Issue
    int difficulty;             // Dificuldade da Issue
    std::string date;           // Data da Issue

public:
    /**
     * Construtor da classe Issue.
     * 
     * @param id O ID da Issue.
     * @param title O título da Issue.
     * @param description A descrição da Issue.
     * @param priority A prioridade da Issue.
     * @param difficulty A dificuldade da Issue.
     * @param date A data da Issue.
     */
    Issue(int id, const std::string& title, const std::string& description, int priority, int difficulty, const std::string& date);

    /**
     * Obtém o ID da Issue.
     * 
     * @return O ID da Issue.
     */
    int getId() const;

    /**
     * Obtém o título da Issue.
     * 
     * @return O título da Issue.
     */
    std::string getTitle() const;

    /**
     * Obtém a descrição da Issue.
     * 
     * @return A descrição da Issue.
     */
    std::string getDescription() const;

    /**
     * Obtém a prioridade da Issue.
     * 
     * @return A prioridade da Issue.
     */
    int getPriority() const;

    /**
     * Obtém a dificuldade da Issue.
     * 
     * @return A dificuldade da Issue.
     */
    int getDifficulty() const;

    /**
     * Obtém a data da Issue.
     * 
     * @return A data da Issue.
     */
    std::string getDate() const;

    /**
     * Define o ID da Issue.
     * 
     * @param id O ID da Issue.
     */
    void setId(int id);

    /**
     * Define o título da Issue.
     * 
     * @param title O título da Issue.
     */
    void setTitle(const std::string& title);

    /**
     * Define a descrição da Issue.
     * 
     * @param description A descrição da Issue.
     */
    void setDescription(const std::string& description);

    /**
     * Define a prioridade da Issue.
     * 
     * @param priority A prioridade da Issue.
     */
    void setPriority(int priority);

    /**
     * Define a dificuldade da Issue.
     * 
     * @param difficulty A dificuldade da Issue.
     */
    void setDifficulty(int difficulty);

    /**
     * Define a data da Issue.
     * 
     * @param date A data da Issue.
     */
    void setDate(const std::string& date);
};

#endif
