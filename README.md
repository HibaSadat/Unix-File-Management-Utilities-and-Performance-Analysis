This project involves developing a suite of Unix-based command-line utilities in C for file management and a simple shell to execute these commands. The project was executed on PuTTy, a terminal emulator. 
The utilities included are:   
-genData: A program to generate a 1000KB text file filled with random data. It accepts a filename as an argument and ensures the output file reaches the exact specified size. 

-mycopy: A file copying utility that reads a file and writes its contents to a new file, timing the operation with various buffer sizes (4096B, 2048B, 1024B, 512B, and 1B). It requires recompiling for each buffer size to measure the performance impact of buffer size on the copying process. An excel file is included to allot the time results. 

-myremove: A file deletion utility that takes a filename as an argument and uses the appropriate system call (unlink for files, rmdir for directories) to remove it from the filesystem. 

-mymove: A file moving utility that functionally renames a file, similar to the rename command found in DOS and Windows systems. 

-msh (Minimal Shell): A shell that recognizes the custom commands mycopy, myremove, and mymove.
