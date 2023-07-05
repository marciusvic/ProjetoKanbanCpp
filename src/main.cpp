/**
 * @file main.cpp
 * @brief Programa principal para gerar um quadro de tarefas
 * @details Programa em C++ para gerar um quadro de tarefas, onde o usuário pode criar, editar, apagar e alterar a propriedade de uma tarefa.
 * @author Márcio Victor
 * @author 20210090869
 * @since 05/07/2023
 * @version 1.0
 */

#include <iostream>
#include "../include/Board.h"
#include "../include/strings.h"

/**
 * @brief Função principal
 * @details Função principal para gerar um quadro de tarefas, onde o usuário pode criar, editar, apagar e alterar a propriedade de uma tarefa. Além disso o usuário pode salvar os dados em um arquivo, e recuperar os dados desse arquivo.
 */

int main(){
    int id; 
    std::string title;
    std::string description;
    int priority;
    int difficult;
    std::string date;
    std::string board;
    int opcao = 0;
    Board quadroPrincipal;
/**
 * Carrega o quadro de tarefas a partir de um arquivo, se disponível, se não, cria um novo quadro.
*/
    strings(17);
    strings(18);
    std::cin >> opcao;
    if (opcao == 1){
        id = quadroPrincipal.carregaBoard();
    }
/**
 * Cria uma nova tarefa no backlog, se o usuário desejar.
*/
    if (opcao == 2){
        strings(1);
        strings(2);
        std::cin.ignore();
        std::getline(std::cin, title);
        strings(3);
        std::getline(std::cin, description);
        strings(4);
        std::cin >> priority;
        strings(5);
        std::cin >> difficult;
        strings(6);
        std::cin >> date;
        id = 1;
        board = "Backlog";
        quadroPrincipal.createIssue(id, title, description, priority, difficult, date, board);
        quadroPrincipal.detalhaIssue(id);
        strings(7);
    }
/**
 * Menu principal do programa, onde o usuário pode escolher o que deseja fazer.
*/
    while (true){
        strings(16);
        std::cin >> opcao;
/**
 * Cria uma nova tarefa no backlog, se o usuário desejar.
*/
        if (opcao == 1){
            strings(2);
            std::cin.ignore();
            std::getline(std::cin, title);
            strings(3);
            std::getline(std::cin, description);
            strings(4);
            std::cin >> priority;
            strings(5);
            std::cin >> difficult;
            strings(6);
            std::cin >> date;
            id = id + 1;
            board = "Backlog";
            quadroPrincipal.createIssue(id, title, description, priority, difficult, date, board);
            quadroPrincipal.detalhaIssue(id);
            strings(7);
            opcao = 0;
        }
/**
 * Mostra os detalhes de uma tarefa, se o usuário desejar.
*/
        if (opcao == 2){
            strings(8);
            std::cin >> id;
            quadroPrincipal.detalhaIssue(id);
            opcao = 0;
        }
/**
 * Move uma tarefa de uma board para outra, se o usuário desejar.
*/
        if (opcao == 3){
            strings(9);
            std::cin >> id;
            strings(10);
            std::cin >> opcao;
            if (opcao == 1){
                board = "Backlog";
            }
            if (opcao == 2){
                board = "Fazendo";
            }
            if (opcao == 3){
                board = "Em Análise";
            }
            if (opcao == 4){
                board = "Testando";
            }
            if (opcao == 5){
                board = "Em Piloto";
            }
            if (opcao == 6){
                board = "Entregue";
            }
            quadroPrincipal.alteraPropriedadeBoard(id, board);
            quadroPrincipal.printBoard();
            opcao = 0;
        }
/**
 * Edita uma tarefa, se o usuário desejar.
*/
        if (opcao == 4){
            strings(11);
            std::cin >> id;
            strings(12);
            std::cin >> opcao;
            if (opcao < 6)
            {
                quadroPrincipal.editaIssue(id, opcao);
                quadroPrincipal.detalhaIssue(id);
            }
            opcao = 0;
        }
/**
 * Apaga uma tarefa, se o usuário desejar.
*/
        if (opcao == 5){
            strings(13);
            std::cin >> id;
            quadroPrincipal.apagaIssue(id);
            opcao = 0;
        }
/**
 * Organiza as tarefas por prioridade, se o usuário desejar.
*/
        if (opcao == 6){
            quadroPrincipal.organizeByPriority();
            strings(14);
            quadroPrincipal.printBoard();
            opcao = 0;
        }
/**
 * Organiza as tarefas por dificuldade, se o usuário desejar.
*/
        if (opcao == 7){
            quadroPrincipal.organizeByDifficulty();
            strings(15);
            quadroPrincipal.printBoard();
            opcao = 0;
        }
/**
 * Imprime o quadro de tarefas, se o usuário desejar.
*/
        if (opcao == 8){
            quadroPrincipal.printBoard();
            opcao = 0;
        }
/**
 * Encerra o programa e salva o estado atual do quadro de tarefas, se o usuário desejar.
*/
        if (opcao == 9){
            quadroPrincipal.salvaBoard();
            break;
        }
    }
    return 0;
}