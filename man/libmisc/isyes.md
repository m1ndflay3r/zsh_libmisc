isyes - y/n input prompt handler


example: if isyes "Do something? (Y/n) "; then do something; else do nothing; fi


flags:

  DEFINVERT - set to non-(empty || zero) value to set default (empty) response to N (default Y)



note: also sets environment variable "yes" to return value for later referencing


