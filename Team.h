//
//  Team.h
//  Flex_Project_Alexander_Chris
//
//  Created by Chris Alexander on 3/30/19.
//  Copyright © 2019 Chris Alexander. All rights reserved.
//

#ifndef Team_h
#define Team_h
#include "Player.h"
#include <vector>

using std::vector;

class Team {
    
private:
    
    vector<Player> roster;
    string name;
    string city;
    double team_points;
    double team_rebounds;
    double team_assists;
    double team_blocks;
    double team_steals;
    
    
public:
    
    Team();
    Team(string, string, double, double, double, double, double);
    
    string get_team_name();
    string get_city();
    void get_roster();
    
    void set_team_name(string);
    void set_city(string);
    void set_roster(Player p, string s);
    void set_team_points(double);
    void set_team_rebounds(double);
    void set_team_assists(double);
    void set_team_blocks(double);
    void set_team_steals(double);
    
    double get_team_points();
    double get_team_rebounds();
    double get_team_assists();
    double get_team_blocks();
    double get_team_steals();
    
    void add(Player a);
    
    Player points_leader();
    Player blocks_leader();
    Player rebounds_leader();
    Player steals_leader();
    Player assists_leader();
    
    
    void operator==(Team& right);
    
};
#endif /* Team_h */
