# zsh_libmisc
Some very powerful library functions for zsh.


This is a collection of various utilities and functions packed into a one, neat little zsh library.


# zelfexec
Arguably the star of the show, zelfexec is a much more powerful implementation of elfexec by abbat (https://github.com/abbat/elfexec)


Written in a mixture of both C and pure zsh, this program is capable of executing any ELF binary piped to it without ever actually writing it to a filesystem of any kind.


differences to abbats' version: 

- arg1 is no longer treated as a filepath for an executable instead of an argument (because why would it be when we can just run ./path/to/binary
