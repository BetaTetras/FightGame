#include <iostream>
#include <ctime>    // For randomness
#include <cctype>   // To automatically convert char to uppercase

#include "CENTRAL.cpp"

int MainMenu()
{
    int Choice;
    int output;

    std::cout << "---------------------------- [ MENU ] ----------------------------";
    std::cout << '\n';
    std::cout << "1 - START GAME" << '\n';
    std::cout << "2 - CREDITS" << '\n';
    std::cout << "3 - INFO" << '\n';
    std::cout << "4 - EXIT GAME" << '\n';
    std::cout << '\n';
    std::cout << "What would you like to do? :" << '\n' << "   > ";
    std::cin >> Choice;
    output = Verif(1, 4, Choice); // Assuming Verif ensures the input is within range
    std::cout << "------------------------------------------------------------------" << '\n';

    return output;
}

int main()
{
    int EnemyCount;
    int Gold;

    system("cls");

    std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- FIGHT GAME -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-";
    std::cout << '\n';
    std::cout << "Welcome to the mini combat game 'FIGHT GAME' !!!" << '\n';
    std::cout << "Let me introduce myself: I am Bob, the game narrator! In this game, you will face an enemy who wants to see you DEAD, but don't worry, you will be able to" << '\n';
    std::cout << "defend yourself with weapons and magical spells. Now, let the show begin:" << '\n';
    std::cout << '\n';
    std::cout << '\n';

    switch (MainMenu())
    {
    case 1:
        GAME(); 
        main();
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
        std::cout << "Exiting the game...";
        break;
    }

    system("cls");
    return 0;
}
