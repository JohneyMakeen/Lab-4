#include <stdio.h>
#define SIZE 5

// Functions for matrix operations
void addtwomatrices(int result[SIZE][SIZE], int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE]);
void multiplytwomatrices(int result[SIZE][SIZE], int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE]);
void transposematrix(int result[SIZE][SIZE], int matrix[SIZE][SIZE]);
void printmatrix(int matrix[SIZE][SIZE]);

int main() {
    // two 5x5 matrices with some values
    int matrix1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int matrix2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    int result[SIZE][SIZE]; // Matrix to store results

    // Perform matrix addition
    addtwomatrices(result, matrix1, matrix2);
    printf("Matrix Addition:\n");
    printmatrix(result);

    // Perform matrix multiplication
    multiplytwomatrices(result, matrix1, matrix2);
    printf("Matrix Multiplication:\n");
    printmatrix(result);

    // Perform matrix transpose on matrix1
    transposematrix(result, matrix1);
    printf("Transpose of Matrix 1:\n");
    printmatrix(result);

    return 0;
}

// Function to add two matrices
void addtwomatrices(int result[SIZE][SIZE], int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplytwomatrices(int result[SIZE][SIZE], int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0; // Initialize the result element to 0
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function to transpose a matrix
void transposematrix(int result[SIZE][SIZE], int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[j][i] = matrix[i][j]; // Assign the transposed element
        }
    }
}

// Function to print the matrix 
void printmatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%5d ", matrix[i][j]); // Print each element with a width of 5 for alignment
        }
        printf("\n"); // Newline after each row
    }
    printf("\n"); // Extra newline for readability between matrices
}
