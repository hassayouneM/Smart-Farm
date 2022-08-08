#ifdef HAVE_CONFIG_H
# include <config.h>
#endif



#include "callbacks.h"
#include "interface.h"
#include <string.h>
#include "support.h"
#include "client.h"
#include <defectueux.h>
#include "sirineouvrier.c"
#include "fonction_mouna.c"

int xs=1;
int ys=1;
int ss;
int ts[2]={0,0};
int tabs[2]={0,0};
int trees[2]={0,0};
int yb,yc,ymc,ymb;
char ycinmodif[10];

int choix_cap[]={0,0};
int radio_act;
capteur capt;
char refe[20];

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button6_clicked                     (GtkWidget          *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *youssef_f0;
GtkWidget *window1y;
window1y=lookup_widget(objet_graphique,"window1y");
gtk_widget_destroy(window1y);
youssef_f0=create_youssef_f0();
gtk_widget_show(youssef_f0);
}


void
on_button5_clicked                     (GtkWidget         *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1y;
GtkWidget *treeview1;
window1y=lookup_widget(objet_graphique,"window1y");
treeview1=lookup_widget(window1y,"treeview1");
afficher_client(treeview1);

}


void
on_button4_clicked                     (GtkWidget           *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1y,*window5y;
window5y=create_window5y() ;
window1y=lookup_widget(objet_graphique,"window1y");
gtk_widget_hide(window1y);
gtk_widget_show (window5y);


}


void
on_button3_clicked                     (GtkWidget         *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1y,*window6y ;
window6y =create_window6y() ;
window1y=lookup_widget(objet_graphique,"window1y");
gtk_widget_hide(window1y);
gtk_widget_show (window6y);

}


void
on_button2_clicked                     (GtkWidget          *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1y , *window3y;
window3y=create_window3y() ;
window1y=lookup_widget(objet_graphique,"window1y");
gtk_widget_hide(window1y);
gtk_widget_show (window3y);

}


void
on_button1_clicked                     (GtkWidget          *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1y,*window2y;
window2y=create_window2y() ;
window1y=lookup_widget(objet_graphique,"window1y");
gtk_widget_hide(window1y);
gtk_widget_show (window2y);
}


void
on_button7_clicked                     (GtkWidget          *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget  *output,*input1 , *input2, *input3, *input4, *input5,*input7;
GtkWidget  *window2y , *window1y;
GtkWidget *combobox3;
GtkWidget *nachat;
GtkWidget *treeview1;
char nachat2[20];
client c;

window2y=create_window2y();

input1=lookup_widget(objet_graphique,"entry1"); 
input2=lookup_widget(objet_graphique,"entry2"); 
input3=lookup_widget(objet_graphique,"entry3"); 
input4=lookup_widget(objet_graphique,"entry4"); 
input5=lookup_widget(objet_graphique,"entry5");
input7=lookup_widget(objet_graphique,"combobox3");
nachat=lookup_widget(objet_graphique,"nachat");
if (yb==1)
{
strcpy(c.sex,"male");}
else
{strcpy(c.sex,"female");}
if (yc==1)
{
strcpy(c.natachat,"livraison");}
else
{strcpy(c.natachat,"boutique");}


output=lookup_widget(objet_graphique,"label36"); 

strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(input1))); 
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(c.num,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(c.email,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(c.natclient,gtk_combo_box_get_active_text(GTK_COMBO_BOX(GTK_COMBO_BOX(input7))));

sprintf(nachat2,"%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nachat)));
strcpy(c.nachat,nachat2);
//ajouter_client(c);
if ((strcmp(c.nom,"")==0)||(strcmp(c.prenom,"")==0)||(strcmp(c.num,"")==0)||(strcmp(c.cin,"")==0)||(strcmp(c.email,"")==0)||(strcmp(c.sex,"")==0)||(strcmp(c.natclient,"")==0)||(strcmp(c.natachat,"")==0)||(strcmp(c.nachat,"")==0))
{
 gtk_label_set_text(GTK_LABEL(output),"remplir tous les champs!");
}
else 
{
ajouter_client(c);
gtk_label_set_text(GTK_LABEL(output),"le client est ajouté avec succés");};
window1y=create_window1y() ;
window2y=lookup_widget(objet_graphique,"window2y");
gtk_widget_hide(window2y);
gtk_widget_show (window1y);
treeview1=lookup_widget(window1y,"treeview1");
afficher_client(treeview1);
}




void
on_button8_clicked                     (GtkWidget          *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1y,*window2y;
GtkWidget *treeview1;
window1y=create_window1y() ;
window2y=lookup_widget(objet_graphique,"window2y");
gtk_widget_hide(window2y);
gtk_widget_show (window1y);
treeview1=lookup_widget(window1y,"treeview1");
afficher_client(treeview1);

}

//modifier
void
on_button9_clicked                     (GtkWidget         *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *output, *input1 , *input2, *input3, *input4, *input5,*input6, *nachat  ;
GtkWidget *window6y,*window1y,*window4y;
GtkWidget *treeview1;
client c ;
char nachat2[20];

window6y=create_window6y();
input1=lookup_widget(objet_graphique,"ymodif1");
input2=lookup_widget(objet_graphique,"ymodif2"); 
input3=lookup_widget(objet_graphique,"ymodif3"); 
input4=lookup_widget(objet_graphique,"ymodif4"); 
input5=lookup_widget(objet_graphique,"ymodif5");
input6=lookup_widget(objet_graphique,"ycombobox");
nachat=lookup_widget(objet_graphique,"ymodifspin");



strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(input1))); 
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(c.num,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(c.email,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(c.natclient,gtk_combo_box_get_active_text(GTK_COMBO_BOX(GTK_COMBO_BOX(input6))));
sprintf(nachat2,"%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nachat)));
strcpy(c.nachat,nachat2);
if (ymb==1)
{
strcpy(c.sex,"male");}
else
{strcpy(c.sex,"female");}
if (ymc==0)
{
strcpy(c.natachat,"livraison");}
else
{strcpy(c.natachat,"boutique");}
modifier_client(ycinmodif,c);

window1y=create_window1y() ;
window4y=lookup_widget(objet_graphique,"window4y");
gtk_widget_hide(window4y);
gtk_widget_show (window1y);
treeview1=lookup_widget(window1y,"treeview1");
afficher_client(treeview1);
}

void
on_button10_clicked                    (GtkWidget          *objet_graphique,
                                        gpointer          user_data)
{
GtkWidget *window1y,*window4y;
GtkWidget *treeview1;
window1y=create_window1y() ;
window4y=lookup_widget(objet_graphique,"window4y");
gtk_widget_hide(window4y);
gtk_widget_show (window1y);
treeview1=lookup_widget(window1y,"treeview1");
afficher_client(treeview1);

}
//recherche
void
on_button11_clicked                    (GtkWidget          *objet_graphique,
                                        gpointer           user_data)
{
GtkWidget *input1, *nom,*prenom,*num,*cinn,*email,*sex,*natclient,*nachat,*natachat;
GtkWidget *window5y;
window5y=create_window5y();
char cin[20];
input1=lookup_widget(objet_graphique,"entry12");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input1))); 
nom=lookup_widget(objet_graphique,"label31");
prenom=lookup_widget(objet_graphique,"label37");
num=lookup_widget(objet_graphique,"label38");
cinn=lookup_widget(objet_graphique,"label39");
email=lookup_widget(objet_graphique,"label40");
sex=lookup_widget(objet_graphique,"label41");
natclient=lookup_widget(objet_graphique,"label42");
natachat=lookup_widget(objet_graphique,"label58");
nachat=lookup_widget(objet_graphique,"label60");


client c= recherche_client(cin);

gtk_label_set_text(GTK_LABEL(nom),c.nom);
gtk_label_set_text(GTK_LABEL(prenom),c.prenom);
gtk_label_set_text(GTK_LABEL(num),c.num);
gtk_label_set_text(GTK_LABEL(cinn),c.cin);
gtk_label_set_text(GTK_LABEL(email),c.email);
gtk_label_set_text(GTK_LABEL(sex),c.sex);
gtk_label_set_text(GTK_LABEL(natclient),c.natclient);
gtk_label_set_text(GTK_LABEL(natachat),c.natachat);
gtk_label_set_text(GTK_LABEL(nachat),c.nachat);


}


