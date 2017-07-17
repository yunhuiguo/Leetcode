#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

      void recursive(int N, vector<int>& arr, int& cnt, int* used) {
        if(arr.size() == N) {  
            cnt++;
            return;
        }

        for(int i = 0; i < N; i++) {    
            if(!used[i]) {
                if((i+1)%(arr.size()+1) == 0 || (arr.size()+1)%(i+1) == 0) {
                    used[i] = 1;
                    arr.push_back(i);
                    recursive(N, arr, cnt, used);
                    arr.pop_back();
                    used[i] = 0;
                }
            }
        }
    }


    int countArrangement(int N) {
        int cnt = 0;
        vector<int> arr;
        int used[N];
        for(int i = 0; i < N; i++)
            used[i] = 0;
        recursive(N, arr, cnt, used);

        return cnt;
    }
};

int main() {
    Solution s;
    cout << s.countArrangement(2);

    cout << endl;
    return 0;

}