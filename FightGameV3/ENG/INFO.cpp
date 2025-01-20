#include <iostream>
#include <cctype> // To automatically convert char to uppercase

void INFO()
{
    char Choice;
    system("cls");

    std::cout << "_________________________________________________________________________________________________________________________" << '\n';
    std::cout << '\n';
    std::cout << '\n';
    std::cout << "Available weapons:" << '\n';
    std::cout << "      1) Wooden Sword" << '\n';
    std::cout << "          - 1/2 chance to deal -20 HP to the enemy" << '\n';
    std::cout << '\n';
    std::cout << "      2) Wooden Staff" << '\n';
    std::cout << "          - 1/3 chance to deal -10 HP to the enemy, and if the enemy is hit," << '\n';
    std::cout << "            allows you to play a second time" << '\n';
    std::cout << '\n';
    std::cout << "Available magic:" << '\n';
    std::cout << "      1) Fireball" << '\n';
    std::cout << "          - 1/3 chance to deal -30 HP to the enemy" << '\n';
    std::cout << '\n';
    std::cout << "      2) Poison Dart" << '\n';
    std::cout << "          - 1/5 chance to deal -5 HP to the enemy over 5 turns [!] EFFECT NOT STACKABLE" << '\n';
    std::cout << '\n';
    std::cout << "      3) THERMONUCLEAR BOMB" << '\n';
    std::cout << "          - 1/100 chance to deal -1,000,000,000 HP to the enemy, marking the end of" << '\n';
    std::cout << "            time [DEBUG TOOL LOL]" << '\n';
    std::cout << '\n';
    std::cout << "Available items:" << '\n';
    std::cout << "      1) Suspicious Potion" << '\n';
    std::cout << "          - Either +30 HP or -10 HP" << '\n';
    std::cout << '\n';
    std::cout << '\n';
    std::cout << "_________________________________________________________________________________________________________________________" << '\n';
    std::cout << '\n';
    std::cout << "Would you like to return to the title screen or exit the game? (Y/N): " << '\n' << "      > ";
    std::cin >> Choice;
    Choice = std::toupper(Choice);
    while (Choice != 'N' && Choice != 'Y')
    {
        std::cout << '\n';
        std::cout << "     ERROR: Invalid input!!!" << '\n';
        std::cout << "     Enter 'Y' or 'N' ONLY: " << '\n' << "        > ";
        std::cin >> Choice;
    }

    if (Choice == 'N')
    {
        exit(0);
    }
}
