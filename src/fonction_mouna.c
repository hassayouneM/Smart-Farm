#include "fonction_mouna.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<gtk/gtk.h>


enum
{
REFERENCE,
TYPE,
MARQUE,
VALEUR,
ACTIVITE,
COLUMNSMOUNA
};


void ajouter_cap(capteur *cap)
{
FILE *f;
//ouverture du fichier en mode ajout
f=fopen("capteurmouna.txt","a+");
if(f!=NULL) //si le fichier est ouvert
{
    
   fprintf(f,"%s %s %s %d %d\n",cap->reference,cap->type,cap->marque,cap->valeur,cap->activite); //ajout du capteur
   fclose(f);
}

}

void modifier_cap(capteur cap,char ref[])
{
	FILE *f,*h;
	capteur c;
	int x;
//ouverture du fichier en mode ajout
	f=fopen("capteurmouna.txt","r");
	h=fopen("tmpmouna.txt","a+");
	if(f!=NULL) //si le fichier est ouvert
	{
		while (fscanf(f,"%s %s %s %d %d \n",c.reference,c.type,c.marque,&(c.valeur),&(c.activite))!=EOF)
		{
    
    			if(strcmp(c.reference,ref)==0)
			{
           
        		fprintf(h,"%s %s %s %d %d\n",cap.reference,cap.type,cap.marque,cap.valeur,cap.activite);
        		}
	else
        	fprintf(h,"%s %s %s %d %d \n",c.reference,c.type,c.marque,c.valeur,c.activite);}}

fclose(f);
fclose(h);
remove("capteurmouna.txt");
x=rename("tmpmouna.txt","capteurmouna.txt");
}

void supprimer_cap(capteur cap)
{
FILE *f,*h;
capteur c;
int x;
//ouverture du fichier en mode ajout
f=fopen("capteurmouna.txt","r");
h=fopen("tmpmouna.txt","a+");
if(f!=NULL) //si le fichier est ouvert
{
while (fscanf(f,"%s %s %s %d %d\n",c.reference,c.type,c.marque,&(c.valeur),&(c.activite))!=EOF)
{
    if(strcmp(c.reference,cap.reference)!=0)
        fprintf(h,"%s %s %s %d %d\n",c.reference,c.type,c.marque,c.valeur,c.activite);
}
}
fclose(f);
fclose(h);
remove("capteurmouna.txt");
x=rename("tmpmouna.txt","capteurmouna.txt");
}

void chercher_cap(GtkWidget *liste, char *ref)
{
GtkCellRenderer *renderer; 
GtkTreeViewColumn *column;
GtkTreeIter iter; 
GtkTreeStore *store;

FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Reference",renderer,"text",REFERENCE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Type",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Marque",renderer,"text",MARQUE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Valeur",renderer,"text",VALEUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Activite",renderer,"text",ACTIVITE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

store=gtk_list_store_new(COLUMNSMOUNA, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING);}
char act[10];

capteur c;

//ouverture du fichier en mode lecture
f=fopen("capteurmouna.txt","r");
if(f!=NULL) //si le fichier est ouvert
	{
	while (fscanf(f,"%s %s %s %d %d",c.reference,c.type,c.marque,&(c.valeur),&(c.activite))!=EOF)
		{
			if(strcmp(c.reference,ref)==0)
				{if (c.activite==1)
    strcpy(act,"active");
    else strcpy(act,"inactive");


				fclose(f);}

			
		}
	
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,REFERENCE,c.reference,TYPE,c.type,MARQUE,c.marque,VALEUR,c.valeur,ACTIVITE,act,-1);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}}


void consulter_cap(GtkWidget *liste)
{
	GtkCellRenderer *renderer; 
GtkTreeViewColumn *column;
GtkTreeIter iter; 
GtkTreeStore *store;

FILE *f;
store=gtk_tree_view_get_model(liste);
    char act[10];
capteur c;

if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Reference",renderer,"text",REFERENCE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Type",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Marque",renderer,"text",MARQUE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Valeur",renderer,"text",VALEUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Activite",renderer,"text",ACTIVITE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

store=gtk_list_store_new(COLUMNSMOUNA, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING);}

