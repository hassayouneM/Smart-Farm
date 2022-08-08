#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <gtk/gtk.h>
#include "client.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
///////////////////////////////////FONCTION RECH  elle rendre soit 1 soit 0 //////////////////////////////////////////////////////
int rech(char cin [])
{
{
int test;
  FILE*f;
client c ;
  f=fopen("client.txt","r");
    test=0;
    if (f!=NULL)
{
  while (fscanf(f,"%s %s %s %s %s %s %s %s %s\n",c.nom, c.prenom,c.num,c.cin,c.email,c.sex ,c.natclient,c.natachat,c.nachat)!=EOF)
{
            if (strcmp(cin,c.cin)==0)
{    
                  test=1;
break;
return 1;
}
}
fclose(f);
}
if (test==0)
{return 0;}
else
 {return 1;}
}
}
//////////////////////////////////////FONCTION AJOUT ////////////////////////////////////////////////////////
void ajouter_client(client c)
{
	
	FILE *f;
	f=fopen("client.txt","a");
	
	if(f!=NULL)
	{	
		fprintf(f,"%s %s %s %s %s %s %s %s %s\n",c.nom, c.prenom,c.num,c.cin,c.email,c.sex ,c.natclient,c.natachat,c.nachat);
		fclose(f);
		
	}
	else printf("NOT FOUND \n");
}

/////////////////////////////////FONCTION MODIFIER//////////////////////////////////////////////////////////////
void modifier_client (char cin[] ,client c)
{
	FILE *f;
	FILE *f1;
	
	client c1 ;
	
	f=fopen("client.txt","r");
	f1=fopen("client1.txt","w");
	if (f!=NULL)
	{
	 while (fscanf(f,"%s %s %s %s %s %s %s %s %s\n",c1.nom, c1.prenom,c1.num,c1.cin,c1.email,c1.sex ,c1.natclient,c1.natachat,c1.nachat)!=EOF)
          {if (strcmp(cin,c1.cin)!=0)
		{
		fprintf(f1,"%s %s %s %s %s %s %s %s %s\n",c1.nom, c1.prenom,c1.num,c1.cin,c1.email,c1.sex ,c1.natclient,c1.natachat,c1.nachat);
		}
		else{fprintf(f1,"%s %s %s %s %s %s %s %s %s\n",c.nom, c.prenom,c.num,c.cin,c.email,c.sex ,c.natclient,c.natachat,c.nachat);}
	}
	}
	fclose(f);
	fclose(f1);
	remove("client.txt");
	rename("client1.txt","client.txt");
}

//////////////////////////////////////////FONCTION SUPPRIME/////////////////////////////////////////////////////
void supprimer_client (char cin[] )

{
	FILE *f, *f1;
	client c ;
 
	f1=NULL;
  	f=fopen("client.txt","r");

  	if (f==NULL)
	{
		return;
	} 
       while (fscanf(f,"%s %s %s %s %s %s %s %s %s\n",c.nom, c.prenom,c.num,c.cin,c.email,c.sex ,c.natclient,c.natachat,c.nachat)!=EOF)
	{
    		if (strcmp(cin,c.cin)!=0)

 
		{  
			f1=fopen("client1.txt","a+");
  			fprintf(f1,"%s %s %s %s %s %s %s %s %s\n",c.nom, c.prenom,c.num,c.cin,c.email,c.sex ,c.natclient,c.natachat,c.nachat);

		fclose(f1);
		}
	 }
fclose(f);
remove("client.txt"); rename("client1.txt","client.txt");

}

////////////////////////////////FONCTION RECHERCE CLIENT///////////////////////////////////////////////	
client recherche_client (char cin[] )
{
	FILE *f;
	client c1;
	client c ; 
	f=fopen("client.txt","r");
	if(f!=NULL)
	{
	while (fscanf(f,"%s %s %s %s %s %s %s %s %s\n",c.nom, c.prenom,c.num,c.cin,c.email,c.sex ,c.natclient,c.natachat,c.nachat)!=EOF)
	{if (strcmp(cin,c.cin)==0)
	{ 
	strcpy(c1.nom , c.nom);
	strcpy(c1.prenom , c.prenom);
	strcpy(c1.num , c.num);
	strcpy(c1.email , c.email);
	strcpy(c1.sex , c.sex);
	strcpy(c1.natclient , c.natclient);
	strcpy(c1.natachat , c.natachat);
	strcpy(c1.nachat , c.nachat);}
	else{
	strcpy(c1.nom , "");
	strcpy(c1.prenom , "");
	strcpy(c1.num ,"");
	strcpy(c1.email , "");
	strcpy(c1.sex , "");
	strcpy(c1.natclient , "");
	strcpy(c1.natachat , "");
	strcpy(c1.nachat , "");}}
	 return (c1);
	fclose(f);
}
}

/////////////////////////////////////FONCTION AFFICHE //////////////////////////////////////////////////
void afficher_client(GtkWidget * liste)
{

GtkCellRenderer * renderer;
GtkTreeViewColumn * column;
GtkTreeIter iter;
GtkListStore * store;

client c;

store = NULL ;

FILE * f;

store = gtk_tree_view_get_model (liste);

if(store == NULL)
{

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " nom", renderer, "text", NOM, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " prenom", renderer, "text", PRENOM, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " num", renderer, "text", NUM, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " cin", renderer, "text", CIN, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " email", renderer, "text", EMAIL, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " sex", renderer, "text", SEX, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " nature_client", renderer, "text", NATCLIENT, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " nature_achat", renderer, "text", NATACHAT, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " nachat", renderer, "text", NACHAT, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f = fopen("client.txt","r");

if(f == NULL)

{printf("erreur lors de l'ouverture du fichier ");}

else
{

  while ( fscanf(f,"%s %s %s %s %s %s %s %s %s\n",c.nom, c.prenom,c.num,c.cin,c.email,c.sex ,c.natclient,c.natachat,c.nachat ) != EOF)
  {
   gtk_list_store_append (store, &iter);
   gtk_list_store_set(store, &iter, NOM, c.nom, PRENOM, c.prenom,NUM, c.num, CIN, c.cin, EMAIL, c.email, SEX, c.sex, NATCLIENT, c.natclient,NATACHAT,c.natachat,NACHAT,c.nachat, -1); 

  } 

 fclose(f);
 
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);

}
}
}



