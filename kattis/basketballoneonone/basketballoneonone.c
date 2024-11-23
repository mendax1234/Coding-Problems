#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 200

int main()
{
  char line[MAX_LEN];

  if (fgets(line, MAX_LEN, stdin))
  {
    line[strcspn(line, "\n")] = 0;
  }
  
  long score1 = 0;
  long score2 = 0;
  for (long i = 0; line[i] != 0; i += 2)
  {
    if (line[i] == 'A')
    {
      score1 += (long)line[i+1] - (long)'0';
    }
    else
    {
      score2 += (long)line[i+1] - (long)'0';
    }
    if (score1 >= 11 && score1 - score2 >= 2)
    {
      printf("A\n");
      return 0;
    }
    if (score2 >= 11 && score2 - score1 >= 2)
    {
      printf("B\n");
      return 0;
    }
  }
}
