#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class semiIssue{
protected:
    int id;
    std::string title;
    std::string description;

public:
    semiIssue(int id, std::string title, std::string description, int priority, int difficult, std::string date, std::string board);
    int getId();
    std::string getTitle();
    std::string getDescription();
    void setTitle(std::string title);
    void setDescription(std::string description);
};

semiIssue::semiIssue(int id, std::string title, std::string description, int priority, int difficult, std::string date, std::string board){
    this->id = id;
    this->title = title;
    this->description = description;
}

int semiIssue::getId(){
    return this->id;
}

std::string semiIssue::getTitle(){
    return this->title;
}

std::string semiIssue::getDescription(){
    return this->description;
}

void semiIssue::setTitle(std::string title){
    this->title = title;
}

void semiIssue::setDescription(std::string description){
    this->description = description;
}

class Issue : public semiIssue{
private:
    int priority;
    int difficult;
    std::string date;
    std::string board;

public:
    Issue(int id, std::string title, std::string description, int priority, int difficult, std::string date, std::string board);
    int getPriority();
    int getDifficult();
    std::string getDate();
    std::string getBoard();
    void setPriority(int priority);
    void setDifficult(int difficult);
    void setDate(std::string date);
    void setBoard(std::string board);
};

Issue::Issue(int id, std::string title, std::string description, int priority, int difficult, std::string date, std::string board) : semiIssue(id, title, description, priority, difficult, date, board){
    this->priority = priority;
    this->difficult = difficult;
    this->date = date;
    this->board = board;
}

int Issue::getPriority(){
    return this->priority;
}

int Issue::getDifficult(){
    return this->difficult;
}

std::string Issue::getDate(){
    return this->date;
}

std::string Issue::getBoard(){
    return this->board;
}

void Issue::setPriority(int priority){
    this->priority = priority;
}

void Issue::setDifficult(int difficult){
    this->difficult = difficult;
}

void Issue::setDate(std::string date){
    this->date = date;
}

void Issue::setBoard(std::string board){
    this->board = board;
}

class Board{
private:
    std::vector<Issue> backlogIssues;
    std::vector<Issue> emAnaliseIssues;
    std::vector<Issue> testandoIssues;
    std::vector<Issue> emPilotoIssues;
    std::vector<Issue> entregueIssues;

public:
    void createIssue(int id, std::string title, std::string description, int priority, int difficult, std::string date, std::string board);
    template <typename T>
    void addIssue(Issue &issue, T &vector);
    template <typename T>
    void removeIssue(int id, T &vector);
    void apagaIssue(int id);
    void editaIssue(int id, int opcao);
    void detalhaIssue(int id);
    template <typename T>
    int buscaBinaria(int id, T &vector, int left, int right);
    template <typename T>
    void bubbleSort(std::vector<Issue> &vector, T compareFn);
    template <typename T>
    void insertionSort(std::vector<Issue> &vector, T compareFn);
    void organizeByPriority();
    void organizeByDifficulty();
    void mudaBoard();
    int alteraPropriedadeBoard(int id, std::string novaBoard);
    void printBoard();
    void salvaBoard();
    int carregaBoard();
};
void Board::createIssue(int id, std::string title, std::string description, int priority, int difficult, std::string date, std::string board){
    Issue issue(id, title, description, priority, difficult, date, board);
    this->backlogIssues.push_back(issue);
}

template <typename T>
void Board::addIssue(Issue &issue, T &vector){
    vector.push_back(issue);
}

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

template <typename T>
void Board::removeIssue(int id, T &vector){
    int index = buscaBinaria(id, vector, 0, vector.size() - 1);
    if (index != -1){
        vector.erase(vector.begin() + index);
    }
}

