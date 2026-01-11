#ifndef COULEUR_H_
#define COULEUR_H_

#include <cmath>
#include <cstdio>
#include <string>

using namespace std;

// Tâche : Mélange deux couleurs (c1 et c2) en fonction d'un coefficient a.
// Données : Coefficient de mélange a, couleurs c1 et c2.
// Résultat : Couleur mélangée.
inline unsigned long melange(double a, unsigned long c1, unsigned long c2)
{
    unsigned long Couleur = 0;

    // Boucle pour mélanger les composants (R, G, B, A)
    for (int i = 0; i < 4; ++i) // R, G, B, A
    {
        // Extrait le composant i (R, G, B, A) de c1
        double r1 = ((c1 >> (24 - i * 8)) & 0xFF);

        // Extrait le composant i (R, G, B, A) de c2
        double r2 = ((c2 >> (24 - i * 8)) & 0xFF);

        // Effectue le mélange linéaire pondéré des composants en fonction de 'a'
        // et les arrondit à la valeur entière la plus proche
        unsigned long composantMelange = lround((1 - a) * r1 + a * r2);

        // Assemble le composant mélangé dans la variable de couleur finale
        // en le décalant à la position correcte dans la valeur finale
        Couleur |= composantMelange << (24 - i * 8);
    }

    // Retourne la couleur mélangée
    return Couleur;
}

// Tâche : Obtient la couleur d'une tache saturnienne en fonction des coordonnées (j, i).
// Données : Coordonnées (j, i), centre de la tache (yT, xT), rayon de la tache (rT),
//           couleurs de mélange (c1, c2, c3).
// Résultat : Couleur obtenue en fonction de la position dans la tache.
inline unsigned long obtenirCouleurSaturne(double j, double i, double yT, double xT, double rT,
                                           unsigned long c1, unsigned long c2, unsigned long c3)
{
    // Calcule la distance entre le centre de la tache et un point de coordonnée (j, i)
    // la distance est divisé par rT pour obtenir des valeurs comprises entre 0 et 1
    // à l'intérieur de la tache
    double dT = distance(yT, xT, j, i) / rT;
    unsigned long couleur;

    if (dT < 0.5)
    {
        // Mélange du Blanc au Jaune pour rT/2
        couleur = melange(2 * dT, c1, c2);
    }
    else
    {
        // Mélange avec la couleur Orange pour rT
        // on fait dT-0.5 car déjà fait plus haut
        couleur = melange(2 * (dT - 0.5), c2, c3);
    }
    return couleur;
}

// Tâche : Obtient la couleur à l'intérieur d'un anneau elliptique.
// Données : Coordonnées (x, y), centre de l'ellipse (x0, y0), dimensions de l'ellipse (a, b),
//           dimensions de l'ellipse interne (aInt, bInt), couleurs de début et de fin, nuance.
// Résultat : Couleur obtenue à l'intérieur de l'anneau elliptique.
inline unsigned long obtenirCouleurAnneau(double x, double y, double x0, double y0, double a, double b,
                                          double aInt, double bInt, unsigned long couleurDebut,
                                          unsigned long couleurFin, double nuance)
{
    // Calculer la distance à l'intérieur de l'ellipse
    double distance = calculerDistanceEllipse(x, y, x0, y0, a, b);
    double distanceInt = calculerDistanceEllipse(x, y, x0, y0, pow(aInt, 2), pow(bInt, 2));

    // Normaliser la distance entre 0 et 1
    double DistanceNormalisee = distance / distanceInt;

    // Utiliser la distance normalisée pour obtenir la couleur
    return melange(nuance * DistanceNormalisee, couleurDebut, couleurFin);
}

// Tâche : Assombrit une couleur en fonction d'un coefficient.
// Données : Couleur d'origine, coefficient d'assombrissement.
// Résultat : Couleur assombrie.
unsigned long assombrirCouleur(unsigned long couleur, double coefficient)
{
    unsigned long noir = 0x000000FF;

    // Mélanger la couleur avec du noir en fonction du coefficient
    unsigned long couleurAssombrie = melange(coefficient, couleur, noir);

    return couleurAssombrie;
}

