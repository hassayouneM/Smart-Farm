#include "sirineouvrier.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<gtk/gtk.h>


enum
{
NOMS,
PRENOMS,
IDS,
DATES,
SEXES,
POSTES,
COLUMNSS
};
enum
{
NOMS1,
PRENOMS1,
IDS1,
DATES1,
SEXES1,
POSTES1,
COLUMNSS1
};


void ajouter_ouvrier_sirine(sir p)
{
FILE *f;
//ouverture du fichier en mode ajout
f=fopen("sir.txt","a+");
if(f!=NULL) //si le fichier est ouvert
{
fprintf(f,"%s %s %s %d %s %d %d %s %s \n",p.nom,p.prenom,p.id,p.date_ouvrier.jour,p.date_ouvrier.mois,p.date_ouvrier.annee,p.date_ouvrier.PA,p.sexe,p.poste); 
   fclose(f);
}

else printf("fichier inexistant");
}
void consulter_ouvrier_sirine(GtkWidget *liste)
{
GtkCellRenderer *renderer; 
GtkTreeViewColumn *column;
GtkTreeIter iter; 
GtkTreeStore *store;
   /* char nom[20];
    char prenom[20];
    char id[20];
Date date_ouvrier;
char sexe[50];
char poste[20];*/
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
sir p;

if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOMS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOMS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",IDS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("date_ouvrier",renderer,"text",DATES,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",SEXES,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("poste",renderer,"text",POSTES,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
store=gtk_list_store_new(COLUMNSS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING);}

//ouverture du fichier en mode ajout
f=fopen("sir.txt","r+");
if(f!=NULL) //si le fichier est ouvert
{
while (fscanf(f,"%s %s %s %d %s %d %d %s %s",p.nom,p.prenom,p.id,&p.date_ouvrier.jour,p.date_ouvrier.mois,&p.date_ouvrier.annee,&p.date_ouvrier.PA,p.sexe,p.poste)!=EOF)
{char r1[20];
char r2[20];
char r3[20];
char r4[10];
char dt_ouvrier[20]="";

sprintf(r1,"%d",p.date_ouvrier.jour);
strcat(dt_ouvrier,r1);
strcat(dt_ouvrier,"/");

sprintf(r2,"%s",p.date_ouvrier.mois);
strcat(dt_ouvrier,r2);
strcat(dt_ouvrier,"/");

sprintf(r3,"%d",p.date_ouvrier.annee);
strcat(dt_ouvrier,r3);
strcat(dt_ouvrier,"-");

sprintf(r4,"%d",p.date_ouvrier.PA);
strcat(dt_ouvrier,r4);



gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,NOMS,p.nom,PRENOMS,p.prenom,IDS,p.id,DATES,dt_ouvrier,SEXES,p.sexe,POSTES,p.poste,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);

}
else printf("fichier inexistant");

}
int verif_sirine(char cin[])
{
FILE*f;
FILE*fa;
sir p;
int trouve=-1;
f=fopen("sir.txt","r+");
fa=fopen("sir1.txt","w");
if (f!=NULL)
{
while( fscanf(f,"%s %s %s %d %s %d %d %s %s",p.nom,p.prenom,p.id,&p.date_ouvrier.jour,p.date_ouvrier.mois,&p.date_ouvrier.annee,&p.date_ouvrier.PA,p.sexe,p.poste)!=EOF)
{
if (strcmp(p.id,cin)==0)
{
trouve=1;
fprintf(fa,"%s %s %s %d %s %d %d %s %s \n",p.nom,p.prenom,p.id,p.date_ouvrier.jour,p.date_ouvrier.mois,p.date_ouvrier.annee,p.date_ouvrier.PA,p.sexe,p.poste); 
}
}
fclose(f);
fclose(fa);
}

return (trouve);
}
void chercher_ouvrier(GtkWidget *liste)
{
GtkCellRenderer *renderer; 
GtkTreeViewColumn *column;
GtkTreeIter iter; 
GtkTreeStore *store;
store=NULL;
FILE *fa;
store=gtk_tree_view_get_model(liste);
sir p;

if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOMS1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOMS1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",IDS1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("date_ouvrier",renderer,"text",DATES1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",SEXES1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("poste",renderer,"text",POSTES1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
store=gtk_list_store_new(COLUMNSS1, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING);}

//ouverture du fichier en mode ajout
fa=fopen("sir1.txt","r+");
if(fa!=NULL) //si le fichier est ouvert
{
while (fscanf(fa,"%s %s %s %d %s %d %d %s %s",p.nom,p.prenom,p.id,&p.date_ouvrier.jour,p.date_ouvrier.mois,&p.date_ouvrier.annee,&p.date_ouvrier.PA,p.sexe,p.poste)!=EOF)
{char r1[20];
char r2[20];
char r3[20];
char r4[10];
char dt_ouvrier[20]="";

sprintf(r1,"%d",p.date_ouvrier.jour);
strcat(dt_ouvrier,r1);
strcat(dt_ouvrier,"/");

sprintf(r2,"%s",p.date_ouvrier.mois);
strcat(dt_ouvrier,r2);
strcat(dt_ouvrier,"/");

sprintf(r3,"%d",p.date_ouvrier.annee);
strcat(dt_ouvrier,r3);
strcat(dt_ouvrier,"-");

sprintf(r4,"%d",p.date_ouvrier.PA);
strcat(dt_ouvrier,r4);



gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,NOMS1,p.nom,PRENOMS1,p.prenom,IDS1,p.id,DATES1,dt_ouvrier,SEXES1,p.sexe,POSTES1,p.poste,-1);
}
fclose(fa);
//remove("sir1.txt");
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);

}
else printf("fichier inexistant");

}

