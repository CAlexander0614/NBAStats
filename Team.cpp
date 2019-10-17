

#include <stdio.h>
#include "Team.h"
#include "Player.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <iomanip>

using std::string;
using std::cout;
using std::endl;




Team::Team(){
}

Team::Team(string a_name, string a_city, double points, double rebounds, double assists, double blocks, double steals) {
    
    name = a_name;
    city = a_city;
    team_points = points;
    team_rebounds = rebounds;
    team_assists = assists;
    team_blocks = blocks;
    team_steals = steals;
    
}

string Team::get_team_name() {
    
    return name;
    
}

string Team::get_city() {
    
    return city;
    
}

void Team::get_roster() {
    
    for(int i = 0; i < roster.size(); i++) {
        
        std::cout << roster[i].get_first_name() << " " << roster[i].get_last_name() << std::endl;
        
    }


  

    
}

double Team::get_team_points() {
    
    return team_points;
    
}

double Team:: get_team_rebounds() {
    
    return team_rebounds;
    
}

double Team::get_team_assists() {
    
    return team_assists;
    
    
}

double Team::get_team_blocks() {
    
    return team_blocks;
    
}

double Team::get_team_steals() {
    
    return team_steals;
    
}

void Team::set_team_points(double points) {
    
    team_points = points;
    
}

void Team::set_team_rebounds(double rebounds) {
    
    team_rebounds = rebounds;
}

void Team::set_team_assists(double assists) {
    
    team_assists = assists;
    
}

void Team::set_team_blocks(double blocks) {
    
    team_blocks = blocks;
    
}

void Team::set_team_steals(double steals) {
    
    team_steals = steals;
    
}


void Team::add(Player a) {
    
    roster.push_back(a);
    
}

void Team::set_team_name(string a_name) {
    
    name = a_name;
    
    
}

void Team::set_city(string a_city) {
    
    city = a_city;
    
}

Player Team::points_leader() {
    
    int x = 0;
    double smallest = roster[0].get_points();
    double largest = roster[0].get_points();
    
    for(int i = 0; i < roster.size(); i++) {
        
        if(roster[i].get_points() < smallest) {
            
            smallest = roster[i].get_points();
            
        }
        
        if(roster[i].get_points() > largest) {
            
            largest = roster[i].get_points();
            x = i;
            
        }
        
    }
    
    
    return roster[x];
    
    
    
}

Player Team::rebounds_leader() {
 
 int x = 0;
 double smallest = roster[0].get_rebounds();
 double largest = roster[0].get_rebounds();
 
 for(int i = 0; i < roster.size(); i++) {
 
 if(roster[i].get_rebounds() < smallest) {
 
 smallest = roster[i].get_rebounds();
 
 }
 
 if(roster[i].get_rebounds() > largest) {
 
 largest = roster[i].get_rebounds();
 x = i;
 
 }
 
 }
 
 
 return roster[x];
 
 
 
 }



Player Team::blocks_leader() {
 
 int x = 0;
 double smallest = roster[0].get_blocks();
 double largest = roster[0].get_blocks();
 
 for(int i = 0; i < roster.size(); i++) {
 
 if(roster[i].get_blocks() < smallest) {
 
 smallest = roster[i].get_blocks();
 
 }
 
 if(roster[i].get_blocks() > largest) {
 
 largest = roster[i].get_blocks();
 x = i;
 
 }
 
 }
 
 
 return roster[x];
 
 
 
 }


Player Team::steals_leader(){
    
    int x = 0;
    double smallest = roster[0].get_steals();
    double largest = roster[0].get_steals();
    
    for(int i = 0; i < roster.size(); i++) {
        
        if(roster[i].get_steals() < smallest) {
            
            smallest = roster[i].get_steals();
            
        }
        
        if(roster[i].get_steals() > largest) {
            
            largest = roster[i].get_steals();
            x = i;
            
        }
        
    }
    
    
    return roster[x];
    
    
}

