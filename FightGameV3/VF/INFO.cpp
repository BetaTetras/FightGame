
#include <iostream>
#include <cctype> // Pour mettre les char automatiquement en majuscule



void INFO()
{

    char Choix;
    system("cls");

    std::cout << "_________________________________________________________________________________________________________________________" << '\n';
    std::cout << '\n';
    std::cout << '\n';
    std::cout << "Arme disponible :" << '\n';
    std::cout << "      1) Epee de bois " << '\n';
    std::cout << "          - 1/2 de faire -20 PV a l'ennemie" << '\n';
    std::cout << '\n';
    std::cout << "      2) Baton de bois " << '\n';
    std::cout << "          - 1/3 de faire -10 PV a l'ennemie et permet , si l'ennemie est toucher ," << '\n';
    std::cout << "            de jouer une deuxieme fois" << '\n';
    std::cout << '\n';
    std::cout << "Magie disponible :" << '\n';
    std::cout << "      1) Boule de feu " << '\n';
    std::cout << "          - 1/3 de faire -30 PV a l'ennemie" << '\n';
    std::cout << '\n';
    std::cout << "      2) Dard empoisonne " << '\n';
    std::cout << "          - 1/5 de faire -5 PV a l'ennemie sur 5 tour [!] EFFET NON CUMMULABLE" << '\n';
    std::cout << '\n';
    std::cout << "      3) BOMBE THERMONUCLEAIRE " << '\n';
    std::cout << "          - 1/100 de faire -1 000 000 000 PV a l'ennemie ce qui signe la fin des " << '\n';
    std::cout << "            temps [DEBUG TOOL LOL]" << '\n';
    std::cout << '\n';
    std::cout << "Objet disponiblre :" << '\n';
    std::cout << "      1) Potion suspecte" << '\n';
    std::cout << "          - Sois +30 PV sois -10 PV" << '\n';
    std::cout << '\n';
    std::cout << '\n';
    std::cout << "_________________________________________________________________________________________________________________________" << '\n';
    std::cout << '\n';
    std::cout << "Voulez vous revenir a l'ecran titre ou voulez-vous quitter le jeu ? (Y/N) : " << '\n' << "      > " ;
    std::cin >> Choix;
    Choix = std::toupper(Choix);
    while(Choix != 'N' && Choix != 'Y')
    {
        std::cout << '\n';
        std::cout << "     ERREUR : Entre non valide !!!" << '\n';
        std::cout << "     Entrer 'Y' ou 'N' UNIQUEMENT : " << '\n' << "        > " ;
        std::cin >> Choix;
    }

    if(Choix == 'N')
    {
        exit(0);
    }


}