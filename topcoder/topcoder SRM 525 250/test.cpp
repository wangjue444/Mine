#include <iostream>
#include <vector>
#include <string>

#define For(a,b,c) for(int a=b;a<c;a++)
using namespace std;


class RainyRoad
{
public:
	string isReachable(vector<string>& road);
};


string RainyRoad::isReachable(vector<string>& road)
{
	int i,j;
	i=0;
	j=0;
	while(i!=road[0].length())
	{
		int tempi=i;
		int tempj=j;
		if(road[j][i+1]=='.'&&road[j][i+1]!='F')
		{
			road[j][i]='1';
			i++;
			continue;
		}
		 if(road[!j][i+1]=='.'&&road[!j][i+1]!='F')
		{
			road[j][i]='2';
			j=!j;
			i=i+1;
			continue;
		}
		 if(road[!j][i]=='.'&&road[!j][i]!='F')
		{
			road[j][i]='3';
			j=!j;
			continue;
		}
		if(tempi==i&&tempj==j)
			break;
	}
	cout<<i;
	if(i==road[0].length()-1)
		return "YES";
	else
		return "NO";



	
}

int main()
{
	RainyRoad a;
	vector<string> b(2);
	b[0]=".W..";
	b[1]="....";
	cout<<a.isReachable(b);
	cout<<endl;
	cout<<b[0]<<endl;
	cout<<b[1]<<endl;
}