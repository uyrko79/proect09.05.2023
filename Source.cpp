#include <iostream>
using namespace std;

char board[3][3]; // игровое поле

// функция для отображения игрового поля
void display_board()
{
    cout << "-------------\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "| " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " |\n";
        cout << "-------------\n";
    }
}

// функция для проверки победителя
char check_winner()
{
    // проверка горизонтальных и вертикальных линий
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

    // проверка диагоналей
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return board[0][0];
    }

    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return board[0][2];
    }

    // нет победителя
    return ' ';
}

// функция для хода игрока
void player_move(char symbol)
{
    setlocale(LC_ALL, "rus");
    int row, col;

    while (true)
    {
        cout << "Ход игрока '" << symbol << "'\n";
        cout << "Введите номер строки (1-3): ";
        cin >> row;
        cout << "Введите номер столбца (1-3): ";
        cin >> col;

        if (row < 1 || row > 3 || col < 1 || col > 3)
        {
            cout << "Неверный ввод, попробуйте снова.\n";
        }
        else if (board[row - 1][col - 1] != ' ')
        {
            cout << "Эта ячейка уже занята, выберите другую.\n";
        }
        else
        {
            board[row - 1][col - 1] = symbol;
            break;
        }
    }
}

// функция для хода компьютера
void computer_move(char symbol)
{
    setlocale(LC_ALL, "rus");
    int row, col;

    cout << "Ход компьютера '" << symbol << "'\n";

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
    srand(time(NULL)); // инициализация генератора случайных чисел

    char player_symbol, computer_symbol;
    cout << "Добро пожаловать в игру в крестики-нолики!\n";
    cout << "Выберите символ, которым хотите играть (X или O): ";
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
        cout << "Некорректный символ. Игра окончена.\n";
        return 0;
    }

    // очистка игрового поля
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }

    int turn = rand() % 2; // определение, кто первый ходит

    // основной игровой цикл
    while (true)
    {
        // ход игрока
        if (turn == 0)
        {
            player_move(player_symbol);
        }
        // ход компьютера
        else
        {
            computer_move(computer_symbol);
        }

        display_board(); // отображение обновленного состояния игрового поля

        char winner = check_winner();
        if (winner != ' ')
        {
            if (winner == player_symbol)
            {
                cout << "Вы выиграли!\n";
            }
            else
            {
                cout << "Компьютер выиграл!\n";
            }
            break;
        }

        // проверка на ничью
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
            cout << "Ничья!\n";
            break;
        }

        turn = 1 - turn; // смена хода
    }

    cout << "Спасибо за игру! До свидания.\n";

    return 0;
}
