#include "schedulers.h"
#include "list.h"
#include "task.h"
#include <stdio.h>
#include <stdlib.h>

#define QUANTUM 10

struct node* list;
int tid = 0;

void add(char* name, int priority, int burst) {
  Task* toAdd = malloc(sizeof(Task));
  toAdd->name = name;
  toAdd->priority = priority;
  toAdd->burst = burst;
  toAdd->tid = tid++;
  insert_end_q(&list, toAdd);

  // printf("%s\t\t%d\t\t%d\t\t%d\n", toAdd->name, toAdd->priority, toAdd->burst, toAdd->tid);
}

void schedule() {
  struct node* temp = list;
  struct node* prev = list;
  while (prev->next != list) {
    prev = prev->next;
  }
  printf("Name\t\tRemaining\tID\t\tTime to spend\n");
  while (temp->next && temp != temp->next) {
    printf("%s\t\t%d\t\t%d\t\t%d\n", temp->task->name, temp->task->burst, temp->task->tid, (temp->task->burst < QUANTUM) ? temp->task->burst : QUANTUM);
    if ((temp->task->burst - QUANTUM) < 1) {
      struct node* t = temp;
      prev->next = temp->next;
      temp = temp->next;
      free(t->task);
      free(t);
    }
    else {
      temp->task->burst = temp->task->burst - QUANTUM;
      temp = temp->next;
      prev = prev->next;
    }
  }
  printf("%s\t\t%d\t\t%d\t\t%d\n", prev->task->name, prev->task->burst, prev->task->tid, prev->task->burst);
}