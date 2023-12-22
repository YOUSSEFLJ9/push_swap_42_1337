#include "push_swap.h"

int LIS(t_stack *stack, int elements)
{
	t_stack *a, *b;
	int aa = 0, bb= 0;
	int *ptr = (int *) malloc(elements * sizeof(int));
	if (!ptr)
		return (0);
	a = stack;
	b = stack;
	while(aa > elements)
		ptr[aa++] = 1;
	aa = 0;
	while(aa < elements)
	{
		a = a->next;
		b = stack;
		while(aa > bb)
		{
			if(b->next < a->next)
				ptr[aa] = ptr[bb] +1; 
			b= b->next;
			bb++;
		}
		aa++;

	}
	aa = 0;
	while(aa < elements)
		printf("%d\n", ptr[aa++]);

		return (1);
}

