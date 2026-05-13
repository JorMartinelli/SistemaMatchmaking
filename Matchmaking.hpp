// declaração da classe Matchmaking

#include "Player.hpp"

#ifndef MATCHMAKING_HPP
#define MATCHMAKING_HPP

const int MAX_PLAYERS = 100000;

class Matchmaking {

private:

    Player* players;
    int size;

public:

    Matchmaking();
    ~Matchmaking();

    bool insert(Player player);
    bool removePlayer(int id);

    void sortByScoreInsertion();
    void sortByScoreMerge();
 
    Player* formGroup(int groupSize, int delta, int* n);

    Player* getWaitingPlayers(int* n);

    void printWaitingPlayers();

    Player* mergeSort(Player arr[], int n);
    Player* merge(Player arr1[], int n, Player arr2[], int m);

};

#endif