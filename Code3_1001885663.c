//1001885663 Tuan Trinh
//The code works with diagonal bingo both ways line 51-69

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define row 5
#define col 5

int check_row(int board[][col]);
int check_column(int board[][col]);
int check_diagonal(int board[][col]);
void out(int board[][col]);
int check_num(int dupe[], int val);
int check_board(int board[][col], int val);
int PickNumber(int dupe[], int count);
int FillBingoCard(int arr[][row], int dupe[], int count);

int check_row(int board[][col]) //row
{
    int count = 0, found = 0;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(board[i][j] == 0)
            {
                count++;
            }
        }
        if(count == 5)
        {
            found++;
        }
        count = 0;
    }

    return (found == 1)? true:false;
}

int check_column(int board[][col]) //column
{
    int count = 0, found = 0;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(board[j][i] == 0)
            {
                count++;
            }
        }
        if(count == 5)
        {
            found++;
        }
        count = 0;
    }

    return (found == 1)? true:false;
}

int check_diagonal(int board[][col]) //diagonal
{
    int count = 0;
    for(int i = 0; i < 5; i++)
    {
        if(board[i][i] == 0)
        {
            count++;
        }
    }
    
    if(count == 5) return true;
    count = 0;        

    for(int i = 4, j = 0; i >= 0; i--, j++)
    {
        if(board[j][i] == 0)
        {
            count++;
        }
    }
    return (count == 5)? true:false;
}

void out(int board[][col])
{
    printf("\n    B       I       N       G       O    \n");
    printf("-----------------------------------------\n");
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(board[i][j] == 0)
            {
                printf("|   X   ");
            }
            else if(board[i][j]/10 > 0)
            {
                printf("|  %d   ", board[i][j]);
            }
            else
            {
                printf("|   %d   ", board[i][j]);
            }
        }
        printf("|\n-----------------------------------------\n");
    }
}

int check_num(int dupe[], int val)
{
    int found = 0, i = 0;
    while(i < 75)
    {
        if(dupe[i] == val)
        {
            found = 1;
        }
        i++;
    }
    return (found == 0)? true:false;
}

int check_board(int board[][col], int val)
{
    int found = 0;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(board[i][j] == val)
            {
                board[i][j] = 0;
                found = 1;
            }
        }
    }
    return (found == 1)? true:false;
}

int PickNumber(int dupe[], int count)
{
    srand(time(0));
    int val = 0;
    val = rand()%75+1;
    while(check_num(dupe, val) == false)
    {
        val = rand()%75+1;
    }
    dupe[count] = val;
    return val;
}

int FillBingoCard(int arr[][row], int dupe[], int count)
{
    srand(time(0));
    int val = 0;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(i == 2 && j == 2)
            {
                arr[j][i] = 0;
            }
            else
            {
                val = rand()%15 + (15*j)+1;
                while(check_num(dupe, val) == false)
                {
                    val = rand()%15 + (15*j)+1;
                }
                dupe[count] = val;
                count++; 
                arr[i][j] = val;
            }
        }
    }
    return count;
}

int main()
{
    int board[row][col] = {}, val = 0;
    int count = 0, dupe[75] = {};
    int t_dupe[75] = {}, t_count = 0;
    char ans = 'Y', temp_char;

    t_count = FillBingoCard(board, t_dupe, t_count);
    out(board);
    printf("\n");

    while((check_row(board) == false && check_diagonal(board) == false && check_column(board) == false) && count < 75)
    {
        val = PickNumber(dupe, count);

        if(val <= 15 && val >= 1)
        {
            temp_char = 'B';
        }
        else if(val <= 30 && val >= 16)
        {
            temp_char = 'I';
        }
        else if(val <= 45 && val >= 31)
        {
            temp_char = 'N';
        }
        else if(val <= 60 && val >= 46)
        {
            temp_char = 'G';
        }
        else
        {
            temp_char = 'O';
        }

        printf("The next number is %c%d\n\n", temp_char, val);
        printf("Do you have it? (Y/N) ");
        scanf(" %c", &ans);
        
        if(ans != 'Y')
        {
            out(board);
            printf("\n");
            count++;
        }
        else
        {
            bool checker = check_board(board, val);
            out(board);
            printf("\n");

            if(checker == true)
            {
                if(check_row(board) == true)
                {
                    printf("You filled out a row - BINGO!!!\n");
                }
                else if(check_column(board) == true)
                {
                    printf("You filled out a column - BINGO!!!\n");
                }
                else if(check_diagonal(board) == true)
                {
                    printf("You filled out a diagonal - BINGO!!!\n");
                }
            }
            else
            {
                printf("That value is not on your BINGO card - are you trying to cheat??\n\n");
            }
            count++;
        }
    }
    return 0;
}