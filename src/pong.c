//I WANT TO PLAY WITH YOU
//        YOUR FRIEND, AI
#include <stdio.h>

int width = 80;
int height = 25;
int player1 = 0, player2 = 0;
int ball_x = 13;
int ball_y = 40;
int ball_step_x = 1;
int ball_step_y = 1;
char input;
int rocket_left = 13;
int rocket_right = 13;

int temp_move_ball = 0;

void field();
void ball();
void rocket(char);
void score();

int main(){
    int winner = 0;
    while (!winner){
        field();
        scanf("%c", &input);
        rocket(input);
        ball();
        score();
        winner = (player1 == 21 || player2 == 21) ? 1 : 0;
        // q -  выход из игры
        if (input == 'q' || input == 'Q'){
            break;
        }
    }
    return 0;
}


void field(){
    char border = '|';
    char top_bot_border = '-';
    char space = ' ';
    char left_rocket = '[';
    char right_rocket = ']';
    char ball = '*';
    
    // Начало цикла для печати строки
    for (int i = 0; i <= 25; i++){
        // Начало цикла для печати столбцов
        for (int j = 0; j <= 80; j++){
            if ((i == 0) || (i == 25)){
                printf("%c", top_bot_border); //Условие для печати верхней и нижней границы
            } else if ((i == ball_x) && (j == ball_y)){
                printf("%c", ball); // Условие для печати мяча
            } else if ((i == 3) && (j == 20)){
                printf("%d", player1); // Условие для печати счета левого игрока
            } else if ((i == 3) && (j ==  60)){
                printf("%d", player2); // Условие для печати счета правого игрока
            } else if ((j == 0) || (j == 40) || (j == 80)){
                printf("%c", border); // Условие для печати границ слева-справа-посередине
            } else if (j == 76) {
                if ( i == rocket_right - 1 || i == rocket_right || i == rocket_right + 1) {
                    // Условие для печати правой ракетки с учетом движения
                    printf("%c", right_rocket);
                } else {
                    printf("%c", space); // Условие для печати пробелов в столбце ракеток
                }
            } else if (j == 4){
                if (i == rocket_left - 1 || i == rocket_left || i == rocket_left + 1){
                    // Условие для печати левой ракетки с учетом движения
                    printf("%c", left_rocket);
                }
                else {
                    printf("%c", space); // Печать пробелов в столбцах
                }
            } else {
                    printf("%c", space); // Печать пробелов в строках
                }
            }
        printf("\n");
    }
}
// Функция движения мяча
void ball(){
    ball_x += ball_step_x;
    ball_y += ball_step_y;
    if (ball_x == 25 || ball_x == 1){
        ball_step_x = -ball_step_x;
    }
    if (ball_y == 80 || ball_y == 1){
        ball_step_y = -ball_step_y;
    }
    if ((ball_y == 5) && (ball_x == rocket_left || ball_x == rocket_left + 1 || ball_x == rocket_left -1)){
        ball_step_x = -ball_step_x;
        ball_step_y = -ball_step_y;
    }
    if ((ball_y == 75) && (ball_x == rocket_right || ball_x == rocket_right + 1 || ball_x == rocket_right -1)){
        ball_step_x = -ball_step_x;
        ball_step_y = -ball_step_y;
    }
}

// Функция для движения ракеток
void rocket(char character){
    if ((character == 'z' || character == 'Z')) rocket_left++;
    if ((character == 'a' || character == 'A')) rocket_left--;
    if ((character == 'k' || character == 'K')) rocket_right--;
    if ((character == 'm' || character == 'M')) rocket_right++;
    
    if (rocket_right == 1 ){
        rocket_right += 1;
    } else if (rocket_right == 24) {
        rocket_right -= 1;
    } else if (rocket_left == 1) {
        rocket_left += 1;
    } else if (rocket_left == 24) {
        rocket_left -= 1;
    }
}

//Функция учета счета
void score(){
    if (ball_y == 1) {
        player2 += 1;
    }
    else if (ball_y == 80){
        player1 += 1;
    }
}