void
on_button12_clicked                    (GtkWidget         *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1y,*window5y;
GtkWidget *treeview1;
window1y=create_window1y() ;
window5y=lookup_widget(objet_graphique,"window5y");
gtk_widget_hide(window5y);
gtk_widget_show (window1y);
treeview1=lookup_widget(window1y,"treeview1");
afficher_client(treeview1);

}


void
on_button13_clicked                    (GtkWidget        *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1, *output;
GtkWidget *window3y , *window1y;
GtkWidget *treeview1;
window3y=create_window3y();
char cin[20];
int x;
input1=lookup_widget(objet_graphique,"entry6");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input1))); 
output=lookup_widget(objet_graphique,"resultaty");
x= rech(cin);
if(x==1)
{
supprimer_client(cin);
gtk_label_set_text(GTK_LABEL(output),"client est supprimé avec succés");
}
else 
{
gtk_label_set_text(GTK_LABEL(output),"client inexistant");
}
window1y=create_window1y() ;
window3y=lookup_widget(objet_graphique,"window3y");
gtk_widget_hide(window3y);
gtk_widget_show (window1y);
treeview1=lookup_widget(window1y,"treeview1");
afficher_client(treeview1);
}


void
on_button14_clicked                    (GtkWidget         *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1y,*window3y;
GtkWidget *treeview1;
window1y=create_window1y() ;
window3y=lookup_widget(objet_graphique,"window3y");
gtk_widget_hide(window3y);
gtk_widget_show (window1y);
treeview1=lookup_widget(window1y,"treeview1");
afficher_client(treeview1);
}


void
on_ymale_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(togglebutton))
{yb=1;}
}


void
on_yfemale_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(togglebutton))
{yb=0;}
}


void
on_ylivraison_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(togglebutton))
{yc=1;}
}


void
on_ysurplace_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(togglebutton))
{yb=0;}
}


void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(togglebutton))
{ymc=1;}
}


void
on_ymodifsex2_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(togglebutton))
{ymb=0;}
}


void
on_ymodifsex1_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(togglebutton))
{ymb=1;}
}


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(togglebutton))
{ymc=0;}
}


void
on_yquittermodif0_clicked              (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1y,*window6y;
GtkWidget *treeview1;
window1y=create_window1y() ;
window6y=lookup_widget(objet_graphique,"window6y");
gtk_widget_hide(window6y);
gtk_widget_show (window1y);
treeview1=lookup_widget(window1y,"treeview1");
afficher_client(treeview1);
}





void
on_yvmodif0_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1, *output;
GtkWidget *window6y,*window4y ;
int x;
input1=lookup_widget(objet_graphique,"ymodif0");
strcpy(ycinmodif,gtk_entry_get_text(GTK_ENTRY(input1))); 
output=lookup_widget(objet_graphique,"yresultmodif");
x= rech(ycinmodif);
if(x==1)
{
window4y =create_window4y() ;
window6y=lookup_widget(objet_graphique,"window6y");
gtk_widget_hide(window6y);
gtk_widget_show (window4y);
}
else 
{
gtk_label_set_text(GTK_LABEL(output),"client inexistant");
}
}


void
on_treeviewsirinego_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
sir p;
gchar*nom;
gchar*prenom;
gchar*id;
GtkListStore *list_store;
list_store= gtk_tree_view_get_model(treeview);
GtkTreeIter iter;
//windowsirinegestionouvrier=lookup_widget(objet,"windowsirinegestionouvrier");
if (gtk_tree_model_get_iter(GTK_TREE_MODEL(list_store),&iter,path))
{
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,0,&nom,1,&prenom,2,&id,-1);
}
strcpy(p.nom,nom);
strcpy(p.prenom,prenom);
strcpy(p.id,id);

