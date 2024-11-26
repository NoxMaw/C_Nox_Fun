#include <stdio.h>
#include <ctype.h>

int fun(char *, int);

int main()
{
  int sum = 0, game_number = 1;
  FILE *file;
  char line[999];

  file = fopen("puzzle", "r");
  if (file == NULL)
    {
      perror("Error opening the file ");
      return 1;
    }

  while (fgets(line, sizeof(line), file))
    {
	  sum += fun(line, game_number);
	  game_number++;
     }

  fclose(file);
  printf("The total number is %d\n", sum);
  return 0;
}

int fun(char *game, int game_number)
{
  int red = 0, green = 0, blue = 0, temp = 0;
  int challenge_red = 12, challenge_green = 13, challenge_blue = 14;

  printf("game %s", game);

  /** Advance 'Game' until the first space */
  while (*game != ':')
    *game++;
  *game++;
  *game++;
  while(*game)
    {
      temp = 0;
      if (*game >= '0' && *game <= '9')
        {
	  temp = *game - '0';
        }
      *game++;

      if (*game == ' ')
        {
	  *game++;
        }

      else if (*game != '\0' && (*game >= '0' && *game <= '9'))
        {
	  temp = (temp * 10) + (*game - '0');
	  *game++;
	  *game++;
        }

      if (temp > 0)
	{
	  if (*game == 'r' && temp > red)
            {
	      red = temp;
	      temp = 0;
            }
	  if (*game == 'g' && temp > green)
            {
	      green = temp;
	      temp = 0;
            }
	  if (*game == 'b' && temp > blue)
            {
	      blue = temp;
	      temp = 0;
            }
        }

    }

  printf("red, green, blue %d %d %d, game %d\n", red, green, blue, game_number);

  /**  if (red <= challenge_red && green <= challenge_green && blue <= challenge_blue)
    {
      printf("Passed: %d\n\n", game_number);
      return (game_number);
    }*/
  putchar('\n');
  return (red * green * blue);
}
