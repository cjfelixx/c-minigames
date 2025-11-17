# TicTacToe in C++ (4x4)

A simple two‑player TicTacToe game implemented in C++. This version uses a **4x4 grid** and allows players to enter moves using coordinates such as `A2`.

---

## 🎮 Features

* 4x4 game board
* Player name input
* Turn‑based gameplay (`X` always goes first)
* Grid‑coordinate input format (e.g., `A2`)
* Win detection on:

  * Rows
  * Columns
  * Diagonals
* Tie detection when the grid is full

---

## 🧩 How the Game Works

### 1. **Player Setup**

* The program prompts the first user (the **X** player) to enter their name.
* Next, the program prompts the second user (the **O** player) to enter their name.

### 2. **Entering Moves**

Players enter their desired move using a coordinate format:

* **Column**: A, B, C, or D
* **Row**: 1, 2, 3, or 4

For example:

```
A2
C4
D1
```

### 3. **Grid Layout**

```
    A   B   C   D
1 |   |   |   |   |
2 |   |   |   |   |
3 |   |   |   |   |
4 |   |   |   |   |
```

Players place an `X` or `O` on the grid based on the entered coordinate.

---

## 🏆 Winning the Game

After each turn, the program checks for:

* 4 matching symbols (X or O) in any **row**
* 4 matching symbols in any **column**
* 4 matching symbols along either **diagonal**

If a player achieves this, the program declares them the winner and ends the game.

---

## 🤝 Tie Game

If all 16 positions are filled (each player takes 8 turns) **and** no winning combination is found:

* The game ends in a **tie**.

---

## 📁 Future Enhancements (Optional)

* Input validation for invalid or occupied positions
* Replay option
* AI opponent mode
* Move history display

---

## 🛠️ Requirements

* C++ compiler (g++, clang++, MSVC, etc.)

---

## ▶️ Running the Program

Compile and run:

```bash
g++ -o tictactoe main.cpp
./tictactoe
```

---

Enjoy playing TicTacToe in a larger 4x4 format!
