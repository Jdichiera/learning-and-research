// Filename     : sudoku.cpp
// Author       : Jeramy Dichiera
// Created      : 07/26/2017
// Description  : This program generates solvable Sudoku boards

//#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>
#include <iterator> // inserter
#include <algorithm> // set_difference
#include <time.h> 
#include <random> 

struct Coordinates {
	int row;
	int col;
};

// Find empty cell function
Coordinates FindEmptyCell(int board[][9]) {
	Coordinates cell = { -1, -1 };
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			std::cout << i << ":" << j << "val =" << board[i][j] << std::endl;
			if (board[i][j] == 0) {
				cell.row = i, cell.col = j;
				return cell;
			}
		}
	}
	return cell;
}


// Validates if value is OK for cell function
bool DuplicateInRow(int board[][9], int row, int value) {
	for (int col = 0; col < 9; col++) {
		if (board[row][col] == value) {
			return true;
		}
	}
	return false;
}


bool DuplicateInColumn(int board[][9], int col, int value) {
	for (int row = 0; row < 9; row++) {
		if (board[row][col] == value) {
			return true;
		}
	}
	return false;
}


bool DuplicateInBlock(int board[][9], int col, int row, int value) {
	int colStart = col - col % 3;
	int rowStart = row - row % 3;
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (board[row + rowStart][col + colStart] == value) {
				return true;
			}
	return false;
}


bool PlaceNumber(int board[][9], int col, int row, int value) {
	bool rowDuplicate = DuplicateInRow(board, row, value);
	bool colDuplicate = DuplicateInColumn(board, col, value);
	bool blockDuplicate = DuplicateInBlock(board, col, row, value);
	if (!rowDuplicate && !colDuplicate && !blockDuplicate) {
		return true;
	}
	return false;
}


std::set<int> FindPossibleValues(int board[][9], Coordinates emptyCell) {
	std::set<int> usedNumbers = {};
	std::set<int> allValues = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::set<int> possibleValues = {};
	std::vector<Coordinates> neighbors;
	Coordinates neighbor;
	// Add row values to set
	for (int i = 0; i < 9; i++) {
		neighbor.row = i;
		neighbor.col = emptyCell.col;
		neighbors.push_back(neighbor);
	}
	// Add col values to set
	for (int i = 0; i < 9; i++) {
		neighbor.row = emptyCell.row;
		neighbor.col = i;
		neighbors.push_back(neighbor);
	}
	// Add block values to set
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			neighbor.row = emptyCell.row - emptyCell.row % 3 + i;
			neighbor.col = emptyCell.col - emptyCell.col % 3 + j;
			neighbors.push_back(neighbor);
		}
	}
	for (auto cell : neighbors) {
		usedNumbers.insert(board[cell.row][cell.col]);
	}
	std::set_difference(allValues.begin(), allValues.end(),
		usedNumbers.begin(), usedNumbers.end(),
		std::inserter(possibleValues, possibleValues.begin()));
	return possibleValues;
}


std::vector<Coordinates> GetEmptyCells(int board[][9]) {
	std::vector<Coordinates> emptyCells;
	Coordinates cell;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == 0) {
				cell.row = i;
				cell.col = j;
				emptyCells.push_back(cell);
			}
		}
	}
	return emptyCells;
}

void Printboard(int board[][9]) {
	std::cout << "\n---------+---------+---------" << std::endl;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (j == 3 || j == 6) {
				std::cout << "|";
			}
			std::cout << " " << board[i][j] << " ";
		}
		if (i == 2 || i == 5) {
			std::cout << "\n---------+---------+--------";
		}
		std::cout << std::endl;
	}
	std::cout << "---------+---------+---------" << std::endl;
}


bool FillCells(int board[][9]) {
	std::vector<Coordinates> emptyCellList = GetEmptyCells(board);
	while (!emptyCellList.empty()) {
		int random = rand();
		Coordinates tempCell = emptyCellList[0];
		emptyCellList.erase(emptyCellList.begin());
		std::set<int> possibleValues = FindPossibleValues(board, tempCell);
		std::vector<int> shuffledValues;
		for (auto number : possibleValues) {
			shuffledValues.push_back(number);
		}
		std::shuffle(std::begin(shuffledValues), std::end(shuffledValues), std::default_random_engine(random));
		for (auto value : shuffledValues) {
			board[tempCell.row][tempCell.col] = value;
			if (emptyCellList.empty()) {
				return true;
			}

			if (FillCells(board)) {
				return true;
			}
		}
		board[tempCell.row][tempCell.col] = 0;
		emptyCellList.push_back(tempCell);
		return false;
	}
}


int main() {
	std::srand(unsigned(time(NULL)));
	int board[9][9] = {};
	FillCells(board);
	Printboard(board);
	system("pause");
	return 0;
}
