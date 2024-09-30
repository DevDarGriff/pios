//#include <stdio.h>



struct list_element {
    struct list_element *next;
    int data;
};
/*
struct list_element c = { NULL, 0};	//next ptr is NULL, end of list
struct list_element b = { &c, 0};	//next ptr points to c
struct list_element a = { &b, 0};	//next ptr points tp a
struct list_element *head = &a;
*/
