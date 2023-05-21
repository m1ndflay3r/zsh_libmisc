‎
=

## chexudlf - *compressed hexadecimal dump reversal (with large file handling)*

*swaps representative chars from chexd or chexdlf for their 0 values, and outputs the original hexdump*

------------------------------------------------------------------------------------


**example:**

    command: fox-ec '!{' | chexudlf

    output: 000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000


**flags:**

    zCHEXUDLFWAITINDEF - set to a non-(empty || zero) value to disable stdin read timeout (default is 3 seconds)

-------------------------------------------------------------------------

*can be piped to hexudlf for one-shot reversal of compressed hexdumps into the original binary data (ex: fox-ec '!{' | chexudlf | hexudlf)*

*takes input only from stdin*
