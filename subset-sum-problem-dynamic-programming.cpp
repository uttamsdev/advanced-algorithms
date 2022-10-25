#include<bits/stdc++.h>
using namespace std;
int subset_sum(int set[], int size, int sum)
{
    int i, j, dp_table[size+1][sum+1];
    for(i = 0; i <= size; i++){
        for(j = 0; j <= sum; j++){
            if(i == 0 && j == 0)
                dp_table[i][j] = 1;
            else if(i == 0 && j!= 0)
                dp_table[i][j] = 0;
            else if(set[i-1] > j)
                dp_table[i][j] = dp_table[i-1][j];
            else dp_table[i][j] = dp_table[i-1][j] || dp_table[i-1][j-set[i-1]];
        }
    }
    return dp_table[size][sum];
}

int main()
{
    int set[]={2,3,4}, sum = 8, size, status;
    size = sizeof(set)/sizeof(set[0]);
    status = subset_sum(set, size, sum);
    if(status == 1){
        cout << "There exist a subset for the given set";
    }
    else {
        cout << "Not subset exist for the given set";
    }
    return 0;
}
