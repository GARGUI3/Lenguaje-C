/*
Author: Alejandro García Guillén
Problem: The Seasonal War - ACM UVA
Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=288
*/
#include <cstdio>
#include <stack>

using namespace std;

int tmp, f, c, a, cont, i, j=0;
char matriz[27][27];
typedef struct{
    int fil;
    int col;
}posicion;
stack <posicion> S;

void lee(){
    c=f;
    for(i = 1; i <= f; i++) {
        gets(&matriz[i][1]);
    }
    for(int i=0;i<=f;i++){
        matriz[i][0]=-1;
        matriz[i][c+1]=-1;
    }
    for(int j=0;j<=c;j++){
        matriz[0][j]=-1;
        matriz[f+1][j]=-1;
    }
}
int F[8]={-1, -1, 0, 1, 1, 1, 0, -1};
int C[8]={0, 1, 1, 1, 0, -1, -1, -1};
void procesa(){
    posicion p;
    while(!S.empty()){
        p=S.top();
        S.pop();
        for(int m=0;m<8;m++){
            if(matriz[p.fil+F[m]] [p.col+C[m]]=='1'){
                posicion temp={p.fil+F[m], p.col+C[m]};
                S.push(temp);
                matriz[p.fil+F[m]] [p.col+C[m]] = '0';
            }
        }
    }
}
void imprime(){
    cont++;
    printf("Image number %d contains %d war eagles.\n", cont, a);
    a=0;
}
int main()
{
    while(scanf("%d\n", &f)==1){
        lee();
        for(i=1; i <= f; i++) {
            for(j=1; j <= c; j++){
               if(matriz[i][j]=='1'){
                    posicion p={i, j};
                    S.push(p);
                    matriz[i][j] = '0';
                    procesa();
                    a++;
               }
            }
        }
        imprime();
    }

}
