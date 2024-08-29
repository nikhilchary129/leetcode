class Solution {
public:
    int minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        int sumv=0,sumh=0;
        for (int i = 0; i < v.size(); i++) sumv += v[i];
        for (int i = 0; i < h.size(); i++) sumh += h[i];
        int i=h.size()-1,j=v.size()-1;
        int t=0;
        while(i>=0 && j>=0){
            if(h[i]>=v[j]){
                t+=h[i]+sumv;
                sumh-=h[i];
                --i;
            }else{
                t+= v[j]+sumh;
                sumv-=v[j];
                --j;
            }
        }
        while (i >= 0) {
            t += h[i] + sumv;
            i--;
        }

        while (j >= 0) {
            t += v[j] + sumh;
            j--;
        }
         return t;
    }
};