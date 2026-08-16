class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int mindist = 1000;
        int minind = -1;
        for(int i = 0 ; i < drones.size();i++){
            for(int j = 0 ; j < 3;j++){
                int x = drones[i][0];
                int y = drones[i][1];
                int range = drones[i][2];
                int dist = abs(target[0]-x)+abs(target[1]-y);
                if(dist<=range){
                    if(dist<mindist){
                        mindist = dist;
                        minind= i;
                    }
                }
            }
        }
        return minind;
    }
};