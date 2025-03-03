#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int board [10][10] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

void toLowerCase(char *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

void printBoard(){

    printf("\n");
    printf("   A B C D E F G H I J\n");

    for (int i = 0; i < 10; i++)
    {
        if(i < 9)
            printf(" %d ", i+1);
        else
            printf("%d ", i+1);

        for (int j = 0; j < 10; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}

int transformColumn(char column){

    switch (column)
    {
    case 'a':
        return 0;

    case 'b':
        return 1;

    case 'c':
        return 2;

    case 'd':
        return 3;

    case 'e':
        return 4;

    case 'f':
        return 5;
    
    case 'g':
        return 6;

    case 'h':
        return 7;

    case 'i':
        return 8;

    case 'j':
        return 9;
        break;
    
    default:
        break;
    }

}

int validate(int size, char direction [10], int column1, int line1, int column2, int line2){

    if(size == 2){
        
        if(line1 > line2 || line2 > line1)
            if(abs(line1 - line2) != 1)
                return 0;

        if(column1 > column2 || column2 > column1)
            if(abs(column1 - column2) != 1)
                return 0;

        if (board[line1][column1] != 0){     
            return 0;
        }
        
        if (board[line2][column2] != 0){
            return 0;
        }

        return 1;
    }  
    else{
        
        if (strcmp(direction, "vertical") == 0){

            if(abs(line1 - line2) != size-1)
                return 0;

            for (int i = 0; i < size; i++){
                if (board[line1+i][column1] != 0)
                    return 0;
            }   
        }
        else 
            if (strcmp(direction, "horizontal") == 0){
                if(abs(column1 - column2) != size-1)
                    return 0;

                for (int i = 0; i < size; i++){
                    if (board[line1][column1+i] != 0)
                    return 0;
                }
            }
            else{
                if(abs(line1 - line2) != size-1)
                    return 0;
                if(abs(column1 - column2) != size-1)
                    return 0;

                for (int i = 0; i < size; i++){
                    if (board[line1+i][column1+i] != 0)
                    return 0;
                }
            }

            return 1;
        }
}
    

int positionShips(int size, char direction [10], char column1, int line1, char column2, int line2){

    int numColumn1 = transformColumn(column1);
    int numColumn2 = transformColumn(column2);
    line1--;
    line2--;
    int valid;

    if (line1 > line2){
        int j = line2;
        line2 = line1;
        line1 = j;
    }

    if (numColumn1 > numColumn2){
        int j = numColumn2;
        numColumn2 = numColumn1;
        numColumn1 = j;
    }

    switch (size)
    {
    case 2:
        
        valid = validate(size, direction, numColumn1, line1, numColumn2, line2);
        if (valid == 0)
            return 0;


        board [line1][numColumn1] = size;
        board [line2][numColumn2] = size;
        printBoard();
        return 1;

    case 3:

        valid = validate(size, direction, numColumn1, line1, numColumn2, line2);
        if (valid == 0)
            return 0;

        if (strcmp(direction, "vertical") == 0)
        {
            for (int i = 0; i < size; i++)
            {
                board [line1+i][numColumn1] = size;
            }
            
        }
        else 
            if (strcmp(direction, "horizontal") == 0)
            {
                for (int i = 0; i < size; i++)
                {
                    board [line1][numColumn1+i] = size;
                }
            }
                else
                {
                    for (int i = 0; i < size; i++)
                    {
                        board [line1+i][numColumn1+i] = size;
                    }
                }
        printBoard();
        return 1;
    
    case 4:
        
        valid = validate(size, direction, numColumn1, line1, numColumn2, line2);
        if (valid == 0)
            return 0;

        if (strcmp(direction, "vertical") == 0)
        {
            for (int i = 0; i < size; i++)
            {
                board [line1+i][numColumn1] = size;
            }
            
        }
        else 
            if (strcmp(direction, "horizontal") == 0)
            {
                for (int i = 0; i < size; i++)
                {
                    board [line1][numColumn1+i] = size;
                }
            }
                else
                {
                    for (int i = 0; i < size; i++)
                    {
                        board [line1+i][numColumn1+i] = size;
                    }
                }
        printBoard();
        return 1;

    case 5:

        valid = validate(size, direction, numColumn1, line1, numColumn2, line2);
        if (valid == 0)
            return 0;

        if (strcmp(direction, "vertical") == 0)
        {
            for (int i = 0; i < size; i++)
            {
                board [line1+i][numColumn1] = size;
            }
            
        }
        else 
            if (strcmp(direction, "horizontal") == 0)
            {
                for (int i = 0; i < size; i++)
                {
                    board [line1][numColumn1+i] = size;
                }
            }
                else
                {
                    for (int i = 0; i < size; i++)
                    {
                        board [line1+i][numColumn1+i] = size;
                    }
                }
        printBoard();
        return 1;
    
    default:
        break;
    }

}

void collectShips(){

    int line1 = 0;
    char column1;
    int line2 = 0;
    char column2;
    char direction[10];

    do
    {
        printf("\n");
        printf("Where would you like to position your Patrol Boat (2 squares)?\n");

        while (1){
            printf("\nFirst coordinate:\n");
            printf("Column (A - J): ");
            scanf(" %c", &column1);
            if ((column1 < 'A' || column1 > 'J') && (column1 < 'a' || column1 > 'j')){
                printf("\nInvalid column. Please, type A, B, C, D, E, F, G, H, I or J.\n");
            }
            else
                break;
        }
        
        while(1){
            printf("\nLine (1 - 10): ");
            scanf(" %d", &line1);

            if (line1 < 1 || line1 > 10){
                printf("\nInvalid line. Please, type 1, 2, 3, 4, 5, 6, 7, 8, 9 or 10\n");
            }
            else
                break;
        }
        
        while (1){
            printf("\nSecond coordinate:\n");
            printf("Column (A - J): ");
            scanf(" %c", &column2);
            if ((column2 < 'A' || column2 > 'J') && (column2 < 'a' || column2 > 'j')){
                printf("\nInvalid column. Please, type A, B, C, D, E, F, G, H, I or J.\n");
            }
            else
                break;
        }
        
        while(1){
            printf("\nLine (1 - 10): ");
            scanf(" %d", &line2);

            if (line2 < 1 || line2 > 10){
                printf("\nInvalid line. Please, type 1, 2, 3, 4, 5, 6, 7, 8, 9 or 10\n");
            }
            else
                break;
        }

        if (positionShips(2, direction, column1, line1, column2, line2) == 1){
            break;
        }
        else{
            printf("\nInvalid coordinates to this ship. Please, insert data again.\n");
        }

    } while (1);

    do
    {
        getchar();
        printf("\n");
        printf("Where would you like to position your Submarine (3 squares)?\n");

        while (1){
            printf("Direction (Horizontal, Vertical or Diagonal): ");
            scanf(" %11[^\n]", direction); // Permite entrada com espaços e limita o buffer

            toLowerCase(direction); // Converte para minúsculas

            if (strcmp(direction, "vertical") != 0 && 
                strcmp(direction, "horizontal") != 0 && 
                strcmp(direction, "diagonal") != 0){
                printf("\nInvalid direction. Please, type 'vertical', 'horizontal' or 'diagonal'.\n");
            }
            else
                break;
        }
        

        while (1){
            printf("\nFirst coordinate:\n");
            printf("Column (A - J): ");
            scanf(" %c", &column1);
            if ((column1 < 'A' || column1 > 'J') && (column1 < 'a' || column1 > 'j')){
                printf("\nInvalid column. Please, type A, B, C, D, E, F, G, H, I or J.\n");
            }
            else
                break;
        }
        
        while(1){
            printf("\nLine (1 - 10): ");
            scanf(" %d", &line1);

            if (line1 < 1 || line1 > 10){
                printf("\nInvalid line. Please, type 1, 2, 3, 4, 5, 6, 7, 8, 9 or 10\n");
            }
            else
                break;
        }
        
        while (1){
            printf("\nSecond coordinate:\n");
            printf("Column (A - J): ");
            scanf(" %c", &column2);
            if ((column2 < 'A' || column2 > 'J') && (column2 < 'a' || column2 > 'j')){
                printf("\nInvalid column. Please, type A, B, C, D, E, F, G, H, I or J.\n");
            }
            else
                break;
        }
        
        while(1){
            printf("\nLine (1 - 10): ");
            scanf(" %d", &line2);

            if (line2 < 1 || line2 > 10){
                printf("\nInvalid line. Please, type 1, 2, 3, 4, 5, 6, 7, 8, 9 or 10\n");
            }
            else
                break;
        }

        if (positionShips(3, direction, column1, line1, column2, line2) == 1){
            break;
        }
        else{
            printf("\nInvalid coordinates to this ship. Please, insert data again.\n");
        }

    } while (1);


    do
    {
        getchar();
        printf("\n");
        printf("Where would you like to position your Battleship (4 squares)?\n");

        while (1){
            printf("Direction (Horizontal, Vertical or Diagonal): ");
            scanf(" %19[^\n]", direction); // Permite entrada com espaços e limita o buffer

            toLowerCase(direction); // Converte para minúsculas

            if (strcmp(direction, "vertical") != 0 && 
                strcmp(direction, "horizontal") != 0 && 
                strcmp(direction, "diagonal") != 0){
                printf("\nInvalid direction. Please, type 'vertical', 'horizontal' or 'diagonal'.\n");
            }
            else
                break;
        }
        

        while (1){
            printf("\nFirst coordinate:\n");
            printf("Column (A - J): ");
            scanf(" %c", &column1);
            if ((column1 < 'A' || column1 > 'J') && (column1 < 'a' || column1 > 'j')){
                printf("\nInvalid column. Please, type A, B, C, D, E, F, G, H, I or J.\n");
            }
            else
                break;
        }
        
        while(1){
            printf("\nLine (1 - 10): ");
            scanf(" %d", &line1);

            if (line1 < 1 || line1 > 10){
                printf("\nInvalid line. Please, type 1, 2, 3, 4, 5, 6, 7, 8, 9 or 10\n");
            }
            else
                break;
        }
        
        while (1){
            printf("\nSecond coordinate:\n");
            printf("Column (A - J): ");
            scanf(" %c", &column2);
            if ((column2 < 'A' || column2 > 'J') && (column2 < 'a' || column2 > 'j')){
                printf("\nInvalid column. Please, type A, B, C, D, E, F, G, H, I or J.\n");
            }
            else
                break;
        }
        
        while(1){
            printf("\nLine (1 - 10): ");
            scanf(" %d", &line2);

            if (line2 < 1 || line2 > 10){
                printf("\nInvalid line. Please, type 1, 2, 3, 4, 5, 6, 7, 8, 9 or 10\n");
            }
            else
                break;
        }

        if (positionShips(4, direction, column1, line1, column2, line2) == 1){
            break;
        }
        else{
            printf("\nInvalid coordinates to this ship. Please, insert data again.\n");
        }

    } while (1);


    do
    {
        getchar();
        printf("\n");
        printf("Where would you like to position your Carrier (5 squares)?\n");

        while (1){
            printf("Direction (Horizontal, Vertical or Diagonal): ");
            scanf(" %19[^\n]", direction); // Permite entrada com espaços e limita o buffer

            toLowerCase(direction); // Converte para minúsculas

            if (strcmp(direction, "vertical") != 0 && 
                strcmp(direction, "horizontal") != 0 && 
                strcmp(direction, "diagonal") != 0){
                printf("\nInvalid direction. Please, type 'vertical', 'horizontal' or 'diagonal'.\n");
            }
            else
                break;
        }
        

        while (1){
            printf("\nFirst coordinate:\n");
            printf("Column (A - J): ");
            scanf(" %c", &column1);
            if ((column1 < 'A' || column1 > 'J') && (column1 < 'a' || column1 > 'j')){
                printf("\nInvalid column. Please, type A, B, C, D, E, F, G, H, I or J.\n");
            }
            else
                break;
        }
        
        while(1){
            printf("\nLine (1 - 10): ");
            scanf(" %d", &line1);

            if (line1 < 1 || line1 > 10){
                printf("\nInvalid line. Please, type 1, 2, 3, 4, 5, 6, 7, 8, 9 or 10\n");
            }
            else
                break;
        }
        
        while (1){
            printf("\nSecond coordinate:\n");
            printf("Column (A - J): ");
            scanf(" %c", &column2);
            if ((column2 < 'A' || column2 > 'J') && (column2 < 'a' || column2 > 'j')){
                printf("\nInvalid column. Please, type A, B, C, D, E, F, G, H, I or J.\n");
            }
            else
                break;
        }
        
        while(1){
            printf("\nLine (1 - 10): ");
            scanf(" %d", &line2);

            if (line2 < 1 || line2 > 10){
                printf("\nInvalid line. Please, type 1, 2, 3, 4, 5, 6, 7, 8, 9 or 10\n");
            }
            else
                break;
        }

        if (positionShips(5, direction, column1, line1, column2, line2) == 1){
            break;
        }
        else{
            printf("\nInvalid coordinates to this ship. Please, insert data again.\n");
        }

    } while (1);
}

int main() {

    printBoard();
    
    collectShips();

    printBoard();
    
    return 0;
}
