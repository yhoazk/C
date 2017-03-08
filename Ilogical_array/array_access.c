#include <stdio.h>

int main()
{
    int i;
    int foo[] = { 3, 38, 38, 0, 19, 21, 3, 11, 19, 42 };
    char bar[] = " abcdefghijklmnopqrstuvwxyz01234567890+-,.!?-_";
    /*
     * In simplistic terms, the access of an array element in C (and in C++, when [] isn't overloaded) is as follows:

    x[i] = *(x + i)
    So, with this and a little bit of arithmetic...
    
      foo[i][bar]
    = (foo[i])[bar]
    = (*(foo + i))[bar]
    = *((*(foo + i)) + bar)
    = *(bar + (*(foo + i)))
    = bar[*(foo + i)]
    = bar[foo[i]]
    Don't use this "fact" though. As you've seen, it makes the code unreadable, and unreadable code is unmaintainable.
     *  
     * */
    for (i = 0; i < 10; ++i) 
    {
      printf("%d\n",  foo[i][bar]);

    }

    printf("Other ilogical access\n");
    /*
     * The C standard defines the [] operator as follows:

    a[b] == *(a + b)
    
    Therefore a[5] will evaluate to:
    
    *(a + 5)
    and 5[a] will evaluate to:
    
    *(5 + a)
    a is a pointer to the first element of the array. a[5] is the value that's 5 elements further from a
    , which is the same as *(a + 5), and from elementary school math we know those are equal (addition is commutative).
     * */

    printf("%c\n", 5[bar]);
    printf("%c\n", bar[5]);
    return 0;
}
