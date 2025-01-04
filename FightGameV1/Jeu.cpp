#include <iostream>

#include <ctime>    //Pour l'aleatoire

#include <cctype> // Pour mettre les char automatiquement en majuscule

//////////////////////////////////////////////

int Verif(int x , int y, int input);
int main();

int MenuPrincipale();

void GAME();
void CREDIT();

//////////////////////////////////////////////

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

int Verif(int x , int y, int input)
{
    while(input < x || input > y)
    {
        std::cout << '\n';
        std::cout << "     ERREUR : Entre non valide !!!" << '\n';
        std::cout << "     Entre une valeur entre " << x << " et " << y << " UNIQUEMENT : " << '\n' << "        > " ;
        std::cin >> input;
    }

    return input;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int MenuCombat()
{
    int Choix;
    int output;

    std::cout << "1 - Attaquer      2 - Magie       3 - Objet" << '\n';
    std::cout << '\n';
    std::cout << "      > ";
    std::cin >> Choix;
    output = Verif(1,3,Choix);
    std::cout << '\n';


    return output;
}

int MenuArme()
{
    int Choix;
    int output;

    std::cout << "1 - Epee de bois (D = 20 ; C = 1/2 )      2 - Baton de bois (D = 10 ; C = 1/3 ; E = +1 )" << '\n';
    std::cout << '\n';
    std::cout << "      > ";
    std::cin >> Choix;
    output = Verif(1,2,Choix);
    std::cout << '\n';


    return output;
}

int MenuMagie()
{
    int Choix;
    int output;

    std::cout << "1 - Boule de feu (D = -30 ; C = 1/3 )      2 - BOMBE THERMONUCLEAIRE  (D = -1 000 000 000 ; C = 1/100 ; E = end game )" << '\n';
    std::cout << '\n';
    std::cout << "      > ";
    std::cin >> Choix;
    output = Verif(1,2,Choix);
    std::cout << '\n';


    return output;
}

int MenuObjet()
{
    int Choix;
    int output;

    std::cout << "1 - Potion suspecte (1/2 +30PV , 1/2 -20PV)" << '\n';
    std::cout << '\n';
    std::cout << "      > ";
    std::cin >> Choix;
    output = Verif(1,1,Choix);
    std::cout << '\n';


    return output;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Memory
{
    int JoueurVie;
    int EnnemieVie;
};

Memory TourJoueur(int JoueurVie , int EnnemieVie)
{

srand(time(NULL));

int PileOuFace;

bool JoueurPlay = true; //1 tour en plus


int JoueurDegat = 10;
int JoueurNbrPotionSus = 3;
std::string JoueurArme;
std::string JoueurMagie;
std::string JoueurObjet;


std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << '\n';

while(JoueurPlay == true)
{   
    JoueurPlay = false;

    switch (MenuCombat())
        {
        case 1:
            switch (MenuArme())
            {
            case 1:
                JoueurArme = "Epee de bois";
                std::cout << "Attaque avec l'arme :  " << JoueurArme << '\n';
                PileOuFace = PileOuFace = rand() % 2 + 1;   // 1 -> 2
                JoueurDegat = 20;
                if(PileOuFace > 1)
                {
                    JoueurDegat = JoueurDegat * 0;
                }

                EnnemieVie = EnnemieVie - JoueurDegat;

                std::cout << '\n';
                std::cout << "Degat infliger : " << JoueurDegat << " ." << '\n';
            break;
            //////////////
            case 2:
                JoueurArme = "Baton de bois";
                std::cout << "Attaque avec l'arme :  " << JoueurArme << '\n';
                PileOuFace = PileOuFace = rand() % 3 + 1;   // 1 -> 2
                JoueurDegat = 10;
                if(PileOuFace > 1)
                {
                    JoueurDegat = JoueurDegat * 0;
                }
                else
                {
                    JoueurPlay = true;
                }

                EnnemieVie = EnnemieVie - JoueurDegat;

                std::cout << '\n';
                std::cout << "Degat infliger : " << JoueurDegat << '\n';
            
            default:
                break;
            }

        break;
        ///////////////////////////////////////////////
        case 2:
            switch (MenuMagie())
            {
            case 1:
            JoueurMagie="Boule de feu";
            std::cout << "Attaque avec la magie  :  " << JoueurMagie << " ." << '\n';
            PileOuFace = PileOuFace = rand() % 3 + 1; //1 -> 3
            JoueurDegat = 30;
            if(PileOuFace > 1)
            {
                JoueurDegat = JoueurDegat * 0;
            }

            EnnemieVie = EnnemieVie - JoueurDegat;

            std::cout << '\n';
            std::cout << "Degat infliger : " << JoueurDegat << " ." << '\n';
            JoueurDegat = 10;
            break;
            //////////////
            case 2:
            JoueurMagie="BOMBE THERMONUCLEAIRE";
            std::cout << "Attaque avec la magie  :  " << JoueurMagie << " ." << '\n';
            PileOuFace = PileOuFace = rand() % 2 + 1; //1 -> [100 DEBUG MODE ON]
            JoueurDegat = 1000000000;
            if(PileOuFace > 1)
            {
                JoueurDegat = JoueurDegat * 0;
            }

            EnnemieVie = EnnemieVie - JoueurDegat;

            std::cout << '\n';
            std::cout << "Degat infliger : " << JoueurDegat << " ." << '\n';
            JoueurDegat = 10;
            break;
            
            default:
                break;
            }
        break;
        ///////////////////////////////////////////////
        case 3:
            switch (MenuObjet())
            {
            case 1:
                JoueurObjet = "Potion susupect";
                std::cout << "Utilisation de l'objet :  " << JoueurMagie << " ." << '\n';
                PileOuFace = PileOuFace = rand() % 2 + 1; //1 -> 2
                
                if(PileOuFace == 1)
                {
                    JoueurVie = JoueurVie + 30;

                    std::cout << '\n';
                    std::cout << "Vous avez eu de la chance : +30 PV !" << '\n';
                }
                else
                {
                    JoueurVie = JoueurVie - 20;
                    std::cout << '\n';
                    std::cout << "Pas de bol : -20 PV !" << '\n';
                }
            break;
            //////////////
            default:
                break;
            }
        break;
        ///////////////////////////////////////////////
        default:
            break;
        }
}
    std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << '\n';

    return {JoueurVie , EnnemieVie};

}

int TourEnnemie(int JoueurVie)
{

srand(time(NULL));

int PileOuFace;
int ChoixEnnemie;

int EnnemieVie = 100;
int EnnemieDegat = 10;
std::string EnnemieArme= "Epee de bois";
std::string EnnemieMagie= "Boule de feu";


std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << '\n';

ChoixEnnemie=rand() % 2 + 1;

switch (ChoixEnnemie)
    {
    case 1:
        std::cout << "Attaque avec l'arme :  " << EnnemieArme << " ." << '\n';
        PileOuFace = PileOuFace = rand() % 2 + 1;   // 1 -> 2
        EnnemieDegat = 10;
        if(PileOuFace > 1)
        {
            EnnemieDegat = EnnemieDegat * 0;
        }

        JoueurVie = JoueurVie - EnnemieDegat;

        std::cout << '\n';
        std::cout << "Degat infliger : " << EnnemieDegat << " ." << '\n';

    break;
    ///////////////////////////////////////////////
    case 2:
        std::cout << "Attaque avec la magie  :  " << EnnemieMagie << " ." << '\n';
        PileOuFace = PileOuFace = rand() % 3 + 1; //1 -> 3
        EnnemieDegat = 30;
        if(PileOuFace > 1)
        {
            EnnemieDegat = EnnemieDegat * 0;
        }

       JoueurVie = JoueurVie - EnnemieDegat;

        std::cout << '\n';
        std::cout << "Degat infliger : " << EnnemieDegat << " ." << '\n';
        EnnemieDegat = 10;
    break;
    ///////////////////////////////////////////////
    case 3:
        std::cout << "Defense !";
    break;
    ///////////////////////////////////////////////
    default:
        break;
    }

    std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << '\n';

    return JoueurVie;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GAME()
{
    system("cls");
    srand(time(NULL));

    int nbrRound = 1;
    char Choix = 'Y';
    int nbrEnnemie = 0;

    int PileOuFace;

    int JoueurVie = 100;
    int JoueurDegat = 10;
    std::string JoueurArme= "Epee de bois";
    std::string JoueurMagie= "Boule de feu";

    int EnnemieVie =100;
    int EnnemieDegat = 10;
    std::string EnnemieArme= "Epee de bois";
    std::string EnnemieMagie= "Boule de feu";


    while(Choix != 'N')
    {
        std::cout << "_________________________________________________________________________________________________________________________" << '\n';
        std::cout << '\n';
        std::cout << "                                                  ENNEMIE NUMERO " << nbrEnnemie + 1 << '\n';
        std::cout << '\n';
        while(EnnemieVie > 0 && JoueurVie > 0)
        {

            std::cout << "################################################################################################################" << '\n';
            std::cout << "                                                  Round " << nbrRound ; 
            std::cout << '\n';
            std::cout << "Vie ennemie : " << EnnemieVie << " PV " << '\n'; 
            std::cout << "Vie joueur : " << JoueurVie << " PV" << '\n'; 


            Memory result = TourJoueur(EnnemieVie,JoueurVie);
            EnnemieVie = result.EnnemieVie;
            JoueurVie = result.JoueurVie;

            
            if(EnnemieVie > 0)
            {
            JoueurVie=TourEnnemie(JoueurVie);
            }
            
            
            std::cout << '\n';
            std::cout << '\n';

            
            nbrRound ++;
        }

        if(EnnemieVie <= 0)
        {
            std::cout << "BRAVO TU A GAGNER !!!" << '\n';
        }
        else if(JoueurVie <= 0)
        {
            std::cout << "MINCE , TU A PERDU !!!" << '\n';
        }

        std::cout << '\n';
        std::cout << '\n';
        std::cout << "Voulez-vous recommencer ? (Y/N) : " << '\n' << "      > ";
        std::cin >> Choix;
        Choix = std::toupper(Choix);
        while( Choix != 'Y' && Choix != 'N')
        {
            std::cout << '\n';
            std::cout << "Erreur : Seul les reponse Y/y et N/n sont autoriser !" << '\n';
            std::cout << "Voulez-vous avoir un supplement dans votre plat ? (Y/N) : " << '\n' << "  > ";
            std::cin >> Choix;
            Choix = std::toupper(Choix);
            std::cout << '\n';
        }

        if(Choix == 'Y')
        {
            nbrEnnemie ++;
            std::cout << "nbrEnnemie : " << nbrEnnemie << '\n';
            EnnemieVie = 100 + (10 * nbrEnnemie);
            system("cls");
        }
        else
        {
            main();
            nbrEnnemie =0;
        }

    }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CREDIT()
{

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


}

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
    std::cout << "      2) BOMBE THERMONUCLEAIRE " << '\n';
    std::cout << "          - 1/100 de faire -1 000 000 000 PV a l'ennemie ce qui signe la fin des " << '\n';
    std::cout << "            temps [DEBUG TOOL LOL]" << '\n';
    std::cout << '\n';
    std::cout << "Objet disponiblre :" << '\n';
    std::cout << "      1) [PAS ENCORE DIPSO] Potion suspecte" << '\n';
    std::cout << "          - Sois +30 PV sois  -20 PV" << '\n';
    std::cout << '\n';
    std::cout << '\n';
    std::cout << "_________________________________________________________________________________________________________________________" << '\n';
    std::cout << '\n';
    std::cout << "Voulez vous revenir a l'ecran titre ou voulez-vous quitter le jeu ? (Y/N) : " << '\n' << "      > " ;
    std::cin >> Choix;
    while(Choix != 'N' && Choix != 'Y')
    {
        std::cout << '\n';
        std::cout << "     ERREUR : Entre non valide !!!" << '\n';
        std::cout << "     Entrer 'Y' ou 'N' UNIQUEMENT : " << '\n' << "        > " ;
        std::cin >> Choix;
    }

    if(Choix == 'Y')
    {
        main();
    }


}

int main()
{

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
        GAME();
    break;
    ///////////////////
    case 2:
        CREDIT();
    break;
    ///////////////////
    case 3:
        INFO(); 
    break;
    ///////////////////
    case 4:
        std::cout << "4";
    break;
    ///////////////////
    default:
        std::cout << "Error"; 
    break;
    }



    system("cls");
    return 0;
}