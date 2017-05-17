/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.cpp
 * Author: Jeff
 * 
 * Created on May 16, 2017, 5:27 PM
 */

#include <iostream>
#include "Player.h"

Player::Player() {
}
//Setters
//void Player::setNum();
//void Player::setGold();
//void Player::setSize();
//Getters
//char Player::getNum();
//int  Player::getGold();
//int  Player::getSize();
//Member functions
void Player::buyLand(char map[][10]){
    char posx,posy;
    std::cin>>posx>>posy;
    map[posy-49][posx-65]='X';
}
//void Player::selLand();
//void Player::buyTrop();
//void Player::selTrop();
//void Player::attack();
Player::~Player() {
}

