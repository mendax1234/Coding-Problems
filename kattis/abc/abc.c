#include <stdio.h>

long find_min(long a, long b, long c)
{
  long min = a;
  if (b < min)
  {
    min = b;
  }
  if (c < min)
  {
    min = c;
  }
  return min;
}

long find_max(long a, long b, long c)
{
  long max = a;
  if (b > max)
  {
    max = b;
  }
  if (c > max)
  {
    max = c;
  }
  return max;
}

long find_mid(long a, long b, long c, long min, long max)
{
  if (a != min && a != max)
  {
    return a;
  }
  if (b != min && b != max)
  {
    return b;
  }
  if (c != min && c != max)
  {
    return c;
  }
}

int main()
{
  long temp1, temp2, temp3;
  scanf("%ld %ld %ld", &temp1, &temp2, &temp3);
  long a = find_min(temp1, temp2, temp3);
  long c = find_max(temp1, temp2, temp3);
  long b = find_mid(temp1, temp2, temp3, a, c);
  long sorted[3] = {a, b, c};
  char index1, index2, index3;
  scanf("\n%c%c%c", &index1, &index2, &index3);
  printf("%ld ", sorted[index1-'A']);
  printf("%ld ", sorted[index2-'A']);
  printf("%ld\n", sorted[index3-'A']);
}

