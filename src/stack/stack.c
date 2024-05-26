#include "stack.h"

Action_t* create_action(int position, ActionType_t type, char* content) {
  Action_t* action = malloc(sizeof(Action_t));

  if(action) {
    action->position = position;
    action->type = type;
    action->content = content;
  }

  return action;
}

Stack_t* create_stack(int size) {
  Stack_t* stack = malloc(sizeof(Stack_t));

  if(stack) {
    stack->top = 0;
    stack->size = size;
    stack->actions = malloc(size * sizeof(Action_t));
  }

  return stack;
}

void delete_stack(Stack_t* this) {
  // libereamos memoria de las acciones guardadas
  for(size_t i = 0; i < this->size; i++) {
    free(this->actions[i]);
  }

  free(this);
}

bool push_stack(Stack_t* this, Action_t* action) {
  if(action == NULL) return false;
  if(this->top == (this->size - 1)) return false;

  this->actions[++this->top] = action;

  return true;
}

Action_t* pop_stack(Stack_t* this) {
  if(this->top == 0) return this->actions[this->top];
  return this->actions[this->top--];
}

void print_action(Action_t* action) {
  puts("Action:");
  printf("- position: %ld\n", action->position);
  printf("- type: %s\n", action->type == INSERT ? "INSERT" : "DELETE");
  printf("- content: %s\n", action->content);
}
