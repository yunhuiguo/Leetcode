#include <iostream>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int max_area = 0;
        while(i <= j) {
            int min_index = height[i] > height[j] ? j:i;
            if(height[min_index]*(j-i) > max_area)
                max_area = height[min_index]*(j-i);
            if(min_index == i)
                i++;
            else
                j--;
        }
        return max_area;
    }
};

int main() {


}