#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 101

void shorten(char line[MAX_LEN])
{
  long i = 0;
  while (line[i] != 0)
  {
    if (isupper(line[i]))
    {
      putchar(line[i]);
    }
    i += 1;
  }
  putchar('\n');
}

int main()
{
  char line[MAX_LEN];

  if (fgets(line, MAX_LEN, stdin))
  {
    line[strcspn(line, "\n")] = 0;
  }
  
  shorten(line);
} 
