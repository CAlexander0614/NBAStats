/*
 * Purpose: This program allows users to look up statistics for NBA players and teams
 * Author: C. Alexander
 */

#include <iostream>
#include "Player.h"
#include "Athlete.h"
#include "Team.h"
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "console.h"
#include <iomanip>

using std::ifstream;
using std::cout;
using std::endl;

bool compare_points(Player& left, Player& right);
bool compare_rebounds(Player& right, Player& left);
bool compare_assists(Player& right, Player& left);
bool compare_blocks(Player& right, Player& left);
bool compare_steals(Player& right, Player& left);

int main(int argc, const char * argv[]) {
   
    vector<Player> league;
    
    vector<Team> teams_vector;
    
    string first, last, position, height, team, line, line2;
    
    string team_name, city;
    
    string team_points, team_rebounds, team_assists, team_blocks, team_steals;
    
    string str_points, str_rebounds, str_assists, str_blocks, str_steals;
    
    
    
    bool running = true;
    
    
    ifstream file, teams;
    
    teams.open("Teams1.txt");
    
    if(teams) {
        
        line2 = "";
        
        teams.ignore(1000, '\n');
        
        while(getline(teams, line2)) {
            
            
            
            int i = 0;
            
            team_name = "";
            
            city = "";
            
            team_points = "";
            
            team_rebounds = "";
            
            team_assists = "";
            
            team_blocks = "";
            
            team_steals = "";
            
            
            
            //Gets team name
            
            while(line2[i] != 9) {
                
                team_name += line2[i];
                
                i++;
                
            }
            
            i++;
            
            
            
            //Gets city
            while(line2[i] != 9) {
                
                city += line2[i];
               
                i++;
                
            }
            
            i++;
            
            
            //Gets team points
            while(line2[i] != 9) {
                
                team_points += line2[i];
               
                i++;
                
                
            }
            
            i++;
            
            
            //Gets team rebounds
            while(line2[i] != 9) {
                
                team_rebounds += line2[i];
                
                i++;
                
            }
            
            i++;
            
            //Gets team assists
            while(line2[i] != 9) {
                
                team_assists += line2[i];
                
                i++;
                
                
            }
            
            i++;
            
            //Gets team blocks
            while(line2[i] != 9) {
                
                team_blocks += line2[i];
                
                i++;
                
            }
            
            i++;
            
            
            //Gets team steals
            while(line2[i] != 9) {
                
                team_steals += line2[i];
                
                i++;
                
                if(line2[i] =='\n') {
                    
                    break;
                }
            }
            
            
            
            
            
            
            double points = std::stod(team_points);
            double rebounds = std::stod(team_rebounds);
            double assists = std::stod(team_assists);
            double blocks = std::stod(team_blocks);
            double steals = std::stod(team_steals);
            
            
            
            Team team(team_name, city, points, rebounds, assists, blocks, steals);
            
            teams_vector.push_back(team);
            
        }
        
        
        
        
   }  else {
        
        std::cout << "Error! Team file could not open!" << std::endl << std::endl;
        
    }
    
    teams.close();
    
    
    
    file.open("Players.txt");
    
    file.clear();
 
    //Opens the txt file and gathers data members for Player objects; otherwise prints error message
    if(file) {
       
        line = "";
        
        file.ignore(1000, '\n');
        
        while(getline(file, line)) {
           
       
            
            int i = 0;
            
            first = "";
            last = "";
            position = "";
            height = "";
            team = "";
            
            
            str_points = "";
            str_rebounds = "";
            str_assists = "";
            str_blocks = "";
            str_steals = "";
            
            //Gets first name
            
            while(line[i] != 9) {
                
                first += line[i];
                
                i++;
                
            }
            
            i++;
            
            
            //Gets last name
           while(line[i] != 9) {
                
                last += line[i];
                i++;
                
            }
            
            i++;
            
            //Gets team
            
            while(line[i] != 9) {
                
                team += line[i];
                i++;
                
            }
            
            i++;
            
            
            //Gets position
            while(line[i] != 9) {
                
                position += line[i];
                i++;
            
            }
            
            i++;
            
            //Gets height
            while(line[i] != 9) {
                
                height += line[i];
                i++;
                
                
            }
            
            i++;
        
            //Gets points
            while(line[i] != 9) {
                
                str_points += line[i];
                i++;
                
                
            }
            
            i++;
            
            //Gets rebounds
            while(line[i] != 9) {
                
                str_rebounds += line[i];
                i++;
                
            }
            
            i++;
            
            //Gets blocks
            while(line[i] != 9) {
                
                str_blocks += line[i];
                i++;
                
                
            }
            
            i++;
            
            //Gets assists
            while(line[i] != 9) {
                
                str_assists += line[i];
                i++;
                
            }
            
            i++;
            
            
            //Gets steals
            while(line[i] != 9) {
                
                str_steals += line[i];
                i++;
                if(line[i] =='\n') {
                    
                    break;
                }
            }
            
           
            
          
            
            double points = std::stod(str_points);
            double rebounds = std::stod(str_rebounds);
            double assists = std::stod(str_assists);
            double blocks = std::stod(str_blocks);
            double steals = std::stod(str_steals);
            
           
            
            Player player(first, last, team, position, height, points, rebounds, blocks, assists, steals);
            
            
            
            league.push_back(player);
            
            
        
            
        }
        
        
        
        
    }  else {
        
        std::cout << "Error! Player file could not open!" << std::endl << std::endl;
        
        }
    

    
    file.close();
    
    string a_team;
    
    char choice;
    
    while(running == true) {
    
   
        //Ensures user enters exactly one char
        choice = console::get_char("A: Display Team Leaders\n"
                               "L: Display League Leaders (Top 10)\n"
                               "T: Display Team Per Game Stats\n"
                               "C: Compare Two Players\n"
                               "P: Search by Player\n"
                               "B: Compare Two Teams\n"
                               "Q: Quit\n");
    
   
        int count = 0;
   
        string a, b, c, d;
   
        Player player1, player2;
   
        Team team1, team2;
   
        string comparison;
   
        string team_name1, team_name2;
        
    
        //These 2 variables are used to flag whether player1 and 2 are found in player comparison/player search
    
        int found1 = 0;
    
        int found2 = 0;
        
    
        int team_found1 = 0;
        int team_found2 = 0;
        
        
    
        choice = tolower(choice);
    
    
        switch (choice) {
        
            case 'l':
            
                cout << std::fixed << std::setprecision(1);
                
                cout << "Display League Leaders (Top 10)." << endl << endl;
            
           
                std::sort(league.begin(), league.end(), compare_points);
            
                cout << "*** Points Per Game ***" << endl << endl;
            
                for(int i = 0; i < 10; i++) {
                
                
                    cout << i+1 << ". " << league[i].get_first_name() << " " << league[i].get_last_name() << endl;
                
                    cout << "Points Per Game: " << league[i].get_points() << endl << endl;
                
                
            
                }
            
                cout << "*** Rebounds Per Game ***" << endl << endl;
                
                std::sort(league.begin(), league.end(), compare_rebounds);
                
                for(int i = 0; i < 10; i++) {
                    
                    
                    cout << i+1 << ". " << league[i].get_first_name() << " " << league[i].get_last_name() << endl;
                    
                    cout << "Rebounds Per Game: " << league[i].get_rebounds() << endl << endl;
                    
                    
                    
                }
                
                cout << "*** Assists Per Game ***" << endl << endl;
                
                std::sort(league.begin(), league.end(), compare_assists);
                
                for(int i = 0; i < 10; i++) {
                    
                    
                    cout << i+1 << ". " << league[i].get_first_name() << " " << league[i].get_last_name() << endl;
                    
                    cout << "Assists Per Game: " << league[i].get_assists() << endl << endl;
                    
                    
                    
                }
                
                cout << "*** Blocks Per Game ***" << endl << endl;
                
                std::sort(league.begin(), league.end(), compare_blocks);
                
                for(int i = 0; i < 10; i++) {
                    
                    
                    cout << i+1 << ". " << league[i].get_first_name() << " " << league[i].get_last_name() << endl;
                    
                    cout << "Blocks Per Game: " << league[i].get_blocks() << endl << endl;
                    
                    
                    
                }
                
                
                cout << "*** Steals Per Game ***" << endl << endl;
                
                std::sort(league.begin(), league.end(), compare_steals);
                
                for(int i = 0; i < 10; i++) {
                    
                    
                    cout << i+1 << ". " << league[i].get_first_name() << " " << league[i].get_last_name() << endl;
                    
                    cout << "Steals Per Game: " << league[i].get_steals() << endl << endl;
                    
                    
                    
                }
                

                break;
            
        
            case 'a':
            
            
                cout << "Display Team Leaders." << endl << endl;
            
           
                cout << "Input team name: ";
            
                //skips any initial whitespace
                std::cin >> std::ws;
                
                
                
                std::getline(std::cin,a_team);
            
           
                cout << endl;
            
            
                //Make sure team name is correct format
            
                for(int i = 1; i < a_team.size(); i++) {
                
                
                    a_team[0] = toupper(a_team[0]);
                
                    a_team[i] = tolower(a_team[i]);
                
            
                }
            
            
            
            
            
                for(int i = 0; i < league.size(); i++) {
                
                
                    if(league[i].get_team() == a_team) {
                    
                    
                        team1.add(league[i]);
                    
                        found1 = 1;
                    
                
                    }
                
            
                }
            
            
                if(found1 == 1) {
            
               
                
                
                    cout << "Points Leader: " << team1.points_leader().get_first_name() << " " <<
                    team1.points_leader().get_last_name() << " " << team1.points_leader().get_points() << " points per game." << endl << endl;
            
            
                
                    cout << "Rebounds Leader: " << team1.rebounds_leader().get_first_name() << " " <<
                    team1.rebounds_leader().get_last_name() << " " << team1.rebounds_leader().get_rebounds()
                    << " rebounds per game." << endl << endl;
            
            
                
                    cout << "Assists Leader: " << team1.assists_leader().get_first_name() << " " <<
                    team1.assists_leader().get_last_name() << " " << team1.assists_leader().get_assists() << " assists per game." << endl << endl;
            
            
                
                    cout << "Blocks Leader: " << team1.blocks_leader().get_first_name() << " " <<
                    team1.blocks_leader().get_last_name() << " " << team1.blocks_leader().get_blocks() << " blocks per game." << endl << endl;
            
            
                
                    cout << "Steals Leader: " << team1.steals_leader().get_first_name() << " " <<
                    team1.steals_leader().get_last_name() << " " << team1.steals_leader().get_steals() << " steals per game." << endl << endl;
            
               
                }
            
            
                
                else {
                
                
                
                    cout << "Team not found!" << endl << endl;
                
            
                
                }
            
            
                
                break;
            
        
            
            case 't':
        
            
            
            cout << "Display Team Stats." << endl << endl;
            
            
                cout << "Input team name: ";
                
                //skips initial whitespace if any
                std::cin >> std::ws;
                
                std::getline(std::cin,a_team);
            
            
            
                //Make sure team name is correct format
            
                for(int i = 1; i < a_team.size(); i++) {
                
                
                    a_team[0] = toupper(a_team[0]);
                
                    a_team[i] = tolower(a_team[i]);
                
                
                    if(a_team[i-1] == 32) {
                    
                    
                        a_team[i] = toupper(a_team[i]);
                    
               
                    }
                
            
                }
            
            
            
         
            
                for(int i = 0; i < teams_vector.size(); i++) {
                
                
                    if(teams_vector[i].get_team_name() == a_team) {
                    
                    
                        count++;
                    
                        team1 = teams_vector[i];
                    
                    
                
                    }
            
                }
            
            
                
                if(count == 0) {
                    
                    
                    cout << endl;
                    
                    cout << "Team not found." << endl << endl;;
                    
                    teams.close();
                    
                    break;
                    
               
                }
                
            
                cout << endl;
            
                cout << "Team: " << team1.get_team_name() << endl;
            
                cout << "City: " << team1.get_city() << endl;
            
                cout << "Points: " << team1.get_team_points() << endl;
            
                cout << "Rebounds: " << team1.get_team_rebounds() << endl;
            
                cout << "Assists: " << team1.get_team_assists() << endl;
            
                cout << "Blocks: " << team1.get_team_blocks() << endl;
            
                cout << "Steals: " << team1.get_team_steals() << endl << endl;

            
                break;
            
        
            case 'c':
            
            
                cout << "Compare Two Players." << endl << endl;
            
            
                cout << "Please enter Player 1's first name: ";
            
                
                //skips initial whitespace if any
                std::cin >> std::ws;
                
                std::getline(std::cin, a);
            
            
                //Makes player 1 first name all lower-case for searc purposes
            
                for(int i = 0; i < a.size(); i++) {
                
                
                
                    a[i] = tolower(a[i]);
                
            
                }
            
            
                cout << "Please enter Player 1's last name: ";
            
                //skips initial whitespace if any
                std::cin >> std::ws;

                std::getline(std::cin, b);
            
            
                //Makes player 1 last name all lower-case for search purposes
            
                for(int i = 0; i < b.size(); i++) {
                
            
                
                    b[i] = tolower(b[i]);
                
            
                }
            
            
            
                cout << "Please enter Player 2's first name: ";
            
                //skips initial whitespace if any
                std::cin >> std::ws;

                std::getline(std::cin, c);
            
            
                //Makes player 2 first name all lower-case for search purposes
            
                for(int i = 0; i < c.size(); i++) {
                
                
                
                    c[i] = tolower(c[i]);
                
            
                }
            
            
                cout << "Please enter Player 2's last name: ";
            
                //skips initial whitespace if any
                std::cin >> std::ws;

                std::getline(std::cin, d);
            
            
                //Makes player 2 last name all lower-case for search purposes
            
                for(int i = 0; i < d.size(); i++) {
                
                
                
                    d[i] = tolower(d[i]);
                
            
                }
            
            
            
            //Loops through all players, makes their name lower case, then checks to see if match found
                for(int i = 0; i < league.size(); i++) {
                
                
                
                
                    string x = league[i].get_first_name();
                
                    string first1 = "";
                
                    string y = league[i].get_last_name();
                
                    string last1 = "";
                
                    string z = league[i].get_first_name();
                
                    string first2 = "";
                
                    string q = league[i].get_last_name();
                
                    string last2 = "";
                
                
                    for(char c : x){
                    
                    
                        c = tolower(c);
                    
                        first1 += c;
                
                    }
                
                
                    for(char c : y) {
                    
                    
                        c = tolower(c);
                    
                        last1 +=c;
                
                    }
                
                
                    for(char c : z) {
                    
                    
                        c = tolower(c);
                    
                        first2 += c;
                    
                
                    }
                
                
                    for(char c: q) {
                    
                    
                        c = tolower(c);
                   
                        last2 += c;
                    
                
                    }
                
                
                    if((first1 == a) && (last1 == b)){
                    
                    
                        player1 = league[i];
                    
                        found1++;
                
                    }
                
            
                    else if ((first2 == c) && (last2 == d)) {
                    
                    
                        player2 = league[i];
                    
                        found2++;
                    
               
                    }
                
                
            
                }
            
            
                if(found1 == 0) {
                
                
                    cout << endl;
                
                    cout << "Player 1 Not Found!" << endl << endl;
                
                    break;
                
                }
            
            
                if(found2 == 0) {
                
                
                    cout << endl;
                
                    cout << "Player 2 Not Found!" << endl << endl;
               
                    break;
                
            
                }
            
            
                //Uses overloaded == to compare the 2 players
           
                player1 == player2;
            
           
                break;
            
        
            case 'p':
            
           
                cout << "Search By Player.  There are " << Athlete::player_count << " players in the league!" << endl << endl;
            
            
                cout << "Input player's first name: ";
            
                //skips initial whitespace if any
                std::cin >> std::ws;
                
                std::getline(std::cin, a);
            
            
                //Makes player first name all lower-case for search purposes
            
                for(int i = 0; i < a.size(); i++) {
                
                
                
                    a[i] = tolower(a[i]);
                
            
                }
            
            
                cout << "Input player's last name: ";
            
                //skips initial whitespace if any
                std::cin >> std::ws;
                
                std::getline(std::cin, b);
            
            
                //Makes player last name all lower-case for search purporses
            
                for(int i = 0; i < b.size(); i++) {
                
                
                
                    b[i] = tolower(b[i]);
                
           
                }
            
                //Loops through all players, makes their name lower case, then checks to see if match found
                for(int i = 0; i < league.size(); i++) {
                
               
                    string x = league[i].get_first_name();
                
                    string first1 = "";
                
                    string y = league[i].get_last_name();
                
                    string last1 = "";
                
                
                    for(char c : x){
                    
                    
                        c = tolower(c);
                    
                        first1 += c;
                
                    }
                
               
                    for(char c : y) {
                    
                    
                        c = tolower(c);
                    
                        last1 +=c;
                
                    }
                
               
                    if((first1 == a) && (last1 == b)){
                    
                   
                        player1 = league[i];
                   
                        found1++;
                        
                       break;
               
                    }

            
                }
            
           
                if(found1 == 0) {
                
                
                    cout << endl;
                
                    cout << "Player not found!" << endl << endl;
                
                    break;
                
            
                }
            
            
                else{
                
                
                    cout << endl << endl;
                
                    player1.get_info();
                
                    cout << endl;
                
           
                
                }
            
            
                
                break;
            
       
            case 'b':
                
            
                cout << "Enter Team 1: ";
            
                //skips initial whitespace if any
                std::cin >> std::ws;
                
                getline(std::cin, team_name1);
            
            
                for(int i = 1; i < team_name1.size(); i++) {
                
                
                    team_name1[0] = toupper(team_name1[0]);
                
                    team_name1[i] = tolower(team_name1[i]);
                
                
                    if(team_name1[i-1] == 32) {
                    
                    
                        team_name1[i] = toupper(team_name1[i]);
                    
               
                    }
                
            
                }
            
                
                
           
                cout << "Enter Team 2: ";
            
                //skips initial whitespace if any
                std::cin >> std::ws;
                
                getline(std::cin, team_name2);
            
            
                for(int i = 1; i < team_name2.size(); i++) {
                
               
                    team_name2[0] = toupper(team_name2[0]);
                
                    team_name2[i] = tolower(team_name2[i]);
                
                
                    if(team_name2[i-1] == 32) {
                    
                    
                        team_name2[i] = toupper(team_name2[i]);
                    
                
                    }
                
            
                }
            
                
                
           
                for(int i = 0; i < teams_vector.size(); i++) {
                

                
                
                    if(teams_vector[i].get_team_name() == team_name1) {
                    
                    
                        team1 = teams_vector[i];
                    
                        team_found1++;
                    
                
                    }
                
               
                    if(teams_vector[i].get_team_name() == team_name2) {
                    
                    
                        team2 = teams_vector[i];
                    
                        team_found2++;
                    
                
                    }
                
            
                }
                
               
                if(team_found1 == 0) {
                    
                    
                    cout << endl;
                    
                    cout << "Team 1 Not Found!" << endl << endl;
                    
                    break;
                }
            
                if(team_found2 == 0) {
                    
                    cout << endl;
                    
                    cout << "Team 2 Not Found!" << endl << endl;
                    
                    break;
                    
                }
                
                team1 == team2;
                
                break;
            
        
           case 'q':
        
        
                cout << "Bye!" << endl << endl;
            
                running = false;
                
                break;
                
        
            default:
            
            
                cout << "Not a valid choice!" << endl << endl;
            
            
                break;
    
        }
 
    }
    
   
}

//Compare friend functions used in the sort algorithm to display league leaders
bool compare_points(Player& left, Player& right) {
    
    return left.points > right.points;
    
}

bool compare_rebounds(Player& right, Player& left) {
    
    return left.rebounds < right.rebounds;
    
}

bool compare_assists(Player& right, Player& left) {
    
    return left.assists < right.assists;
    
}

bool compare_blocks(Player& right, Player& left) {
    
    return left.blocks < right.blocks;
    
}

bool compare_steals(Player& right, Player& left) {

    return left.steals < right.steals;
    
}
