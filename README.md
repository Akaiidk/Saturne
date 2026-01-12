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

<img width="760" height="428" alt="Saturne10etoile" src="https://github.com/user-attachments/assets/2bb07d82-6cf8-4529-87b0-c1811ead66a8" />
<img width="760" height="428" alt="Saturne10" src="https://github.com/user-attachments/assets/88b92102-cf27-4fd1-819d-d18d729b0c99" />
<img width="760" height="428" alt="Saturne9" src="https://github.com/user-attachments/assets/f93c54bc-c7ca-42f9-9409-3bc6c06af7e4" />
<img width="760" height="428" alt="Saturne8" src="https://github.com/user-attachments/assets/281e62bc-c7ca-4a5c-aacb-a2d9e41594bf" />
<img width="760" height="428" alt="Saturne7" src="https://github.com/user-attachments/assets/dc3f16a5-5527-4923-8544-95eaef64e97a" />
<img width="760" height="428" alt="Saturne6" src="https://github.com/user-attachments/assets/de95d3da-fbbc-477e-b002-bc159c36de70" />
<img width="760" height="428" alt="Saturne5" src="https://github.com/user-attachments/assets/b8a06c57-ec24-4523-a2ed-330c275b2e85" />
<img width="760" height="428" alt="Saturne4" src="https://github.com/user-attachments/assets/b529ce0f-f265-43ce-b997-7cabd7d5efcb" />
<img width="760" height="428" alt="Saturne3" src="https://github.com/user-attachments/assets/874d8821-ebb8-42fd-b254-e4f972fadcc8" />
<img width="760" height="428" alt="Saturne2" src="https://github.com/user-attachments/assets/ff12862b-9392-4441-9942-ea40a557332f" />
<img width="760" height="428" alt="Saturne1" src="https://github.com/user-attachments/assets/de56867c-fd10-4d8c-8788-d9de443bcbf4" />



## ⚙️ Compilation et Exécution

Pour générer une image (exemple avec l'étape 11) :

1. Compilez le projet (via un IDE comme Code::Blocks ou en ligne de commande) :
   ```bash
   g++ Projet-Saturne-11.cpp OutilsCreationImage.cpp -o Saturne
