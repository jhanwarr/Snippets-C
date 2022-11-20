#include <stdio.h>
#include <ctype.h>
//packages required

int main(void) 
{
    int high = 100;
    int low = 1;
    int mid = (high + low) / 2;
    
    char r;
    char enter;
    int infinite = 1;

    while(infinite)
    {
        printf("Hi! You have to pick an integer between 1 and 100. I will try and find it within 7 guesses.\n");
        printf("\n");
        
        printf("Enter 'y' if the number picked is the guessed number.\n");
        printf("Enter 'h' if the number is higher than the guessed number.\n");
        printf("Enter 'l' if the number is lower than the guessed number.\n");
        
        printf("Enter any key to continue: ");
        getchar();
        getchar();
        
        int i = 1;
        
        while(i <= 7)
        {
            printf("Guess %d: Is the number you picked %d?\n", i, mid);
            r = getchar();
            enter = getchar();
            
            if(r == 'y')
            {
                i = -1;
                break;
            }
            
            else if(r == 'h')
            {
                high = mid - 1;
                mid = (high + low) / 2;
            }
            
            else if(r == 'l')
            {
                low = mid + 1;
                mid = (high + low) / 2;
            }
            
            else
            {
                printf("Invalid input. Please input again.\n");
                i--;
            }
            i += 1;
        }
        
        if(i == -1)
            printf("Hurrah! We guessed your number correctly!\n");

        else
            printf("Oops, we couldn't guess your number :-(\n");
            
        printf("Enter 'y' to play again; otherwise enter any other character to exit.\n");

        if(getchar() != 'y')
            infinite = 0;
        
        getchar();
    }

    printf("I hope you had fun playing. \n");
    return 0;
}
