#!/usr/bin/env zsh

template() {
  #load modules
  autoload libmiscinit           #
  libmiscinit                    # this loads literally every libmisc module. Replace with needed functions via autoload
  template_fail() {
    print 'Usage: <usage information>'
  }
  #fetch user input, trying stdin first
  if [ -z "$ztemplateWAITINDEF" ] || [ "$ztemplateWAITINDEF" = 0 ]; then
    export zFOXT=3
  else
    unset zFOXT
    unset ztemplateWAITINDEF
  fi
  ztemplate_stdin="$(fox)"
  unset zFOXT
  ztemplTESTWX="${ztemplate_stdin: :5}"
  if [ "$ztemplTESTWX" = "error" ]; then
    if [ -z "$@" ]; then
      template_fail
      return 1
    else
      ztemplate_stdin="$@"
      if isfile "$ztemplate_stdin"; then
        ztemplate_stdin="$(fox-fr "$ztemplate_stdin")"
      fi
    fi
  elif [ "$ztemplTESTWX" = 'file:' ]; then
    ztemplate_stdin="${ztemplate_stdin:5}"
    if isfile "$ztemplate_stdin"; then
      ztemplate_stdin="$(fox-fr "$ztemplate_stdin")"
    else
      template_fail
      return 1
    fi
  fi
  #env setup
  if [ ! -d "/tmp" ]; then
    template_working_dir=$HOME
  else
    template_working_dir='/tmp'
  fi
  #set process name for template binary to template
  export zELFSPOOF="template"
}
