#ifndef SIRINEOUVRIER_H_INCLUDED
#define SIRINEOUVRIER_H_INCLUDED
#include<stdio.h>
#include <gtk/gtk.h>
typedef struct d_ouvrier
{
int jour;
char mois[20];
int annee;
int PA;
}Date;
typedef struct sirine
{
    char nom[20];
    char prenom[20];
    char id[20];
    Date date_ouvrier;
    char sexe[50];
    char poste[50];
}sir;

void ajouter_ouvrier_sirine(sir p);
void consulter_ouvrier_sirine(GtkWidget *liste);
int verif_sirine(char cin[]);
void chercher_ouvrier(GtkWidget *liste);
void supprimer_ouvrier();

//int verif_supprimer(char cin[]);
void supprimer_ouvriertree(sir p);
void modifier_ouvrier();
void joursp_ouvrier();
void meilleur_ouvrier();
void consulter_Financier_ouvrier(GtkWidget *liste);
void consulter_Agricole_ouvrier(GtkWidget *liste);
void financier_ouvrier();
void agricole_ouvrier();

#endif
