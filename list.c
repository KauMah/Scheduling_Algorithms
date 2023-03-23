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

// Insert based on task length
void insert_sjf(struct node** head, Task* newTask) {
    struct node* newNode = malloc(sizeof(struct node));
    struct node* curr;
    struct node* prev;
    newNode->task = newTask;
    newNode->next = NULL;
    // empty case
    if (!*head) {
        *head = newNode;
        return;
    }
    int burst = newNode->task->burst;
    // Insert at head
    // newTask-> next becomes head, head becomes newtask
    if (burst <= (*head)->task->burst) {
        newNode->next = *head;
        *head = newNode;
    }
    else {
        prev = *head;
        curr = prev->next;
        while (prev) {
            // handle placing at end of list
            if (!curr) {
                prev->next = newNode;
                break;
            }
            if (burst <= curr->task->burst) {
                prev->next = newNode;
                newNode->next = curr;
                break;
            }
            prev = curr;
            curr = curr->next;
        }
    }

}

// Insert based on task length
void insert_priority(struct node** head, Task* newTask) {
    struct node* newNode = malloc(sizeof(struct node));
    struct node* curr;
    struct node* prev;
    newNode->task = newTask;
    newNode->next = NULL;
    // empty case
    if (!*head) {
        *head = newNode;
        return;
    }
    int priority = newNode->task->priority;
    // Insert at head
    // newTask-> next becomes head, head becomes newtask
    if (priority <= (*head)->task->priority) {
        newNode->next = *head;
        *head = newNode;
    }
    else {
        prev = *head;
        curr = prev->next;
        while (prev) {
            // handle placing at end of list
            if (!curr) {
                prev->next = newNode;
                break;
            }
            if (priority <= curr->task->priority) {
                prev->next = newNode;
                newNode->next = curr;
                break;
            }
            prev = curr;
            curr = curr->next;
        }
    }

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
