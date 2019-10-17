//
//  Player.cpp
//  Flex_Project_Alexander_Chris
//
//  Created by Chris Alexander on 3/30/19.
//  Copyright © 2019 Chris Alexander. All rights reserved.
//

#include <stdio.h>
#include "Player.h"
#include "Athlete.h"
#include <string>
#include <iostream>
#include <string>
#include <iomanip>


using std::string;
using std::cout;
using std::endl;

Player::Player(string a_first,
       string a_last,
       string a_team ,
       string a_position,
       string a_height,
       double a_points,
       double a_rebounds,
       double a_blocks,
       double a_assists,
       double a_steals) : Athlete(a_first, a_last, a_position, a_height) {
    
    set_first_name(a_first);
    set_last_name(a_last);
    set_position(a_position);
    set_height(a_height);
    
    points = a_points;
    rebounds = a_rebounds;
    blocks = a_blocks;
    assists = a_assists;
    steals =  a_steals;
    team = a_team;
}

string Player::get_team() {
    
    return team;
}

double Player::get_rebounds() {
    
    return rebounds;
    
}

double Player::get_points() {
    
    return points;
    
}

double Player::get_steals() {
    
    return steals;
    
}

double Player::get_blocks() {
    
    return blocks;
    
}

double Player::get_assists() {
    
    return assists;
    
}

void Player::set_assists(double a) {
    
    assists = a;
    
}

void Player::set_points(double b) {
    
    points = b;
    
}

void Player::set_rebounds(double c) {
    
    rebounds = c;
    
}

void Player::set_blocks(double d) {
    
    blocks = d;
    
}

void Player::set_steals(double e) {
    
    steals = e;
    
    
}

void Player::get_info() {
    
    cout << std::fixed << std::setprecision(1) << endl;
    cout <<"Name: " << get_first_name() << " " << get_last_name() << endl <<
    "Team: " << get_team() << endl <<
    "Height: " << get_height() << endl <<
    "Position: " << get_position() << endl <<
    "Points: " << get_points() << endl <<
    "Rebounds: " << get_rebounds() << endl <<
    "Assists: " << get_assists() << endl <<
    "Blocks: " << get_blocks() << endl <<
    "Steals: " << get_steals() << endl;
    
    
}


//Lets user compare stats of 2 players; puts ** around the higher statistic
void Player::operator==(Player& right) {

    

    cout << std::fixed << std::setprecision(1) << endl;

    cout <<  "\t\t" << get_first_name() << " " << std::setw(15) << std::left << get_last_name()  << right.get_first_name()  << " " << right.get_last_name() << endl;
    
    std::cout << "Points: \t";
    
    if(get_points() > right.get_points()) {
        
        
        cout <<  "**" << get_points() << std::setw(15) << std::left << "**"   << right.get_points() << endl;
        
    }
    
    if(get_points() < right.get_points()) {
        
        cout << std::left << std::setw(18) << get_points()   << "\t **" << right.get_points() << "**" << endl;
        
    }
    
    if(get_points() == right.get_points()) {
        
        cout <<  get_points()  << std::left << std::setw(15) << '\t' << right.get_points() << endl;
        
    }
  
    
    cout << "Rebounds: \t";
    
    if(get_rebounds() > right.get_rebounds()) {
        
     
     cout <<  "**" << get_rebounds() << std::setw(16) << std::left << "**" << right.get_rebounds() << endl;
     
    }
    
    if(get_rebounds() < right.get_rebounds()) {
        
         cout << get_rebounds()  << std::left << std::setw(18) << '\t' << "**" << right.get_rebounds() << "**" << endl;
    }
    
    if(get_rebounds() == right.get_rebounds()) {
        
        cout <<  get_rebounds()  << std::left << std::setw(15) << '\t' << right.get_rebounds() << endl;
    }

    cout << "Assists: \t";
    
    if(get_assists() > right.get_assists()) {
        
         cout <<  "**" << get_assists() << "**"  << std::setw(14) << std::left << '\t' << right.get_assists() << endl;
        
    }
    
    if(get_assists() < right.get_assists()) {
        
        cout << get_assists()  << std::left << std::setw(18) << '\t' << "**" << right.get_assists() << "**" << endl;
    }
    
    if(get_assists() == right.get_assists()) {
        
        cout <<  get_assists()  << std::left << std::setw(15) << '\t' << right.get_assists() << endl;
    }
    
    cout << "Blocks: \t";
    
    if(get_blocks() > right.get_blocks()) {
        
        cout <<  "**" << get_blocks() << "**"  << std::setw(14) << std::left << '\t' << right.get_blocks() << endl;
    }
    
    if(get_blocks() < right.get_blocks()) {
        
         cout << get_blocks()  << std::left << std::setw(18) << '\t' << "**" << right.get_blocks() << "**" << endl;
        
    }
    
    if(get_blocks() == right.get_blocks()) {
        
        cout <<  get_blocks()  << std::left << std::setw(15) << '\t' << right.get_blocks() << endl;
    }
    
    
    cout << "Steals: \t";
    
    if(get_steals() > right.get_steals()) {
        
        cout <<  "**" << get_steals() << "**"  << std::setw(14) << std::left << '\t' << right.get_steals() << endl;
    }
    
    if(get_steals() < right.get_steals()) {
        
        
        cout << get_steals()  << std::left << std::setw(18) << '\t' << "**" << right.get_steals() << "**" << endl;
        
    }
    
    if(get_steals() == right.get_steals()) {
        
        cout <<  get_steals()  << std::left << std::setw(15) << '\t' << right.get_steals() << endl;
    }
    
    cout << endl << endl;
    
}



