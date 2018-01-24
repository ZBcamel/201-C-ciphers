/*
 This is created by Sarah Nadi for CMPUT 201 at the University of Alberta.
 Posting this file or any solution created based on it in a public website violates the Code of Conduct of the course and the university.
 */

#ifndef __BUCKETSTACK_H__
#define __BUCKETSTACK_H__

#include <stdbool.h>
#include <assert.h> 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct NodeBucket {
    char** val;
    struct NodeBucket* next;
};

struct Stack {
    struct NodeBucket* firstBucket;
    int topElt;
    int bucketSize;
};

struct NodeBucket* createNewNodeBucket (int bucketSize);
void initStack (int bucketSize, struct Stack **stack);
bool isEmpty (const struct Stack *stack);
void push (char* val, struct Stack *stack);
void pop(struct Stack *stack);
int size (const struct Stack *stack);
void swap (struct Stack *stack);
char* top (const struct Stack *stack);
void print (const struct Stack *stack);
#endif /* bucketstack_h */
