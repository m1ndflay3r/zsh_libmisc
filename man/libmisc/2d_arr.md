‎
=

## 2d_arr - *2d array (grid) support for zsh*

---------------------------------

**examples:**


    fox-fr /path/to/file | 2d_arr <create||cr> <arr_name> - read data from stdin, convert to 2d array under <arr_name>

      note: expects data to be a proper grid, with all lines the same length. Padding will be added in a future update.


    blank=1 2d_arr <create||cr> <arrname> <x> <y> - create empty array under <arrname> with size <x> by <y> (default 10x10, each indice initialized with character ".")

      note: set flag init_char to set initialization character for blank 2d array (default is ".")


    2d_arr <delete||del> <arr_name> - delete existing 2d array


    2d_arr <query||qu> <arr_name> <x> <y> - return contents of indice at pos x y in given array


    2d_arr <query_grid||qg> <arr_name> <-x||-y||-d> - returns x and y length of grid stored at arrname (in format of "x y"). Pass -x or -y to return only x_ln or only y_ln. Pass -d to return diagonal length from 1 1 to ((OOB-1))


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


    2d_arr <invert_section||is> <arr_name> <x> <y> <xx> <yy> - swaps x and y axes of arr_name starting from indice x y and ending at indice xx yy. Set flag overwrite_indices to 1 to allow for non-square (rectangular) section inversion (will overwrite overlapping indices, and will error out if flipped x y coords are oob)


    2d_arr <anti_invert||ai> <arr_name> <x> <y> <xx> <yy> - same as invert, except from opposite corner (flipped x and y axes). Uses invert if opts are blank, or invert_section if opts are filled.


    2d_arr <mirror_x||mx> <arr_name> <y_begin> <y_end> <x_begin> <x_end> - mirror (reverse) contents of rows from y_begin to y_end. Setting x begin and x end will only mirror contents within that range. Leave all values blank to mirror entire grid along x axis.


    2d_arr <mirror_y||my> <arr_name> <x_begin> <x_end> <y_begin> <y_end> - mirror (reverse) contents of columns from x_begin to x_end. Setting y_begin and y_end will only mirror contents within that range. Leave all values blank to mirror entire grid along y axis.


    2d_arr <rotate_90||r9> <arr_name> <x_begin> <y_begin> <x_end> <y_end> - rotate indices from x_begin y_begin to x_end y_end by 90°. Leave all opts blank to rotate entire array.


    2d_arr <rotate_180||r18> <arr_name> <x_begin> <y_begin> <x_end> <y_end> - rotate indices from x_begin y_begin to x_end y_end by 180°. Leave all opts blank to rotate entire array.


    2d_arr <rotate_270||r27> <arr_name> <x_begin> <y_begin> <x_end> <y_end> - rotate indices from x_begin y_begin to x_end y_end by 270°. Leave all opts blank to rotate entire array.


    2d_arr <flush||fl> <arr_name> - consolidate ledger updates (ledger size management). Use this if your program updates the array enough for ledger size to become a concern.


    2d_arr <resize_arr||ra> <arr_name> <new_x_ln> <new_y_ln> - resize array to new_x_ln by new_y_ln. Truncates from bottom right corner if new x y ln is smaller than old x y ln.

      note: set flags ra_x and ra_y to specify an x y offset value for begin write old array contents to new array (ex, ra_x=2 ra_y=2 means old array contents will be aligned to x2 y2 in new array)


    2d_arr <insert_col||inc> <arr_name> <x> - insert new, empty column at col x. Previous col x and subsequent columns move up by one (new col x is inserted behind previous col x contents), increasing array x_ln by 1.


    2d_arr <insert_row||inr> <arr_name> <y> - insert new, empty row at row y. Previous row y and subsequent rows move up by one (new row y is inserted behind previous row y), increasing array y_ln by 1.


    2d_arr <delete_col||dlc> <arr_name> <x> - deletes col x, moving all subsequent columns down by one, and reducing array x_ln by 1.


    2d_arr <delete_row||dlr> <arr_name> <y> - deletes row y, moving all subsequent rows down by one, and reducing array y_ln by 1.


    2d_arr <readin_col||ric> <arr_name> <x> <col_data> - separating by newline, replace contents of col x with contents of col_data, starting from y1 and moving down until either no data remains or y ln exceeded.

      note: set flag ric_by_space=1 to divide col_data by space instead of by newline


    2d_arr <readin_row||rir> <arr_name> <y> <row_data> - separating by space, replace contents of row y with contents of row_data, starting from x1 and moving down until either no data remains or x_ln exceeded.

      note: set flag rir_by_newline=1 to divide row_data by newline instead of by space


    2d_arr <readin_section||ris> <arr_name> <x> <y> <section_data> - starting at x y, and with x delim of ' ' and y delim of '\n', replace indices in section with contents of section_data, stopping either when data ends or when OOB (x OOB continues on next y, y OOB terminates)




---------------------------------

able to handle multi-char entries in a single indice, though this will result in draw appearing warped

return code 3 = oob

return code 4 (for links) = no link exists

array names may not be integer, though string containing int is fine (ex, arrname a10 is fine but arrname 10 is disallowed)

any function which references a section of an array (such as query_section) begins in the upper left corner and ends in the lower right (i.e, start values aught to always be lower than end values)
