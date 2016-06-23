#include <iostream>
#include <vector>
#include <cmath>
using namespace std;



vector<double> final;
int combine[100][100];


extern "C"
int com(int p1,int p2)
{
	int re=1;


	for(int i=1;i<=p2;i++)
	{
		re=(re*(p1-p2+i))/i;
	}


	return re;
}

extern "C"
void init()
{
	
	for(int  i=0;i<=100;i++)
	{
		for(int j=0;j<=i;j++)
		{
			combine[i][j]=com(i,j);
			//cout<<combine[i][j]<<endl;
		}
	}

}




extern "C"
void explend(int n,double c1,double a1,double c2,double a2,double c3,double a3,double c4,double a4,int m1,int s1,int m2,int s2,int m3,int s3,int m4,int s4)
{
	int temp1=0;
	vector<double> first(n+1);
	vector<double> second(n+1);
	vector<double> third(n+1);
	vector<double> forth(n+1);
	vector<double> fifth(n+1);
	vector<double> tempfinal(n+1);

	for(temp1=0;temp1<=n;temp1++)
		first[temp1]=0;
	for(temp1=0;temp1<=n;temp1++)
		second[temp1]=0;
	for(temp1=0;temp1<=n;temp1++)
		third[temp1]=0;
	for(temp1=0;temp1<=n;temp1++)
		forth[temp1]=0;
	for(temp1=0;temp1<=n;temp1++)
		fifth[temp1]=0;
	for(temp1=0;temp1<=n;temp1++)
		tempfinal[temp1]=0;




	for(temp1=0;temp1<=n;temp1++)
	{
		first[temp1]=(1-c1-c2-c3-c4)*pow(0.9893,temp1)*pow(0.0107,n-temp1)*combine[n][temp1];
	}


	for(temp1=0;temp1<=m1;temp1++)
	{
		second[2*temp1+s1]=c1*pow(a1,temp1)*pow(1-a1,m1-temp1)*combine[m1][temp1];

	}
	for(temp1=0;temp1<=m2;temp1++)
	{
		third[2*temp1+s2]=c2*pow(a2,temp1)*pow(1-a2,m2-temp1)*combine[m2][temp1];
	}

	for(temp1=0;temp1<=m3;temp1++)
	{
		forth[2*temp1+s3]=c3*pow(a3,temp1)*pow(1-a3,m3-temp1)*combine[m3][temp1];
	}


	for( temp1=0;temp1<=m4;temp1++)
	{
		fifth[2*temp1+s4]=c4*pow(a4,temp1)*pow(1-a4,m4-temp1)*combine[m4][temp1];
	}

	for(temp1=0;temp1<=n;temp1++)
	{
		tempfinal[temp1]=first[temp1]+second[temp1]+third[temp1]+forth[temp1]+fifth[temp1];
		cout<<tempfinal[temp1]<<endl;
		cout<<combine[0][0];
	}

	final=tempfinal;

}

extern "C"
void show()
{
	cout<<"df";
	cout<<combine[0][0];
}
