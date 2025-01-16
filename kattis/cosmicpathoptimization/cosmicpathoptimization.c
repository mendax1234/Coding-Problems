#include <stdio.h>

int main() {
  int n = 0;
  scanf("%d", &n);
  
  int sum = 0;
  for (int i = 0; i < n; i += 1)
  {
    int t = 0;
    scanf("%d", &t);
    sum += t;
  }

  printf("%d\n", sum / n);
}
