#include <stdio.h>

#define MAX 1001

int main() {
  int n;
  scanf("%d", &n);

  int hi = MAX;
  int lo = 0;
  for (int i = 0; i < n; i += 1)
  {
    int l;
    int h;
    scanf("%d %d", &l, &h);
    hi = hi > h ? h : hi;
    lo = lo < l ? l : lo;
  }

  if (lo > hi)
  {
    printf("edward is right\n");
  }
  else
  {
    printf("gunilla has a point\n");
  }
}
