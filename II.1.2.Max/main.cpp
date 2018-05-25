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

    while(start <= sfarsit){
        if(start == sfarsit) return A[start];
        if(A[start] >= A[sfarsit]) sfarsit--;
        else start++;
    }
}

int main()
{
    read();
    fout<<max_value(A,1,N);
    return 0;
}
