// Création du projet de la planète Saturne : ajout de l'ombre de Saturne

#include <cmath>
#include <cstdio>
#include <string>
#include "OutilsCreationImage.h"
#include "Geometrie.h"
#include "Couleur.h"
using namespace std;

int main()
{
    printf("creation d'une image de la planete Saturne\n");

    // chemin du dossier de sauvegarde, relatif
    // c'est-à-dire à partir du dossier courant
    string chemin = "images_creees";
    string nomFichierImage = chemin + "\\Saturne10.bmp";

    const int HAUTEUR = 428;
    const int LARGEUR = 760;

    // Initialisation des dimensions de l'image
    int x = HAUTEUR - 1;
    int y = LARGEUR - 1;

    // Calcul des coordonnées du centre et du rayon de Saturne
    double xCentreSaturne = 0.5 * x;
    double yCentreSaturne = 0.5 * y;
    double rayonSaturne = 0.25 * x; // 0.25 par défaut

    // Calcul des coordonnées du centre et du rayon de la tache de Saturne
    double xT = 0.80 * xCentreSaturne;
    double yT = 0.85 * yCentreSaturne;
    double rT = rayonSaturne + distance(yT, xT, yCentreSaturne, xCentreSaturne);

    // Calcul des rayons du grand anneau (GA) de Saturne
    double VariableTailleGrandRayon = 0.305;    // variables pour a, défaut : 0.305
    double VariableTaillePetitRayon = 0.12;     // variables pour b, défaut : 0.12
    double GAgrandRayonInt = VariableTailleGrandRayon * 1.026 * y; // a1
    double GApetitRayonInt = VariableTaillePetitRayon * 1.033 * x; // b1
    double GAgrandRayonExt = VariableTailleGrandRayon * 1.246 * y; // a2
    double GApetitRayonExt = VariableTaillePetitRayon * 1.25 * x;  // b2

    // Calcul des rayons du  petit anneau (PA) de Saturne en utilisant les inverse de GA
    double PAgrandRayonInt = VariableTailleGrandRayon * 0.754 * y;
    double PApetitRayonInt = VariableTaillePetitRayon * 0.75 * x;
    double PAgrandRayonExt = VariableTailleGrandRayon * 0.974 * y;
    double PApetitRayonExt = VariableTaillePetitRayon * 0.967 * x;

    // Calcul du repère de la couleur et de la nuance du grand anneau (GA)
    // et petit anneau (PA) de Saturne
    double GAgrandRayonC = (GAgrandRayonInt + GAgrandRayonExt) / 2;
    double GApetitRayonC = (GApetitRayonInt + GApetitRayonExt) / 2;
    double nuanceCouleurGA = 4.5;
    double PAgrandRayonC = (PAgrandRayonInt + PAgrandRayonExt) / 2;
    double PApetitRayonC = (PApetitRayonInt + PApetitRayonExt) / 2;
    double nuanceCouleurPA = 3.5;

    // Calcul de la dimension de l'ombre de Saturne et son inclinaison
    double SOMBREgrandRayon = rayonSaturne * 3;
    double SOMBREpetitRayon = rayonSaturne;
    double SOMBREinclinaisonP = -40 * rayonSaturne / x;
    double SOMBREinclinaisonQ = 30 * rayonSaturne / x;

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

            // Vérifier si le point est à l'intérieur de l'anneau elliptique avant
            if (estDansDemiAnneauElliptiqueAvant(j, i, yCentreSaturne, xCentreSaturne, GAgrandRayonInt, GApetitRayonInt, GAgrandRayonExt, GApetitRayonExt))
            {
                // Obtenez la couleur de l'anneau
                couleur = obtenirCouleurAnneau(j, i, yCentreSaturne, xCentreSaturne, GAgrandRayonC, GApetitRayonC, GAgrandRayonInt, GApetitRayonInt, Jaune, Rouge, nuanceCouleurGA);
            }
            else if (estDansDemiAnneauElliptiqueAvant(j, i, yCentreSaturne, xCentreSaturne, PAgrandRayonInt, PApetitRayonInt, PAgrandRayonExt, PApetitRayonExt))
            {
                // Obtenez la couleur de l'anneau
                couleur = obtenirCouleurAnneau(j, i, yCentreSaturne, xCentreSaturne, PAgrandRayonC, PApetitRayonC, PAgrandRayonInt, PApetitRayonInt, Jaune, Rouge, nuanceCouleurPA);
            }
            // Si le point est à l'intérieur du disque de Saturne et à l'extérieur de
            // l'anneau elliptique avant, mettre la couleur à obtenirCouleurSaturne
            else if (distance(yCentreSaturne, xCentreSaturne, j, i) <= rayonSaturne)
            {
                couleur = obtenirCouleurSaturne(j, i, yT, xT, rT, Blanc, Orange, Rouge);
            }
            // Si le point est à l'intérieur de l'anneau elliptique arrière et à l'extérieur
            // du disque de Saturne, mettre la couleur à obtenirCouleurAnneauIncline avec une partie sombre
            else if (estDansDemiAnneauElliptiqueArriere(j, i, yCentreSaturne, xCentreSaturne, GAgrandRayonInt, GApetitRayonInt, GAgrandRayonExt, GApetitRayonExt))
            {
                // Obtenez la couleur de l'anneau
                couleur = obtenirCouleurAnneau(j, i, yCentreSaturne, xCentreSaturne, GAgrandRayonC, GApetitRayonC, GAgrandRayonInt, GApetitRayonInt, Jaune, Rouge, nuanceCouleurGA);
                
                // Utilisez la fonction obtenirCouleurPAnneauAssombrie pour assombrir la couleur si nécessaire
                couleur = obtenirCouleurAnneauAssombrie(j, i, yCentreSaturne, xCentreSaturne, rayonSaturne, GAgrandRayonC, GApetitRayonC, SOMBREgrandRayon, SOMBREpetitRayon, SOMBREinclinaisonP, SOMBREinclinaisonQ, Jaune, Rouge, nuanceCouleurGA);
            }
            else if (estDansDemiAnneauElliptiqueArriere(j, i, yCentreSaturne, xCentreSaturne, PAgrandRayonInt, PApetitRayonInt, PAgrandRayonExt, PApetitRayonExt))
            {
                // Obtenez la couleur de l'anneau
                couleur = obtenirCouleurAnneau(j, i, yCentreSaturne, xCentreSaturne, PAgrandRayonC, PApetitRayonC, PAgrandRayonInt, PApetitRayonInt, Jaune, Rouge, nuanceCouleurPA);
                
                // Utilisez la fonction obtenirCouleurPAnneauAssombrie pour assombrir la couleur si nécessaire
                couleur = obtenirCouleurAnneauAssombrie(j, i, yCentreSaturne, xCentreSaturne, rayonSaturne, PAgrandRayonC, PApetitRayonC, SOMBREgrandRayon, SOMBREpetitRayon, SOMBREinclinaisonP, SOMBREinclinaisonQ, Jaune, Rouge, nuanceCouleurPA);
            }

            matricePixels[i][j] = couleur;
        }
    }

    // Création de l'image
    OutilsCreationImage::creeImage(nomFichierImage, matricePixels, HAUTEUR);

    printf("image creee");
    return 0;
}