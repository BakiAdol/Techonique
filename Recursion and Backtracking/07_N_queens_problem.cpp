/**
 * N queens problem 
 **/
#include <bits/stdc++.h>
 
using namespace std;

int board_size;
bool board[50][50];

bool isValid(int row, int col)
{	
	/**
	 * It is confirm that no more than one queen placed in same row, because in a particular row,
	 * if this cell is valid then we place a queen and move to next row, and if this cell is not 
	 * valid then we go to next column in same row.
	 * */
	
	// this board[row][col] is an invalid cell if any queen found in this column
	for(int i=0;i<board_size;i++) if(board[i][col]) return false;
	
	// this board[row][col] is an invalid cell if any queen found in it's left diagonal
	for(int i=row,j=col;i>=0 and j>=0;i--,j--) if(board[i][j]) return false;
	
	// this board[row][col] is an invalid cell if any queen found in it's right diagonal
	for(int i=row,j=col;i>=0 and j<board_size;i--,j++) if(board[i][j]) return false;
	
	return true; // otherwise this board[row][col] is an valid cell
}

bool nQueens(int row)
{
	if(row>=board_size)
	{
		// if and only if we reach this step when we found the result, so print this board
		for(int i=0;i<board_size;i++)
		{
			for(int j=0;j<board_size;j++)
			{
				printf(board[i][j] ? " Q" : " .");
			}
			printf("\n");
		}
		return true;
	}
	
	for(int col=0;col<board_size;col++) // try to place a queen in board[row][eacn column]
	{
		if(isValid(row,col)) // if this cell is valid
		{
			board[row][col]=true; // place a queen in this cell
			
			/**
			 * Then let's go to next row. If next row/ row+1 working properly that means, row+1
			 * queen is not attack by any previous row queen then we go on. otherwise our current
			 * row queen is valid cell but attact next row queen so we move current row queen to
			 * this same row next column.
			 **/
			if(nQueens(row+1)) return true;
			board[row][col]=false; // remove queen from this cell if next row is not working
		}
	}
	
	/**
	 * It's for when we can't place any queen int this row, so we need to remove previous row queen
	 * to next column. and continue this process.
	 **/
	return false;
}

int main()
{
	scanf("%d",&board_size); // input an square board size
	
	nQueens(0);
	
	return 0;
}
