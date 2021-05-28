#include <bits/stdc++.h>
#define X first
#define Y second
#define mp make_pair
#define ll long long
#define pb push_back
using namespace std;
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};


struct mtt{
	vector< vector<int> > mat;
	//int mat[8][8];
	int step;
	mtt(){
		mat=vector<vector<int>>(8,vector<int>(8,-1));
	}
}m;

struct car{
	vector< pair<int,int> > v;
	int dir;
	int id;
};

queue< mtt > q;

car getCar(mtt m,int x,int y){
	car c;
	c.v.pb(mp(x,y));
	c.id = m.mat[x][y];
	for(int i=0;i<4;i++){
		pair<int,int> f = mp(x + dx[i],y+dy[i]);
		if( m.mat[f.X][f.Y] == c.id ){
			c.dir = i;
			c.v.pb(f);
			break;
		}
	}
	if(m.mat[x + dx[c.dir]*2][y+ dy[c.dir]*2] == c.id){
		c.v.pb(mp(x + dx[c.dir]*2,y+ dy[c.dir]*2));
	}
	return c;
}

int isOk(mtt m,car c,int dir,int tar){
	if(dir != c.dir && dir != 3 - c.dir) return 0;
	//cout<<"hi "<<c.id<<endl;
	for(auto f: c.v){
		pair<int,int> f2 = mp(f.X + dx[dir],f.Y + dy[dir]);
		//cout<<f2.X<<' '<<f2.Y<<' '<<m.mat[f2.X][f2.Y]<<endl;
		if( m.mat[f2.X][f2.Y] != tar && m.mat[f2.X][f2.Y] != c.id ) {
			return 0;
		}
	}

	return 1;
}

mtt moveCar(mtt m,car c,int dir){
	/*cout<<"move"<<endl;
	for(int i=1;i<=6;i++){
		for(int j=1;j<=6;j++){
			cout<<m.mat[i][j]<<' ';
		}
		cout<<endl;
	}*/	

	for(int i=1;i<=6;i++) for(int j=1;j<=6;j++) if(m.mat[i][j] == c.id) m.mat[i][j] = 0;
	
	for(auto f : c.v) m.mat[f.X + dx[dir]][f.Y + dy[dir]] = c.id;

	m.step++;
	/*cout<<"after"<<endl;
	for(int i=1;i<=6;i++){
		for(int j=1;j<=6;j++){
			cout<<m.mat[i][j]<<' ';
		}
		cout<<endl;
	}*/	

	return m;
}

int gogo(mtt m){
	for(int i=1;i<=6;i++){
		for(int j=1;j<=6;j++){
			if(m.mat[i][j] != 0 && m.mat[i-1][j] != m.mat[i][j] && m.mat[i][j-1] != m.mat[i][j]){
				//cout<<"get "<<i<<' '<<j<<endl;
				car c = getCar(m,i,j);
				//cout<<c.id<<' '<<c.dir<<endl;
				//for(auto f:c.v) cout<<f.X<<' '<<f.Y<<" - ";
				//cout<<endl;	
				
				for(int k=0;k<4;k++){
					if(c.id == 1 && k == 1 && isOk(m,c,k,-1)) {
						//cout<<"find end"<<endl;
						return 1;
					}
					if(isOk(m,c,k,0) == 1){
						//cout<<"push "<<k<<' '<<c.id<<endl;
						mtt m3 = moveCar(m,c,k)  ;
						/*for(int i2=1;i2<=6;i2++){
							for(int j2=1;j2<=6;j2++) cout<<m3.mat[i2][j2]<<' ';
							cout<<endl;
						}*/
						q.push(m3);
					}
				}
				
			}			
		}
	}	
	return 0;
}
#define hash Hash
pair<ll,ll> hash(mtt m){
	ll ans = 0;
	ll ans2 = 0;
	ll M = 12321427;
	ll M2 = 123123;
	ll mod7 = (ll)(1e9+7);
	ll mod9 = (ll)(1e9+9);
	for(int i=1;i<=6;i++) for(int j=1;j<=6;j++){
 ans = (ans * M + m.mat[i][j] +1) % mod7;
	ans2 = (ans2 * M2 + m.mat[i][j] +1 ) % mod9;
}

	
	return mp(ans,ans2);
}


int main(){
	//memset(m.mat,-1,sizeof(m.mat));	
	for(int i=1;i<=6;i++){
		for(int j=1;j<=6;j++){
			cin>>m.mat[i][j];
		}
	}	
	m.step = 2;

	set<pair<ll,ll> > ss;

	q.push(m);

	while(!q.empty()){
		mtt now = q.front();
		q.pop();

		pair<ll,ll> h = hash(now);
		
		if(ss.find(h) != ss.end()) continue;
		ss.insert(h);


		/*cout<<"now"<<' '<<now.step<<endl;
		for(int i=1;i<=6;i++){
			for(int j=1;j<=6;j++){
				cout<<now.mat[i][j]<<' ';
			}
			cout<<endl;
		}*/
		
		if(gogo(now)){
			cout<<now.step<<endl;
			return 0;	
		}

		if(now.step > 10 ){
			break;
		}
	}
	cout<<-1<<endl;	

	return 0;
}
