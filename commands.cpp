#include <algorithm>
#include <iostream>

#include "commands.h"

using namespace std;

/*
 * Compares the robot_id, returns true if bot1.robot_id is larger
 */
bool compare_id(robot& bot1, robot& bot2) {return (bot1.id() < bot2.id()); }

/*
* Print all the robots still in the system in ascendind order of robot id.
*/
void show(vector<robot>&  all_robots) {
    vector<robot> copy_vector = all_robots;
    sort(copy_vector.begin(), copy_vector.end(), compare_id);

    for (robot& bot : copy_vector) {
        if (!bot.destroyed()) {
            cout << bot.id() << " " << bot.team_id() << " " << bot.current_position().x() << " " <<
            bot.current_position().y() << endl;
        }
    }
}

/*
 * Compares the steps taken of bot1 and bot2.
 * If the number of steps is equal, compare their robot number.
 */
bool compare_distance_travelled(robot& bot1, robot& bot2) {
    if (bot1.step_count() != bot2.step_count()) {
        return bot1.step_count() < bot2.step_count();

    } else { //this orders the robots by robot number if the number of steps taken is the same.
        return (bot1.id() < bot2.id());
    }
}

/**
 * Lists all the robots in the system, each with the total distance it has travelled.
 * Each line of the output consists of two numbers, the robot number and the distance travelled,
 * and they are in increasing order of distance travelled. If two robots have travelled the same
 * distance, they are ordered by robot number.
 * @param all_robots
 */
void travelled(vector<robot>& all_robots){
    vector<robot> copy_vector = all_robots;

    //sort by distance travelled
    sort(copy_vector.begin(), copy_vector.end(), compare_distance_travelled);
    for (robot& bot: copy_vector) {
        if (!bot.destroyed())
        cout << bot.id() << " : " << bot.step_count() << endl;
    }
}

/*
 * Print out the number of robots within n steps of the origin using the Manhattan metric
 */
void within(int n, vector<robot>& all_robots) {
    int count = 0;
    for (robot& bot: all_robots) {
        int distance = manhattan_distance(bot.current_position(),point(0,0));
        if (distance <= n) {
            count++;
        }
    }
    cout << count << endl;
}

/*
 * Turns the robot to the left once
 */
void turnleft(int robot_id, vector<robot>& all_robots) {
    for (robot& bot: all_robots) {
        if (bot.id() == robot_id) {
            //we found the robot, now change direction it is facing
            bot.turnleft();
            break;
        }
    }
}

/*
 * Turns the robot to the right once
 */
void turnright(int robot_id, vector<robot>& all_robots) {
    for (robot& bot: all_robots) {
        if (bot.id() == robot_id) {
            //we found the robot, now change direction it is facing
            bot.turnright();
            break;
        }
    }
}

/**
 * Attempt to move robot r one step in the direction it is facing.
 * If the target location is already occupied by a robot on the same team, no move is possible,
 * and the robot stays where it was. If the target location is occupied by a robot of another team,
 * that robot should be removed from the system, after which our robot moves.
 * @param robot_id robot to move
 * @param all_robots all the robots in the system
 */
void move(int robot_id, std::vector<robot>& all_robots) {
    point next_space(0,0);
    bool bot_moved = false;

    for (robot& current_bot: all_robots) {
        if (current_bot.id() == robot_id) { //specific robot found
            next_space = current_bot.next_move_point(1);

            //is the next space occupied?
            for (robot& other_bot: all_robots){

                //if the coord of the next space match with the position of another robot, then there is a robot on the next step
                if ( (next_space.x() == other_bot.current_position().x()) && (next_space.y() == other_bot.current_position().y()) && !(other_bot.destroyed()) ){

                    if (are_enemies(current_bot, other_bot)) { //they are enemies, destroy other bot and move current bot
                        other_bot.set_destroyed(true);
                        bot_moved = true;
                        current_bot.move(1);
                    }
                    break;
                }
            }
            //has the robot already moved?
            if (!bot_moved) {
                current_bot.move(1);
            }
            break;
        }
    }
}