/*int verif_supprimer(char cin[])
{
FILE*f;
//FILE*fa;
sir p;
int trouve=-1;
f=fopen("sir.txt","r+");
//fa=fopen("sir1.txt","a+");
if (f!=NULL)
{
while( fscanf(f,"%s %s %s %d %s %d %d %s %s",p.nom,p.prenom,p.id,&p.date_ouvrier.jour,p.date_ouvrier.mois,&p.date_ouvrier.annee,&p.date_ouvrier.PA,p.sexe,p.poste)!=EOF)
{
if (strcmp(p.id,cin)==0)
{
trouve=1;
//fprintf(fa,"%s %s %s %d %s %d %d %s %s \n",p.nom,p.prenom,p.id,p.date_ouvrier.jour,p.date_ouvrier.mois,p.date_ouvrier.annee,p.date_ouvrier.PA,p.sexe,p.poste); 
}
}
fclose(f);
//fclose(fa);
}

return (trouve);
}
*/
void supprimer_ouvrier()
{
FILE*f;
FILE*fa;
FILE*h;
sir p;
char cin[20]="";
f=fopen("sir.txt","r+");
fa=fopen("sir1.txt","r+");
h=fopen("sirsupp.txt","a+");
if (fa!=NULL)
{
while( fscanf(fa,"%s %s %s %d %s %d %d %s %s",p.nom,p.prenom,p.id,&p.date_ouvrier.jour,p.date_ouvrier.mois,&p.date_ouvrier.annee,&p.date_ouvrier.PA,p.sexe,p.poste)!=EOF)
{
strcpy(cin,p.id);
}
fclose(fa);
//remove("sir1.txt");
}

if (f!=NULL)
{
while( fscanf(f,"%s %s %s %d %s %d %d %s %s",p.nom,p.prenom,p.id,&p.date_ouvrier.jour,p.date_ouvrier.mois,&p.date_ouvrier.annee,&p.date_ouvrier.PA,p.sexe,p.poste)!=EOF)
{
if (strcmp(p.id,cin)!=0)
{
fprintf(h,"%s %s %s %d %s %d %d %s %s \n",p.nom,p.prenom,p.id,p.date_ouvrier.jour,p.date_ouvrier.mois,p.date_ouvrier.annee,p.date_ouvrier.PA,p.sexe,p.poste); 
}
}
fclose(f);
fclose(h);
remove("sir.txt");
    rename ("sirsupp.txt","sir.txt");
}
}


