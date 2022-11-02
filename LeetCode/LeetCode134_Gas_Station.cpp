// Time complexity: O(N)
// Space complexity: O(1)
/*
  1,2,3,4,5
- 3,4,5,1,2
  -2,-2,-2,3,3
  0,2,4,6,3

  2,3,4
  3,4,3
  -1,0,1
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        gas[n - 1] -= cost[n - 1];
        int maxGas = gas[n-1], ans = n-1;

        for (int i = n-2; i >= 0; i--) {
            gas[i] += gas[i+1] - cost[i];
            if (gas[i] > maxGas) {
                maxGas = gas[i];
                ans = i;
            }
        }

        return gas[0] >= 0 ? ans : -1;
    }
};

// Without storing values into memory faster than upper approach
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), totalG=0, totalC=0, idx=0, temp=0;
        
        for(int i=0; i<n; i++){
            totalG += gas[i];
            totalC += cost[i];
        }
        
        if(totalC > totalG) return -1;
        
        for(int i=0; i<n; i++){
            temp += gas[i];
            temp -= cost[i];
            
            if(temp<0){
                idx = i+1;
                temp = 0;
            }
        }
        
        return idx;
    }
};