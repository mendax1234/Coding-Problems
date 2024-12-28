#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_open(char c)
{
  return c == '(' || c == '{' || c == '[';
}

bool is_matching_close(char c, char d)
{
  return (c == '[' && d == ']') ||
    (c == '{' && d == '}') ||
    (c == '(' && d == ')');
}

int consume_valid(char *string, int begin)
{
  if (string[begin] == 0)
  {
    return begin;
  }
  if (!is_open(string[begin]))
  {
    return begin;
  }

  int end = consume_valid(string, begin + 1);
  if (is_matching_close(string[begin], string[end]))
  {
    return consume_valid(string, end + 1);
  }
  return begin;
}

int main()
{
  int n;
  scanf("%d\n", &n);
  char *str = calloc(n + 1, sizeof(char));
  for (int i = 0; i < n; i += 1)
  {
    str[i] = getchar();
  }
  int end = consume_valid(str, 0);
  if (str[end] == 0)
  {
    printf("Valid\n");
  }
  else
  {
    printf("Invalid\n");
  }
  free(str);
}

