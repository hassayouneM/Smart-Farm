#ifndef CLIENT_H_
#define CLIENT_H_
#include <gtk/gtk.h>
 enum 
	{ 	
		NOM,
		PRENOM,
		NUM,
		CIN,
		EMAIL,
		SEX,
		NATCLIENT,
		NATACHAT,
		NACHAT,
		COLUMNS,
	};


typedef struct client 
{ 
char nom[20];
char prenom[20];
char num[12];
char cin[9];
char email[50];
char sex[9];
char natclient[30];
char natachat[30];
char nachat[30];
}client;

void ajouter_client(client c);
void modifier_client (char cin[],client c);
void supprimer_client (char cin[] );
client recherche_client (char cin [] );
void afficher_client (GtkWidget *liste);

#endif
