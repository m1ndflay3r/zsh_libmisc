libmiscinit - initialization tasks for libmisc

loads all libmisc functions into shell and performs any necessary setup steps


add the following to any zsh script to use libmisc (including .zshrc):

  fpath=(/path/to/libmisc.zwc $fpath)
  autload libmiscinit
  libmiscinit

