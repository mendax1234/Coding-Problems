#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LEN 20

int string_to_int(char *line)
{
  int len = strlen(line);
  int times = 1;
  int sum = 0;
  for (int i = len; i >= 0; i -= 1)
  {
    if (isdigit(line[i]))
    {
      sum += (line[i] - '0') * times;
      times *= 10;
    }
  }
  return sum;
}

void int_to_string(int num)
{
  char res[MAX_LEN] = { 0 };
 
  int i;
  for (i = 0; num != 0; num /= 10, i += 2)
  {
    int digit = num % 10;
    res[i] = digit + '0';
    res[i+1] = ' ';
  }
  res[i-1] = 0;

  int len = strlen(res);
  for (int i = len; i >= 0; i -= 1)
  {
    putchar(res[i]);
  }
  putchar('\n');
}

int main()
{
  int n;
  scanf("%d\n", &n);
  int *preprocess = calloc(n, sizeof(int));

  for (int i = 0; i < n; i += 1)
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
    int num1 = string_to_int(line1);
    int num2 = string_to_int(line2);
    int sum = num1 + num2;
    preprocess[i] = sum;
  }
  for (int i = 0; i < n; i += 1)
  {
    int_to_string(preprocess[i]);
  }
  free(preprocess);
}
