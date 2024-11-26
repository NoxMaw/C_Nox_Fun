#include <stdio.h>
#include <ctype.h>

int getlinez(FILE *, char *);
int getindex(char *, int);
int checkindex(char *line, int index);

/**
 * Main - Entry point of the program
 */
int main()
{
  char line_one[999] = {'.'}, line_two[999] = {'.'};
  int index_one[99] = {0}, index_two[99] = {0};
  int i = 0, j = 0, temp = 0;
  FILE *file = fopen("puzzle2", "r");

  /** Return error if cant open file */
  if (!file)
    {
      perror("Error opening the file ");
      return (-1);
    }

  /** get first line*/
  getlinez(file, line_one);
  printf("%s", line_one);

  /** Get all indexes from 1st line and store them in index_one */
  while(line_one[i])
    {
      index_one[j] = getindex(line_one, i);
      i++;
      if (index_one[j])
	{
	  temp = checkindex(line_one, index_one[j]);
	  /**printf("%d, j:%d\n", index_one[j], j);*/
	  i = index_one[j] + 1;
	  j++;
	}
    }
  getlinez(file, line_two);

  return (0);
}

/**
 * Gets the next line from the file
 * ands stores it in given buffer[999]
 */
int getlinez(FILE *file, char *nuline)
{
  fgets(nuline, sizeof(char) * 999, file);

  return(0);
}

/**
 * GetIndex
 * Find next char that's not point nor alphanum
 */
int getindex(char *line, int i)
{
  while (line[i] != '\0' && (line[i] == '.' || isdigit(line[i])))
      i++;

  if (line[i + 1])
    return(i);

  return(0);
}

/**
 * CheckIndex
 * check if there are numbers at index or
 * around index
 * Save number of index and return it
 */
int checkindex(char *line, int index)
{
  int i = index, j = 0, l = 0, power = 10;
  int buffer_temp = 0;
  int buffer_numbers[99] = {0};

  printf("line :%s\n index: %d\n", line, index);
  printf("index:  line[%d] %c\n", i, line[i]);

  /** Check current index
   * Do this for up and down line */
  i++;
  if (isdigit(line[i]))
    {
      power = 10;
      buffer_temp = line[i] - '0';
      i--;
      while(isdigit(line[i]))
	{
	  buffer_temp += ((line[i] - '0') * power);
	  i--;
	  power *= 10;
	}
      i = index + 1;
      power = 10;
      while(isdigit(line[i]))
	{
	  buffer_temp *= power;
	  buffer_temp += line[i] - '0';
	  i++;
	}
      if (buffer_temp)
	{
	  buffer_numbers[l] = buffer_temp;
	  l++;
	}
    }
  i = index;

  printf("index found: %d\n", buffer_numbers[0]);
  /** return for testing */
  return (buffer_numbers[0]);

  /** Check index -1
   * Do this for up and down line *
  if (isdigit(line[i - 1]))
    {
      j = index;
      while(isdigit(line[j]))
    }

    /** Check index +1
   * Do this for up and down line *
    if (isdigit(line[i + 1]))
      {
	
      }*/
}