//ouverture du fichier en mode ajout
f=fopen("capteurmouna.txt","r+");
if(f!=NULL) //si le fichier est ouvert
{
while (fscanf(f,"%s %s %s %d %d",c.reference,c.type,c.marque,&(c.valeur),&(c.activite))!=EOF)
{
if (c.activite==1)
    strcpy(act,"active");
    else strcpy(act,"inactive");
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,REFERENCE,c.reference,TYPE,c.type,MARQUE,c.marque,VALEUR,c.valeur,ACTIVITE,act,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);

}

}
void consulter_temperature_cap(GtkWidget *liste)
{
GtkCellRenderer *renderer; 
GtkTreeViewColumn *column;
GtkTreeIter iter; 
GtkTreeStore *store;
FILE *f;
store=gtk_tree_view_get_model(liste);
char act[10];
capteur c;
if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Reference",renderer,"text",REFERENCE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Type",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Marque",renderer,"text",MARQUE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Valeur",renderer,"text",VALEUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Activite",renderer,"text",ACTIVITE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

store=gtk_list_store_new(COLUMNSMOUNA, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING);}

//ouverture du fichier en mode ajout
f=fopen("capteurmouna.txt","r+");
if(f!=NULL) //si le fichier est ouvert
{
while (fscanf(f,"%s %s %s %d %d \n",c.reference,c.type,c.marque,&(c.valeur),&(c.activite))!=EOF)
{ if(strcmp(c.type,"Temperature")==0){
if (c.activite==1)
    strcpy(act,"active");
if (c.activite==0) strcpy(act,"inactive");
    gtk_list_store_append(store,&iter);}
gtk_list_store_set(store,&iter,REFERENCE,c.reference,TYPE,c.type,MARQUE,c.marque,VALEUR,c.valeur,ACTIVITE,act,-1);
}}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}

void consulter_humidite_cap(GtkWidget *liste)
{
GtkCellRenderer *renderer; 
GtkTreeViewColumn *column;
GtkTreeIter iter; 
GtkTreeStore *store;
FILE *f;
store=gtk_tree_view_get_model(liste);
char act[10];
capteur c;
if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Reference",renderer,"text",REFERENCE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Type",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Marque",renderer,"text",MARQUE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Valeur",renderer,"text",VALEUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Activite",renderer,"text",ACTIVITE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

store=gtk_list_store_new(COLUMNSMOUNA, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING);}


f=fopen("capteurmouna.txt","r+");
if(f!=NULL) //si le fichier est ouvert
{
while (fscanf(f,"%s %s %s %d %d \n",c.reference,c.type,c.marque,&(c.valeur),&(c.activite))!=EOF)
{ if(strcmp(c.type,"Humidite")==0){
if (c.activite==1)
    strcpy(act,"active");
 if (c.activite==0) strcpy(act,"inactive");
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,REFERENCE,c.reference,TYPE,c.type,MARQUE,c.marque,VALEUR,c.valeur,ACTIVITE,act,-1);
}}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
void cap_alarm(char txt[],int day,int month, int year )
{

FILE *f;

int jour ;
int numb;
int mois ;
int annee ;
float val ;

 char msg[100];
strcpy(txt,"capteur de Temperature:\n");
    f=fopen("temperature.txt","r");
    if(f!=NULL)
    {
        while(fscanf(f,"%d %d %d %d %f",&numb,&jour,&mois,&annee,&val)!=EOF)
        {
            if((jour==day) && (mois==month) && (annee==year))
            {
		
                if(val<5||val>40)
                   {
			if(numb==1) strcat(txt,"1\t");
			if(numb==2) strcat(txt,"2\t");
			if(numb==3) strcat(txt,"3\t");
			if(numb==4) strcat(txt,"4\t");
			if(numb==5) strcat(txt,"5\t");
			if(numb==6) strcat(txt,"6\t");
			if(numb==7) strcat(txt,"7\t");
			if(numb==8) strcat(txt,"8\t");
			if(numb==9) strcat(txt,"9\t");
		} 
            }
        }
    }
fclose(f);
strcat(txt,"\ncapteur d'Humidite:\n");
    f=fopen("humidite.txt","r");
    if(f!=NULL)
    {
        while(fscanf(f,"%d %d %d %d %f",&numb,&jour,&mois,&annee,&val)!=EOF)
        {
            if((jour==day) && (mois==month) && (annee==year))
            {
                if((jour==day) && (mois==month) && (annee==year))

                   { if(val<50||val>100){
		if(numb==1) strcat(txt,"1\t");
			if(numb==2) strcat(txt,"2\t");
			if(numb==3) strcat(txt,"3\t");
			if(numb==4) strcat(txt,"4\t");
			if(numb==5) strcat(txt,"5\t");
			if(numb==6) strcat(txt,"6\t");
			if(numb==7) strcat(txt,"7\t");
			if(numb==8) strcat(txt,"8\t");
			if(numb==9) strcat(txt,"9\t");}}
            }

        }
    }
fclose(f);
}

