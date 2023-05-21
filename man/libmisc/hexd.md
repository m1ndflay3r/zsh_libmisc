‎
=

## hexd - *leightweight hexadecimal dumper*

-------------------------------------------

**Examples:**

    hexd /path/to/file
    hexd "string"
    print -n "string" | hexd
    print -n "file:/path/to/file" | hexd


**flags:**

    zHEXDWAITINDEF - set to a non-(zero || empty) value to disable timeout on read from stdin (default timeout 33 sec)
    zHEXXD - set to a non-(zero || empty) value to format output in style of xxd -p
    zHEXDSH - set to a non-(zero || empty) value to format output in shell syntax (\x00\x00...)
