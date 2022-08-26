#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>


/**
 * main entry point for the program. This program executes the Unix call: $cat
 * which reads files sequentially, printing them to standard output
 *
 * the cat function will print out the first line of the text file accordingly.
 */

int main( int argc,char *argv[] ) {

    for (int j = 1; j < argc; ++j) {
        int current; //which file is open
        int i;

        /**
         * storing the current open file inside char arrat
         */
        char storeFile[1];
        current = open(argv[j],O_RDONLY,0777);

        /**
         * if there is no file provided in the argument line
         * error message notifying user that the file retreival has
         * failed
         */
        if (current == -argc) {

            printf("ERROR: file failed to open.");
        }
        if((i=read(current,storeFile,1))>0) {
                printf("%c", storeFile[0]);
        } //while
         /**
          * After storing file in array, and reading contents,
          * close the file.
          */
            close(current);

    } // for
} //main
