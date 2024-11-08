/*
   Titre: Exercice BMI
   Auteurs: ASSOUN A.K.Rodrigue; MESSAN Elom Ra�ssa
   Ecole: EPL
   Fili�re:LP GL S2
   Ann�e Acad�mique: 2023-2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_CTYPE,"");
    //d�claration des variables
    int poids;
    float taille,PI,BMI;
    char sexe,Etat, answer;

    //d�but du programme
    do
    {
        system("cls");
        printf("Programme de calcul du poids th�orique par la formule de Lorenz\n");
        do
        {
            printf("\nEntrez votre sexe sous la forme (M/F) : ");
            scanf("%c",&sexe);
            fflush(stdin);
            //Verification de l'entr�e
            if (sexe!='M'&& sexe!='F')
            {
                printf("\n Erreur...Veuillez entrer un caract�re entre M et F : ");
            }
        }
        while(sexe!='M'&& sexe!='F');

        do
        {
            printf("\nEntrez votre Taille en Cm             : ");
            scanf("%f",&taille);
            fflush(stdin);
            //v�rification de la taille entr�e
            if (taille<0 || taille>400)
            {
                printf("\nErreur... Entrez une taille entre 0 et 400Cm");
            }
        }
        while(taille<0 || taille>400);

        do
        {
            printf("\nEntrez votre Poids                    : ");
            //V�rifiaction du poids entrer
            scanf("%d",&poids);
            if (poids<0)
            {
                printf("\nErreur, entrez un poids sup�rieur � z�ro");
            }
        }
        while(poids<0);
        //Calcule du poids th�orique
        if (sexe=='M')
        {
            PI=(taille-100)-(taille-150)/4;
        }
        else if (sexe=='F')
        {
            PI=(taille-100)-(taille-120)/4;
        }
        //Calcule de l'indicateurs de l'ob�sit�
        taille=taille/100;
        BMI=poids/(pow(taille,2));
        //V�rification d'Etat D'ob�sit�
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
        printf("\nVotre poids th�orique est  : PI = %.2f",PI);
        printf("\nL'indicateur d'ob�sit� est : BMI = %.2f ",BMI);
        printf("\nVous �tes en �tat          : %c  ",Etat);
        printf("\nL'abr�viation selon l'�tat est (M)Malade,(N)Normal,(O)Ob�se. ");

        fflush(stdin);
        printf("\nVoulez-vous ex�cuter encore (O/N) : ");
        scanf("%c", &answer);

    }
    while(answer=='O');
    return 0 ;
}
