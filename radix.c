//  Yuya Oguchi
//  COEN12L Lab 4
//  2/24/2015
//  Maze Runner
//  radix.c

#include <stdio.h>
#include "deque.h"

void radixSort(DEQUE *dq) {
    DEQUE *deck[10]; //create bucket to hold last number 0-9 digit nodes

    int i;
    for(i=0;i<10;i++){
         deck[i] = createDeque(); // create the bucket
    }

    int n;
    int divide = 1;//temp int to divide the numbers by
    int max;//max times to run
    int digits = 1;
    for (n=0; n<digits; n++) {
	    int temp;
	    int items = numItems(dq);//items is the number of item in the dq
	    for (i = 0; i < items; i++){//run for all items in dq
            temp = removeFirst(dq);//remove the current node from list
            if (temp>max) {
                max = temp;
            }//this set max number to be the number with highest digits
            addLast(deck[(temp/divide) % 10], temp);//add the current node to corresponding bucket
	    }
	    int temp2;//hold number of items in each bucket
        int j;
	    for (i = 0; i< 10; i++){
            temp2 = numItems(deck[i]);//set temp2 to the number of item in the bucket
            for (j = 0; j < temp2; j++){//run for all items in the bucket
                addLast(dq, removeFirst(deck[i]));//add each one back to the dq and delete from deck
            }
	    }
        if (n==0) {//make sure it runs once
            while((max=(max/10)) != 0){//come up with num. this needs to run by counting digit in highest num.
                digits++;
            }
        }
        divide *= 10;// this changes the digit from 1 to 10 to 100 and so on every run
    }

    for(i=0;i<10;i++){//run through all the bucket
        destroyDeque(deck[i]);//destroy buckets which should now be empty
    }
}

int main() {
    DEQUE *deckf = createDeque(); // create the deque to store nodes in

    printf("Type in numbers!\n"); // type in the numbers to sort
    int num = 1;
    while(num >= 0){
        scanf("%i", &num);
        if (num >=0){
            addLast(deckf, num); // add all numbers into node in set deckf
        }
    }

    radixSort(deckf); // sort

    int items = numItems(deckf);
    int i;

    for (i = 0; i < items; i++){
        printf("%i ", removeFirst(deckf));//print all sorted numbers in the list
    }
    
    printf("\n");
    return 0;
}
