#include <iostream>
using namespace std;

int main() {
	int P[] = {1,   5,   8,   9,  10,  17,  17,  20};
	int L[] = {1,   2,   3,   4,   5,   6,   7,   8};
	int n = 8;
	int m = sizeof(P)/sizeof(int);
	
	//cout << m << endl;
	int T[n+1][m+1];
	
	for(int i = 0; i <= n; i++)
	    for(int j = 0; j <= m; j++)
	        T[i][j] = 0;
	
	for(int i = 1; i <= n; ++i)
	{
	    for(int j = 1; j <= m; ++j)
	    {
	        int p1 = T[i][j-1];
	        int p2 = (i >= L[j-1]) ? P[j-1] + T[i-L[j-1]][j-1] : 0;
	        int p3 = 0;
	        //int p3 = (i >= L[j-1]) ? P[j-1] + T[i-L[j-1]][j] : 0;
	        
	        T[i][j] = max(T[i][j], max(p1, max(p2, p3)));
	    }
	}
	
	cout << T[n][m] << endl;
}
