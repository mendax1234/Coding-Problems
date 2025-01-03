#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 12
#define TEN "10"

int main()
{
  char line[MAX_LEN];
  if (fgets(line, MAX_LEN, stdin))
  {
    line[strcspn(line, "\n")] = 0;
  }
  // Check if it satisfies
  bool is_champ = true;
  int index = 0;
  for (int i = 0; line[i] != 0 && i < 10; i += 1)
  {
    index = i + 1;
    if (i != 9 && line[i] != '1' + i)
    {
      is_champ = false;
      break;
    }
    if (i == 9 && strcmp(line + i, TEN) != 0)
    {
      is_champ = false;
      break;
    }
  }
  is_champ ? printf("%d\n", index) : printf("-1\n");
}
