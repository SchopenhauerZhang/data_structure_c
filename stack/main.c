/*
 * Copyright (C) schopenhauerzhang
 * Copyright (C) schopenhauerzhang, Inc.
 */
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

int get(){
	return 1;
}

int main(int argc,char ** argv){
	printf("main\n");
	printf("argc : %d\n",argc);
	printf("argv:%s\n",argv[0]);
	printf("argv:%d\n",atoi(argv[1]));
	stack(atoi(argv[1]));
	get();
	return 0;
}