‎
=

## **zelfexec** - A highly versatile *elfexec* implementation, written in a mixture of C and zsh.
  
*Inspired by abbats' elfexec (https://github.com/abbat/elfexec - used for reference only, all code original)*

----------------------------------------------------------------------------------

**execute ELF binaries piped to stdin without writing them to disk.**



  Primary differences to abbat's *elfexec* implementation:
  
  - it's in a zsh library!
    
  - stdin of the child process can be handled separately from stdin of zelfexec ( via env var *zSTDIN* )
    
  - arg0 can be spoofed ( via env var *zELFSPOOF* )
    
  - arg1 is always treated as a child-process argument and never as a file to be executed
    
  - fallback mode (omnibin)
    


**examples:**

  *basic use:*

    command: fox-fr /path/to/busybox | zelfexec whoami

    output: $USER


  *arg0 spoofing:*

    command: fox-fr /path/to/busybox | zELFSPOOF="whoami" zelfexec

    output: $USER


  *child-process stdin handling:*

    command: fox-fr /path/to/busybox | zSTDIN="some text" zelfexec cat

    output: "some text"

-------------------------------------------------------------------------------------------------

  *flags:*

    zELFWAITINDEF - set to a non-(zero || empty) value to wait indefinitely for stdin pipe (default is 33 seconds)

    zWAITFORSTDIN - set to a non-empty value to wait for a second stdin pipe, to use for stdin of the new process

-------------------------------------------------------------------------------------------------
  *requires linux > 3.17, and fexecve to be enabled and usable.*

  *fallback mode requires read, write, and execute permissions in either /tmp or $HOME*
