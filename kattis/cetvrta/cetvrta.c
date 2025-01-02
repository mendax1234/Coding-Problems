#include <stdio.h>

int find_x(int n, int x[3])
{
  int count1 = 1;
  int count2 = 0;
  long index = 0;
  for (int i = 1; i <= 2; i += 1)
  {
    if (x[i] == x[0])
    {
      count1 += 1;
    }
    else
    {
      count2 += 1;
      index = i;
    }
  }
  if (count1 > count2)
  {
    return x[index];
  }
  else
  {
    return x[0];
  }
}

int find_y(int n, int y[3])
{
  int count1 = 1;
  int count2 = 0;
  long index = 0;
  for (int i = 1; i <= 2; i += 1)
  {
    if (y[i] == y[0])
    {
      count1 += 1;
    }
    else
    {
      count2 += 1;
      index = i;
    }
  }
  if (count1 > count2)
  {
    return y[index];
  }
  else
  {
    return y[0];
  }
}

int main()
{
  int x[3] = { 0 };
  int y[3] = { 0 };
  for (int i = 0; i < 3; i += 1)
  {
    scanf("%d %d", &x[i], &y[i]);
  }
  printf("%d %d\n", find_x(3, x), find_y(3, y));
}

