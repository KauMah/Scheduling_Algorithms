#include "schedulers.h"
#include "list.h"
#include "task.h"
#include <stdio.h>
#include <stdlib.h>

struct node** list;
int tid = 0;

void add(char* name, int priority, int burst) {
  Task* toAdd = malloc(sizeof(Task));
  toAdd->name = name;
  toAdd->priority = priority;
  toAdd->burst = burst;
  toAdd->tid = tid++;
  insert(list, toAdd);

  // printf("%s\t%d\t%d\t%d\n", toAdd->name, toAdd->priority, toAdd->burst, toAdd->tid);
}

void schedule() {
  // struct node* temp = list;
  // while (temp) {
  //   // printf("%s\t%d\n", temp->task->name, temp->task->burst);
  //   printf("hey\n");
  //   temp = temp->next;
  // }
  return;
}
