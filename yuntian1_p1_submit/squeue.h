/*
This is created by Sarah Nadi for CMPUT 201 at the University of Alberta.
Posting this file or any solution created based on it in a public website violates the Code of Conduct of the course and the university.
*/
#ifndef __SQUEUE_H__
#define __SQUEUE_H__

#include <stdbool.h>
#include <assert.h> 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Node{
    char* val;
    struct Node* next;
    struct Node* prev;
};

struct Squeue{
    struct Node* first;
    struct Node* last;
};

void initSqueue (struct Squeue ** squeue);
bool isEmpty (const struct Squeue * squeue);
void addFront (struct Squeue * squeue, char* val);
void addBack (struct Squeue * squeue, char* val);
void leaveFront (struct Squeue * squeue);
char* peekBack (const struct Squeue *squeue);
void leaveBack (struct Squeue *squeue);
char* peekFront (const struct Squeue * squeue);
void print (const struct Squeue * squeue, char direction);
void nuke (struct Squeue * squeue);
void mergeFront(struct Squeue* squeue);
void mergeBack(struct Squeue* squeue);
#endif
