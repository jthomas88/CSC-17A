/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: Jeff
 *
 * Created on May 16, 2017, 5:27 PM
 */

#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    char num;  //Player number (1 - 4)
    int  gold; //Amount of capital player has
    int  size; //Army size
public:
    //Constructor
    Player();
    //Setters
    void setNum();
    void setGold();
    void setSize();
    //Getters
    char getNum();
    int  getGold();
    int  getSize();
    //Member functions
    void buyLand(char[][10]);
    void selLand();
    void buyTrop();
    void selTrop();
    void attack();
    //Destructor
    virtual ~Player();

};

#endif /* PLAYER_H */

