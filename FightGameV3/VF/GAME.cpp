#include <iostream>
#include <ctime>    //Pour l'aleatoire
#include <cctype> // Pour mettre les char automatiquement en majuscule


#include "tour.cpp"




int GAME()
{
    system("cls");
    srand(time(NULL));

    int nbrRound = 1; //Nombre de round
    char Choix = 'Y'; //Pour continuée
    int nbrEnnemie = 0; //Incrémentation de la difficulté

    int PileOuFace; //RNG du jeu
    int JoueurNbrPotionSus = 3; //Nombre de potion suspecte
    int NombreTourEmpoisonne = 0; //Nombre de tour ou l'ennemie est empoisonnée
    int Error = 0; //Erreur (ex : Plus de potion suspecte ou deja empoissonnée)

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
        system("cls");
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

            do{
            Error =0;
            Memory result = TourJoueur(JoueurVie,EnnemieVie,JoueurNbrPotionSus,NombreTourEmpoisonne,Error);

            EnnemieVie = result.EnnemieVie;
            JoueurVie = result.JoueurVie;
            JoueurNbrPotionSus = result.JoueurNbrPotionSus;
            Error = result.Error;
            NombreTourEmpoisonne = result.NombreTourEmpoisonne;

            }while(Error == 1);
            

            // std::cout << '\n';
            // std::cout << '\n';
            // std::cout << "      [DEBUG] EnnemieVie : " << EnnemieVie << '\n';
            // std::cout << "      [DEBUG] JoueurVie : " << JoueurVie << '\n';
            // std::cout << '\n';
            // std::cout << '\n';
            
            if(EnnemieVie > 0)
            {
            JoueurVie=TourEnnemie(JoueurVie);
            }

            // std::cout << '\n';
            // std::cout << '\n';
            // std::cout << "      [DEBUG] EnnemieVie : " << EnnemieVie << '\n';
            // std::cout << "      [DEBUG] JoueurVie : " << JoueurVie << '\n';
            // std::cout << '\n';
            // std::cout << '\n';

            if(NombreTourEmpoisonne > 0)
            {
                std::cout << '\n';
                std::cout << "Ennemie empoissonne pour encore " << NombreTourEmpoisonne << " tour !" << '\n';
                std::cout << '\n';

                EnnemieVie = EnnemieVie - 5;
                NombreTourEmpoisonne --;

            }

            std::cout << "################################################################################################################" << '\n';
            
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
        }

        else
        {
        return 0;
        }

    }

}