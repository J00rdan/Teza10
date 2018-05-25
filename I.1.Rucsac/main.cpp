#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("input.dat");
ofstream fout("output.dat");

typedef struct
{
    float greutate;
    float profit;
    float eficienta;
} obiect;

obiect M[1000];
int N,G;
float profit_total;

void read(){

    fin>>N>>G;
    for(int i = 1; i <= N; i++){

        fin>>M[i].greutate>>M[i].profit;
        M[i].eficienta = M[i].profit/M[i].greutate;
    }
}

void sort_data(){

    int isSorted = 0;

    do{
        isSorted = 1;
        for(int i = 1; i < N; i++)
            if(M[i].eficienta < M[i + 1].eficienta){
                swap(M[i].eficienta, M[i + 1].eficienta);
                swap(M[i].profit, M[i + 1].profit);
                swap(M[i].greutate, M[i + 1].greutate);
                isSorted = 0;
            }
    }while(isSorted == 0);
}

float greedy(){

    int current = 1;
    int G_current = 0;

    while(current <= N && G_current + M[current].greutate <= G){
            profit_total += M[current].profit;
            G_current += M[current].greutate;
            current++;
    }

    profit_total += M[current].profit * (G - G_current) / M[current].greutate;
    return profit_total;
}

int main()
{
    read();
    sort_data();

    fout<<greedy();

    for(int i = 1; i <= N; i++)
        cout<<M[i].eficienta<<" "<<M[i].greutate<<" "<<M[i].profit<<endl;

    return 0;
}
