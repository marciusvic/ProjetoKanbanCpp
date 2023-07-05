/**
 * @file Issue.cpp
 * @brief Implementação das funções da classe Issue
*/

#include "../include/Issue.h"
#include <iostream>

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

Issue::Issue(int id, std::string title, std::string description, int priority, int difficult, std::string date, std::string board)
    : semiIssue(id, title, description), priority(priority), difficult(difficult), date(date), board(board) {
}
/**
 * @brief getter da prioridade da tarefa
 */
int Issue::getPriority(){
    return priority;
}
/**
 * @brief getter da dificuldade da tarefa
 */
int Issue::getDifficult(){
    return difficult;
}
/**
 * @brief getter da data da tarefa
 */
std::string Issue::getDate(){
    return date;
}
/**
 * @brief getter do quadro de tarefas da tarefa
 */
std::string Issue::getBoard(){
    return board;
}
/**
 * @brief setter da prioridade da tarefa
 * @param priority nova prioridade da tarefa
 */
void Issue::setPriority(int priority){
    this->priority = priority;
}
/**
 * @brief setter da dificuldade da tarefa
 * @param difficult nova dificuldade da tarefa
 */
void Issue::setDifficult(int difficult){
    this->difficult = difficult;
}
/**
 * @brief setter da data da tarefa
 * @param date nova data da tarefa
 */
void Issue::setDate(std::string date){
    this->date = date;
}
/**
 * @brief setter do quadro de tarefas da tarefa
 * @param board novo quadro de tarefas da tarefa
 */
void Issue::setBoard(std::string board){
    this->board = board;
}
/**
 * @brief função que imprime os dados da tarefa, herdado da classe semiIssue.
 */
void Issue::printIssue(){
    semiIssue::printIssue();
    std::cout << "Prioridade: " << this->priority << std::endl;
    std::cout << "Dificuldade: " << this->difficult << std::endl;
    std::cout << "Data: " << this->date << std::endl;
    std::cout << "Board: " << this->board << std::endl;
}