# 🪐 Projet Saturne - Codage Numérique

Ce projet consiste en la création procédurale d'une image de la planète Saturne en **C++**. L'objectif est de générer un fichier image au format `.bmp` en calculant la couleur de chaque pixel à l'aide de formules mathématiques (géométrie dans le plan, équations d'ellipses et calculs de dégradés).

## 🚀 Concept du projet

Le projet est divisé en **11 étapes progressives**. Chaque fichier `Projet-Saturne-X.cpp` représente une étape de construction de l'image finale, permettant de passer d'un simple disque à une planète complète avec des anneaux inclinés, des ombres portées et un fond étoilé.

### Les étapes de création :
1. **Initialisation** : Création du canevas et du fond.
2. **Disque de base** : Tracé de la forme sphérique de la planète.
3. **Dégradés** : Application de nuances de couleurs pour simuler l'éclairage.
4. **Anneaux simples** : Ajout des premières ellipses pour les anneaux.
5. **Inclinaison** : Utilisation de calculs géométriques pour incliner les anneaux.
6. **Transparence & Superposition** : Gestion de l'ordre d'affichage (avant/arrière de la planète).
7. **Ombres portées** : Simulation de l'ombre de la planète sur ses propres anneaux.
8. **Détails des anneaux** : Séparation entre le Grand Anneau (GA) et le Petit Anneau (PA).
9. **Finition & Optimisation** : Ajustement des constantes de taille et de couleur.
10. **Environnement** : Ajout d'un fond étoilé (`ciel_etoile.jpg`).
11. **Finalisation** : Rendu haute définition avec inclinaison personnalisée.

## 🛠️ Stack Technique

* **Langage** : C++
* **Format de sortie** : BMP (Bitmap)
* **Concepts utilisés** : 
    * Géométrie analytique (Ellipses inclinées, calcul de distances).
    * Algorithmes de remplissage de matrices de pixels.
    * Gestion des couleurs (Format ARGB/Hexadécimal).

## 📂 Structure des fichiers

- `Projet-Saturne-1.cpp` à `11.cpp` : Les différentes versions du code source.
- `OutilsCreationImage.h/cpp` : Bibliothèque utilitaire pour l'écriture du fichier BMP.
- `Geometrie.h` & `Couleur.h` : Fonctions mathématiques pour les formes et les dégradés.
- `Saturne.bmp` : Le résultat final généré.

##📸 Aperçu
[Saturne10etoile.bmp](https://github.com/user-attachments/files/24555784/Saturne10etoile.bmp)
[Saturne9.bmp](https://github.com/user-attachments/files/24555783/Saturne9.bmp)
[Saturne6.bmp](https://github.com/user-attachments/files/24555782/Saturne6.bmp)
[Saturne5.bmp](https://github.com/user-attachments/files/24555780/Saturne5.bmp)
[Saturne4.bmp](https://github.com/user-attachments/files/24555779/Saturne4.bmp)
[Saturne1.bmp](https://github.com/user-attachments/files/24555778/Saturne1.bmp)


## ⚙️ Compilation et Exécution

Pour générer une image (exemple avec l'étape 11) :

1. Compilez le projet (via un IDE comme Code::Blocks ou en ligne de commande) :
   ```bash
   g++ Projet-Saturne-11.cpp OutilsCreationImage.cpp -o Saturne
