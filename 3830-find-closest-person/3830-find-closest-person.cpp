class Solution {
public:
    int findClosest(int x, int y, int z) {
        int distXtoZ = abs(x - z);
        int distYtoZ = abs(y - z);

        if (distXtoZ < distYtoZ) return 1;
        else if (distXtoZ > distYtoZ) return 2;

        return 0; 
    }
};