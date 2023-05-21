‎
=

## hexec - *execute hex dump directly without writing new files*

-------------------------------------------------

**examples:**

    print -rn "<hexdump>" | hexec
    hexec /path/to/hexdump
    hexec "<hexdump>"

**flags:**

    zHEXECWAITINDEF - set to a non-(zero || empty) value to disable timeout of read from stdin (default is 3 seconds)
