//860 lemonade challenge : 

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int change = 0;
        int n = bills.size();
        int five = 0;
        int ten = 0;
        bool condition = true;
        for(int i = 0 ; i < n ; i++){
            if(bills[i]==5){
                five++;
            }
            else if(bills[i]==10){
                if(five>=1){
                ten++;
                five--;
                }
                else{
                    condition = false;
                    break;
                }
            }
            else if(bills[i]==20){
                if(ten >=1 && five>=1){
                    ten--;
                    five--;
                }
                else if (five>=3){
                    five-=3;
                }
                else{
                    condition = false;
                    break;
                }
            }

        }
        return condition;

        
    }
};
