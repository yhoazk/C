# C Stuff


## Special Macros

`__LINE__`
`__COUNTER__`

```C
    printf("__LINE__ Macro %d\n", __LINE__);
    printf("__COUNTER__ Macro %d\n", __COUNTER__);
    printf("__COUNTER__ Macro %d\n", __COUNTER__);
    printf("__COUNTER__ Macro %d\n", __COUNTER__)
```
Gives
```
__LINE__ Macro 45
__COUNTER__ Macro 0
__COUNTER__ Macro 1
__COUNTER__ Macro 2
```
## Variadic Macros

Stringize the macro input argument with `#`, this adds quotes to the input argument.
```C
#define stringize(x) #x
 stringize(fff)
```
Produces:
```
 "fff"
```

## Concatenate Macro




## Change the entry point of an application:

When, for some reason, the entry point function has to be renamed,
the linker is responsible to assign the entry point. For example:

```c
#include <stdio.h>

int entry()
{
  return 0;
}
```

And the compile/link command is now:

```
gcc -o entry.exe entry.c -Wl, -eentry -nostartfiles
```

The `-Wl,-eentry` passes arguments to the linker, and the linker takes
a `-e` argument to set the entry function.

The command `-nostrartfiles` omits the `ctr*.o` files containing `_start`
but stills allows to use a libc.


Another way to acomplish this is to use the `binutils`, this provides the 
command `objcopy` to make an arbitrary function the new entry point.

This requires a relocatable compilation, which is done with the gcc flag
`-c`

This way:
```
gcc -c program.c -o program.exe
```

Then redefine the the entry to be main:

```
objcopy --redefine-sym entry=main program.o
```
Now use gcc to compile the new object file:

```
gcc program.o -o program
```

If the program already has a function called `main`, performa a separated
`objcopy` invocation:

```
objcopy --redefine-sym oldmain=main program.o
```

