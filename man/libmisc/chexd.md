‎
=

## chexd - *hexadecimal dump compressor*

*any sequence of 2 or more '0's is swapped for a representative char, often significantly reducing dump size*

------------------------------------------------------------------



**example:**

    command: print -n '000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000' | chexd

    output: !{


**flags:**

    zCHEXDWAITINDEF - set to a non-(empty || zero) value to disable stdin read timeout (default is 33 seconds)

------------------------------------------------------------------
*takes input only from stdin*
