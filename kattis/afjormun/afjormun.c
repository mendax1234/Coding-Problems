#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LEN 300

void format_meme(char *line)
{
  line[0] = toupper(line[0]);
  for (long i = 1; line[i] != 0; i += 1)
  {
    if (isupper(line[i]))
    {
      line[i] = tolower(line[i]);
    }
  }
}

int main()
{
  long n;
  scanf("%ld\n", &n);
  char **line = calloc((size_t)n, sizeof(char *));
  if (line == NULL)
  {
    return 1;
  }
  for (long i = 0; i < n; i += 1)
  {
    line[i] = calloc(MAX_LEN, sizeof(char));
    if (line[i] == NULL)
    {
      for (long j = 0; j < i; j += 1)
      {
        free(line[j]);
      }
      free(line);
      return 1;
    }
  }

  for (long i = 0; i < n; i += 1)
  {
    if (fgets(line[i], MAX_LEN, stdin))
    {
      line[i][strcspn(line[i], "\n")] = 0;
    }
  }

  for (long i = 0; i < n; i += 1)
  {
    format_meme(line[i]);
    printf("%s\n", line[i]);
  }
  
  for (long i = 0; i < n; i += 1)
  {
    free(line[i]);
  }
  free(line);
}
