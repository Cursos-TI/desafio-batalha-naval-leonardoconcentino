#include <stdio.h>
#include <string.h>

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

void printBoard(){

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
            for (int i = 0; i < size; i++){
                if (board[line1+i][column1] != 0)
                    return 0;
            }   
        }
        else 
            if (strcmp(direction, "horizontal") == 0){
                for (int i = 0; i < size; i++){
                    if (board[line1][column1+i] != 0)
                    return 0;
                }
            }
            else{
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

    switch (size)
    {
    case 2:
        
        int boolean = validate(size, direction, numColumn1, line1, numColumn2, line2);
        if (boolean == 0)
            break;


        board [line1][numColumn1] = size;
        board [line2][numColumn2] = size;
        
        break;

    case 3:
        
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
        
        break;
    
    case 4:
        
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
        
        break;

    case 5:
        
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
        
        break;
    
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
            scanf("%c", &column1);
            getchar();
            if (column1 >= 'a' && column1 <= 'i'){
                printf("\nInvalid column. Please, type A, B, C, D, E, F, G, H or I.\n");
            }
            else
                break;
        }
        

        printf("\nLine (1 - 10): ");
        scanf("%d", &line1);
        getchar();

        printf("\nSecond coordinate:\n");
        printf("Column (A - J): ");
        scanf("%c", &column2);
        getchar();

        printf("\nLine (1 - 10): ");
        scanf("%d", &line2);

        positionShips(2, direction, column1, line1, column2, line2);
    } while (1);
    
    
    
    getchar();
    printf("\n");
    printf("Where would you like to position your Submarine (3 squares)?\n");

        printf("Direction (Horizontal, Vertical or Diagonal): ");
        scanf("%s", direction);
        getchar();

        printf("\nFirst coordinate:\n");
        printf("Column (A - J): ");
        scanf("%c", &column1);
        getchar();

        printf("\nLine (1 - 10): ");
        scanf("%d", &line1);
        getchar();

        printf("\nSecond coordinate:\n");
        printf("Column (A - J): ");
        scanf("%c", &column2);
        getchar();

        printf("\nLine (1 - 10): ");
        scanf("%d", &line2);

        positionShips(3, direction, column1, line1, column2, line2);

    getchar();
    printf("\n");
    printf("Where would you like to position your Battleship (4 squares)?\n");

        printf("Direction (Horizontal, Vertical or Diagonal): ");
        scanf("%s", direction);
        getchar();

        printf("\nFirst coordinate:\n");
        printf("Column (A - J): ");
        scanf("%c", &column1);
        getchar();

        printf("\nLine (1 - 10): ");
        scanf("%d", &line1);
        getchar();

        printf("\nSecond coordinate:\n");
        printf("Column (A - J): ");
        scanf("%c", &column2);
        getchar();

        printf("\nLine (1 - 10): ");
        scanf("%d", &line2);

        positionShips(4, direction, column1, line1, column2, line2);

    getchar();
    printf("\n");
    printf("Where would you like to position your Carrier (5 squares)?\n");

        printf("Direction (Horizontal, Vertical or Diagonal): ");
        scanf("%s", direction);
        getchar();

        printf("\nFirst coordinate:\n");
        printf("Column (A - J): ");
        scanf("%c", &column1);
        getchar();

        printf("\nLine (1 - 10): ");
        scanf("%d", &line1);
        getchar();

        printf("\nSecond coordinate:\n");
        printf("Column (A - J): ");
        scanf("%c", &column2);
        getchar();

        printf("\nLine (1 - 10): ");
        scanf("%d", &line2);

        positionShips(5, direction, column1, line1, column2, line2);

}

int main() {

    printBoard();
    
    collectShips();

    printBoard();
    
    return 0;
}
