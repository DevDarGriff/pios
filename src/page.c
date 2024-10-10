#include <stdio.h>
#include <stdint.h>
#include <stddef.h>


//double check what libraries are needed?



    struct ppage physical_page_array[128];    //128 pages, each 2mb in length. covers 256 megs of mem
    struct ppage *free_list_head = NULL;

	//function that initializes list of free physical page structures
    void init_pfa_list(void) {
      free_list_head = NULL;

      for (int i = 0; i < 128; i++) {
        physical_page_array[i].physical_addr = (void *)(i * 2 * 1024 * 1024);
        physical_page_array[i].next = free_list_head;
        physical_page_array[i].prev = NULL;

        if (free_list_head != NULL) {
          free_list_head->prev = &physical_page_array[i];
        }
        free_list_head = &physical_page_array[i];
      }
    }

	//function to allocate pages to mem
    struct ppage *allocate_physical_pages(unsigned int npages) {
      if (npages == 0) {	//invalid request
        return NULL;
      }

      struct ppage *allocd_list = NULL;
      struct ppage *current = free_list_head;

      for (unsigned int i = 0; i < npages; i++) {
        if (current == NULL) {
	  if(allocd_list != NULL) {
	    free_allocated_pages(allocd_list);
	  }
          return NULL;
        }
	//unlink from free list
        if (current->prev != NULL) {
	  current->prev->next = current->next;
        } else {
	  free_list_head = current->next;	//at head of list
        }

        if (current->next != NULL) {
	  current->next->prev = current->prev;
        }
	//add to allocated list
        current->next = allocd_list;
        if(allocd_list != NULL) {
	  allocd_list->prev = current;
        }

        allocd_list = current;
        allocd_list->prev = NULL;	//new head of allocated list
	//move to next page
        current = current->next;

      }
      return allocd_list;	//return list of allocated pages
    }


	//function to free physical pages from mem
    void free_physical_pages(struct ppage *ppage_list) {
      struct ppage *current = ppage_list;

      while (current != NULL) {
	struct ppage *next_page = current->next;	//store the next page
	//link back to free list
        current->next = free_list_head;
        current->prev = NULL;

        if (free_list_head != NULL) {
	   free_list_head->prev = current;	//update prev pointer to new head
        }
	free_list_head = current;	//update head to new free page

	current = next_page;	//move to next allocated page
      }
    }




/*
Sources Used:

https://wiki.osdev.org/Writing_A_Page_Frame_Allocator

*/
