# RobotWarCoursework
This coursework was part of the C++ module I took in my second year. 
The task is to implement a robot war, in which a large number of robots, grouped into several teams, move around in 2-dimensional space. The program will read as input two files, start.txt and commands.txt, and produce output on the standard output.

The initial state of the system is described by a file start.txt, each line of which will contain four numbers identifying a robot, its team, and its initial position, e.g. 1673 2 53 -89. 
This says that robot 1673 belongs to team 2 and starts with x-coordinate 53 and y-coordinate -89. Robots and teams are indentified by positive whole numbers; coordinates are also whole numbers, but may be negative.
At any time, each robot will be facing north, east, south or west. All robots start off facing north. We assume a conventional 2-dimensional space, so one step north from (53, -89) is (53, -88), while one step east would be (54, -89).

The program should then read commands.txt, acting on each line as it is read. The lines have the following forms and meanings, where r stands for a robot number. If the named robot does not exist, the command should be silently ignored. An exmple of a command:

within n: Print out the number of robots within n steps of the origin. (That is, the distance is n or less.) You should print the number on a line by itself, with no extra text. Distance here is the sum of the absolute values of the x- and y-coordinates (the Manhattan metric), so the distance to (2, -5) is 7.
