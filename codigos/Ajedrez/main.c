
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8

char board[SIZE][SIZE];

// Inicializa el tablero con las piezas en su lugar
void initBoard() {
    const char* initRowWhite = "RNBQKBNR";
    const char* initRowBlack = "rnbqkbnr";

    for (int i = 0; i < SIZE; i++) {
        board[0][i] = initRowBlack[i]; // negras
        board[1][i] = 'p';             // peones negros
        board[6][i] = 'P';             // peones blancos
        board[7][i] = initRowWhite[i]; // blancas
    }

    // casillas vacías
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '.';
        }
    }
}

// Muestra el tablero
void printBoard() {
    printf("\n  a b c d e f g h\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("%d\n", 8 - i);
    }
    printf("  a b c d e f g h\n\n");
}

// Convierte coordenadas tipo "e2" a índices [fila][columna]
int parsePosition(char pos[3], int* row, int* col) {
    if (strlen(pos) != 2) return 0;
    *col = pos[0] - 'a';
    *row = 8 - (pos[1] - '0');
    return (*row >= 0 && *row < SIZE && *col >= 0 && *col < SIZE);
}

// Mueve una pieza si es válido
int movePiece(char from[3], char to[3]) {
    int r1, c1, r2, c2;
    if (!parsePosition(from, &r1, &c1) || !parsePosition(to, &r2, &c2)) {
        printf("Coordenadas inválidas.\n");
        return 0;
    }

    char piece = board[r1][c1];
    if (piece == '.') {
        printf("No hay pieza en esa casilla.\n");
        return 0;
    }

    // Puedes agregar aquí reglas específicas según el tipo de pieza
    board[r2][c2] = piece;
    board[r1][c1] = '.';
    return 1;
}

int main() {
    char from[3], to[3];
    int turn = 1; // 1 = blancas, 0 = negras

    initBoard();

    while (1) {
        printBoard();
        printf("Turno de %s\n", turn ? "blancas" : "negras");
        printf("Mover desde (ej. e2): ");
        scanf("%s", from);
        printf("Mover hacia (ej. e4): ");
        scanf("%s", to);

        if (movePiece(from, to)) {
            turn = !turn;
        }
    }

    return 0;
}
