/**
 * list data structure containing the tasks in the system
 */

#include "task.h"

struct node {
    Task* task;
    struct node* next;
};

// insert and delete operations.
void insert(struct node** head, Task* task);
void insert_end(struct node** head, Task* task);
void insert_end_q(struct node** head, Task* task);
void insert_sjf(struct node** head, Task* newTask);
void delete(struct node** head, Task* task);
void traverse(struct node* head);
