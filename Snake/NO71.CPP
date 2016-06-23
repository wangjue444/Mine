#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include "resource.h"
#define NORTH 1
#define WEST 2
#define EAST 3
#define SOUTH 4
#define SIZE 11



LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;
LRESULT CALLBACK DiaProc (HWND hDia, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK DiaProc2 (HWND hDia, UINT message, WPARAM wParam, LPARAM lParam);

int start=0;
int pause=0;
HINSTANCE hInstance_globe;
HWND hwnd_globe;

int item=0;

int sign=0;
int L_x=0;
int L_y=0;
int speed=0;
int timelimit=20;
int timelimit1=20;
int timelimit2=20;
int timelimitn1=40;
int timelimitn2=40;
HDC hdc_globle;
HDC mdc;
HDC buf;
HDC tem;
HBITMAP bufBitmap;
HBITMAP bg=(HBITMAP)LoadImage(NULL,TEXT("bitmap12.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
HBITMAP welcome=(HBITMAP)LoadImage(NULL,TEXT("bitmap11.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
DWORD t_now=NULL,t_pre=NULL;



typedef struct _N
{
	int state;
	int staten;
	int NO;
	LPCTSTR num;
	POINT now;
	int direct;
	HBITMAP snack;
	_N* till;
	_N* pre;
	_N* next;
}Snack,*Snack_ptr;



Snack_ptr aa;
Snack_ptr bb;
Snack_ptr bb1;
Snack_ptr bb2;
Snack_ptr cc;
Snack_ptr tt;
Snack_ptr tt1;

void Snack_Init(Snack_ptr &S)
{
	S=(Snack_ptr)malloc(sizeof(Snack));
	S->snack=(HBITMAP)LoadImage(NULL,TEXT("bitmap3.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
	S->now.x=0;
	S->now.y=0;
	S->state=0;
	S->direct=EAST;
	S->next=NULL;
	S->pre=NULL;
	S->till=S;
}

void Prize_Init(Snack_ptr &S)
{
	S=(Snack_ptr)malloc(sizeof(Snack));
	S->snack=(HBITMAP)LoadImage(NULL,TEXT("bitmap4.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
	S->now.x=0;
	S->now.y=0;
	S->direct=EAST;
	S->next=NULL;
	S->till=S;
}


void Snack_Add(Snack_ptr &S)
{
	S->till->next=(Snack_ptr)malloc(sizeof(Snack));
	S->till->next->pre=S->till;
	if(S->till->NO==1)
	S->till->next->snack=(HBITMAP)LoadImage(NULL,TEXT("bitmap1.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
	else
	S->till->next->snack=(HBITMAP)LoadImage(NULL,TEXT("bitmap5.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
	S->till->next->NO=S->till->NO;
	S->till->next->direct=S->till->direct;
	switch(S->till->direct)
	{
	case EAST:
		S->till->next->now.x=S->till->now.x-SIZE;
		S->till->next->now.y=S->till->now.y;
		break;
	case WEST:
		S->till->next->now.x=S->till->now.x+SIZE;
		S->till->next->now.y=S->till->now.y;
		break;
	case NORTH:
		S->till->next->now.x=S->till->now.x;
		S->till->next->now.y=S->till->now.y+SIZE;
		break;
	case SOUTH:
		S->till->next->now.x=S->till->now.x;
		S->till->next->now.y=S->till->now.y-SIZE;

	
	}
	
	S->till=S->till->next;
	S->till->next=NULL;
}

void Snack_Delete(Snack_ptr &S)
{
	Snack_ptr p;
	Snack_ptr q;
	p=S;
	q=S->next;
	while(q)
	{
		free(p);
		p=q;
		q=q->next;
	}
	free(p);
	S=NULL;

}


void Restart()
{
	speed=0;
	Snack_Delete(aa);
	Snack_Delete(cc);
	aa=NULL;
	Snack_Init(aa);
	tt=aa;
	aa->NO=1;
	aa->num="ÂÌÉßÊ§°Ü";
	aa->state=0;
	aa->staten=0;

	
	for(int i=0;i<20;i++)
		Snack_Add(aa);
	cc=NULL;
	Snack_Init(cc);
	tt1=cc;
	cc->NO=2;
	cc->num="À¶ÉßÊ§°Ü";
	cc->state=0;
	cc->staten=0;
	cc->now.x=0;
	cc->now.y=550;
	
	for(int i=0;i<20;i++)
		Snack_Add(cc);
	sign=0;
	



	item=0;

	 sign=0;
	 L_x=0;
	 L_y=0;
	 speed=0;
	 timelimit=20;
	timelimit1=20;
	 timelimit2=20;
	 timelimitn1=40;
	timelimitn2=40;
}

void Snack_Show1(Snack_ptr &S,Snack_ptr &S1)
{

	HDC mdc;
	mdc=CreateCompatibleDC(hdc_globle);

	BitBlt(hdc_globle,0,0,800,600,buf,0,0,SRCCOPY);
	Snack_ptr p;
	Snack_ptr q;
	p=S;
	q=S1;
	while(p)
	{
		SelectObject(mdc,p->snack);
		BitBlt(hdc_globle,p->now.x,p->now.y,800,600,mdc,0,0,SRCCOPY);
		p=p->next;
	}
	while(q)
	{
		SelectObject(mdc,q->snack);
		BitBlt(hdc_globle,q->now.x,q->now.y,800,600,mdc,0,0,SRCCOPY);
		q=q->next;
	}
	DeleteObject(mdc);

}

void Prize_Show(Snack_ptr &P,Snack_ptr &P1,Snack_ptr &P2)
{
	HDC mdc;
	mdc=CreateCompatibleDC(hdc_globle);
	srand(time(NULL));
//	BitBlt(hdc_globle,0,0,800,600,buf,0,0,SRCCOPY);
	if(sign==0)
	{
		int temp;
		temp=rand()%1000;
		if(temp>500)
		{
		
			P->NO=4;
			P->snack=(HBITMAP)LoadImage(NULL,TEXT("bitmap6.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
		}
		else if(temp<=500&&temp>400)
		{
		
			P->NO=3;
			P->snack=(HBITMAP)LoadImage(NULL,TEXT("bitmap4.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
		}
		else if(temp<=400&&temp>200)
		{
			P->NO=5;
			P->snack=(HBITMAP)LoadImage(NULL,TEXT("bitmap7.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
		}
		else if(temp<=200&&temp>100)
		{
			P->NO=6;
			P->snack=(HBITMAP)LoadImage(NULL,TEXT("bitmap8.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
		}
		else if(temp<=100)
		{
			P->NO=7;
			P->snack=(HBITMAP)LoadImage(NULL,TEXT("bitmap9.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);

		}
	
		temp=rand()%1000;
		if(temp>500)
		{
			P1->NO=4;
			P1->snack=(HBITMAP)LoadImage(NULL,TEXT("bitmap6.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
		}
		else if(temp<=500&&temp>400)
		{
		
			P1->NO=3;
			P1->snack=(HBITMAP)LoadImage(NULL,TEXT("bitmap4.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
		}
		else if(temp<=400&&temp>200)
		{
			P1->NO=5;
			P1->snack=(HBITMAP)LoadImage(NULL,TEXT("bitmap7.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
		}
		else if(temp<=200&&temp>100)
		{
			P1->NO=6;
			P1->snack=(HBITMAP)LoadImage(NULL,TEXT("bitmap8.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
		}
		else if(temp<=100)
		{
			P1->NO=7;
			P1->snack=(HBITMAP)LoadImage(NULL,TEXT("bitmap9.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);

		}
		temp=rand()%1000;
		if(temp>500)
		{
			P2->NO=4;
			P2->snack=(HBITMAP)LoadImage(NULL,TEXT("bitmap6.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
		}
		else if(temp<=500&&temp>400)
		{
		
			P2->NO=3;
			P2->snack=(HBITMAP)LoadImage(NULL,TEXT("bitmap4.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
		}
		else if(temp<=400&&temp>200)
		{
			P2->NO=5;
			P2->snack=(HBITMAP)LoadImage(NULL,TEXT("bitmap7.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
		}
		else if(temp<=200&&temp>100)
		{
			P2->NO=6;
			P2->snack=(HBITMAP)LoadImage(NULL,TEXT("bitmap8.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
		}
		else if(temp<=100)
		{
			P2->NO=7;
			P2->snack=(HBITMAP)LoadImage(NULL,TEXT("bitmap9.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);

		}
		P->now.x=SIZE*(rand()%71);
		P->now.y=SIZE*(rand()%52);
		P1->now.x=SIZE*(rand()%71);
		P1->now.y=SIZE*(rand()%52);
		P2->now.x=SIZE*(rand()%71);
		P2->now.y=SIZE*(rand()%52);
		sign=1;
	}
	SelectObject(mdc,P->snack);
	BitBlt(hdc_globle,P->now.x,P->now.y,800,600,mdc,0,0,SRCCOPY);
	SelectObject(mdc,P1->snack);
	BitBlt(hdc_globle,P1->now.x,P1->now.y,800,600,mdc,0,0,SRCCOPY);
		SelectObject(mdc,P2->snack);
	BitBlt(hdc_globle,P2->now.x,P2->now.y,800,600,mdc,0,0,SRCCOPY);
	
	DeleteObject(mdc);
}




void Snack_Move1(Snack_ptr &S)
{
	int pace=SIZE;
	Snack_ptr p;
	Snack_ptr q;
	q=S->till;
	p=S->till;
	if(speed)
	{
		pace*=3;
	}
	if(S->state==1)
	{
		pace*=2;
	}
	while(p->pre!=NULL)
	{
		p->now.x=p->pre->now.x;
		p->now.y=p->pre->now.y;
		p=p->pre;
	}
	

			if(p->direct==NORTH)
			{
				p->now.y-=pace;
				if(p->now.y<0)
				{
					MessageBox(hwnd_globe,S->num,"×²ËÀÁË",MB_OK);
					Restart();
					//SendMessage(hwnd_globe,WM_CLOSE,0,0);
					//p->now.y=600-SIZE;
				}

			}
			else if(p->direct==WEST)
			{
				p->now.x-=pace;
				if(p->now.x<0)
				{
					MessageBox(hwnd_globe,S->num,"×²ËÀÁË",MB_OK);
					Restart();
					//SendMessage(hwnd_globe,WM_CLOSE,0,0);
				}
					//p->now.x=800-SIZE;
			}
			else if(p->direct==SOUTH)
			{
				p->now.y+=pace;
				if(p->now.y>600-SIZE)
				{
						MessageBox(hwnd_globe,S->num,"×²ËÀÁË",MB_OK);
						Restart();
					//SendMessage(hwnd_globe,WM_CLOSE,0,0);
				}
				//	p->now.y=0;
			}
			else if(p->direct==EAST)
			{
				p->now.x+=pace;
				if(p->now.x>800-SIZE)
				{
						MessageBox(hwnd_globe,S->num,"×²ËÀÁË",MB_OK);
						Restart();
					//SendMessage(hwnd_globe,WM_CLOSE,0,0);
				}
				//	p->now.x=0;
			}
			
	
	
}
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow)
{
	

	static TCHAR szAppName[] = TEXT ("HelloWin") ;
	HWND	hwnd ;
	MSG	msg ;
	WNDCLASS	wndclass ;
       
 	wndclass.style		  = CS_HREDRAW | CS_VREDRAW ;
 	wndclass.lpfnWndProc  = WndProc ;
	wndclass.cbClsExtra	  = 0 ;
	wndclass.cbWndExtra	  = 0 ;
	wndclass.hInstance	  = hInstance ;
	//wndclass.hIcon		  = LoadIcon (NULL, IDI_APPLICATION) ;
	wndclass.hIcon		  = LoadIcon (NULL, MAKEINTRESOURCE(IDI_ICON1)) ;
  	wndclass.hCursor	  = LoadCursor (NULL, IDC_ARROW) ;
 	wndclass.hbrBackground	= (HBRUSH) GetStockObject (BLACK_BRUSH) ;
  	wndclass.lpszMenuName	= NULL ;
	wndclass.lpszClassName	= szAppName ;
      
	if (!RegisterClass (&wndclass))
     {
			MessageBox (	NULL, TEXT ("This program requires Windows NT!"), 
          				szAppName, MB_ICONERROR) ;
		return 0 ;
     }
     
	hwnd = CreateWindow( szAppName,	
		TEXT ("Î§ÉßÓÎÏ·"),
			WS_OVERLAPPEDWINDOW,	
			CW_USEDEFAULT,	
			CW_USEDEFAULT,	
			800,	
			648,	
			NULL,			
		    NULL,	       
		    hInstance,	  
		    NULL) ; 	   
    
	ShowWindow (hwnd, iCmdShow) ;
	UpdateWindow (hwnd) ;
	

		hInstance_globe=hInstance;
		HMENU hMenu;
		hMenu=LoadMenu(hInstance,MAKEINTRESOURCE(IDR_MENU1));
		SetMenu(hwnd,hMenu); 

		 


	




	hdc_globle=GetDC(hwnd);
	mdc=CreateCompatibleDC(hdc_globle);
	buf=CreateCompatibleDC(hdc_globle);
	tem=CreateCompatibleDC(hdc_globle);
	


	hwnd_globe=hwnd;
	Snack_Init(aa);
	aa->num="ÂÌÉßÊ§°Ü";
	aa->NO=1;
	for(int i=0;i<20;i++)
		Snack_Add(aa);
	Snack_Init(cc);
	cc->NO=2;
	cc->num="À¶ÉßÊ§°Ü";
	cc->now.x=0;
	cc->now.y=550;
	for(int i=0;i<20;i++)
		Snack_Add(cc);

	

	Prize_Init(bb);
	Prize_Init(bb1);
	Prize_Init(bb2);
	bb->NO=3;
	bb1->NO=3;
	bb2->NO=3;



	SelectObject(buf,bg);
	
	t_pre=GetTickCount();

	
//	hbmp=aa->next->snack;
  
	while (1)
     {
		 	
		if (PeekMessage(&msg,NULL,0,0,PM_REMOVE))
	   { 
	  
       if (msg.message == WM_QUIT)
           break;
	
	

	   TranslateMessage(&msg);


	   DispatchMessage(&msg);
	   }
		t_now=GetTickCount();
		if(start==0)
		{
				SelectObject(mdc,welcome);
	BitBlt(hdc_globle,0,0,800,600,mdc,0,0,SRCCOPY);
		}

		if(t_now-t_pre>50&&start==1)
		{	
			

					
					if(timelimit>0)
						timelimit--;
					if(timelimit==0)
						speed=0;
					if(timelimit1>0)
						timelimit1--;
					if(timelimit1==0)
						aa->state=0;
					if(timelimit2>0)
						timelimit2--;
					if(timelimit2==0)
						cc->state=0;
					if(timelimitn1>0)
						timelimitn1--;
					if(timelimitn1==0)
					{
						aa->staten=0;
						aa->snack=(HBITMAP)LoadImage(NULL,TEXT("bitmap3.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
					}
					if(timelimitn2>0)
						timelimitn2--;
					if(timelimitn2==0)
					{

						cc->staten=0;
						cc->snack=(HBITMAP)LoadImage(NULL,TEXT("bitmap3.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
					}

			Snack_Move1(aa);

			Snack_Move1(cc);

			Snack_Show1(aa,cc);
			Prize_Show(bb,bb1,bb2);

			if(aa->now.x==bb->now.x&&aa->now.y==bb->now.y||aa->now.x==bb1->now.x&&aa->now.y==bb1->now.y||aa->now.x==bb2->now.x&&aa->now.y==bb2->now.y)
			{
				if(aa->now.x==bb->now.x&&aa->now.y==bb->now.y)
				{
					switch(bb->NO)
					{
					case 3:
						Snack_Add(aa);
						Snack_Add(aa);
						Snack_Add(aa);
						break;
					case 4:
						for(int i=0;i<50;i++)
							Snack_Add(aa);
						break;
					case 5:
						speed=1;
						timelimit=20;
						break;
					case 6:
						aa->state=1;
						timelimit1=60;
						break;
					case 7:
						aa->staten=2;
						aa->snack=(HBITMAP)LoadImage(NULL,TEXT("bitmap9.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
						timelimitn1=80;
						break;
					}
				}
				
				if(aa->now.x==bb1->now.x&&aa->now.y==bb1->now.y)
				{
					int i;
					switch(bb1->NO)
					{
					case 3:
						Snack_Add(aa);
						Snack_Add(aa);
						Snack_Add(aa);
						break;
					case 4:
						for( i=0;i<50;i++)
							Snack_Add(aa);
						break;
					case 5:
						speed=1;
						timelimit=20;
						break;
					case 6:
						aa->state=1;
						timelimit1=60;
						break;
					case 7:
						aa->staten=2;
						aa->snack=(HBITMAP)LoadImage(NULL,TEXT("bitmap9.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
						timelimitn1=80;
						break;
					}
				}
				if(aa->now.x==bb2->now.x&&aa->now.y==bb2->now.y)
				{
					int i;
					switch(bb2->NO)
					{
					case 3:
						Snack_Add(aa);
						Snack_Add(aa);
						Snack_Add(aa);
						break;
					case 4:
						for( i=0;i<50;i++)
							Snack_Add(aa);
						break;
					case 5:
						speed=1;
						timelimit=20;
						break;
					case 6:
						aa->state=1;
						timelimit1=60;
						break;
					case 7:
						aa->staten=2;
						aa->snack=(HBITMAP)LoadImage(NULL,TEXT("bitmap9.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
						timelimitn1=80;
						break;
					}
				}
				sign=0;
			}
			if(cc->now.x==bb->now.x&&cc->now.y==bb->now.y||cc->now.x==bb1->now.x&&cc->now.y==bb1->now.y||cc->now.x==bb2->now.x&&cc->now.y==bb2->now.y)
			{
				if(cc->now.x==bb->now.x&&cc->now.y==bb->now.y)
				{
					switch(bb->NO)
					{
					case 3:
						Snack_Add(cc);
						Snack_Add(cc);
						Snack_Add(cc);
						break;
					case 4:
						for(int i=0;i<50;i++)
							Snack_Add(cc);
						break;
					case 5:
						speed=1;
						timelimit=20;
						break;
					
					case 6:
						cc->state=1;
						timelimit2=60;
						break;
					case 7:
						cc->staten=2;
						cc->snack=(HBITMAP)LoadImage(NULL,TEXT("bitmap9.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
						timelimitn2=80;
						break;
					}
				}
				if(cc->now.x==bb1->now.x&&cc->now.y==bb1->now.y)
				{
					switch(bb1->NO)
					{
					case 3:
						Snack_Add(cc);
						Snack_Add(cc);
						Snack_Add(cc);
						break;
					case 4:
						for(int i=0;i<50;i++)
							Snack_Add(cc);
						break;
					case 5:
						speed=1;
						timelimit=20;
						break;
					
					case 6:
						cc->state=1;
						timelimit2=60;
						break;
					case 7:
						cc->staten=2;
						cc->snack=(HBITMAP)LoadImage(NULL,TEXT("bitmap9.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
						timelimitn2=80;
						break;
					}
				}
				if(cc->now.x==bb2->now.x&&cc->now.y==bb2->now.y)
				{
					switch(bb2->NO)
					{
					case 3:
						Snack_Add(cc);
						Snack_Add(cc);
						Snack_Add(cc);
						break;
					case 4:
						for(int i=0;i<50;i++)
							Snack_Add(cc);
						break;
					case 5:
						speed=1;
						timelimit=20;
						break;
					
					case 6:
						cc->state=1;
						timelimit2=60;
						break;
					case 7:
						cc->staten=2;
						cc->snack=(HBITMAP)LoadImage(NULL,TEXT("bitmap9.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
						timelimitn2=80;
						break;
					}
				}
				sign=0;
			}
			
			tt=aa;
			tt1=cc;

			if(aa->now.x==cc->now.x&&aa->now.y==cc->now.y)
			{
				MessageBox(hwnd,"Í¬¹éÓÚ¾¡","Í¬¹éÓÚ¾¡",MB_OK);
				Restart();
			}
			while(tt->next)
			{
				tt=tt->next;
				if(aa->staten!=2)
				{

					if(aa->now.x==tt->now.x&&aa->now.y==tt->now.y)
					{
							MessageBox(hwnd,"ÂÌÉßÊ§°Ü","ÂÌÉßÊ§°Ü",MB_OK);
							Restart();
					
					}
				}
				if(cc->staten!=2)
				{
					if(cc->now.x==tt->now.x&&cc->now.y==tt->now.y)
					{
							MessageBox(hwnd,"À¶ÉßÊ§°Ü","À¶ÉßÊ§°Ü",MB_OK);
							Restart();
						
					}
				}
			}
			while(tt1->next)
			{
				tt1=tt1->next;
				if(cc->staten!=2)
				{
					if(cc->now.x==tt1->now.x&&cc->now.y==tt1->now.y)
					{
							MessageBox(hwnd,"À¶ÉßÊ§°Ü","À¶ÉßÊ§°Ü",MB_OK);
							Restart();
							
					}
				}
				if(aa->staten!=2)
				{
					if(aa->now.x==tt1->now.x&&aa->now.y==tt1->now.y)
					{
							MessageBox(hwnd,"ÂÌÉßÊ§°Ü","ÂÌÉßÊ§°Ü",MB_OK);
							Restart();
							
					}
				}
			}


			t_pre=t_now;
		}

     }
	return msg.wParam ;
}

LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	HDC	hdc ;
	PAINTSTRUCT ps ;

	
	
	switch (message)
     {
	case 	WM_PAINT:
		hdc = BeginPaint (hwnd, &ps) ;
		
  		EndPaint (hwnd, &ps) ;
		break;

	case WM_COMMAND:
		switch(wParam)
		{
		case ID_40006:
			SendMessage(hwnd,WM_CLOSE,0,0);
			break;
		case ID_40004:
			Restart();
			start=1;
			pause=1;
			break;
		case ID_40009:
			if(pause==0)
				break;
			if(start==0)
				start=1;
			else
				start=0;
			break;

		case ID_40007:
			DialogBox(  hInstance_globe, MAKEINTRESOURCE(IDD_DIALOG1), hwnd_globe,(DLGPROC)DiaProc);
			break;
			
		case ID_40008:
			DialogBox(  hInstance_globe, MAKEINTRESOURCE(IDD_DIALOG2), hwnd_globe,(DLGPROC)DiaProc2);
			break;


		}
		break;
	case WM_KEYDOWN:
		{
			switch(wParam)
			{
				case VK_UP:
				{	
	
					if(aa->direct!=SOUTH&&aa->direct!=NORTH)
					{

						aa->direct=NORTH;

					
					}
				}
				break;
				case VK_DOWN:
				{

					if(aa->direct!=NORTH&&aa->direct!=SOUTH)
					{

						aa->direct=SOUTH;

					
					}
				}break;
				case VK_LEFT:
				{

					if(aa->direct!=EAST&&aa->direct!=WEST)
					{

						aa->direct=WEST;
				
	
					
					}
				}break;
				case VK_RIGHT:
				{

					if(aa->direct!=WEST&&aa->direct!=EAST)
					{

						aa->direct=EAST;
	
					}
					
				}
				break;
				case VK_ESCAPE:
					SendMessage(hwnd,WM_CLOSE,0,0);
					break;




			}
			break;
		}

	case WM_CHAR:
		switch(wParam)
		{
				case 'w':
				{	

					if(cc->direct!=SOUTH&&cc->direct!=NORTH)
					{

						cc->direct=NORTH;
	
					}
				}
				break;
				case 's':
				{
		
					if(cc->direct!=NORTH&&cc->direct!=SOUTH)
					{

						cc->direct=SOUTH;
	
					
					}
				}break;
				case 'a':
				{

					if(cc->direct!=EAST&&cc->direct!=WEST)
					{

						cc->direct=WEST;
				

					
					}
				}break;
				case 'd':
				{

					if(cc->direct!=WEST&&cc->direct!=EAST)
					{
	
						cc->direct=EAST;

					}
					
				}
				break;
			}
		break;



	case	WM_DESTROY:
		PostQuitMessage (0) ;
		return 0 ;
     }
   return DefWindowProc (hwnd, message, wParam, lParam) ;
}

LRESULT CALLBACK DiaProc (HWND hDia, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
		case WM_INITDIALOG:
				return TRUE;

		case WM_COMMAND:
			if (LOWORD(wParam) == IDOK ||LOWORD(wParam)==IDCANCEL) 
			{
				EndDialog(hDia, LOWORD(wParam));
				return TRUE;
			}
			break;
	}
	return FALSE;
}

LRESULT CALLBACK DiaProc2 (HWND hDia, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
		case WM_INITDIALOG:
				return TRUE;

		case WM_COMMAND:
			if (LOWORD(wParam) == IDOK ||LOWORD(wParam)==IDCANCEL) 
			{
				EndDialog(hDia, LOWORD(wParam));
				return TRUE;
			}
			break;
	}
	return FALSE;
}

