/**
	Da Katta's favorite hobby is to play chess whenever he is free. He likes the Knight more than any other piece so he wants to check if he can move the knight to every other position in the board at a given scenario. You need to help him with knights tour.

A knight's tour is a sequence of moves of a knight on a chessboard such that the knight visits every square only once. It has been proven that a knight's tour is always possible for sufficiently large grid sizes. In this problem, however some squares will contain other pieces and will not be traversable.

Given an MxN (M,N<8) chessboard with several blocked cells, figure out if a knight starting at (0,0) is able to traverse all non-blocked cells without trodding on the same cell more than once.
**/
/**
	pseudocode/skeleton for knightstour backtracking algorithm:

	FindSolution(test_solution){
		if (test_solution is finished)
			return true
		for each legal move from the current position
			add the move to test_solution
			if(FindSolution(test_solution)) t
				return true

		return false

		if solution does not work go back

	}


**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
//using namespace std;

//solution coordinates: vector of pairs
//class as knight tour solver
class KnightTour{
	int knightMoves[8][2] = {
		{ 1,  2},
		{-1,  2},
		{ 1, -2},
		{-1, -2},
		{ 2,  1},
		{-2,  1},
		{ 2, -1},
		{-2, -1}
	};

	//dimensions of board
	int M, N;

	//counter to determine if solution is done
	int cellsLeft;

	//decided to rep 2D array w/ double pointer
	int **board;

	//a coordinate 
	struct Coord{
		int x;
		int y;
	};

	//the solution i want to print out
	std::vector<Coord> sol;
	Coord knightCoord;

	public:
	KnightTour(int M_in, int N_in){
		M = M_in;
		N = N_in;
		board = new int*[M];
		cellsLeft = M * N;
		knightCoord.x = 0;
		knightCoord.y = 0;
		sol.push_back(knightCoord);
		cellsLeft--;
		for(int i = 0; i < M; ++i){
			board[i] = new int[N];
		}

		for(int i = 0; i < M; ++i){
			for(int j = 0; j < N; ++j){
				board[i][j] = 0;
			}
		}
		board[knightCoord.x][knightCoord.y] = 1;

	}

	bool knightCanMove(int board_x, int board_y, int x_in, int y_in){
		int x = board_x + x_in;
		int y = board_y + y_in;
		return (x >= 0) && (x < M) && (y >= 0) && (y < N)
			&& (board[x][y] == 0); 
	}

	void fillBlockedCells(int x_in, int y_in){
		board[x_in][y_in] = 1;
		cellsLeft--;
	}

	//how can we tell the board is full
	//have a counter - cells left
	//check if board is filled
	bool findSolution(){
		if(cellsLeft == 0){
			//should i print answer here or later
			return true;
		}
		// DEBUG: 
		// else if(cellsLeft == 1){
		// 	std::cout << "cells left: " << cellsLeft << '\n';
		// 	displayDebug();
		// }

		//check all possible moves to see if it works
		for(int i = 0; i < 8; i++){
			if(knightCanMove(knightCoord.x, knightCoord.y, 
				knightMoves[i][0], knightMoves[i][1])){
				Coord trialMove;
				// trialMove.x = knightMoves[i][0];
				// trialMove.y = knightMoves[i][1];
				knightCoord.x += knightMoves[i][0];
				knightCoord.y += knightMoves[i][1]; 
				fillBlockedCells(knightCoord.x, knightCoord.y);

				sol.push_back(knightCoord);
				if(findSolution()){
					return true;
				}
				else{
					board[sol.back().x][sol.back().y] = 0;
				    sol.pop_back();
				    cellsLeft++;
				    knightCoord.x = sol.back().x;
				    knightCoord.y = sol.back().y;
				 //   displayDebug();
				}

			}


		}

	    return false;

	}

	void displaySol(){
		for(int i = 0; i < sol.size(); i++){
			std::cout << sol[i].x << ' ' << sol[i].y << '\n';
		}
	}

	void displayDebug(){
		std::cout << "===========solution size: " << sol.size() << " ==========\n";
		for(int i = 0; i < sol.size(); i++){
			std::cout << '[' << sol[i].x << ", " << sol[i].y << "] ";
		}
		std::cout << '\n';
	}
	//free the 2D array - destructor?

};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    //knightSolve
    //knightMove
    int M, N, B;
    int B_x, B_y;
    std::vector<std::pair<int, int> > blocked_cells;
    std::cin >> M >> N >> B;
    KnightTour ktour = KnightTour(M, N);
    //int board[M][N] = {0};
    for(int i = 0; i < B; i++){
        std::cin >> B_x >> B_y;
        ktour.fillBlockedCells(B_x, B_y);
        //std::pair<int, int> blocked_coord(B_x, B_y);
        //board[B_x][B_y] = 1;
    }
    if(ktour.findSolution()){
    	ktour.displaySol();
    }
    else{
    	std::cout << "No" << '\n';
    }

    //should i have a {can knight move} function?
    return 0;
}
