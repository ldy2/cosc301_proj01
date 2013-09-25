/*
 *
 * Farah Fouladi & Lauren Yeary, September 25, 2013
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/resource.h>

#include "list.h"

void usage(char *program) {
    fprintf(stderr, "usage: %s [<datafile>]\n", program);
    exit(1);
}


int main(int argc, char **argv) {
/*	struct rusage rusage;
	struct rusage tusage;
	printf ("System time: %d\n", rusage.ru_utime);
*/

    FILE *datafile = NULL;

    /* find out how we got invoked and deal with it */
    switch (argc) {
        case 1:
            /* only one program argument (the program name) */ 
            /* just equate stdin with our datafile */
            datafile = stdin;        
            break;

        case 2:
            /* two arguments: program name and input file */
            /* open the file, assign to datafile */
            datafile = fopen(argv[1], "r");
            if (datafile == NULL) {
                printf("Unable to open file %s: %s\n", argv[1], strerror(errno));
                exit(-1);
            }
            break;

        default:
            /* more than two arguments?  throw hands up in resignation */
            usage(argv[0]);
    }

    /*
     * you should be able to just read from datafile regardless
     * whether it's stdin or a "real" file.
     */
	char input_list[128];
	const char *hash = "#";
        const char *sep = " \t\n";
        char *temp, *word, *line;
	struct node *head = NULL;

	while ((fgets(input_list, 128, datafile)) != NULL) {
		//printf("%d",input_list[0]);
		if(input_list[0] != 35) {
			for(line = strtok_r(input_list, hash, &temp); line != NULL; line = strtok_r(NULL, hash, &temp)) {
				//puts(line);
				for(word = strtok_r(line, sep, &temp); word != NULL; word = strtok_r(NULL, sep, &temp)) {
		                	if(check_if_valid(word) != NULL) {
						//puts("prints");
						add_in_order(word, &head);
						//puts(word);
					}
        			}
			}
		}
	}
    //puts(head->value);
    list_print(head);
    fclose(datafile);
    //free_list(head);

    struct rusage ru;
    int rv = getrusage(RUSAGE_SELF, &ru);
    printf("User Time: %d.06%d\n",ru.ru_utime.tv_sec, ru.ru_utime.tv_usec);
    printf("System Time: %d.06%d\n",ru.ru_stime.tv_sec, ru.ru_stime.tv_usec);
    //printf("%d\n User Time:", utime);
    return 0;
}

