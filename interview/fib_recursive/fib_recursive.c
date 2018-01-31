#include <stdio.h>

size_t fib_recursive(size_t k)
{
  if (k < 2) {
    return 1;
  }
  return fib_recursive(k-1) + fib_recursive(k-2);
}

int main(int argc, char const *argv[]) {
  size_t k;
  scanf("%i", &k);
  for (size_t i = 0; i < 12; i++) {
    printf("%i\n",fib_recursive(i));

  }
  printf("Gives the n number of the fibonacci sequence\n", );
  printf("%i\n",fib_recursive(k));
  return 0;
}
