‎
=

## blep - *grep implementation*

*currently just handles basic grep stdin pattern match use cases (with highlighting support)*

--------------------------------------------------------------------


**example:**

    fox-fr /path/to/file | blep "foo"


**flags:**

    zBLEPWAITINDEF - set to a non-(zero || empty) value to disable stdin read timeout (default is 3 seconds)

    zBLEPNOHIGHLIGHT - disable highlighting of input pattern in matched strings

---------------------------------------------------------------------
*work-in-progress*