supprimer_ouvriertree(p);
gtk_list_store_remove(GTK_LIST_STORE(list_store),&iter);
}


void
on_buttonbackgosir_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowsirinegestionouvrier, *youssef_f0;

windowsirinegestionouvrier=lookup_widget(objet,"windowsirinegestionouvrier");
gtk_widget_hide(windowsirinegestionouvrier);
youssef_f0=create_youssef_f0();
gtk_widget_show(youssef_f0);
}


void
on_buttonmeilleurouvriergos_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowmeilleurouvrier;
GtkWidget *windowsirinegestionouvrier;

windowsirinegestionouvrier=lookup_widget(objet,"windowsirinegestionouvrier");
gtk_widget_hide(windowsirinegestionouvrier);
windowmeilleurouvrier=lookup_widget(objet,"windowmeilleurouvrier");
windowmeilleurouvrier=create_windowmeilleurouvrier();
gtk_widget_show(windowmeilleurouvrier);
}


void
on_buttonrechos_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowsirinegestionouvrier, *windowrechercherouvrier;
GtkWidget *treeviewsirinerech;
GtkWidget *input1;
int trouve;
char cin [20];
windowsirinegestionouvrier=lookup_widget(objet,"windowsirinegestionouvrier");
input1 = lookup_widget(objet, "entryrechos");
strcpy(cin, gtk_entry_get_text(GTK_ENTRY(input1)));
trouve=verif_sirine(cin);
if (trouve==1)
{
gtk_widget_hide(windowsirinegestionouvrier);
windowrechercherouvrier=lookup_widget(objet,"windowrechercherouvrier");
windowrechercherouvrier=create_windowrechercherouvrier();
gtk_widget_show(windowrechercherouvrier);
treeviewsirinerech =lookup_widget(windowrechercherouvrier,"treeviewsirinerech");
chercher_ouvrier(treeviewsirinerech);
}
else 
{
GtkWidget *dialog4sir;
dialog4sir=create_dialog4sir() ;
gtk_widget_show(dialog4sir) ;
}
}


void
on_buttonmodos_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowsirinegestionouvrier, *windowmodificationsirinetree;

windowsirinegestionouvrier=lookup_widget(objet,"windowsirinegestionouvrier");

windowmodificationsirinetree=lookup_widget(objet,"windowmodificationsirinetree");
gtk_widget_hide(windowsirinegestionouvrier);
windowmodificationsirinetree=create_windowmodificationsirinetree();
gtk_widget_show(windowmodificationsirinetree);
}


void
on_buttonsupposg_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowsirinegestionouvrier,*window2sir;

windowsirinegestionouvrier=lookup_widget(objet,"windowsirinegestionouvrier");
gtk_widget_hide(windowsirinegestionouvrier);
window2sir=lookup_widget(objet,"window2sir");
window2sir=create_window2sir();
gtk_widget_show(window2sir);
}


void
on_buttonajouterouvrier_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowsirinegestionouvrier, *windowajouterouvrier;
windowsirinegestionouvrier=lookup_widget(objet,"windowsirinegestionouvrier");
gtk_widget_hide(windowsirinegestionouvrier);
windowajouterouvrier=create_windowajouterouvrier();
gtk_widget_show(windowajouterouvrier);
}


void
on_buttongogestionouvriersir_clicked   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1sir;
GtkWidget *windowsirinegestionouvrier;
GtkWidget *treeviewsirinego;
window1sir=lookup_widget(objet,"window1sir");
gtk_widget_hide(window1sir);
windowsirinegestionouvrier=lookup_widget(objet,"windowsirinegestionouvrier");
windowsirinegestionouvrier=create_windowsirinegestionouvrier();
gtk_widget_show(windowsirinegestionouvrier);
treeviewsirinego = lookup_widget(windowsirinegestionouvrier,"treeviewsirinego");
consulter_ouvrier_sirine(treeviewsirinego);
}


void
on_bsgo_clicked                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowsirinegestionouvrier, *windowajouterouvrier;
GtkWidget *treeviewsirinego;
windowajouterouvrier=lookup_widget(objet,"windowajouterouvrier");
gtk_widget_hide(windowajouterouvrier);
windowsirinegestionouvrier=lookup_widget(objet,"windowsirinegestionouvrier");
windowsirinegestionouvrier=create_windowsirinegestionouvrier();
gtk_widget_show(windowsirinegestionouvrier);
treeviewsirinego = lookup_widget(windowsirinegestionouvrier,"treeviewsirinego");
consulter_ouvrier_sirine(treeviewsirinego);
}


void
on_radiobuttonhosirine_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
{xs=0;}
}


void
on_radiobuttonfemmesir_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
{xs=1;}
}


void
on_oag_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{ts[0]=1;}
}


void
on_of_toggled                          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{ts[1]=2;}
}


void
on_buttonvaliderao_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *input1;
  GtkWidget *input2;
  GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
  GtkWidget *input6;
  GtkWidget *input7;

GtkWidget * pRadio1;
GtkWidget * pRadio2;
//GtkWidget * pLabel;
 GtkWidget *windowajouterouvrier;
GtkWidget *windowsirinegestionouvrier;
GtkWidget *treeviewsirinego;
    char nom[20]; 
    char prenom[20];
    char id[20];
    Date date_ouvrier;
char sexe[50];
char poste[20];

