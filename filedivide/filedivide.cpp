#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc,char* argv[])
{
	char buf;
	char name[3];
	int count=0;
	int size;
	int temp;
	int exit=0;
	FILE* fp;
	FILE* fp1;
	
	switch(argc)
	{
	case 1:
		printf("filedivide             ---2011 by VinerL ----\n");
		printf("enter \"filedivide filename\" to divide file\nenter \"filedivide part1 part2...\" to put them together\n");
		
		break;
	case 2:
		printf("filedivide             ---2011 by VinerL ----\n");
		printf("enter the size of each part(Mb):\n");
		scanf("%d",&size);
		fp=fopen(argv[1],"rb");

		
		while(1)
		{
			temp=0;
			count++;
			itoa(count,name,10);
			fp1=fopen(name,"wb");
			while(temp<size*1024*1024)
			{
				if(fread(&buf,1,1,fp))
				{
					fwrite(&buf,1,1,fp1);
				}
				else
				{
					exit=1;
					break;
				}
				temp++;
			}

			if(exit==1)
			{
				printf("\nsuccess!\n");
				break;
			}

		}
		break;
	default:
		printf("filedivide             ---2011 by VinerL ----\n");
		fp=fopen("final","wb");
		for(int i=1;i<=argc-1;i++)
		{
			itoa(i,name,10);
			fp1=fopen(name,"rb");
			while(fread(&buf,1,1,fp1))
			{
				fwrite(&buf,1,1,fp);
			}
		}
		printf("\nsuccess!\n");


		break;
	}



	return 0;
}
