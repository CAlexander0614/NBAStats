//
//  Athlete.cpp
//  Flex_Project_Alexander_Chris
//
//  Created by Chris Alexander on 3/30/19.
//  Copyright © 2019 Chris Alexander. All rights reserved.
//

#include <stdio.h>
#include "Athlete.h"
#include <string>
#include <iostream>

using std::string;

int Athlete::player_count = 0;

Athlete::Athlete(string first, string last, string a_height, string a_position){
    
    first_name = first;
    last_name = last;
    height = a_height;
    position = a_position;
    player_count++;
    
}

string Athlete::get_first_name() {
    
    return first_name;
    
}

string Athlete::get_last_name() {
    
    return last_name;
    
}

string Athlete::get_position() {
    
    return position;
    
}

string Athlete::get_height() {
    
    return height;
    
}

void Athlete::get_info() {
    
    std::cout << first_name << " " << last_name << std::endl;
    
    std::cout << "Position: " << position << std::endl;
    
    
    
}

void Athlete::set_first_name(string a) {
    
    first_name = a;
    
}

void Athlete::set_last_name(string b) {
    
    last_name = b;
    
}

void Athlete::set_height(string c) {
    
    height = c;
    
}

void Athlete::set_position(string d) {
    
    position = d;
    
}


