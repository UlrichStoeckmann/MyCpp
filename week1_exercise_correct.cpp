//Convert this program to C++
//change to C++ is
//change to one line comments
//change defines of constants to const
//change array to vector<>
// inline any short function



#include <iostream>
#include <vector>

using namespace std;

inline void sum(int& p, int n, vector<int>& d){
	p = 0;
	for(int i = 0; i < n; i++)
		p = p + d[i];
	}

int main(int argc, char **argv)
{
	const int N = 40;
	int accum = 0;
	vector<int> data(N);

	for(int i = 0; i < N; i++)
		data[i] = i;

	sum(accum, N, data);

	cout << "Sum is " << accum << endl;

	return 0;
}
