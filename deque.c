//  Yuya Oguchi
//  COEN12L Lab 4
//  2/24/2015
//  Maze Runner
//  Deque.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "deque.h"

typedef struct node{
    int number;
    struct node *next;
    struct node *prev;
} NODE;

struct deque {
    int counter;
    NODE *head;
};

DEQUE *createDeque(void){
    NODE *list = malloc(sizeof(NODE)); //this creates node when called
    list->number = -1;
    list->next = list;
    list->prev = list;

    DEQUE *dq = malloc(sizeof(DEQUE)); //create set of NODE called dq
    dq->counter = 0;
    dq->head = list;
    return dq;
}



void destroyDeque(DEQUE *dq){
    assert(dq!= NULL);// check to make sure there is dq set
    NODE *node = dq->head;
    NODE *next;

    do { //free each node by running through dq list
        next = node->next;
        free(node);
        node = next;
    } while (node != dq->head);
    free(dq);
}

int numItems(DEQUE *dq){
    assert(dq!= NULL);// check to make sure there is dq set
    return dq ->counter; // return the kept number of counter in dq
}

void addFirst(DEQUE *dq, int x){
    NODE *deck = malloc(sizeof(NODE)); // create NODE to insert
    deck->number = x; // allocate the number
    deck->next = dq->head->next;// next four line set deck in to the beginning of list
    deck->prev = dq->head;
    dq->head->next->prev = deck;
    dq->head->next = deck;
    dq->counter++;//increment counter
}

void addLast(DEQUE *dq, int x){
    NODE *decklast = malloc(sizeof(NODE)); // create NODE to insert
    decklast->number = x;//give number to that NODE
    decklast->next = dq->head;//next four line set NODE at the end of list and connect all links
    decklast->prev = dq->head->prev;
    dq->head->prev->next = decklast;
    dq->head->prev = decklast;
    dq->counter++; // increment counter
}


int removeFirst(DEQUE *dq){
    assert(dq!= NULL); // check to make sure there is something to erase in the first place
    NODE *deckrf = dq->head->next;//temp NODE

    dq->head->next = deckrf->next; // link temp node to keep all the linked list
    deckrf->next->prev = dq->head;

    int temp = deckrf->number; // temp holder to delete the NODE
    free(deckrf); // free the first one
    dq->counter--; //decrement counter
    return temp; // return the value of the temp NODE which you deleted
}

int removeLast(DEQUE *dq){
    assert(dq!= NULL);//make sure there is something to erase
    NODE *deckrl = dq->head->prev; //temp NODE

    dq->head->prev = deckrl->prev; // connect temp node to make sure link doesnt dissapear
    deckrl->prev->next = dq->head;

    int temp = deckrl->number; //temp NODE to delete
    free(deckrl);//delete that NODE
    dq->counter--;//decrement counter
    return temp;//return the value of deleted node
}


int getFirst(DEQUE *dq){
    assert(dq!= NULL);//make sure there are nodes in the dq
    return dq->head->next->number;//return the first node number
}


int getLast(DEQUE *dq){
    assert(dq!= NULL);//make sure there are nodes in the dq
    return dq->head->prev->number; // return the value of last node by going prov from head
}
