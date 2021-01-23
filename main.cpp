#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

#include "robot.h"
#include "commands.h"

using namespace std;

/**
 * Splits the string at space into a vector
 * @param initialStr initial string
 * @return vector, where each entry is a word/character
 */
vector<string> separate_at_space(const string& initialStr) {
    vector<string> v;
    stringstream string_stream(initialStr);
    while (string_stream.good()) {
        string temp;
        getline(string_stream, temp, ' ');
        v.push_back(temp);
    }
    return v;
}

int main() {
    vector<robot> all_robots;

//-----reading from start.txt and creating robot objects in vector all_robots
    string start_line;
    ifstream start_file("start.txt");

    int robot_id, team_id, pos_x, pos_y;

    if (start_file.is_open()) {
        while (start_file >> robot_id >> team_id >> pos_x >> pos_y) {

            //creating a robot object and pushing it to the vector
            all_robots.emplace_back(robot_id, team_id, pos_x, pos_y);
        }
        start_file.close();
    }



//-----reading from commands.txt and applying each command
    string command_line;
    ifstream command_file("commands.txt");

    if (command_file.is_open()) {
        while (getline(command_file, command_line)) {
            vector<string> command = separate_at_space(command_line);

            // calling the appropriate function for each command
            if (command[0] == "show") {
                show(all_robots);
            } else if (command[0] == "travelled") {
                travelled(all_robots);

            } else if (command[0] == "within") {
                within(stoi(command[1]), all_robots);

            } else if (command[0] == "turnleft") {
                turnleft(stoi(command[1]), all_robots);

            } else if (command[0] == "turnright") {
                turnright(stoi(command[1]), all_robots);

            } else if (command[0] == "move") {
                move(stoi(command[1]), all_robots);

            }
        }
        command_file.close();
    }
    return 0;
}