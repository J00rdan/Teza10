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

int binarySearch(int V[], int N, int K){

    int start = 1;
    int sfarsit = N;
    while(start <= sfarsit){
        if(start == sfarsit) return V[start] == K;
        if(K <= V[start + (sfarsit - start)/2]) sfarsit = start + (sfarsit - start)/2;
        else start = start + (sfarsit - start)/2 + 1;
        cout<<start<<" "<<sfarsit<<endl;
    }
}

int main()
{
    read();
    fout<<binarySearch(A,N,K);
    return 0;
}
