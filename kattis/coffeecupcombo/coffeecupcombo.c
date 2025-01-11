#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int n;
  scanf("%d\n", &n);

  char *line = calloc(n+2, sizeof(char));
  
  if (fgets(line, n+2, stdin))
  {
    line[strcspn(line, "\n")] = 0;
  }
 
  int sum = 0;
  int left = 0;
  for (int i = 0; i < n; i += 1)
  {
    if (line[i] == '1')
    {
      left = 2;
      sum += 1;
    }
    else if (left != 0)
    {
      left -= 1;
      sum += 1;
    }
  }
  printf("%d\n", sum);
}
