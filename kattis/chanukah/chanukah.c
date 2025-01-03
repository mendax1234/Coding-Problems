#include <stdio.h>

int calc_num_candles(int days)
{
  int sum = 0;
  for (int i = 0; i < days; i += 1)
  {
    sum += i + 2;
  }
  return sum;
}

int main()
{
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i += 1)
  {
    int ds_num;
    int days;
    scanf("%d %d", &ds_num, &days);
    int candles = calc_num_candles(days);
    printf("%d %d\n", ds_num, candles);
  }
}
