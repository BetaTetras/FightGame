#include <iostream>
#include <ctime>    //Pour l'aleatoire
#include <cctype> // Pour mettre les char automatiquement en majuscule

#include "CENTRAL.cpp"

int MenuPrincipale()
{
    int Choix;
    int output;

    std::cout << "---------------------------- [ MENU ] ----------------------------";
    std::cout << '\n';
    std::cout << "1 - START GAME" << '\n';
    std::cout << "2 - CREDIT" << '\n';
    std::cout << "3 - INFO" << '\n';
    std::cout << "4 - QUITTER LE JEU" << '\n';
    std::cout << '\n';
    std::cout << "Que voulez-vous faire ? :" << '\n' << "   > ";
    std::cin >> Choix;
    output = Verif(1,4,Choix);
    std::cout << "------------------------------------------------------------------" << '\n';

    return output;

}


int main()
{

    int NbrEnnemie;
    int Gold;

    system("cls");


    std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- FIGHT GAME -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-";
    std::cout << '\n';
    std::cout <<                                                                 "Bienvenue dans le mini jeu de combat de 'FIGHT GAME' !!!" << '\n';
    std::cout << "Je me presente : je suis Bob le narrateur du jeu ! Dans ce jeux vous aller etre confonter a un ennemie qui veut votre MORT , mais ne vous inquiete pas , vous aller pouvoir" << '\n';
    std::cout << "vous defendre grace a des arme et des sort magique . Maintenant , que le show commence :" << '\n';
    std::cout << '\n';
    std::cout << '\n';

    

    switch (MenuPrincipale())
    {
    case 1:
        while (GAME() == 0)
        {
            main(); 
        }

    break;
    ///////////////////
    case 2:
        CREDIT();
        main();
    break;
    ///////////////////
    case 3:
        INFO();
        main();
    break;
    ///////////////////
    case 4:
        std::cout << "4";
    break;
    }



    system("cls");
    return 0;
}