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
