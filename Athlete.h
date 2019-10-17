

#ifndef Athlete_h
#define Athlete_h
#include <string>

using std::string;

class Athlete {

private:
    
    string first_name;
    string last_name;
    string height;
    string position;
    
    
public:
    
    Athlete(string first, string second, string height, string position);
    string get_first_name();
    string get_last_name();
    string get_height();
    string get_position();
    static int player_count;

    void set_first_name(string);
    void set_last_name(string);
    void set_height(string);
    void set_position(string);
    virtual void get_info();
    
};



#endif /* Athlete_h */
