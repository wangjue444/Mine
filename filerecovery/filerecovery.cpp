#include <stdio.h>
#include <process.h>

bool picture=0;
bool compress=0;
bool video=0;
bool document=0;
bool handle=0;
int main()
{
	FILE* fp;
	char id[20];
	char temp[20];
	char origin[20];
	char com[100];
	char del[20];
	for(int i=0;i<=3011;i++)
	{
		sprintf(origin,"FILE%.4d",i);
		sprintf(temp,"FILE%.4d.CHK",i);
		sprintf(del,"del %s",temp);
		
		if(fp=fopen(temp,"rb"))
		{
			handle=0;

			fread(id,1,16,fp);
			if(id[0]==73&&id[1]==68&&id[2]==51&&id[3]==3)
			{
				handle=1;
				puts(temp);
				system("mkdir F:\\mp3");
				sprintf(com,"copy %s F:\\mp3\\%s.mp3 ",temp,origin);
				puts(com);
				system(com);
			}
			else if(id[0]==-1&&id[1]==-40&&id[2]==-1)
			{
				handle=1;
				
				if(!picture)
				{
					system("mkdir F:\\picture");
					picture=1;
				}
				puts(temp);
				system("mkdir F:\\picture\\jpeg");
				sprintf(com,"copy %s F:\\picture\\jpeg\\%s.jpeg ",temp,origin);
				puts(com);
				system(com);
			}
			else if(id[0]==137&&id[1]==80&&id[2]==78)
			{
				handle=1;
				if(!picture)
				{
					system("mkdir F:\\picture");
					picture=1;
				}
				puts(temp);
				system("mkdir F:\\picture\\png");
				sprintf(com,"copy %s F:\\picture\\png\\%s.png ",temp,origin);
				puts(com);
				system(com);
			}
			else if(id[0]==71&&id[1]==73&&id[2]==70)
			{
				handle=1;
								if(!picture)
				{
					system("mkdir F:\\picture");
					picture=1;
				}
				puts(temp);
				system("mkdir F:\\picture\\gif");
				sprintf(com,"copy %s F:\\picture\\gif\\%s.gif ",temp,origin);
				puts(com);
				system(com);
			}
			else if(id[0]==66&&id[1]==76)
			{
				handle=1;
								if(!picture)
				{
					system("mkdir F:\\picture");
					picture=1;
				}
				puts(temp);
				system("mkdir F:\\picture\\bmp");
				sprintf(com,"copy %s F:\\picture\\bmp\\%s.bmp ",temp,origin);
				puts(com);
				system(com);
			}
			else if(id[0]==0x50&&id[1]==0x4b&&id[2]==0x03)
			{
				handle=1;
				if(!compress)
				{
					system("mkdir F:\\compress");
					compress=1;
				}
				puts(temp);
				system("mkdir F:\\compress\\zip");
				sprintf(com,"copy %s F:\\compress\\zip\\%s.zip ",temp,origin);
				puts(com);
				system(com);
			}
			else if(id[0]==82&&id[1]==97&&id[2]==114)
			{

				handle=1;
				if(!compress)
				{
					system("mkdir F:\\compress");
					compress=1;
				}
				puts(temp);
				system("mkdir F:\\compress\\rar");
				sprintf(com,"copy %s F:\\compress\\rar\\%s.rar ",temp,origin);
				puts(com);
				system(com);
			}

			else if(id[0]==65&&id[1]==86&&id[2]==73)
			{

				handle=1;
				if(!video)
				{
					system("mkdir F:\\video");
					video=1;
				}
				puts(temp);
				system("mkdir F:\\video\\avi");
				sprintf(com,"copy %s F:\\video\\avi\\%s.avi ",temp,origin);
				puts(com);
				system(com);
			}
			
			else if(id[0]==46&&id[1]==82&&id[2]==77)
			{
				handle=1;
				if(!video)
				{
					system("mkdir F:\\video");
					video=1;
				}
				puts(temp);
				system("mkdir F:\\video\\rm");
				sprintf(com,"copy %s F:\\video\\rm\\%s.rm ",temp,origin);
				puts(com);
				system(com);
			}
			else if(id[0]==0&&id[1]==0&&id[2]==1&&(id[3]==186||id[3]==179))
			{
				handle=1;
				if(!video)
				{
					system("mkdir F:\\video");
					video=1;
				}
				puts(temp);
				system("mkdir F:\\video\\mpg");
				sprintf(com,"copy %s F:\\video\\mpg\\%s.mpg ",temp,origin);
				puts(com);
				system(com);
			}
			else if(id[0]==87&&id[1]==65&&id[2]==86)
			{
				handle=1;
				if(!video)
				{
					system("mkdir F:\\video");
					video=1;
				}
				puts(temp);
				system("mkdir F:\\video\\wav");
				sprintf(com,"copy %s F:\\video\\wav\\%s.wav ",temp,origin);
				puts(com);
				system(com);
			}
			else if(id[0]==0x30&&id[1]==0x26&&id[2]==0xb2)
			{
				handle=1;
				if(!video)
				{
					system("mkdir F:\\video");
					video=1;
				}
				puts(temp);
				system("mkdir F:\\video\\asf");
				sprintf(com,"copy %s F:\\video\\asf\\%s.asf ",temp,origin);
				puts(com);
				system(com);
			}
			else if(id[0]==0x00&&id[1]==0x00&&id[2]==0x00&&(id[3]==0x1c||id[3]==0x18)&&id[4]==0x66)
			{
				handle=1;
				if(!video)
				{
					system("mkdir F:\\video");
					video=1;
				}
				puts(temp);
				system("mkdir F:\\video\\3pg");
				sprintf(com,"copy %s F:\\video\\3pg\\%s.3pg ",temp,origin);
				puts(com);
				system(com);
			}

			else if((id[0]==0x46&&id[1]==0x4c&&id[2]==0x56&&id[3]==0x01)||(id[0]==0x00&&id[1]==0x00&&id[2]==0x00&&id[3]==0x20&&id[4]==0x66))
			{
				handle=1;
				if(!video)
				{
					system("mkdir F:\\video");
					video=1;
				}
				puts(temp);
				system("mkdir F:\\video\\rmvb");
				sprintf(com,"copy %s F:\\video\\rmvb\\%s.rmvb ",temp,origin);
				puts(com);
				system(com);
			}
			else if(id[0]==0x25&&id[1]==0x50&&id[2]==0x44)
			{
				handle=1;

				puts(temp);
				system("mkdir F:\\pdf");
				sprintf(com,"copy %s F:\\pdf\\%s.pdf ",temp,origin);
				puts(com);
				system(com);
			}
			else if(id[0]==0xd0&&id[1]==0xcf&&id[2]==0x11)
			{
				handle=1;
				if(!document)
				{
					system("mkdir F:\\document");
					document=1;
				}
				puts(temp);
				system("mkdir F:\\document\\word");
				sprintf(com,"copy %s F:\\document\\word\\%s.doc ",temp,origin);
				puts(com);
				system(com);
			}






			
			fclose(fp);
			if(handle)
			{
			system(del);
			}
			
		}
	}

}



