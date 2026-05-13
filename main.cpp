#include <iostream>   
#include <string>     
#include <chrono>     
#include "Matchmaking.hpp" 
#include "Player.hpp"

int main() {
    Matchmaking sistema;

    Player player1 = Player(1, "Ana", 1000, 5);
    Player player2 = Player(2, "Bruno", 800, 2);
    Player player3 = Player(3, "Carol", 1000, 1);
    Player player4 = Player(4, "Davi", 800, 4);
    Player player5 = Player(5, "Ester", 900, 3);

    sistema.insert(player1);
    sistema.insert(player2);
    sistema.insert(player3);
    sistema.insert(player4);
    sistema.insert(player5);

    std::cout << "\n--- Verificando insercao ---\n" << std::endl;
    sistema.printWaitingPlayers();

    sistema.removePlayer(3); // Remove Carol

    std::cout << "\n--- Verificando exclusao (ID 3 - Carol) ---\n" << std::endl;
    sistema.printWaitingPlayers();

    sistema.sortByScoreInsertion();
    std::cout << "\n--- Verificando ordenacao pelo insertion ---\n" << std::endl;
    sistema.printWaitingPlayers();

    Player player6 = Player(6, "Fabio", 1000, 2);
    sistema.insert(player3); // Insere Carol de volta (agora no fim da fila)
    sistema.insert(player6); // Insere Fabio

    sistema.sortByScoreMerge();
    std::cout << "\n--- Verificando ordenacao pelo merge (Com Carol e Fabio) ---\n" << std::endl;
    sistema.printWaitingPlayers();

    std::cout << "\nTentando formar grupo de 3 com delta 10 (Deve falhar):\n" << std::endl;
    int nGrupoFalha;
    Player* grupoFalha = sistema.formGroup(3, 10, &nGrupoFalha);
    if (grupoFalha == nullptr) {
        std::cout << "Resultado: Nenhum grupo formado.\n" << std::endl;
    }

    std::cout << "\nTentando formar grupo de 3 com delta 200 (Deve funcionar):\n" << std::endl;
    int nGrupoSucesso;
    Player* grupoSucesso = sistema.formGroup(3, 200, &nGrupoSucesso);

    if (grupoSucesso != nullptr) {
        std::cout << "Grupo Formado (" << nGrupoSucesso << " jogadores):\n" << std::endl;
        for (int i = 0; i < nGrupoSucesso; i++) {
            std::cout << "[" << grupoSucesso[i].getId() << " | " << grupoSucesso[i].getName() << " | " << grupoSucesso[i].getScore() << "]\n" << std::endl;
        }
        delete[] grupoSucesso;
    }

    std::cout << "\nFila apos formar o grupo:\n" << std::endl;
    sistema.printWaitingPlayers();

    std::cout << "\n--- Testando recuperacao de dados (getWaitingPlayers) ---\n" << std::endl;
    int totalRestante;
    Player* listaCopiada = sistema.getWaitingPlayers(&totalRestante);

    if (listaCopiada != nullptr) {
        std::cout << "Existem " << totalRestante << " jogadores esperando na copia.\n" << std::endl;
        delete[] listaCopiada;
    } else {
        std::cout << "Fila vazia.\n" << std::endl;
    }

    return 0;
}