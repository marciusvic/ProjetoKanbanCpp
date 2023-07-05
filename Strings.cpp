#include "Strings.h"
#include <iostream>

void strings(int num){
    if (num == 1){
        std::cout << "Para começar, vamos criar a sua primeira issue." << std::endl;
    }
    if (num == 2){
        std::cout << "Digite o título da issue: " << std::endl;
    }
    if (num == 3){
        std::cout << "Digite a descrição da issue: " << std::endl;
    }
    if (num == 4){
        std::cout << "Digite a prioridade da issue: " << std::endl;
    }
    if (num == 5){
        std::cout << "Digite a dificuldade da issue: " << std::endl;
    }
    if (num == 6){
        std::cout << "Digite a data da issue: " << std::endl;
    }
    if (num == 7){
        std::cout << "Sua issue foi criada e adicionada na board Backlog" << std::endl;
    }
    if (num == 8){
        std::cout << "Digite o número da issue que deseja ver os detalhes: " << std::endl;
    }
    if (num == 9){
        std::cout << "Digite o número da issue que deseja mover: " << std::endl;
    }
    if (num == 10){
        std::cout << "Para qual board deseja mover a issue?" << std::endl;
        std::cout << "1 - Backlog" << std::endl;
        std::cout << "2 - Em Análise" << std::endl;
        std::cout << "3 - Testando" << std::endl;
        std::cout << "4 - Em Piloto" << std::endl;
        std::cout << "5 - Entregue" << std::endl;
    }
    if (num == 11){
        std::cout << "Digite o número da issue que deseja editar: " << std::endl;
    }
    if (num == 12){
        std::cout << "O que deseja editar?" << std::endl;
        std::cout << "1 - Título" << std::endl;
        std::cout << "2 - Descrição" << std::endl;
        std::cout << "3 - Prioridade" << std::endl;
        std::cout << "4 - Dificuldade" << std::endl;
        std::cout << "5 - Data" << std::endl;
        std::cout << "6 - Voltar" << std::endl;
    }
    if (num == 13){
        std::cout << "Digite o número da issue que deseja apagar: " << std::endl;
    }
    if (num == 14){
        std::cout << "Boards organizados por ordem de prioridade, do menor para o maior" << std::endl;
    }
    if (num == 15){
        std::cout << "Boards organizados por ordem de dificuldade, do menor para o maior" << std::endl;
    }
    if (num == 16){
        std::cout << "O que deseja fazer agora?" << std::endl;
        std::cout << "1 - Criar uma nova issue" << std::endl;
        std::cout << "2 - Ver detalhes sobre uma issue" << std::endl;
        std::cout << "3 - Mover uma issue de uma board para outra" << std::endl;
        std::cout << "4 - Editar uma issue" << std::endl;
        std::cout << "5 - Apagar uma issue" << std::endl;
        std::cout << "6 - Organizar as issues por prioridade" << std::endl;
        std::cout << "7 - Organizar as issues por dificuldade" << std::endl;
        std::cout << "8 - Imprimir o quadro" << std::endl;
        std::cout << "9 - Sair" << std::endl;
    }
    if (num == 17){
        std::cout << "Este é o projeto Kanban, aqui você pode criar, editar, remover e organizar suas issues." << std::endl;
    }
    if (num == 18){
        std::cout << "Deseja carregar o quadro salvo anteriormente?" << std::endl;
        std::cout << "1 - Sim" << std::endl;
        std::cout << "2 - Não" << std::endl;
    }
}
