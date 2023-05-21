‎
=

## omnibin - *fallback mode for zelfexec*

*A simple script that writes binary data piped to stdin to /tmp, handles the arguments of zelfexec, hands them to the new binary, then deletes it after execution.*

-------------------------------------------------------------

This particular module is not meant to be invoked manually - rather, you should simply call zelfexec and it will determine whether to use fallback mode on its own.

-------------------------------------------------------------

*there is no benefit to calling omnibin directly, and doing so may result in unpredictable behavior.*
