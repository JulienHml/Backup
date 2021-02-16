# Backup v1.0.0 - uniquement pour Windows
*Backup* vous permet de créer simplement une sauvegarde de vos fichiers sur votre ordinateur Windows.
Il vous permet de sélectionner plusieurs dossiers de votre choix, ce qui évite les copies de dossiers système et de dossiers de programme.
Par exemple, le dossier *Mes documents* est souvent remplis de fichiers générés pas certains programmes, *Backup* vous permet de faire le tri pour une sauvegarde pertinente.

### Les dossiers a copier
Voici un exemple du fichier "input_folders.txt".
Vous y placerez les chemins absolue de tous les dossiers a copier.
![input folders](/public/inputs.png)

### Le répertoire de sortie
Pour le fichier "output_folders.txt", vous y placerez le seul chemin absolu de sortie.
*Backup* y créera un sous-dosssier à cet emplacement.
![output folder](/public/output.png)

### Recommandations
- Compresser la sauvegarde (en .zip par exemple).
- Chiffrer le dossier, particulièrement si il est placé sur un support amovible (avec [VeraCrypt](https://www.veracrypt.fr/en/Home.html) par exemple).
- Enregistrer la sauvegarde sur un disque dur externe.

### Planificateur de tâches de Windows
Il peut être intéressant d'enregistrer *Backup* dans le planificateur de tâches du système.
Une exécution hebdomadaire est sûrement une bon choix, à vous de voire.