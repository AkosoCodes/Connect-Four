#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define x 7
#define y 6
#define matchSize 4

#define checkerPlayer1 'X'
#define checkerPlayer2 'O'
#define checkerWinner 'Y'
#define Saves "SAVES.txt"

//      Normal Comment
//*     Highlighted Comment
//!     Alert Comment
//?     Query Comment
//      TODO A to do comment

//------------------------------------------------------------------------------------------------

//! VARIABLES
int board[y][x]; 
char PLAYER_1[18]; 
char PLAYER_2[18]; 

int menuOption; 
int returnToMenu;

int result = 0;
int choice = 0;
int currentPlayer;
int gameResult;


//! FUNCTIONS
void startMenu(); // Main Menu
void loadMenu(); // Load Menu
void rules(); // Rules Tab
void infoAndrija(); // Info Tab
void endMenu(); // End Menu

int gameLoop(); // Game Loop
void showBoard(); // Shows the board
void clearBoard(); //Clears Board
bool addChecker(int Column, int _checker); // Adds Checkers

void newGame(bool loadedGame); // New Game
void loadGame(); // Load Game
void saveGame(); // Save Game

int boardState(); // Checks the state of the Board
bool CheckForMatches(int Row, int Column, int RowPattern, int ColumnPattern); // Checks for win condition
void fillInMatch(int Row, int Column, int RowPattern, int ColumnPattern); // Replaces checker for Y

bool loadData(int Mode, int Id, char *Name); // Loads Save File
void listSavedGames(); // Shows all saved games
void listSavedPlayer(); // Shows all saved games of a certain player
void showBoardID(); // Displays certain board

void clear(); // Clears the terminal
bool invalidChar(char *String, char invalidChar); // Checks for invalid characters
void exitGame(int Code); // Exit Game


int main(){

    //Starts the program with the Start Menu
    startMenu();

    return 0;
}


//*===================================================
//*                Main Menu Functions
//*===================================================

//! START MENU 
void startMenu(){

    //* Do-While loop makes sure that it is repeated until the user makes a valid input.
    do
    {
        clear(); // clears the terminal

        // Prints the Menu and options.
        printf("\n"); 
        printf("              -=- Connect Four -=-       \n");
        printf("           What would you like to do?    \n");
        printf("        +=============================+  \n");
        printf("        |   1. New Game               |  \n");
        printf("        |   2. Load Saved Game        |  \n");
        printf("        |   3. How to play?           |  \n");
        printf("        |   4. Information            |  \n");
        printf("        |   5. Exit Game              |  \n");
        printf("        +=============================+  \n");

        scanf("%d",&menuOption); //Scans for player input

       
        fflush(stdin);  //Flushes the input and clears the buffer so that a infinite loop doesn't occur.

    } while (menuOption > 5 || menuOption < 1);     
    //Checks whether the input is valid. in the case that it is not valid, the whole loop will repeat.


    //* Switch scans the previous input and assigns it to the particular case.
    switch (menuOption)
    {

        case 1: // Starts a New Game
            newGame(false);
        break;

        case 2: // Opens the Load Game Menu
            loadMenu();
        break;

        case 3: // Opens the Rules tab
            rules();
        break;

        case 4: // Opens information about me - Andrija :D
            infoAndrija();
        break;

        case 5: // Opens the Exit Game function.
            endMenu();
        return;
    }
}

//! LOAD MENU
void loadMenu(){

    do
    {
    
        clear(); // clears the terminal

        //Prints the Menu and options.
        printf("\n");
        printf("              -=- Connect Four -=-       \n");
        printf("           What would you like to do?    \n");
        printf("        +=============================+  \n");
        printf("        |   1. Load Game              |  \n");
        printf("        |   2. List all saved games   |  \n");
        printf("        |   3. List all Players       |  \n");
        printf("        |   4. Show a Board with ID   |  \n");
        printf("        |   5. Return to Main menu    |  \n");
        printf("        +=============================+  \n");

        scanf("%d",&menuOption); // Scans for player input

        
        fflush(stdin); // Flushes the input and clears the buffer so that a infinite loop doesn't occur.

    } while (menuOption > 5 || menuOption < 1);
    
    switch(menuOption){

        case 1: // Loads a saved game
            loadGame();
        break;

        case 2: // Lists all the saved games from the save file.
                
                clear(); // clears the terminal

                printf("\n");
                printf("                -=- All Saves -=-      \n");
                printf("        +=============================+\n");
                listSavedGames(); //* List Saves Games Function
                printf("        +=============================+\n");
                system("pause");
                loadMenu();
        break;

        case 3: // Lists all the saved players from the save file.
                clear();
                listSavedPlayer(); //* List Saves by Player Function
                system("pause");
                loadMenu();
        break;

        
        case 4: // Shows a specific Board with ID
            showBoardID(); //* Shows a Board with ID Function
            loadMenu();
        break;

        case 5: // Returns back to Starting Menu
            startMenu();
        break;
    }
}

