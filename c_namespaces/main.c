/* client code */
#include "interface.h"

int main(void)
{
    /* Here the advantaje is that we only have a Library variable and
     * all its functions and values are linked to it. Otherwise we'll
     * have a buch of function names that might collide with clients
     * code names. */
    Library.method1(3);
    Library.method2(5);
    printf("%d\n", Library.some_value);
    return 0;
}
/* end */
