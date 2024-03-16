#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

const int WIDTH = 17;
const int HEIGHT = 27;
const int PLAYABLE_HEIGHT = HEIGHT - 4; // Ограничиваем высоту поля

vector<vector<int>> field(HEIGHT, vector<int>(WIDTH, 0));
vector<vector<pair<int, int>>> pieces = {
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}},   // I
    {{0, 0}, {0, 1}, {1, 1}, {2, 1}},   // J
    {{0, 1}, {1, 1}, {2, 1}, {2, 0}},   // L
    {{0, 0}, {1, 0}, {0, 1}, {1, 1}},   // O
    {{1, 0}, {2, 0}, {0, 1}, {1, 1}},   // S
    {{1, 0}, {0, 1}, {1, 1}, {2, 1}},   // T
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}}    // Z
};
vector<pair<int, int>> currentPiece;
vector<pair<int, int>> nextPiece;
int currentX = WIDTH / 2;
int currentY = 0;
int currentPieceType;
int rotation = 0;
bool gameover = false;

void draw() {
    system("cls");
    cout << "Current Field:" << endl;
    for (int i = 0; i < PLAYABLE_HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            bool pieceFound = false;
            for (auto p : currentPiece) {
                int x = currentX + p.first;
                int y = currentY + p.second;
                if (x == j && y == i) {
                    cout << "X ";
                    pieceFound = true;
                    break;
                }
            }
            if (!pieceFound) {
                if (field[i][j] == 0) cout << ". ";
                else cout << "# ";
            }
        }
        cout << endl;
    }
    cout << "Controls: A - move left, D - move right, W - rotate" << endl;
    cout << "\nNext Piece:" << endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            bool found = false;
            for (auto p : nextPiece) {
                if (p.first == j && p.second == i) {
                    found = true;
                    break;
                }
            }
            if (found) cout << "# ";
            else cout << ". ";
        }
        cout << endl;
    }
}

void generatePiece() {
    currentPiece = nextPiece;
    nextPiece.clear();
    currentPieceType = rand() % 7;
    nextPiece = pieces[currentPieceType];
    rotation = 0;
}

bool checkCollision() {
    for (auto p : currentPiece) {
        int x = currentX + p.first;
        int y = currentY + p.second;
        if (x < 0 ||  x >= WIDTH || y >= PLAYABLE_HEIGHT || field[y][x] != 0) return true;
    }
    return false;
}

void placePiece() {
    for (auto p : currentPiece) {
        int x = currentX + p.first;
        int y = currentY + p.second;
        field[y][x] = 1;
    }
}

void rotatePiece() {
    vector<pair<int, int>> rotatedPiece = currentPiece;
    for (auto& p : rotatedPiece) {
        int x = p.first;
        int y = p.second;
        p.first = -y;
        p.second = x;
    }

    if (!checkCollision()) {
        currentPiece = rotatedPiece;
    }
}

void update() {
    if (GetAsyncKeyState('A') & 0x8000 && currentX > 0) --currentX;
    if (GetAsyncKeyState('D') & 0x8000 && currentX < WIDTH - 1) ++currentX;
    if (GetAsyncKeyState('W') & 0x8000) {
        rotatePiece();
        Sleep(200); // Задержка, чтобы избежать многократного вращения при удерживании клавиши
    }

    ++currentY;

    if (checkCollision()) {
        --currentY;
        placePiece();
        generatePiece();
        currentX = WIDTH / 2;
        currentY = 0;
        if (checkCollision()) gameover = true;
    }
    else if (currentY + static_cast<int>(currentPiece.size()) > PLAYABLE_HEIGHT) {
        --currentY;
        placePiece();
        generatePiece();
        currentX = WIDTH / 2;
        currentY = 0;
        if (checkCollision()) gameover = true;
    }
}

int main() {
    srand(time(0));

    generatePiece();

    while (!gameover) {
        draw();
        update();
        Sleep(100);
    }

    cout << "Game Over!" << endl;

    return 0;
}