sir p;
windowajouterouvrier=lookup_widget(objet,"windowajouterouvrier");	 
input1 = lookup_widget(objet, "entrynomo");
input2 = lookup_widget(objet, "entryprenomo");
input3 = lookup_widget(objet, "entryido");
input4= lookup_widget(objet,"jo");
input5=lookup_widget(objet,"mo");
input6=lookup_widget(objet,"ao");
input7=lookup_widget(objet,"pa");
if((strcmp((gtk_entry_get_text(GTK_ENTRY(input1))),"")==0)||(strcmp((gtk_entry_get_text(GTK_ENTRY(input2))),"")==0)||(strcmp((gtk_entry_get_text(GTK_ENTRY(input3))),"")==0)||(strcmp(gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)),"")==0))
{ 
g_print("non");
GtkWidget *dialog1sir;
dialog1sir=create_dialog1sir() ;
gtk_widget_show(dialog1sir) ;

}
else{
 strcpy(p.nom, gtk_entry_get_text(GTK_ENTRY(input1)));
 strcpy(p.prenom, gtk_entry_get_text(GTK_ENTRY(input2)));
 strcpy(p.id, gtk_entry_get_text(GTK_ENTRY(input3)));
 p.date_ouvrier.jour= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
strcpy(p.date_ouvrier.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)));
p.date_ouvrier.annee= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
p.date_ouvrier.PA= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));

 if (xs==1)
{strcpy(p.sexe,"Femme");}
if (xs==0)
{strcpy(p.sexe,"Homme");}


if (ts[0]==1)
{strcpy(p.poste,"Agricole");}
 if (ts[1]==2) 
{strcpy(p.poste,"Financier");}

GtkWidget *dialog2sir;
dialog2sir=create_dialog2sir() ;
gtk_widget_show(dialog2sir) ;

 ajouter_ouvrier_sirine(p);


gtk_widget_hide(windowajouterouvrier);
windowsirinegestionouvrier=lookup_widget(objet,"windowsirinegestionouvrier");
windowsirinegestionouvrier=create_windowsirinegestionouvrier();
gtk_widget_show(windowsirinegestionouvrier);
treeviewsirinego = lookup_widget(windowsirinegestionouvrier,"treeviewsirinego");
consulter_ouvrier_sirine(treeviewsirinego);
}
}


void
on_backsr_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowsirinegestionouvrier, *windowrechercherouvrier;
GtkWidget *treeviewsirinego;
windowrechercherouvrier=lookup_widget(objet,"windowrechercherouvrier");
gtk_widget_hide(windowrechercherouvrier);
windowsirinegestionouvrier=lookup_widget(objet,"windowsirinegestionouvrier");
windowsirinegestionouvrier=create_windowsirinegestionouvrier();
gtk_widget_show(windowsirinegestionouvrier);
treeviewsirinego = lookup_widget(windowsirinegestionouvrier,"treeviewsirinego");
consulter_ouvrier_sirine(treeviewsirinego);
}


void
on_buttonsupprechsir_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeviewsirinego;

GtkWidget*windowrechercherouvrier=lookup_widget(objet,"windowrechercherouvrier");
supprimer_ouvrier();
gtk_widget_hide(windowrechercherouvrier);
GtkWidget *dialog3sir;
dialog3sir=create_dialog3sir() ;
gtk_widget_show(dialog3sir) ;
GtkWidget*windowsirinegestionouvrier=lookup_widget(objet,"windowsirinegestionouvrier");
windowsirinegestionouvrier=create_windowsirinegestionouvrier();
gtk_widget_show(windowsirinegestionouvrier);
treeviewsirinego = lookup_widget(windowsirinegestionouvrier,"treeviewsirinego");
consulter_ouvrier_sirine(treeviewsirinego);
}


void
on_buttonmodrechsir_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowrechercherouvrier, *windowmodificationsirine;


windowrechercherouvrier=lookup_widget(objet,"windowrechercheouvrier");

windowmodificationsirine=lookup_widget(objet,"windowmodificationsirine");
gtk_widget_hide(windowrechercherouvrier);
windowmodificationsirine=create_windowmodificationsirine();

gtk_widget_show(windowmodificationsirine);
}


void
on_backmodouvs_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowmodificationsirine, *windowrechercherouvrier,*treeviewsirinerech;

windowmodificationsirine=lookup_widget(objet,"windowmodificationsirine");
gtk_widget_hide(windowmodificationsirine);
windowrechercherouvrier=lookup_widget(objet,"windowrechercherouvrier");
windowrechercherouvrier=create_windowrechercherouvrier();
gtk_widget_show(windowrechercherouvrier);
treeviewsirinerech =lookup_widget(windowrechercherouvrier,"treeviewsirinerech");
consulter_ouvrier_sirine(treeviewsirinerech);
}


void
on_buttoncinmods_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
sir p;
GtkWidget *output1;
GtkWidget *output2;
GtkWidget *output3;


output1= lookup_widget(objet,"entrynommods");
output2= lookup_widget(objet, "entryprenmods");
output3= lookup_widget(objet,"entrycinmods");

FILE*fa;
fa=fopen("sir1.txt","r+");
if (fa!=NULL)
{
while( fscanf(fa,"%s %s %s %d %s %d %d %s %s",p.nom,p.prenom,p.id,&p.date_ouvrier.jour,p.date_ouvrier.mois,&p.date_ouvrier.annee,&p.date_ouvrier.PA,p.sexe,p.poste)!=EOF)
{
gtk_entry_set_text(GTK_ENTRY(output1),p.nom);
gtk_entry_set_text(GTK_ENTRY(output2),p.prenom);
gtk_entry_set_text(GTK_ENTRY(output3),p.id);

}
fclose(fa);
}

}


void
on_radiobuttonfsirmod_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
{ys=1;}
}


void
on_radiobuttonmsirmod_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
{ys=0;}
}


void
on_oagmod_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{tabs[0]=1;}
}


void
on_ofmod_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{tabs[1]=2;}
}


void
on_buttonokmodsir_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input1;
  GtkWidget *input2;
  GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
  GtkWidget *input6;
  GtkWidget *input7;

GtkWidget * pRadio1;
GtkWidget * pRadio2;
//GtkWidget * pLabel;
 GtkWidget *windowmodificationouvrier;
GtkWidget *windowsirinegestionouvrier;
GtkWidget *treeviewsirinego;
    char nom[20]; 
    char prenom[20];
    char id[20];
    Date date_ouvrier;
