#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for input
    int height;
    do
    height = get_int("Enter the height of the pyramid: ");

    while ( height < 1 || height > 8 );

    // print the required number of rows

    int row, column,space;
    //for the number of rows
    for (row = 0; row<height ; row++)
    {
        //for the spaces in each line
        for (space = height-1; space > row; space = space - 1)
        {
            printf(" ");
        }
        for (column = 0; column <= row; column++)
        {
            printf("#");
        }
        printf("  ");
        for (column = 0; column <= row; column++)
        {
            printf("#");
        }
        printf("\n");
    }
}