#include "bucketstack.h"
//intitate nodebucket
struct NodeBucket* createNewNodeBucket (int bucketSize){
    struct NodeBucket *NodeBucket1;
    NodeBucket1 = malloc(sizeof(struct NodeBucket));
    NodeBucket1->next = NULL;
    NodeBucket1->val = malloc(bucketSize * sizeof(char*));
    return NodeBucket1;
}
//intitate stack
void initStack (int bucketSize, struct Stack **stack){
    *stack = malloc(sizeof(struct Stack));
    if (stack == NULL)
        exit(1);
    (*stack)->bucketSize = bucketSize;
    (*stack)->topElt = -1;
    (*stack)->firstBucket = createNewNodeBucket(bucketSize);
}
//check if stack is empty
bool isEmpty (const struct Stack *stack){
    return size(stack) == 0;
}
//push a element to a stack
void push (char* val, struct Stack *stack){
    //no bucket exist
    if (stack->firstBucket == NULL){
        struct NodeBucket * NewBucket;
        NewBucket = createNewNodeBucket(stack->bucketSize);
        stack->firstBucket = NewBucket;
    }
    //bucket is function
    if(stack->topElt < (stack->bucketSize)-1){
        (stack->topElt) += 1;
        stack->firstBucket->val[stack->topElt] = malloc(strlen(val)+1);
        strcpy(stack->firstBucket->val[stack->topElt],val) ;
    }
    //bucket is full
    else{
        struct NodeBucket * NewBucket2; 
        NewBucket2 = createNewNodeBucket(stack->bucketSize);
        NewBucket2->next = stack->firstBucket;
        NewBucket2->val[0] = malloc(strlen(val)+1);
        strcpy(NewBucket2->val[0],val);
        stack->firstBucket = NewBucket2;
        stack->topElt = 0;
    }
}
//pop a element from a stack
void pop(struct Stack *stack){
    assert(!isEmpty(stack));
    // only one element left
    if(stack->topElt == 0){
        struct NodeBucket * temp; 
        temp = createNewNodeBucket(stack->bucketSize);
        temp = stack->firstBucket;
        stack->firstBucket = stack->firstBucket->next;
        stack->topElt = stack->bucketSize - 1; 
        if (stack->firstBucket == NULL)
            stack->topElt = -1; 
        free(temp->val);
        free(temp);
    }
    else {
        stack->firstBucket->val[stack->topElt-1] = realloc(stack->firstBucket->val[stack->topElt-1],strlen(stack->firstBucket->val[stack->topElt])+1);
        stack->firstBucket->val[stack->topElt] = NULL;
        free(stack->firstBucket->val[stack->topElt]);
        stack->topElt -= 1;
    }
}
//check the size of the stack
int size (const struct Stack *stack){
    struct NodeBucket *countBucket;
    int counter;
    counter = 0;
    //count how many element in the non-empty bucket
    counter = counter + stack->topElt +1;
    for(countBucket = stack->firstBucket->next;countBucket != NULL;countBucket = countBucket->next)
        counter = counter + stack->bucketSize; 
    return counter;
}
//return top value of the stack
char* top (const struct Stack *stack){
    assert(!isEmpty(stack));
    return stack->firstBucket->val[stack->topElt];
}
//print the whole stack
void print (const struct Stack *stack){
    struct NodeBucket * temp;
    int firstP,otherP;
    if (stack->topElt == -1)
    printf("stack is:\n");
    else{
    printf("stack is:\n");
    //print first bucket
    if(!isEmpty(stack)){
        temp = stack->firstBucket;
        for(firstP = stack->topElt;firstP >= 0;firstP--){
            printf("\t%s\n",temp->val[firstP]);
        }
        temp = stack->firstBucket;
        //print other bucket
        for (temp != NULL;temp = temp->next;){
            for(otherP = stack->bucketSize -1;otherP >= 0;otherP--){
             printf("\t%s\n",temp->val[otherP]);
            }
        }
        }
    }
}
//swap top 2 element of a stack
void swap (struct Stack *stack){
    assert(size(stack)>1);
    char *topFirst, *topSecond;;
    topFirst = malloc(strlen(top(stack)+1));
    strcpy(topFirst,top(stack));
    if(stack->topElt == 0){
    topSecond = malloc(strlen(stack->firstBucket->next->val[stack->bucketSize-1]));
    strcpy(topSecond,stack->firstBucket->next->val[stack->bucketSize-1]);
    stack->firstBucket->val[stack->topElt] = realloc(stack->firstBucket->val[stack->topElt],strlen(stack->firstBucket->next->val[stack->bucketSize-1])+1);
    stack->firstBucket->next->val[stack->bucketSize-1] = realloc(stack->firstBucket->next->val[stack->bucketSize-1],strlen(stack->firstBucket->val[stack->topElt])+1);
    strcpy(stack->firstBucket->val[stack->topElt],topSecond);
    strcpy(stack->firstBucket->next->val[stack->bucketSize-1],topFirst);
    }
    else if(stack->topElt > 0){
        topSecond = malloc(strlen(stack->firstBucket->val[stack->topElt-1]));
        strcpy(topSecond,stack->firstBucket->val[stack->topElt-1]);
        stack->firstBucket->val[stack->topElt] = realloc(stack->firstBucket->val[stack->topElt] ,strlen(stack->firstBucket->val[stack->topElt-1]));
        stack->firstBucket->val[stack->topElt-1] = realloc(stack->firstBucket->val[stack->topElt-1],strlen(stack->firstBucket->val[stack->topElt]));
        strcpy(stack->firstBucket->val[stack->topElt],topSecond);
        strcpy(stack->firstBucket->val[stack->topElt-1],topFirst);
    }
    free(topFirst);
    free(topSecond);
}
