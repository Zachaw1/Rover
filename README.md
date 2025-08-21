# Rover
I am pretending to write some logic for a rover that will land on Mars and will need to be remotely navigated. The terrain will be mapped to a 5x5 square totaling 25 cells to which the rover will need the ability to navigate to.
The rover will start in the center square which will be referenced as position (0,0) or (X,Y). When moving up one vertical positional square from (0,0) the new position would be (0,1). Moving right one position would put the rover at (1,0), moving one square to the left from center would place it at (-1,0) and one space down from center would put the new position at (0,-1).
I want to allow the rover to be navigated from the starting position of (0,0) to user-specified coordinates and output the current position to the user via a command line output.
