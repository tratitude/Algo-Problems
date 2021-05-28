#include <bits/stdc++.h>

using namespace std;

#define ALL(x) x.begin(), x.end()

typedef long long int lld;
typedef pair<int, int> pii;

int n;
vector<int> negVec;

int nextNeg(int index, int bound)
{
    if(index+bound < negVec.size()){
        return negVec[index+bound];
    }
    else{
        return n -1;
    }
}

int beforeNeg(int index, int bound)
{
    if(index-bound > 0){
        return negVec[index-bound];
    }
    else{
        return n -1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(15);
    cout << fixed;

    int pos=0, neg=0;
    //vector<bool> input;
    
    cin >> n;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        //input.push_back(num>0);  // pos = true
        if(num<0)
            negVec.push_back(i);
    }
    for(int bound=0; bound<negVec.size(); bound++){
        for(int count=0; count < negVec.size(); count+=bound){
            if(bound%2){  // neg
                if(count == 0){
                    int now = negVec[count];
                    int after = nextNeg(count, bound);
                    neg += ((after - now) * (now+1));
                }
                else{
                    int before = negVec[count-1];
                    int after = nextNeg(count, bound);
                    int now = negVec[count];
                    neg += (after-before)*(now-before+1);
                }
                
            }
            else{
                if(count == 0){

                }
                else{

                }
            }
        }
    }

    cout << pos << " " << neg << endl;
    return 0;
}