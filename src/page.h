#ifndef __PAGE_H__
#define __PAGE_H__



    struct ppage {
      struct ppage *next;
      struct ppage *prev;
      void *physical_addr;

    };


#endif