void supprimer_ouvriertree(sir p)
{
FILE*f;

FILE*g;
FILE*ga;
sir p1;
f=fopen("sir.txt","r+");
g=fopen("sir3.txt","a+");
ga=fopen("sir4.txt","a+");

if (f==NULL ||g==NULL)
  return;
else 
{
     while( fscanf(f,"%s %s %s %d %s %d %d %s %s \n",p1.nom,p1.prenom,p1.id,&p1.date_ouvrier.jour,p1.date_ouvrier.mois,&p1.date_ouvrier.annee,&p1.date_ouvrier.PA,p1.sexe,p1.poste)!=EOF)
{
if (strcmp(p.id,p1.id)!=0 )
//strcmp(p.nom,p1.nom)!=0 ||strcmp(p.prenom,p1.prenom)!=0 ||
{fprintf(g,"%s %s %s %d %s %d %d %s %s \n",p1.nom,p1.prenom,p1.id,p1.date_ouvrier.jour,p1.date_ouvrier.mois,p1.date_ouvrier.annee,p1.date_ouvrier.PA,p1.sexe,p1.poste); 
}
if(strcmp(p.id,p1.id)==0)
{fprintf(ga,"%s %s %s %d %s %d %d %s %s \n",p1.nom,p1.prenom,p1.id,p1.date_ouvrier.jour,p1.date_ouvrier.mois,p1.date_ouvrier.annee,p1.date_ouvrier.PA,p1.sexe,p1.poste); 
}
}
fclose(f);
fclose(g);
fclose(ga);
remove("sir.txt");
   rename ("sir3.txt","sir.txt");
}
}
void modifier_ouvrier()
{
FILE*f;
FILE*fa;
FILE*h;
sir p;
char cin[20]="";
char nom[20]="";
char prenom[20]="";
f=fopen("sir.txt","r+");
fa=fopen("sir1.txt","r+");
h=fopen("sirsupp.txt","a+");
if (fa!=NULL)
{
while( fscanf(fa,"%s %s %s %d %s %d %d %s %s",p.nom,p.prenom,p.id,&p.date_ouvrier.jour,p.date_ouvrier.mois,&p.date_ouvrier.annee,&p.date_ouvrier.PA,p.sexe,p.poste)!=EOF)
{
strcpy(nom,p.nom);
strcpy(prenom,p.prenom);
strcpy(cin,p.id);
/*char r1[20];
char r2[20];
char r3[20];
char r4[10];
char dt_ouvrier[20]="";

sprintf(r1,"%d",p.date_ouvrier.jour);
strcat(dt_ouvrier,r1);
strcat(dt_ouvrier,"/");

sprintf(r2,"%s",p.date_ouvrier.mois);
strcat(dt_ouvrier,r2);
strcat(dt_ouvrier,"/");

sprintf(r3,"%d",p.date_ouvrier.annee);
strcat(dt_ouvrier,r3);
strcat(dt_ouvrier,"-");

sprintf(r4,"%d",p.date_ouvrier.PA);
strcat(dt_ouvrier,r4);

strcpy(sexe,p.sexe);
strcpy(prenom,p.poste);*/
}
fclose(fa);
//remove("sir1.txt");
}

if (f!=NULL)
{
while( fscanf(f,"%s %s %s %d %s %d %d %s %s",p.nom,p.prenom,p.id,&p.date_ouvrier.jour,p.date_ouvrier.mois,&p.date_ouvrier.annee,&p.date_ouvrier.PA,p.sexe,p.poste)!=EOF)
{
if (strcmp(p.id,cin)!=0)
{
fprintf(h,"%s %s %s %d %s %d %d %s %s \n",p.nom,p.prenom,p.id,p.date_ouvrier.jour,p.date_ouvrier.mois,p.date_ouvrier.annee,p.date_ouvrier.PA,p.sexe,p.poste); 
}
}
fclose(f);
fclose(h);
remove("sir.txt");
    rename ("sirsupp.txt","sir.txt");
}

}

void joursp_ouvrier(){
FILE *f;
FILE *g;
 int i,a,id,j,m,pa,max;
 //float e;
 int tab[100]={0};

   f=fopen("absenteisme.txt","r");
for(i=0;i<100;i++){tab[i]=0;};
      if (f!=NULL ){
            while (fscanf(f,"%d   %d  %d  %d  %d\n",&id,&j,&m,&a,&pa)!=EOF){
                 if (pa==1) tab[id]+=1;}
    max=tab[0];

   for (i=0;i<100;i++){
    if (tab[i]>max)
        {max=tab[i];
                    }
   }

      }
 g=fopen("ouvriersir1.txt","w");
if(g!=NULL){
for (i=0;i<100;i++){if (tab[i]==max) fprintf(g,"%d\n",i);}

}
fclose(g);

fclose(f);

}
/*void meilleur_ouvrier()
{
    FILE*fa;
   char texte[100]="";
int i;
  strcpy(texte,"le meilleur ouvrier a l'identifiant numéro:");
    fa=fopen("ouvriersir1.txt","r");
    if(fa!=NULL)
    {
       while(fscanf(fa,"%d",i)!=EOF)
       {
       char r[20];
       sprintf(r,"%d",i);
       strcat(texte,r);

       }
       fclose(fa);
      // return 1;
    }
    else printf("impossible d'ouvrir le fichier");
   // return 0;
}*/

