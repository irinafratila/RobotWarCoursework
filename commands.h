#ifndef COMMANDS_H
#define COMMANDS_H

#include <string>
#include <vector>
#include "point.h"
#include "robot.h"

class commands {
public:
    commands() = default;
};

void show(std::vector<robot>& all_robots);
void travelled(std::vector<robot>& all_robots);
void within(int n, std::vector<robot>& all_robots);
void turnleft(int robot_id, std::vector<robot>& all_robots);
void turnright(int robot_id, std::vector<robot>& all_robots);
void move(int robot_id, std::vector<robot>& all_robots);

#endif