#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
void srs() { cout << "Please try being serious\nGood Bye\n"; }
string rps(int i)
{
    if (i == 1)
        return "Rock";
    else if (i == 2)
        return "Paper";
    else
        return "Scissors";
}
int main()
{
    cout << "Hello\nRock Paper Scissors?\nyes->1   no->0\n";
    string i;
    getline(cin, i);
    if (i != "1" && i != "0")
    {
        srs();
        return 0;
    }
    if (i == "1")
    {
        srand(time(0));
        cout << "How long do you want to play?\n";
        cout << "n Rounds->n   If you want to decide later->0  [Please make sure n is not tooo big :) ]\n";
        getline(cin, i);
        for (auto &x : i)
            if (x < '0' || x > '9')
            {
                srs();
                return 1;
            }
        int n = stoi(i), com = 0, user = 0;
        cout << "Rock<->1   Paper<->2   Scissors<->3   wantToQuit<->4\n";
        int round = 1;
        if (n == 0)
            n--;
        while (n--)
        {
            getline(cin, i);
            if (i != "1" && i != "2" && i != "3" && i != "4")
            {
                srs();
                return 1;
            }
            if (i == "4")
                break;
            cout << "Round " << round++ << endl;
            int randomNum = (rand() % 3) + 1, j = i[0] - '0';
            cout << "You->" << rps(j) << "  " << "Me->" << rps(randomNum) << endl;
            if (randomNum == j)
            {
                cout << "Haha, it's a tie. Your score->" << user << "  " << "My score->" << com << endl;
            }
            else if ((j == 1 && randomNum == 3) || j == randomNum + 1)
            {
                user++;
                cout << "You won! Your score->" << user << "  " << "My score->" << com << endl;
            }
            else
            {
                com++;
                cout << "I won:) Your score->" << user << "  " << "My score->" << com << endl;
            }
        }
        if (com == user)
        {
            cout << "DRAW! GG\n";
            cout << "Your score->" << user << "  " << "My score->" << com << endl;
        }
        else if (user > com)
        {
            cout << "Congrats! you won\n";
            cout << "Your score->" << user << "  " << "My score->" << com << endl;
        }
        else
        {
            cout << "I won:) Thanks for playing\n";
            cout << "Your score->" << user << "  " << "My score->" << com << endl;
        }
        cout << "Good Bye\n";
    }
    else
    {
        cout << "Bye! :)\nPlease do come again when you feel like playing\n";
    }
}