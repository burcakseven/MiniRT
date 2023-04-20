#include "gc.h"
#include <stdlib.h>
#include <parser/scene.h>

struct s_allocated {
	void *data;
	struct s_allocated *next;
	struct s_allocated *prev;
};

typedef struct s_allocated t_allocated;

static t_allocated *get_allocated_datas() {
	static t_allocated allocateds = { NULL, NULL, NULL };
	return &allocateds;
}

static t_allocated *create_new_node(void *data) {
	t_allocated *node = (t_allocated *)malloc(sizeof(t_allocated));
	if (node == NULL)
		return NULL;
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

//static void append(void *data) {
//	t_allocated *datas = get_allocated_datas();
//	t_allocated *next = create_new_node(data);
//	if (next == NULL)
//		ft_error();
//	if (datas->next == NULL) {
//		datas->next = next;
//		datas->prev = NULL;
//	} else {
//		next->prev = datas->prev;
//		datas->prev->next = next;
//		datas->prev = next;
//	}
//}

static void append(void *data) {
    t_allocated *datas = get_allocated_datas();
    t_allocated *new = create_new_node(data);
    if (new == NULL)
        ft_error();
    if (datas->next == NULL) {
        datas->next = new;
    } else {
        new->next = datas->next;
		datas->next->prev = new;
		datas->next = new;
    }
}

void *new(size_t size) {
	void *data = malloc(size);
	if (data == NULL)
		ft_error();
	append(data);
	return data;
}

//void del(void *ptr) {
//	t_allocated *datas = get_allocated_datas()->next;
//	while (datas != NULL) {
//		if (datas->data == ptr) {
//			if (datas->prev == NULL) {
//				datas->next = datas->next->next;
//				if (datas->next)
//					datas->next->prev = NULL;
//			} else {
//				datas->prev->next = datas->next;
//				if (datas->next)
//					datas->next->prev = datas->prev;
//			}
//			free(datas);
//			break;
//		}
//		datas = datas->next;
//	}
//}

void del(void *ptr) {
    t_allocated *datas = get_allocated_datas()->next;
    while (datas != NULL) {
        if (datas->data == ptr) {
            if (datas->prev == NULL) {
                get_allocated_datas()->next = datas->next;
                if (datas->next)
                    datas->next->prev = NULL;
            } else {
                datas->prev->next = datas->next;
                if (datas->next)
                    datas->next->prev = datas->prev;
            }
            free(datas->data);
            free(datas);
            break;
        }
        datas = datas->next;
    }
}

void garbage_collect() {
	t_allocated *datas = get_allocated_datas()->next;
	while (datas) {
		t_allocated *next = datas->next;
		free(datas->data);
		free(datas);
		datas = next;
	}
	get_allocated_datas()->next = NULL;
	get_allocated_datas()->prev = NULL;
}
