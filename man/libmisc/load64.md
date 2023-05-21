‎
=

## load64 - *load (undump) base64 dump into random variable and return variable name*

-----------------------------------------------------------------------------

**example:**

    print -n "<base64 dump>" | load64

    output: CqyHzponH

**flags:**

    zLOAD64WAITINDEF - set to a non-(zero || empty) value to disable timeout of read from stdin (default is 33 seconds)

------------------------------------------------------------------------------

*takes input only from stdin*
