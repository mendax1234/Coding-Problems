#include <stdio.h>
#include <string.h>

#define MAX_LEN 1001

int main()
{
  char line[MAX_LEN];

  if (fgets(line, MAX_LEN, stdin))
  {
    line[strcspn(line, "\n")] = 0;
  }

  printf("%s\n", line);
}
