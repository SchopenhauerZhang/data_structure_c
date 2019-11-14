/*
 * Copyright (C) schopenhauerzhang
 * Copyright (C) schopenhauerzhang, Inc.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define uint32 int 
#define ulong long 


struct Data {
	uint32 u;
	ulong l;
	double d;
	char * str;
};

struct List {
	struct Data * data;
    struct List * pre;
    struct List * next;
};

struct Stack {
	uint32 size;
	struct List * list;
};

int is_empty_stack(struct Stack * stack){
	printf("stack size %d",stack->size);
	if(stack->size > 0){
		return -1;
	}
	return 1;
}
	
int 
lpush(uint32 add,struct Stack * stack) {
	printf("push : %d,%d\n", add,stack->size);
	if(is_empty_stack(stack) > 0){
    	stack->size = 1;
    	stack->list->data->u = add;
		printf("push : %d,%d\n", add,stack->size);
		printf("push : %d,%d\n", add,stack->list->data->u);
	} else {
		printf("stack size  d");
	}
    return 1;
}

int
rpop(struct Stack * stack) {
	if(is_empty_stack(stack) > 0){
    	
	} else {
		printf("pop : %d,%d\n", stack->list->data->u,stack->size);
	}

	return 1;
}

int 
stack(uint32 add) {
	printf("stack \n");
	struct Stack stack;
	lpush(add,&stack);
	rpop(&stack);
	return 1;
}



