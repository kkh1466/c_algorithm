// 탈출
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

string map[51];
int r,c,result;

int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

enum object{
    mole=1,
    water=2,
};

struct block{
    int x;
    int y;
    int type;
    int time;
    block(int _x, int _y, int _type, int _time){
        x=_x;
        y=_y;
        type=_type;
        time=_time;
    }         
};

vector<block> v;

bool cmp(block a, block b){
    if(b.type==mole) return true;
    else return false;
}

void simulation(){
    queue<block> q;
    for(const auto& b : v) q.push(b);
    while(!q.empty()){
        block b=q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int nx=b.x+dx[i];
            int ny=b.y+dy[i];
            if(nx>=0 && nx<r && ny>=0 && ny<c){
                if(b.type==water){
                    if(map[nx][ny]=='.'){
                        map[nx][ny]='*';
                        q.push(block(nx,ny,water,b.time+1));
                    }
                }

                if(b.type==mole){
                    if(map[nx][ny]=='D'){
                        result=b.time+1;
                        return;
                    } 
                    if(map[nx][ny]=='.'){
                        if(map[nx][ny]!='*'){
                            map[nx][ny]='S';
                            q.push(block(nx,ny,mole,b.time+1));
                        }
                    }
                }

            }
        }
    }
}

int main(){
    cin>>r>>c; // r행 c열
    for(int i=0; i<r; i++) cin>>map[i];

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(map[i][j]=='S'){
                v.push_back(block(i,j,mole,0));
            } 
            if(map[i][j]=='*'){
                v.push_back(block(i,j,water,0));
            }
        }
    }

    sort(v.begin(),v.end(),cmp);
    
    simulation();

    if(result==0) cout<<"KAKTUS";
    else cout<<result;

}