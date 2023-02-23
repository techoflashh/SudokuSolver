#include<stdio.h>
#include<stdbool.h>

int COUNT=0;
bool check(char grid[9][9],int row,int coulumn,char e){
    for (int i=0;i<9;i++){
        if (grid[row][i]==e){
            return false;
        }
        if (grid[i][coulumn]==e){
            return false;
        }
        if (grid[3*(row/3) + i/3][3*(coulumn/3) + i%3]==e){
            return false;
        }
    }   
    return true;
}

bool solutions(char grid[9][9],char* arr){
    for (int row=0;row<9;row++){
        for (int col=0;col<9;col++){
            if (grid[row][col]=='0'){
                for (int i=0;i<9;i++){
                    if (check(grid,row,col,arr[i])){
                        grid[row][col]=arr[i];
                        bool temp = solutions(grid,arr);
                        if (temp==true){
                            return true;
                        }
                        else{
                            grid[row][col]='0';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
int main(){
    char grid[9][9];
    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            scanf(" %c",&grid[i][j]);
        }
    }
    char arr[9] = {'1','2','3','4','5','6','7','8','9'};
    if (solutions(grid,arr)){
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                printf("%c ",grid[i][j]);
            }
            printf("\n");
        }
    }else {
        printf("No Solutions Possible!\n");
    }
}