/*EXE  �ļ�ͷ��4D5A
Windows Bitmap (bmp)���ļ�ͷ��424D 
CAD (dwg)���ļ�ͷ��41433130 
Adobe Photoshop (psd)���ļ�ͷ��38425053 
Rich Text Format (rtf)���ļ�ͷ��7B5C727466 
XML (xml)���ļ�ͷ��3C3F786D6C 
HTML (html)���ļ�ͷ��68746D6C3E 
Email [thorough only] (eml)���ļ�ͷ��44656C69766572792D646174653A 
Outlook Express (dbx)���ļ�ͷ��CFAD12FEC5FD746F 
Outlook (pst)���ļ�ͷ��2142444E 
MS Word/Excel (xls.or.doc)���ļ�ͷ��D0CF11E0 
MS Access (mdb)���ļ�ͷ��5374616E64617264204A 
WordPerfect (wpd)���ļ�ͷ��FF575043 
Postscript (eps.or.ps)���ļ�ͷ��252150532D41646F6265 
Adobe Acrobat (pdf)���ļ�ͷ��255044462D312E 
Quicken (qdf)���ļ�ͷ��AC9EBD8F 
Windows Password (pwl)���ļ�ͷ��E3828596 
ZIP Archive (zip)���ļ�ͷ��504B0304 
RAR Archive (rar)���ļ�ͷ��52617221 
Wave (wav)���ļ�ͷ��57415645 
AVI (avi)���ļ�ͷ��41564920 
Real Audio (ram)���ļ�ͷ��2E7261FD 
Real Media (rm)���ļ�ͷ��2E524D46 
MPEG (mpg)���ļ�ͷ��000001BA 
MPEG (mpg)���ļ�ͷ��000001B3 
Quicktime (mov)���ļ�ͷ��6D6F6F76 
Windows Media (asf)���ļ�ͷ��3026B2758E66CF11 
MIDI (mid)���ļ�ͷ��4D546864 
*/
