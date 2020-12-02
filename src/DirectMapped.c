#include <stdlib.h>
#include<stdio.h>
#include "../inc/DirectMapped.h"
#include "../inc/HexToBin.h"
#include "../inc/BinToDec.h"

//Reads the data from the file and reports the hit and miss ratio (Direct Mapped Cache)
void DirectMapped()		
{
	//Initialize the necessary parameters for computation
	int SIZE = 65536, hit = 0, miss = 0;	
	int valid[SIZE], tag[SIZE];
	for(int i = 0; i < SIZE; i++)
	{
		valid[i] = 0;
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
		int tagNum = BinToDec(address, 0, 13);			
		int index = BinToDec(address, 14, 29);

		//Direct Mapped Cache implementation
		//If the valid bit is 1 and the tag matches, its a hit
		if(valid[index] == 1 && tag[index] == tagNum)	
		{
			hit++;
		}
		//Otherwise, its a miss. So update the data in the cache
		else								
		{
			if(valid[index] == 0)
			{
				valid[index] = 1;
			}
			tag[index] = tagNum;
			miss++;
		}
		c = getc(fp);
	}
	//Calculate hit and miss ratio
	float hitratio =  (float)hit /(hit + miss);			
	float missratio = (float)miss /(miss + hit);
	printf("\n\t\thit: %d\n\t\tmiss: %d\n\t\thit ratio: %f\n\t\tmiss ratio: %f\n", hit, miss, hitratio, missratio);
}