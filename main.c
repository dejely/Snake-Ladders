#include <stdio.h>
#include <time.h>

#define MAX 4
#define BOARD 100
#define NUM_LADD 10
#define NUM_SNAKE 10

int players, roll, names[MAX], positions[MAX];
int ladder_ends[10] = {38, 14, 31, 42, 84, 44, 67, 91, 100};
int ladder_start[10] = {1, 4, 9, 21, 28, 36, 51, 71, 80};
int snake_start[10] = {6, 26, 11, 53, 19, 60, 24, 73, 75, 78};
int snake_end[10] = {16, 47, 49, 56, 62, 64, 87, 93, 95, 98};

int  roll_dice(){
    return (rand() %6) + 1;
}

int init_snake_ladder(int position){
    for (int i = 0; i < NUM_SNAKE; i++){

    }
}

int main(){

    roll = roll_dice();

    printf("Enter the number of players (2-4): ");
    scanf("%d", &players);

    if (players < 2 || players > 4) {
        printf("Invalid number of players. Exiting...\n");
        return 1;
    }

    for (int i = 0; i < players; i++) {
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", names[i]);
    }
    
    int winner = -1;
    while (winner == -1) {
        for (int i = 0; i < players; i++) {
            printf("\n%s's turn. Hit Enter to roll", names[i]);
            getchar(); 
            getchar();

            printf("%s rolled a %d.\n", names[i], roll);
            positions[i] += roll;

            if (positions[i] > BOARD) {
                positions[i] -= roll; //stays in place if roll > 100
                printf("%s needs an exact roll to win.\n", names[i]);
            } else {
                positions[i] = init_snake_ladder(positions[i]);
                printf("%s is now at position %d.\n", names[i], positions[i]);
            }
            if (positions[i] == BOARD) {
                winner = i;
                break;
            }
        }
    }

    printf("%s wins!\n", names[winner]);

}
