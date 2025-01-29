#include <stdio.h>

#define ROWS 3
#define COLS 3

int findSaddlePoint(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        int min_row_val = matrix[i][0];
        int min_col_idx = 0;
        for (int j = 1; j < COLS; j++) {
            if (matrix[i][j] < min_row_val) {
                min_row_val = matrix[i][j];
                min_col_idx = j;
            }
        }

        int is_max_in_col = 1;
        for (int k = 0; k < ROWS; k++) {
            if (matrix[k][min_col_idx] > min_row_val) {
                is_max_in_col = 0;
                break;
            }
        }

        if (is_max_in_col) {
            return min_row_val;
        }
    }
    
    return -1;
}

int main() {
    int matrix1[ROWS][COLS] = {
        {3, 8, 10},
        {9, 7, 6},
        {2, 11, 5}
    };

    int matrix2[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int saddlePoint1 = findSaddlePoint(matrix1);
    int saddlePoint2 = findSaddlePoint(matrix2);

    printf("Saddle point in matrix 1: %d\n", saddlePoint1);
    printf("Saddle point in matrix 2: %d\n", saddlePoint2);

    return 0;
}
