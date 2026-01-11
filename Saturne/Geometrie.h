#ifndef GEOMETRIE_H_
#define GEOMETRIE_H_

#include <cmath>
#include <cstdio>
#include <string>

using namespace std;

// Tâche : Calcule la distance entre deux points (x1, y1) et (x2, y2).
// Données : Coordonnées des points (x1, y1) et (x2, y2).
// Résultat : Distance entre les deux points.
inline double distance(double x1, double y1, double x2, double y2)
{
    double dx = x2 - x1;
    double dy = y2 - y1;
    double d2 = dx * dx + dy * dy; // Théorème de Pythagore
    return sqrt(d2);
}

// Tâche : Vérifie si un point (x, y) est à l'intérieur d'une ellipse.
// Données : Coordonnées du point (x, y), centre (x0, y0), grands et petits axes (a, b).
// Résultat : Vrai si le point est à l'intérieur de l'ellipse, sinon faux.
inline bool estDansEllipse(double x, double y, double x0, double y0, double a, double b)
{
    // Calcul des termes pour simplifier la condition
    double term1 = (x - x0) / a;
    double term2 = (y - y0) / b;

    // Vérifie si le point est à l'intérieur de l'ellipse
    return (term1 * term1 + term2 * term2 <= 1);
}

// Tâche : Vérifie si un point (x, y) est à l'intérieur d'un anneau elliptique.
// Données : Coordonnées du point (x, y), centre (x0, y0), dimensions des deux ellipses (a1, b1, a2, b2).
// Résultat : Vrai si le point est à l'intérieur de l'anneau elliptique, sinon faux.
inline bool estDansAnneauElliptique(double x, double y, double x0, double y0, double a1,
                                    double b1, double a2, double b2)
{
    // Vérifie si le point est à l'intérieur de la première ellipse
    bool estDansEllipse1 = estDansEllipse(x, y, x0, y0, a1, b1);

    // Vérifie si le point est à l'intérieur de la deuxième ellipse
    bool estDansEllipse2 = estDansEllipse(x, y, x0, y0, a2, b2);

    // Vérifie si le point est dans l'anneau elliptique (à l'intérieur de la 2eme et à l'extérieur de la 1ere)
    return estDansEllipse2 && !estDansEllipse1;
}

// Tâche : Vérifie si un point (x, y) est à l'intérieur d'un demi-anneau elliptique arrière.
// Données : Coordonnées du point (x, y), centre (x0, y0), dimensions des deux ellipses (a1, b1, a2, b2).
// Résultat : Vrai si le point est à l'intérieur du demi-anneau elliptique arrière, sinon faux.
inline bool estDansDemiAnneauElliptiqueArriere(double x, double y, double x0, double y0, double a1,
                                               double b1, double a2, double b2)
{
    // Vérifie si le point est à l'intérieur de l'anneau elliptique et à gauche du centre
    return estDansAnneauElliptique(x, y, x0, y0, a1, b1, a2, b2) && (y <= y0);
}

// Tâche : Vérifie si un point (x, y) est à l'intérieur d'un demi-anneau elliptique droit.
// Données : Coordonnées du point (x, y), centre (x0, y0), dimensions des deux ellipses (a1, b1, a2, b2).
// Résultat : Vrai si le point est à l'intérieur du demi-anneau elliptique droit, sinon faux.
inline bool estDansDemiAnneauElliptiqueAvant(double x, double y, double x0, double y0, double a1,
                                             double b1, double a2, double b2)
{
    // Vérifie si le point est à l'intérieur de l'anneau elliptique et à droite du centre
    return estDansAnneauElliptique(x, y, x0, y0, a1, b1, a2, b2) && (y >= y0);
}

// Tâche : Calcule |f(x, y)| pour une ellipse.
// Données : Coordonnées du point (x, y), centre (x0, y0), grands et petits axes (a, b).
// Résultat : |f(x, y)| pour l'ellipse.
inline double calculerDistanceEllipse(double x, double y, double x0, double y0, double a, double b)
{
    double term1 = (x - x0) / a;
    double term2 = (y - y0) / b;
    return fabs((term1 * term1 + term2 * term2) - 1);
}

