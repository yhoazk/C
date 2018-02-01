/* interface.c */
#include "interface.h"

void method1(int x)
{
    printf("method1\n");   
}
void method2(int arg)
{
   printf("method1\n");   
}
/* initialize the struct with the . initializer, this method can be also used as in Verilog for modules. */
const struct library Library = {
    .method1 = method1,
    .method2 = method2,
    .some_value = 36
};
/* end interface.c */

