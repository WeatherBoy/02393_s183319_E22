#include <iostream>
#include <math.h>
using namespace std;

typedef enum { wood, stone } material;

struct tile {
    int x, y;
    bool isWall;
    material type;
};

void drawTheMaze(tile** playground, int n_rows, int n_cols, int player_pos_x, int player_pos_y) {

    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            if (i == player_pos_y && j == player_pos_x) {
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
    int input_rows;
    int input_columns;

    cin >> input_rows >> input_columns;

    // Simply finding the player's x- and y-position.
    int player_pos_y = floor(input_rows/2);
    int player_pos_x = floor(input_columns/2);

    // initialize a double pointer of type tile, which points to a pointer
    // of size columns.
    tile** playground = new tile*[input_rows];

    for (unsigned int i = 0; i < input_rows; i++) {
        // Then at each index in our pointer I create a new
        // pointer with the size of the rows.
        playground[i] = new tile[input_columns];

    }

    // Create the maze as the lecturer intended!
    for (int i = 0; i < input_rows; i++) {
        for (int j = 0; j < input_columns; j++) {
            playground[i][j].x = j;
            playground[i][j].y = i;
            playground[i][j].isWall = (j==0 || i==(input_rows-1) || (i==0 && j!=3) || j==(input_columns-1));
            if (i == player_pos_x && j == player_pos_y) {
                // Do nothing
            } else if (playground[i][j].isWall) {
                playground[i][j].type = stone;
            } else {
                playground[i][j].type = wood;
            }
        }
    }

    // Then we draw it using our awesome drawTheMaze function
    drawTheMaze(playground, input_rows, input_columns, player_pos_x, player_pos_y);

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

        } else if (command == 'd' && playground[player_pos_y + 1][player_pos_y].isWall == 0) {
            // Same as with the up-command
            player_pos_y++;

        }

        drawTheMaze(playground, input_rows, input_columns, player_pos_x, player_pos_y);
        cin >> command;
    }

    // Finally I have to clean up after myself - garbage collection
    for (unsigned int i = 0; i < input_rows; i++) {
        // Deleting the inner arrays
        delete playground[i];

    }
    delete playground;


    return 0;
}