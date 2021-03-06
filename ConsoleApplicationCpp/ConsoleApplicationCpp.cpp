// ConsoleApplicationCpp.cpp : Defines the entry point for the console application.

/* C/C++ program to solve N Queen Problem using
backtracking */

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <vector>
#include <ctime>
#include <time.h>
#define N 17

std::vector<int> solutions = {};

/* A utility function to print solution */
void printSolution(int board[N][N])
{
	static int k = 1;
	printf("%d-\n", k++);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf(" %d ", board[i][j]);
		printf("\n");
	}
	printf("\n");
}

/* A utility function to check if a queen can
be placed on board[row][col]. Note that this
function is called when "col" queens are
already placed in columns from 0 to col -1.
So we need to check only left side for
attacking queens */
bool isSafe(int board[N][N], int row, int col)
{
	int i, j;

	/* Check this row on left side */
	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;

	/* Check upper diagonal on left side */
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;

	/* Check lower diagonal on left side */
	for (i = row, j = col; j >= 0 && i<N; i++, j--)
		if (board[i][j])
			return false;

	return true;
}

/* A recursive utility function to solve N
Queen problem */
bool solveNQUtil(int board[N][N], int col)
{
	/* base case: If all queens are placed
	then return true */
	if (col == N)
	{
		//printSolution(board);
		solutions.push_back(1);
		return true;
	}

	/* Consider this column and try placing
	this queen in all rows one by one */
	bool res = false;
	for (int i = 0; i < N; i++)
	{
		/* Check if queen can be placed on
		board[i][col] */
		if (isSafe(board, i, col))
		{
			/* Place this queen in board[i][col] */
			board[i][col] = 1;

			// Make result true if any placement
			// is possible
			res = solveNQUtil(board, col + 1); //|| res;

			/* If placing queen in board[i][col]
			doesn't lead to a solution, then
			remove queen from board[i][col] */
			board[i][col] = 0; // BACKTRACK
		}
	}

	/* If queen can not be place in any row in
	this column col then return false */
	return res;
}

/* This function solves the N Queen problem using
Backtracking. It mainly uses solveNQUtil() to
solve the problem. It returns false if queens
cannot be placed, otherwise return true and
prints placement of queens in the form of 1s.
Please note that there may be more than one
solutions, this function prints one of the
feasible solutions.*/
void solveNQ()
{
	int board[N][N];
	int i = 0, j = 0;


	//Init the chessboard to 0's

	for (i = 0; i < N; i++)

		for (j = 0; j < N; j++)

			board[i][j] = 0;
	//std::memset(board, 0, sizeof(board));

	/*if (solveNQUtil(board, 0) == false)
	{
		printf("Solution does not exist");
		return;
	}*/
	solveNQUtil(board, 0);
	int ant = solutions.size();
	printf("Number of solutions are: %d", ant);
	
}

// driver program to test above function
int main()
{
	const clock_t begin_time = std::clock();
	solveNQ();	
	std::cout << "\n" << "Time in seconds are: " << float(clock() - begin_time) / CLOCKS_PER_SEC << "\n";	
	int n = 1;
	std::cin >> n;
	return 0;
}

