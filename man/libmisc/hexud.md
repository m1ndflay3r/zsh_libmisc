‎
=

## hexud - *hexadecimal dump reversal*

-------------------------------------------------------------------

**examples:**

    hexud /path/to/file
    hexud "string"
    print -n "string" | hexud
    print -n "file:/path/to/file" | hexud

**flags:**

    zHEXUDWAITINDEF - set to a non-(zero || empty) value to disable timeout on read from stdin (default timeout 3 sec)
