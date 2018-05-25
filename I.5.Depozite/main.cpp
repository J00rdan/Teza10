#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("input.dat");
ofstream fout("output.dat");

int N;
int C[100];
int M[100][2];

void read(){

    fin>>N;
    for(int i = 1; i <= N; i++)
        fin>>C[i];
}

int suma(int start, int sfarsit){

    int s = 0;

    for(int j = start; j <= sfarsit; j++)
        s += C[j];
    return s;
}

int rest(int index){

    return M[index][0] % N;
}

void calcul_resturi(){

    for(int i = 1; i <= N; i++){

        M[i][0] = suma(1,i);
        M[i][1] = rest(i);
    }
}

int main()
{
    read();
    calcul_resturi();

    for(int i = 1; i <= N; i++)
        if(M[i][1] == 0){
            for(int j = 1; j <= i; j++) fout<<j<<" ";
            return 0;
        }

    for(int i = 1; i <= N; i++)
        for(int j = i + 1; j <= N; j++)
            if(M[i][1] == M[j][1]){
                for(int k = i + 1; k <= j; k++) fout<<k<<" ";
                return 0;
            }

    return 0;
}
