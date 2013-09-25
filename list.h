#ifndef __LIST_H__
#define __LIST_H__

/* your list data structure declarations */

struct node {
        int value;
        struct node *next;
};

void usage(char *);

char *check_if_valid(char *);

void add_in_order(char *, struct node **);

void list_print (struct node *);

//void free_list (struct node *);

/* your function declarations associated with the list */


#endif // __LIST_H__
