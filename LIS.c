#include "push_swap.h"

int max(int a, int b)
{
	if(a > b)
		return (a);
	return(b);
}
int max_arr(int *ptr, int len)
{
	int	max;
	int	i;
	
	max = 0;
	i = 0;
	while(i < len)
	{
		if(max < ptr[i])
			max = ptr[i];
		i++;
	}
	return (max);
}

void belon_to_lis(t_stack *stack_a, int *ptr, int len)
{
	int		max;
	t_stack	*node;
	
	max = max_arr(ptr, len);
	while(--len >= 0)
	{
		if(ptr[len] == max && max >= 0)
		{
			node = stack_a;
			while(node)
			{
				if(node->index == len)
				{
					node->lis = 1;
					break;
				}
				node = node->prev;
			}
			max--;
		}

	}
}
int LIS(t_stack *stack, int elements)
{
	t_stack *a;
	t_stack *b;
	int i = 0; 
	int j;
	int *ptr = (int *) malloc(elements * sizeof(int));
	if (!ptr)
		return (0);
	a = stack;
	b = stack;
	while(i < elements)
		ptr[i++] = 1;
	i = 1;
	while((i < elements) && a->next)
	{
		a = a->next;
		b = stack;
		j = 0;
		while(i > j)
		{
			if(b->num < a->num)
				ptr[i] = max(ptr[j] +1, ptr[i]);
			b= b->next;
			j++;
		}
		i++;
	}
	belon_to_lis(a, ptr, elements);
	 i =0;
	 free(ptr);
	printf("\n----------------------------------\n");
	while(i < elements)
		printf("%d\n", ptr[i++]);
	printf("\n----------------------------------\n");
	return (0);

}
