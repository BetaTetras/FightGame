#include <iostream>
#include <ctime>    // For randomness
#include <cctype> // To automatically capitalize characters

int Verif(int x , int y, int input)
{
    while(input < x || input > y)
    {
        std::cout << '\n';
        std::cout << "     ERROR: Invalid input!!!" << '\n';
        std::cout << "     Enter a value between " << x << " and " << y << " ONLY: " << '\n' << "        > ";
        std::cin >> input;
    }

    return input;
}

int CombatMenu()
{
    int Choice;
    int output;

    std::cout << "1 - Attack      2 - Magic       3 - Item" << '\n';
    std::cout << '\n';
    std::cout << "      > ";
    std::cin >> Choice;
    output = Verif(1,3,Choice);
    std::cout << '\n';

    return output;
}

int WeaponMenu()
{
    int Choice;
    int output;

    std::cout << "1 - Wooden Sword (D = 20; C = 1/2)      2 - Wooden Staff (D = 10; C = 1/3; E = +1)       3 - Back" << '\n';
    std::cout << '\n';
    std::cout << "      > ";
    std::cin >> Choice;
    output = Verif(1,3,Choice);
    std::cout << '\n';

    return output;
}

int MagicMenu()
{
    int Choice;
    int output;

    std::cout << "1 - Fireball (D = -30; C = 1/3)      2 - Poison Dart (D = -5; C = 1/5; E = -5 * 5)       3 - Back" << '\n';
    std::cout << '\n';
    std::cout << "      > ";
    std::cin >> Choice;
    output = Verif(1,4,Choice);
    std::cout << '\n';

    return output;
}

int ItemMenu()
{
    int Choice;
    int output;

    std::cout << "1 - Suspicious Potion (1/2 +30HP, 1/2 -20HP)       2 - Back" << '\n';
    std::cout << '\n';
    std::cout << "      > ";
    std::cin >> Choice;
    output = Verif(1,2,Choice);
    std::cout << '\n';

    return output;
}


struct Memory
{
    int PlayerHealth;
    int EnemyHealth;

    int PlayerNumSuspiciousPotions;
    int PoisonedTurns;

    int Error;
};