void consulter_Agricole_ouvrier(GtkWidget *liste)
{
GtkCellRenderer *renderer; 
GtkTreeViewColumn *column;
GtkTreeIter iter; 
GtkTreeStore *store;
store=NULL;
FILE *fa;
store=gtk_tree_view_get_model(liste);
sir p;

if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOMS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOMS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",IDS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("date_ouvrier",renderer,"text",DATES,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",SEXES,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("poste",renderer,"text",POSTES,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
store=gtk_list_store_new(COLUMNSS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING);}

//ouverture du fichier en mode ajout
fa=fopen("siragricole.txt","r+");
if(fa!=NULL) //si le fichier est ouvert
{
while (fscanf(fa,"%s %s %s %d %s %d %d %s %s",p.nom,p.prenom,p.id,&p.date_ouvrier.jour,p.date_ouvrier.mois,&p.date_ouvrier.annee,&p.date_ouvrier.PA,p.sexe,p.poste)!=EOF)
{char r1[20];
char r2[20];
char r3[20];
char r4[10];
char dt_ouvrier[20]="";

sprintf(r1,"%d",p.date_ouvrier.jour);
strcat(dt_ouvrier,r1);
strcat(dt_ouvrier,"/");

sprintf(r2,"%s",p.date_ouvrier.mois);
strcat(dt_ouvrier,r2);
strcat(dt_ouvrier,"/");

sprintf(r3,"%d",p.date_ouvrier.annee);
strcat(dt_ouvrier,r3);
strcat(dt_ouvrier,"-");

sprintf(r4,"%d",p.date_ouvrier.PA);
strcat(dt_ouvrier,r4);



gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,NOMS,p.nom,PRENOMS,p.prenom,IDS,p.id,DATES,dt_ouvrier,SEXES,p.sexe,POSTES,p.poste,-1);
}
fclose(fa);
//remove("sir1.txt");
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);

}}
//else printf("fichier inexistant");


void consulter_Financier_ouvrier(GtkWidget *liste)
{
GtkCellRenderer *renderer; 
GtkTreeViewColumn *column;
GtkTreeIter iter; 
GtkTreeStore *store;
store=NULL;
FILE *fa;
store=gtk_tree_view_get_model(liste);
sir p;

if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOMS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOMS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",IDS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("date_ouvrier",renderer,"text",DATES,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",SEXES,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("poste",renderer,"text",POSTES,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
store=gtk_list_store_new(COLUMNSS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING);}

//ouverture du fichier en mode ajout
fa=fopen("sirfinancier.txt","r+");
if(fa!=NULL) //si le fichier est ouvert
{
while (fscanf(fa,"%s %s %s %d %s %d %d %s %s",p.nom,p.prenom,p.id,&p.date_ouvrier.jour,p.date_ouvrier.mois,&p.date_ouvrier.annee,&p.date_ouvrier.PA,p.sexe,p.poste)!=EOF)
{char r1[20];
char r2[20];
char r3[20];
char r4[10];
char dt_ouvrier[20]="";

sprintf(r1,"%d",p.date_ouvrier.jour);
strcat(dt_ouvrier,r1);
strcat(dt_ouvrier,"/");

sprintf(r2,"%s",p.date_ouvrier.mois);
strcat(dt_ouvrier,r2);
strcat(dt_ouvrier,"/");

sprintf(r3,"%d",p.date_ouvrier.annee);
strcat(dt_ouvrier,r3);
strcat(dt_ouvrier,"-");

sprintf(r4,"%d",p.date_ouvrier.PA);
strcat(dt_ouvrier,r4);



gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,NOMS,p.nom,PRENOMS,p.prenom,IDS,p.id,DATES,dt_ouvrier,SEXES,p.sexe,POSTES,p.poste,-1);
}
fclose(fa);
//remove("sir1.txt");
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);

}}
//else printf("fichier inexistant");

void financier_ouvrier()
{
FILE*f;
FILE*g;
sir p;
f=fopen("sir.txt","r");
g=fopen("sirfinancier.txt","w");
if (f!=NULL)
{
while( fscanf(f,"%s %s %s %d %s %d %d %s %s",p.nom,p.prenom,p.id,&p.date_ouvrier.jour,p.date_ouvrier.mois,&p.date_ouvrier.annee,&p.date_ouvrier.PA,p.sexe,p.poste)!=EOF)
{
if (strcmp(p.poste,"Financier")==0)

fprintf(g,"%s %s %s %d %s %d %d %s %s \n",p.nom,p.prenom,p.id,p.date_ouvrier.jour,p.date_ouvrier.mois,p.date_ouvrier.annee,p.date_ouvrier.PA,p.sexe,p.poste); 

}

fclose(f);
fclose(g);
}
}

void agricole_ouvrier()
{
FILE*f;
FILE*g;
sir p;
f=fopen("sir.txt","r");
g=fopen("siragricole.txt","w");
if (f!=NULL)
{
while( fscanf(f,"%s %s %s %d %s %d %d %s %s",p.nom,p.prenom,p.id,&p.date_ouvrier.jour,p.date_ouvrier.mois,&p.date_ouvrier.annee,&p.date_ouvrier.PA,p.sexe,p.poste)!=EOF)
{
if (strcmp(p.poste,"Agricole")==0)

fprintf(g,"%s %s %s %d %s %d %d %s %s \n",p.nom,p.prenom,p.id,p.date_ouvrier.jour,p.date_ouvrier.mois,p.date_ouvrier.annee,p.date_ouvrier.PA,p.sexe,p.poste); 

}
fclose(f);
fclose(g);
}
}





