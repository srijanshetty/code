#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class BoardState {
    public:
        int moves, size, nullx, nully;
        int board[5][5];
        BoardState *prev;
        BoardState *goal;

        BoardState(int s) {
            size = s;
            moves = 0;
            prev = NULL;
            goal = NULL;

            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    cin >> board[i][j];
                    if (board[i][j] == 0) {
                        nullx = i;
                        nully = j;
                    }
                }
            }
        }

        BoardState(BoardState *previous) {
            size = previous->size;
            moves = previous->moves + 1;
            prev = previous;
            goal = previous->goal;

            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    board[i][j] = previous->board[i][j];
                    if (board[i][j] == 0) {
                        nullx = i;
                        nully = j;
                    }
                }
            }
        }

        void print() {
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    cout << board[i][j] << " ";
                }
                cout << endl;
            }
        }

        int difference() const {
            int count = 0;
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    if (board[i][j] != goal->board[i][j]) {
                        ++count;
                    }
                }
            }

            return count;
        }

        bool test() {
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    if ( board[i][j] != goal->board[i][j] ) {
                        return false;
                    }
                }
            }

            return true;
        }
};

struct ManhattanBoardComparer {
    bool operator()(const BoardState &s1, const BoardState &s2) {
        return s1.moves + s1.difference() < s2.moves + s2.difference();
    }
};

struct HammingBoardComparer {
    bool operator()(const BoardState &s1, const BoardState &s2) {
        return s1.moves < s2.moves;
    }
};

priority_queue<BoardState, vector<BoardState>, ManhattanBoardComparer> mQueue;
priority_queue<BoardState, vector<BoardState>, HammingBoardComparer> hQueue;

void hMove(BoardState s1) {
    if (s1.nullx - 1 < s1.size && s1.nullx > 0) {
        BoardState temp1 = BoardState(&s1);
        temp1.board[s1.nullx][s1.nully] = temp1.board[s1.nullx - 1][s1.nully];
        temp1.board[s1.nullx - 1][s1.nully] = 0;
        temp1.nullx = s1.nullx - 1;
        hQueue.push(temp1);
    }

    if (s1.nullx + 1 < s1.size) {
        BoardState temp1 = BoardState(s1);
        temp1.board[s1.nullx][s1.nully] = temp1.board[s1.nullx + 1][s1.nully];
        temp1.board[s1.nullx + 1][s1.nully] = 0;
        temp1.nullx = s1.nullx + 1;
        hQueue.push(temp1);
    }

    if (s1.nully - 1 < s1.size && s1.nully > 0) {
        BoardState temp1 = BoardState(&s1);
        temp1.board[s1.nullx][s1.nully] = temp1.board[s1.nullx][s1.nully - 1];
        temp1.board[s1.nullx][s1.nully - 1] = 0;
        temp1.nully = s1.nully - 1;
        hQueue.push(temp1);
    }

    if (s1.nully + 1 < s1.size) {
        BoardState temp1 = BoardState(s1);
        temp1.board[s1.nullx][s1.nully] = temp1.board[s1.nullx][s1.nully + 1];
        temp1.board[s1.nullx][s1.nully + 1] = 0;
        temp1.nully = s1.nully + 1;
        hQueue.push(temp1);
    }
}

int main() {
    int size;
    cin >> size;

    BoardState start = BoardState(size);
    BoardState goal = BoardState(size);
    start.goal = &goal;

    int count = 0;
    BoardState temp = start;
    while(!temp.test()) {
        ++count;
        hMove(temp);
        temp = hQueue.top();

        // temp.print();
        cout << endl;
        hQueue.pop();
    }

    cout << count;

    return 0;
}
