#include <stdio.h>
int binarySearch2D(int matrix[][4], int rows, int cols, int element) {
    int l=0;
    int r=rows*cols-1;
    while (l<=r) {
        int mid = l+(r-l)/2;
        int midElement = matrix[mid / cols][mid % cols];

        if (midElement==element) {
            return 1; 
        } else if (midElement<element) {
            l=mid+1;
        } else {
            r=mid-1;
        }
    }
    return 0;
}

int main() {
    int rows = 3;
    int cols = 4;
    int matrix[3][4] = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    int element = 5;
    int result = binarySearch2D(matrix, rows, cols, element);
    if (result) {
        printf("Element %d found in the 2D array.\n", element);
    } else {
        printf("Element %d not found in the 2D array.\n", element);
    }
    return 0;
}