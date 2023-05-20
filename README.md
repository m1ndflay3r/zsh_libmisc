‎
=
# zsh_libmisc (WIP)
A collection of various utilities and functions packed into one, neat little zsh library.


This library is intended to be 100% self-sufficient, and should theoretically operate with nothing but a linux kernel and static zsh.


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



‎
=
## -    features    -
Below is a basic summary of the features and components of libmisc:

### utilities

    == libmiscinit : initialization tasks for libmisc
    == zelfexec    : powerful elfexec implementation
     |-- omnibin       : fallback mode for zelfexec
    == hexd        : lightweight hex dumper, with some extra features
     |-- hexdlf        : hexd, with large (infinite) filesize handling
     |-- chexd         : simple deflation-based hex dump compressor
       |-- chexdlf         : chexd, with large (infinite) filesize handling
    == hexud       : lightweight hex dump reversal, with some extra features
     |-- hexudlf       : hexud, with large (infinite) filesize handling
     |-- chexud        : reversal of compressed hex dumps created with chexd
       |-- chexudlf        : chexud, with large (infinite) filesize handling
    == b64d        : simple base64 dumper, with minimal extra features
     |-- cb64d         : simple deflation-based base64 dump compressor
    == b64ud       : simple base64 dump reveral, with minimal extra features
     |-- cb64ud        : reversal of compressed base64 dumps created with cb64d
     |-- load64        : reverse a b64 dump, store resulting binary in random variable, print variable name
    == fox         : minimal *cat* implementation (stdin)
     |-- fox-fr        : minimal *cat* implementation (fileread)
     |-- fox-ec        : minimal *cat* implementation (args)
     |-- zzcat         : minimal *cat* implementation (pure zsh version)
    == trandom     : generate a random ASCII string
    == revstr      : outputs input string, backwards
    == filesize    : precise file size info in bin, oct, dec, or hex format
    == zbinfmt     : register an interpreter by file extension
    == ztput       : minimal *tput* implementation
    == ctext       : user-friendly ztput wrapper
    == zfile       : lightweight implementation of "file", in pure zsh
    == ztat        : minimal *stat* implementation
    == zrm         : file deletion
    == zrmdir      : folder deletion
    == zmv         : minimal mv clone
    == zcp         : minimal cp -r clone
    == zmkdir      : minimal mkdir clone
    == zmkfifo     : minimal mkfifo clone, with some minor tweaks
    == zchgrp      : minimal chgrp clone
    == zchown      : minimal chown clone
    == zchmod      : minimal chmod clone
    == nullbyte    : print N number of null bytes (default 1)
    == zls         : ls -a clone (wip)
    == zsudo       : sudo implementation (wip)
    == blep        : grep implementation (wip)
    
### pet-peeves, fringe-case workarounds, and other oddities
    
    == nrandom     : a consistently-behaving version of "echo $RANDOM"
    == arrmatch    : lazy array matching
    == isfile      : return 0 if anything whatsoever exists at given filepath
    == chkvldint   : return 0 if input is valid int, or 1 if not
    == getstrln    : returns length of input string
    == isevennum   : return 0 if input is even integer, 1 if not
    == isyes       : for easy handling of simple Y/n input prompts
    == zreadin     : wrapper for *fox* that times out after 3 seconds 
    == zzsh        : simple wrapper for zsh-static-5.8 that bypasses the backspace issues with zle (wip)
--------------------------------------------------------------------------------------------
‎
=
# -    zelfexec    -
Arguably the star of the show (which is why it gets its own section in README.md), zelfexec is an *almost-too-useful* and *highly-versatile* implementation of elfexec by abbat ( https://github.com/abbat/elfexec - *used for reference only, all code original* )


Written in a mixture of both C and pure zsh, this software is capable of executing any ELF binary piped to it without ever actually writing it to a filesystem of any kind. As you can imagine, this functionality is *hilariously* powerful. A number of libmisc's functions and utilities wouldn't be possible if they didn't depend on zelfexec for their operation.



Differences to abbats' version: 


- it's in a zsh library!


- arg1 is no longer treated as a filepath for an executable instead of an argument ( because why would it be when we can just run *./path/to/binary* or *fileread /path/to/file | zelfexec* )


- stdin of the child process can be handled separately from stdin of zelfexec ( via the environment variable *zSTDIN* )


- arg0 can be spoofed ( via the environment variable *zELFSPOOF* )


- misc. fixes and tweaks to account for fringe use-cases


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
