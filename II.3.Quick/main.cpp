#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("input.dat");
ofstream fout("output.dat");

int N;
int A[1000];

void read(){

    fin>>N;
    for(int i = 1; i <= N; i++)
        fin>>A[i];
}

int quick(int V[], int start, int sfarsit){

    int i = start;
    int j = sfarsit;
    int miscare = 0;
    while(i < j){
        if(V[i] > V[j]){
            swap(V[i],V[j]);
            miscare = 1;
        }
        if(miscare == 0) i++;
        else j--;
    }
    return i;
}

int quick_sort(int V[], int start, int sfarsit){

    if(start < sfarsit){

        int k = quick(V,start,sfarsit);
        quick_sort(V,start,k - 1);
        quick_sort(V,k+1,sfarsit);
    }
}

int main()
{
    read();
    quick_sort(A,1,N);
    for(int i = 1; i <= N; i++)
        fout<<A[i]<<" ";
    return 0;
}
