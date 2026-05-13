// implementação da classe Matchmaking

#include <iostream>
#include "Matchmaking.hpp"

Matchmaking::Matchmaking() {
    size = 0;
    players = new Player[MAX_PLAYERS];
}

Matchmaking::~Matchmaking() {
    delete[] players;
}

bool Matchmaking::insert(Player player){

    if(size < MAX_PLAYERS){

        players[size] = player;
        size ++;
        return true;

    } else{

        return false;
    }
}

bool Matchmaking::removePlayer(int id){

    for(int i = 0; i < size; i++){

        if(players[i].getId() == id){

            for(int j = i; j < size - 1; j++){
                players[j] = players[j+1]; // movendo os jogadores a frente do jogador retirado uma posição para trás
            }
            size --;
            return true;
        }
    }

    return false;
}

void Matchmaking::sortByScoreInsertion(){

    int i, j;
    Player current;

    for (i = 1; i < size; i++) {  

        current = players[i];                     
        j = i - 1;                             

        while(j >= 0) {  

            // quando o score é maior
            if (players[j].getScore() > current.getScore()) {
                players[j+1] = players[j];
            }
            // quando o score é igual, mas muda o timestamp
            else if (players[j].getScore() == current.getScore() && players[j].getTimestamp() > current.getTimestamp()) {
                players[j+1] = players[j];
            }

            else {
                break;
            }

            j = j - 1;                         
        }

        players[j+1] = current;                    
    }
}

Player* Matchmaking::merge(Player arr1[], int n, Player arr2[], int m) {

    Player* mArr = new Player[n + m];

    int i = 0;
    int j = 0;

    while(i < n && j < m) {

        // quando o score do primeiro é menor
        if(arr1[i].getScore() < arr2[j].getScore()) {

            mArr[i + j] = arr1[i];
            i++;

        } 

        // scores iguais, mas timestamp do primeiro é menor
        else if(arr1[i].getScore() == arr2[j].getScore() && arr1[i].getTimestamp() <= arr2[j].getTimestamp()){

            mArr[i + j] = arr1[i];
            i++;
  
        } else { // score de arr2 é menor ou timestamp de arr2 é menor

            mArr[i + j] = arr2[j];
            j++;
        }
    }

    while(i < n) {

        mArr[i + j] = arr1[i];
        i++;
    }

    while(j < m) {

        mArr[i + j] = arr2[j];
        j++;
    }

    return mArr;
}

Player* Matchmaking::mergeSort(Player arr[], int n) {

    if(n <= 1) {

        Player* player = new Player[n];

        if(n == 1){
            player[0] = arr[0];
        }

        return player;
    }

    int mid = n / 2;

    Player* left = mergeSort(arr, mid);
    Player* right = mergeSort(arr + mid, n - mid);

    Player* sorted = merge(left, mid, right, n - mid);

    delete[] left;
    delete[] right;

    return sorted;
}

void Matchmaking::sortByScoreMerge() {

    if(size <= 1){
        return;
    }   

    Player* sorted = mergeSort(players, size);

    for(int i = 0; i < size; i++) {
        players[i] = sorted[i];
    }

    delete[] sorted;
}

Player* Matchmaking::formGroup(int groupSize, int delta, int* n){

    if(size < groupSize){
        *n = 0;
        return nullptr;
    }

    for(int start = 0; start <= size - groupSize; start++){

        int minScore = players[start].getScore();

        int maxScore = players[start + groupSize - 1].getScore();

        if(maxScore - minScore <= delta){

            Player* group = new Player[groupSize];

            for(int i = 0; i < groupSize; i++){
                group[i] = players[start + i];
            }


            for(int j = start; j < size - groupSize; j++){
                players[j] = players[j + groupSize];
            }

            size -= groupSize;
            *n = groupSize;
            return group;
        }
    }

    *n = 0; // caso não seja encontrado um grupo
    return nullptr;
}

Player* Matchmaking::getWaitingPlayers(int* n){

    if(size == 0){
        *n = 0;
        return nullptr;
    }

    Player* waiting_players = new Player[size];

    for(int i = 0; i < size; i++){
        waiting_players[i] = players[i];
    }

    *n = size;
    return waiting_players;
}

void Matchmaking::printWaitingPlayers(){

    std::cout << "Waiting Players:" << std::endl;

    if(size == 0){

        std::cout << "(empty)" << std::endl;
        return;
    }

    for(int i = 0; i < size; i++){

        std::cout
            << "[" 
            << players[i].getId() << " | "
            << players[i].getName() << " | "
            << players[i].getScore() << " | "
            << players[i].getTimestamp()
            << "]"
            << std::endl;
    }
}