#ifndef ROBOT_H
#define ROBOT_H
#include "point.h"

/**
 * A robot in a 2-d environment
 */
class robot {
    point initial_position_;
    point current_position_;
    int robot_id_;
    int team_id_;
    std::string direction_facing_ = "N";
    bool destroyed_ = false;
    int step_count_ = 0;


public:
    robot(int robot_id, int team_id, int pos_x, int pos_y);

    //getters
    point initial_position() const { return initial_position_; }
    point current_position() const { return current_position_; }
    int id() const { return robot_id_; }
    int team_id() const { return team_id_; }
    std::string direction_facing() const {return direction_facing_; };
    bool destroyed() const { return destroyed_; }
    int step_count() const {return step_count_;}

    //setters
    void set_current_position(int x, int y) {
        current_position_ = point(x,y);
    }

    void set_destroyed(bool new_state) {
        destroyed_ = new_state;
    }

    void increment_step_count(int x){
        step_count_ += x;
    }

    void turnleft();
    void turnright();
    point next_move_point(int steps);
    void move(int steps);

};
bool are_enemies(robot& bot1, robot& bot2);

#endif