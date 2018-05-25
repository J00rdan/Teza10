#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("input.dat");
ofstream fout("output.dat");

int N,K;
int A[1000];

void read(){

    fin>>N>>K;
    for(int i = 1; i <= N; i++)
        fin>>A[i];
}

int binarySearch(int V[], int start, int sfarsit, int K){

        if(start == sfarsit) return V[start] == K;
        if(K <= V[start + (sfarsit - start)/2]) return binarySearch(V, start ,start + (sfarsit - start)/2 ,K);
        else return binarySearch(V, start + (sfarsit - start)/2 + 1 ,sfarsit ,K);
}

int main()
{
    read();
    fout<<binarySearch(A,1,N,K);
    return 0;
}
