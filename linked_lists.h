#ifndef LINKED_LISTS_H_INCLUDED
#define LINKED_LISTS_H_INCLUDED

typedef struct Noeud{
    char* Valeur;
    struct Noeud* Suivant;
}Noeud;


typedef struct{
    Noeud* tete;
}Liste;

typedef struct Noeud_liste{
    Liste Valeur;
    struct Noeud_liste* Suivant;
}Noeud_liste;

typedef struct{
    Noeud_liste* tete;
}Liste_de_Liste;

void initialiser_liste(Liste*);
void ajouter_element(Liste*, char*);
void afficher_liste(Liste*);
char* retirer_element(Liste*);
unsigned int longeur_liste(Liste*);
void detruire_liste(Liste*);

void initialiser_liste_de_liste(Liste_de_Liste*);
void ajouter_liste(Liste_de_Liste*, Liste);
void afficher_liste_de_liste(Liste_de_Liste*);
Liste retirer_liste(Liste_de_Liste*);
unsigned int longeur_liste_de_liste(Liste_de_Liste*);
void afficher_element_liste_de_liste(Liste*);
void detruire_liste_de_liste(Liste_de_Liste*);

#endif