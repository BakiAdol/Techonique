/**
 * Knight Tour Problem
 * */
#include <bits/stdc++.h>

using namespace std;

int board_size;

int board[50][50];

// knight can move 8 cells
int krow[]={2,1,-1,-2,-2,-1,1,2};
int kcol[]={1,2,2,1,-1,-2,-2,-1};

bool isValid(int row, int col)
{
	/**
	 * check next move/ cell is valid or not. if next cell is out of board or already visited
	 * then this cell is invalid. Otherwise it's valid cell
	 * */
	return (row>=0 and row<board_size and col>=0 and col<board_size and board[row][col]==0);
}

bool knightsTour(int row, int col, int countCells)
{
	// if all celll is visited that means we found a result.
	if(countCells==board_size*board_size)
	{
		for(int x=0;x<board_size;x++)
		{
			for(int y=0;y<board_size;y++)
			{
				printf("%d ",board[x][y]);
			}
			printf("\n");
		}
		return true;
	}
	
	for(int i=0;i<8;i++)
	{
		int nRow=row+krow[i];
		int nCol=col+kcol[i];
		if(isValid(nRow,nCol))
		{
			countCells++;
			board[nRow][nCol]=countCells;
			/**
			 * we try to visit current cell to all 8 movable cell if those are valid cell.
			 * If 8 of 1 cell is valid then we count this cell and again recursively call
			 * 8 movabel cell. 
			 * */
			if(knightsTour(nRow,nCol,countCells)) return true;
			/**
			 * when we don't go to next cell that means our previous move is invalid. So 
			 * unvisite this cell and again another remain 8 of cells.
			 * */
			countCells--;
			board[nRow][nCol]=0;
		}
	}
	/**
	 * If we didn't move any of 8 cell from this current cell, that means our approach is wrong.
	 * So get back to previous cell and again try.
	 * */
	return false;
}

int main()
{
	scanf("%d",&board_size);
	board[0][0]=1; 
	knightsTour(0,0,1);
	return 0;
}
