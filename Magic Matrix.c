/*
 * CSC 161-02 Spring 2022 Assignment
 */

#include <stdio.h>

void print(int size, int matrix[][size])
{
    printf("The Magic Square is -- \n\n");
    
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int magic_square(int num, int size, int matrix[][size])
{
    int diagonal_2 = 0;
    int diagonal = 0;
    int coloumn = 0;
    int row = 0;
    
    for (int j = 0; j < size; j++)
    {
        diagonal += matrix[j][j];
    }
    
    for (int j = 0; j < size; j++)
    {
        coloumn = 0;
        
        for (int i = 0; i < size; i++)
        {
            coloumn += matrix[i][j];
        }
        
        if (coloumn != diagonal)
        {
            printf("The %dth matrix is not a Magic Square.\n\n", num);
            return 0;
        }
    }
    
    for (int i = 0; i < size; i++)
    {
        row = 0;
        
        for(int j = 0; j < size; j++)
        {
            row += matrix[i][j];
        }
        
        if (row != diagonal)
        {
            printf("The %dth matrix is not a Magic Square.\n\n", num);
            return 0;
        }
    }
    
    for(int i = 0; i < size; i++)
    {
        int j = size - 1;
        diagonal_2 += matrix[i][j-i];
    }
    
    if (diagonal_2 != diagonal)
    {
        printf("The %dth matrix is not a Magic Square.\n\n", num);
        return 0;
    }
    
    printf("The given matrix is a Magic Square!\n\n");
    print(size, matrix);
    return 1;
}

int user_input()
{
    printf("Enter the size of the matrix : \n");
    int m;
    scanf("%d", &m);
    
    int matrix[m][m];
    
    printf("Enter the elements of matrix -- \n");
    
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int result = magic_square(5, m, matrix);
}

int main(void) 
{
	printf("Menu -\n\n");
	printf("1. m_1: {{2, 7, 6}, \n");
	printf("         {9, 5, 1}, \n");
	printf("         {4, 3, 8}}\n\n");
	
	printf("2. m_2: {{8, 0, 7}, \n");
	printf("         {4, 5, 6}, \n");
	printf("         {3, 10, 2}}\n\n");
	
	printf("3. m_3: {{2, 16, 13, 3}, \n");
	printf("         {11, 5, 8, 10}, \n");
	printf("         {7, 9, 12, 6}, \n");
	printf("         {14, 4, 1, 15}}\n\n");
	
	printf("4. m_4: {{2, 16, 13, 3}, \n");
	printf("         {11, 5, 8, 10}, \n");
	printf("         {7, 9, 12, 6}, \n");
	printf("         {14, 4, 1, 7}}\n\n");
	
	printf("5. Input your own matrix or QUIT\n\n");
	
	
	int m_1[3][3] = {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}};
	int result = magic_square(1, 3, m_1);
	                
	int m_2[3][3] = {{8, 0, 7}, {4, 5, 6}, {3, 10, 2}};
	result = magic_square(2, 3, m_2);
	                 
	int m_3[4][4] = {{2, 16, 13, 3}, {11, 5, 8, 10}, {7, 9, 12, 6}, {14, 4, 1, 15}};
	result = magic_square(3, 4, m_3);
	                 
	int m_4[4][4] = {{2, 16, 13, 3}, {11, 5, 8, 10}, {7, 9, 12, 6}, {14, 4, 1, 7}};
	result = magic_square(4, 4, m_4);
	
	
	printf("Enter 'y' if you want to input your own matrix. Else enter any character to QUIT : ");
	char choice;
	scanf("%c", &choice);
	
	if (choice == 'y')
	    result = user_input();
	    
	printf("Thanks a lot for using my code. I hope it helped :-)\n\n");
	
	return 0;
}