// implementação da classe Player

#include "Player.hpp"

Player::Player(){
    id = 0; 
    name = ""; 
    score = 0; 
    timestamp = 0;
}

Player::Player(int id, std::string name, int score, int timestamp){
    this ->  id = id;
    this -> name = name;
    this -> score = score;
    this -> timestamp = timestamp;
}

Player::~Player(){}

int Player::getId() {
    return this -> id;
}

std::string Player::getName() {
    return this -> name;
}

int Player::getScore() {
    return this -> score;
}

int Player::getTimestamp() {
    return this -> timestamp;
}