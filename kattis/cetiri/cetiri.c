#include <stdio.h>

void swap(int a[], int tar, int src)
{
  int temp = a[tar];
  a[tar] = a[src];
  a[src] = temp;
}

void bubble_pass(int last, int a[])
{
  for (int i = 0; i < last; i += 1)
  {
    if (a[i] > a[i+1])
    {
      swap(a, i, i+1);
    }
  }
}

void bubble_sort(int n, int a[n])
{
  for (int last = n - 1; last > 0; last -= 1)
  {
    bubble_pass(last, a);
  }
}

int find_missing(int n, int a[n])
{
  int first_diff = a[1] - a[0];
  int last_diff = a[2] - a[1];
  if (first_diff == last_diff)
  {
    return a[2] + last_diff;
  }
  if (first_diff > last_diff)
  {
    return a[1] - last_diff;
  }
  return a[1] + first_diff;
}

int main()
{
  int a[3] = { 0 };
  for (int i = 0; i < 3; i += 1)
  {
    scanf("%d", &a[i]);
  }
  bubble_sort(3, a);
  int missing = find_missing(3, a);
  printf("%d\n", missing);
}

