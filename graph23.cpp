//1334. find the city with the smallest number of neighbours at a threshhold distance

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        for(int i = 0 ; i < edges.size();i++){
            dist[edges[i][0]][edges[i][1]] = edges[i][2]; 
            dist[edges[i][1]][edges[i][0]] = edges[i][2]; 
        }
        for(int i = 0 ; i<n;i++){
            dist[i][i]=0;
        }
        for(int k = 0 ; k<n;k++){
            for(int i = 0; i< n;i++){
                for(int j = 0 ; j < n ; j++){
                    if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX) dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }

        int maxcount = n;
        int cityno = -1;
        for(int i = 0 ; i<n;i++){
            int city = 0;
            for(int j = 0 ; j < n;j++){
                if(dist[i][j]<=distanceThreshold) city++;
            }
            if(city<=maxcount){
                maxcount = city;
                cityno = i;
            }
        }
        return cityno;
    }
};
