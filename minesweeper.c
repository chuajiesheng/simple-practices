/**
 * CS1010 AY2012/3 Semester 1 Lab4 Ex3
 * minesweeper.c 
 * <Type in description of program>
 * <Type your name here>
 * <Type your discussion group here>
 */

#include <stdio.h>
#define MINE '*'       // a mine-filled square
#define L1_ROWS 8      // number of rows for level-1 grid
#define L1_COLS 8      // number of columns for level-1 grid
#define L2_ROWS 12     // number of rows for level-2 grid
#define L2_COLS 16     // number of columns for level-2 grid
#define L3_ROWS 16     // number of rows for level-3 grid
#define L3_COLS 30     // number of columns for level-3 grid

int main(void)
{
	int i, j;
	int level, rows, cols;
	int rows_limit[3] = {L1_ROWS, L2_ROWS, L3_ROWS};
	int cols_limit[3] = {L1_COLS, L2_COLS, L3_COLS};

	scanf("%d\n", &level);

	rows = rows_limit[level-1];
	cols = cols_limit[level-1];

	int mine[rows][cols];
	for (i = 0; i <= rows; i++) {
		for (j = 0; j <= cols; j++) {
			char c = 0;
			scanf("%c", &c);
			if (c == 45) { // -
				mine[i][j] = 0;
				//printf("-");
			} else if (c == 42) { // *
				mine[i][j] = 1;
				//printf("*");
			}
		}
		//printf("\n");
	}

	//printf("\n");

	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			int current = 0;

			int r, c;
			// up position
			r = i - 1;
			c = j;
			if (r >= 0) {
				//printf("accessing [%d][%d]\n", r, c);
				current += mine[r][c];
			}

			// down position
			r = i + 1;
			c = j;
			if (r < rows) {
				//printf("accessing [%d][%d]\n", r, c);
				current += mine[r][c];
			}

			// left position
			r = i;
			c = j - 1;
			if (c >= 0) {
				//printf("accessing [%d][%d]\n", r, c);
				current += mine[r][c];
			}

			// right position
			r = i;
			c = j + 1;
			if (c < cols) {
				//printf("accessing [%d][%d]\n", r, c);
				current += mine[r][c];
			}

			// up right positon
			r = i - 1;
			c = j + 1;
			if (r >= 0 && c < cols) {
				//printf("accessing [%d][%d]\n", r, c);
				current += mine[r][c];
			}

			// down right position
			r = i + 1;
			c = j + 1;
			if (r < rows && c < cols) {
				//printf("accessing [%d][%d]\n", r, c);
				current += mine[r][c];
			}

			// down left position
			r = i + 1;
			c = j - 1;
			if (r < rows && c >= 0) {
				//printf("accessing [%d][%d]\n", r, c);
				current += mine[r][c];
			}

			// up left position
			r = i - 1;
			c = j - 1;
			if (r >= 0 && c >= 0) {
				//printf("accessing [%d][%d]\n", r, c);
				current += mine[r][c];
			}


			// current position
			if (mine[i][j] == 1) {
				current = 9;
			}

			printf(" %d", current);
		}
		printf("\n");
	}

    return 0;
}

// Read the grid for minefield
void scan_mines(char grid[][L3_COLS+1], int rows) {
	int r;

	for (r=0; r<rows; r++) {
		scanf("%s", grid[r]); // Alternatively: gets(grid[r])
	}

}

