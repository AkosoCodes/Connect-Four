<h1 align="center">Connect Four</h1>

<p>This was a game assigned for the 'Principles of Computer Programming' course as Singidunum University.</p>

## 📝 | Table of Contents
- [🧐 Project Task <a name="project_task"></a>](#--project-task-)
- [💡 Logic & Features  <a name="project_logic"></a>](#--logic--features--)
- [📸 Demonstration <a name="demo"></a>](#--demonstration-)
- [🧰 Languages & Tools <a name="languages_&_tools"></a>](#--languages--tools-)
- [🏁 Getting Started <a name="getting_started"></a>](#--getting-started-)
- [⚖ License <a name="license"></a>](#--license-)


## 🧐 | Project Task <a name="project_task"></a>

Write a program that implements a computer version of the connect four (https://en.wikipedia.org/wiki/Connect_Four) game.

The game is played on a board that is 7 fields wide and 6 fields high. It is played by two players with the symbols ‘X’ and ‘O’. Players can choose the column in which their symbol is placed on top of the symbols that are already in that column. The winner is the player that first makes a row of 4 symbols either vertically, horizontally or diagonally.<br>


## 💡 | Logic & Features  <a name="project_logic"></a>

**<h3>Game Logic</h3>**
First the *’X’* player should make its move by entering an integer number from 1 to 7 which indicates the row in which the symbol should be placed. Afterwards, the program switches turns and allows the other player to make their move. At the end of each turn, the state of the board is printed onto the terminal, and the program checks whether a win/ending condition is fulfilled. After the game has ended, players have the option to start a new game or go back to the main menu.<br>

  **<h4>Ending Conditions</h4>**
The game ends if one of the following cases is true:<ul>
    <li><strong>A Player connects at least 4 symbols</strong> <i>(Horizontal, Vertical or Diagonal connection)</i></li>
    <li><strong>The board is filled</strong> <i>(No more spaces)</i></li>
</ul>If someone wins, the board with the higlighted connected symbols that caused the victory is printed, and the winner is informed.<br>

**<h3>Saving</h3>**
If at any point one of the players enters 0 instead of an integer 1 to 7, program should save the current game. The current state of the board, including the player names is then saved, using a unique ID. After saving the game, the ID of the game is printed in the console and the game continues without further interruption. The game itself is logged and saved inside the file result.txt.<br>

**<h3>Loading</h3>**
If the load game option is selected, the user should input the ID of the saved game and then start the game from the saved point. From this point on, the game will continue from the saved point as normal.<br>

## 📸 | Demonstration <a name="demo"></a>

<h3>Menu:</h3>
<img src="https://user-images.githubusercontent.com/74971935/179793994-d123bfdf-d624-4892-a66e-221024c342fb.gif" width="400px">

<h3>Game Demo:</h3>
<img src="https://user-images.githubusercontent.com/74971935/179793989-5ed41385-fbb8-404f-a330-7b5800cd2818.gif" width="400px">

<h3>Saving & Loading Demo:</h3>
<img src="https://user-images.githubusercontent.com/74971935/179796146-a8cc0944-9636-461b-bfd6-9234a766e150.gif" width="400px">


## 🧰 | Languages & Tools <a name="languages_&_tools"></a>
<p><img src="https://img.icons8.com/color/452/c-programming.png" width=30 alt="C">
<a href="https://code.visualstudio.com/"><img src="https://upload.wikimedia.org/wikipedia/commons/thumb/9/9a/Visual_Studio_Code_1.35_icon.svg/768px-Visual_Studio_Code_1.35_icon.svg.png?20210804221519" width=30 alt="VS-Code"></a></p>


## 🏁 | Getting Started <a name="getting_started"></a>
These instructions will get you a copy of the project up and running on your local machine.

**<h3>Requirements:</h3>**
<ul>
<li>C/C++ Compiler</li>
</ul>

**<h3>Guide:</h3>**
<ol>
<li>Compile the file</li>
<li>Run the output</li>
<li>Have fun! :D</li>
</ol><br>


## ⚖ | License <a name="license"></a>
This repository is not under any license. Normal copyright laws apply.
