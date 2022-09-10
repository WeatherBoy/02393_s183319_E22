#include <iostream>
using namespace std;

typedef enum { wood, stone } material;

struct tile {
    int x, y;
    bool isWall;
    material type;
};

#define NROWS 12
#define NCOLS 16

void drawTheMaze(tile playground[NROWS][NCOLS], int player_pos_x, int player_pos_y) {

    for (int i = 0; i < NROWS; i++) {
        for (int j = 0; j < NCOLS; j++) {
            if (j == player_pos_x && i == player_pos_y) {
                cout << "O";
            } else if (playground[i][j].isWall) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

}

int main() {
    // IMPORTANT! command should be a char, because the input is not space separated.
    char command;
    tile playground[NROWS][NCOLS];

    int player_pos_x = 5;
    int player_pos_y = 5;

    // Create the maze as the lecturer intended!
    for (int i = 0; i < NROWS; i++) {
        for (int j = 0; j < NCOLS; j++) {
            playground[i][j].x = j;
            playground[i][j].y = i;
            playground[i][j].isWall = (j==0 || i==(NROWS-1) || (i==0 && j!=3) || j==(NCOLS-1));
            if (j == player_pos_x && i == player_pos_y) {
            } else if (playground[i][j].isWall) {
                playground[i][j].type = stone;
            } else {
                playground[i][j].type = wood;
            }
        }
    }

    // Then we draw it using our awesome drawTheMaze function
    drawTheMaze(playground, player_pos_x, player_pos_y);

    // Then we take in the first user command
    cin >> command;

    // Then we use a while-loop to keep taking in user commands until it becomes "q"
    // upon which we quit.
    while (command != 'q') {
        // We then always check that the updated position isn't wall before we actually
        // update our player position.
        if (command == 'l' && playground[player_pos_y][player_pos_x - 1].isWall == 0) {
            player_pos_x--;

        } else if (command == 'r' && playground[player_pos_y][player_pos_x + 1].isWall == 0) {
            player_pos_x++;

        } else if (command == 'u' && playground[player_pos_y - 1][player_pos_x].isWall == 0) {
            // Remember! Because we draw our maze from top to bottom, then our "up"-direction
            // becomes negative in terms of y. 
            // (Realize that the first thing we print is the top left corner.)
            player_pos_y--;

        } else if (command == 'd' && playground[player_pos_y + 1][player_pos_x].isWall == 0) {
            // Same as with the up-command
            player_pos_y++;

        }

        drawTheMaze(playground, player_pos_x, player_pos_y);
        cin >> command;
    }

    return 0;

}