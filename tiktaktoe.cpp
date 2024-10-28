#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

#define X 'X'
#define O 'O'
#define EMPTY ' '
#define BOARD_SIZE 9

void SetTextColor(WORD color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void ShowMap(char arr[]) {
    cout << char(218) << char(196) << char(196) << char(196) << char(194) << char(196) << char(196) << char(196) << char(194) << char(196) << char(196) << char(196) << char(191) << endl;

    for (int row = 0; row < 3; ++row) {
        cout << char(179);
        for (int col = 0; col < 3; ++col) {
            int idx = row * 3 + col;
            if (arr[idx] == X) {
                SetTextColor(9); 
                cout << ' ' << X << ' ';
            }
            else if (arr[idx] == O) {
                SetTextColor(12);
                cout << ' ' << O << ' ';
            }
            else {
                cout << ' ' << arr[idx] << ' ';
            }
            SetTextColor(7);
            cout << char(179);
        }
        cout << endl;
        if (row < 2) {
            cout << char(195) << char(196) << char(196) << char(196) << char(197) << char(196) << char(196) << char(196) << char(197) << char(196) << char(196) << char(196) << char(180) << endl;
        }
    }

    cout << char(192) << char(196) << char(196) << char(196) << char(193) << char(196) << char(196) << char(196) << char(193) << char(196) << char(196) << char(196) << char(217) << endl;
}

bool CheckWin(char board[], char player) {
    int winPatterns[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6}
    };
    for (auto& pattern : winPatterns) {
        if (board[pattern[0]] == player && board[pattern[1]] == player && board[pattern[2]] == player)
            return true;
    }
    return false;
}

void PlayerMove(char board[], char player) {
    int move;
    do {
        cout << "Make a move (1-9): ";
        cin >> move;
        move--;
    } while (move < 0 || move >= BOARD_SIZE || board[move] == X || board[move] == O);
    board[move] = player;
}

void ComputerMove(char board[]) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[i] != X && board[i] != O) {
            board[i] = O;
            if (CheckWin(board, O)) return;
            board[i] = '1' + i;
        }
    }
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[i] != X && board[i] != O) {
            board[i] = X;
            if (CheckWin(board, X)) {
                board[i] = O;
                return;
            }
            board[i] = '1' + i;
        }
    }
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[i] != X && board[i] != O) {
            board[i] = O;
            return;
        }
    }
}

void ResetGame(char board[]) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        board[i] = '1' + i;
    }
}

int main() {
    char board[BOARD_SIZE];
    char currentPlayer = X;
    ResetGame(board);

    while (true) {
        system("cls");
        ShowMap(board);

        if (currentPlayer == X) {
            PlayerMove(board, currentPlayer);
            if (CheckWin(board, X)) {
                system("cls");
                ShowMap(board);
                cout << "YOU WIN!\n";
                break;
            }
            currentPlayer = O;
        }
        else {
            ComputerMove(board);
            if (CheckWin(board, O)) {
                system("cls");
                ShowMap(board);
                cout << "YOU LOSE!\n";
                break;
            }
            currentPlayer = X;
        }

        bool isDraw = true;
        for (int i = 0; i < BOARD_SIZE; ++i) {
            if (board[i] != X && board[i] != O) {
                isDraw = false;
                break;
            }
        }
        if (isDraw) {
            system("cls");
            ShowMap(board);
            cout << "DRAW\n";
            break;
        }
    }
    return 0;
}