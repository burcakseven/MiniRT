#include "gc.h"

struct s_allocated {
	void *data;
	struct s_allocated *next;
	struct s_allocated *prev;
	struct s_allocated *last;
};

typedef struct s_allocated t_allocated;

static t_allocated *get_allocated_datas(){
	static t_allocated	allocateds;

	return (&allocateds);
}

static void append(void *data)
{
	t_allocated *datas;
	t_allocated *tmp;
	t_allocated *next;

	datas = get_allocated_datas();
	tmp = datas;
	next = (t_allocated *) malloc(sizeof *next);
	if (next == NULL)
		return ;
	next->data = data;
	while (tmp->next && tmp->next->next)
		tmp = tmp->next;
	next->prev = tmp;
	tmp->next = next;
	datas->last = next;
}
void *new(size_t size)
{
	void *data = malloc(size);
	append(data);
	return (data);
}

void del(void *ptr)
{
	t_allocated *datas;

	datas = get_allocated_datas();
	while (datas->next)
	{
		if (datas->data == ptr)
		{
			datas->prev->next = datas->next;
			free(datas->data);
			free(datas);
		}
		datas = datas->next;
	}
}

void garbage_collect()
{
	t_allocated *datas;

	datas = get_allocated_datas()->last;
	while(datas->prev)
	{
		if (datas->prev)
			datas->prev->next = NULL;
		free(datas->data);
		free(datas);
		datas = datas->prev;
	}
}
