#include <iostream>
#include <ctime>    // For randomness
#include <cctype> // To automatically convert characters to uppercase


#include "tour.cpp"

int GAME()
{
    system("cls");
    srand(time(NULL));

    int nbrRound = 1; // Number of rounds
    char Choice = 'Y'; // For continuation
    int nbrEnemy = 0; // Increment difficulty

    int CoinFlip; // RNG of the game
    int PlayerNumSuspiciousPotions = 3; // Number of suspicious potions
    int PoisonedTurns = 0; // Number of turns the enemy is poisoned
    int Error = 0; // Error (e.g., no more suspicious potions or already poisoned)

    int PlayerHealth = 100;
    int PlayerDamage = 10;
    std::string PlayerWeapon = "Wooden Sword";
    std::string PlayerMagic = "Fireball";

    int EnemyHealth = 100;
    int EnemyDamage = 10;
    std::string EnemyWeapon = "Wooden Sword";
    std::string EnemyMagic = "Fireball";


    while(Choice != 'N')
    {
        system("cls");
        std::cout << "_________________________________________________________________________________________________________________________" << '\n';
        std::cout << '\n';
        std::cout << "                                                  ENEMY NUMBER " << nbrEnemy + 1 << '\n';
        std::cout << '\n';
        while(EnemyHealth > 0 && PlayerHealth > 0)
        {

            std::cout << "################################################################################################################" << '\n';
            std::cout << "                                                  Round " << nbrRound ; 
            std::cout << '\n';
            std::cout << "Enemy HP: " << EnemyHealth << " HP " << '\n'; 
            std::cout << "Player HP: " << PlayerHealth << " HP" << '\n'; 

            do{
                Error = 0;
                Memory result = PlayerTurn(PlayerHealth, EnemyHealth, PlayerNumSuspiciousPotions, PoisonedTurns, Error);

                EnemyHealth = result.EnemyHealth;
                PlayerHealth = result.PlayerHealth;
                PlayerNumSuspiciousPotions = result.PlayerNumSuspiciousPotions;
                Error = result.Error;
                PoisonedTurns = result.PoisonedTurns;

            }while(Error == 1);

            // std::cout << '\n';
            // std::cout << '\n';
            // std::cout << "      [DEBUG] EnemyHP : " << EnemyHP << '\n';
            // std::cout << "      [DEBUG] PlayerHP : " << PlayerHP << '\n';
            // std::cout << '\n';
            // std::cout << '\n';
            
            if(EnemyHealth > 0)
            {
                PlayerHealth = EnemyTurn(PlayerHealth);
            }

            // std::cout << '\n';
            // std::cout << '\n';
            // std::cout << "      [DEBUG] EnemyHP : " << EnemyHP << '\n';
            // std::cout << "      [DEBUG] PlayerHP : " << PlayerHP << '\n';
            // std::cout << '\n';
            // std::cout << '\n';

            if(PoisonedTurns > 0)
            {
                std::cout << '\n';
                std::cout << "Enemy poisoned for " << PoisonedTurns << " more turn(s)!" << '\n';
                std::cout << '\n';

                EnemyHealth = EnemyHealth - 5;
                PoisonedTurns--;

            }

            std::cout << "################################################################################################################" << '\n';
            
            std::cout << '\n';
            std::cout << '\n';

            nbrRound++;
        }

        if(EnemyHealth <= 0)
        {
            std::cout << "CONGRATULATIONS, YOU WON!!!" << '\n';
        }
        else if(PlayerHealth <= 0)
        {
            std::cout << "OH NO, YOU LOST!!!" << '\n';
        }

        std::cout << '\n';
        std::cout << '\n';
        std::cout << "Do you want to restart? (Y/N) : " << '\n' << "      > ";
        std::cin >> Choice;
        Choice = std::toupper(Choice);
        while( Choice != 'Y' && Choice != 'N')
        {
            std::cout << '\n';
            std::cout << "Error: Only Y/y and N/n responses are allowed!" << '\n';
            std::cout << "Do you want to have a supplement in your dish? (Y/N) : " << '\n' << "  > ";
            std::cin >> Choice;
            Choice = std::toupper(Choice);
            std::cout << '\n';
        }

        if(Choice == 'Y')
        {
            nbrEnemy++;
            std::cout << "nbrEnemy : " << nbrEnemy << '\n';
            EnemyHealth = 100 + (10 * nbrEnemy);
        }

        else
        {
            return 0;
        }

    }

}
