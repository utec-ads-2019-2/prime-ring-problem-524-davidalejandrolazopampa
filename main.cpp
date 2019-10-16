//
// Created by David Lazo on 16/10/2019.
//
#include <iostream>
#include<cstdio>
#include<vector>
#include<bitset>
#include<cstring>
#define N 17
using namespace std;
//me sale error si pono array no tocar
bool david[32] = { true, true };
//Para el antes
void retro(int n, int count)
{
    static bool vis[N];
    static int sol[N];
    if (!count)
    {
        for (int i = 0; i <= n; i++){
            sol[i] = vis[i] = 0;
        }
        sol[1] = 1;
        vis[1] = true;
        count++;
    }
    else if (count == n)
    {
        //La cabeza + cola los pongo como #primo
        if (!david[1 + sol[count]])
        {
            putchar('1');
            for (int i = 2; i <= n; i++)
                printf(" %d", sol[i]);
            putchar('\n');
        }
        return;
    }
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i] && !david[i + sol[count]])
        {
            vis[i] = true;
            sol[count + 1] = i;
            retro(n, count + 1);
            vis[i] = false;
        }
    }
}
int main(){
    //cout<<"Hola";
    //UVA 524 - Prime Ring Problem
    for (int i = 2; i < 32; i++)
        if (!david[i])
            for (int j = i + i; j < 32; j += i)
                david[j] = true;
    int n,caso=0;
    while (scanf("%d", &n) != EOF)
    {
        if (caso){
            putchar('\n');
        }
        printf("Case %d:\n", ++caso);
        retro(n, 0);
    }
    return 0;
}