void Board::apagaIssue(int id){
    for (int i = 0; i < backlogIssues.size(); i++){
        if (backlogIssues[i].getId() == id){
            removeIssue(id, backlogIssues);
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

void Board::detalhaIssue(int id){
    for (int i = 0; i < backlogIssues.size(); i++){
        if (backlogIssues[i].getId() == id){
            std::cout << "Título: " << backlogIssues[i].getTitle() << std::endl;
            std::cout << "Descrição: " << backlogIssues[i].getDescription() << std::endl;
            std::cout << "Prioridade: " << backlogIssues[i].getPriority() << std::endl;
            std::cout << "Dificuldade: " << backlogIssues[i].getDifficult() << std::endl;
            std::cout << "Data: " << backlogIssues[i].getDate() << std::endl;
            std::cout << "Board: " << backlogIssues[i].getBoard() << std::endl;
        }
    }
    for (int i = 0; i < emAnaliseIssues.size(); i++){
        if (emAnaliseIssues[i].getId() == id){
            std::cout << "Título: " << emAnaliseIssues[i].getTitle() << std::endl;
            std::cout << "Descrição: " << emAnaliseIssues[i].getDescription() << std::endl;
            std::cout << "Prioridade: " << emAnaliseIssues[i].getPriority() << std::endl;
            std::cout << "Dificuldade: " << emAnaliseIssues[i].getDifficult() << std::endl;
            std::cout << "Data: " << emAnaliseIssues[i].getDate() << std::endl;
            std::cout << "Board: " << emAnaliseIssues[i].getBoard() << std::endl;
        }
    }
    for (int i = 0; i < testandoIssues.size(); i++){
        if (testandoIssues[i].getId() == id){
            std::cout << "Título: " << testandoIssues[i].getTitle() << std::endl;
            std::cout << "Descrição: " << testandoIssues[i].getDescription() << std::endl;
            std::cout << "Prioridade: " << testandoIssues[i].getPriority() << std::endl;
            std::cout << "Dificuldade: " << testandoIssues[i].getDifficult() << std::endl;
            std::cout << "Data: " << testandoIssues[i].getDate() << std::endl;
            std::cout << "Board: " << testandoIssues[i].getBoard() << std::endl;
        }
    }
    for (int i = 0; i < emPilotoIssues.size(); i++){
        if (emPilotoIssues[i].getId() == id){
            std::cout << "Título: " << emPilotoIssues[i].getTitle() << std::endl;
            std::cout << "Descrição: " << emPilotoIssues[i].getDescription() << std::endl;
            std::cout << "Prioridade: " << emPilotoIssues[i].getPriority() << std::endl;
            std::cout << "Dificuldade: " << emPilotoIssues[i].getDifficult() << std::endl;
            std::cout << "Data: " << emPilotoIssues[i].getDate() << std::endl;
            std::cout << "Board: " << emPilotoIssues[i].getBoard() << std::endl;
        }
    }
    for (int i = 0; i < entregueIssues.size(); i++){
        if (entregueIssues[i].getId() == id){
            std::cout << "Título: " << entregueIssues[i].getTitle() << std::endl;
            std::cout << "Descrição: " << entregueIssues[i].getDescription() << std::endl;
            std::cout << "Prioridade: " << entregueIssues[i].getPriority() << std::endl;
            std::cout << "Dificuldade: " << entregueIssues[i].getDifficult() << std::endl;
            std::cout << "Data: " << entregueIssues[i].getDate() << std::endl;
            std::cout << "Board: " << entregueIssues[i].getBoard() << std::endl;
        }
    }
}

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

void Board::organizeByPriority(){
    auto compareFn = [](Issue &a, Issue &b){
        return a.getPriority() > b.getPriority();
    };

    bubbleSort(backlogIssues, compareFn);
    bubbleSort(emAnaliseIssues, compareFn);
    bubbleSort(testandoIssues, compareFn);
    bubbleSort(emPilotoIssues, compareFn);
    bubbleSort(entregueIssues, compareFn);
}

void Board::organizeByDifficulty()
{
    auto compareFn = [](Issue &a, Issue &b){
        return a.getDifficult() > b.getDifficult();
    };

    insertionSort(backlogIssues, compareFn);
    insertionSort(emAnaliseIssues, compareFn);
    insertionSort(testandoIssues, compareFn);
    insertionSort(emPilotoIssues, compareFn);
    insertionSort(entregueIssues, compareFn);
}

void Board::mudaBoard(){
    for (int i = 0; i < backlogIssues.size(); i++){
        if (backlogIssues[i].getBoard() != "Backlog"){
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
    for (int i = 0; i < emAnaliseIssues.size(); i++){
        if (emAnaliseIssues[i].getBoard() != "Em Análise"){
            if (emAnaliseIssues[i].getBoard() == "Backlog"){
                backlogIssues.push_back(emAnaliseIssues[i]);
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

int Board::alteraPropriedadeBoard(int id, std::string novaBoard){
    for (int i = 0; i < backlogIssues.size(); i++){
        if (backlogIssues[i].getId() == id){
            backlogIssues[i].setBoard(novaBoard);
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

void Board::printBoard(){
    std::cout << "== Backlog =="
              << "\t"
              << "== Em Análise =="
              << "\t"
              << "== Testando =="
              << "\t"
              << "== Em Piloto =="
              << "\t"
              << "== Entregue ==" << std::endl;

    int maxIssues = std::max(backlogIssues.size(), std::max(emAnaliseIssues.size(), std::max(testandoIssues.size(), std::max(emPilotoIssues.size(), entregueIssues.size()))));

    for (int i = 0; i < maxIssues; i++){
        if (i < backlogIssues.size()){
            std::cout << "#" << backlogIssues[i].getId() << " " << backlogIssues[i].getTitle() << "\t\t";
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
    std::cout << "======================================================================================" << std::endl;
}

void Board::salvaBoard(){
    std::ofstream arquivoSaida("quadroPrincipal.txt");

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

int Board::carregaBoard(){
    std::ifstream arquivoEntrada("quadroPrincipal.txt");
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

    strings(17);
    strings(18);
    std::cin >> opcao;
    if (opcao == 1){
        id = quadroPrincipal.carregaBoard();
    }
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
    while (true){
        strings(16);
        std::cin >> opcao;
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
        if (opcao == 2){
            strings(8);
            std::cin >> id;
            quadroPrincipal.detalhaIssue(id);
            opcao = 0;
        }
        if (opcao == 3){
            strings(9);
            std::cin >> id;
            strings(10);
            std::cin >> opcao;
            if (opcao == 1){
                board = "Backlog";
            }
            if (opcao == 2){
                board = "Em Análise";
            }
            if (opcao == 3){
                board = "Testando";
            }
            if (opcao == 4){
                board = "Em Piloto";
            }
            if (opcao == 5){
                board = "Entregue";
            }
            quadroPrincipal.alteraPropriedadeBoard(id, board);
            quadroPrincipal.printBoard();
            opcao = 0;
        }
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
        if (opcao == 5){
            strings(13);
            std::cin >> id;
            quadroPrincipal.apagaIssue(id);
            opcao = 0;
        }
        if (opcao == 6){
            quadroPrincipal.organizeByPriority();
            strings(14);
            quadroPrincipal.printBoard();
            opcao = 0;
        }
        if (opcao == 7){
            quadroPrincipal.organizeByDifficulty();
            strings(15);
            quadroPrincipal.printBoard();
            opcao = 0;
        }
        if (opcao == 8){
            quadroPrincipal.printBoard();
            opcao = 0;
        }
        if (opcao == 9){
            quadroPrincipal.salvaBoard();
            break;
        }
    }
    return 0;
}