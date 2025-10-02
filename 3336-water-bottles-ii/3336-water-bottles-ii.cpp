class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {        
        int numEmptyBottles = 0;
        int numBottlesDrunk = 0;

        // 최초 현재 가진 물을 다 마심
        numEmptyBottles = numBottlesDrunk = numBottles;
        
        while(numEmptyBottles >= numExchange)
        {
            numEmptyBottles -= numExchange;
            numBottlesDrunk++;
            numEmptyBottles++;
            numExchange++;
        }
        
        return numBottlesDrunk;
    }
};