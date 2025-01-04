#include <iostream>
#include <ctime>    //Pour l'aleatoire
#include <cctype> // Pour mettre les char automatiquement en majuscule


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

    std::cout << "1 - Boule de feu (D = -30 ; C = 1/3 )      2 - Dard empoisonne  (D = -5 ; C = 1/5 ; E = -5 * 5 )" << '\n';
    std::cout << '\n';
    std::cout << "      > ";
    std::cin >> Choix;
    output = Verif(1,3,Choix);
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


struct Memory
{
    int JoueurVie;
    int EnnemieVie;

    int JoueurNbrPotionSus;
    int NombreTourEmpoisonne;

    int Error;
};

Memory TourJoueur(int JoueurVie , int EnnemieVie , int JoueurNbrPotionSus ,int NombreTourEmpoisonne , int Error)
{

srand(time(NULL));

int PileOuFace;

bool JoueurPlay = true; //1 tour en plus

int JoueurDegat = 10;
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
                PileOuFace = PileOuFace = rand() % 3 + 1;   // 1 -> 3
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
                if(NombreTourEmpoisonne == 0)
                {
                    JoueurMagie = "Dard empoisonne";
                    std::cout << "Attaque avec la magie  :  " << JoueurMagie << " ." << '\n';
                    PileOuFace = PileOuFace = rand() % 5 + 1; //1 -> 3
                    if(PileOuFace==1)
                    {
                        std::cout << '\n';
                        std::cout << "L'ennemie est maintenant empoisonne !" << '\n';
                        NombreTourEmpoisonne = 5;
                    }
                    else
                    {
                        std::cout << '\n';
                        std::cout << "Attaque rate !" << '\n';
                    }

                }

                else
                {
                    std::cout << '\n';
                    std::cout << "L'ennemie est deja empoisonnée , cette attaque n'est pas cummulable !";
                }

                break;
                //////////////
                case 3:
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
            }
        break;
        ///////////////////////////////////////////////
        case 3:
            switch (MenuObjet())
            {
            case 1:
                if(JoueurNbrPotionSus >0)
                {
                    JoueurObjet = "Potion susupect";
                    std::cout << "Utilisation de l'objet :  " << JoueurObjet << " ." << '\n';
                    PileOuFace = PileOuFace = rand() % 2 + 1; //1 -> 2
                    
                    if(PileOuFace == 1)
                    {
                        JoueurVie = JoueurVie + 30;

                        std::cout << '\n';
                        std::cout << "Vous avez eu de la chance : +30 PV !" << '\n';
                    }
                    else
                    {
                        JoueurVie = JoueurVie - 10;
                        std::cout << '\n';
                        std::cout << "Pas de bol : -10 PV !" << '\n';
                    }

                    JoueurNbrPotionSus --;
                    
                    std::cout << '\n';
                    std::cout << "Nombre de " << JoueurObjet << " restante : " << JoueurNbrPotionSus << '\n';
                    std::cout << '\n';

                    
                }
                else
                {
                    std::cout << "Plus de Potion suspecte en reserve !" << '\n';

                    Error = 1;
                }
            break;
            //////////////
            }
        break;
        ///////////////////////////////////////////////
        }
}
    std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << '\n';

    return {
        JoueurVie,  //Garde en mémoire les PV du Joueur 
        EnnemieVie, //Garde en mémoire les PV de l'ennemie 

        JoueurNbrPotionSus, //Garde en mémoire le nombre de potion suspecte 
        NombreTourEmpoisonne, //Iniatise les tour d'empoissonnement 

        Error //Erreur (ex : Plus de potion suspecte , enemie deja empoisonnée)
    };

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