//! RULES
void rules(){

    do
    {
        clear();

        printf("\n");
        printf("                              -=- Connect Four -=-                               \n\n");

        //Description
        printf("Description:\n\n");
        printf("This game is played on a vertical board wich has seven hollow columns and six rows.\nEach column has a hole in the upper part of the board, where pieces are introduced.\nThere is a window for every square, so that pieces can be seen from both sides.\n\n");
    
        //Objective
        printf("Objective:\n\n");
        printf("The aim for both players is to make a straight line of four own pieces.\nThe line can be vertical, horizontal or diagonal.\n\n");
        
        printf("1. Return to Main Menu: ");
        scanf("%d", &returnToMenu);

    } while (returnToMenu != 1);

    if(returnToMenu == 1){
        startMenu();
    }
}

//! INFORMATION
void infoAndrija(){

    do
    {
        clear(); // clears the termina

        printf("\n");
        printf("                        -=- Information -=-         \n");
        printf("\n");
        printf("                This whole program was written by   \n");
        printf("                 Andrija Stankovic - 2020230164     \n");
        printf("\n");

        printf("1. Return to Main Menu: ");
        scanf("%d", &returnToMenu); // Scans for player input

        
        fflush(stdin); // Flushes the input and clears the buffer so that a infinite loop doesn't occur.
        } while (returnToMenu != 1);
        
        startMenu();
}

//! END MENU
void endMenu(){

    do
    {
        clear();

        printf("\n");
        printf("Are you sure you want to quit?  \n");
        printf("1. No, take me back.            \n");
        printf("2. Yes, quit the game.          \n");

        scanf("%d", &returnToMenu); // Scans for player input

    } while (returnToMenu > 2 || returnToMenu < 1);

    if(returnToMenu == 1){
        startMenu();
    } else 
    exitGame(0);
}




//*===================================================
//*                     Game Logic
//*===================================================

//! GAME LOOP
int gameLoop(){

    int choice = -1; // Player Input
    int check = 0; // Check Board Input

    while(true){
        
        clear(); // clears the terminal
        check = boardState();

        //Displays the board
        showBoard();

        if(check == 0) {
            
            choice = -1; // resets the choice

            printf("It is %s's turn to play. \n", currentPlayer ? PLAYER_2 : PLAYER_1);
            printf("Select a column (1-%d) or press 0 to save: ", x);

            scanf("%d", &choice); //Get player input

            fflush(stdin); //Flushes the input and clears the buffer so that a infinite loop doesn't occur.

            if (choice > 0 && choice <=x){
                
                if (addChecker(choice, currentPlayer + 1)){
                    currentPlayer = !currentPlayer; //If we successfully added a checker, change the player
                } else{

                    //If we did not add the checker, then inform that the column is full.
                    printf("Column %d is full, please select a valid column.\n", choice);
                    system("pause");
                }
            } else if(choice == 0){

                //Saves the game and pauses
                saveGame();
                system("pause");
            } else {

                //If the input was not 0, nor in range of the board, the player made an invalid choice
                printf("****Invalid choice****\n");
                system("pause");
            }  
        } else {

            //If our check returns anything other than 0, that means the game came to an end and pass that value back to StartGame
            return check;
        }
    }

    return 0;
}

