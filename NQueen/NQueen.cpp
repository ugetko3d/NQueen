#include <iostream>

bool solve(int col, int** chessboard);
bool safeCell(int row, int col, int** chessboard);
void printBoard(int** chessboard);

int n;

int main()
{
	std::cout << "NQueen problem solver! \n\n";
	std::cout << "Enter a number N for a NxN chessboard: \n";
	std::cin >> n;

	int** chessboard = (int**) calloc(n, sizeof(int*));
	int i, j;
	for (i = 0; i < n; i++)
	{
		chessboard[i] = (int*) calloc(n, sizeof(int));
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			chessboard[i][j] = 0;
		}
	}

	if (solve(0, chessboard))
	{
		std::cout << "Found solution!\n\n";
		printBoard(chessboard);
	}
	else
	{
		std::cout << "No solution found..." << std::endl;
	}

}

bool solve(int col, int** chessboard)
{
	if (col == n)
	{
		return true;
	}
	for (int i = 0; i < n; i++)
	{
		if (safeCell(i, col, chessboard))
		{
			chessboard[i][col] = 1;
			if (solve(col + 1, chessboard))
			{
				return true;
			}
			else
			{
				chessboard[i][col] = 0;
			}
		}
	}
	return false;
}

bool safeCell(int row, int col, int** chessboard)
{
	int i, j;

	for (i = 0; i < col; i++) {
		if (chessboard[row][i] == 1) {
			return false;
		}
	}

	for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
		if (chessboard[i][j] == 1) {
			return false;
		}
	}

	for (i = row, j = col; i < n && j >= 0; i++, j--) {
		if (chessboard[i][j] == 1) {
			return false;
		}
	}
}

void printBoard(int** chessboard)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			std::cout << chessboard[i][j] << "\t";
		}
		std::cout << "\n";
	}
}