class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {        
        int numFullBottles = numBottles;
        int numEmptyBottles = 0;
        int numBottlesDrunk = 0;

        // 최초 현재 가진 물을 다 마심
        numEmptyBottles = numBottlesDrunk = numFullBottles;
        numFullBottles = 0;

        while(numEmptyBottles >= numExchange)
        {
            while(numEmptyBottles >= numExchange)
            {
                numEmptyBottles -= numExchange;
                numFullBottles++;
                numExchange++;   
            }
            numBottlesDrunk += numFullBottles;
            numEmptyBottles += numFullBottles;
            numFullBottles = 0;
        }
        
        return numBottlesDrunk;
    }
};