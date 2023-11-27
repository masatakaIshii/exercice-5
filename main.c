/*
    Filename    :exercice_5

    Created     :31/10/2017

    Made by     :Masataka ISHII

    Description :Programme permettant de calculer le prix d'une petite annonce passee par un client
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    double totalPrice;                  //Prix total des petites annonces
    double firstWeekPrice;              //Prix de la premiere semaine
    double currentPrice;                //Prix courant ou le prix sans la reduction de la premiere semaine
    double typeNews;                    //Type de l'annonce
    double distributionArea;            //Zone de distribution

    double lineCount;                   //Nombre de ligne
    double lineSuppPrice = 7.5;         //Prix en plus pour chaque ligne supplementaire

    double numberWeeks;                 //Nombre de semaine de parution des petites annonces

    double customerCategory;            //Categorie du client pour determiner le taux de reduction
    double reductionRate;               //Taux de reduction

    double years;                       //Demande de l'annee actuel au client pour determiner s'il b�n�ficie de la reduction de premiere semaine
    double proOrPar;                    //Pour determiner si le client est un professionnel ou un particulier
    double reductionFirstWeek;          //Taux de reduction de la premiere semaine

    double anonyma;                     //Pour determiner si le client choisit l'option pour preserver l'anonymat de toute transaction
    double saveCost;                    //Pour sauvegarder le cout de base de l'option
    double anonymaCost;                 //Supplement pour les clients qui veulent preserver l'anonymat de toute transaction

    double stop = 2;                    //Pour arreter ou recommencer le programme

    do{
        stop = 2;                    //Pour que stop ce soit pas � 1 lorsque l'utilisateur recommence le programme
        printf("Bienvenue au bon cote ESGI, nous vous proposons un prix par rapport a vos petites annonces proposees.\n");
        printf("Veuillez completer correctement les critere sur vos besoins, avec des nombres entiers, positifs et limite en fonction de l'information demandee.\n");

        //Le type de lannonce
        printf("\nLe type d'annonce (entre 1 et 4):");
        do{
            scanf("%lf", &typeNews);
            if(typeNews < 1 || typeNews > 4 || (int)ceil(typeNews) - (int)floor(typeNews) != 0){
            printf("Vous avez mal saisi les valeurs, recommencez:\n");
            }
        }while(typeNews < 1 || typeNews > 4 || (int)ceil(typeNews) - (int)floor(typeNews) != 0);

//Cette partie permet a l'utilisateur de saisir un nombre positif, entier et dans la plage indiquee.

        //La zone de distribution du journal
        printf("\nLa zone de distribution (1 ou 2):");
        do{
            scanf("%lf", &distributionArea);
            if(distributionArea < 1 || distributionArea > 2 || (int)ceil(distributionArea) - (int)floor(distributionArea) != 0){
            printf("Vous avez mal saisi les valeurs, recommencez:\n");
            }
        }while(distributionArea < 1 || distributionArea > 2 || (int)ceil(distributionArea) - (int)floor(distributionArea) != 0);

        //Le prix en fonction du type et de la zone
        if(distributionArea == 1){
            switch((unsigned short)typeNews){
                case 1:
                    firstWeekPrice= 5.5;
                    break;
                case 2:
                    firstWeekPrice = 7.5;
                    break;
                case 3:
                    firstWeekPrice = 9.5;
                    break;
                case 4:
                    firstWeekPrice = 11.5;
                    break;
                default:
                    printf("ERROR");
                    exit(-1);
            }
        } else{
            switch((unsigned short)typeNews){
                case 1:
                    firstWeekPrice = 6.5;
                    break;
                case 2:
                    firstWeekPrice = 8.5;
                    break;
                case 3:
                    firstWeekPrice = 10.5;
                    break;
                case 4:
                    firstWeekPrice = 12.5;
                    break;
                default:
                    printf("ERROR");
                    exit(-1);
            }
        }
        printf("Votre zone de distribution est de %.0lf et votre zone de %.0lf. Le prix de base est de : %.1lf euros\n", distributionArea, typeNews, firstWeekPrice);

        //prix par rapport au ligne
        printf("\nNombre de lignes de vos petites annonces (un nombre entier entre 0 a 1000, car ce sont des petites annonces) :");
        do{
            scanf("%lf", &lineCount);
            if(lineCount < 0 || lineCount > 1000 || (int)ceil(lineCount) - (int)floor(lineCount) != 0){
            printf("Vous avez mal saisi les valeurs, recommencez:\n");
            }
        }while(lineCount < 0 || lineCount > 1000 || (int)ceil(lineCount) - (int)floor(lineCount) != 0);

        if(lineCount == 0){
            totalPrice = 0;
            printf("Votre prix est de %.0lf euros.\n", totalPrice);
            do{
                printf("\nVoulez vous revoir a zero le calcul du prix de vos petites annonces?\n");
                printf("1.Recommencer\n0.Arreter\n");
                scanf("%lf", &stop);
                if(stop != 1 && stop != 0){
                printf("Vous avez mal saisi.\n");
                }
            }while(stop != 1 && stop != 0);
            printf("\n");
        }

        if (stop == 1){
            printf("\n");
            stop = 2;
            continue;
        }else if(stop == 0){
            exit(-1);
        }

        //prix par rapport au nombre de pages saisi superieur a 5
        if(lineCount > 5){
            currentPrice = firstWeekPrice;
            firstWeekPrice = (lineCount - 5) * lineSuppPrice;
            printf("A partir de la 5eme ligne, le cout par ligne supplementaire est de %.1lf euros.\n", lineSuppPrice);
            printf("En comptant le cout des lignes supplementaire, le prix est de : (%.0lf - 5) * %.1lf = %.1lf euros\n", lineCount, lineSuppPrice, firstWeekPrice);
        }

        //nombre de semaines
        printf("\nCombien de semaines voulez vous que les petites annonces apparaissent ?\n");
        printf("il faut saisir un nombre entier et positif entre 1 et 10 :");
        do{
            scanf("%lf", &numberWeeks);
            if(numberWeeks < 1 || numberWeeks > 10 || (int)ceil(numberWeeks) - (int)floor(numberWeeks) != 0){
            printf("Vous avez mal saisi les valeurs, recommencez:\n");
            }
        }while(numberWeeks < 1 || numberWeeks > 10 || (int)ceil(numberWeeks) - (int)floor(numberWeeks) != 0);

        //Categorie du client pour determiner le taux de reduction pour le prix des autres semaines que la premiere
        printf("\nDe quel categorie de client etes-vous (entre 1 et 5) :");
        do{
            scanf("%lf", &customerCategory);
            if(customerCategory < 1 || customerCategory > 5 || (int)ceil(customerCategory) - (int)floor(customerCategory) != 0){
            printf("Vous avez mal saisi les valeurs, recommencez:\n");
            }
        }while(customerCategory < 1 || customerCategory > 5 || (int)ceil(customerCategory) - (int)floor(customerCategory) != 0);

        switch((unsigned short)customerCategory){
            case 1:
                reductionRate = 0.1;
                break;
            case 2:
                reductionRate = 0.12;
                break;
            case 3:
                reductionRate = 0.15;
                break;
            case 4:
                reductionRate = 0.16;
                break;
            case 5:
                reductionRate = 0.2;
                break;
            default:
                printf("ERROR");
                exit(-1);
        }
        printf("Comme vous etes a la %.0lf. categorie, a part pour la premiere semaine, vous avez un taux de reduction de %.0lf%%.\n", customerCategory, reductionRate * 100);

        //Reduction du prix par rapport a si le client est professionel ou particulier
        printf("\nActuellement, en quelle anne etes-vous ? :");
        do{
            scanf("%lf", &years);
            if((int)ceil(years) - (int)floor(years) != 0){
            printf("Vous avez mal saisi les valeurs, recommencez:\n");
            }
        }while((int)ceil(years) - (int)floor(years) != 0);
        if(years < 1937){
            printf("Vous pouvez utiliser ce programme meme avant la creation du premier ordinateur numerique electronique.\n");
            printf("Malheureusement, meme si vous avez une machine a voyager dans le temps vous ne pouvez pas avoir la reduction de premiere semaine.\n");
        }else if(years == 2019){
            printf("Vous n'avez pas acces a la reduction de premiere semaine, meme si vous etes un blade runner.\n");
        }else if(years == 2100){
            printf("Que vous ayez effectuer le processus Downsizing ou pas, vous n'aurez pas acces a la reduction de premiere semaine\n");
        }else if(years < 2015){
            printf("Malheureusement vous ne pouvez pas avoir la reduction de premiere semaine. Elle sera exclusivement en 2015.\n");
        }else if(years > 2015){
            printf("Malheureusment c'est trop tard pour la reduction de premiere semaine, c'etait en 2015.\n");
        }

        if(years == 2015){
            printf("\nDepuis 2015, nous accordons une reduction sur le prix de base de la premiere semaine qui est variable par rapport au statut du client.\n");
            printf("Etes-vous un client professionel ou un particulier ? :\n");
            printf("1. Professionnel\n");
            printf("2. Particulier \n");
            do{
                scanf("%lf", &proOrPar);
                if(proOrPar < 1 || proOrPar > 2 || (int)ceil(proOrPar) - (int)floor(proOrPar) != 0){
                printf("Vous avez mal saisi les valeurs, recommencez:\n");
                }
            }while(proOrPar < 1 || proOrPar > 2 || (int)ceil(proOrPar) - (int)floor(proOrPar) != 0);
            (unsigned short) proOrPar;

            if(proOrPar == 1){
                reductionFirstWeek = 0.02;
                printf("Comme vous etes professionnel, le taux de reduction de la premier semaine est de %.2lf%%\n", reductionFirstWeek * 100);
            }else if(proOrPar == 2){
                reductionFirstWeek = 0.1;
                printf("Comme vous etes particulier, le taux de la premier semaine reduction est de %.2lf\n", reductionFirstWeek * 100);
            }else{
                printf("ERROR");
                exit(-1);
            }
            currentPrice = firstWeekPrice;
            firstWeekPrice -= firstWeekPrice * reductionFirstWeek;
            printf("le prix de la premiere semaine est de : %.2lf - %.2lf * %.2lf = %.2lf euros", currentPrice, currentPrice, reductionFirstWeek, firstWeekPrice);
        }


        printf("\nVoulez-vous conserver l'anonymat de vos transactions ?\n");
        printf("1. Oui\n");
        printf("0. Non\n");
        do{
            scanf("%lf", &anonyma);
            if(anonyma < 0 || anonyma > 1 || (int)ceil(anonyma) - (int)floor(anonyma) != 0){
            printf("Vous avez mal saisi les valeurs, recommencez:\n");
            }
        }while(anonyma < 0 || anonyma > 1 || (int)ceil(anonyma) - (int)floor(anonyma) != 0);
        (unsigned short) anonyma;

        if(anonyma == 1){
                anonymaCost = 13;
                saveCost = anonymaCost;
            switch((unsigned short)numberWeeks){
                case 1:
                    printf("Le prix total de l'option pour %.0lf semaines c'est :%.0lf * %.0lf = %.0lf euros.\n", numberWeeks, numberWeeks, saveCost, anonymaCost);
                    break;
                case 2:
                    anonymaCost *= 2;
                    printf("Le prix total de l'option pour %.0lf semaines c'est :%.0lf * %.0lf = %.0lf  euros.\n", numberWeeks, numberWeeks, saveCost, anonymaCost);
                    break;
                case 3:
                    anonymaCost *= 3;
                    printf("Le prix total de l'option pour %.0lf  semaines c'est :%.0lf  * %.0lf  = %.0lf  euros.\n", numberWeeks, numberWeeks, saveCost, anonymaCost);
                    break;
                default:
                    anonymaCost *= 3;
                    printf("A partir de la quatrieme semaine, il n'y a plus de cout sur l'option de preservation de l'anonymat.\n");
                    printf("Le prix total de l'option pour %.0lf  semaines c'est :%d * %.0lf  = %.0lf  euros.\n", numberWeeks, 3, saveCost, anonymaCost);
                    break;
            }
        }else if(anonyma == 0){
            anonymaCost = 0;
        }else{
            printf("ERROR");
            exit(-1);
        }
        //le prix total des petites annonces en prenant compte du nombre de semaine, de la reduction par rapport a la duree de parition
        totalPrice = firstWeekPrice + anonymaCost + (currentPrice - currentPrice * reductionRate) * (numberWeeks - 1);
        printf("\nLe prix total est: %.2lf + %.0lf  + (%.2lf - %.2lf * %.2lf) * (%.0lf  - 1) = %.2lf euros.", firstWeekPrice, anonymaCost, currentPrice, currentPrice, reductionRate, numberWeeks, totalPrice);

        do{
            printf("\nVoulez vous revoir a zero le calcul du prix de vos petites annonces?\n");
            printf("1.Recommencer\n0.Arreter\n");
            scanf("%lf", &stop);
            if(stop != 1 && stop != 0){
            printf("Vous avez mal saisi.\n");
            }
        }while(stop != 1 && stop != 0);
        printf("\n");
        (unsigned short) stop;     //fonction pour recommencer ou arreter
    }while(stop != 0);
    return 0;
}
