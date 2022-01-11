#include<stdio.h>

//Function to print out matrix on console
void displayMatrix(int row, int column, int matrix[row][column]);

//Function to multiply two matrices
void matrixMultiply(int row1, int column1, int matrixA[row1][column1], int column2, int matrixB[column1][column2], int result[row1][column2]);

//Driver function
int main()
{
	int p, q, r;
	int i, j;
	printf("Enter number of rows of matrix A: ");
	scanf("%d", &p);
	printf("Enter number of columns of matrix A: ");
	scanf("%d", &q);
	
	int matrixA[p][q];
	printf("\nEnter elements of matrix A\n");
	for(i = 0; i < p; i++)
	{
		for(j = 0; j < q; j++)
		{
			printf("A[%d][%d] = ", i, j);
			scanf("%d", &matrixA[i][j]);
		}
	}
	
	printf("\nNOTICE: Number of rows of matrix B = %d for matrix multiplication\n\n", q);
	printf("Enter number of columns of matrix B: ");
	scanf("%d", &r);
	
	int matrixB[q][r];
	printf("\nEnter elements of matrix B\n");
	for(i = 0; i < q; i++)
	{
		for(j = 0; j < r; j++)
		{
			printf("B[%d][%d] = ", i, j);
			scanf("%d", &matrixB[i][j]);
		}
	}
	printf("\nMatrix A: \n");
	displayMatrix(p, q, matrixA);
	printf("\nMatrix B: \n");	
	displayMatrix(q, r, matrixB);
	
	int resultMatrix[p][r];
	matrixMultiply(p, q, matrixA, r, matrixB, resultMatrix);
	printf("\nResultant matrix A * B: \n");
	displayMatrix(p, r, resultMatrix);
	
	return 0;
}


void displayMatrix(int row, int column, int matrix[row][column])
{
	int i, j;
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < column; j++)
		{
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return;
}


void matrixMultiply(int row1, int column1, int matrixA[row1][column1], int column2, int matrixB[column1][column2], int result[row1][column2])
{
	int row2 = column1;
	int i, j, k;

	for(i = 0; i < row1; i++)
	{
		for(j = 0; j < column2; j++)
		{
			result[i][j] = 0;
			for(k = 0; k < column1; k++)
			{
				result[i][j] += matrixA[i][k] * matrixB[k][j];
			}
		}
	}
	return;
}
