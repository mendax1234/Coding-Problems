#include <stdio.h>

int main()
{
  int n;
  scanf("%d\n", &n);
  for (int i = 0; i < n; i += 1)
  {
    double ans = 0;
    int temp;
    scanf("%d\n", &temp);
    for (int k = 0; k < temp; k += 1)
    {
      ans += 0.5;
      ans *= 2;
    }
    printf("%d\n", (int)ans);
  }
}
