#ifndef FONCTION_MOUNA_H_INCLUDED
#define FONCTION_MOUNA_H_INCLUDED
#include<stdio.h>
#include <gtk/gtk.h>
typedef struct capteur
{
    char reference[20];
    char type[20];
    char marque[20];
    int valeur;
    int activite;
}capteur;
//les entetes des fonctions
void ajouter_cap(capteur *cap);
void modifier_cap(capteur cap,char ref[]);
void supprimer_cap(capteur cap);
void chercher_cap(GtkWidget *liste, char *ref);
void consulter_cap(GtkWidget *liste);
void consulter_humidite_cap(GtkWidget *liste);
void consulter_temperature_cap(GtkWidget *liste);
void cap_alarm(char txt[],int day,int month, int year );


#endif
