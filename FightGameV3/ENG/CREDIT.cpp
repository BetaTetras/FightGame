#include <iostream>

void CREDIT()
{
    char Choice;

    system("cls");

    std::cout << "_________________________________________________________________________________________________________________________" << '\n';
    std::cout << '\n';
    std::cout << '\n';
    std::cout << "Mini-game created, imagined, and developed in C++ by GREGOIRE GIBRAT. All the work on this project is dedicated to him." << '\n';
    std::cout << "FREE game created solely to learn development in C++. The code is open to all for improvement or modification." << '\n';
    std::cout << '\n';
    std::cout << '\n';
    std::cout << "Thanks for playing, and don't forget to thank Tetras!" << '\n';
    std::cout << '\n';
    std::cout << '\n';
    std::cout << "_________________________________________________________________________________________________________________________" << '\n';

    std::cout << '\n';
    std::cout << "Would you like to return to the main menu? (Y/N) : " << '\n' << "    > ";
    std::cin >> Choice;
    Choice = std::toupper(Choice);
    while(Choice != 'N' && Choice != 'Y')
    {
        std::cout << '\n';
        std::cout << "     ERROR: Invalid input!!!" << '\n';
        std::cout << "     Enter 'Y' or 'N' ONLY : " << '\n' << "        > ";
        std::cin >> Choice;
    }

    if(Choice == 'N')
    {
        exit(0);
    }
}
