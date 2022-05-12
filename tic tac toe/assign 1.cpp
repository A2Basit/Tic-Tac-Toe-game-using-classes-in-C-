#include <iostream>//standerd libraries for c++
#include <string>
using namespace std;//standerd namespace

class TicTacToe {//class tic tac toe
private:
    int list_[3][3];
    char turn;
    int enter_move;
public:
    TicTacToe() {//constructor initialing empty boards to zero
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                list_[i][j] = 0;
            }
        }
        turn = '1';
    }
    //making colomns and rows of the game i.e. maikng 3x3 grid
    void board() {
        cout << " " << endl;
      
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
            {
                cout << " " << list_[i][j];//spaces will be printed between rows and colomns
                if (j <= 1)
                    cout << " |";
                else
                    cout << endl;
                if (j == 2 && i < 2)
                    cout << "" << endl;
            }
        }
    }
    //making game engine
    void gamefoo() {
        for (int i = 0; i < 9; i++)
        {
            if (turn == '1') {
                cout << "Player 1 Turn: " << endl;
            }
            else if (turn == '2') {
                cout << "Player 2 Turn: " << endl;
            }
            int horizontal, vertical;//making two variables for entering the position to be marked
            cout << "which position" << endl;
            cin >> enter_move;//user will enter move i.e., 1,2,3,4 untill 9.
            if (enter_move == 1) {
                horizontal = 0;
                vertical = 0;
            }
            else if (enter_move == 2) {
                horizontal = 0;
                vertical = 1;
            }
            else if (enter_move == 3) {
                horizontal = 0;
                vertical = 2;
            }
            else if (enter_move == 4) {
                horizontal = 1;
                vertical = 0;
            }
            else if (enter_move == 5) {
                horizontal = 1;
                vertical = 1;
            }
            else if (enter_move == 6) {
                horizontal = 1;
                vertical = 2;
            }
            else if (enter_move == 7) {
                horizontal = 2;
                vertical = 0;
            }
            else if (enter_move == 8) {
                horizontal = 2;
                vertical = 1;
            }
            else if (enter_move == 9) {
                horizontal = 2;
                vertical = 2;
            }
            if (enter_move > 9 || enter_move < 1) {//if postion is greater than 9 or negative then error will be printed
                cout << "Invalid Enter_move Position" << endl;
                break;
            }

            if (turn == '1' && list_[horizontal][vertical] != 1 && list_[horizontal][vertical] != 2) {
                list_[horizontal][vertical] = 1;
                turn = '2';
            }
            else if (turn == '2' && list_[horizontal][vertical] != 2 && list_[horizontal][vertical] != 1) {
                list_[horizontal][vertical] = 2;
                turn = '1';
            }
            else {//if user will enter the number at already filled place it will give a message.
                cout << "Box is already filled" << endl;
                gamefoo();
            }
            board();
            //making win condition
            if ((list_[0][0] == 1 && list_[0][1] == 1 && list_[0][2] == 1) || (list_[1][0] == 1 && list_[1][1] == 1 && list_[1][2] == 1) || 
                (list_[2][0] == 1 && list_[2][1] == 1 && list_[2][2] == 1) || (list_[0][0] == 1 && list_[1][0] == 1 && list_[2][0] == 1) || 
                (list_[0][1] == 1 && list_[1][1] == 1 && list_[2][1] == 1) || (list_[0][1] == 1 && list_[1][1] == 1 && list_[2][1] == 1) || 
                (list_[0][2] == 1 && list_[1][1] == 1 && list_[2][0] == 1) || (list_[0][0] == 1 && list_[1][1] == 1 && list_[2][2] == 1))
            {//checking all the places i.e., verticle or horizontal or diagnols for player one
                cout << "Player 1 winner" << endl;
                break;
            }
            else if ((list_[0][0] == 2 && list_[0][1] == 2 && list_[0][2] == 2) || (list_[1][0] == 2 && list_[1][1] == 2 && list_[1][2] == 2) || 
                (list_[2][0] == 2 && list_[2][1] == 2 && list_[2][2] == 2) || (list_[0][0] == 2 && list_[1][0] == 2 && list_[2][0] == 2) || 
                (list_[0][1] == 2 && list_[1][1] == 2 && list_[2][1] == 2) || (list_[0][1] == 2 && list_[1][1] == 2 && list_[2][1] == 2) || 
                (list_[0][2] == 2 && list_[1][1] == 2 && list_[2][0] == 2) || (list_[0][0] == 2 && list_[1][1] == 2 && list_[2][2] == 2)) 
            {//checking all the places i.e., verticle or horizontal or diagnols for player two
                cout << "Player 2 wineer" << endl;
                break;
            }//if nothing equals then game is drawn
            else if (i == 8) {
                cout << "no one wins" << endl;
            }
        }
    }
};

int main() {//making main function
    TicTacToe a1;
    a1.board();
    a1.gamefoo();
}