char sexe[50];
char poste[20];

sir p;
windowmodificationouvrier=lookup_widget(objet,"windowmodificationouvrier");	 
input1 = lookup_widget(objet, "entrynommods");
input2 = lookup_widget(objet, "entryprenmods");
input3 = lookup_widget(objet, "entrycinmods");
input4= lookup_widget(objet,"jms");
input5=lookup_widget(objet,"mms");
input6=lookup_widget(objet,"ams");
input7=lookup_widget(objet,"pams");
supprimer_ouvrier();
if((strcmp((gtk_entry_get_text(GTK_ENTRY(input1))),"")==0)||(strcmp((gtk_entry_get_text(GTK_ENTRY(input2))),"")==0)||(strcmp((gtk_entry_get_text(GTK_ENTRY(input3))),"")==0)||(strcmp(gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)),"")==0))
{ 
g_print("non");
GtkWidget *dialog1sir;
dialog1sir=create_dialog1sir() ;
gtk_widget_show(dialog1sir) ;

}
else{
 strcpy(p.nom, gtk_entry_get_text(GTK_ENTRY(input1)));
 strcpy(p.prenom, gtk_entry_get_text(GTK_ENTRY(input2)));
 strcpy(p.id, gtk_entry_get_text(GTK_ENTRY(input3)));
 p.date_ouvrier.jour= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
strcpy(p.date_ouvrier.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)));
p.date_ouvrier.annee= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
p.date_ouvrier.PA= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));

 if (ys==1)
{strcpy(p.sexe,"Femme");}
if (ys==0)
{strcpy(p.sexe,"Homme");}


if (tabs[0]==1)
{strcpy(p.poste,"Agricole");}
 if (tabs[1]==2) 
{strcpy(p.poste,"Financier");}

GtkWidget *dialog5sir;
dialog5sir=create_dialog5sir() ;
gtk_widget_show(dialog5sir) ;

 ajouter_ouvrier_sirine(p);


gtk_widget_hide(windowmodificationouvrier);
windowsirinegestionouvrier=lookup_widget(objet,"windowsirinegestionouvrier");
windowsirinegestionouvrier=create_windowsirinegestionouvrier();
gtk_widget_show(windowsirinegestionouvrier);
treeviewsirinego = lookup_widget(windowsirinegestionouvrier,"treeviewsirinego");
consulter_ouvrier_sirine(treeviewsirinego);
}
}


void
on_buttonvalidersupptreesiri_clicked   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowsirinegestionouvrier;

GtkWidget *window2sir=lookup_widget(objet,"window2sir");
GtkWidget *treeviewsirinego;
gtk_widget_hide(window2sir);
windowsirinegestionouvrier=lookup_widget(objet,"windowsirinegestionouvrier");
windowsirinegestionouvrier=create_windowsirinegestionouvrier();

treeviewsirinego = lookup_widget(windowsirinegestionouvrier,"treeviewsirinego");
consulter_ouvrier_sirine(treeviewsirinego);
gtk_widget_show(windowsirinegestionouvrier);
}


void
on_closedialog5sir_clicked             (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *dialog5sir=lookup_widget(objet,("dialog5sir"));

gtk_widget_destroy(dialog5sir);
}


void
on_backmodstree_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowsirinegestionouvrier,*windowmodificationsirinetree;

windowmodificationsirinetree=lookup_widget(objet,"windowmodificationsirinetree");
GtkWidget *treeviewsirinego;
gtk_widget_hide(windowmodificationsirinetree);
windowsirinegestionouvrier=lookup_widget(objet,"windowsirinegestionouvrier");
windowsirinegestionouvrier=create_windowsirinegestionouvrier();

treeviewsirinego = lookup_widget(windowsirinegestionouvrier,"treeviewsirinego");
consulter_ouvrier_sirine(treeviewsirinego);
gtk_widget_show(windowsirinegestionouvrier);
}


void
on_fmodstree_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
{ss=1;}
}


void
on_mmodstree_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
{ss=0;}
}


void
on_agmodstree_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{trees[0]=1;}
}


void
on_fimodstree_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{trees[1]=2;}
}


void
on_validermodstree_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input1;
  GtkWidget *input2;
  GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
  GtkWidget *input6;
  GtkWidget *input7;

GtkWidget * pRadio1;
GtkWidget * pRadio2;
//GtkWidget * pLabel;
 GtkWidget *windowmodificationsirinetree;
GtkWidget *windowsirinegestionouvrier;
GtkWidget *treeviewsirinego;
    char nom[20]; 
    char prenom[20];
    char id[20];
    Date date_ouvrier;
char sexe[50];
char poste[20];

sir p;
windowmodificationsirinetree=lookup_widget(objet,"windowmodificationsirinetree");	 
input1 = lookup_widget(objet, "entrynomstree");
input2 = lookup_widget(objet, "entryprenstree");
input3 = lookup_widget(objet, "entrycinstree");
input4= lookup_widget(objet,"jmodstree");
input5=lookup_widget(objet,"modsirtree");
input6=lookup_widget(objet,"amodstree");
input7=lookup_widget(objet,"pamodstree");
if((strcmp((gtk_entry_get_text(GTK_ENTRY(input1))),"")==0)||(strcmp((gtk_entry_get_text(GTK_ENTRY(input2))),"")==0)||(strcmp((gtk_entry_get_text(GTK_ENTRY(input3))),"")==0)||(strcmp(gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)),"")==0))
{ 
g_print("non");
GtkWidget *dialog1sir;
dialog1sir=create_dialog1sir() ;
gtk_widget_show(dialog1sir) ;

}
else{
 strcpy(p.nom, gtk_entry_get_text(GTK_ENTRY(input1)));
 strcpy(p.prenom, gtk_entry_get_text(GTK_ENTRY(input2)));
 strcpy(p.id, gtk_entry_get_text(GTK_ENTRY(input3)));
 p.date_ouvrier.jour= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
strcpy(p.date_ouvrier.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)));
p.date_ouvrier.annee= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
p.date_ouvrier.PA= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));

 if (ss==1)
{strcpy(p.sexe,"Femme");}
if (ss==0)
{strcpy(p.sexe,"Homme");}


