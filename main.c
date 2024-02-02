//
//  main.c
//  simple linkedlist
//
//  Created by Mingmanas Sivaraksa on 4/2/2566 BE.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(int argc, const char * argv[]) {
    int z=5;
    struct node a,b,*head ;
    a.value = z;
    a.next=&b;
    head=&a;
    b.value=head->value+3;

    printf("%d\n", head ->value ); //what value for 5
    printf("%d\n", head ->next->value ); //what value for 8
/*  Exercise I
    1. Add 1 more node at the end
    2. Add value(11)
    3. Make next become NULL
    4. print with head
 */

    struct node c;
    b.next = &c;
    c.value = 11;
    c.next = NULL;
    printf("c = %d\n", head->next->next->value);
    
/*  Exercise II
        1. Add 1 more at the begining!!!!
        2. Add value (2)
*/
    struct node d;
    d.next = &a;
    d.value = 2;
    head = &d;
    printf("%d\n%d\n%d\n%d\n", d.value, d.next->value, d.next->next->value, d.next->next->next->value);

    typedef struct node* NodePtr;
    NodePtr tmp=head; //add temp value to faciliate
        
    /*  Exercise III Use loop to print everything
        int i,n=5;
        for(i=0;i<n;i++){
            printf("%3d", tmp->value);
          // What is missing???
        }
    */

    int i,n=4;
    printf("for loop => ");
    for(i=0;i<n;i++){
        printf("%3d", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
    
   /*  Exercise IV change to while loop!! (you can use NULL to help)
       
         while(){
            printf("%3d", tmp->value);
           // What is missing???
        }
    */

    tmp = head;
    printf("while loop => ");
    while(tmp!=NULL){
        printf("%3d", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
    
 /*  Exercise V Use malloc to create all nodes, instead of create a struct!!
         //use a loop to help
          
     */

    NodePtr linkedlist = (NodePtr)malloc((sizeof(struct node)));
    NodePtr new_head = linkedlist;
    tmp = head;

    for (int i = 0; i < 4; i++) {
        linkedlist->value = tmp->value;
        tmp = tmp->next;
        if (i != 3) {
            linkedlist->next = (NodePtr)malloc(sizeof(struct node));
            linkedlist = linkedlist->next;
        }
        else {
            linkedlist->next = NULL;
        }
    }

    linkedlist = new_head;

    printf("loop create node => ");
    while (linkedlist!=NULL) {
        printf("%3d", linkedlist->value);
        linkedlist = linkedlist->next;
    }
    printf("\n");

    /*  Exercise VI Free all node !!
         //use a loop to help
          
     */

    NodePtr next = new_head->next;

    printf("freeing => ");
    while (new_head!=NULL) {
        next = new_head->next;
        printf("%3d ", new_head->value);
        free(new_head);
        new_head = next;
    }
    printf("=> done\n\n");

    return 0;
}