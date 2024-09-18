#include <stdio.h>

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



char glbl[128];

void kernel_main() {

	//declare, initialize, & store timer count
    unsigned long timer_value;
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

    delay(1000);

    while(1){
    }
}
