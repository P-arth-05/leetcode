class Solution {
public:
    double angleClock(int hour, int minutes) {
        if (hour == 12) hour = 0;

        double hourAngle = hour * 30 + minutes * 0.5;
        double minuteAngle = minutes * 6;

        double angle = abs(hourAngle - minuteAngle);

        return min(angle, 360 - angle);
    }
};