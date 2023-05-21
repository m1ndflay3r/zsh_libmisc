‎
=

hexdlf - a basic hexadecimal dumper (with large file handling)


input is taken in 1 of 4 forms: 

  hexdlf /path/to/file
  hexdlf "string"
  print -n "string" | hexdlf
  print -n "file:/path/to/file" | hexdlf


flags:

  zHEXDLFWAITINDEF - set to a non-(zero || empty) value to disable timeout on read from stdin (default timeout 3 sec)
  zHEXXD - set to a non-(zero || empty) value to format output in style of xxd -p
  zHEXDSH - set to a non-(zero || empty) value to format output in shell syntax (\x00\x00...)


