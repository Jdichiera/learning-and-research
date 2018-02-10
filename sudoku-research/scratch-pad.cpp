////void Printboard(int board[][9]) {
////	std::cout << "\n---------+---------+---------" << std::endl;
////	for (int i = 0; i < 9; i++) {
////		for (int j = 0; j < 9; j++) {
////			if (j == 3 || j == 6) {
////				std::cout << "|";
////			}
////			std::cout << " " << board[i][j] << " ";
////		}
////		if (i == 2 || i == 5) {
////			std::cout << "\n---------+---------+--------";
////		}
////		std::cout << std::endl;
////	}
////	std::cout << "---------+---------+---------" << std::endl;
////}
////
////
////std::vector<Coordinates> GetRowNeighbors(int board[][9], Coordinates cell) {
////	std::vector<Coordinates> rowNeighbors;
////	Coordinates neighbor;
////	/*std::cout << "\nValue at position ( " << row << " , " << column << " ) - "
////	<< board[row][column] << std::endl;
////	std::cout << "Row Neighbors : ";*/
////	for (int i = 0; i < 9; i++) {
////		neighbor.row = cell.row;
////		neighbor.column = i;
////		rowNeighbors.push_back(neighbor);
////	}
////	//for (auto coord : rowNeighbors) {
////	//	std::cout << "\n( " << coord.row << "," << coord.column << " ) - " << board[coord.row][coord.column];
////	//}
////	return rowNeighbors;
////}
////
////std::vector<Coordinates> GetColumnNeighbors(int board[][9], Coordinates cell) {
////	std::vector<Coordinates> columnNeighbor;
////	Coordinates neighbor;
////	/*std::cout << "\nValue at position ( " << row << " , " << column << " ) - "
////	<< board[row][column] << std::endl;
////	std::cout << "Column Neighbors : ";*/
////	for (int i = 0; i < 9; i++) {
////		neighbor.row = i;
////		neighbor.column = cell.column;
////		columnNeighbor.push_back(neighbor);
////	}
////	/*for (auto coord : columnNeighbor) {
////	std::cout << "\n( " << coord.row << "," << coord.column << " ) - " << board[coord.row][coord.column];
////	}*/
////	return columnNeighbor;
////}
////
////std::vector<Coordinates> GetBlockNeighbors(int board[][9], Coordinates cell) {
////	std::vector<Coordinates> blockNeighbor;
////	Coordinates neighbor;
////	/*std::cout << "\nValue at position ( " << row << " , " << column << " ) - "
////	<< board[row][column] << std::endl;*/
////	neighbor.row = (cell.row / 3) * 3;
////	neighbor.column = (cell.column / 3) * 3;
////
////	for (int i = 0; i < 3; i++) {
////		for (int j = 0; j < 3; j++) {
////			neighbor.row = (cell.row / 3) * 3 + i;
////			neighbor.column = (cell.column / 3) * 3 + j;
////			blockNeighbor.push_back(neighbor);
////		}
////	}
////	/*std::cout << "Block Neighbors : ";
////	for (auto coord : blockNeighbor) {
////	std::cout << "\n( " << coord.row << "," << coord.column << " ) - " << board[coord.row][coord.column];
////	}*/
////	return blockNeighbor;
////}
////
////std::vector<Coordinates> GetNeighbors(Coordinates cell) {
////	std::vector<Coordinates> cellNeighbors;
////	Coordinates neighbor;
////
////	// Get row neighbors
////	for (int i = 0; i < 9; i++) {
////		neighbor.row = cell.row;
////		neighbor.column = i;
////		cellNeighbors.push_back(neighbor);
////	}
////	// Get col neighbors
////	for (int i = 0; i < 9; i++) {
////		neighbor.row = i;
////		neighbor.column = cell.column;
////		cellNeighbors.push_back(neighbor);
////	}
////	// Get block neighbors
////	for (int i = 0; i < 3; i++) {
////		for (int j = 0; j < 3; j++) {
////			neighbor.row = (cell.row / 3) * 3 + i;
////			neighbor.column = (cell.column / 3) * 3 + j;
////			cellNeighbors.push_back(neighbor);
////		}
////	}
////	return cellNeighbors;
////}
////
////Coordinates FindEmptyCell(int board[][9]) {
////	bool foundEmpty = false;
////	Coordinates emptyCell = { -1, -1 };
////	for (int i = 0; i < 9; i++) {
////		for (int j = 0; j < 9; j++) {
////			if (board[i][j] < 1) {
////				emptyCell.row = i;
////				emptyCell.column = j;
////				foundEmpty = true;
////				break;
////			}
////		}
////		if (foundEmpty) {
////			break;
////		}
////	}
////	/*while (cellFilled) {
////	int row = 0;
////	int column = 0;
////	if (board[row][column] == 0) {
////	emptyCell.row = row;
////	emptyCell.column = column;
////	cellFilled = false;
////	}
////	row++;
////	column++;
////	}*/
////	if (foundEmpty) {
////		std::cout << "Empty found at ( " << emptyCell.row << "," << emptyCell.column << " )";
////	}
////	else {
////		std::cout << "\nBoard is full ...";
////	}
////	return emptyCell;
////}
////
////std::vector<int> GetVectorNumbers() {
////	int number = 0;
////	srand(time(NULL));
////	std::vector<int> numbers;
////	int count = 1;
////	bool numberExists;
////
////	while (count != 10) {
////		number = rand() % 9 + 1;
////		numberExists = std::find(numbers.begin(), numbers.end(), number) != numbers.end();
////
////		if (!numberExists) {
////			numbers.push_back(number);
////			count++;
////		}
////	}
////	/*for (auto &number : numbers) {
////	std::cout << " " << number;
////	}*/
////
////	return numbers;
////
////}
//
//
//
//void TryFillCells() {
//	std::cout << "--==Try fill cells==--";
//	//std::deque<SudokuCell> emptyCells;
//	/*for (auto cell : this->cells) {
//	if (cell.value == 0) {
//	emptyCells.push_back(cell);
//	}
//	}*/
//	auto emptyCells = std::deque<SudokuCell>{ cells };
//
//	if (!FillCells(emptyCells)) {
//		std::cout << "Board is full";
//	}
//}
//int GetIndexValue(int index) {
//	int value;
//	value = this->cells[index].value;
//	return value;
//}
//
//Coordinates GetCoordinates(int index) {
//	return Coordinates{ index / 3, index % 3 };
//}
//
//int GetIndex(Coordinates cell) {
//	return cell.column * 9 + cell.row;
//}
//
//// get cell by index
//std::shared_ptr<SudokuCell> at(int index) {
//	GetCoordinates(index);
//	std::cout << "get pointer index" << std::endl;
//}
//// get cell by coord
//std::shared_ptr<SudokuCell> at(Coordinates position) {
//	std::cout << "get pointer coord" << std::endl;
//}
//
//
//bool FillCells(std::deque<SudokuCell> &emptyCells) {
//	std::cout << "\n--==Fill cells==--";
//	// Save the first empty cell to a temp cell
//	auto cell = emptyCells.front();
//	// Pop off the first cell from the empty cell queue
//	emptyCells.pop_front();
//	// Get values for all of the neighbor elements. These should be numbers 1 - 9. No dups
//	std::set<int> neighborValues = {};
//	int index;
//	int value;
//	for (auto neighbor : cell.neighbors) {
//		index = GetIndex(neighbor);
//		value = GetIndexValue(index);
//		neighborValues.insert(value);
//	}
//	std::cout << "\nNeighbor Values\n";
//	std::cout << "\n================\n";
//	for (auto value : neighborValues) {
//		std::cout << value;
//	}
//	std::cout << "\n================";
//	// Find set of potential numbers for this cell. Should be a number 1-9 that is
//	// not in the set of values from the neighbors
//	std::set<int> allValues = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	std::vector<int> potentialValues;
//	std::set_difference(allValues.begin(), allValues.end(),
//		neighborValues.begin(), neighborValues.end(),
//		std::inserter(potentialValues, potentialValues.begin()));
//	std::cout << "\nPotential Values\n";
//	std::cout << "\n================\n";
//	for (auto value : potentialValues) {
//		std::cout << value;
//	}
//	std::cout << "\n================";
//
//	// for each value in the potential numbers, set the value of the cell to the first value
//	// in the options
//	for (auto value : potentialValues) {
//		cell.value->value;
//	}
//
//	// If we are at the last cell in the group, return true everything has been filled.
//	if (emptyCells.empty()) {
//		return true;
//	}
//
//	// If we call this function again and it returns true, return true (this will keep the
//	// recursive loop going
//	if (FillCells(emptyCells)) {
//		return true;
//	}
//	// Backrtrack ??
//	// Set cell value to 0
//	// Push the cell back onto the front of the emptyCells collection
//	// Return false
//	cell.value = 0;
//	emptyCells.push_front(cell);
//	return false;
//}