//! SHOW BOARD
void showBoard(){

        clear(); // clears the terminal

        //For loop to print horizontal border.      
        for(int i = 0; i<y; i++){

            printf("+");

            for(int k=0; k<x; k++){
                printf("===+");      
            } 
            printf("\n");


            //For loop to print vertical border.  
            printf("|");
            for (int j = 0; j<x; j++){

                switch (board[i][j]){
                    case 1:
                        printf(" %c ", checkerPlayer1);
                        break;

                    case 2:
                        printf(" %c ", checkerPlayer2);
                        break;

                    case 3:
                        printf(" %c ", checkerWinner);
                        break;

                    default:
                        printf("   ");
                        break;

                }
                //ends a column
                printf("|");
                
            }
            printf("\n");
        }

        //For loop to print final horizontal border.
            printf("+");

            for(int k=0; k<x; k++){
                printf("===+");      
            }
            printf("\n");
}

//! CLEAR BOARD
void clearBoard(){
    //Goes from one element to another and sets it to 0.
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            board[i][j] = 0;
        }
    }
}

//! ADD CHECKER
bool addChecker(int Column, int _checker) {

    //Loop through elements vertically
    for (int i = y - 1; i >= 0; i--) {
        if (board[i][Column - 1] == 0) {
            
            board[i][Column - 1] = _checker; // If we find an empty slot, add a checker
            
            return true; // If successfully added a checker, return TRUE.
        }
    }
    //If we cannot add checker, return FALSE.
    return false;
}




//*===================================================
//*                  Win Conditions
//*===================================================

//! BOARD STATE
int boardState(){

    int winner = 0;

    // Horizontal (-) check
    for (int i = y - 1; i >= 0; i--) {
        for (int j = 0; j <= x - matchSize; j++) {
            //Check if there are any matches
            if (CheckForMatches(i, j, 0, 1)) {
                //If we got a match return the winner and mark the winning match
                winner = board[i][j];
                fillInMatch(i, j, 0, 1);
                return winner;
            }
        }
    }

    // Vertical (|) check
    for (int i = y - 1; i >= (matchSize - 1); i--) {
        for (int j = 0; j < x; j++) {
            //Check if there are any matches
            if (CheckForMatches(i, j, -1, 0)) {
                //If we got a match return the winner and mark the winning match
                winner = board[i][j];
                fillInMatch(i, j, -1, 0);
                return winner;
            }
        }
    }

    // Diagonal (/) check
    for (int i = y - 1; i >= (matchSize - 1); i--) {
        for (int j = 0; j <= x - matchSize; j++) {
            //Check if there are any matches
            if (CheckForMatches(i, j, -1, 1)) {
                //If we got a match return the winner and mark the winning match
                winner = board[i][j];
                fillInMatch(i, j, -1, 1);
                return winner;
            }
            //Go to next element
        }
    }

    // Diagonal (\) check
    for (int i = y - 1; i >= (matchSize - 1); i--) {
        for (int j = x - 1; j >= (matchSize - 1); j--) {
            //Check if there are any matches
            if (CheckForMatches(i, j, -1, -1)) {
                //If we got a match return the winner and mark the winning match
                winner = board[i][j];
                fillInMatch(i, j, -1, -1);
                return winner;
            }
        }
    }

    //If none of the loops matched, check if the board is filled up
    int checkerCount = 0;
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (board[i][j] == 1 || board[i][j] == 2) {
                //Count the amount of checkers in the board
                checkerCount++;
            }
        }
    }

    if (checkerCount == x * y) {
        //If the amount of checkers in the board matches the amount of elements the board has
        //Return 3 which means none of the players won the game
        winner = 3;
    } else {
        //If the board is not full, and we have no winners, continue the game
        winner = 0;
    }
    //return winner value
    return winner;
}

//! FILLS MATCH
void fillInMatch(int Row, int Column, int RowPattern, int ColumnPattern) {
    //Depending on the starting element and pattern, loop throught pattern and replace it with a Y.
    for (int i = 0; i < matchSize; i++) {
        board[Row + RowPattern * i][Column + ColumnPattern * i] = 3;
    }
}

