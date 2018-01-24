/* interface.h */
#include <stdio.h>
struct library {
    const int some_value;
    void (*function1)(void);
    void (*method2)(int);
    void (*method1)(int);
    /* ... */
};

extern const struct library Library;
/* interface.h */
