/*
   Titre: Exercice BMI
   Auteurs: ASSOUN A.K.Rodrigue; MESSAN Elom Raïssa
   Ecole: EPL
   Filière:LP GL S2
   Année Académique: 2023-2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_CTYPE,"");
    //déclaration des variables
    int poids;
    float taille,PI,BMI;
    char sexe,Etat, answer;

    //début du programme
    do
    {
        system("cls");
        printf("Programme de calcul du poids théorique par la formule de Lorenz\n");
        do
        {
            printf("\nEntrez votre sexe sous la forme (M/F) : ");
            scanf("%c",&sexe);
            fflush(stdin);
            //Verification de l'entrée
            if (sexe!='M'&& sexe!='F')
            {
                printf("\n Erreur...Veuillez entrer un caractère entre M et F : ");
            }
        }
        while(sexe!='M'&& sexe!='F');

        do
        {
            printf("\nEntrez votre Taille en Cm             : ");
            scanf("%f",&taille);
            fflush(stdin);
            //vérification de la taille entrée
            if (taille<0 || taille>400)
            {
                printf("\nErreur... Entrez une taille entre 0 et 400Cm");
            }
        }
        while(taille<0 || taille>400);

        do
        {
            printf("\nEntrez votre Poids                    : ");
            //Vérifiaction du poids entrer
            scanf("%d",&poids);
            if (poids<0)
            {
                printf("\nErreur, entrez un poids supérieur à zéro");
            }
        }
        while(poids<0);
        //Calcule du poids théorique
        if (sexe=='M')
        {
            PI=(taille-100)-(taille-150)/4;
        }
        else if (sexe=='F')
        {
            PI=(taille-100)-(taille-120)/4;
        }
        //Calcule de l'indicateurs de l'obésité
        taille=taille/100;
        BMI=poids/(pow(taille,2));
        //Vérification d'Etat D'obésité
        if (BMI<=27)
        {
            Etat='N';
        }
        else if (BMI>27)
        {
            Etat='O';
        }
        else if(BMI>=32)
        {
            Etat='M';
        }
        //Affichage
        printf("\nVotre poids théorique est  : PI = %.2f",PI);
        printf("\nL'indicateur d'obésité est : BMI = %.2f ",BMI);
        printf("\nVous êtes en état          : %c  ",Etat);
        printf("\nL'abréviation selon l'état est (M)Malade,(N)Normal,(O)Obèse. ");

        fflush(stdin);
        printf("\nVoulez-vous exécuter encore (O/N) : ");
        scanf("%c", &answer);

    }
    while(answer=='O');
    return 0 ;
}
