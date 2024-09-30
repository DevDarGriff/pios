//#include <stdio.h>
//#include "rprintf.c"
#include "serial.h"
#include "rprintf.h"

	//method to retrieve pi's clock counter
unsigned long get_timer_count() {
    unsigned long *timer_count_register = 0x3f003004;
    return *timer_count_register;
}
      //method to delay pi's clock counter
void delay(unsigned int microsecond_delay) {
    unsigned long start_time;
    unsigned long current_time;

    start_time = get_timer_count();

    do {
	current_time = get_timer_count();
    } while ((current_time - start_time) < microsecond_delay);
}

	//function prototypes linked list
    list_add(struct list_element **list_head, struct list_element *new_element);
    list_remove(struct list_element *element);



	//declare global variable el -- will hold current Execution Level
unsigned int el;

	//function to read and retrieve address from CurrentEl
unsigned int getEl() {

    asm("mrs %0, CurrentEL"
	: "=r"(el)
	:
	:);

    return el>>2;
}

void print_current_El() {
    el = getEl();
    esp_printf(putc, "Current Execution Level is: %d\r\n", el);
}


char glbl[128];

void kernel_main() {



	//retrieve current Execution Level, print EL to terminal
    print_current_El();


	//declare, initialize, & store timer count
    unsigned long timer_value;
    timer_value = get_timer_count();
    delay(1000);
    timer_value = get_timer_count();

	//declaration of external & local variables
    extern int __bss_start, __bss_end;
    char *bssStart, *bssEnd;
	//set bss boundries using mem address of bss start & end
    bssStart = &__bss_start;
    bssEnd = &__bss_end;
	//for loop to initialize bss segment to zeros
    for(char *index = bssStart; index <= bssEnd; index++) {
	*index = 0;
    }

/*
    struct list_element c = { NULL, 0};		//next ptr is NULL, end of list
    struct list_element b = { &c, 0};		//next ptr points to c
    struct list_element a = { &b, 0};		//next ptr points to a
    struct list_element *head = &a;
*/

    while(1){
    }
}
