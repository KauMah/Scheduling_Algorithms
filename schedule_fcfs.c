#include "schedulers.h"
#include "list.h"
#include "task.h"
#include <stdio.h>
#include <stdlib.h>

struct node* list;
int tid = 0;

void add(char* name, int priority, int burst) {
  Task* toAdd = malloc(sizeof(Task));
  toAdd->name = name;
  toAdd->priority = priority;
  toAdd->burst = burst;
  toAdd->tid = tid++;
  insert_end(&list, toAdd);

  // printf("%s\t%d\t%d\t%d\n", toAdd->name, toAdd->priority, toAdd->burst, toAdd->tid);
}

void schedule() {
  printf("[NAME]\t[PRIORITY]\t[BURST]\n");
  traverse(list);
  struct node* temp;
  // I'm a responsible C programmer so I clean up after myself
  while (list) {
    temp = list;
    list = list->next;
    free(temp->task);
    free(temp);
  }
  return;
}
