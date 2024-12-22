‎
=

## 2d_arr - *basic 2d array (grid) support for zsh*

---------------------------------

**examples:**


    fox-fr /path/to/file | 2d_arr create <arr_name> - read data from stdin, convert to 2d array under <arr_name>


    blank=1 2d_arr create <arrname> <x> <y> - create empty array under <arrname> with size <x> by <y> (default 10x10)


    2d_arr <delete||del> <arr_name> - delete existing 2d array


    2d_arr <query||qu> <arr_name> <x> <y> - return contents of indice at pos x y in given array


    2d_arr <query_grid||qg> <arr_name> - returns x and y length of grid stored at arrname


    2d_arr <query_col||qc> <arr_name> <x> - returns contents of column x


    2d_arr <query_row||qr> <arr_name> <y> - return contents of row y


    2d_arr <search||ss> <arr_name> <search term> - search 2d array for indice matching search term


    2d_arr <update||upd> <arr_name> <value> <x> <y> - change contents of indice at x and y pos to given value


    2d_arr <draw||dr> <arr_name> - print grid corresponding to arr_name


---------------------------------

utilizes zelfexec

able to handle multi-char entries in a single indice, though this will result in draw appearing warped
