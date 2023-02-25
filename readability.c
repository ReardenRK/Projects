#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// function to count no of letters
int count_letters(string text);

// function to count no of words
int count_words(string text);

// function to count no of sentences
int count_sentences(string text);

int main(void)
{
    string text = get_string("Enter text: ");
    // l = number of letters
    float l = count_letters(text);
    // w = number of words
    float w = count_words(text);
    // s = number of sentences
    float s = count_sentences(text);

    printf("Number of letters = %f\n",l);
    printf("Number of words = %f\n",w);
    printf("Number of sentences = %f\n",s);



    // L = rate of letters per 100 words
    float L = (l/w) * 100.0;
    printf("Average number of letters per 100 words: %f\n", L);
    // S = rate of sentences per 100 words
    float S = (s/w) * 100.0;
    printf("Average number of sentences per 100 words: %f\n", S);

    // index = coleman - liaw index
    float index = 0.0588 * L - 0.296 * S - 15.8 ;

    // if index is 16 or greater, we print index as 16+
    if ((int) index >= 16)
    {
        printf("Grade : 16+\n");
    }
    // if index is lesser than 16, we print index as the intended value
    else
    {
        printf("Grade : %i\n", (int) index);
    }
}

// letters can be counter with isalphabetical condition
// the condition can be looped and a counter be added
// the counter adds +1 whenever the char of the array is alphabetical
// the counter remains the same if isalphabetical is not true
int count_letters(string text)
{
    // we start with a for loop that loops till we reach the terminal nul value of string
    int letters = 0;
    for (int i = 0;text[i] != '\0';i++)
    {
        if (isalpha(text[i])) // if isalpha is not false i.e. isalpha is true
        {
            letters ++; // 1 letter is added to counter
        }
    }
    return letters;
}


// words can be counted by counting the nummber of spaces, exclamations, dots, questions marks etc
// the condition is looped to count the number of words
// the counter adds +1 whenever the char is one of coditions specified
// the counter remains the same if condition is not met
int count_words(string text)
{
    int words = 0;
    //loop throughout the chars of the string till the nul value is reached
    for (int j = 0; text[j] != '\0';j++)
    {
        // if one of the chars specifies the following condition, the counter increases by 1
        if ( text[j] == '.' || text[j] == '!' || text[j] == '\"' || text[j] == '?')
        {
            if (text[j+1] != ' ')
            {
                words ++;
            }
        }
        else if (text[j] == ' ' && isalpha(text[j+1]))
        {
            words ++;
        }
    }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;

    for (int k = 0;text[k] != '\0';k++)
    {
        if (text[k] == '.' || text[k] == '!' || text[k] == '\"' || text[k] == '?')
        {
            sentences ++;
        }
    }
    return sentences;
}
