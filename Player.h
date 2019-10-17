
#ifndef Player_h
#define Player_h
#include "Athlete.h"
#include <string>


class Player : public Athlete {
    
private:
    string team;
    double points;
    double rebounds;
    double blocks;
    double assists;
    double steals;
    
public:
    
    Player(string first = "",
           string last = "",
           string team = "",
           string position ="",
           string height = "",
           double points = 0,
           double rebounds = 0,
           double blocks = 0,
           double assists = 0,
           double steals = 0);
    
    
    string get_team();
    double get_points();
    double get_rebounds();
    double get_blocks();
    double get_assists();
    double get_steals();
    void get_info();
    
    void set_team(double);
    void set_points(double);
    void set_rebounds(double);
    void set_blocks(double);
    void set_assists(double);
    void set_steals(double);
    
    void operator==(Player& right);
   
    
    
    friend bool compare_points(Player& right, Player& left);
    friend bool compare_rebounds(Player& right, Player& left);
    friend bool compare_assists(Player& right, Player& left);
    friend bool compare_blocks(Player& right, Player& left);
    friend bool compare_steals(Player& right, Player& left);
    
};

#endif /* Player_h */
