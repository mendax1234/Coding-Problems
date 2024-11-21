#include <stdio.h>
#include <string.h>

#define MAX_LEN 102

char get_average_ascii(char string[MAX_LEN])
{
  long i = 0;
  long sum = 0;
  while(string[i] != 0)
  {
    sum += (long)string[i];
    i += 1;
  }
  long avg = sum / i;
  return (char)avg;
}

int main()
{
  char string[MAX_LEN];

  if (fgets(string, MAX_LEN, stdin))
  {
    string[strcspn(string, "\n")] = 0;
  }

  putchar(get_average_ascii(string));
}
