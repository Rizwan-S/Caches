#include <stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include "../inc/SetAssociative.h"
#include "../inc/HexToBin.h"
#include "../inc/BinToDec.h"


//Reads the data from the file and reports the hit and miss ratio (4 way set associative Cache)
void SetAssociative()			
{
	//Initialize the necessary parameters for computation
	int SIZE = 16384, hit = 0, miss = 0;				
	int valid[SIZE][4], tag[SIZE][4];

	for(int i = 0; i < SIZE; i++)		
	{
		for(int j = 0; j < 4; j++)
		{
			valid[i][j] = 0;
		}
	}

	char buff[15], hex[10];
	int c = getc(fp);

	//Compute the following operations till end of file
	while(c != EOF)								
	{
		int temp = 0;

		//In this loop, take input char by char and store in in a char array (store a line in an array)
		while(c != '\n' && c != EOF)		
		{
			buff[temp++] = c;			
			c = getc(fp);
		}
		
		//Consider only the hexadecimal part of the line
		for(int i = 0; i < 8; i++)			
		{	
			hex[i] = buff[4 + i];
		}

		char* address;
		//Get the memory address in binary form	
		address = HexToBin(hex);			

		//Find the tag and index from the address
		int tagNum = BinToDec(address, 0, 15);			
		int index = BinToDec(address, 16, 29);

		int pos = -1;
		bool present = false;

		//For set associative, each row is assumed to be a priority queue (PRIORITY IS BASED ON LRU POLICY)
		//Check if the tag is present or not
		for(int i = 0; i < 4; i++)					
		{
			if(valid[index][i] == 1 && tag[index][i] == tagNum)
			{
				hit++;
				present = true;
				pos = i;			//Store the index of the tag		
				break;
			}
		}
		//If the tag is present, put it at the end of the queue and update its priority
		if(present == true)			
		{
			//If the queue is full, shift some elements and move the tag to the end of the queue
			if(valid[index][3] == 1)			
			{
				for(int i = pos; i< 3; i++)
				{
					tag[index][i] = tag[index][i+1];
				}
				tag[index][3] = tagNum;
			}
			//If the queue is not full, put the tag at the end of the queue after shifting some elements in the queue
			else
			{
				for(int i = pos; i < 3; i++)	
				{
					if(valid[index][i+1] == 1)
					{
						tag[index][i] = tag[index][i+1];
					}
					else
					{
						tag[index][i] = tagNum;
						break;
					}
				}
			}
		}
		//If the tag is not present, insert the tag at the end of the queue
		else					
		{
			//If the queue is full, remove the first element and put the tag at the end after shifting all the elements
			if(valid[index][3] == 1)	
			{
				for(int i = 0; i < 3; i++)
				{
					tag[index][i] = tag[index][i+1];
				}
				tag[index][3] = tagNum;
			}
			else
			{
				//If the queue is not full, insert the tag at the end of the queue
				for(int i = 0; i < 4; i++)		
				{
					if(valid[index][i] == 0)
					{
						valid[index][i] = 1;
						tag[index][i] = tagNum;
						break;
					}
				}
			}
			miss++;
		}
		c = getc(fp);
	}

	//Find hit and miss ratio
	float hitratio =  (float)hit /(hit + miss);			
	float missratio = (float)miss /(miss + hit);
	printf("\n\t\thit: %d\n\t\tmiss: %d\n\t\thit ratio: %f\n\t\tmiss ratio: %f\n", hit, miss, hitratio, missratio);
}
