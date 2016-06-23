#include "type.h"
#include "const.h"
#include "protect.h"
#include "tty.h"
#include "console.h"
#include "string.h"
#include "proc.h"
#include "global.h"
#include "proto.h"

void TestA()
{

	int i = 0;
	while (1) {
        for(i=0;i<100;i++){
		printf_A("%x ",i);

		milli_delay(1000);}
	}
}


void TestB()
{
	int i = 0x1000;
	while(1){
		printf_B("proc2 ");

		milli_delay(1000);
	}
}


void TestC()
{
	int i = 0x2000;
	while(1){
		printf_C("proc3 ");

		milli_delay(1000);
	}
}
