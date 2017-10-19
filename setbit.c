/*
 * setbit.c
 *
 *  Created on: 2017.5.10
 *      Author: asia
 */

#include <stdio.h>

/*
 @function brief :
 @parameter in   :
 @parameter out:
 @return               :
 @author              :  asia
 @date                  : 2017年10月19日
 @time                  : 下午11:27:22
 */

int setBit(void *reg,int pos,int length,char val) {
	unsigned char 		length8 = 1;
	unsigned short 		length16 = 1;
	unsigned int  		length32 = 1;
	unsigned long long 	length64 = 1;

	if (val != 1 && val != 0) {
		return -9;
	}
	if (reg == NULL){
		return -7;
	}
	if (pos<0 || pos > 8*sizeof(length)){
		return -6;
	}

	if (val == 1) {
	switch (length) {
			case 1 :
				if(pos < 8){
					length8 = length8 << pos;
					*(unsigned char *)reg |= length8;
					return 0;}
				else
					return -1;
			break;
			case 2 :
					if(pos < 16){
						length16 = length16 << pos;
						*(unsigned short *)reg |= length16;
						return 0;}
					else
						return -2;
			break;
			case 4 :
					if(pos < 32){
						length32 = length32 << pos;
						*(unsigned int *)reg |= length32;
						return 0;}
					else
						return -3;
			break;
			case 8 :
					if(pos < 64){
						length64 = length64 << pos;
						*(unsigned long long *)reg |= length64;
						return 0;}
					else
						return -4;
			break;
			default :
				return -5;
		}
	}
	if(val == 0){
		switch(length)
			{
				case 1 :
					if(pos < 8){
						length8 = length8 << pos;
						length8 = ~length8;
						*(unsigned char *)reg &= length8;
						return 0;}
					else
						return -1;
				break;
				case 2 :
						if(pos < 16){

							length16 = length16 << pos;
							length16 = ~length16;
							*(unsigned short *)reg &= length16;
							return 0;}
						else
							return -2;
				break;
				case 4 :
						if(pos < 32){
							length32 = length32 << pos;
							length32 = ~length32;
							*(unsigned int *)reg &= length32;
							return 0;}
						else
							return -3;
				break;
				case 8 :
						if(pos < 64){
							length64 = length64 << pos;
							length64 = ~length64;
							*(unsigned long long *)reg &= length64;
							return 0;}
						else
							return -4;
				break;
				default :
					return -5;
			}
	}
	return 255; //shouldn't get here
}

/*
 @function brief  :
 @parameter in   :
 @parameter out:
 @return               :
 @author              :  asia
 @date                  : 2017年10月19日
 @time                  : 下午11:26:24
 */

int getBit(void *reg,int pos,int length)
{
	unsigned char 		length8 = 1;
	unsigned short 		length16 = 1;
	unsigned int  		length32 = 1;
	unsigned long long 	length64 = 1;

	if(reg == NULL)
		return -7;
	if (pos<0 || pos > 8*sizeof(length)){
			return -6;
		}

	switch(length)
	{
		case 1 :
			if(pos < 8){
				length8 = length8 << pos;
				length8 &= *(unsigned char *)reg;
				length8 = length8 >> pos;
				return length8;}
			else
				return -1;
		break;
		case 2 :
				if(pos < 16){
					length16 = length16 << pos;
					length16 &= *(unsigned short *)reg;
					length16 = length16 >> pos;
					return length16;}
				else
					return -2;
		break;
		case 4 :
				if(pos < 32){
					length32 = length32 << pos;
					length32 &= *(unsigned int *)reg;
					length32 = length32 >> pos;
					return length32;}
				else
					return -3;
		break;
		case 8 :
				if(pos < 64){
					length64 = length64 << pos;
					length64 &= *(unsigned long long *)reg;
					length64 = length64 >> pos;
					return length64;}
				else
					return -4;
		break;
		default :
			return -5;
	}
	return 255; // shouldn't get here
}

