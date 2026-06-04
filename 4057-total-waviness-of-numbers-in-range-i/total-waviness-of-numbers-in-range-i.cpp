class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int t = 0;
        for (int i=num1; i <= num2; i++) {
            t += wavy(i);
        }
        return t;
    }

private:
    int wavy(int n) {
        if (n < 101) return 0;
        int w = 0, a, b, c;

        c = n%10, n /= 10;
        b = n%10, n /= 10;
    
        while (n) {
            a = n%10;
            if ((b>a && b>c) || (b<a && b<c)) w++;
            c=b, b=a, n /= 10;
        }

        return w;
    }
};