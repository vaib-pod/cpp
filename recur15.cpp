//282. expression add operators

class Solution {
public:
    void dfs(string& num, int target, int start, long long current, long long last_op, string expression, vector<string>& ans) {
        if(start == num.size()){
            if(current==target) ans.push_back(expression);
            return;
        }
    

    for(int i = start ; i < num.size();i++){
        if(i > start && num[start]=='0'){
            break;
        }

        string cur_num = num.substr(start,i-start+1);
        long long cur_num_val = stoll(cur_num);

        if(start==0){
            dfs(num,target, i+1, cur_num_val, cur_num_val,cur_num,ans);
        }
        else{
            dfs(num,target, i+1, current+cur_num_val, cur_num_val,expression+"+"+cur_num,ans);
            dfs(num,target, i+1, current-cur_num_val, -cur_num_val,expression+"-"+cur_num,ans);
            dfs(num,target, i+1, current-last_op+last_op*cur_num_val,last_op* cur_num_val,expression+"*"+cur_num,ans);
        }
    }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        dfs(num,target,0,0,0,"",ans);
        return ans;
    }
};
