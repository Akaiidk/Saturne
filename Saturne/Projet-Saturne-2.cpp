// Création du projet de la planète Saturne : disque Saturne couleur en dégradé

#include <cmath>
#include <cstdio>
#include <string>
#include "OutilsCreationImage.h"
#include "Geometrie.h"
#include "Couleur.h"
using namespace std;

int main()
{
    printf("creation d'une image de la planete saturne\n");

    // chemin du dossier de sauvegarde, relatif
    // c'est-à-dire à partir du dossier courant
    string chemin = "images_creees";
    string nomFichierImage = chemin + "\\Saturne2.bmp";

    const int HAUTEUR = 428;
    const int LARGEUR = 760;

    // Initialisation des dimensions de l'image
    int x = HAUTEUR - 1;
    int y = LARGEUR - 1;

    // Calcul des coordonnées du centre et du rayon de Saturne
    double xCentreSaturne = 0.5 * x;
    double yCentreSaturne = 0.5 * y;
    double rayonSaturne = 0.25 * x;

    // Calcul des coordonnées du centre et du rayon de la tache de Saturne
    double xT = 0.80 * xCentreSaturne;
    double yT = 0.85 * yCentreSaturne;
    double rT = rayonSaturne + distance(yT, xT, yCentreSaturne, xCentreSaturne);

    // Définition des couleurs
    unsigned long Rouge = 0xFF0000FF;
    unsigned long Orange = 0xFF9D00FF;
    unsigned long Blanc = 0xFFFFFFFF;
    unsigned long Transparent = 0x00009000;

    // Matrice de pixels pour l'image
    unsigned long matricePixels[HAUTEUR][LARGEUR];

    // Boucles pour remplir la matrice de pixels
    int i, j;
    for (i = 0; i <= x; ++i)
        for (j = 0; j <= y; ++j)
        {
            unsigned long couleur = Transparent;

            if (distance(yCentreSaturne, xCentreSaturne, j, i) <= rayonSaturne)
            {
                couleur = obtenirCouleurSaturne(j, i, yT, xT, rT, Blanc, Orange, Rouge);
            }

            // Attribution de la couleur à la matrice de pixels
            matricePixels[i][j] = couleur;
        }

    // Création de l'image
    OutilsCreationImage::creeImage(nomFichierImage, matricePixels, HAUTEUR);

    printf("image creee");
    return 0;
}