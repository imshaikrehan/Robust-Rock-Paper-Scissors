# Rock Paper Scissors (C++)

A command-line Rock-Paper-Scissors game written in C++ that features a predictive opponent.

## Overview
Instead of relying purely on random number generation, this version implements a basic AI opponent using a Markov chain. The program tracks the user's move history and transition patterns to predict their next move and actively counter it.

## Features
- **Predictive Opponent:** Uses a 3x3 transition matrix to calculate the probability of the user's next move based on their previous move.
- **Object-Oriented Structure:** Game logic and state are encapsulated within a dedicated class.
- **Game Modes:** Support for finite round limits or an "endless" mode.
- **Input Validation:** Safe handling of invalid inputs to prevent runtime errors or infinite loops.

## How the Prediction Works
The AI assumes that human players are not truly random. It records what a player throws *immediately after* a specific move. 

For example, if the player throws *Rock*, the program updates the transition matrix for the state `lastMove = Rock`. If the data shows the player has a high probability of throwing *Paper* after *Rock*, the AI will anticipate *Paper* and throw *Scissors*. The model becomes more accurate as the round count increases.

## Build and Run

Require a standard C++ compiler (like `g++`).

**Compile:**
```bash
g++ rockPaperScissors.cpp -o rps
