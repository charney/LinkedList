#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "list.h"
/*
 * list.c
 *
 *  Created on: Mar 23, 2013
 *  Author: charney
 *
 * A simple implementation of a singly linked list and some functions to do actions on said list
 */

struct lnode {
        char *wordp;
        int count;
        int lastLine;
        struct lnode *next;
};

/**
 * Returns a new linked list node filled in with the given word and line, and
 * sets the count to be 1. Make sure to duplicate the word, as the original word
 * may be modified by the calling function.
 */
struct lnode* newNode (char* word, int line) {
struct lnode *np;
np = (struct lnode*)malloc(sizeof(struct lnode));
np->wordp = (char *)malloc(strlen(word) + 1);
strcpy(np->wordp,word);
np->lastLine = line;
np->count = 1;
np->next = NULL;
return np;
}

/**
 * In a linked list with *head as the head pointer, adds the given node to the
 * front of the list.
 */
void pushNode (struct lnode** head, struct lnode* node) {
node->next = *head;
*head = node;
}

/**
 * Returns the pointer to the node containing the given word in the linked list
 * with head as the head pointer. If a node with the given word cannot be found,
 * the function returns NULL.
 */
struct lnode* getNode (struct lnode* head, char* word) {
struct lnode * n = head;
        while(n != NULL){
                if(strcmp(n->wordp,word) == 0){
                        return n;
                }
                n = n->next;
        }
        return NULL;
}

/**
 * Removes the specified node from the list, and frees all memory the node is
 * using. Remember if *head is the node being deleted, it must be updated.
 */
void deleteNode (struct lnode** head, struct lnode* node){
        free(node->wordp);
        if(node == *head)
        {
        *head = node->next;
        free(node);
        }else{
                struct lnode *n = *head;
                while(n != NULL){
                        if(n->next == node){
                                n->next = node->next;
                                free(node);
                                break;
                        }
                        n = n->next;
                }
        }
}

/**
 * Simply returns the next node in the list, or NULL if there are no further nodes.
 */
struct lnode *nodeGetNext(struct lnode *node) {
if(node->next == NULL){
        return NULL;
}else{
        return node->next;
}
}

/**
 * Simply returns the word in the given node.
 */
char *nodeGetWord(struct lnode *node) {
return node->wordp;
}

/**
 * Simply returns the line in the given node.
 */
int nodeGetLine(struct lnode *node) {
return node->lastLine;
}

/**
 * Simply returns the count in the given node.
 */
int nodeGetCount(struct lnode *node) {
return node->count;
}

/**
 * Set the count in the node to be the given count.
 */
void nodeSetCount(struct lnode *node, int count) {
node->count = count;
}

/**
 * Set the line in the node to be the given line.
 */
void nodeSetLine(struct lnode *node, int line){
node->lastLine = line;
}

/**
 * Deletes every node in the list with *head as the head pointer. After calling
 * this function, all memory used by the list should be freed, and *head
 * should be NULL.
 */
void deleteList(struct lnode **head) {
while(*head != NULL){
        deleteNode(head,*head);
}
*head = NULL;
}

/*
 * Evict the specified node from the list, but does not free the memory used by it.
 */
void evictNode (struct lnode** head, struct lnode* node){
	        if(node == *head)
	        {
	        *head = node->next;
	        node->next = NULL;
	        }else{
	                struct lnode *n = *head;
	                while(n != NULL){
	                        if(n->next == node){
	                                n->next = node->next;
	                    	        node->next = NULL;
	                                break;
	                        }
	                        n = n->next;
	                }
	        }
}

/*
 * Inserts the given node (insertingNode) after the node prevNode into the list with
head pointer head. If the prevNode is NULL, then the node insertingNode is inserted at the front
of the list.
 */
void insertNode (struct lnode** head, struct lnode* prevNode, struct lnode* insertingNode){
if(prevNode == NULL){
	pushNode(head,insertingNode);
}else{
	insertingNode->next = prevNode->next;
	prevNode->next = insertingNode;
}
}

/*
 * Print out the word, count and line fields of each node in a list that starts from the
 * specified node. The output format is as follows:
 */
void printList (struct lnode* node){
	struct lnode *ptr = node;
	        while(ptr != NULL)
	        {
	                printf("%s %d %d\n",ptr->wordp, ptr->count, ptr->lastLine);
	                ptr = ptr->next;
	        }
}
/*
 * Simply returns the prev node in the list, or NULL if there are no previous nodes.
 */
struct lnode *nodeGetPrev(struct lnode *head, struct lnode *node){
if(node == head){
	return NULL;
}else{
	struct lnode *n = head;
	while(n != NULL){
		if(n->next == node){
			return n;
		}
		n = n->next;
	}
	return NULL;
}
}
