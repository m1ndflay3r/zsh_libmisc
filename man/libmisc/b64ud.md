‎
=

## b64ud - *simple base64 dump reverser.*

*takes base64 values as input, and outputs binary data*

---------------------------------------------------------------------

**examples:**

    b64ud /path/to/file
    b64ud "string"
    print -n "string" | b64ud
    print -n "file:/path/to/file" | b64ud


**flags:**

    zB64UDWAITINDEF - set to a non-(zero || empty) value to disable timeout on read from stdin (default timeout 6 sec)

--------------------------------------------------------------------

*utilizes zelfexec*
