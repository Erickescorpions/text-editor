#ifndef STACK_H_
#define STACK_H_

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef enum {INSERT = 0, DELETE} ActionType_t;

typedef struct {
  size_t position;
  ActionType_t type;
  char* content;
} Action_t;

typedef struct {
  int top;
  int size;
  Action_t** actions;
} Stack_t;

Action_t* create_action(int position, ActionType_t type, char* content);
Stack_t* create_stack(int size);
void delete_stack(Stack_t* this);
bool push_stack(Stack_t* this, Action_t* action);
Action_t* pop_stack(Stack_t* this);
void print_action(Action_t* action);

#endif // STACK_H_