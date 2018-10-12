#include<bits/stdc++.h>
using namespace std;
# define UNASSIGNED 0
class sudoku{
public:
    int mat[9][9];
public:
    sudoku(){
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                mat[i][j]=UNASSIGNED;
            }
        }
    }
    //check whether the cell has 0 or some other number from 1  to 9
    bool unAssignedPlace(int mat[9][9],int &row,int &col)
    {
        for(row=0;row<9;row++)
            {
                for(col=0;col<9;col++)
                {
                    if(mat[row][col]==UNASSIGNED)
                    {
                        return true;
                    }
                }
            }
        return false;
    }
    // checks if the cell row contains any same number as num
    bool usedRow(int mat[9][9],int row,int num)
    {
        for(int i=0;i<9;i++)
        {
            if(mat[row][i]==num)
            {
                return true;
            }
        }
        return false;
    }
     // checks if the cell column contains any same number as num
    bool usedCol(int mat[9][9],int col,int num)
    {
        for(int i=0;i<9;i++)
        {
            if(mat[i][col]==num)
            {
                return true;
            }
        }
        return false;
    }
     // checks if the cell block contains any same number as num
    bool usedBlock(int mat[9][9],int rowStart,int colStart,int num)
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(mat[rowStart+i][colStart+j]==num)
                {
                    return true;
                }
            }
        }
        return false;
    }
     // checks if the cell row, col & block contains any same number as num
    bool isSafe(int mat[9][9],int row,int col,int num)
    {
        return (!usedBlock(mat,row-row%3,col-col%3,num) && !usedRow(mat,row,num) && !usedCol(mat,col,num));
    }
    //solve sudoku by backtracking
    bool solveSudoku(int mat[9][9])
    {
        int row, col;
        if(!unAssignedPlace(mat,row,col))
        {
            return true;
        }
        for(int i=1;i<=9;i++)
        {
            if(isSafe(mat,row,col,i))
            {
                mat[row][col]=i;
                if(solveSudoku(mat))
                {
                    return true;
                }
                mat[row][col]=UNASSIGNED;
            }
        }
        return false;
    }
    //print sudoku
    void printSudoku(int mat[9][9])
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(mat[i][j]==UNASSIGNED)
                {
                    cout<<"| . |";
                }
                else
                {
                    cout<<"| "<<mat[i][j]<<" |";
                }
            }
            cout<<endl;
        }
        cout<<endl;
    }
    //soduko generator
    void sudokuGenerator(int mat[9][9],int p)
    {
        srand(time(0));
        int pos[p]={0},numpos[p]={0};
        for(int i=0;i<p;i++)
        {
            pos[i]=rand()%81;
        }
        for(int i=0;i<p;i++)
        {
            numpos[i]=rand()%9+1;
        }
        int j=0;
        for(int i=0;i<p;i++)
        {
            int num;
            int row=pos[j]/9;
            int col=pos[j]%9;
            num=numpos[j];
            if(isSafe(mat,row,col,num))
            {
                mat[row][col]=num;
            }
            j++;
        }
     }
};
//main function
int main(){
    sudoku s;
    int n,lvl;
    char ch;
    system("clear");
    cout<<"starting new game"<<endl;
    cout<<"choose level (lvl 1 or 2 or 3) :";
    cin>>lvl;
    if(lvl==1)
    {
        n=25;
    }else if(lvl==2)
    {
        n=20;
    }else if(lvl==3)
    {
        n=15;
    }
    cout<<"Sudoku: \n";
    s.sudokuGenerator(s.mat,n);
    s.printSudoku(s.mat);
    cout<<"Solved Sudoku:"<<endl;
    if (s.solveSudoku(s.mat) == true)
    {
        s.printSudoku(s.mat);
    }
    else
    {
        cout<<"No solution exists"<<endl;
    }
    cout<<"If you want to enter your own sudoku enter 'y'or to exit enter 'n':";
    cin>>ch;
    system("clear");
    if(ch=='y')
    {
        cout<<"Sudoku: \n";
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                cin>>s.mat[i][j];
            }
        }
        cout<<"Entered Sudoku: "<<endl;
        s.printSudoku(s.mat);
        cout<<"Solved Sudoku"<<endl;
        if (s.solveSudoku(s.mat) == true)
        {
            s.printSudoku(s.mat);
        }
        else
        {
            cout<<"No solution exists"<<endl;
    }
    }else
    {
        exit(0);
    }
    return 0;
}
