#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int sumLine(char *);
char *translate(const char *line);

int main()
{
    FILE *file;
    char line[99];
    char *con;
    int sum = 0;

    file = fopen("string.txt", "r");
    if (file == NULL)
    {
        perror("Error opening the file ");
        return 1;
    }

    while (fgets(line, sizeof(line), file))
    {
        putchar('a');
        con = translate(line);
        //printf("precon: %s", line);
        //printf("%s", con);
        sum += sumLine(con);
        free(con);
    }
    fclose(file);
    printf("The total number is %d", sum);
    getchar();
    return(0);
}

int sumLine(char *string) {
    int i, first = 0, last = 0, sum;

    for (i = 0; string[i]; i++)
    {
        if (isdigit(string[i]))
        {
            if (!first)
                first = string[i] - 48;
            last = string[i] - 48;
        }
    }
    sum = (first * 10) + last;
    //printf("con: %s first %d, last: %d, sum: %d\n\n", string, first, last);
    return (sum);
}

char *translate(const char *line) {
    const char *numbers[][2] =
    {
        {"One", "1"},
        {"Two", "2"},
        {"Three", "3"},
        {"Four", "4"},
        {"Five", "5"},
        {"Six", "6"},
        {"Seven", "7"},
        {"Eight", "8"},
        {"Nine", "9"}
    };
    int word_len;
    char *translated = calloc(999, sizeof(char)); // Allocate space for translation
    int translated_index = 0;
    int j = 0, i = 0;
    int matched = 0;

    while (*line)
    {
        matched = 0;
        for (i = 0; i < 9; i++)
        {
            word_len = strlen(numbers[i][0]);
            for (j = 0; j < word_len; j++)
            {
                if (tolower(line[j]) != tolower(numbers[i][0][j]))
                {
                    break;
                }
            }
            if (j == word_len)
            {
                strcat(translated, numbers[i][1]);
                translated_index += strlen(numbers[i][1]);
                strcat(translated, line);
                translated_index += strlen(line);
                matched = 1;
                break;
            }
        }
        if (!matched)
        {
            translated[translated_index++] = *line;
        }
        line++;
    }
    translated[translated_index] = '\0';

    return translated;
}
