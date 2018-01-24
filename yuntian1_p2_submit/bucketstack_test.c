#include "bucketstack.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  //We will have two stacks
  struct Stack *s1 = NULL;
  struct Stack *s2 = NULL;
  initStack(5, &s1);
  initStack(3, &s2);
  push("uno", s1);
  push("dos", s1);
  //s1 now has "dos" and "uno" in that order
  assert(strcmp("dos", top(s1)) == 0);
  //s2 is empty at this moment
  assert(isEmpty(s2));
  push("tres", s2);
  //We just added "tres" in s2
  assert(strcmp("tres", top(s2)) == 0);
  assert(size(s1) == 2);
  assert(size(s2) == 1);
  //Time to swap "dos" and "uno"
  swap(s1);
  //s1 now has "uno" and "dos" in that order
  assert(strcmp("uno", top(s1)) == 0);
  //Let's add 100 elements to each stack
  for(int i = 0; i < 3; i++) {
    push("hola", s1);
    push("mundo!", s2); 
  }
  print(s1);
  print(s2);

  for(int i = 0; i < 97; i++) {
    push("hola", s1);
    push("mundo!", s2);
  }

  assert(size(s1) == 102);
  assert(size(s2) == 101);
  //s1 should have "hola" at the top
  assert(strcmp(top(s1), "hola") == 0);
  //s2 should have "mundo!" at the top
  assert(strcmp(top(s2), "mundo!") == 0);
  
  for(int i = 0; i < 100; i++) {
    assert(strcmp(top(s1), "hola") == 0);
    pop(s1);
    assert(strcmp(top(s2), "mundo!") == 0);
    pop(s2);
  }
  assert(strcmp(top(s1), "uno") == 0);
  pop(s1);
  assert(strcmp(top(s1), "dos") == 0);
  pop(s1);
  
  assert(strcmp(top(s2), "tres") == 0);
  pop(s2);
  
  free(s1);
  free(s2);
  return 0;
}
