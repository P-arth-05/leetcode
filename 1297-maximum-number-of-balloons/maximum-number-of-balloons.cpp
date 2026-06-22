class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> balon(5,0);
        for(int i=0;i<text.size();i++){
            if(text[i]=='b')balon[0]++;
            else if(text[i]=='a')balon[1]++;
            else if(text[i]=='l')balon[2]++;
            else if(text[i]=='o')balon[3]++;
            else if(text[i]=='n')balon[4]++;
        }
        balon[2] /= 2;
        balon[3] /= 2;
        int ans = 10000;
        for(int i = 0; i < 5; i ++){
            ans = min(ans,balon[i]);
        }
        return ans;
    }
};