#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  unsigned int roll_counter;
  unsigned int period = 5000;

  while (1) {
    if(0 == (roll_counter++ % period))
    {
      printf("Done\n" );
      sleep(1);
    }
    printf("." );

  }
  return 0;
}
