#include <stdio.h>
#include <stdlib.h>
#include "list.h"


char *check_if_valid(char *word) {
	//int num = atoi(word);
	//puts("reached check if valid");

	if (isdigit(word[0]) == 0) {
		if (word[0] != 45) {
			return NULL;
		}
	}
	int i = 1;
	for (; i < strlen(word); i++) {
		if (isdigit(word[i]) == 0) {
			return NULL;
		}
	}
	return word;
}

void add_in_order(char *word, struct node **head) {
	//puts ("get here?");
	int val = atoi(word);
	struct node *newnode = malloc(sizeof(struct node));
	newnode->value = val;
	struct node *sorted = (*head);
	struct node *p;
	struct node *t;

	//printf("%d\n",newnode->value);
	if ((*head) == NULL) {
		newnode->next = (*head);
		(*head) = newnode;
		(head) = &newnode;
		//puts("null");
	}
	else if (val <= ((*head)->value)) {
		newnode->next = (*head);
		(*head) = newnode;
		(head) = &newnode;
		//puts("first");
	}
	else {
		p = (*head);
		while ((*head) != NULL) {
			if ((*head)->next == NULL) {
				(*head)->next = newnode;
				newnode->next = NULL;
				(*head) = p;
				break;
			}
			else if (val <= ((*head)->next)->value) {
				//puts("here???");
				t = (*head)->next;
				(*head)->next = newnode;
				newnode->next = t;
				(*head) = p;
				break;
			}
			else {
				(*head) = (*head)->next;
			}
		//puts("end");
		}
	}
}

void list_print (struct node *head) {
	struct node *t;
	while (head != NULL) {
		printf("%d\n",head->value);
		t = head;
		head = head->next;
		free(t);
	}
}
/*
void free_list (struct node *head) {
	struct node *t;
	//t = head;
	while (head != NULL) {
		puts("here though");
		t = head;
		if (t->next == NULL) {
			if (t == head) {
				free(t);
				break;
			}
			free(t);
			//head = t;
		}
		else {
			t = t->next;
		}
	}
}
*/
