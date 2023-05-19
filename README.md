# zsh_libmisc
This is a collection of various utilities and functions packed into a one, neat little zsh library.


This library is 100% self sufficient, and could theoretically operate with nothing but a linux kernel and static zsh.


--------------------------------------------------------------------------------------------------------------------------------


## zelfexec
Arguably the star of the show, zelfexec is a much more powerful implementation of abbats' elfexec (https://github.com/abbat/elfexec).


Written in a mixture of both C and pure zsh, this software is capable of executing any ELF binary piped to it without ever actually writing it to a filesystem of any kind. As you can imagine, this functionality is hilariously powerful. Many of libmisc's functions and utilities utilize this in their operation.



Differences to abbats' version: 


- it's in a zsh library!


- arg1 is no longer treated as a filepath for an executable instead of an argument (because why would it be when we can just run ./path/to/binary or even use cat (or the libmisc builtin fox-fr) like so: fox-fr /path/to/binary | zelfexec)


- stdin of the child process can be handled separately from stdin of zelfexec (via the environment variable zSTDIN)


- arg0 can be spoofed (via the environment variable zELFSPOOF)


- some misc. fixes for fringe use cases

‎
=
**Examples**:


  basic use:

    command: fox-fr /path/to/busybox | zelfexec whoami

    output: $USER


  arg0 spoofing:

    command: fox-fr /path/to/busybox | zELFSPOOF="whoami" zelfexec

    output: $USER


  child-process stdin handling:

    command: fox-fr /path/to/busybox | zSTDIN="some text" zelfexec cat

    output: "some text"

‎
=
*requires linux > 3.17, and fexecve to be enabled and usable*
