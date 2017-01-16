#include <stdio.h> 
/*
 * POC
 * This is a test program to demostrate the evaluation of the 
 * input arguments, the most common case is that the arguments
 * are evaluated from left to rigth, so in this case the output
 * is:
 * 7 6 5
 * Also this is not specified by C std, then it depends on the 
 * compiler.
 * By enabling all the warnings gcc warns about this undesired
 * behaviour.
 * warning: operation on 'i' may be undefined [-Wsequence-point]
 * */
int main()
{
    int i = 5;
    printf("\n%d %d %d\n", i++, i++, i++);
    // prints 7,6,5
    return 0;
}
