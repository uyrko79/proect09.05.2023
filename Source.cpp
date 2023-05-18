#include <iostream>
using namespace std;

char board[3][3]; // ������� ����

// ������� ��� ����������� �������� ����
void display_board()
{
    cout << "-------------\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "| " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " |\n";
        cout << "-------------\n";
    }
}

// ������� ��� �������� ����������
char check_winner()
{
    // �������� �������������� � ������������ �����
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return board[i][0];
        }

        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return board[0][i];
        }
    }

    // �������� ����������
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return board[0][0];
    }

    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return board[0][2];
    }

    // ��� ����������
    return ' ';
}

// ������� ��� ���� ������
void player_move(char symbol)
{
    setlocale(LC_ALL, "rus");
    int row, col;

    while (true)
    {
        cout << "��� ������ '" << symbol << "'\n";
        cout << "������� ����� ������ (1-3): ";
        cin >> row;
        cout << "������� ����� ������� (1-3): ";
        cin >> col;

        if (row < 1 || row > 3 || col < 1 || col > 3)
        {
            cout << "�������� ����, ���������� �����.\n";
        }
        else if (board[row - 1][col - 1] != ' ')
        {
            cout << "��� ������ ��� ������, �������� ������.\n";
        }
        else
        {
            board[row - 1][col - 1] = symbol;
            break;
        }
    }
}

// ������� ��� ���� ����������
void computer_move(char symbol)
{
    setlocale(LC_ALL, "rus");
    int row, col;

    cout << "��� ���������� '" << symbol << "'\n";

    while (true)
    {
        row = rand() % 3;
        col = rand() % 3;
        if (board[row][col] == ' ')
        {
            board[row][col] = symbol;
            break;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL)); // ������������� ���������� ��������� �����

    char player_symbol, computer_symbol;
    cout << "����� ���������� � ���� � ��������-������!\n";
    cout << "�������� ������, ������� ������ ������ (X ��� O): ";
    cin >> player_symbol;

    if (player_symbol == 'X' || player_symbol == 'x')
    {
        player_symbol = 'X';
        computer_symbol = 'O';
    }
    else if (player_symbol == 'O' || player_symbol == 'o')
    {
        player_symbol = 'O';
        computer_symbol = 'X';
    }
    else
    {
        cout << "������������ ������. ���� ��������.\n";
        return 0;
    }

    // ������� �������� ����
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }

    int turn = rand() % 2; // �����������, ��� ������ �����

    // �������� ������� ����
    while (true)
    {
        // ��� ������
        if (turn == 0)
        {
            player_move(player_symbol);
        }
        // ��� ����������
        else
        {
            computer_move(computer_symbol);
        }

        display_board(); // ����������� ������������ ��������� �������� ����

        char winner = check_winner();
        if (winner != ' ')
        {
            if (winner == player_symbol)
            {
                cout << "�� ��������!\n";
            }
            else
            {
                cout << "��������� �������!\n";
            }
            break;
        }

        // �������� �� �����
        bool is_draw = true;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    is_draw = false;
                    break;
                }
            }
            if (!is_draw)
            {
                break;
            }
        }
        if (is_draw)
        {
            cout << "�����!\n";
            break;
        }

        turn = 1 - turn; // ����� ����
    }

    cout << "������� �� ����! �� ��������.\n";

    return 0;
}
