#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

string letters = "abcdefghijklmnopqrstuvwxyz";
// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};


int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!...");
    }
    else if (score1 == score2)
    {
        printf("Tie!\n");
    }
    else
    {
        printf("Player 2 wins!...");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    //score for player
    int scores = 0;
    //outerloop for extracting each character of the word entered
    for (int i = 0; word[i] != '\0'; i++)
    {
        //converts any uppercases to lowercases
        if (isupper(word[i]))
        {
            word[i] = tolower(word[i]);
        }
        //inner loop to equate the characters with the characters in 'letters' array
        for (int j = 0; j < 26; j ++)
        {
            //finds the index of the character in 'letters' array and adds the int of tht index number
            //from the points array
            // eg if we find c, it is of index 2, now we add the value at index 2 in POINTS[] to score
            if (word[i] == letters [j])
            {
                scores = scores + POINTS[j];
            }
        }
    }
    return scores;
}
