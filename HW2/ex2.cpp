/*Программа нахождения Гамильтонова цикла*/


#include <iostream.h>
#include <stdlib.h>
 
const int n=5;
 
int way[n] ;     // номер хода, на котором посещается вершина
int num[n];     // номера посещаемых вершин
int v0=2;      // начальная вершина
 

int a[n][n]=            // матрица смежности  
{
    0,1,1,0,0,
	1,0,0,1,0,
	1,0,0,1,0,
	0,1,1,0,1,
    0,0,1,1,0
};
 
void prnt(void)
{
int p;
        for ( p = 0 ; p<n ; p++)
	 cout<<num[p]+1<<"\t";
	 cout<<num[0]+1 ;
         cout<<"\n" ;
}
 
                                             
int gamilton ( int k)                                // нахождение гамильтонова цикла
{
int v,q1=0;
    for(v=0; v<n && !q1; v++)
    {
      if(a[v][num[k-1]]||a[num[k-1]][v])
      {
    if (k==n &&  v==v0 ) q1=1;
    else if (way[v]==-1) 
            {
          way[v] = k ; num[k]=v; 
          q1=gamilton (k+1) ;
          if (!q1) way[v]=-1;  
        } else continue;
    } 
    }   return q1;
}
 
int main()
{
int j;

    cout<<"Гамильтонов цикл \n";
        for(j=0;j<n;j++) way[j]=-1;
        num[0]=v0 ;
          way[v0]=v0;
    if(gamilton (1)) prnt(); 
    else cout<<"Нет решений \n";
    cin.get();
	return 0;
}
