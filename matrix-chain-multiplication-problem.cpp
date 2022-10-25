#include<bits/stdc++.h>
using namespace std;


int MatrixChainOrder(int p[], int n)
{
  int m[n][n];

  int i, j, k, L, q;

  for (i=0; i<n; i++)
    m[i][i] = 0;

  for (L=2; L<n; L++)
  {
    for (i=1; i<n-L+1; i++)
    {
      j = i+L-1;
        m[i][j] = INT_MAX;
      for (k=i; k<j; k++)
      {
        q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
        if (q < m[i][j])

          m[i][j] = q;
      }
    }

  }
  for(int i = 1; i <n; i++){
    for(int j = 1; j <n; j++){
       if(j >= i){
        cout << m[i][j] << "\t";
       }
       else {
        cout << "\t";
       }

    }
    cout << endl;
  }
  return m[1][n-1];
}

int main()
{
  int arr[] = {4,10,3,12,20,7};
  int size = sizeof(arr)/sizeof(arr[0]);
    cout<< MatrixChainOrder(arr,size)<<" Minimum scalar operations";

}
