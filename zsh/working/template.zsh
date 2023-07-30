#!/usr/bin/env zsh

template() {
  ## load modules
  autoload libmiscinit           #
  libmiscinit                    # this loads literally every libmisc module. Replace with needed functions via autoload
  ## failure printout
  template_fail() {
    print 'Usage: <usage information>'
  }
  ## fetch user input
  #read command line args to array
  unset template_arg_array
  declare -a template_arg_array
  for template_args in $=@; do
    template_arg_array+=("$template_args")
  done
  #stdin read
  ztemplate_stdin_empty=0
  if [ -z "$ztemplateWAITINDEF" ] || [ "$ztemplateWAITINDEF" = 0 ]; then
    export zFOXT=3
  else
    unset zFOXT
    unset ztemplateWAITINDEF
  fi
  ztemplate_stdin="$(fox)"
  unset zFOXT
  ztemplate_stdin_read_return="${ztemplate_stdin: :5}"
  if [ "$ztemplate_stdin_read_return" = "error" ]; then
    # error out if both stdin and command line args are empty
    if [ -z "$@" ]; then
      template_fail
      return 1
    else
#      ztemplate_stdin="$@"                      #uncomment to treat input as file path if file exists at that path
#      if isfile "$ztemplate_stdin"; then
#        ztemplate_stdin="$(fox-fr "$ztemplate_stdin")"
#      fi
      ztemplate_stdin_empty=1
    fi
    # allow for manual file readin through filepath on stdin (print -n "file:/home/user/file.txt" | template)
  elif [ "$ztemplate_stdin_read_return" = 'file:' ]; then
    ztemplate_stdin="${ztemplate_stdin:5}"
    if isfile "$ztemplate_stdin"; then
      ztemplate_stdin="$(fox-fr "$ztemplate_stdin")"
    else
      template_fail
      return 1
    fi
  fi
  if [ "$ztemplate_stdin_empty" != 1 ]; then
    export zSTDIN=$ztemplate_stdin
  else
    unset zSTDIN
  fi
  ## env setup
  if [ ! -d "/tmp" ]; then
    template_working_dir=""$HOME"/template"
  else
    template_working_dir='/tmp/template'
  fi
  #create working directory if not exist
  [ ! -d "$template_working_dir" ] && zmkdir -p "$template_working_dir"
  #set process name for template binary
  export zELFSPOOF="template"
  ## define template binary as function
  ztemplate_binary() {
    #insert hexdump created with "zHEXDSH=1 hexd /path/to/file"
    print -n ""
  }
  ## execution
  (ztemplate_binary | zSTDIN=$zSTDIN zelfexec $=template_arg_array)
  return $?
}
