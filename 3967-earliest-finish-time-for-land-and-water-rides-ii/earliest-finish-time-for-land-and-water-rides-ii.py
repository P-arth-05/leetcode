class Solution(object):
    def earliestFinishTime(self, landStartTime, landDuration, waterStartTime, waterDuration):
        min_land_finish = float('inf')
        for i in range(len(landStartTime)):
            min_land_finish = min(min_land_finish, landStartTime[i] + landDuration[i])
            
        ans_land_first = float('inf')
        for j in range(len(waterStartTime)):
            current_time = max(min_land_finish, waterStartTime[j]) + waterDuration[j]
            ans_land_first = min(ans_land_first, current_time)

        min_water_finish = float('inf')
        for i in range(len(waterStartTime)):
            min_water_finish = min(min_water_finish, waterStartTime[i] + waterDuration[i])
            
        ans_water_first = float('inf')
        for j in range(len(landStartTime)):
            current_time = max(min_water_finish, landStartTime[j]) + landDuration[j]
            ans_water_first = min(ans_water_first, current_time)

        return min(ans_land_first, ans_water_first)