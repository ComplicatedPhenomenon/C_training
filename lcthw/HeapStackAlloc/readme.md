# Allocate space from heap  and stack 
It should be noted that `argv[0]` holds the name of the program itself and `argv[1]` is a pointer to the first command line argument supplied, and `*argv[n]` is the last argument. If no arguments are supplied,` argc` will be one, and if you pass one argument then `argc `is set at 2.