// Tâche : Calcule F(x, y) pour une ellipse inclinée.
// Données : Coordonnées du point (x, y), centre (x0, y0), dimensions (a, b),
//           paramètres d'inclinaison (p, q).
// Résultat : F(x, y) pour l'ellipse inclinée.
double calculerDistanceEllipseDiagonale(double x, double y, double x0, double y0,
                                        double a, double b, double p, double q)
{
    double dx = x - x0;
    double dy = y - y0;

    double u = p * dx + q * dy;
    double v = -q * dx + p * dy;

    // Calcul de F(x, y)
    double Fxy = (u * u) / (a * a) + (v * v) / (b * b) - 1;

    return Fxy;
}

//----------------------------//
//------ANNEXE PARTIE 11------//
//----------------------------//

// Tâche : Vérifie si un point (x, y) est à l'intérieur d'une ellipse inclinée.
// Données : Coordonnées du point (x, y), centre (x0, y0), dimensions (a, b),
//           paramètres d'inclinaison (p, q).
// Résultat : Vrai si le point est à l'intérieur de l'ellipse inclinée, sinon faux.
inline bool estDansEllipseIncline(double x, double y, double x0, double y0, double a,
                                  double b, double p, double q)
{
    double dx = x - x0;
    double dy = y - y0;

    double u = p * dx + q * dy;
    double v = -q * dx + p * dy;

    // Calcul de F(x, y)
    double Fxy = (u * u) / (a * a) + (v * v) / (b * b) - 1;

    return Fxy <= 0;
}

// Tâche : Vérifie si un point (x, y) est à l'intérieur d'un anneau elliptique incliné.
// Données : Coordonnées du point (x, y), centre (x0, y0), dimensions des deux ellipses (a1, b1, a2, b2),
//           paramètres d'inclinaison (p, q).
// Résultat : Vrai si le point est à l'intérieur de l'anneau elliptique incliné, sinon faux.
inline bool estDansAnneauElliptiqueIncline(double x, double y, double x0, double y0, double a1, double b1,
                                           double a2, double b2, double p, double q)
{
    // Vérifie si le point est à l'intérieur de la première ellipse
    bool estDansEllipse1 = estDansEllipseIncline(x, y, x0, y0, a1, b1, p, q);

    // Vérifie si le point est à l'intérieur de la deuxième ellipse
    bool estDansEllipse2 = estDansEllipseIncline(x, y, x0, y0, a2, b2, p, q);

    // Vérifie si le point est dans l'anneau elliptique (à l'intérieur de la 2eme et à l'extérieur de la 1ere)
    return estDansEllipse2 && !estDansEllipse1;
}

// Tâche : Vérifie si un point (x, y) est à l'intérieur d'un demi-anneau elliptique arrière incliné.
// Données : Coordonnées du point (x, y), centre (x0, y0), dimensions des deux ellipses (a1, b1, a2, b2),
//           paramètres d'inclinaison (p, q).
// Résultat : Vrai si le point est à l'intérieur du demi-anneau elliptique arrière incliné, sinon faux.
inline bool estDansDemiAnneauElliptiqueArriereIncline(double x, double y, double x0, double y0, double a1,
                                                      double b1, double a2, double b2, double p, double q)
{
    // Vérifie si le point est à l'intérieur de l'anneau elliptique et à gauche du centre
    return estDansAnneauElliptiqueIncline(x, y, x0, y0, a1, b1, a2, b2, p, q) && (y <= y0);
}

// Tâche : Vérifie si un point (x, y) est à l'intérieur d'un demi-anneau elliptique droit incliné.
// Données : Coordonnées du point (x, y), centre (x0, y0), dimensions des deux ellipses (a1, b1, a2, b2),
//           paramètres d'inclinaison (p, q).
// Résultat : Vrai si le point est à l'intérieur du demi-anneau elliptique droit incliné, sinon faux.
inline bool estDansDemiAnneauElliptiqueAvantIncline(double x, double y, double x0, double y0, double a1,
                                                    double b1, double a2, double b2, double p, double q)
{
    // Vérifie si le point est à l'intérieur de l'anneau elliptique et à droite du centre
    return estDansAnneauElliptiqueIncline(x, y, x0, y0, a1, b1, a2, b2, p, q) && (y >= y0);
}

#endif