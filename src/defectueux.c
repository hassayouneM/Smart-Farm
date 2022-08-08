#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <gtk/gtk.h>
#include "client.h"
#include <stdlib.h>
#include <defectueux.h>
#include <stdio.h>

char idmaxhumid()
{
    int t[9],ti[9],tr[9];
    int num,j,m,a,i,imax,tmp,tmpi,ji;
    float val;
    char ch[10],res[15]="";
    FILE *f ;
    f=fopen("humidite.txt","r");
     for (ji=0; ji<9; ji++)
        {t[ji]=0;
        ti[ji]=ji+1;}

    while (fscanf(f,"%d %d %d %d %f \n",&num,&j,&m,&a,&val )!=EOF )
    {
        if ((val>70)||(val<0))
        t[num-1]+=1;
    }
     for(i = 0; i < 9; i++)
    {
      for(j = 1; j < 9; j++)
        {
          if(t[i] > t[j])
            {
              tmp = t[i];
              tmpi=ti[i]  ;
              t[i] = t[j];
              ti[i]=ti[j];
              t[j] = tmp;
              ti[j]=tmpi;
              j--;
            }
}
     }
     fclose(f);
     tr[0]=ti[1];
        i=1;
while (t[i]==t[i+1])
{
    tr[i]=ti[i+1];
    i++;
}
sprintf(ch,"%d",tr[0]);
strcpy(res,ch);
for (j=1;j<i;j++)
{
    sprintf(ch,"%d",tr[j]);
    strcat(res,",");
    strcat(res,ch);
}
     return (res);

}
char idmaxtemp()
{
    int t[9],ti[9],tr[9];
    int num,j,m,a,i,imax,tmp,tmpi,ji;
    float val;
    char ch[10],res[15]="";
    FILE *f ;
    f=fopen("temperature.txt","r");
     for (ji=0; ji<9; ji++)
        {t[ji]=0;
        ti[ji]=ji+1;}

    while (fscanf(f,"%d %d %d %d %f \n",&num,&j,&m,&a,&val )!=EOF )
    {
        if ((val>70)||(val<0))
        t[num-1]+=1;
    }
     for(i = 0; i < 9; i++)
    {
      for(j = 1; j < 9; j++)
        {
          if(t[i] > t[j])
            {
              tmp = t[i];
              tmpi=ti[i]  ;
              t[i] = t[j];
              ti[i]=ti[j];
              t[j] = tmp;
              ti[j]=tmpi;
              j--;
            }
}
     }
     fclose(f);
     tr[0]=ti[1];
        i=1;
while (t[i]==t[i+1])
{
    tr[i]=ti[i+1];
    i++;
}
sprintf(ch,"%d",tr[0]);
strcpy(res,ch);
for (j=1;j<i;j++)
{
    sprintf(ch,"%d",tr[j]);
    strcat(res,",");
    strcat(res,ch);
}
     return (res);

}
