class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> st;
        stack<int> sd;

        int initSt = students.size();
        int ans = 0;

        int st0 = 0, st1 = 0, sd0 = 0, sd1 = 0;
        for (int i = 0; i < students.size(); i++)
        {
            st.push(students[i]);
            if (students[i] == 0) st0++;
            else st1++;
        }
            
        for (int i = sandwiches.size() - 1; i >= 0; i--)
        {
            sd.push(sandwiches[i]);
            if (sandwiches[i] == 0) sd0++;
            else sd1++;
        }
            
        while(true)
        {
            int curSt = st.front();
            int curSd = sd.top();

            if (curSt == curSd)
            {
                st.pop();
                sd.pop();

                ans++;

                if (curSt == 0) st0--;
                else st1--;

                if (curSd == 0) sd0--;
                else sd1--; 
            }
            else
            {
                st.pop();
                st.push(curSt);
            }

            if (st.empty()) break;
            else if (sd.top() == 0 && st0 <= 0) break;
            else if (sd.top() == 1 && st1 <= 0) break;
        }

        return initSt - ans;
    }
};