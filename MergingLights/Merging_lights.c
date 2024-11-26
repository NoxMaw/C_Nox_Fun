#include <stdio.h>
#include <string.h>
#include <ctype.h>

void print_square(char arr[12][9]);
void initialize_board(char arr[12][9]);
void move_piece(char arr[12][9], int A, int B, char turn);
int select_piece(char arr[12][9], char turn);
int convert_character(char Z);
void preview_movement(char arr[12][9], int A, int B);
void finalize_movement(char arr[12][9], int A, int B, char turn);
void select_movement(char arr[12][9], char turn);

int main()
{
  int playing = 1;
  char arr[12][9];
  char turn = 'B';
  int c;

  printf("Welcome to the game\n pieces: 🍺>🍻>🍾 || 🍪>🥯>🥞\n Select 'Q' to quit\n");

  initialize_board(arr);
  print_square(arr);
  while(playing)
    {
      playing = select_piece(arr, turn);
      turn = turn == 'B' ? 'C' : 'B';
    }

  return (0);
}

/**
 *Handles selecting of pieces
 */
int select_piece(char arr[12][9], char turn)
{
  char A = 'A', B = 'B';
  int a = 0, b = 0, c = 0;

  if (turn != 'B' && turn != 'C')
    turn = 'B';

  printf("Please select a piece, it is now %c's turn\n", turn);
  printf("Type Q to quit");
  while(1)
    {
      while ((c = getchar()) != '\n' && c != EOF);
      printf("A: ");
      A = toupper(getchar());
      if (A == 'Q')
	return(0);
      while ((c = getchar()) != '\n' && c != EOF);
      printf("0: ");
      B = getchar();
      printf("============\n");

      a = convert_character(A);
      b = (B - '0') - 1;

      /**Debug message
       *printf("arr[a:%d][b:%d] == %c\n", a, b, arr[a][b]);*/

      if (arr[a][b] == turn)
	{
	  /** Visual feedback */
	  arr[a][b] = 'X';
	  printf("Piece at %c %c selected\n", A, B);

	  /** Move piece handler*/
	  move_piece(arr, a, b, turn);
	  return (1);
	}
      else
	{
	  printf("Invalid piece\n");
	}
    }
}

void move_piece(char arr[12][9], int A, int B, char turn)
{
  int i = 0, c;

  printf("Possilbe movements:\n");
  preview_movement(arr, A, B);
  select_movement(arr, turn);
  finalize_movement(arr, A, B, turn);
}

void finalize_movement(char arr[12][9], int A, int B, char turn)
{
  arr[A][B] = '.';
  for(int i = 0; i < 12; i++) {
    for(int j = 0; j < 9; j++) {
      if(arr[i][j] == '@') {
	arr[i][j] = '.';
      }
    }
  }
  print_square(arr);
}

void select_movement(char arr[12][9], char turn)
{
  char A, B;
  int a, b, c;

  printf("Please select a place to move\n");
  while(1)
    {
      printf("A: ");
      while ((c = getchar()) != '\n' && c != EOF);
      A = toupper(getchar());
      printf("0: ");
      while ((c = getchar()) != '\n' && c != EOF);
      B = getchar();

      a = convert_character(A);
      b = (B - '0') - 1;

      if (arr[a][b] == '@')
	{
	  arr[a][b] = turn;
	  printf("Moved piece to %c %c\n", A, B);
	  return;
	}
      else
	{
	  printf("Invalid movement\n");
	}
    }
}

void preview_movement(char arr[12][9], int A, int B)
{
  /** Frontal movement representation*/
  if (A < 12)
    {
      arr[A + 1][B] = '@';
      if (B < 9)
	arr[A + 1][B + 1] = '@';
      if (B > 0)
	arr[A + 1][B - 1] = '@';
    }
  /** Diagonal back movement representation*/
  if (A > 1)
    {
      if (B < 9)
	arr[A - 1][B + 1] = '@';
      if (B > 0)
	arr[A - 1][B - 1] = '@';
    }
  print_square(arr);
}

/**
 *Converts a char to an int
 */
int convert_character(char Z)
{
  /**
   * A = 0, B = 1, etc...
   */
  int i = 0;
  char A = 'A';

  while (A != Z)
    {
      A++;
      i++;
    }

  return(i);
}

void initialize_board(char arr[12][9])
{
  int i, j;
  for(i = 0; i < 12; i++)
    {
      for(j = 0; j < 9; j++)
	{
	  if (i == 0 && (j < 4 || j > 4))
	    arr[i][j] = 'B';
	  else if (i == 11 && (j < 4 || j > 4))
	    arr[i][j] = 'C';
	  else
	    arr[i][j] = '.';
	}
    }
}

void print_square(char arr[12][9])
{
  int i, j, k = 1;
  char alpha = 'A';

  printf("============\n");
  putchar(' ');
  for (k = 1; k < 10; k++)
    printf("%d", k);
  putchar('\n');

  for(i = 0; i < 12; i++)
    {
      for(j = 0; j < 9; j++)
	{
	  if (j == 0)
	    printf("%c", alpha++);
	  printf("%c", arr[i][j]);
	}
      printf("\n");
    }
  printf("============\n");
}
