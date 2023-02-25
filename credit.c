#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long number;
    long counter,count, first_two,a,b,c,m,n,even_sum, odd_sum, final_sum;
    //continually prompts the user to input a decent interger only number
    do
    {
        number = get_long("Enter card number: ");
    }
    while ( number < 0 );
    long original = number;

    // counts the number of digits in the input number
    for (count = 0; number != 0; count++)
    {
        number = number / 10; // the number ends up to be zero after the for loop
    }
    //printf("The number of digits is: %li\n", count);

    // to prevent the number to become 0 again, we assign it to another variable 'original' in line 15

    //Derive the first 2 digits of the number
    first_two = original / pow(10,count - 2);
    //printf("The first two digits of the number are: %li\n", first_two);

    // Calculate the odd sum for the luhn's algorithm
    odd_sum = 0;
    for (int i = 0; i <= count; i = i + 2)
    {
        a = original / pow(10,i-1);
        b = a % 10;
        c = b * 2;
        if (c > 9)
        {
            c = (c/10) + (c%10);
            odd_sum = odd_sum + c;
        }
        else
        {
            odd_sum = odd_sum + c;
        }
    }
   // printf("The oddsum is : %li\n", odd_sum);

    // Calculate the even sum for the luhn's algorithm
    even_sum = 0;
    for (int j = 1; j <= count; j = j+2)
    {
        m = original / pow(10,j-1);
        n = m % 10;
        even_sum = even_sum + n;
    }
  //  printf("The even sum is: %li\n", even_sum);

    // Final checksum
    final_sum = even_sum + odd_sum;
  //  printf("The sum is : %li\n", final_sum);
    final_sum = final_sum % 10;

    // Checking validity of card after passing the luhn's algorithm
    if (final_sum == 0)
    {
       // printf("The card number passes validity test.\nThe card is ");
        // Check for MASTERCARD
        if (count == 16)
        {
            if (first_two == 4 || first_two == 51 || first_two == 52 || first_two == 53 || first_two == 54 || first_two == 55)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        // Check for VISA
        else if (count == 13)
        {
            if (first_two == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (count == 16)
        {
            if (first_two == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        //Check for AMEX
        else if (count == 15)
        {
            if (first_two == 34 || first_two == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        // Output when none matches
        else
        {
            printf("INVALID\n");
        }

    }
    else
    {
        printf("INVALID\n");
    }

}