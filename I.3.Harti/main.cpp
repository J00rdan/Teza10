#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("input.dat");
ofstream fout("output.dat");

int N;
int A[1000][1000];
int culoare[1000];

void read(){

    fin>>N;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            fin>>A[i][j];
}

void solve(){

    for(int i = 1; i <= N; i++){
        culoare[i] = 1;
        for(int j = 1; j <= N; j++)
            if(A[i][j] == 1 && culoare[i] == culoare[j]) culoare[i]++;
    }
}

void show(){

    for(int i = 1; i <= N; i++)
        fout<<i<<" "<<culoare[i]<<endl;
}

int main()
{
    read();
    solve();
    show();
    return 0;
}