if (trees[0]==1)
{strcpy(p.poste,"Agricole");}
 if (trees[1]==2) 
{strcpy(p.poste,"Financier");}

GtkWidget *dialog5sir;
dialog5sir=create_dialog5sir() ;
gtk_widget_show(dialog5sir) ;

 ajouter_ouvrier_sirine(p);

gtk_widget_hide(windowmodificationsirinetree);
windowsirinegestionouvrier=lookup_widget(objet,"windowsirinegestionouvrier");
windowsirinegestionouvrier=create_windowsirinegestionouvrier();
gtk_widget_show(windowsirinegestionouvrier);
treeviewsirinego = lookup_widget(windowsirinegestionouvrier,"treeviewsirinego");
consulter_ouvrier_sirine(treeviewsirinego);
}
}


void
on_closediag1sir_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *dialog1sir=lookup_widget(objet,("dialog1sir"));

gtk_widget_destroy(dialog1sir);
}


void
on_closedialog2sir_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *dialog2sir=lookup_widget(objet,("dialog2sir"));

gtk_widget_destroy(dialog2sir);
}


void
on_closedialog3sir_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *dialog3sir=lookup_widget(objet,("dialog3sir"));

gtk_widget_destroy(dialog3sir);
}


void
on_closedialog4sir_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *dialog4sir=lookup_widget(objet,("dialog4sir"));

gtk_widget_destroy(dialog4sir);
}


void
on_buttonbackmeilleurgos_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowmeilleurouvrier;
GtkWidget *windowsirinegestionouvrier;
GtkWidget *treeviewsirinego;
windowmeilleurouvrier=lookup_widget(objet,"windowmeilleurouvrier");
gtk_widget_hide(windowmeilleurouvrier);
windowsirinegestionouvrier=lookup_widget(objet,"windowsirinegestionouvrier");
windowsirinegestionouvrier=create_windowsirinegestionouvrier();
gtk_widget_show(windowsirinegestionouvrier);
 treeviewsirinego=lookup_widget(windowsirinegestionouvrier,"treeviewsirinego");
consulter_ouvrier_sirine(treeviewsirinego);
}


void
on_buttonmeilleurouvrier_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
char texte[100]="";
char texte1[100];
GtkWidget*windowmeilleurouvrier=lookup_widget(objet,"windowmeilleurouvrier");
GtkWidget*output=lookup_widget(objet,"labelmeilleurouvrier");
joursp_ouvrier();
 FILE*fa;
   //char texte[100]="";
int i;
  //strcpy(texte,"le meilleur ouvrier a l'identifiant numéro:");
    fa=fopen("ouvriersir1.txt","r");
    if(fa!=NULL)
    {
       while(fscanf(fa,"%d",&i)!=EOF)
       {
       char r[20];
       sprintf(r,"%d",i);
       strcat(texte,r);
sprintf(texte1,"le meilleur ouvrier a l'identifiant numéro: %s ",texte);
       }
       fclose(fa);
    }

gtk_label_set_text(GTK_LABEL(output),texte1);
}




void
on_buttonokmodstree_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
sir p;
GtkWidget *output1;
GtkWidget *output2;
GtkWidget *output3;


output1= lookup_widget(objet,"entrynomstree");
output2= lookup_widget(objet, "entryprenstree");
output3= lookup_widget(objet,"entrycinstree");
FILE*fa;
fa=fopen("sir4.txt","r+");
if (fa!=NULL)
{
while( fscanf(fa,"%s %s %s %d %s %d %d %s %s",p.nom,p.prenom,p.id,&p.date_ouvrier.jour,p.date_ouvrier.mois,&p.date_ouvrier.annee,&p.date_ouvrier.PA,p.sexe,p.poste)!=EOF)
{
gtk_entry_set_text(GTK_ENTRY(output1),p.nom);
gtk_entry_set_text(GTK_ENTRY(output2),p.prenom);
gtk_entry_set_text(GTK_ENTRY(output3),p.id);

}
fclose(fa);}
}






void
on_back_acceuil_cap_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *youssef_f0;
GtkWidget *mouna_gestion_cap;
mouna_gestion_cap=lookup_widget(objet,"mouna_gestion_cap");
gtk_widget_destroy(mouna_gestion_cap);
youssef_f0=create_youssef_f0();
gtk_widget_show(youssef_f0);
}


void
on_treeview_cap_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

GtkTreeIter iter;

gchar* ref;
gchar* type;
gchar* marque;
gint* val;
gint* act;
capteur cap;


GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if(gtk_tree_model_get_iter(model, &iter ,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model), &iter,0,&ref ,1, &type, 2, &marque, 3, &val , 4 , &act, -1);

strcpy(cap.reference,ref);
strcpy(cap.type,type);
strcpy(cap.marque,marque);
cap.valeur=val;
cap.activite=act;

supprimer_cap(cap);
gtk_list_store_remove(GTK_LIST_STORE(model), &iter);

}}


void
on_button_recherche_cap_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
char ref[20];
GtkWidget* input ;
GtkWidget *treeview_cap;
input = lookup_widget(objet, "recherche_cap") ;
strcpy(ref,gtk_entry_get_text(GTK_ENTRY(input)));
GtkWidget* mouna_gestion_cap ;
mouna_gestion_cap=lookup_widget(objet,"mouna_gestion_cap");
treeview_cap=lookup_widget(mouna_gestion_cap,"treeview_cap");
chercher_cap(treeview_cap,ref);
}





void
on_button_ajout_cap_accueil_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mouna_ajouter_cap;
GtkWidget *mouna_gestion_cap;
mouna_gestion_cap=lookup_widget(objet,"mouna_gestion_cap");

gtk_widget_destroy(mouna_gestion_cap);
mouna_ajouter_cap=create_mouna_ajouter_cap();
gtk_widget_show(mouna_ajouter_cap);
}