//! CHECKS FOR WIN
bool CheckForMatches(int Row, int Column, int RowPattern, int ColumnPattern) {

    int matches = 0;

    //Loop through elements following a pattern and find if any of them match
    for (int i = 0; i < matchSize; i++) {
        //Check if any any of the elements are 0
        if (board[Row + RowPattern * i][Column + ColumnPattern * i] == 0) {
            //If they are, skip this check since we know that 0 is a empty field
            return false;
        } else if (board[Row + RowPattern * i][Column + ColumnPattern * i] == board[Row][Column]) {
            //If the element matches the first element, count the match
            matches++;
        } else {
            //If we don't have a 0 and an element does not match the starting one, skip since we know there is no winner
            return false;
        }
    }
    if (matches == matchSize) {
        
        return true; //If there is a Winner, return TRUE.
    }
    
    return false; // If there are no Winners, return FALSE.
}



//*===================================================
//*                New and Load Game
//*===================================================

//! NEW GAME
void newGame(bool loadedGame){

//* Choose player names if the game is not loaded
if(!loadedGame){

    //* Player 1 chooses the name
    do {
        clear();

        //Enter name
        printf("STARTING NEW GAME:\n");
        printf("Please enter the name of Player 1: ");
        scanf("%s", &PLAYER_1);

        fflush(stdin); // Flushes the input and clears the buffer so that a infinite loop doesn't occur.

    } while (invalidChar(PLAYER_1, '-')); // Checks whether the name contains '-', as that would be an invalid character due to how the games are stored and saved.
    

    //* Player 2 chooses the name
    do {
        clear();

        //Enter names
        printf("STARTING NEW GAME:\n");
        printf("Please enter the name of Player 2: ");
        scanf("%s", &PLAYER_2);

        //Flushes the input and clears the buffer so that a infinite loop doesn't occur.
        fflush(stdin);
        
    } while (invalidChar(PLAYER_2, '-')); //Checks whether the name contains '-', as that would be an invalid character due to how the games are stored and saved.
}
    
    while(true){
    if (!loadedGame) {

            //If the game is not loaded, it clears the board and sets the first player to PLAYER 1.
            clearBoard(board);
            currentPlayer = 0;
        } else {
            //If the game is loaded, return to false for the next loop.
            loadedGame = false;
        }
    
    result = gameLoop();

    //* Checks for Winner
    switch(result){

        //* Player 1 WINS!
        case 1:
            printf("%s won the game!\n", PLAYER_1);
            system("pause");
        break;

        //* Player 2 WINS!
        case 2:
            printf("%s won the game!\n", PLAYER_2);
            system("pause");
        break;

        //* DRAW!
        case 3:
            printf("The game is a draw!\n");
            system("pause");
        break;

        //* safeguard option
        default:
        break;
    }
    
    //* After Game options
    do {
        choice = 0;
        clear();

        printf("What do you want to do next?\n");
        printf("1. Play another game!\n");
        printf("2. Return to Main Menu\n");
        printf("Choose an option: ");

        scanf("%d", &choice); // scans for input.
        
        fflush(stdin); // Flushes the input and clears the buffer so that a infinite loop doesn't occur.

    } while (choice != 1 && choice != 2);

        //Check player choice
        if (choice == 1) {

            continue; // Repeats the Game loop
        } else {
    
            startMenu(); // Returns to Menu
        }
    }
}

//! LOAD GAME
void loadGame() {

    int id = 0;

    clear();

    printf("\n"); printf("                -=- Load Game -=-      \n");
    printf("\n"); printf("Please enter the ID of the save: ");

    scanf("%d", &id); // Scans player input

    clear();
    printf("                -=- Load Game -=-      \n");

    //Loads data and Starts the game
    if (!loadData(0, id, NULL)) {
        //If there is no Save, inform the user.
        printf("There are no saves with said ID\n");
        system("pause");
    } else {
        newGame(true);
    }
}

