#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_LEN 82

bool is_vowel(char c)
{
  c = tolower(c);
  if (c == 'a' || c == 'e' || c == 'i'
      || c == 'o' || c == 'u')
  {
    return true;
  }
  return false;
}

int main() {
  char line[MAX_LEN];

  if (fgets(line, MAX_LEN, stdin))
  {
    line[strcspn(line, "\n")] = 0;
  }

  int vowel = 0;
  for (int i = 0; line[i] != 0; i += 1)
  {
    if (is_vowel(line[i]))
    {
      vowel += 1;
    }
  }

  printf("%d\n", vowel);
}
