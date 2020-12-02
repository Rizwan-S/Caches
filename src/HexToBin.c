#include "../inc/HexToBin.h"
#include <stdlib.h>

//Utility function for converting hex to binary
int FillInBin(char arr[], int j, char a, char b, char c, char d)	
{
	arr[j++] = a;
	arr[j++] = b;
	arr[j++] = c;
	arr[j++] = d;
	return j;
}

//Function to convert hexadecimal to binary
char *HexToBin(char hex[])					
{
	char* bin = (char*)malloc(32*sizeof(char));
	int j = 0;
	for(int i = 0; i < 8; i++)
	{
		switch(hex[i])							
		{
			case '0':
				j = FillInBin(bin, j, '0', '0', '0', '0');
				break;
			case '1':
				j = FillInBin(bin, j, '0', '0', '0', '1');
				break;
			case '2':
				j = FillInBin(bin, j, '0', '0', '1', '0');
				break;
			case '3':
				j = FillInBin(bin, j, '0', '0', '1', '1');
				break;
			case '4':
				j = FillInBin(bin, j, '0', '1', '0', '0');
				break;
			case '5':
				j = FillInBin(bin, j, '0', '1', '0', '1');
				break;	
			case '6':
				j = FillInBin(bin, j, '0', '1', '1', '0');
				break;
			case '7':
				j = FillInBin(bin, j, '0', '1', '1', '1');
				break;
			case '8':
				j = FillInBin(bin, j, '1', '0', '0', '0');
				break;
			case '9':
				j = FillInBin(bin, j, '1', '0', '0', '1');
				break;
			case 'a':
				j = FillInBin(bin, j, '1', '0', '1', '0');
				break;
			case 'b':
				j = FillInBin(bin, j, '1', '0', '1', '1');
				break;
			case 'c':
				j = FillInBin(bin, j, '1', '1', '0', '0');
				break;
			case 'd':
				j = FillInBin(bin, j, '1', '1', '0', '1');
				break;
			case 'e':
				j = FillInBin(bin, j, '1', '1', '1', '0');
				break;
			case 'f':
				j = FillInBin(bin, j, '1', '1', '1', '1');
				break;	
		}
	}
	return bin;
}