//std::vector<SudokuCell> GenerateCells() {
//	std::vector<SudokuCell> gameBoard;
//	for (int i = 0; i < 9; i++) {
//		for (int j = 0; j < 9; j++) {
//			SudokuCell cell = SudokuCell(i, j, 0);
//			gameBoard.push_back(cell);
//		}
//	}
//	return gameBoard;
//}


//bool CheckRowNeighbors(int board[][9], Coordinates cell) {
//	//std::cout << "\n\n--==Checking row neighbors ==--" << std::endl;
//	bool rowClear = true;
//	int cellValue = board[cell.row][cell.column];
//	std::vector<Coordinates> rowNeighbors = GetRowNeighbors(board, cell);
//	for (auto neighborCell : rowNeighbors) {
//		if (neighborCell.row != cell.row || neighborCell.column != cell.column) {
//			//std::cout << "Checking (" << neighborCell.row << "," << neighborCell.column << ")" << std::endl;
//			//std::cout << "Coord no match " << std::endl;
//			if (board[neighborCell.row][neighborCell.column] == cellValue) {
//				//std::cout << "Value match " << std::endl;
//				rowClear = false;
//			}
//		}
//	}
//	std::cout << "\nRow clear : " << rowClear << std::endl;
//	return rowClear;
//}
//
//bool CheckColumnNeighbors(int board[][9], Coordinates cell) {
//	//std::cout << "\n\n--==Checking column neighbors ==--" << std::endl;
//	bool columnClear = true;
//	int cellValue = board[cell.row][cell.column];
//	std::vector<Coordinates> columnNeighbors = GetColumnNeighbors(board, cell);
//	for (auto neighborCell : columnNeighbors) {
//		if (neighborCell.row != cell.row || neighborCell.column != cell.column) {
//			//std::cout << "Checking (" << neighborCell.row << "," << neighborCell.column << ")" << std::endl;
//			//std::cout << "Coord no match " << std::endl;
//			if (board[neighborCell.row][neighborCell.column] == cellValue) {
//				//std::cout << "Value match " << std::endl;
//				columnClear = false;
//			}
//		}
//	}
//	std::cout << "\nColumn clear : " << columnClear << std::endl;
//	return columnClear;
//}
//
//bool CheckBlockNeighbors(int board[][9], Coordinates cell) {
//	//std::cout << "\n\n--==Checking block neighbors ==--" << std::endl;
//	bool blockClear = true;
//	int cellValue = board[cell.row][cell.column];
//	std::vector<Coordinates> blockNeighbors = GetBlockNeighbors(board, cell);
//	for (auto neighborCell : blockNeighbors) {
//		if (neighborCell.row != cell.row || neighborCell.column != cell.column) {
//			//std::cout << "Checking (" << neighborCell.row << "," << neighborCell.column << ")" << std::endl;
//			//std::cout << "Coord no match " << std::endl;
//			if (board[neighborCell.row][neighborCell.column] == cellValue) {
//				//std::cout << "Value match " << std::endl;
//				blockClear = false;
//			}
//		}
//	}
//	std::cout << "\nBlock clear : " << blockClear << std::endl;
//	return blockClear;
//}