// Tâche : Obtient la couleur à l'intérieur d'un anneau elliptique assombri.
// Données : Coordonnées (x, y), centre de l'ellipse (x0, y0), rayon, dimensions de l'ellipse (a, b),
//           dimensions de l'ellipse interne (aS, bS), paramètres d'inclinaison (pS, qS),
//           couleurs de début et de fin, nuance.
// Résultat : Couleur obtenue à l'intérieur de l'anneau elliptique assombri.
unsigned long obtenirCouleurAnneauAssombrie(double x, double y, double x0, double y0, double rayon,
                                            double a, double b, double aS, double bS,
                                            double pS, double qS, unsigned long couleurDebut,
                                            unsigned long couleurFin, double nuance)
{
    // Utiliser la fonction obtenirCouleurPAnneau pour obtenir la couleur de base
    unsigned long couleur = obtenirCouleurAnneau(x, y, x0, y0, a, b, aS, bS, couleurDebut, couleurFin, nuance);

    // Assombrir la couleur uniquement à l'intérieur de l'ellipse diagonale
    double distanceEllipseDiagonale = fabs(calculerDistanceEllipseDiagonale(x, y, x0, y0, aS, bS, pS, qS));

    // Si le point est à l'intérieur de l'ellipse diagonale
    if (distanceEllipseDiagonale <= rayon)
    {
        double coefficientAssombrissement = 0.6; // Vous pouvez ajuster ce coefficient
        couleur = assombrirCouleur(couleur, coefficientAssombrissement);
    }

    return couleur;
}

//----------------------------//
//------ANNEXE PARTIE 11------//
//----------------------------//

// Tâche : Obtient la couleur à l'intérieur d'un anneau elliptique incliné.
// Données : Coordonnées (x, y), centre de l'ellipse (x0, y0), dimensions de l'ellipse (a, b),
//           dimensions de l'ellipse interne (aInt, bInt), couleurs de début et de fin, nuance,
//           paramètres d'inclinaison (p, q).
// Résultat : Couleur obtenue à l'intérieur de l'anneau elliptique incliné.
inline unsigned long obtenirCouleurAnneauIncline(double x, double y, double x0, double y0, double a, double b,
                                                 double aInt, double bInt, unsigned long couleurDebut,
                                                 unsigned long couleurFin, double nuance, double p, double q)
{
    // Calculer la distance à l'intérieur de l'ellipse
    double distance = fabs(calculerDistanceEllipseDiagonale(x, y, x0, y0, a, b, p, q));
    double distanceInt = fabs(calculerDistanceEllipseDiagonale(x, y, x0, y0, pow(aInt, 2), pow(bInt, 2), p, q));

    // Normaliser la distance entre 0 et 1
    double DistanceNormalisee = distance / distanceInt;

    // Utiliser la distance normalisée pour obtenir la couleur
    return melange(nuance * DistanceNormalisee, couleurDebut, couleurFin);
}

// Tâche : Obtient la couleur à l'intérieur d'un anneau elliptique incliné assombri.
// Données : Coordonnées (x, y), centre de l'ellipse (x0, y0), rayon, dimensions de l'ellipse (a, b),
//           dimensions de l'ellipse interne (aS, bS), paramètres d'inclinaison (pS, qS),
//           couleurs de début et de fin, nuance, paramètres d'inclinaison (p, q).
// Résultat : Couleur obtenue à l'intérieur de l'anneau elliptique incliné assombri.
unsigned long obtenirCouleurAnneauAssombrieIncline(double x, double y, double x0, double y0, double rayon,
                                                   double a, double b, double aS, double bS,
                                                   double pS, double qS, unsigned long couleurDebut,
                                                   unsigned long couleurFin, double nuance, double p, double q)
{
    // Utiliser la fonction obtenirCouleurPAnneau pour obtenir la couleur de base
    unsigned long couleur = obtenirCouleurAnneauIncline(x, y, x0, y0, a, b, aS, bS, couleurDebut, couleurFin, nuance, p, q);

    // Assombrir la couleur uniquement à l'intérieur de l'ellipse diagonale
    double distanceEllipseDiagonale = fabs(calculerDistanceEllipseDiagonale(x, y, x0, y0, aS, bS, pS, qS));

    // Si le point est à l'intérieur de l'ellipse diagonale
    if (distanceEllipseDiagonale <= rayon)
    {
        double coefficientAssombrissement = 0.6; // Vous pouvez ajuster ce coefficient
        couleur = assombrirCouleur(couleur, coefficientAssombrissement);
    }

    return couleur;
}

#endif