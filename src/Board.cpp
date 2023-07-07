/**
 * @file Board.cpp
 * @brief Implementação das funções da classe Board
 */

#include "../include/Board.h"
#include <iostream>
#include <fstream>

/**
 * @brief Função responsável por criar uma nova tarefa, e adiciona-la a backlogIssues(no primeiro momento)
 */

void Board::createIssue(int id, std::string title, std::string description, int priority, int difficult, std::string date, std::string board){
    Issue issue(id, title, description, priority, difficult, date, board);
    this->backlogIssues.push_back(issue);
}
/**
 * @brief Função responsável por adicionar uma tarefa a um determinado vetor
 * @param issue Tarefa a ser adicionada
 * @param vector Vetor(template) a ser adicionado a tarefa
*/
template <typename T>
void Board::addIssue(Issue &issue, T &vector){
    vector.push_back(issue);
}
/**
 * @brief Função de busca binária
 * @param id Id da tarefa a ser buscada
 * @param vector Vetor(template) a ser buscado
 * @param left Posição inicial do vetor
 * @param right Posição final do vetor
*/
template <typename T>
int Board::buscaBinaria(int id, T &vector, int left, int right){
    if (right >= left){
        int mid = left + (right - left) / 2;

        if (vector[mid].getId() == id){
            return mid;
        }

        if (vector[mid].getId() > id){
            return buscaBinaria(id, vector, left, mid - 1);
        }

        return buscaBinaria(id, vector, mid + 1, right);
    }

    return -1;
}
/**
 * @brief Função responsável por remover uma tarefa de um determinado vetor
 * @param id Id da tarefa a ser removida
 * @param vector Vetor(template) a ser removido a tarefa
*/
template <typename T>
void Board::removeIssue(int id, T &vector){
    int index = buscaBinaria(id, vector, 0, vector.size() - 1);
    if (index != -1){
        vector.erase(vector.begin() + index);
    }
}
/**
 * @brief Função responsável por apagar uma tarefa de todos os vetores, ele chama a função removeIssue para cada vetor, e assim apagando a tarefa de todos os vetores, ele faz uma dupla verificação, visto que na buscabinária ele busca o id, e se nao encontrar ele retorna -1, já aqui é garantido que ele não vai retornar -1, pois ele já passou por todos os vetores, e se não encontrou, é porque não existe.
 * @param id Id da tarefa a ser apagada
*/
void Board::apagaIssue(int id){
    for (int i = 0; i < backlogIssues.size(); i++){
        if (backlogIssues[i].getId() == id){
            removeIssue(id, backlogIssues);
        }
    }
    for (int i = 0; i < fazendoIssues.size(); i++){
        if (fazendoIssues[i].getId() == id){
            removeIssue(id, fazendoIssues);
        }
    }
    for (int i = 0; i < emAnaliseIssues.size(); i++){
        if (emAnaliseIssues[i].getId() == id){
            removeIssue(id, emAnaliseIssues);
        }
    }
    for (int i = 0; i < testandoIssues.size(); i++){
        if (testandoIssues[i].getId() == id){
            removeIssue(id, testandoIssues);
        }
    }
    for (int i = 0; i < emPilotoIssues.size(); i++){
        if (emPilotoIssues[i].getId() == id){
            removeIssue(id, emPilotoIssues);
        }
    }
    for (int i = 0; i < entregueIssues.size(); i++){
        if (entregueIssues[i].getId() == id){
            removeIssue(id, entregueIssues);
        }
    }
}
/**
 * @brief Função responsável por editar uma tarefa, novamente ele faz uma varredura pelo id da tarefa em cada board, e se encontrar ele edita a tarefa, ele faz uma verificação de qual opção o usuário escolheu, e assim editando a tarefa.
 * @param id Id da tarefa a ser editada
 * @param opcao Opção escolhida pelo usuário
*/
void Board::editaIssue(int id, int opcao){
    std::string title;
    std::string description;
    int priority;
    int difficult;
    std::string date;
    for (int i = 0; i < backlogIssues.size(); i++){
        if (backlogIssues[i].getId() == id){
            if (opcao == 1){
                std::cout << "Digite o novo título: " << std::endl;
                std::cin.ignore();
                std::getline(std::cin, title);
                backlogIssues[i].setTitle(title);
            }
            if (opcao == 2){
                std::cout << "Digite a nova descrição: " << std::endl;
                std::cin.ignore();
                std::getline(std::cin, description);
                backlogIssues[i].setDescription(description);
            }
            if (opcao == 3){
                std::cout << "Digite a nova prioridade: " << std::endl;
                std::cin >> priority;
                backlogIssues[i].setPriority(priority);
            }
            if (opcao == 4){
                std::cout << "Digite a nova dificuldade: " << std::endl;
                std::cin >> difficult;
                backlogIssues[i].setDifficult(difficult);
            }
            if (opcao == 5){
                std::cout << "Digite a nova data: " << std::endl;
                std::cin >> date;
                backlogIssues[i].setDate(date);
            }
        }
    }
    for (int i = 0; i < fazendoIssues.size(); i++){
        if (fazendoIssues[i].getId() == id){
            if (opcao == 1){
                std::cout << "Digite o novo título: " << std::endl;
                std::cin.ignore();
                std::getline(std::cin, title);
                fazendoIssues[i].setTitle(title);
            }
            if (opcao == 2){
                std::cout << "Digite a nova descrição: " << std::endl;
                std::cin.ignore();
                std::getline(std::cin, description);
                fazendoIssues[i].setDescription(description);
            }
            if (opcao == 3){
                std::cout << "Digite a nova prioridade: " << std::endl;
                std::cin >> priority;
                fazendoIssues[i].setPriority(priority);
            }
            if (opcao == 4){
                std::cout << "Digite a nova dificuldade: " << std::endl;
                std::cin >> difficult;
                fazendoIssues[i].setDifficult(difficult);
            }
            if (opcao == 5){
                std::cout << "Digite a nova data: " << std::endl;
                std::cin >> date;
                fazendoIssues[i].setDate(date);
            }
        }
    }
    for (int i = 0; i < emAnaliseIssues.size(); i++){
        if (emAnaliseIssues[i].getId() == id){
            if (opcao == 1){
                std::cout << "Digite o novo título: " << std::endl;
                std::cin.ignore();
                std::getline(std::cin, title);
                emAnaliseIssues[i].setTitle(title);
            }
            if (opcao == 2){
                std::cout << "Digite a nova descrição: " << std::endl;
                std::cin.ignore();
                std::getline(std::cin, description);
                emAnaliseIssues[i].setDescription(description);
            }
            if (opcao == 3){
                std::cout << "Digite a nova prioridade: " << std::endl;
                std::cin >> priority;
                emAnaliseIssues[i].setPriority(priority);
            }
            if (opcao == 4){
                std::cout << "Digite a nova dificuldade: " << std::endl;
                std::cin >> difficult;
                emAnaliseIssues[i].setDifficult(difficult);
            }
            if (opcao == 5){
                std::cout << "Digite a nova data: " << std::endl;
                std::cin >> date;
                emAnaliseIssues[i].setDate(date);
            }
        }
    }
    for (int i = 0; i < testandoIssues.size(); i++){
        if (testandoIssues[i].getId() == id){
            if (opcao == 1){
                std::cout << "Digite o novo título: " << std::endl;
                std::cin.ignore();
                std::getline(std::cin, title);
                testandoIssues[i].setTitle(title);
            }
            if (opcao == 2){
                std::cout << "Digite a nova descrição: " << std::endl;
                std::cin.ignore();
                std::getline(std::cin, description);
                testandoIssues[i].setDescription(description);
            }
            if (opcao == 3){
                std::cout << "Digite a nova prioridade: " << std::endl;
                std::cin >> priority;
                testandoIssues[i].setPriority(priority);
            }
            if (opcao == 4){
                std::cout << "Digite a nova dificuldade: " << std::endl;
                std::cin >> difficult;
                testandoIssues[i].setDifficult(difficult);
            }
            if (opcao == 5){
                std::cout << "Digite a nova data: " << std::endl;
                std::cin >> date;
                testandoIssues[i].setDate(date);
            }
        }
    }
    for (int i = 0; i < emPilotoIssues.size(); i++){
        if (emPilotoIssues[i].getId() == id){
            if (opcao == 1){
                std::cout << "Digite o novo título: " << std::endl;
                std::cin.ignore();
                std::getline(std::cin, title);
                emPilotoIssues[i].setTitle(title);
            }
            if (opcao == 2){
                std::cout << "Digite a nova descrição: " << std::endl;
                std::cin.ignore();
                std::getline(std::cin, description);
                emPilotoIssues[i].setDescription(description);
            }
            if (opcao == 3){
                std::cout << "Digite a nova prioridade: " << std::endl;
                std::cin >> priority;
                emPilotoIssues[i].setPriority(priority);
            }
            if (opcao == 4){
                std::cout << "Digite a nova dificuldade: " << std::endl;
                std::cin >> difficult;
                emPilotoIssues[i].setDifficult(difficult);
            }
            if (opcao == 5){
                std::cout << "Digite a nova data: " << std::endl;
                std::cin >> date;
                emPilotoIssues[i].setDate(date);
            }
        }
    }
    for (int i = 0; i < entregueIssues.size(); i++){
        if (entregueIssues[i].getId() == id){
            if (opcao == 1){
                std::cout << "Digite o novo título: " << std::endl;
                std::cin.ignore();
                std::getline(std::cin, title);
                entregueIssues[i].setTitle(title);
            }
            if (opcao == 2){
                std::cout << "Digite a nova descrição: " << std::endl;
                std::cin.ignore();
                std::getline(std::cin, description);
                entregueIssues[i].setDescription(description);
            }
            if (opcao == 3){
                std::cout << "Digite a nova prioridade: " << std::endl;
                std::cin >> priority;
                entregueIssues[i].setPriority(priority);
            }
            if (opcao == 4){
                std::cout << "Digite a nova dificuldade: " << std::endl;
                std::cin >> difficult;
                entregueIssues[i].setDifficult(difficult);
            }
            if (opcao == 5){
                std::cout << "Digite a nova data: " << std::endl;
                std::cin >> date;
                entregueIssues[i].setDate(date);
            }
        }
    }
}
/**
 * @brief Função responsável por detalhar uma tarefa, ele faz uma varredura pelo id da tarefa em cada board, e se encontrar ele "printa" a tarefa usando a função de polimorfismo.
*/
void Board::detalhaIssue(int id){
    for (int i = 0; i < backlogIssues.size(); i++){
        if (backlogIssues[i].getId() == id){
            backlogIssues[i].printIssue();
        }
    }
    for (int i = 0; i < fazendoIssues.size(); i++){
        if (fazendoIssues[i].getId() == id){
            fazendoIssues[i].printIssue();
        }
    }
    for (int i = 0; i < emAnaliseIssues.size(); i++){
        if (emAnaliseIssues[i].getId() == id){
            emAnaliseIssues[i].printIssue();
        }
    }
    for (int i = 0; i < testandoIssues.size(); i++){
        if (testandoIssues[i].getId() == id){
            testandoIssues[i].printIssue();
        }
    }
    for (int i = 0; i < emPilotoIssues.size(); i++){
        if (emPilotoIssues[i].getId() == id){
            emPilotoIssues[i].printIssue();
        }
    }
    for (int i = 0; i < entregueIssues.size(); i++){
        if (entregueIssues[i].getId() == id){
            entregueIssues[i].printIssue();
        }
    }
}
/**
 * @brief Função de ordenação bubbleSort para organizar as tarefas por prioridade ou dificuldade.
 * @param vector Vetor(template) a ser ordenado
 * @param compareFn Função de comparação
*/
template <typename T>
void Board::bubbleSort(std::vector<Issue> &vector, T compareFn){
    int n = vector.size();
    bool swapped;

    for (int i = 0; i < n - 1; ++i){
        swapped = false;

        for (int j = 0; j < n - i - 1; ++j){
            if (compareFn(vector[j], vector[j + 1])){
                std::swap(vector[j], vector[j + 1]);
                swapped = true;
            }
        }

        if (!swapped){
            break;
        }
    }
}
/**
 * @brief Função de ordenação insertionSort para organizar as tarefas por prioridade ou dificuldade.
 * @param vector Vetor(template) a ser ordenado
 * @param compareFn Função de comparação
*/
template <typename T>
void Board::insertionSort(std::vector<Issue> &vector, T compareFn){
    int n = vector.size();

    for (int i = 1; i < n; ++i){
        Issue key = vector[i];
        int j = i - 1;

        while (j >= 0 && compareFn(vector[j], key))
        {
            vector[j + 1] = vector[j];
            --j;
        }

        vector[j + 1] = key;
    }
}
/**
 * @brief Função responsável por organizar as tarefas por prioridade, ele chama a função bubbleSort para cada vetor, e assim organizando as tarefas por prioridade.
*/
void Board::organizeByPriority(){
    auto compareFn = [](Issue &a, Issue &b){
        return a.getPriority() > b.getPriority();
    };

    bubbleSort(backlogIssues, compareFn);
    bubbleSort(fazendoIssues, compareFn);
    bubbleSort(emAnaliseIssues, compareFn);
    bubbleSort(testandoIssues, compareFn);
    bubbleSort(emPilotoIssues, compareFn);
    bubbleSort(entregueIssues, compareFn);
}
/**
 * @brief Função responsável por organizar as tarefas por dificuldade, ele chama a função insertionSort para cada vetor, e assim organizando as tarefas por dificuldade.
*/
void Board::organizeByDifficulty()
{
    auto compareFn = [](Issue &a, Issue &b){
        return a.getDifficult() > b.getDifficult();
    };

    insertionSort(backlogIssues, compareFn);
    insertionSort(fazendoIssues, compareFn);
    insertionSort(emAnaliseIssues, compareFn);
    insertionSort(testandoIssues, compareFn);
    insertionSort(emPilotoIssues, compareFn);
    insertionSort(entregueIssues, compareFn);
}
/**
 * @brief Função responsável por alterar a propriedade de uma tarefa, para muda-la de board, em primeiro passo ele verifica em cada vector se a propriedade "board" de cada Issue condiz com a board que ele está, se nao condizer, ele verifica o board que pertence e colocar no vector correto, essa função será usada dentro da função que altera a propriedade board de uma Issue.
*/
void Board::mudaBoard(){
    for (int i = 0; i < backlogIssues.size(); i++){
        if (backlogIssues[i].getBoard() != "Backlog"){
            if (backlogIssues[i].getBoard() == "Fazendo"){
                fazendoIssues.push_back(backlogIssues[i]);
                removeIssue(backlogIssues[i].getId(), backlogIssues);
            }
            if (backlogIssues[i].getBoard() == "Em Análise"){
                emAnaliseIssues.push_back(backlogIssues[i]);
                removeIssue(backlogIssues[i].getId(), backlogIssues);
            }
            if (backlogIssues[i].getBoard() == "Testando"){
                testandoIssues.push_back(backlogIssues[i]);
                removeIssue(backlogIssues[i].getId(), backlogIssues);
            }
            if (backlogIssues[i].getBoard() == "Em Piloto"){
                emPilotoIssues.push_back(backlogIssues[i]);
                removeIssue(backlogIssues[i].getId(), backlogIssues);
            }
            if (backlogIssues[i].getBoard() == "Entregue"){
                entregueIssues.push_back(backlogIssues[i]);
                removeIssue(backlogIssues[i].getId(), backlogIssues);
            }
        }
    }
    for (int i = 0; i < fazendoIssues.size(); i++){
        if (fazendoIssues[i].getBoard() != "Fazendo"){
            if (fazendoIssues[i].getBoard() == "Backlog"){
                backlogIssues.push_back(fazendoIssues[i]);
                removeIssue(fazendoIssues[i].getId(), fazendoIssues);
            }
            if (fazendoIssues[i].getBoard() == "Em Análise"){
                emAnaliseIssues.push_back(fazendoIssues[i]);
                removeIssue(fazendoIssues[i].getId(), fazendoIssues);
            }
            if (fazendoIssues[i].getBoard() == "Testando"){
                testandoIssues.push_back(fazendoIssues[i]);
                removeIssue(fazendoIssues[i].getId(), fazendoIssues);
            }
            if (fazendoIssues[i].getBoard() == "Em Piloto"){
                emPilotoIssues.push_back(fazendoIssues[i]);
                removeIssue(fazendoIssues[i].getId(), fazendoIssues);
            }
            if (fazendoIssues[i].getBoard() == "Entregue"){
                entregueIssues.push_back(fazendoIssues[i]);
                removeIssue(fazendoIssues[i].getId(), fazendoIssues);
            }
        }
    }
    for (int i = 0; i < emAnaliseIssues.size(); i++){
        if (emAnaliseIssues[i].getBoard() != "Em Análise"){
            if (emAnaliseIssues[i].getBoard() == "Backlog"){
                backlogIssues.push_back(emAnaliseIssues[i]);
                removeIssue(emAnaliseIssues[i].getId(), emAnaliseIssues);
            }
            if (emAnaliseIssues[i].getBoard() == "Fazendo"){
                fazendoIssues.push_back(emAnaliseIssues[i]);
                removeIssue(emAnaliseIssues[i].getId(), emAnaliseIssues);
            }
            if (emAnaliseIssues[i].getBoard() == "Testando"){
                testandoIssues.push_back(emAnaliseIssues[i]);
                removeIssue(emAnaliseIssues[i].getId(), emAnaliseIssues);
            }
            if (emAnaliseIssues[i].getBoard() == "Em Piloto"){
                emPilotoIssues.push_back(emAnaliseIssues[i]);
                removeIssue(emAnaliseIssues[i].getId(), emAnaliseIssues);
            }
            if (emAnaliseIssues[i].getBoard() == "Entregue"){
                entregueIssues.push_back(emAnaliseIssues[i]);
                removeIssue(emAnaliseIssues[i].getId(), emAnaliseIssues);
            }
        }
    }
    for (int i = 0; i < testandoIssues.size(); i++){
        if (testandoIssues[i].getBoard() != "Testando"){
            if (testandoIssues[i].getBoard() == "Backlog"){
                backlogIssues.push_back(testandoIssues[i]);
                removeIssue(testandoIssues[i].getId(), testandoIssues);
            }
            if (testandoIssues[i].getBoard() == "Fazendo"){
                fazendoIssues.push_back(testandoIssues[i]);
                removeIssue(testandoIssues[i].getId(), testandoIssues);
            }
            if (testandoIssues[i].getBoard() == "Em Análise"){
                emAnaliseIssues.push_back(testandoIssues[i]);
                removeIssue(testandoIssues[i].getId(), testandoIssues);
            }
            if (testandoIssues[i].getBoard() == "Em Piloto"){
                emPilotoIssues.push_back(testandoIssues[i]);
                removeIssue(testandoIssues[i].getId(), testandoIssues);
            }
            if (testandoIssues[i].getBoard() == "Entregue"){
                entregueIssues.push_back(testandoIssues[i]);
                removeIssue(testandoIssues[i].getId(), testandoIssues);
            }
        }
    }
    for (int i = 0; i < emPilotoIssues.size(); i++){
        if (emPilotoIssues[i].getBoard() != "Em Piloto"){
            if (emPilotoIssues[i].getBoard() == "Backlog"){
                backlogIssues.push_back(emPilotoIssues[i]);
                removeIssue(emPilotoIssues[i].getId(), emPilotoIssues);
            }
            if (emPilotoIssues[i].getBoard() == "Fazendo"){
                fazendoIssues.push_back(emPilotoIssues[i]);
                removeIssue(emPilotoIssues[i].getId(), emPilotoIssues);
            }
            if (emPilotoIssues[i].getBoard() == "Em Análise"){
                emAnaliseIssues.push_back(emPilotoIssues[i]);
                removeIssue(emPilotoIssues[i].getId(), emPilotoIssues);
            }
            if (emPilotoIssues[i].getBoard() == "Testando"){
                testandoIssues.push_back(emPilotoIssues[i]);
                removeIssue(emPilotoIssues[i].getId(), emPilotoIssues);
            }
            if (emPilotoIssues[i].getBoard() == "Entregue"){
                entregueIssues.push_back(emPilotoIssues[i]);
                removeIssue(emPilotoIssues[i].getId(), emPilotoIssues);
            }
        }
    }
    for (int i = 0; i < entregueIssues.size(); i++){
        if (entregueIssues[i].getBoard() != "Entregue"){
            if (entregueIssues[i].getBoard() == "Backlog"){
                backlogIssues.push_back(entregueIssues[i]);
                removeIssue(entregueIssues[i].getId(), entregueIssues);
            }
            if (entregueIssues[i].getBoard() == "Fazendo"){
                fazendoIssues.push_back(entregueIssues[i]);
                removeIssue(entregueIssues[i].getId(), entregueIssues);
            }
            if (entregueIssues[i].getBoard() == "Em Análise"){
                emAnaliseIssues.push_back(entregueIssues[i]);
                removeIssue(entregueIssues[i].getId(), entregueIssues);
            }
            if (entregueIssues[i].getBoard() == "Testando"){
                testandoIssues.push_back(entregueIssues[i]);
                removeIssue(entregueIssues[i].getId(), entregueIssues);
            }
            if (entregueIssues[i].getBoard() == "Em Piloto"){
                emPilotoIssues.push_back(entregueIssues[i]);
                removeIssue(entregueIssues[i].getId(), entregueIssues);
            }
        }
    }
}
/**
 * @brief Essa função é a responsável de alterar a propriedade 'board' de uma Issue específica, ele chama a função mudaBoard() após alterar a propriedade, organizando assim cada issue em sua respectiva board.
 * @param id Id da tarefa a ser alterada
 * @param novaBoard Nova board a ser alterada
*/
int Board::alteraPropriedadeBoard(int id, std::string novaBoard){
    for (int i = 0; i < backlogIssues.size(); i++){
        if (backlogIssues[i].getId() == id){
            backlogIssues[i].setBoard(novaBoard);
            mudaBoard();
            return 0;
        }
    }
    for (int i = 0; i < fazendoIssues.size(); i++){
        if (fazendoIssues[i].getId() == id){
            fazendoIssues[i].setBoard(novaBoard);
            mudaBoard();
            return 0;
        }
    }
    for (int i = 0; i < emAnaliseIssues.size(); i++){
        if (emAnaliseIssues[i].getId() == id){
            emAnaliseIssues[i].setBoard(novaBoard);
            mudaBoard();
            return 0;
        }
    }
    for (int i = 0; i < testandoIssues.size(); i++){
        if (testandoIssues[i].getId() == id){
            testandoIssues[i].setBoard(novaBoard);
            mudaBoard();
            return 0;
        }
    }
    for (int i = 0; i < emPilotoIssues.size(); i++){
        if (emPilotoIssues[i].getId() == id){
            emPilotoIssues[i].setBoard(novaBoard);
            mudaBoard();
            return 0;
        }
    }
    for (int i = 0; i < entregueIssues.size(); i++){
        if (entregueIssues[i].getId() == id){
            entregueIssues[i].setBoard(novaBoard);
            mudaBoard();
            return 0;
        }
    }
    return 0;
}
/**
 * @brief Função responsável por printar o board, ele printa cada vetor, e assim printando o board inteiro.
*/
void Board::printBoard(){
    std::cout << "== Backlog =="
              << "\t"
              << "== Fazendo =="
              << "\t"
              << "== Em Análise =="
              << "\t"
              << "== Testando =="
              << "\t"
              << "== Em Piloto =="
              << "\t"
              << "== Entregue ==" << std::endl;

    int maxIssues = std::max(backlogIssues.size(), std::max(fazendoIssues.size(), std::max(emAnaliseIssues.size(), std::max(testandoIssues.size(), std::max(emPilotoIssues.size(), entregueIssues.size())))));

    for (int i = 0; i < maxIssues; i++){
        if (i < backlogIssues.size()){
            std::cout << "#" << backlogIssues[i].getId() << " " << backlogIssues[i].getTitle() << "\t\t";
        }
        else{
            std::cout << "\t\t";
        }

        if (i < fazendoIssues.size()){
            std::cout << "#" << fazendoIssues[i].getId() << " " << fazendoIssues[i].getTitle() << "\t\t";
        }
        else{
            std::cout << "\t\t";
        }

        if (i < emAnaliseIssues.size()){
            std::cout << "#" << emAnaliseIssues[i].getId() << " " << emAnaliseIssues[i].getTitle() << "\t\t";
        }
        else{
            std::cout << "\t\t";
        }

        if (i < testandoIssues.size()){
            std::cout << "#" << testandoIssues[i].getId() << " " << testandoIssues[i].getTitle() << "\t\t";
        }
        else{
            std::cout << "\t\t";
        }

        if (i < emPilotoIssues.size()){
            std::cout << "#" << emPilotoIssues[i].getId() << " " << emPilotoIssues[i].getTitle() << "\t\t";
        }
        else{
            std::cout << "\t\t";
        }

        if (i < entregueIssues.size()){
            std::cout << "#" << entregueIssues[i].getId() << " " << entregueIssues[i].getTitle();
        }

        std::cout << std::endl;
    }
    std::cout << "=======================================================================================================" << std::endl;
}
/**
 * @brief Função responsável por salvar o board em um arquivo txt, ele salva primeiro o tamanho de cada vector, e após isso salva os dados em sequencia.
*/
void Board::salvaBoard(){
    std::ofstream arquivoSaida("../data/quadroPrincipal.txt");

    if (arquivoSaida.is_open()){
        arquivoSaida << backlogIssues.size() << "\n";
        for (int i = 0; i < backlogIssues.size(); i++){
            arquivoSaida << backlogIssues[i].getId() << "\n";
            arquivoSaida << backlogIssues[i].getTitle() << "\n";
            arquivoSaida << backlogIssues[i].getDescription() << "\n";
            arquivoSaida << backlogIssues[i].getPriority() << "\n";
            arquivoSaida << backlogIssues[i].getDifficult() << "\n";
            arquivoSaida << backlogIssues[i].getDate() << "\n";
            arquivoSaida << backlogIssues[i].getBoard() << "\n";
        }
        arquivoSaida << fazendoIssues.size() << "\n";
        for (int i = 0; i < fazendoIssues.size(); i++){
            arquivoSaida << fazendoIssues[i].getId() << "\n";
            arquivoSaida << fazendoIssues[i].getTitle() << "\n";
            arquivoSaida << fazendoIssues[i].getDescription() << "\n";
            arquivoSaida << fazendoIssues[i].getPriority() << "\n";
            arquivoSaida << fazendoIssues[i].getDifficult() << "\n";
            arquivoSaida << fazendoIssues[i].getDate() << "\n";
            arquivoSaida << fazendoIssues[i].getBoard() << "\n";
        }
        arquivoSaida << emAnaliseIssues.size() << "\n";
        for (int i = 0; i < emAnaliseIssues.size(); i++){
            arquivoSaida << emAnaliseIssues[i].getId() << "\n";
            arquivoSaida << emAnaliseIssues[i].getTitle() << "\n";
            arquivoSaida << emAnaliseIssues[i].getDescription() << "\n";
            arquivoSaida << emAnaliseIssues[i].getPriority() << "\n";
            arquivoSaida << emAnaliseIssues[i].getDifficult() << "\n";
            arquivoSaida << emAnaliseIssues[i].getDate() << "\n";
            arquivoSaida << emAnaliseIssues[i].getBoard() << "\n";
        }
        arquivoSaida << testandoIssues.size() << "\n";
        for (int i = 0; i < testandoIssues.size(); i++){
            arquivoSaida << testandoIssues[i].getId() << "\n";
            arquivoSaida << testandoIssues[i].getTitle() << "\n";
            arquivoSaida << testandoIssues[i].getDescription() << "\n";
            arquivoSaida << testandoIssues[i].getPriority() << "\n";
            arquivoSaida << testandoIssues[i].getDifficult() << "\n";
            arquivoSaida << testandoIssues[i].getDate() << "\n";
            arquivoSaida << testandoIssues[i].getBoard() << "\n";
        }
        arquivoSaida << emPilotoIssues.size() << "\n";
        for (int i = 0; i < emPilotoIssues.size(); i++){
            arquivoSaida << emPilotoIssues[i].getId() << "\n";
            arquivoSaida << emPilotoIssues[i].getTitle() << "\n";
            arquivoSaida << emPilotoIssues[i].getDescription() << "\n";
            arquivoSaida << emPilotoIssues[i].getPriority() << "\n";
            arquivoSaida << emPilotoIssues[i].getDifficult() << "\n";
            arquivoSaida << emPilotoIssues[i].getDate() << "\n";
            arquivoSaida << emPilotoIssues[i].getBoard() << "\n";
        }
        arquivoSaida << entregueIssues.size() << "\n";
        for (int i = 0; i < entregueIssues.size(); i++){
            arquivoSaida << entregueIssues[i].getId() << "\n";
            arquivoSaida << entregueIssues[i].getTitle() << "\n";
            arquivoSaida << entregueIssues[i].getDescription() << "\n";
            arquivoSaida << entregueIssues[i].getPriority() << "\n";
            arquivoSaida << entregueIssues[i].getDifficult() << "\n";
            arquivoSaida << entregueIssues[i].getDate() << "\n";
            arquivoSaida << entregueIssues[i].getBoard() << "\n";
        }
        arquivoSaida.close();
    }
    else{
        std::cout << "Não foi possível abrir o arquivo" << std::endl;
    }
}
/**
 * @brief Função responsável por carregar o board de um arquivo txt, ele carrega primeiro o tamanho de cada vector, e após isso carrega os dados em sequencia.
*/
int Board::carregaBoard(){
    std::ifstream arquivoEntrada("../data/quadroPrincipal.txt");
    int maiorId = 0;
    int numIssues;
    int id;
    std::string title;
    std::string description;
    int priority;
    int difficult;
    std::string date;
    std::string board;
    std::string line;
    if (arquivoEntrada.is_open()){
        while (std::getline(arquivoEntrada, line)){
            numIssues = std::stoi(line);
            for (int i = 0; i < numIssues; i++){
                std::getline(arquivoEntrada, line);
                id = std::stoi(line);
                if (id > maiorId){
                    maiorId = id;
                }
                std::getline(arquivoEntrada, line);
                title = line;
                std::getline(arquivoEntrada, line);
                description = line;
                std::getline(arquivoEntrada, line);
                priority = std::stoi(line);
                std::getline(arquivoEntrada, line);
                difficult = std::stoi(line);
                std::getline(arquivoEntrada, line);
                date = line;
                std::getline(arquivoEntrada, line);
                board = line;
                Issue issue(id, title, description, priority, difficult, date, board);
                if (board == "Backlog"){
                    backlogIssues.push_back(issue);
                }
                if (board == "Fazendo"){
                    fazendoIssues.push_back(issue);
                }
                if (board == "Em Análise"){
                    emAnaliseIssues.push_back(issue);
                }
                if (board == "Testando"){
                    testandoIssues.push_back(issue);
                }
                if (board == "Em Piloto"){
                    emPilotoIssues.push_back(issue);
                }
                if (board == "Entregue"){
                    entregueIssues.push_back(issue);
                }
            }
        }
        arquivoEntrada.close();
        return maiorId;
    }
    else{
        std::cout << "Não foi possível abrir o arquivo" << std::endl;
        return 0;
    }
}
