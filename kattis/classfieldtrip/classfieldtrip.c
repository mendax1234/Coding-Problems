#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 102

void merge(char *line1, char *line2, char *merged)
{
  int i, j;
  int k = 0;
  for (i = 0, j = 0; line1[i] != 0 && line2[j] != 0; k += 1)
  {
    if (line1[i] < line2[j])
    {
      merged[k] = line1[i];
      i += 1;
    }
    else
    {
      merged[k] = line2[j];
      j += 1;
    }
  }
  if (line1[i] == 0)
  {
    for (int m = j; line2[m] != 0; m += 1, k += 1)
    {
      merged[k] = line2[m];
    }
  }
  else if (line2[j] == 0)
  {
    for (int m = i; line1[m] != 0; m += 1, k += 1)
    {
      merged[k] = line1[m];
    }
  }
}

int main()
{
  char line1[MAX_LEN];

  if (fgets(line1, MAX_LEN, stdin))
  {
    line1[strcspn(line1, "\n")] = 0;
  }
  
  char line2[MAX_LEN];

  if (fgets(line2, MAX_LEN, stdin))
  {
    line2[strcspn(line2, "\n")] = 0;
  }

  int len = strlen(line1) + strlen(line2);
  char *merged = calloc(len + 1, sizeof(char));
  merge(line1, line2, merged);
  merged[len] = 0;
  printf("%s\n", merged);
  free(merged);
}
