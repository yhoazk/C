/* Common spinner and progress bar utilities */
#include <stdio.h>
#include <unistd.h>

void spinner()
{
  static int step;

  if(step < 3)
  {
    step++;
  } 
  else
  {
    step = 0;
  }

  printf("\b");
  switch(step)
  {
    case 0:
      printf("-");
      break;
    case 1:
      printf("/");
      break;
    case 2:
      printf("|");
      break;
    default:
      printf("\\");
      break;
  }
  fflush(stdout); // could be fd=1 used here?
}


void progress_bar()
{
  static int pos = 0;

  for(int i=0; i<106; ++i)
  {
    printf("\b");
  }

  printf("[");

  for(int i=0; i<100;++i)
  {
    if(i < pos)
    {
      printf("#");
    }else{
      printf(" ");
    }
  }
  printf("] %d%%", pos);
  fflush(stdout);
  ++pos;

}

int main()
{
  /* Hide the cursor */
  fputs("\e[?25l", stdout);
  printf("calculating: ");
  unsigned k = 20;
  while(k > 0)
  {
    spinner();
    usleep(200 * 1000);
    --k;
  }
  k = 100;
  for(int i=0;i<=100; ++i)
  {
    progress_bar();
    usleep(100 * 1000);
  }
  printf("\n");
  /* Restore the cursor */
  fputs("\e[?25h", stdout);
  return 0;
}
