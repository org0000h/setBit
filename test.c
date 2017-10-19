/*
 * test.c
 *
 *  Created on: 2017��5��10��
 *      Author: asia
 */
#include <stdio.h>
#include "setBit.h"

int main(){
	unsigned short reg=9;
	int b=0,c=0;
	b=setBit(&reg,3,sizeof(reg),0);
	c=getBit(&reg,3,sizeof(reg));
	printf("b=%d\n",b);
	printf("c=%d\n",c);
	printf("reg=%d\n",reg);
	return 0;
}
