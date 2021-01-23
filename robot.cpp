#include "robot.h"

using namespace std;

robot::robot(int robot_id, int team_id, int pos_x, int pos_y) : robot_id_(robot_id), team_id_(team_id), initial_position_(pos_x, pos_y) {
    current_position_.set_x(pos_x);
    current_position_.set_y(pos_y);
}

void robot::turnleft() {
    if (direction_facing_ == "N") {
        direction_facing_ = "W";

    } else if (direction_facing_ == "W") {
        direction_facing_ = "S";

    } else if (direction_facing_ == "S") {
        direction_facing_ = "E";

    } else if (direction_facing_ == "E") {
        direction_facing_ = "N";
    }
}

void robot::turnright() {
    if (direction_facing_ == "N") {
        direction_facing_ = "E";

    } else if (direction_facing_ == "W") {
        direction_facing_ = "N";

    } else if (direction_facing_ == "S") {
        direction_facing_ = "W";

    } else if (direction_facing_ == "E") {
        direction_facing_ = "S";
    }
}

/**
 * Calculates where the next step of the robot is depending on the direction is facing.
 * @param steps the number of steps to calculate from current position
 * @return coordinates of next position
 */
point robot::next_move_point(int steps){
    point next_space(0,0);

    if (direction_facing_ == "N") {
        next_space = point(current_position().x(),current_position().y()+steps);
    }
    else if (direction_facing_ == "E") {
        next_space = point(current_position().x()+steps, current_position().y());
    }

    else if (direction_facing_ == "S") {
        next_space = point(current_position().x(), current_position().y()-steps);
    }

    else if (direction_facing_ == "W") {
        next_space = point(current_position().x()-steps, current_position().y());
    }

    return next_space;
}
/**
 * Moves the robot by the number specified by steps in the direction is facing.
 */
void robot::move(int steps) {
    current_position_ = next_move_point(steps);
    step_count_ += steps;
}

/**
 * Return true if robots are part of the same team, false otherwise.
 */
bool are_enemies(robot& bot1, robot& bot2){
    if (bot1.team_id() != bot2.team_id()) {
        return true;
    }
    return false;
}