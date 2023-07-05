/**
 * @file semiIssue.cpp
 * @brief Implementação das funções da classe semiIssue
*/

#include "../include/semiIssue.h"
#include <iostream>

/**
 * @brief Construtor da classe semiIssue
 * @param id ID da tarefa
 * @param title Título da tarefa
 * @param description Descrição da tarefa
 */

semiIssue::semiIssue(int id, std::string title, std::string description)
    : id(id), title(title), description(description) {
}

/**
 * @brief Obtém o ID da tarefa
 * @return ID da tarefa
 */

int semiIssue::getId(){
    return id;
}

/**
 * @brief Obtém o título da tarefa
 * @return Título da tarefa
 */

std::string semiIssue::getTitle(){
    return title;
}

/**
 * @brief Obtém a descrição da tarefa
 * @return Descrição da tarefa
 */

std::string semiIssue::getDescription(){
    return description;
}

/**
 * @brief Define o título da tarefa
 * @param newTitle Novo título da tarefa
 */

void semiIssue::setTitle(std::string newTitle){
    title = newTitle;
}

/**
 * @brief Define a descrição da tarefa
 * @param newDescription Nova descrição da tarefa
 */

void semiIssue::setDescription(std::string newDescription){
    description = newDescription;
}

/**
 * @brief Imprime os dados da tarefa
 */

void semiIssue::printIssue(){
    std::cout << "Título: " << this->title << std::endl;
    std::cout << "Descrição: " << this->description << std::endl;
}