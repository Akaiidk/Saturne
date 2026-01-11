// Création du projet de la planète Saturne : demi anneau de Saturne avant, couleur unie

#include <cmath>
#include <cstdio>
#include <string>
#include "OutilsCreationImage.h"
#include "Geometrie.h"
using namespace std;

int main()
{
    printf("creation d'une image de la planete Saturne\n");

    // chemin du dossier de sauvegarde, relatif
    // c'est-à-dire à partir du dossier courant
    string chemin = "images_creees";
    string nomFichierImage = chemin + "\\Saturne5.bmp";

    const int HAUTEUR = 428;
    const int LARGEUR = 760;

    // Initialisation des dimensions de l'image
    int x = HAUTEUR - 1;
    int y = LARGEUR - 1;

    // Calcul des coordonnées du centre et du rayon de Saturne
    double xCentreSaturne = 0.5 * x;
    double yCentreSaturne = 0.5 * y;
    double rayonSaturne = 0.25 * x; // 0.25 par défaut

    // Calcul des rayons de l'anneau de Saturne
    double VariableTailleGrandRayon = 0.305;    // variables pour a, défaut : 0.305
    double VariableTaillePetitRayon = 0.12;     // variables pour b, défaut : 0.12
    double GrandRayonInt = VariableTailleGrandRayon * 0.754 * y;  // a1
    double PetitRayonInt = VariableTaillePetitRayon * 0.75* x;    // b1
    double GrandRayonExt = VariableTailleGrandRayon * 1.246 * y;  // a2
    double PetitRayonExt = VariableTaillePetitRayon * 1.25 * x;   // b2

    // Définition des couleurs
    unsigned long Rouge = 0xFF0000FF;
    unsigned long Orange = 0xFF9D00FF;
    unsigned long Jaune = 0xFFFF6BFF;
    unsigned long Blanc = 0xFFFFFFFF;
    unsigned long Transparent = 0x00009000;

    // Matrice de pixels pour l'image
    unsigned long matricePixels[HAUTEUR][LARGEUR];

    // Boucles pour remplir la matrice de pixels
    for (int i = 0; i <= x; ++i)
    {
        for (int j = 0; j <= y; ++j)
        {
            unsigned long couleur = Transparent; // Couleur du fond

            // Vérifier si le point est à l'intérieur de l'anneau elliptique
            if (estDansDemiAnneauElliptiqueAvant(j, i, yCentreSaturne, xCentreSaturne, GrandRayonInt, PetitRayonInt, GrandRayonExt, PetitRayonExt))
            {
                // Obtenez la couleur de l'anneau
                couleur = Orange;
            }

            matricePixels[i][j] = couleur;
        }
    }

    // Création de l'image
    OutilsCreationImage::creeImage(nomFichierImage, matricePixels, HAUTEUR);

    printf("image creee");
    return 0;
}