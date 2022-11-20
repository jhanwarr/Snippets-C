/*
 * CSC 161-02 Spring 2022 Assignment
 */

#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//libraries needed

typedef struct agent 
{
    int x;
    int y;
} agent;


int main(void) 
{    
    srand(time(NULL));
    
    FILE *text;
    
    if ((text = fopen("walk.txt","w")) == NULL)
    {
       printf("Error creating the file. Exiting the code");
       exit(1);
    }
       

    while (1)
    {
        printf("Please enter 's' to run the program : ");
        
        char start[2];
        fgets(start, 2, stdin);
        
        if ( strcmp(start, "s") == 0 )
            break;
      
        else
        {
            printf("Invalid input...\n");
        }
    }
    
    agent agent1; 
    agent1.x = 0;
    agent1.y = 0;
    
    printf("Hello, I am agent 1. \n\n");
    fprintf(text, "Hello, I am agent 1. \n\n");
    printf("My Original Position is : (%d, %d)\n", agent1.x, agent1.y);
    fprintf(text, "My Original Position is : (%d, %d)\n", agent1.x, agent1.y);
    printf("The following positions are - \n\n");
    fprintf(text, "The following positions are - \n\n");
    printf(" Coordinates       Direction\n");
    fprintf(text, " Coordinates       Direction\n");
    printf("%2d : (%2d, %2d)\n", 1, agent1.x, agent1.y);
    fprintf(text, "%2d : (%2d, %2d)\n", 1, agent1.x, agent1.y);
    
    char direction[6];

    for (int i = 1; i < 15; i++)
    {
        int a1 = rand() % 4;
        
        if (a1 == 0)
        {
            agent1.x++;
            strcpy (direction, "right");
        }
            
        else if (a1 == 1)
        {
            agent1.y++;
            strcpy (direction, "up");
        }
            
        else if (a1 == 2)
        {
            agent1.x--;
            strcpy (direction, "left");
        }
        
        else
        {
            agent1.y--;
            strcpy (direction, "down");
        }
        
        printf("%2d : (%2d,%2d)        %s\n", (i+1), agent1.x, agent1.y, direction);
        fprintf(text, "%2d : (%2d,%2d)        %s\n", (i+1), agent1.x, agent1.y, direction);
    }
    
    float dist = sqrt ( ( pow(agent1.x, 2) + pow(agent1.y, 2) ) );
    printf("\nThe Euclidean Distance from the start is : %3f", dist);
    fprintf(text, "\nThe Euclidean Distance from the start is : %3f", dist);

    agent agent2;
    agent2.x = 0;
    agent2.y = 0;

    printf("\n\n\nHello, I am agent 2. \n");
    fprintf(text, "\n\n\nHello, I am agent 2. \n");
    printf("My Original Position is : (%d, %d)\n\n", agent2.x, agent2.y);
    fprintf(text, "My Original Position is : (%d, %d)\n\n", agent2.x, agent2.y);
    printf("The following positions are - \n\n");
    fprintf(text, "The following positions are - \n\n");
    printf(" Coordinates       Direction\n");
    fprintf(text, " Coordinates       Direction\n");
    printf("%2d : (%2d, %2d)\n", 1, agent2.x, agent2.y);
    fprintf(text, "%2d : (%2d, %2d)\n", 1, agent2.x, agent2.y);
    
    
    for (int i = 1; i < 15; i++)
    {
        int a2 = rand() % 5;
        
        if ( (a2 == 0) || (a2 == 4))
        {
            agent2.x++;
            strcpy (direction, "right");
        }
            
        else if (a2 == 1)
        {
            agent2.y++;
            strcpy (direction, "up");
        }
            
        else if (a2 == 2)
        {
            agent2.x--;
            strcpy (direction, "left");
        }
        
        else
        {
            agent2.y--;
            strcpy (direction, "down");
        }
        
        printf("%2d : (%2d,%2d)        %s\n", (i+1), agent2.x, agent2.y, direction);
        fprintf(text, "%2d : (%2d,%2d)        %s\n", (i+1), agent2.x, agent2.y, direction);
    }
    
    dist = sqrt ( ( pow(agent2.x, 2) + pow(agent2.y, 2) ) );
    printf("\nThe Euclidean Distance from the start is : %3f", dist);
    fprintf(text, "\nThe Euclidean Distance from the start is : %3f", dist);
    
    fclose(text); 
    return 0;
}
