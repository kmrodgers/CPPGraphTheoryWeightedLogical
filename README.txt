README
Text-Based Graph Theory Logging Program

This is a text-based game for running Monte Carlo simulations for Petersen Graphs and Complete Graphs (more in development). 

For Petersen Graphs, This program allows the user to select the weight of the edges between the nodes. 

For Complete Graphs, this program allows users to select the number of nodes and the weight between the nodes.

To run this on OS X, you need to install Xcode for the C++ compiler. 

To run this game (assuming using OS X):

Double-click "Start.command"

In “output_data”, the following files will be created after the program has run:
“master_data.txt”, “player1_moves.txt”, “player2_moves.txt”, "player1_unique_moves, "player2_unique_moves", and “results.txt”.

“master_data.txt” - This is the raw, unsorted, unparsed data at outputted by the program. The last number at the end of the string is the winner of this game. It is 
written in the following format: 1-1-2-1–3-1-4, and can be read as: “Starting node” - “Weight removed” - “Ending node”: where move 1 is from 1 to 2 removing weight 1, move 2 is from 2 - 3 removing weight 1, etc.

“player1_moves” - All the player one moves after the analysis algorithm is run

“player2_moves” - All the player two moves after the analysis algorithm is run

"player1_unique_moves" - All the player one unique moves

"player2_unique_moves" - All the player two unique moves

“results.txt” - Same output of the results as what is at the end of the Terminal

NOTE: You must move these four files into a separate folder in “output_data” or out of “output_data”. The way this program works is by adding onto the end of the files 
already there.

Author: Kyle Rodgers
Email: krodgers@ole.augie.edu