void
on_button_modif_cap_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview_cap;
GtkWidget* mouna_reference_modifier ;
GtkWidget* mouna_gestion_cap ;
mouna_gestion_cap=lookup_widget(objet,"mouna_gestion_cap");
gtk_widget_destroy(mouna_gestion_cap);

mouna_reference_modifier=create_mouna_reference_modifier();
gtk_widget_show(mouna_reference_modifier);

}


void
on_button_type_cap_clicked                          (GtkWidget       *objet,
                                        gpointer         user_data)
{
char typecap[20];
GtkWidget *comboboxentry_cap_acceuil;
GtkWidget *treeview_cap;
GtkWidget *mouna_gestion_cap;
mouna_gestion_cap=lookup_widget(objet,"mouna_gestion_cap");
comboboxentry_cap_acceuil=lookup_widget(objet,"comboboxentry_cap_acceuil");

strcpy(typecap,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry_cap_acceuil)));
gtk_widget_destroy(mouna_gestion_cap);

mouna_gestion_cap=create_mouna_gestion_cap();
gtk_widget_show(mouna_gestion_cap);
treeview_cap=lookup_widget(mouna_gestion_cap,"treeview_cap");
if(strcmp(typecap,"Temperature")==0)
{consulter_temperature_cap(treeview_cap);}
else if (strcmp(typecap,"Humidite")==0) 
{consulter_humidite_cap(treeview_cap);}
else consulter_cap(treeview_cap);
}

void
on_button_ajout_cap_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mouna_gestion_cap;
GtkWidget *mouna_ajouter_cap;
GtkWidget *treeview_cap;
mouna_ajouter_cap=lookup_widget(objet,"mouna_ajouter_cap");
mouna_gestion_cap=lookup_widget(objet,"mouna_gestion_cap");
gtk_widget_destroy(mouna_ajouter_cap);
mouna_gestion_cap=create_mouna_gestion_cap();
gtk_widget_show(mouna_gestion_cap);

treeview_cap=lookup_widget(mouna_gestion_cap,"treeview_cap");

consulter_cap(treeview_cap);
}


void
on_check_ajout_cap1_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{choix_cap[0]=1;}
}


void
on_check_ajout_cap2_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{choix_cap[1]=1;}
}


void
on_radioact_ajout_cap_act_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
radio_act=1;
}


void
on_radio_ajout_cap_inact_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
radio_act=0;
}


void
on_buttonajout_cap_enregistre_clicked  (GtkWidget *objet_graphique,
                                        	gpointer         user_data)
{

GtkWidget* input ;
GtkWidget* combobox_ajout_cap;
GtkWidget* mouna_Ajout_val;
GtkWidget *treeview_cap;
GtkWidget *mouna_ajouter_cap;
GtkWidget *mouna_gestion_cap;
GtkWidget *entry_ref_ajout_cap;

capteur cap;

mouna_ajouter_cap=lookup_widget(objet_graphique,"mouna_ajouter_cap");
input= lookup_widget(mouna_ajouter_cap, "entry_ref_ajout_cap") ;
strcpy(cap.reference,gtk_entry_get_text(GTK_ENTRY(input)));

combobox_ajout_cap=lookup_widget(objet_graphique,"combobox_ajout_cap");
strcpy(cap.marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_ajout_cap)));

mouna_Ajout_val=lookup_widget(objet_graphique,"mouna_Ajout_val");
cap.valeur=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mouna_Ajout_val));

if (choix_cap[0]==1) {strcpy(cap.type,"Humidite");}
else {strcpy(cap.type,"Temperature");}

cap.activite=radio_act;
ajouter_cap(&cap);

mouna_gestion_cap=lookup_widget(objet_graphique,"mouna_gestion_cap");

gtk_widget_destroy(mouna_ajouter_cap);
mouna_gestion_cap=create_mouna_gestion_cap();
gtk_widget_show(mouna_gestion_cap);

treeview_cap=lookup_widget(mouna_gestion_cap,"treeview_cap");
consulter_cap(treeview_cap);

}


void
on_back_demande_cap_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview_cap;
GtkWidget *mouna_gestion_cap;
GtkWidget *mouna_reference_modifier;

mouna_reference_modifier=lookup_widget(objet,"mouna_reference_modifier");
mouna_gestion_cap=lookup_widget(objet,"mouna_gestion_cap");
mouna_gestion_cap=create_mouna_gestion_cap();
gtk_widget_show(mouna_gestion_cap);

treeview_cap=lookup_widget(mouna_gestion_cap,"treeview_cap");

consulter_cap(treeview_cap);

gtk_widget_destroy(mouna_reference_modifier);


}


void
on_button_demande_cap_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *mouna_modifier_cap;
GtkWidget *mouna_reference_modifier;
GtkWidget *input;
GtkWidget *entry_ref_demande_cap;
GtkWidget *treeview_cap;


mouna_modifier_cap=lookup_widget(objet,"mouna_modifier_cap");

mouna_reference_modifier=lookup_widget(objet,"mouna_reference_modifier");

input= lookup_widget(mouna_reference_modifier, "entry_ref_demande_cap") ;
strcpy(refe,gtk_entry_get_text(GTK_ENTRY(input)));


mouna_modifier_cap=create_mouna_modifier_cap();
gtk_widget_show(mouna_modifier_cap);

gtk_widget_destroy(mouna_reference_modifier);
}


void
on_back_mouna_part2_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview_cap;
GtkWidget *mouna_gestion_cap;
GtkWidget *mouna_partie2;

mouna_partie2=lookup_widget(objet,"mouna_partie2");
mouna_gestion_cap=lookup_widget(objet,"mouna_gestion_cap");
mouna_gestion_cap=create_mouna_gestion_cap();
gtk_widget_show(mouna_gestion_cap);

treeview_cap=lookup_widget(mouna_gestion_cap,"treeview_cap");

consulter_cap(treeview_cap);

