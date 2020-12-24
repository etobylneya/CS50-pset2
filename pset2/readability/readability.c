#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

size_t count_letters(string text);
size_t count_words(string text);
size_t count_sentences(string text);
int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    // printf("%d letter(s)\n", letters);
    // printf("%d word(s)\n", words);
    // printf("%d sentence(s)\n", sentences);
    float L = letters * 100 / words;
    float S = sentences * 100 / words;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    //printf("%f\n", index);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 1 && index < 16)
    {
        int res = round(index);
        printf("Grade %d\n", res);
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    //printf("Grade %d\n", index);
}

size_t count_letters(string text)
{
    size_t length = strlen(text);
    int counter = 0;
    for (size_t i = 0; i <= length; i++)
    {
        //int space = 0;
        //printf("%c\n", text[i]);
        char character = text[i];
        bool space = isspace(character);
        bool digit = isdigit(character);
        bool punct = ispunct(character);
        if (space == true)
        {
            counter++;
            //printf("The counter is %d\n", counter);
        }
        else if (digit == true)
        {
            counter++;
        }
        else if (punct == true)
        {
            counter++;
        }
    }
    length = length - counter;
    return length;
}
size_t count_words(string text)
{
    size_t length = strlen(text);
    int counter = 1;
    for (size_t i = 0; i <= length; i++)
    {
        bool space = isspace(text[i]);
        if (space == true)
        {
            counter++;
        }
    }
    return counter;
}

size_t count_sentences(string text)
{
    size_t length = strlen(text);
    int counter = 0;
    for (size_t i = 0; i <= length; i++)
    {
        //bool space = isspace(text[i]);
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            counter++;
        }
    }
    return counter;
}