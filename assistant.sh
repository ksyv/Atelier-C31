#!/bin/bash
echo "Analyse en cours..."
#On capture le resultat de ls | wc -l
NB_FICHIERS=$(ls | wc -l)

#On fait des maths avec $(())
NIVEAU=$(( NB_FICHIERS * 10 ))

echo "Salut $USER !"
echo "Tu as créé $NB_FICHIERS fichiers ici."
echo "Ton niveau de développeur est de : $NIVEAU XP."