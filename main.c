#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#pragma region Exo_1

void invert(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main_Exo1() {
    int a = 10;
    int b = 1;

    printf("Avant: a = %d, b = %d\n", a, b);
    invert(&a, &b);
    printf("Apres invert: a = %d, b = %d\n", a, b);
    return 0;
}

#pragma endregion
#pragma region Exo_2
typedef struct Personne {
    char nom[50];
    int age;
    int taille_cm;
} Personne;

void afficherPersonne(Personne *p) {
    printf("Nom: %s\n", p->nom);
    printf("Age: %d\n", p->age);
    printf("Taille: %d cm\n", p->taille_cm);
}

Personne ajouterPersonne(char *nom, int age, int taille_cm) {
    Personne *p = (Personne *) malloc(sizeof(Personne));
    strcpy(p->nom, nom);
    p->age = age;
    p->taille_cm = taille_cm;
    return *p;
}

int main_Exo2() {
    Personne personnes[5];
    personnes[0] = ajouterPersonne("Jean", 20, 180);
    personnes[1] = ajouterPersonne("Paul", 25, 170);
    personnes[2] = ajouterPersonne("Jacques", 30, 160);
    personnes[3] = ajouterPersonne("Pierre", 35, 150);
    personnes[4] = ajouterPersonne("Marie", 40, 140);

    for (int i = 0; i < sizeof(personnes) / sizeof(personnes[0]); ++i) {
        printf("\nPersonne %d: \n", i + 1);
        afficherPersonne(&personnes[i]);
    }
    return 0;
}

#pragma endregion
#pragma region Exo_3
typedef struct Element {
    int valeur;
    struct Element *next;
} Element;

void addElement(Element **liste, int valeur) {
    Element *newList = (Element *) malloc(sizeof(Element));
    newList->valeur = valeur;
    newList->next = *liste;
    *liste = newList;
}

void afficherListe(Element *liste) {
    Element *courant = liste;
    while (courant != NULL) {
        printf("%d\n", courant->valeur);
        courant = courant->next;
    }
}

void deleteElement(Element **liste, int valeur) {
    Element *courant = *liste;
    Element *precedent = NULL;
    while (courant != NULL) {
        if (courant->valeur == valeur) {
            if (precedent != NULL) {
                precedent->next = courant->next;
            } else {
                *liste = courant->next;
            }
            return;
        }
        precedent = courant;
        courant = courant->next;
    }
}

int main_Exo3() {
    Element *liste = NULL;
    addElement(&liste, 1);
    addElement(&liste, 2);
    addElement(&liste, 3);
    addElement(&liste, 4);
    addElement(&liste, 5);

    printf("Avant suppression: \n");
    afficherListe(liste);
    deleteElement(&liste, 3);
    printf("\nApres suppression: \n");
    afficherListe(liste);
    return 0;
}

#pragma endregion
#pragma region Exo_4
typedef struct Voiture {
    char marque[50];
    char modele[50];
    int annee;
} Voiture;

typedef struct Garage {
    Voiture *voitures;
    struct Garage *next;
} Garage;

void addVoiture(Garage **garage, char *marque, char *modele, int annee) {
    Garage *newGarage = (Garage *) malloc(sizeof(Garage));
    Voiture *voiture = (Voiture *) malloc(sizeof(Voiture));
    strcpy(voiture->marque, marque);
    strcpy(voiture->modele, modele);
    voiture->annee = annee;
    newGarage->voitures = voiture;
    newGarage->next = *garage;
    *garage = newGarage;
}

void afficherGarage(Garage *garage) {
    Garage *courant = garage;
    int index = 1;
    while (courant != NULL) {
        printf("Voiture[%d]: marque:\"%s\" modele:\"%s\" année: \"%d\"\n", index, courant->voitures->marque, courant->voitures->modele, courant->voitures->annee);
        index++;
        courant = courant->next;
    }
}

void supprimerVoiture(Garage **garage, char *modele) {
    Garage *courant = *garage;
    Garage *precedent = NULL;
    while (courant != NULL) {
        if (strcmp(courant->voitures->modele, modele) == 0) {
            if (precedent != NULL) {
                precedent->next = courant->next;
            } else {
                *garage = courant->next;
            }
            return;
        }
        precedent = courant;
        courant = courant->next;
    }
}

int main_Exo4() {
    Garage *garage = NULL;
    addVoiture(&garage, "Renault", "Clio2", 2000);
    addVoiture(&garage, "Citroen", "C3", 2010);
    addVoiture(&garage, "Peugeot", "2008", 2005);

    printf("Avant suppression: \n");
    afficherGarage(garage);
    supprimerVoiture(&garage, "2008");
    printf("\nApres suppression: \n");
    afficherGarage(garage);

    return 0;
}
#pragma endregion

int main(void) {
    printf("Exo_1: \n");
    main_Exo1();
    printf("\nExo_2: ");
    main_Exo2();
    printf("\nExo_3: \n");
    main_Exo3();
    printf("\nExo_4: \n");
    main_Exo4();
    return 0;
}
