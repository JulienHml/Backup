# Backup v1.0.0 - uniquement pour Windows
*Backup* vous permet de cr�er simplement une sauvegarde de vos fichiers sur votre ordinateur Windows.
Il vous permet de s�lectionner plusieurs dossiers de votre choix, ce qui �vite les copies de dossiers syst�me et de dossiers de programme.
Par exemple, le dossier *Mes documents* est souvent remplis de fichiers g�n�r�s pas certains programmes, *Backup* vous permet de faire le tri pour une sauvegarde pertinente.

### Les dossiers a copier
Voici un exemple du fichier "input_folders.txt".
Vous y placerez les chemins absolue de tous les dossiers a copier.
![input folders](/public/inputs.png)

### Le r�pertoire de sortie
Pour le fichier "output_folders.txt", vous y placerez le seul chemin absolu de sortie.
*Backup* y cr�era un sous-dosssier � cet emplacement.
![output folder](/public/output.png)

### Recommandations
- Compresser la sauvegarde (en .zip par exemple).
- Chiffrer le dossier, particuli�rement si il est plac� sur un support amovible (avec [VeraCrypt](https://www.veracrypt.fr/en/Home.html) par exemple).
- Enregistrer la sauvegarde sur un disque dur externe.

### Planificateur de t�ches de Windows
Il peut �tre int�ressant d'enregistrer *Backup* dans le planificateur de t�ches du syst�me.
Une ex�cution hebdomadaire est s�rement une bon choix, � vous de voire.