//! SAVE GAME
void saveGame(){
    

    FILE *saveFile; // Pointer to the save file
    int lastID = 0; // This is the last saved ID in the save file
    char line[256]; // String in which data is stored
    
    //First opens in reading only mode to acquire existing Information
    saveFile = fopen(Saves, "r");
    if (saveFile){
        while (fgets(line, sizeof(line), saveFile)){
            char *token = strtok(line, "-");
            lastID = atoi(token);
        } //It will ignore the first part due to NULL, and read the first thing after a "-" which is the last ID
        fclose(saveFile);
    } else {
        lastID = 0;
    }

    saveFile = fopen(Saves, "a");
    if(saveFile){

        //If there is a file, then it writes the players, their ID +1, who the current player is and the board information.
        fprintf(saveFile, "%d-%s-%s-%d", lastID + 1, PLAYER_1, PLAYER_2, currentPlayer);
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                fprintf(saveFile, "-%d", board[i][j]);
            }
        }
    
    fprintf(saveFile, "\n");
    fclose(saveFile);

    printf("The game was successfuly saved with ID: %d\n", lastID + 1);
    } else {
        //Print a message if something is wrong
        printf("There was a problem creating a save\n");
        }
}

//! LOAD DATA
bool loadData(int mode, int Id, char *Name) {

    FILE *file; // Pointer to our file
    
    file = fopen(Saves, "r"); // Open file for reading
    if (file) {
        // If the file is located, create temporary variables
        int id;
        int displayedSaves = 0;
        int emptySlots = 0;
        int tokenIndex = 0;
        char line[256];
        char *token;

        //Reads through the File lines and stores it into line[] with a maximum of 256 characters.
        while (fgets(line, sizeof(line), file)) {
            // Clears all previous data for each line
            id = 0;
            strcpy(PLAYER_1, "");
            strcpy(PLAYER_2, "");
            currentPlayer = 0;
            clearBoard();
            
            tokenIndex = 0; // Token Index is used to know which element is being read
            token = strtok(line, "-"); // Split the line into tokens

            while (token != NULL) {
                switch (tokenIndex) {
                    case 0:
                        id = atoi(token); // Reads the ID
                        break;

                    case 1:
                        strcpy(PLAYER_1, token); // Reads the Player 1
                        break;

                    case 2:
                        strcpy(PLAYER_2, token); // Reads the Player 2
                        break;

                    case 3:
                        currentPlayer = atoi(token); // Reads the Current Player
                        break;

                    default:
                        //Converts the sequence to a 2D array and reads the board
                        board[(tokenIndex - 4) / x][(tokenIndex - 4) % x] = atoi(token);
                        break;
                }
                
                token = strtok(NULL, "-"); // Repeats the process for each line in the save file.
                tokenIndex++;
            }

            //After all tokens, emptySlots count how many empty spaces are on the board for that game.
            emptySlots = 0;
            for (int i = 0; i < y; i++) {
                for (int j = 0; j < x; j++) {
                    if (board[i][j] == 0) {
                        emptySlots++;
                    }
                }
            }
            

            //*   Different Modes called by other functions
            switch (mode) {

                //* Load Game
                case 0:
                    //Mode 0 returns true if the current loaded save matches our search
                    //The data remains in the global variables, and we start a game using it
                    if (id == Id) {
                        fclose(file);
                        return true;
                    }
                    break;

                //* Shows all Saved Games
                case 1:
                    //Mode 1 prints out all the saves we have and counts how many it printed out
                    printf("      %d | %s vs %s | %d\n", id, PLAYER_1, PLAYER_2, emptySlots);
                    displayedSaves++;
                    break;

                //* Shows all Saved Games for a specific Player
                case 2:
                    //Mode 2 check if any of the loaded players match with the search, and prints out only those saves
                    //It also counts how many it printed out
                    if (strcmp(Name, PLAYER_1) == 0 || strcmp(Name, PLAYER_2) == 0) {
                        printf("      %d | %s vs %s | %d\n", id, PLAYER_1, PLAYER_2, emptySlots);
                        displayedSaves++;
                    }
                    break;

                //* Shows a Board with a specific ID
                case 3:
                    if (id == Id) {
                        fclose(file);
                        showBoard();
                        printf("'%c' - %s\n", checkerPlayer1, PLAYER_1);
                        printf("'%c' - %s\n", checkerPlayer2, PLAYER_2);
                        return true;
                    }
                    break;
            }
        }
        
        fclose(file); // Closes the Save File
        
        //Returns true if a message was displayed.
        if (displayedSaves != 0) {
            return true;
        }

        return false; // Otherwise, if the file exists but there are no results then return false.
    } else {
        //Otherwise, if there is no file, return false with a message.
        printf("A Save file does not exist.\n");
        return false;
    }
}

