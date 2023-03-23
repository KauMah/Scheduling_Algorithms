/**
 * Various list operations
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"
#include "task.h"


 // add a new task to the list of tasks
void insert(struct node** head, Task* newTask) {
    // add the new task to the list
    struct node* newNode = malloc(sizeof(struct node));

    newNode->task = newTask;
    newNode->next = *head;
    *head = newNode;
}

void insert_end(struct node** head, Task* newTask) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->task = newTask;
    newNode->next = NULL;
    if (!*head) {
        *head = newNode;
    }
    else {
        struct node* trav = *head;
        while (trav->next) {
            trav = trav->next;
        }
        trav->next = newNode;
    }
}

void insert_end_q(struct node** head, Task* newTask) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->task = newTask;
    newNode->next = *head;
    if (!*head) {
        *head = newNode;
    }
    else {
        struct node* trav = *head;
        while (trav->next && trav->next != *head) {
            trav = trav->next;
        }
        trav->next = newNode;
    }
}

struct node* getNode(struct node) {
    return NULL;
}
// delete the selected task from the list
void delete(struct node** head, Task* task) {
    struct node* temp;
    struct node* prev;

    temp = *head;
    // special case - beginning of list
    if (strcmp(task->name, temp->task->name) == 0) {
        *head = (*head)->next;
    }
    else {
        // interior or last element in the list
        prev = *head;
        temp = temp->next;
        while (strcmp(task->name, temp->task->name) != 0) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
    }
}

// traverse the list
void traverse(struct node* head) {
    struct node* temp;
    temp = head;

    while (temp != NULL) {
        printf("[%s]\t[%d]\t[%d]\n", temp->task->name, temp->task->priority, temp->task->burst);
        temp = temp->next;
    }
}
