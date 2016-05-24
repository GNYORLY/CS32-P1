#pragma once

class History
{
public:
	History(int nRows, int nCols);
	bool record(int r, int c);
	void display() const;
private:
	int his = 0;
	int m_rows;
	int m_cols;
	int rows[100];
	int cols[100];
};

