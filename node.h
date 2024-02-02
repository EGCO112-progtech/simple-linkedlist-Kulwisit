//
//  node.h
//  simple linkedlist
//
//  Created by Mingmanas Sivaraksa on 4/2/2566 BE.
//

// this part is use for preventing error from multiple include
// if not define
#ifndef node_h
#define node_h

struct node
{
    int value;
    struct node *next;
};

// struct node * create_Node() {

//     struct node * new_node = (struct node *)malloc(sizeof(struct node));
//     new_node->next = NULL;

//     return new_node;
// }

#endif /* node_h */
