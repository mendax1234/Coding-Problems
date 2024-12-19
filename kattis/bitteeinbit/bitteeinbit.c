#include <string.h>
#include <stdio.h>

#define MAX_LEN 100

int main()
{
  char line[MAX_LEN];

  if (fgets(line, MAX_LEN, stdin))
  {
    line[strcspn(line, "\n")] = 0;
  }

  putchar(line[0]);
}
