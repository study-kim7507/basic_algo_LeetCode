struct cmp
{
    bool operator()(vector<int>& classA, vector<int>& classB)
    {
        int passA = classA[0];
        int totalA = classA[1];
        double originalRatioA = (double)passA / totalA;

        int passB = classB[0];
        int totalB = classB[1];
        double originalRatioB = (double)passB / totalB;

        passA++; totalA++; passB++; totalB++;

        double newRatioA = (double)passA / totalA;
        double newRatioB = (double)passB / totalB;

        double diffA = newRatioA - originalRatioA;
        double diffB = newRatioB - originalRatioB;

        if (diffA <= diffB) return true;
        else return false;
    }
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // 새로운 학생을 추가했을 때, 오르는 평균 합격 비율이 가장 높은 클래스에 삽입
        // Prority Queue

        int n = classes.size();

        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        for(auto& e : classes)
            pq.push(e);

        for (int i = 0; i < extraStudents; i++)
        {
            auto cur = pq.top(); pq.pop();
            cur[0] += 1; 
            cur[1] += 1;
            pq.push(cur);
        }

        double ans = 0.0;
        while (!pq.empty())
        {
            auto cur = pq.top(); pq.pop();

            std::cout << cur[0] << " " << cur[1] << "\n";
            ans += (double)cur[0] / cur[1]; 
        }

        ans /= n;
        return ans;
    }
};