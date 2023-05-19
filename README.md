# zsh_libmisc
This is a collection of various utilities and functions packed into a one, neat little zsh library.


This library is 100% self sufficient, and could theoretically operate with nothing but a linux kernel and static zsh.


--------------------------------------------------------------------------------------------------------------------------------


# zelfexec
Arguably the star of the show, zelfexec is a much more powerful implementation of elfexec (https://github.com/abbat/elfexec).


Written in a mixture of both C and pure zsh, this program is capable of executing any ELF binary piped to it without ever actually writing it to a filesystem of any kind. Many of libmisc's functions utilize this in their operation.



differences to abbats' version: 


- arg1 is no longer treated as a filepath for an executable instead of an argument (because why would it be when we can just run ./path/to/binary


- stdin of the child process can be handled separately from stdin of zelfexec (via the environment variable zSTDIN)


- arg0 can be spoofed (via the environment variable zELFSPOOF)



