#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("input.dat");
ofstream fout("output.dat");

int N;
int A[1000];

void read(){

    fin>>N;
    for(int i = 1; i <= N; i++) fin>>A[i];
}

int max_value(int V[], int start, int sfarsit){

    if(start == sfarsit) return A[start];
    int middle = start + (sfarsit - start)/2;
    int max1 = max_value(V,start,middle);
    int max2 = max_value(V,middle + 1,sfarsit);
    return max(max1,max2);
}

int main()
{
    read();
    fout<<max_value(A,1,N);
    return 0;
}
