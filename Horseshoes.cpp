//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>

using namespace std;
char mat[10][10];
int best=0;
bool vis[10][10];

void rec(int left, int right, int row, int col)
{
    //base case
    if(vis[row][col]==true)
        return;
    if(mat[row][col]!='(' && mat[row][col]!=')')
        return;
    if(mat[row][col]=='(' && right!=0)
        return;
    if(mat[row][col]==')' && left<=best/2)
        return;
    if(mat[row][col]==')')
        right++;
    else{
        left++;
    }
    if(right==left && left!=0){
        best=max(best, right);
        return;
    }
    vis[row][col]=true;
    rec(left, right, row, col+1);
    rec(left, right, row, col-1);
    rec(left, right, row+1, col);
    rec(left, right, row-1, col);
    vis[row][col]=false;
    if(mat[row][col]==')')
        right--;
    else{
        left--;
    }
}

int main()
{
    int n;
    int i, j;
    
    cin >> n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin >> mat[i][j];
        }
    }
    rec(0, 0, 1, 1);
    
    cout << best*2 << endl;
    
    return 0;
}
