//#include <stdio.h>
#include <stdint.h>

void putc(int data) {

	//set mu_io pointer to mu_io register address
    volatile uint32_t *mu_io = (volatile uint32_t *) 0x3F215040;
	//write char to mu_io register
    *mu_io = (uint32_t)data;


/*
			fails with following declarations:

	//set mu_io pointer to mu_io register address
    unsigned int *mu_io = (unsigned int *) 0xFE215004;	//is this the correct MU_IO register address for raspberry pi 5?
	//write char to mu_io register
    *mu_io = (unsigned int)data;
*/
}