Memory PlayerTurn(int PlayerHealth, int EnemyHealth, int PlayerNumSuspiciousPotions, int PoisonedTurns, int Error)
{
    srand(time(NULL));

    int CoinFlip;
    bool Exit = false;
    bool PlayerTurnComplete = false;

    bool PlayerPlay = true; // 1 more turn

    int PlayerDamage = 10;
    std::string PlayerWeapon;
    std::string PlayerMagic;
    std::string PlayerItem;

    std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << '\n';

    while (PlayerPlay == true)
    {
        PlayerPlay = false;

        while (Exit == false && PlayerTurnComplete == false)
        {
            switch (CombatMenu())
            {
                case 1:
                    while (Exit == false && PlayerTurnComplete == false)
                    {
                        switch (WeaponMenu())
                        {
                            case 1:
                                PlayerWeapon = "Wooden Sword";
                                std::cout << "Attack with the weapon:  " << PlayerWeapon << '\n';
                                CoinFlip = rand() % 2 + 1;   // 1 -> 2
                                PlayerDamage = 20;
                                if (CoinFlip > 1)
                                {
                                    PlayerDamage = PlayerDamage * 0;
                                }

                                EnemyHealth = EnemyHealth - PlayerDamage;

                                std::cout << '\n';
                                std::cout << "Damage inflicted: " << PlayerDamage << " ." << '\n';
                                PlayerTurnComplete = true;
                                break;
                            //////////////
                            case 2:
                                PlayerWeapon = "Wooden Staff";
                                std::cout << "Attack with the weapon:  " << PlayerWeapon << '\n';
                                CoinFlip = rand() % 3 + 1;   // 1 -> 3
                                PlayerDamage = 10;
                                if (CoinFlip > 1)
                                {
                                    PlayerDamage = PlayerDamage * 0;
                                }
                                else
                                {
                                    PlayerPlay = true;
                                }

                                EnemyHealth = EnemyHealth - PlayerDamage;

                                std::cout << '\n';
                                std::cout << "Damage inflicted: " << PlayerDamage << '\n';
                                PlayerTurnComplete = true;
                                break;
                            //////////////
                            case 3:
                                Exit = true;
                                break;
                        }
                    }
                    Exit = false;
                    break;
                ///////////////////////////////////////////////
                case 2:
                    while (Exit == false && PlayerTurnComplete == false)
                    {
                        switch (MagicMenu())
                        {
                            case 1:
                                PlayerMagic = "Fireball";
                                std::cout << "Attack with magic:  " << PlayerMagic << " ." << '\n';
                                CoinFlip = rand() % 3 + 1; // 1 -> 3
                                PlayerDamage = 30;
                                if (CoinFlip > 1)
                                {
                                    PlayerDamage = PlayerDamage * 0;
                                }

                                EnemyHealth = EnemyHealth - PlayerDamage;

                                std::cout << '\n';
                                std::cout << "Damage inflicted: " << PlayerDamage << " ." << '\n';
                                PlayerDamage = 10;
                                PlayerTurnComplete = true;
                                break;
                            //////////////
                            case 2:
                                if (PoisonedTurns == 0)
                                {
                                    PlayerMagic = "Poison Dart";
                                    std::cout << "Attack with magic:  " << PlayerMagic << " ." << '\n';
                                    CoinFlip = rand() % 5 + 1; // 1 -> 3
                                    if (CoinFlip == 1)
                                    {
                                        std::cout << '\n';
                                        std::cout << "The enemy is now poisoned!" << '\n';
                                        PoisonedTurns = 5;
                                    }
                                    else
                                    {
                                        std::cout << '\n';
                                        std::cout << "Attack missed!" << '\n';
                                    }
                                }
                                else
                                {
                                    std::cout << '\n';
                                    std::cout << "The enemy is already poisoned, this attack cannot be stacked!";
                                }

                                PlayerTurnComplete = true;
                                break;
                            //////////////
                            case 3:
                                Exit = true;
                                break;

                            case 4:
                                PlayerMagic = "THERMONUCLEAR BOMB";
                                std::cout << "Attack with magic:  " << PlayerMagic << " ." << '\n';
                                CoinFlip = rand() % 2 + 1; // 1 -> [100 DEBUG MODE ON]
                                PlayerDamage = 1000000000;
                                if (CoinFlip > 1)
                                {
                                    PlayerDamage = PlayerDamage * 0;
                                }

                                EnemyHealth = EnemyHealth - PlayerDamage;

                                std::cout << '\n';
                                std::cout << "Damage inflicted: " << PlayerDamage << " ." << '\n';
                                PlayerDamage = 10;
                                PlayerTurnComplete = true;
                                break;
                        }
                    }
                    Exit = false;
                    break;
                ///////////////////////////////////////////////
                case 3:
                    while (Exit == false && PlayerTurnComplete == false)
                    {
                        switch (ItemMenu())
                        {
                            case 1:
                                if (PlayerNumSuspiciousPotions > 0)
                                {
                                    PlayerItem = "Suspicious Potion";
                                    std::cout << "Use item:  " << PlayerItem << " ." << '\n';
                                    CoinFlip = rand() % 2 + 1; // 1 -> 2

                                    if (CoinFlip == 1)
                                    {
                                        PlayerHealth = PlayerHealth + 30;

                                        std::cout << '\n';
                                        std::cout << "You got lucky: +30 HP!" << '\n';
                                    }
                                    else
                                    {
                                        PlayerHealth = PlayerHealth - 10;
                                        std::cout << '\n';
                                        std::cout << "Bad luck: -10 HP!" << '\n';
                                    }

                                    PlayerNumSuspiciousPotions--;

                                    std::cout << '\n';
                                    std::cout << "Number of " << PlayerItem << " remaining: " << PlayerNumSuspiciousPotions << '\n';
                                    std::cout << '\n';
                                }
                                else
                                {
                                    std::cout << "No more suspicious potions left!" << '\n';

                                    Error = 1;
                                }
                                PlayerTurnComplete = true;
                                break;
                            //////////////
                            case 2:
                                Exit = true;
                                break;
                        }
                    }
                    Exit = false;
                    break;
            }
        }
    }
    std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << '\n';

    return {
        PlayerHealth,  // Keep track of player's health
        EnemyHealth,   // Keep track of enemy's health

        PlayerNumSuspiciousPotions, // Keep track of the number of suspicious potions
        PoisonedTurns, // Keep track of the poison turn count

        Error // Error (e.g., no suspicious potions, enemy already poisoned)
    };
}

int EnemyTurn(int PlayerHealth)
{
    srand(time(NULL));

    int CoinFlip;
    int EnemyChoice;

    int EnemyHealth = 100;
    int EnemyDamage = 10;
    std::string EnemyWeapon = "Wooden Sword";
    std::string EnemyMagic = "Fireball";

    std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << '\n';

    EnemyChoice = rand() % 2 + 1;

    switch (EnemyChoice)
    {
        case 1:
            std::cout << "Attack with weapon:  " << EnemyWeapon << " ." << '\n';
            CoinFlip = rand() % 2 + 1;   // 1 -> 2
            EnemyDamage = 10;
            if (CoinFlip > 1)
            {
                EnemyDamage = EnemyDamage * 0;
            }

            PlayerHealth = PlayerHealth - EnemyDamage;

            std::cout << '\n';
            std::cout << "Damage inflicted: " << EnemyDamage << " ." << '\n';
            break;
        ///////////////////////////////////////////////
        case 2:
            std::cout << "Attack with magic:  " << EnemyMagic << " ." << '\n';
            CoinFlip = rand() % 3 + 1; // 1 -> 3
            EnemyDamage = 30;
            if (CoinFlip > 1)
            {
                EnemyDamage = EnemyDamage * 0;
            }

            PlayerHealth = PlayerHealth - EnemyDamage;

            std::cout << '\n';
            std::cout << "Damage inflicted: " << EnemyDamage << " ." << '\n';
            EnemyDamage = 10;
            break;
        ///////////////////////////////////////////////
        case 3:
            std::cout << "Defense!" << '\n';
            break;
        ///////////////////////////////////////////////
        default:
            break;
    }

    std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << '\n';

    return PlayerHealth;
}
