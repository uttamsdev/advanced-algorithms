#include <bits/stdc++.h>
using namespace std;

const int Size = 100;
int minimumPath(int dp_table[Size][Size], int row, int col){
    int minPath[row][col];
    for(int i = 0; i<row; i++) {
        for(int j = 0; j<col; j++) {
            if(i==0 && j==0) {
                minPath[i][j] = dp_table[0][0];
            }
            else if(j==0) {
                minPath[i][j] = minPath[i-1][j] + dp_table[i][j];
            }
            else if(i==0){
                minPath[i][j] = minPath[i][j-1] + dp_table[i][j];
            }
            else {
                minPath[i][j] = (minPath[i][j-1]>minPath[i-1][j] ? minPath[i-1][j]: minPath[i][j-1]) + dp_table[i][j];
            }
        }
    }
    return minPath[row-1][col-1];
}

int main() {
    int row, col;
    cout << "Enter number of rows: ";
    scanf("%d",&row);
    cout << "Enter number of columns: ";
    scanf("%d",&col);

    int dp_table[Size][Size];
    cout << "Enter table value:\n";
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            scanf("%d", &dp_table[i][j]);
        }
    }
    printf("The Minimum cost value is: %d\n", minimumPath(dp_table, row, col));
    return 0;
}
