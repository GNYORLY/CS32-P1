
#include "history.h"
#include "globals.h"
#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <cstdlib>
using namespace std;

///////////////////////////////////////////////////////////////////////////
//  History implementations
///////////////////////////////////////////////////////////////////////////

History::History(int nRows, int nCols)
{
	m_rows = nRows;
	m_cols = nCols;
}

bool History::record(int r, int c)
{
	if (r < 1 || r > m_rows || c < 1 || c > m_cols)
		return false;
	rows[his] = r;
	cols[his] = c;
	his++;
	return true;
}

void History::display() const
{
	// Position (row,col) in the arena coordinate system is represented in
	// the array element grid[row-1][col-1]
	char grid[MAXROWS][MAXCOLS];
	int r, c;
	
	clearScreen();
	// Fill the grid with dots
	for (r = 0; r < m_rows; r++)
		for (c = 0; c < m_cols; c++)
			grid[r][c] = '.';

	for (int k = 0; k < his; k++)
		if (isalpha(grid[rows[k]][cols[k]]))
		{
			if (grid[rows[k]][cols[k]] != 'Z')
				grid[rows[k]][cols[k]]++;
			else
				continue;
		}
		else
			grid[rows[k]][cols[k]] = 'A';
	
// Draw the grid
	
	for (r = 0; r < m_rows; r++)
	{
		for (c = 0; c < m_cols; c++)
			cout << grid[r][c];
		cout << endl;
	}
	cout << endl;

}
