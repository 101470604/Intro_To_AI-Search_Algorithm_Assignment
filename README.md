# README 

This program is a project for the subject COS30019 - Introduction to AI as part of my 
formal education at Swinburne University of Technology. The purpose of this program is 
to take in a grid layout specified in a .txt file and utilize a user selected search algorithm 
to determine a series of steps that will lead to an goal coordinate. 

## REQUIREMENTS

To run this program you will need a PC with software for running bash scripts installed
and a .txt file in the following format:

[grid_width, grid_height] </br>
[(starting_x, starting_y) </br>
(goal_1_x, goal_1_y) | (goal_2_x, goal_2_y) </br>
(wall_1_x, wall_1_y, wall_1_width, wall_1_height) </br>
(wall_2_x, wall_2_y, wall_2_width, wall_2_height) </br>
(wall_3_x, wall_3_y, wall_3_width, wall_3_height) </br>

Each variable placeholder must be replaced with 1 whole integer, NO DOUBLES
Any deviatons from this format will return an error. 

## HOW TO USE

1. Open the command line in windows & navigate to installation directory 
2. Run with the following command: ./search <grid_file.txt> <method>

<grid_file.txt> = the txt file specifying the layout of the grid. Must fit previously stated format. 
<method> = the name of the search algorithm to be used. 

The following are a list of valid method name inputs & their full name:
BFS - Breadth first search 
DFS - Depth first search 
GBFS - Greedy best first search 
A* - A Star search 
BS - Beam Search

FOR EXAMPLE: C:\Assignment_1 ./search grid.txt BFS

### ADDITIONAL PARAMETERS 

At the end of any valid argument, appending either of the following options will 
execute the program with additional functionality:

visualize  - Prints a textual representation of the grid & search to the terminal
pcheck     - Prints the execution time in milliseconds before the path

e.g:
/Assignment_1.exe A* text.txt visualize pcheck

