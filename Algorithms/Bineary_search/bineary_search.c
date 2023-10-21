/*
 * bineary_search.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Shaimaa Gamal
 */

#include "std_types.h"
#include "bineary_search.h"
uint8 Bineary_search(uint8* arr, uint8 size, uint8 num)
{
	uint8 low = 0;
	uint8 high = size - 1;
	uint8 mid = (low + high) / 2;
	uint8 index ;
	while(high >=low)
	{
		mid = (low + high) / 2;
		if (arr[mid] > num)
		{
			high = mid - 1;


		}
		else if (arr[mid] < num)
		{
			low = mid + 1;


		}
		else if (arr[mid] == num)
		{
			index = mid;
			break;
		}

	}
	if (low > high)
	{
		printf("Element Doesn't Exist");
		index = 255;
	}

	return index;

}
