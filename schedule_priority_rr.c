#include "schedulers.h"
#include "list.h"
#include "task.h"
#include "cpu.h"
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
  insert_priority(&list, toAdd);

}

void schedule() {
}