//! LIST SAVES
void listSavedGames(){

    // Displays all saved Games
    if (!loadData(1, 0, NULL)) {    
        //If there are no saves, inform the user.
        printf("There are no saves\n");
    }
}

//! LIST SAVES BY PLAYER
void listSavedPlayer(){

    char name[20];

    clear();
    printf("\n"); printf("           -=- All Saves for Player -=-      \n");
    printf("\n"); printf("Please enter the name: ");

    scanf("%s", name); // Scans user input

    fflush(stdin); // Flushes the input and clears the buffer so that a infinite loop doesn't occur.
    clear(); 

    printf("\n");
    printf("           -=- All Saves for %s -=-      \n");
    printf("        +=============================+\n");

    // Loads data and Shows all Saved Games for the specific player
    if (!loadData(2, 0, name)) {
        //If there are no games, inform the user
        printf("There are no saves with said player\n");
    }
    printf("        +=============================+\n");
}

//! SHOW BOARD WITH ID
void showBoardID(){

    int id = 0;

    clear();
    
    printf("\n"); printf("             -=- Draw Board -=-      \n"); 
    printf("\n"); printf("Please enter the ID of the board:");
    
    scanf("%d", &id); //Scans player input
    
    fflush(stdin); // Flushes the input and clears the buffer so that a infinite loop doesn't occur.
    clear();

    printf("             -=- Draw Board -=-      \n");
    //Loads data and display a board
    if (!loadData(3, id, NULL)) {
        //If there is no save, inform the user.
        printf("There are no saves with said ID\n");
    }
    system("pause");
}




//*===================================================
//*                     Other
//*===================================================

//! Clear Terminal Function
void clear(){
    system("cls"); // clears the terminal
}

//! Invalid Char Boolean Function 
bool invalidChar(char *String, char invalidChar){

    //It checks all elements within the string and returns TRUE if there is a '-' character inside it.
    for (int i = 0; i < strlen(String); i++) {
        if (String[i] == invalidChar) {
            return true;
        }
    }
    
    return false; // If there are no invalid characters, it returns False and the game continues.
}

//! Exit Game Function (Thank you)
void exitGame(int Code){
    
    clear(); // clears the console

    //* THANK YOU
    printf(" _______ __   __ _______ __    _ ___   _   __   __ _______ __   __  \n");
    printf("|       |  | |  |   _   |  |  | |   | | | |  | |  |       |  | |  | \n");
    printf("|_     _|  |_|  |  |_|  |   |_| |   |_| | |  |_|  |   _   |  | |  | \n");
    printf("  |   | |       |       |       |      _| |       |  | |  |  |_|  | \n");
    printf("  |   | |       |       |  _    |     |_  |_     _|  |_|  |       | \n");
    printf("  |   | |   _   |   _   | | |   |    _  |   |   | |       |       | \n");
    printf("  |___| |__| |__|__| |__|_|  |__|___| |_|   |___| |_______|_______| \n");
    printf("\n");

    //* FOR PLAYING
    printf(" _______ _______ ______     _______ ___     _______ __   __ ___ __    _ _______ __  \n");
    printf("|       |       |    _ |   |       |   |   |   _   |  | |  |   |  |  | |       |  |\n"); 
    printf("|    ___|   _   |   | ||   |    _  |   |   |  |_|  |  |_|  |   |   |_| |    ___|  |\n");
    printf("|   |___|  | |  |   |_||_  |   |_| |   |   |       |       |   |       |   | __|  |\n"); 
    printf("|    ___|  |_|  |    __  | |    ___|   |___|       |_     _|   |  _    |   ||  |__|\n"); 
    printf("|   |   |       |   |  | | |   |   |       |   _   | |   | |   | | |   |   |_| |__ \n"); 
    printf("|___|   |_______|___|  |_| |___|   |_______|__| |__| |___| |___|_|  |__|_______|__|\n"); 

    printf("\n"); printf("\n");

    exit(Code); // Terminates the program
}

// Created by Andrija Stanković - 2020230164
//?                               :D