Player Team::assists_leader(){
    
    int x = 0;
    double smallest = roster[0].get_assists();
    double largest = roster[0].get_assists();
    
    for(int i = 0; i < roster.size(); i++) {
        
        if(roster[i].get_assists() < smallest) {
            
            smallest = roster[i].get_assists();
            
        }
        
        if(roster[i].get_assists() > largest) {
            
            largest = roster[i].get_assists();
            x = i;
            
        }
        
    }
    
    
    return roster[x];
    
    
    
}

void Team::operator==(Team& right) {
    
    
    cout << std::fixed << std::setprecision(1) << endl;
    
    cout <<  "Team: \t\t" <<  std::setw(21) << std::left << get_team_name() << right.get_team_name() << endl;
    
    cout << "City: \t\t"<< std::setw(21) << std::left<< get_city()  << right.get_city() << endl;
    
    std::cout << "Points: \t";
    
    if(get_team_points() > right.get_team_points()) {
        
        
        cout <<  "**" << get_team_points() << std::setw(14) << std::left << "**"   << right.get_team_points() << endl;
        
    }
    
    if(get_team_points() < right.get_team_points()) {
        
        cout << std::left << std::setw(18) << get_team_points()   << "\t **" << right.get_team_points() << "**" << endl;
        
    }
    
    if(get_team_points() == right.get_team_points()) {
        
        cout <<  get_team_points()  << std::left << std::setw(15) << '\t' << right.get_team_points() << endl;
        
    }
    
    
    cout << "Rebounds: \t";
    
    if(get_team_rebounds() > right.get_team_rebounds()) {
        
        
        cout <<  "**" << get_team_rebounds() << std::setw(15) << std::left << "**" << right.get_team_rebounds() << endl;
        
    }
    
    if(get_team_rebounds() < right.get_team_rebounds()) {
        
        cout << get_team_rebounds()  << std::left << std::setw(14) << '\t' << "**" << right.get_team_rebounds() << "**" << endl;
    }
    
    if(get_team_rebounds() == right.get_team_rebounds()) {
        
        cout <<  get_team_rebounds()  << std::left << std::setw(15) << '\t' << right.get_team_rebounds() << endl;
    }
    
    cout << "Assists: \t";
    
    if(get_team_assists() > right.get_team_assists()) {
        
        cout <<  "**" << get_team_assists() << "**"  << std::setw(10) << std::left << '\t' << right.get_team_assists() << endl;
        
    }
    
    if(get_team_assists() < right.get_team_assists()) {
        
        cout << get_team_assists()  << std::left << std::setw(14) << '\t' << "**" << right.get_team_assists() << "**" << endl;
    }
    
    if(get_team_assists() == right.get_team_assists()) {
        
        cout <<  get_team_assists()  << std::left << std::setw(15) << '\t' << right.get_team_assists() << endl;
    }
    
    cout << "Blocks: \t";
    
    if(get_team_blocks() > right.get_team_blocks()) {
        
        cout <<  "**" << get_team_blocks() << "**"  << std::setw(14) << std::left << '\t' << right.get_team_blocks() << endl;
    }
    
    if(get_team_blocks() < right.get_team_blocks()) {
        
        cout << get_team_blocks()  << std::left << std::setw(18) << '\t' << "**" << right.get_team_blocks() << "**" << endl;
        
    }
    
    if(get_team_blocks() == right.get_team_blocks()) {
        
        cout <<  get_team_blocks()  << std::left << std::setw(15) << '\t' << right.get_team_blocks() << endl;
    }
    
    
    cout << "Steals: \t";
    
    if(get_team_steals() > right.get_team_steals()) {
        
        cout <<  "**" << get_team_steals() << "**"  << std::setw(14) << std::left << '\t' << right.get_team_steals() << endl;
    }
    
    if(get_team_steals() < right.get_team_steals()) {
        
        
        cout << get_team_steals()  << std::left << std::setw(18) << '\t' << "**" << right.get_team_steals() << "**" << endl;
        
    }
    
    if(get_team_steals() == right.get_team_steals()) {
        
        cout <<  get_team_steals()  << std::left << std::setw(15) << '\t' << right.get_team_steals() << endl;
    }
    
    cout << endl << endl;
    
}


    
    
    


