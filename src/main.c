#include "stack/stack.h"

int main() {
  Action_t* action = create_action(5, INSERT, "Hola mundo");

  Stack_t* s = create_stack(5);
  push_stack(s, action);
  Action_t* popped_action = pop_stack(s);

  print_action(popped_action);
}