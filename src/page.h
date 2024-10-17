#ifndef __PAGE_H__
#define __PAGE_H__

#include "list.h"

    struct ppage {
      struct ppage *next;
      struct ppage *prev;
      void *physical_addr;

    };


    void int_pfa_list(void);
    struct ppage *allocate_physical_pages(unsigned int npages);
    void free_physical_pages(struct ppage *ppage_list);


#endif
