class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        map<int, int> dayMap;
        int prefixSum = 0, freeDays = 0, previousDay = days;

        for (auto& meeting : meetings) {
            previousDay = min(previousDay, meeting[0]); // 첫 회의가 시작하는 날을 알기 위해
            dayMap[meeting[0]]++;   // 회의가 시작하는 날에는 +1
            dayMap[meeting[1] + 1]--;   // 회의가 끝나는 날 +1 에는 -1
        }

        freeDays += (previousDay - 1); // 첫 회의가 시작하는 날 전에는 모두 free한 날임
        for (auto& day : dayMap) {
            int currentDay = day.first;
            
            if (prefixSum == 0) {   // 현재까지 진행 중이 회의 수 0이면 아무런 회의가 진행 X, 0 보다 크면 회의가 진행 중
                freeDays += currentDay - previousDay;   
            }
            prefixSum += day.second;
            previousDay = currentDay;
        }

        // Add all days after the last day of meetings
        freeDays += days - previousDay + 1;
        return freeDays;
    }
};