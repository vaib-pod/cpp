class Solution {
public:
    bool duplicate(string s,string t){
        string concat = s+t;
        sort(concat.begin(),concat.end());
        for(int i = 0 ; i < concat.size()-1;i++){
            if(concat[i]==concat[i+1]){
                return false;
            }
        }
        return true;
    }
    int solve(int ind, string temp,vector<string>&arr){
        int n = arr.size();
        if(ind==n){
            return temp.size();
        }
        int take = 0;
        int notTake=0;
        if(duplicate(temp,arr[ind])){
            take = solve(ind+1,temp+arr[ind],arr);
            
        }
        notTake = solve(ind+1,temp,arr);
        return max(take,notTake);
    }
    int maxLength(vector<string>& arr) {
        string temp = "";
        
        return solve(0,temp,arr);
    }
};