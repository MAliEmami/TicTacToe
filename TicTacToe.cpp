#include <iostream>
using namespace std;

class tictactoe
{
private:
    int Board[3][3];
    int Player1;
    int Player2;

public:
    tictactoe(int board[3][3], int player1, int player2) // all the index should be 0
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                Board[i][j] = 0;
            }
        }
    }
    void set_Board(int board)
    {
        Board[3][3] = board;
    }
    void set_player1(int player1)
    {
        Player1 = player1;
    }
    void set_player2(int player2)
    {
        Player2 = player2;
    }

    void play()
    {
        int num;
        int x, y; // x==i y==j
        for (int i = 1; i < 10; i++)
        {
            cout << "print number between 1-9: ";
            if (i % 2 == 1) // if i is odd player1 turn
            {
                cout << "player1: \n";
                while (1) // if the number is wrong we use thise loop
                {
                    cin >> num;
                    if (num >= 1 && num <= 9)
                    {
                        break;
                    }
                    cerr << "wrong number!\n";
                }
                x = (num - 1) / 3; // to get i in array
                y = (num - 1) % 3; // to get j in array
                num = 1;           // to know its player1
                input(x, y, num);
                if (chekwinner() == 1)
                {
                    print();
                    cout << "*****<Player1 Won>***** \n";
                    break;
                }
            }
            else if (i % 2 == 0) // if i is even player2 turn
            {
                cout << "player2: \n";
                while (1)
                {
                    cin >> num;
                    if (num >= 1 && num <= 9)
                    {
                        break;
                    }
                    cerr << "wrong number!\n";
                }
                x = (num - 1) / 3; // to get i in array
                y = (num - 1) % 3; // to get j in array
                num = 2;           // to know its player2
                input(x, y, num);
                if (chekwinner() == 2)
                {
                    print();
                    cout << "*****<Player2 Won>***** \n";
                    break;
                }
            }
            print();
        }
        if (chekwinner() == 3)
        {
            cout << "*****<Draw>***** \n";
        }
    }

    void input(int x, int y, int num)
    {
        Board[x][y] = num;
    }

    int chekwinner()
    {
        for (int i = 0; i < 3; i++) // check vertical row player1 & player2
        {
            if (Board[i][0] == 1 && Board[i][1] == 1 && Board[i][2] == 1)
            {
                return 1;
            }
            if (Board[i][0] == 2 && Board[i][1] == 2 && Board[i][2] == 2)
            {
                return 2;
            }
        }
        for (int j = 0; j < 3; j++) // check horizontal row player1 & player2
        {
            if (Board[0][j] == 1 && Board[1][j] == 1 && Board[2][j] == 1)
            {
                return 1;
            }
            if (Board[0][j] == 2 && Board[1][j] == 2 && Board[2][j] == 2)
            {
                return 2;
            }
        }

        if (Board[0][0] == 1 && Board[1][1] == 1 && Board[2][2] == 1) // check diameter of array
        {
            return 1;
        }
        if (Board[0][2] == 1 && Board[1][1] == 1 && Board[2][0] == 1) // check diameter of array
        {
            return 1;
        }
        if (Board[0][0] == 2 && Board[1][1] == 2 && Board[2][2] == 2) // check diameter of array
        {
            return 2;
        }
        if (Board[0][2] == 2 && Board[1][1] == 2 && Board[2][0] == 2) // check diameter of array
        {
            return 2;
        }
        else
        {
            return 3;
        }
    }

    void print()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << Board[i][j] << '\t';
            }
            cout << '\n';
            cout << '\n';
        }
    }
};

int main()
{
    int board[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = 0;
        }
    }

    int player1 = 1;
    int player2 = 2;

    tictactoe A(board, player1, player2);
    A.print();
    A.play();
    A.chekwinner();
    int error;
    cin >> error;

    return 0;
}