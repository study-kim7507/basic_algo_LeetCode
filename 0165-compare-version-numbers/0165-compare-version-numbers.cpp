class Solution {
public:
    int compareVersion(string version1, string version2) {
        if (version1.find('.') == string::npos) version1 += ".0";
        if (version2.find('.') == string::npos) version2 += ".0";

        int v1Lead = stoi(version1.substr(0, version1.find('.')));
        int v2Lead = stoi(version2.substr(0, version2.find('.')));

        if (v1Lead < v2Lead) return -1;
        else if (v1Lead > v2Lead) return 1;

        version1 = version1.substr(version1.find('.') + 1);
        version2 = version2.substr(version2.find('.') + 1);

        vector<int> v1Revision;
        vector<int> v2Revision;

        string v1CurRevision = "";
        for (int i = 0; i < version1.size(); i++)
        {
            if (version1[i] == '.')
            {
                v1Revision.push_back(stoi(v1CurRevision));
                v1CurRevision = "";
                continue;
            }
            v1CurRevision += version1[i];
        }
        v1Revision.push_back(stoi(v1CurRevision));

        string v2CurRevision = "";
        for (int i = 0; i < version2.size(); i++)
        {
            if (version2[i] == '.')
            {
                v2Revision.push_back(stoi(v2CurRevision));
                v2CurRevision = "";
                continue;
            }
            v2CurRevision += version2[i];
        }
        v2Revision.push_back(stoi(v2CurRevision));

        int lessRevisionSize = min(int(v1Revision.size()), int(v2Revision.size()));
        int greaterRevisionSize = max(int(v1Revision.size()), int(v2Revision.size()));

        for (int i = 0; i < greaterRevisionSize - lessRevisionSize; i++)
        {
            if (v1Revision.size() < v2Revision.size()) v1Revision.push_back(0);
            else v2Revision.push_back(0);
        }

        for (int i = 0; i < greaterRevisionSize; i++)
        {
            if (v1Revision[i] < v2Revision[i]) return -1;
            else if (v1Revision[i] > v2Revision[i]) return 1;
        }

        return 0;
    }
};