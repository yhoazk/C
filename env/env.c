/* Program to print the environment variables in which the program is
 * being run
 * */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  /* The getenv functions receives a string and returns a pointer to
   * the buffer where the values of that variable is described as str
   * */
  printf("Print the editor envvar\n");
  char *myenvvar = getenv("PATH");
  if(NULL != myenvvar)
  {
    printf("The PATH env var is set to:\n %s\n", myenvvar);
  }
  else
  {

  }
  return 0;
}
