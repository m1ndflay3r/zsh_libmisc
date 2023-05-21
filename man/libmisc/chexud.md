‎
=

## chexud - *compressed hexadecimal dump reversal*

*swaps representative chars from chexd for their 0 values, and outputs the original hexdump*

----------------------------------------------------------------------------------------



**example:**

    command: fox-ec '!{' | chexud

    output: 000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000


**flags:**

    zCHEXUDWAITINDEF - set to a non-(empty || zero) value to disable stdin read timeout (default is 33 seconds)

--------------------------------------------------------------------------------------

*can be piped to hexud for one-shot reversal of compressed hexdumps into the original binary data (ex: fox-ec '!{' | chexud | hexud)*

*takes input only from stdin*
