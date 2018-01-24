# Creating namespaces in C

For completeness there are several ways to achieve the "benefits" you might get from namespaces, in C.

One of those methods is using a structure to house a bunch of method pointers which are the interface to your library/etc..

You then use an extern instance of this structure which you initialize inside 
your library pointing to all your functions. 
This allows you to keep your names simple in your library without stepping on
the clients namespace (other than the extern variable at global scope, 1 
variable vs possibly hundreds of methods..)

There is some additional maintenance involved but it is minimal.

--- 
