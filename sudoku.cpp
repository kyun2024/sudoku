#include <iostream>

int m[9][9];
int rc[9],cc[9],sc[9];

using namespace std;

int sudoku_count = 0;

void f(int r,int c){
    //cout << "in\n";
    if(r==9){
        sudoku_count++;
        cout << "---------\n";
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout << m[i][j];
            }
            cout << endl;
        }
    }
    int nr,nc,idx;
    for(idx=9*r+c+1;idx<81;idx++){
        if(m[idx/9][idx%9]==0)break;
    }
    nr = idx/9;
    nc = idx%9;
    //cout << r << " " << c << " " << 3*(r/3)+c/3 << endl;
    for(int num=0;num<9;num++){
        //cout << num << endl;
        if((rc[r]&(1<<num))==0 && (cc[c]&(1<<num))==0 && (sc[3*(r/3)+c/3]&(1<<num))==0){
            m[r][c]=num+1;
            rc[r]|=(1<<num);
            cc[c]|=(1<<num);
            sc[3*(r/3)+c/3]|=(1<<num);
            f(nr,nc);
            m[r][c]=0;
            rc[r]&=~(1<<num);
            cc[c]&=~(1<<num);
            sc[3*(r/3)+c/3]&=~(1<<num);
        }
    }
}

int main(){
    int n;
    int a,b,k;
    cin >> n;
    while(n--){
        cin >> a >> b >> k;
        a--;
        b--;
        m[a][b]=k;
        rc[a]|=(1<<(k-1));
        cc[b]|=(1<<(k-1));
        sc[3*(a/3)+b/3]|=(1<<(k-1));
    }
    f(0,0);
    cout << "---------" << endl;
    cout << "count of sudoku : " << sudoku_count << endl;
    return 0;
}