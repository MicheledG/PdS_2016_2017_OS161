#include <addrspace_info.h>

void print_segment_info (int nsegment, vaddr_t vbase, paddr_t pbase, size_t npages) {

	kprintf("\n================\n");
	kprintf("SEGMENT #%02d INFO:\n", nsegment);
	kprintf("segment logical base address: 0x%08x\n", vbase);
	kprintf("segment physical base address: 0x%08x\n", pbase);		
	kprintf("segment nr. pages: %d\n", npages);
	int size = npages * PAGE_SIZE;		
	kprintf("segment size: %d\n", size);
	kprintf("================\n");		

	return;
}

void print_stack_info (paddr_t stackpbase) {
	
	kprintf("\n================\n");
	kprintf("STACK INFO:\n");
	kprintf("stack base physical base address: 0x%08x\n", stackpbase);		
	kprintf("================\n");		

	return;

}
