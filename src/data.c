#include "data.h"
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>

struct
queue create_queue()
{
	struct queue data;

	data.elements = 0;
	data.first = data.last = NULL;

	return data;
}

void
add_element_queue(struct queue *q, u_int8_t x, u_int8_t y)
{
	struct q_data *element = malloc(sizeof(struct q_data));
	element->x = x;
	element->y = y;
	element->next = NULL;

	if (q->elements > 0)
		q->last->next = element;
	else
		q->first = element;

	q->last = element;
	++q->elements;
}

void
delete_element(struct queue *q)
{
	struct q_data *element = q->first;
	q->first = q->first->next;
	--q->elements;
	free(element);
}

struct q_data*
read_element(struct queue *q)
{
	return q->first;
}

u_int8_t
q_empty(struct queue *q)
{
	return (q->elements == 0);
}
