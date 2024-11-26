#include <stdio.h>
#include <ctype.h>

int sumLine(char *);

int main()
{
    FILE *file;
    char line[99];
    int sum = 0;

    file = fopen("\string.txt", "r");
    if (file == NULL)
    {
        perror("Error opening the file ");
        return 1;
    }

    while (fgets(line, sizeof(line), file))
    {
        sum += sumLine(line);
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
    return (sum);
}