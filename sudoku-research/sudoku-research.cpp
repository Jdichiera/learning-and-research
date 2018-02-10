// Filename     : XX.cpp
// Author       : Jeramy Dichiera
// Created      : XX/XX/XXXX
// Description  : X
#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>
#include <iterator>
#include <algorithm> // set_difference
#include <time.h> 
#include <random> 

struct Coordinates {
	int row;
	int col;
};

int myrandom(int i) { return std::rand() % i; }



// Find empty cell function
Coordinates FindEmptyCell(int board[][9]) {
	//bool emptyFound = false;
	Coordinates cell = { -1, -1 };
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			std::cout << i << ":" << j << "val =" << board[i][j] <<  std::endl;
			if (board[i][j] == 0) {
				cell.row = i, cell.col = j;
				return cell;
				//emptyFound = true;
				//break;
			}
		}
	}
	//std::cout << "Empty found: " << emptyFound << std::endl;
	//return emptyFound;
	return cell;
}
// Validates if value is OK for cell function
bool DuplicateInRow(int board[][9], int row, int value) {
	//bool duplicateFound = false;
	for (int col = 0; col < 9; col++) {
		if (board[row][col] == value) {
			return true;
		}
	}
	//std::cout << "Duplicate in row : " << duplicateFound << std::endl;
	return false;
}
bool DuplicateInColumn(int board[][9], int col, int value) {
	//bool duplicateFound = false;
	for (int row = 0; row < 9; row++) {
		if (board[row][col] == value) {
			//std::cout << "\n( " << col << "," << row << " ) - " << board[col][row];
			return true;
		}
	}
	//std::cout << "Duplicate in column : " << duplicateFound << std::endl;
	return false;
}
bool DuplicateInBlock(int board[][9], int col, int row, int value) {
	//bool duplicateFound = false;
	int colStart = col - col % 3;
	int rowStart = row - row % 3;
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (board[row + rowStart][col + colStart] == value) {
				return true;
			}
	//std::cout << "Duplicate in block : " << duplicateFound << std::endl;
	return false;
}

bool PlaceNumber(int board[][9], int col, int row, int value) {
	//bool numberWorks = false;
	bool rowDuplicate = DuplicateInRow(board, row, value);
	bool colDuplicate = DuplicateInColumn(board, col, value);
	bool blockDuplicate = DuplicateInBlock(board, col, row, value);
	if (!rowDuplicate && !colDuplicate && !blockDuplicate) {
		return true;
	}
	//std::cout << "Placenumber : " << numberWorks << std::endl;
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
bool IsFull(int board[][9]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] > 0) {
				return true;
			}
		}
	}
	return false;
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

bool TryFillCells(int board[][9], std::vector<Coordinates> emptyCells) {
	//while()
	return false;
}

bool FillCells(int board[][9]) {
	std::vector<Coordinates> emptyCellList = GetEmptyCells(board);
	/*for (auto cell : emptyCellList) {
		std::cout << emptyCellList.size() << ", " << cell.row << ":" << cell.col << " - Val = " << board[cell.row][cell.col];
	}*/
	while (!emptyCellList.empty()) {
		int random = rand();
		Coordinates tempCell = emptyCellList[0];
		emptyCellList.erase(emptyCellList.begin());
		std::set<int> possibleValues = FindPossibleValues(board, tempCell);
		std::vector<int> shuffledValues;
		for (auto number : possibleValues) {
			shuffledValues.push_back(number);
		}
		//if (possibleValues.size() > 1) {
		std::shuffle(std::begin(shuffledValues), std::end(shuffledValues), std::default_random_engine(random));
		//}
		for (auto value : shuffledValues) {
			board[tempCell.row][tempCell.col] = value;

			if (emptyCellList.empty()) {
				std::cout << "board full";
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
	/*if (!TryFillCells(board, emptyCell)) {

	}*/
	//for (auto value : possibleValues) {
	//	//if (PlaceNumber(board, emptyCell.col, emptyCell.row, value)) {
	//		board[emptyCell.row][emptyCell.col] = value;
	//		std::cout << board[emptyCell.row][emptyCell.col] << "-" << emptyCell.row << ":" << emptyCell.col << " = " << value;
	//		emptyCell = FindEmptyCell(board);
	//		possibleValues = FindPossibleValues(board, emptyCell);
	//		if (possibleValues.empty()) {
	//			board[emptyCell.row][emptyCell.col] = 0;
	//		}
	//		if (IsFull(board)) {
	//			return true;
	//		}
	//	}
	////}
	//return false;

	//boTryFillCells(board, possibleValues, emptyCell);
	//std::cout << "\nUsed ";
	//for (auto num : usedNumbers) {
	//	std::cout << num << ", ";
	//}
	//std::cout << "\nPossible ";
	//for (auto num : possibleValues) {
	//	std::cout << num << ", ";
	//}



	//for (int value = 1; value <= 9; value++) {
	//	if (PlaceNumber(board, col, row, value)) {
	//		board[row][col] = value;
	//	if (FillCells(board)) {
	//		return true;
	//	}

	//	
	//	}
	//}
	//return false;
}

//bool TryFillCells(int board[][9], std::set<int> possibleValues, Coordinates emptyCell) {
//	for (auto value : possibleValues) {
//		if (PlaceNumber(board, emptyCell.col, emptyCell.row, value)) {
//			board[emptyCell.col][emptyCell.row] = value;
//			if (FillCells(board)) {
//				return true;
//			}
//			board[emptyCell.col][emptyCell.row] = 0;
//		}
//	}
//	return false;
//}
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


int main() {
	std::srand(unsigned(time(NULL)));

	int board[9][9] = {0};

	int value;
	int col;
	int row;
	Coordinates emptyCell = FindEmptyCell(board);
	std::set<int> possibleValues = FindPossibleValues(board, emptyCell);
 
	//Printboard(board);
	FillCells(board);
	Printboard(board);
	system("pause");
	return 0;
}
