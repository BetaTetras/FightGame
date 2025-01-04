#include <iostream>


void CREDIT()
{

    char Choix;

    system("cls");

    std::cout << "_________________________________________________________________________________________________________________________" << '\n';
    std::cout << '\n';
    std::cout << '\n';
    std::cout << "Mini-jeu cree, imagine et developpe en C++ par GREGOIRE GIBRAT. Tout le travail de ce projet lui est destine." << '\n';
    std::cout << "Jeu GRATUIT cree dans le seul but d'apprendre le developpement en C++. Code ouvert a tous pour amelioration" << '\n';
    std::cout << "ou modification." << '\n';
    std::cout << '\n';
    std::cout << '\n';
    std::cout << "Thanks for playing, and don't forget to thank Tetras!" << '\n';
    std::cout << '\n';
    std::cout << '\n';
    std::cout << "_________________________________________________________________________________________________________________________" << '\n';

    std::cout << '\n';
    std::cout << "Voulre-vous revenir au menu principal ? (Y/N) : " << '\n' << "    > ";
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