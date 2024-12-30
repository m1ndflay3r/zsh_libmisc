‎
=

## 2d_arr - *basic 2d array (grid) support for zsh*

---------------------------------

**examples:**


    fox-fr /path/to/file | 2d_arr <create||cr> <arr_name> - read data from stdin, convert to 2d array under <arr_name>

      note: expects data to be a proper grid, with all lines the same length. Padding will be added in a future update.


    blank=1 2d_arr <create||cr> <arrname> <x> <y> - create empty array under <arrname> with size <x> by <y> (default 10x10, each indice initialized with character ".")


    2d_arr <delete||del> <arr_name> - delete existing 2d array


    2d_arr <query||qu> <arr_name> <x> <y> - return contents of indice at pos x y in given array


    2d_arr <query_grid||qg> <arr_name> - returns x and y length of grid stored at arrname (in format of "x y")


    2d_arr <query_col||qc> <arr_name> <x> - returns contents of column x (printed horizontally)


    2d_arr <query_row||qr> <arr_name> <y> - return contents of row y (printed vertically)


    2d_arr <query_adj||qa> <arr_name> <x> <y> <direction> - print contents and coords of all indices adjacent to given indice in given direction (output in format of "contents x y"). Directions available are nw, n, ne, e, se, s, sw, and w).

      note: set flag single=1 before command to only print first adjacent result


    2d_arr <create_link||cl> <arr_name> <x> <y> <xx> <yy> - link indice x y to indice xx yy

      note: set flag mono=1 before command to only link in one direction (i.e querying <x> <y> will return <xx> <yy>, but querying <xx> <yy> won't return <x> <y>)


    2d_arr <query_link||ql> <arr_name> <x> <y> - query indice x y for x y coords of all indices linked to it (in format of "x y", separated by newline)


    2d_arr <delete_link||dl> <arr_name> <x> <y> <xx> <yy> - unlink indice x y from indice xx yy


    2d_arr <search||ss> <arr_name> <search term> - search 2d array for all indices matching search term (in format of "x y", each result on newline)


    2d_arr <update||upd> <arr_name> <value> <x> <y> - change contents of indice at x and y pos to given value


    2d_arr <draw||dr> <arr_name> - print grid corresponding to arr_name


    updstr=<char> 2d_arr <update_section||us> <arr_name> <x> <y> <xx> <yy> - replace contents of every indice starting from x y and ending at xx yy with contents of updstr


    2d_arr <query_section||qs> <arr_name> <x> <y> <xx> <yy> - print section of grid starting from x y and ending at xx yy


    2d_arr <invert||inv> <arr_name> - swaps x and y axes of grid corresponding to arr_name



---------------------------------

utilizes zelfexec

able to handle multi-char entries in a single indice, though this will result in draw appearing warped

return code 3 = oob

return code 4 (for links) = no link exists
