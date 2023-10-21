/*
 * Linear_search.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Shaimaa Gamal
 */

#include "Linear_search.h"
uint8 linear_search(uint8 * arr,uint8 size,uint8 num)
{
	int index=0;
	for(uint8 i=0;i<size;i++)
	{
		if(arr[i]==num)
			break;
	}
	return index;
}