//==========
//// Filename     : sudoku.cpp
//// Author       : Jeramy Dichiera
//// Created      : 07/25/2017
//// Description  : A sudoku game
//
//#include <iostream>
//#include <queue>
//#include <set>
//#include <vector>
//#include <algorithm> // Random_shuffle
//#include <memory>
//#include <math.h>
//#include <time.h>       /* time */
//#include <iterator>
//
//
//struct Coordinates {
//	int column = 0; // X
//	int row = 0; // Y
//};
//
//struct Neighbor {
//	Coordinates coordinates;
//	int value;
//};
//
//class SudokuCell {
//public:
//	Coordinates position;
//	int value;
//	std::vector<Neighbor> neighbors;
//	SudokuCell(int col, int row, int value) {
//		this->position = { col, row };
//		this->value = value;
//		GenerateNeighbors();
//		//PrintCell();
//	}
//	void SetValue(int value) {
//		this->value = value;
//	}
//private:
//	void GenerateNeighbors() {
//		Neighbor neighbor;
//
//		// Get row neighbors
//		for (int i = 0; i < 9; i++) {
//			neighbor.coordinates.row = this->position.row;
//			neighbor.coordinates.column = i;
//			neighbor.value = this->value;
//			neighbors.push_back(neighbor);
//		}
//		// Get col neighbors
//		for (int i = 0; i < 9; i++) {
//			neighbor.coordinates.row = i;
//			neighbor.coordinates.column = this->position.column;
//			neighbor.value = this->value;
//			neighbors.push_back(neighbor);
//		}
//		// Get block neighbors
//		for (int i = 0; i < 3; i++) {
//			for (int j = 0; j < 3; j++) {
//				neighbor.coordinates.row = (this->position.row / 3) * 3 + i;
//				neighbor.coordinates.column = (this->position.column / 3) * 3 + j;
//				neighbor.value = this->value;
//				neighbors.push_back(neighbor);
//			}
//		}
//	}
//	void PrintCell() {
//		std::cout << "\nCell : ( " << this->position.column << "," << this->position.row << " ) - " << "Value" << this->value;
//		std::cout << "\nNeighbors : " << std::endl;
//		for (auto neighbor : this->neighbors) {
//			std::cout << "\nCell : ( " << neighbor.coordinates.column << "," << neighbor.coordinates.row << " ) - " << "Value" << neighbor.value;;
//		}
//	}
//
//
//};
//
//class GameBoard {
//public:
//	int displayBoard[9][9];
//	std::vector<SudokuCell> cells;
//	GameBoard() {
//		for (int i = 0; i < 9; i++) {
//			for (int j = 0; j < 9; j++) {
//				SudokuCell cell = SudokuCell(i, j, 0);
//				cells.push_back(cell);
//			}
//		}
//		cells[0].value = 1;
//		cells[5].value = 2;
//		cells[19].value = 3;
//		cells[20].value = 4;
//		cells[4].value = 5;
//		cells[77].value = 6;
//		cells[43].value = 7;
//		cells[55].value = 8;
//		cells[13].value = 9;
//		HighlightNeighbors(cells[0]);
//	}
//
//	void PrintBoard() {
//		for (auto cell : this->cells) {
//			this->displayBoard[cell.position.column][cell.position.row] = cell.value;
//		}
//		std::cout << "\n---------+---------+---------" << std::endl;
//		for (int i = 0; i < 9; i++) {
//			for (int j = 0; j < 9; j++) {
//				if (j == 3 || j == 6) {
//					std::cout << "|";
//				}
//				std::cout << " " << this->displayBoard[i][j] << " ";
//			}
//			if (i == 2 || i == 5) {
//				std::cout << "\n---------+---------+--------";
//			}
//			std::cout << std::endl;
//		}
//		std::cout << "---------+---------+---------" << std::endl;
//	}
//	int GetIndex(Coordinates cell) {
//		return cell.column * 9 + cell.row;
//	}
//
//	// get coordinates by index
//	Coordinates GetCoordinates(int index) {
//		return Coordinates{ index / 3, index % 3 };
//	}
//
//	// get cell by index
//	std::shared_ptr<SudokuCell> at(int index) {
//		GetCoordinates(index);
//		std::cout << "get pointer index" << std::endl;
//	}
//	// get cell by coord
//	std::shared_ptr<SudokuCell> at(Coordinates position) {
//		std::cout << "get pointer coord" << std::endl;
//	}
//
//	int GetIndexValue(int index) {
//		int value;
//		value = this->cells[index].value;
//		return value;
//	}
//
//	std::set<int> GetNeighborValues() {
//		int index;
//		int value;
//		std::set<int> neighborValues = {};
//		return neighborValues;
//		for (auto neighbor : this->cells) {
//			index = GetIndex(neighbor.position);
//			value = GetIndexValue(index);
//			neighborValues.insert(value);
//		}
//		std::cout << "\nNeighbor Values\n";
//		std::cout << "\n================\n";
//		for (auto value : neighborValues) {
//			std::cout << value;
//		}
//	}
//
//	void HighlightNeighbors(SudokuCell cell) {
//		for (auto neighbor : cell.neighbors) {
//			std::cout << neighbor.coordinates.column;
//			this->displayBoard[neighbor.coordinates.row][neighbor.coordinates.column] = 7;
//		}
//	}
//};
//
//
//
//
//
//
//
//
//
//
//int main() {
//	int displayBoard[9][9] = { 0 };
//	//board[5][7] = 0;
//	//std::vector<SudokuCell> gameBoard;
//	/*for (int i = 0; i < 9; i++) {
//	for (int j = 0; j < 9; j++) {
//	board[i][j] = 1;
//	}
//	}*/
//	//board[5][7] = 0;
//	//FillBoard(displayBoard);
//	GameBoard gameBoard = GameBoard();
//	//PrintBoard(displayBoard, gameboard);
//
//	gameBoard.PrintBoard();
//	system("pause");
//}
