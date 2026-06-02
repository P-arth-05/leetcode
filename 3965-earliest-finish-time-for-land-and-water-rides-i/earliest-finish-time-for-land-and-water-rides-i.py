class Solution:
    def earliestFinishTime(self, landStartTime: list[int], landDuration: list[int], 
                           waterStartTime: list[int], waterDuration: list[int]) -> int:
        
        def calculate_min_finish(start1, dur1, start2, dur2):
            min_end_first = min(s + d for s, d in zip(start1, dur1))
            return min(max(min_end_first, s) + d for s, d in zip(start2, dur2))
        # Scenario A: Land first, Water second
        land_first = calculate_min_finish(landStartTime, landDuration, waterStartTime, waterDuration)
        # Scenario B: Water first, Land second
        water_first = calculate_min_finish(waterStartTime, waterDuration, landStartTime, landDuration)
        return min(land_first, water_first)