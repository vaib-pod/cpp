// 167. Two Sum II - input array is sorted


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int point1 = 0;
        int n = numbers.size();
        int point2 = n-1;
        vector<int> arr;
        while(point1<=point2){
            int sum = 0;
            sum = numbers[point1]+numbers[point2];
            if(sum>target){
                point2--;
            }
            else if(sum<target){
                point1++;
            }
            else if(sum==target){
                arr.push_back(point1+1);
                arr.push_back(point2+1);
                break;
            }
        }
        return arr;

    }
};
