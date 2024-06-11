#include <iostream>
#include <limits>

using namespace std;

const int BOARD_SIZE = 3;

bool checkVictory(int tab[BOARD_SIZE][BOARD_SIZE], int line, int column, int joueur)
{
    // CHECK HORIZONTAL
    int cpt = 0;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (tab[line][i] == joueur) cpt++;
        else cpt = 0;
        if (cpt == BOARD_SIZE) return true;
    }

    // CHECK VERTICAL
    cpt = 0;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (tab[i][column] == joueur) cpt++;
        else cpt = 0;
        if (cpt == BOARD_SIZE) return true;
    }

    // CHECK DIAGONAL1
    cpt = 0;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (tab[i][i] == joueur) cpt++;
        else cpt = 0;
        if (cpt == BOARD_SIZE) return true;
    }

    // CHECK DIAGONAL2
    cpt = 0;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (tab[i][BOARD_SIZE - 1 - i] == joueur) cpt++;
        else cpt = 0;
        if (cpt == BOARD_SIZE) return true;
    }

    return false;
}

void showTab(int t[BOARD_SIZE][BOARD_SIZE])
{
    // Affichage des numéros de colonnes
    cout << "  ";
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        cout << i + 1 << " ";
    }
    cout << endl;

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        // Affichage du numéro de ligne
        cout << i + 1 << " ";

        for (int j = 0; j < BOARD_SIZE; j++)
        {
            switch (t[i][j]) {
            case 0:
                cout << (char)254;
                break;
            case 1:
                cout << "X";
                break;
            case 2:
                cout << "O";
                break;
            default:
                cout << "?";
            }
            cout << " ";
        }
        cout << endl;
    }
}

int main()
{
    int scoreJoueur1 = 0;
    int scoreJoueur2 = 0;

    while (1)
    {
        int tab[BOARD_SIZE][BOARD_SIZE] = { 0 };
        int cptTour = 1;
        int joueur;

        while (cptTour <= BOARD_SIZE * BOARD_SIZE)
        {
            system("cls");
            joueur = (cptTour % 2 == 1) ? 1 : 2;
            cout << "Score : J1 - " << scoreJoueur1 << " | J2 - " << scoreJoueur2 << endl;
            cout << " " << endl;
            cout << "TOUR " << cptTour << endl;
            cout << "A TON TOUR JOUEUR " << joueur << endl;
            showTab(tab);

            bool hasPlayed = false;
            int line;
            int column;
            while (!hasPlayed)
            {
                cout << "Choisis ta ligne (1-" << BOARD_SIZE << ") : ";
                cin >> line;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Choisis ta colonne (1-" << BOARD_SIZE << ") : ";
                cin >> column;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                line--;
                column--;

                if (line >= 0 && line < BOARD_SIZE && column >= 0 && column < BOARD_SIZE && tab[line][column] == 0)
                {
                    tab[line][column] = joueur;
                    hasPlayed = true;
                }
                else
                {
                    cout << "Case invalide, reessaye !" << endl;
                }
            }

            if (checkVictory(tab, line, column, joueur))
            {
                break;
            }
            cptTour++;

            system("cls");
            showTab(tab);

            if (checkVictory(tab, line, column, joueur))
            {
                cout << "JOUEUR " << joueur << " A GAGNE" << endl;
                if (joueur == 1)
                {
                    scoreJoueur1++;
                }
                else
                {
                    scoreJoueur2++;
                }
            }
            else
            {
                cout << "EGALITE" << endl;
            }

        }

        char replay = 'N';
        cout << "Voulez-vous rejouer ? (Y/N) : ";
        cin >> replay;
        replay = tolower(replay);

        if (replay != 'y')
            break;
    }

    return 0;
}