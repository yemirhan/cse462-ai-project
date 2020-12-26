#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int turnlimit;

int win(const char board[7][7], int * winner) {
    int i, j;
    int x = 0, o = 0;

    for (i = 0; i < 7; i++){
        for (j = 0; j < 7; j++){
            if (board[i][j] == 'X'){
                if (j && board[i][j - 1] == ' ') x++;
                if ((j != 6) && board[i][j + 1] == ' ') x++;
                if (i && board[i - 1][j] == ' ') x++;
                if ((i != 6) && board[i + 1][j] == ' ') x++;
                
            }else if (board[i][j] == 'O'){
                if (j && board[i][j - 1] == ' ') o++;
                if ((j != 6) && board[i][j + 1] == ' ') o++;
                if (i && board[i - 1][j] == ' ') o++;
                if ((i != 6) && board[i + 1][j] == ' ') o++;
            }
        }
    }

    if (x == 0){
        *winner = -1;
        return -1;
    }
    if (o == 0){
        *winner = 1;
        return 1;
    }
    *winner = (x > o) ? 1 : (x < o) ? -1 : 0;
    return 0;
}

int minimax(char board[7][7], int player, int turnl) {
    int winner;

    if ((win(board, &winner) != 0) || (turnl == 0)) return winner * player;
    
    int move_i = -1;
    int tscore, score = -2;
    int i, j;

    for(i = 0; i < 9; ++i){
        for(j = 0; j < 9; ++j){
            if(player != -1 && board[i][j] == 'O'){
                if (j && board[i][j - 1] == ' '){
                    board[i][j] = ' ';
                    board[i][j - 1] = 'O';
                    tscore = -minimax(board, player * -1, turnl - 1);
                    board[i][j] = 'O';
                    board[i][j - 1] = ' ';

                    if (tscore > score){
                        score = tscore;
                        move_i = i;
                    } 
                }

                if ((j != 6) && board[i][j + 1] == ' '){
                    board[i][j] = ' ';
                    board[i][j + 1] = 'O';
                    tscore = -minimax(board, player * -1, turnl - 1);
                    board[i][j] = 'O';
                    board[i][j + 1] = ' ';

                    if (tscore > score){
                        score = tscore;
                        move_i = i;
                    }
                }

                if (i && board[i - 1][j] == ' '){
                    board[i][j] = ' ';
                    board[i - 1][j] = 'O';
                    tscore = -minimax(board, player * -1, turnl - 1);
                    board[i][j] = 'O';
                    board[i - 1][j] = ' ';

                    if (tscore > score){
                        score = tscore;
                        move_i = i - 1;
                    }
                }

                if ((i != 6) && board[i + 1][j] == ' '){
                    board[i][j] = ' ';
                    board[i + 1][j] = 'O';
                    tscore = -minimax(board, player * -1, turnl - 1);
                    board[i][j] = 'O';
                    board[i + 1][j] = ' ';

                    if (tscore > score){
                        score = tscore;
                        move_i = i + 1;
                    }
                }
 
            }
            else if(player == -1 && board[i][j] == 'X'){
                if (j && board[i][j - 1] == ' '){
                    board[i][j] = ' ';
                    board[i][j - 1] = 'X';
                    tscore = -minimax(board, player * -1, turnl - 1);
                    board[i][j] = 'X';
                    board[i][j - 1] = ' ';

                    if (tscore > score){
                        score = tscore;
                        move_i = i;
                    } 
                }

                if ((j != 6) && board[i][j + 1] == ' '){
                    board[i][j] = ' ';
                    board[i][j + 1] = 'X';
                    tscore = -minimax(board, player * -1, turnl - 1);
                    board[i][j] = 'X';
                    board[i][j + 1] = ' ';

                    if (tscore > score){
                        score = tscore;
                        move_i = i;
                    }
                }

                if (i && board[i - 1][j] == ' '){
                    board[i][j] = ' ';
                    board[i - 1][j] = 'X';
                    tscore = -minimax(board, player * -1, turnl - 1);
                    board[i][j] = 'X';
                    board[i - 1][j] = ' ';

                    if (tscore > score){
                        score = tscore;
                        move_i = i - 1;
                    }
                }

                if ((i != 6) && board[i + 1][j] == ' '){
                    board[i][j] = ' ';
                    board[i + 1][j] = 'X';
                    tscore = -minimax(board, player * -1, turnl - 1);
                    board[i][j] = 'X';
                    board[i + 1][j] = ' ';

                    if (tscore > score){
                        score = tscore;
                        move_i = i + 1;
                    }
                }
            }
        }
    }
    if(move_i == -1) return 0;
    return score;
}

