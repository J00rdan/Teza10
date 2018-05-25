#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("input.dat");
ofstream fout("output.dat");

int N,S;
int V[1000];
int total;

void read(){

    fin>>N;
    for(int i = 1; i <= N; i++)
        fin>>V[i];
    fin>>S;
}

void sort_data(){

    int isSorted = 0;

    do
    {
        isSorted = 1;
        for(int i = 1; i < N; i++)
        if(V[i] < V[i + 1]){
                swap(V[i], V[i + 1]);
                isSorted = 0;
        }
    }while(!isSorted);
}

int greedy(){

    for(int i = 1; i <= N; i++){
        int repetare = 0;
        while(S - V[i] >= 0){
            S -= V[i];
            repetare++;
            total += V[i];
        }
        fout<<V[i]<<" "<<repetare<<endl;
    }
    fout<<total;
}

int main()
{
    read();
    sort_data();
    greedy();
    return 0;
}
