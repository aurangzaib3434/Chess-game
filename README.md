
Zohaib Hassaan:

Commit Description:

In this commit, I set up the main game board.


I initialized the 2D array and dynamically allocated all the pieces to their correct starting coordinates on the board to prepare for the game loop.



Commit Title: Add colored console GUI, game loop, and win-condition 

Commit Description:

In this commit, I finalized the game engine and UI. I implemented the colored console output, managed the turn-based user input loop, and added the King capture logic to trigger the game-over condition.



Tehreem Zahra:

Commit Title: Add base Piece class and define polymorphic structure 


Commit Description :

In this commit, I created the core foundation of our OOP Chess game.


I set up the abstract base Piece class, defined fundamental properties like piece color and symbols, and created the virtual isValidMove function to enable polymorphism for the rest of the project.





 Aurang Zaib :
Commit Title: Implement specific movement rules and path-clearing logic 


Commit Description :
In this commit, I handled the game rules for all chess pieces.


I used inheritance to implement specific movement logic for each piece (e.g., L-shape for Knight, diagonals for Bishop).


I also added the isPathClear helper function to prevent pieces from jumping over each other.