void computerMove(char board[7][7]){
    int base_i, base_j;
    int move_i, move_j;
    int tscore, score = -2;
    int i, j;

    for(i = 0; i < 9; ++i){
        for(j = 0; j < 9; ++j){
            if(board[i][j] == 'O'){
                if (j && board[i][j - 1] == ' '){
                    board[i][j] = ' ';
                    board[i][j - 1] = 'O';
                    tscore = -minimax(board, -1, turnlimit);
                    board[i][j] = 'O';
                    board[i][j - 1] = ' ';

                    if (tscore > score){
                        score = tscore;
                        base_i = i;
                        base_j = j;
                        move_i = i;
                        move_j = j - 1;
                    } 
                }

                if ((j != 6) && board[i][j + 1] == ' '){
                    board[i][j] = ' ';
                    board[i][j + 1] = 'O';
                    tscore = -minimax(board, -1, turnlimit);
                    board[i][j] = 'O';
                    board[i][j + 1] = ' ';

                    if (tscore > score){
                        base_i = i;
                        base_j = j;
                        score = tscore;
                        move_i = i;
                        move_j = j + 1;
                    }
                }

                if (i && board[i - 1][j] == ' '){
                    board[i][j] = ' ';
                    board[i - 1][j] = 'O';
                    tscore = -minimax(board, -1, turnlimit);
                    board[i][j] = 'O';
                    board[i - 1][j] = ' ';

                    if (tscore > score){
                        base_i = i;
                        base_j = j;
                        score = tscore;
                        move_i = i - 1;
                        move_j = j;
                    }
                }

                if ((i != 6) && board[i + 1][j] == ' '){
                    board[i][j] = ' ';
                    board[i + 1][j] = 'O';
                    tscore = -minimax(board, -1, turnlimit);
                    board[i][j] = 'O';
                    board[i + 1][j] = ' ';

                    if (tscore > score){
                        base_i = i;
                        base_j = j;
                        score = tscore;
                        move_i = i + 1;
                        move_j = j;
                    }
                }
            }
        }
    }

    board[base_i][base_j] = ' ';
    board[move_i][move_j] = 'O';
    printf("Computer moves the piece at %c%d to %c%d\n", 'a' + base_i, 1 + base_j,  'a' + move_i, 1 + move_j);
}

void playerMove(char board[7][7]){
    char inp1[3] = {0};
    char inp2[3] = {0};

    do {
        printf("Choose piece to move : ");
        scanf("%s", inp1);
    } while (!islower(inp1[0]) || !isdigit(inp1[1]) || (board[inp1[0] - 'a'][inp1[1] - '1'] != 'X'));
    
    do {
        printf("Choose the new position for %s : ", inp1);
        scanf("%s", inp2);
    } while ((!islower(inp2[0]) || !isdigit(inp2[1]) || (board[inp2[0] - 'a'][inp2[1] - '1'] != ' ')) || 
            (((inp1[0] == inp2[0]) && (abs(inp1[1] - inp2[1]) != 1)) || ((abs(inp1[0] - inp2[0]) == 1) && (inp1[1] != inp2[1]))));
    
    board[inp1[0] - 'a'][inp1[1] - '1'] = ' ';
    board[inp2[0] - 'a'][inp2[1] - '1'] = 'X';
    printf("Player moves the piece at %s to %s\n", inp1, inp2);
}

void showBoard(char board[7][7]) {
    int i, j;

    printf("\n  1 2 3 4 5 6 7 8 9\n");

    for (i = 0; i < 7; i++){
        printf("%c ", 'a' + i);
        for (j = 0; j < 7; j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}

void init(char board[7][7], int peaces) {
    int i, x, y;

    srand((unsigned int)time(NULL));  
    
    memset(board, ' ', 49);
    
    for (i = 0; i < peaces; i++){
        x = rand() % 7;
        y = rand() % 7;

        if (board[x][y] == ' ')
            board[x][y] = 'X';
        else
            i--;
    }

    for (i = 0; i < peaces; i++){
        x = rand() % 7;
        y = rand() % 7;

        if (board[x][y] == ' ')
            board[x][y] = 'O';
        else
            i--;
    }
} 


int main(){
    char board[7][7];
    int winner, turn, player, peaces;
    
    printf("AI: O, You: X\nAre you Player1 or Player2? (enter 1 or 2): ");
    scanf("%d", &player);

    printf("Number of pieces: ");
    scanf("%d", &peaces);

    printf("What is turnlimit?: ");
    scanf("%d", &turnlimit);
    
    init(board, peaces);

    for (turn = 0; turn < (turnlimit * 2); ++turn){
        if (win(board, &winner) != 0)
            break;
        if ((turn + player) % 2 == 0)
            computerMove(board);
        else{
            showBoard(board);
            playerMove(board);
        }
    }

    if (turn == turnlimit)
        win(board, &winner);

    if (winner == 0)
        printf("DRAW\n");
    else if (winner == 1)
        printf("PLAYER1 WINS.\n");
    else if (winner == -1)
        printf("PLAYER2 WINS.\n");

    return 0;
}
