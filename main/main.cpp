#include <stdio.h>
#include "Recast.h"

int main(int argc, char const *argv[]) {
    //	handle arguments
    if (argc == 1) {
        printf("Please enter message\n");
        return 1;
        // return -1;
    }
    for (int count = 1; count < argc; count++) {
        if (argv[count][0] == '-') {
            // Handle options
            printf("%s", argv[count]);
        } else {
            // Handle infile
        }
    }
    return 0;
}
