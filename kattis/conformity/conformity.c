#include <stdio.h>
#include <stdlib.h>

void swap(int a[], int pos1, int pos2)
{
  int temp = a[pos1];
  a[pos1] = a[pos2];
  a[pos2] = temp;
}

void bubble_pass(int last, int a[]) {
  for (int i = 0; i < last; i += 1) {
    if (a[i] > a[i+1]) {
      swap(a, i, i+1);
    }
  }
}

void bubble_sort(int n, int a[n]) {
  for (int last = n - 1; last > 0; last -= 1) {
    bubble_pass(last, a);
  }
}

int main(void)
{
  int n;
  scanf("%d", &n);

  int **input = calloc(n, sizeof(int *));
  for (int i = 0; i < n; i += 1)
  {
    input[i] = calloc(5, sizeof(int));
  }

  for (int i = 0; i < n; i += 1)
  {
    for (int j = 0; j < 5; j += 1)
    {
      scanf("%d", &input[i][j]);
    }
  }

  for (int i = 0; i < n; i += 1)
  {
    bubble_sort(5, input[i]);
  }
  
  int pop = n;
  for (int i = 0; i < 5; i += 1)
  {
    int num_diff = 0;
    if (pop == 1)
    {
      pop = n;
      break;
    }
    for (int j = 1; j < n; j += 1)
    {
      if (input[j][i] != input[0][i])
      {
        num_diff += 1;
      }
    }
    pop -= num_diff;
  }
  
  printf("%d\n", pop);
}
