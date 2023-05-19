cb64d - base64 dump compressor

any sequence of 2 or more 'A's (0) is swapped for a representative char, often significantly reducing dump size


takes input only from stdin


example:

  command: print -n 'AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA' | cb64d

  output: ?>)


flags:

  zCB64DWAITINDEF - set to a non-(empty || zero) value to disable stdin read timeout (default is 33 seconds)
