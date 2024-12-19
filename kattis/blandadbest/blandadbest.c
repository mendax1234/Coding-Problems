#include <stdio.h>
#include <string.h>

#define MAX_LEN 50

int main()
{
  int n;
  scanf("%d\n", &n);
  if (n == 1)
  {
    char line[MAX_LEN];

    if (fgets(line, MAX_LEN, stdin))
    {
      line[strcspn(line, "\n")] = 0;
    }

    printf("%s\n", line);
  }
  else
  {
    char line1[MAX_LEN];
    char line2[MAX_LEN];

    if (fgets(line1, MAX_LEN, stdin))
    {
      line1[strcspn(line1, "\n")] = 0;
    }

    if (fgets(line2, MAX_LEN, stdin))
    {
      line2[strcspn(line2, "\n")] = 0;
    }

    printf("blandad best\n");
  }
}
