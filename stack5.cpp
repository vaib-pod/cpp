//735. Asteroid collision

class Solution {

public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> st;
        for(int i = 0 ; i < n ; i++){
            
            int value = asteroids[i];
            if(st.size()==0){
                st.push_back(value);
            }
            else if(st.back()>0 && value<0){
                if(abs(st.back())==abs(asteroids[i])){
                    st.pop_back();
                }
                else{
                    while((st.size()!=0) && (st.back()>0) && (abs(st.back())<abs(asteroids[i]))){
                        st.pop_back();
                    }
                    if(st.size()!=0 && (st.back()==abs(asteroids[i]))){
                        st.pop_back();
                    }
                    else if(st.size()==0 || st.back()<0){
                        st.push_back(value);
                    }
                    
                    
                }
            }
            else{
                st.push_back(value);
            }

        }
        return st;
        
    }
};
