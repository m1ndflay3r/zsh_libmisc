‎
=

## busybox - *the classic multi-call binary (https://busybox.net/, v1.36.0, x86_64 + armv7h) - in a zsh library!*

*busybox v1.36.0 contained in a zelfexec-powered zsh script*

--------------------------------------------------------------------------
**enabling:**

    step 1 - copy busybox module from folder "zsh/extra" to "zsh/comp"

    step 2 - add line "autoload busybox" to zsh/comp/libmiscinit, at beginning of autoload section

    step 3 - recompile libmisc with either "./build --dynamic" or "./build --static"

**example:**

    command: busybox --version

    output: BusyBox v1.36.0 (2023-01-04 09:56:28 UTC) multi-call binary.


**flags:**

    zbusyboxWAITINDEF - set to a non-(zero || empty) value to disable timeout on read from stdin (default timeout 1 second)

