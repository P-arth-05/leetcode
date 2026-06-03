class Solution {
public:
    bool isHappy(int n) {
        int count = 0;
        while (count < 100000){
            int num = 0 ;
            while(n > 0){
                num += (n%10)*(n%10);
                n = n / 10;
            }
            n = num;
            if (n == 1){
                return true;
            }
            count++;
        }
        return false;
    }
};