gtk_widget_destroy(mouna_partie2);

}


void
on_button_aff_cap_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget* aff;
GtkWidget* spinbutton_day_cap;
GtkWidget* spinbutton_month_cap;
GtkWidget* spinbutton_year_cap;
GtkWidget* mouna_partie2;
GtkWidget *treeview_mounap2;
int day, month, year;
char txt[200];
spinbutton_day_cap=lookup_widget(objet,"spinbutton_day_cap");
day=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_day_cap));


spinbutton_month_cap=lookup_widget(objet,"spinbutton_month_cap");
month=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_month_cap));

spinbutton_year_cap=lookup_widget(objet,"spinbutton_year_cap");
year=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_year_cap));

aff=lookup_widget(objet,"aff_mounap2");

cap_alarm(txt,day, month, year);
gtk_label_set_text(GTK_LABEL(aff),txt);

}

void
on_part2_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mouna_gestion_cap;
GtkWidget *mouna_partie2;

mouna_partie2=lookup_widget(objet,"mouna_partie2");
mouna_gestion_cap=lookup_widget(objet,"mouna_gestion_cap");
mouna_partie2=create_mouna_partie2();
gtk_widget_show(mouna_partie2);
gtk_widget_destroy(mouna_gestion_cap);
}
void
on_check_modifi_cap1_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{choix_cap[0]=1;}
}


void
on_check_modifi_cap2_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{choix_cap[1]=1;}
}


void
on_radio_act_mod_cap_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
radio_act=1;
}


void
on_radio_inact_mod_cap_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
radio_act=0;
}


void
on_back_modifie_ca_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mouna_gestion_cap;
GtkWidget *mouna_modifier_cap;
GtkWidget *treeview_cap;
mouna_modifier_cap=lookup_widget(objet,"mouna_modifier_cap");
mouna_gestion_cap=lookup_widget(objet,"mouna_gestion_cap");

mouna_gestion_cap=create_mouna_gestion_cap();
gtk_widget_show(mouna_gestion_cap);
treeview_cap=lookup_widget(mouna_gestion_cap,"treeview_cap");

consulter_cap(treeview_cap);
gtk_widget_destroy(mouna_modifier_cap);
}


void
on_button_mod_cap_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget* input ;
GtkWidget* combobox_modifi_cap;
GtkWidget* mouna_modifi_val;
GtkWidget *treeview_cap;
GtkWidget *mouna_modifier_cap;
GtkWidget *mouna_gestion_cap;
GtkWidget *entry_ref_ajout_cap;
capteur cap;

mouna_gestion_cap=lookup_widget(objet_graphique,"mouna_gestion_cap");

mouna_modifier_cap=lookup_widget(objet_graphique,"mouna_modifier_cap");



input= lookup_widget(mouna_modifier_cap, "entry_ref_mod_cap") ;
strcpy(cap.reference,gtk_entry_get_text(GTK_ENTRY(input)));

combobox_modifi_cap=lookup_widget(objet_graphique,"combobox_modifi_cap");
strcpy(cap.marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_modifi_cap)));

mouna_modifi_val=lookup_widget(objet_graphique,"mouna_modifi_val");
cap.valeur=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mouna_modifi_val));

if (choix_cap[0]==1) {strcpy(cap.type,"Humidite");}
else {strcpy(cap.type,"Temperature");}

cap.activite=radio_act;

modifier_cap(cap,refe);
gtk_widget_destroy(mouna_modifier_cap);

mouna_gestion_cap=create_mouna_gestion_cap();

gtk_widget_show(mouna_gestion_cap);

treeview_cap=lookup_widget(mouna_gestion_cap,"treeview_cap");

consulter_cap(treeview_cap);



}


void
on_button_mcap_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *youssef_f0;
GtkWidget *mouna_gestion_cap;
GtkWidget *treeview_cap;

youssef_f0=lookup_widget(objet,"youssef_f0");

gtk_widget_destroy(youssef_f0);
mouna_gestion_cap=lookup_widget(objet,"mouna_gestion_cap");
mouna_gestion_cap=create_mouna_gestion_cap();

gtk_widget_show(mouna_gestion_cap);

treeview_cap=lookup_widget(mouna_gestion_cap,"treeview_cap");

consulter_cap(treeview_cap);
}


void
on_buttonaffichersirinego_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)
{
char typeposte[20];
GtkWidget *comboboxsir;
GtkWidget *treeviewsirinego;
GtkWidget *windowsirinegestionouvrier;
windowsirinegestionouvrier=lookup_widget(objet,"windowsirinegestionouvrier");
comboboxsir=lookup_widget(objet,"comboboxsir");

strcpy(typeposte,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxsir)));
gtk_widget_hide(windowsirinegestionouvrier);

windowsirinegestionouvrier=create_windowsirinegestionouvrier();
gtk_widget_show(windowsirinegestionouvrier);
treeviewsirinego=lookup_widget(windowsirinegestionouvrier,"treeviewsirinego");
if(strcmp(typeposte,"Financier")==0)
{financier_ouvrier();
consulter_Financier_ouvrier(treeviewsirinego);}
else if (strcmp(typeposte,"Agricole")==0) 
{agricole_ouvrier();
consulter_Agricole_ouvrier(treeviewsirinego);}
else consulter_ouvrier_sirine(treeviewsirinego);
}


void
on_buttongouvriersirine_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *youssef_f0;
GtkWidget *windowsirinegestionouvrier;
GtkWidget *treeviewsirinego;

youssef_f0=lookup_widget(objet,"youssef_f0");

gtk_widget_destroy(youssef_f0);
windowsirinegestionouvrier=lookup_widget(objet,"windowsirinegestionouvrier");
windowsirinegestionouvrier=create_windowsirinegestionouvrier();

gtk_widget_show(windowsirinegestionouvrier);

treeviewsirinego=lookup_widget(windowsirinegestionouvrier,"treeviewsirinego");

consulter_ouvrier_sirine(treeviewsirinego);
}




