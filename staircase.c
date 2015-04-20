#include <stdio.h>

int main(){
  int n;
  scanf("%d\n", &n);
  int array[100];
  int j;
  for (j=0; j<n; j++) {
    scanf("%d\n", &array[j]);
  }
  int sum = 0;
  int i;
  for (i=0; i<n-2;) {
    if (array[i]  < array[i+1]) {
      sum += array[i];
      i += 1;      
    }
    if (array[i]  > array[i+1]) {
      sum += array[i + 1];
      i += 2;      
    }
  }
  printf("%d\n", sum);
  return 0;
}
