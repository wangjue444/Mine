#include <vector>
#include <cmath>
#include <iostream>
#include <limits>
using namespace std;

class DropCoins
{
public:
	int getMinimum(vector <string> board, int K)
	{

		int res=numeric_limits<int>::max();
		int w=board[0].length();
		int h=board.size();
		for(int x0=0;x0<w;x0++){
			for(int y0=0;y0<h;y0++){
				for(int x1=x0+1;x1<w;x1++){
					for(int y1=y0+1;y1<h;y1++){
						int coins=0;
						for(int i=x0;i<x1;i++){
							for(int j=y0;j<y1;j++)
							{
								if(board[i][j]=='o')
									coins++;
							}
						}
						
						if(coins==K){
							int a=x0;
							int b=w-x1-1;
							int c=y0;
							int d=h-y0-1;
							res=__min(res,a+b+c+d+__min(a,b)+__min(c,d));
						}
					}
				}
			}
		}
		
							
		
		return res==numeric_limits<int>::max()?-1:res;
	}
};


int main()
{
	vector<string> a;
	a.push_back(".o..");
	a.push_back("oooo");
	a.push_back("..o.");
	DropCoins b;
	cout<<b.getMinimum(a,3);
	
	
	
}