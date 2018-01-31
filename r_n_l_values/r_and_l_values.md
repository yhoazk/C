# [`lvalues` and `rvalues`](https://eli.thegreenplace.net/2011/12/15/understanding-lvalues-and-rvalues-in-c-and-c)

## Simple definition:

**`lvalue`**: Represents an object that occupies some identifiable location in
memory (i.e. has an address).

**`rvalues`**: Are defined by exclusion, by saying that either an expression is
`lvalue` or `rvalue`. Then an `rvalue` is an expression that does NOT represents
an object occupying some identifiable memory location.
