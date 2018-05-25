#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("input.dat");
ofstream fout("output.dat");

typedef struct{
                float start;
                float sfarsit;
}spectacol;

spectacol spectacole[100];
float start, sfarsit;
int N;
float pauza;

void read(){

    fin>>start>>sfarsit>>N;
    for(int i = 1; i <= N; i++)
        fin>>spectacole[i].start>>spectacole[i].sfarsit;
    fin>>pauza;
}

void sort_data(){

    int isSorted = 1;
    do
    {
        isSorted = 1;
        for(int i = 1; i < N; i++)
            if(spectacole[i].sfarsit > spectacole[i + 1].sfarsit){
                swap(spectacole[i].sfarsit, spectacole[i + 1].sfarsit);
                swap(spectacole[i].start, spectacole[i + 1].start);
                isSorted = 0;
            }
    }while(!isSorted);
}

void solve(){

    float ultim = start;

    for(int i = 1; i <= N; i++){
        if(spectacole[i].start >= ultim && spectacole[i].sfarsit <= sfarsit - pauza){
            ultim = spectacole[i].sfarsit + pauza;
            fout<<spectacole[i].start<<" "<<spectacole[i].sfarsit<<endl;
        }
    }
}

int main()
{
    read();
    sort_data();
    cout<<start<<" "<<sfarsit<<" "<<pauza<<endl;
    for(int i = 1; i <= N; i++)
        cout<<spectacole[i].start<<" "<<spectacole[i].sfarsit<<endl;
    solve();
    return 0;
}
