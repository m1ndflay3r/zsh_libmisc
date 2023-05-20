hexudlf - hexadecimal dump reversal (with large file handling)


input is taken in 1 of 4 forms: 

  hexudlf /path/to/file
  hexudlf "string"
  print -n "string" | hexudlf
  print -n "file:/path/to/file" | hexudlf


flags:

  zHEXUDLFWAITINDEF - set to a non-(zero || empty) value to disable timeout on read from stdin (default timeout 3 sec)


