#include "squeue.h"
//innitiate squeue
void initSqueue (struct Squeue ** squeue){
    struct Squeue *squeue1;
    squeue1 = malloc(sizeof(struct Squeue));    
    squeue1->first = NULL;
    squeue1->last  = NULL;
    *squeue = squeue1;
}
//check if squeue is empty
bool isEmpty (const struct Squeue * squeue){
    if (squeue->first == NULL)
        return true;
    else
        return false;
}
//add a element in front of a squeue
void addFront (struct Squeue * squeue, char* val){
    struct Node *temp;
    temp = malloc(sizeof(struct Node));
    temp->val = malloc(strlen(val)+1);
    strcpy(temp->val, val);
    temp->prev = NULL;
    temp->next = NULL;
    if (squeue->first  ==  NULL)
    {
        squeue->first = squeue->last = temp;
    }
    else
    {
        squeue->first->prev = temp;
        temp->next = squeue->first;
        squeue->first = temp;
    }    
}
//add a element at end of a squeue
void addBack (struct Squeue * squeue, char* val){
    struct Node *temp;
    temp = malloc(sizeof(struct Node));
    temp->val = malloc(strlen(val)+1);
    strcpy(temp->val, val); 
    temp->prev = NULL;
    temp->next = NULL;
    if (squeue->last  ==  NULL)
    {
        squeue->first = squeue->last = temp;
    }
    else
    {
        squeue->last->next = temp;
        temp->prev = squeue->last;
        squeue->last = temp;
    } 
}
//delete a element at the end of a squeue
void leaveBack (struct Squeue * squeue){
    assert (!isEmpty(squeue));
    struct Node *temp;
    temp = squeue->last;
    if(squeue->first == squeue->last){
    free(temp->val);
    free(temp);
    squeue->first = squeue->last = NULL;
    }    
    else{
    squeue->last = squeue->last->prev;
    squeue->last->next =NULL;
    free(temp->val);
    free(temp);
    }
}
//delete a element in front of a squeue
void leaveFront (struct Squeue *squeue){
    assert (!isEmpty(squeue));
    struct Node *temp;
    temp = squeue->first;
    if( 
    squeue->first == squeue->last){
    free(temp->val);
    free(temp);
    squeue->first = squeue->last = NULL;
    }   
    else{
    squeue->first = squeue->first->next;
    squeue->first->prev =NULL;
    free(temp->val);
    free(temp);
    }
}
//return last value of squeue
char* peekBack (const struct Squeue *squeue){
    assert (!isEmpty(squeue));
    return squeue->last->val;
}
//return first value of squeue
char* peekFront (const struct Squeue * squeue){
    assert (!isEmpty(squeue));
    return squeue->first->val;
}
// print squeue in two order
void print (const struct Squeue * squeue, char direction){
    struct Node *temp;
    if (direction =='f'){   
        printf("stack is:\n");
        temp = squeue->first;
        while (temp)
        {
        printf("\t%s\n", temp->val);
        temp = temp->next;
        }
    }
    else if(direction == 'r'){
        printf("stack is:\n");
        temp = squeue->last;
        while (temp)
        {
        printf("\t%s\n", temp->val);
        temp = temp->prev;
        }
    }
    else
    fprintf(stderr,"Error, illegal direction <entered direction>");
}
//clear squeue
void nuke (struct Squeue * squeue){
      while (!isEmpty(squeue))
        leaveFront(squeue);
}
//merge first two element of squeue
void mergeFront(struct Squeue* squeue){
    char *temp = malloc(strlen(squeue->first->val)+strlen(squeue->first->next->val)+1);
    strcpy(temp,squeue->first->val);
    strcat(temp,squeue->first->next->val);
    leaveFront(squeue);
    squeue->first->val = realloc(squeue->first->val, strlen(temp)+1);
    strcpy(squeue->first->val,temp);
    free(temp);
}
//merge last two element of squeue
void mergeBack(struct Squeue* squeue){
    char *temp = malloc(strlen(squeue->last->val)+strlen(squeue->last->prev->val)+2);
    strcpy(temp,squeue->last->val);
    strcat(temp,squeue->last->prev->val);
    leaveBack(squeue);
    squeue->last->val = realloc(squeue->last->val, strlen(temp)+1);
    strcpy(squeue->last->val,temp);
    free(temp);
}