cb64ud - base64 dump decompressor

reverses cb64d, swapping representitive chars with original A (0) values


takes input only from stdin


example:

  command: fox-ec '?>)' | cb64ud

  output: AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA


flags:

  zCB64UDWAITINDEF - set to a non-(empty || zero) value to disable stdin read timeout (default is 33 seconds)


note: can be piped to b64ud for one-shot reversal of compressed b64 dumps into the original binary data (ex "fox-ec '?>)' | cb64ud | b64ud")
