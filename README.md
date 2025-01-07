‎
=
# zsh_libmisc (WIP)
A collection of various utilities and functions packed into a single, unified **zsh** library.


This library is essentially my own stdlib for ZSH, and comes packed with a variety of useful features which aim to extend the capability and scope of ZSH as a programming language.

Honestly, it's become so useful that I rarely write anything in ZSH without it anymore!

To use libmisc, run the included build script like so:

    ./build  
    
or

    ./build --static
    
    
This will generate *libmisc.zwc* in the root of the source directory. Afterwards, add the following to your *.zshrc* :

    fpath=(/path/to/source/directory/libmisc.zwc $fpath)
    autoload libmiscinit
    libmiscinit


Once done, every subsequent zsh session will have the functions of libmisc available.



--------------------------------------------------------------------------------------------
*Full documentation, including documentation on each individual feature of libmisc, is included in the **man** directory.*



--------------------------------------------------------------------------------------------

### - latest feature -

    == 2d_arr      : 2d array (grid) support for zsh



--------------------------------------------------------------------------------------------



‎
=
## -    features    -
Below is a basic summary of the features and components of libmisc:

### utilities

    == libmiscinit : initialization tasks for libmisc
    == zelfexec    : "elfexec" implementation
     |-- omnibin       : fallback mode for zelfexec
    == 2d_arr      : 2d array (grid) support for ZSH
    == zterm       : tmux-like <zsh/zpty> wrapper, including attach / detach functionality
    == hexd        : lightweight hex dumper
     |-- hexdlf        : hexd, with large (infinite) filesize handling
     |-- chexd         : deflation-based hex dump compressor
       |-- chexdlf         : chexd, with large (infinite) filesize handling
    == hexud       : lightweight hex dump reversal
     |-- hexudlf       : hexud, with large (infinite) filesize handling
     |-- chexud        : reversal of compressed hex dumps created with chexd
       |-- chexudlf        : chexud, with large (infinite) filesize handling
    == b64d        : minimal base64 dumper
     |-- cb64d         : deflation-based base64 dump compressor
    == b64ud       : minimal base64 dump reversal
     |-- cb64ud        : reversal of compressed base64 dumps created with cb64d
     |-- load64        : b64ud into a random-named variable, print variable name
    == filesize    : filesize info in binary, octal, decimal, or hexadecimal formats
    == fox         : "cat" implementation (stdin)
     |-- fox-fr        : "cat" implementation (fileread)
     |-- fox-ec        : "cat" implementation (args)
     |-- zzcat         : "cat" implementation (pure zsh version)
    == ztput       : "tput" implementation
     |-- ctext         : user-friendly ztput wrapper
    == zdate       : "date" implementation
    == zfile       : "file" implementation
    == ztat        : "stat" implementation
    == zrm         : "rm" implementation
    == zrmdir      : "rmdir" implementation
    == zmv         : "mv" implementation
    == zcp         : "cp -r" implementation
    == zmkdir      : "mkdir" implementation
    == zmkfifo     : "mkfifo" implementation
    == zchgrp      : "chgrp" implementation
    == zchown      : "chown" implementation
    == zchmod      : "chmod" implementation
    == zls         : "ls" implementation
    == zln         : "ln" implementation
    == zwhich      : "which" implementation
    == zsudo       : "sudo" implementation (wip)
    == blep        : "grep" implementation (wip)
    
### QOL, pet-peeves, fringe-case workarounds, toys, and other oddities
    
    == trandom     : generate random ASCII string
    == nrandom     : consistently-behaving version of "echo $RANDOM"
    == zbinfmt     : register an interpreter by file extension
    == revstr      : output given input string, backwards
    == hexec       : execute hex dump directly without writing new files
    == getstrln    : returns length of input string
    == isyes       : easy handling of simple Y/n input prompts
    == nullbyte    : print N number of null bytes (default 1)
    == chkvldint   : return 0 if input is a valid integer, or 1 if not
    == isevennum   : return 0 if input is even integer, 1 if not
    == isfile      : return 0 if anything of any type exists at given filepath
    == zreadin     : *fox* wrapper that times out after 3 seconds
    == arrmatch    : lazy array matching
    == clocky      : fun rainbow clock printout, for use with zsh prompt
    == nclocky     : clocky, but without the rainbow colours
    == zzsh        : wrapper for zsh-static-5.8 intended to bypass the backspace issues with zle (wip)

### extra
    == busybox     : the classic multi-call binary (https://busybox.net, v1.36.0, x86_64 + armv7h) - in a zsh library!
--------------------------------------------------------------------------------------------

*this feature list is very incomplete, and will have significant additions and changes as development of libmisc progresses*

‎
=
# -    zelfexec    -
Arguably the star of the show (which is why it gets its own section in README.md), **zelfexec** is an *almost-too-useful* piece of software inspired by abbats' *elfexec* ( https://github.com/abbat/elfexec *- used for reference only, all code original* )


Written in a mixture of both C and pure zsh, this software is capable of executing any ELF binary piped to it without ever actually writing it to a filesystem of any kind. A number of libmisc's functions and utilities wouldn't be possible if they didn't depend on zelfexec for their operation.



Differences to abbats' version:


- it's in a zsh library!


- arg1 isn't treated as a filepath for an executable (run *<fileread> /path/to/file | zelfexec* if you really need this)


- stdin of the child process can be handled separately from stdin of zelfexec ( via the environment variable *zSTDIN* )


- arg0 can be spoofed ( via the environment variable *zELFSPOOF* )


- the existence of a fallback mode (omnibin)


- probably more I'm forgetting

‎
=


**Examples**:

--------------------------------------------------------------------------------------------

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
*normal operation requires linux > 3.17, and fexecve to be enabled and usable.*


*fallback mode requires read, write, and execute permissions within either /tmp or $HOME*
