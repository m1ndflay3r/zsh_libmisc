hexec - execute hexdump directly without writing new files


takes input in 1 of 3 forms: 

print -rn "<hexdump>" | hexec
hexec /path/to/hexdump
hexec "<hexdump>"


flags:

  zHEXECWAITINDEF - set to a non-(zero || empty) value to disable timeout of read from stdin (default is 3 seconds)
