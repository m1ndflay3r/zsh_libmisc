‎
=

fox - cat implementation (stdin read)

Pretty self-explanatory. Anything given to stdin is repeated on stdout.


example:

  command: fox <<EOF
some data
EOF

  output: some data


flags:

  zFOXT - set a timeout value rather than hanging indefinitely on null stdin (ex: zFOXT=3 fox <<...)
