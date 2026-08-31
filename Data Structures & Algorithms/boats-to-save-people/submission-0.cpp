class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // So, we have weights of people and infinite number of boats.
        // One person can board on at most one boat thus the maximum number of boats we can assume are equal to the number of people.
        // Thus, each boat must carry at least one person and if any one person's weight exceeds the limit then we can't board all the people onto the boats.
        // We need a strategy to accommodate all the people onto the minimum number of boats.
        // There is one more condition given that a boat can accomodate at most 2 people at a time.
        // How do we choose those 2 people out of the given set of people?
        // If we choose the lightest 2 of all the people then it could be the case where we have a lot of weight limit wasted on the boat and wher we could have fit one heavier person instead of the lighter one.
        // And, if we choose the heaviest of the 2 people then it might be the case that they do not fit together in the boat.
        // Thus, we must find a middle ground and for each instance we must accommodate the lightest and heaviest person on the boat.

        sort(people.begin(), people.end());

        int lightestPos = 0, heaviestPos = people.size() - 1;

        int boatCounter = 0;

        while(lightestPos <= heaviestPos) {
            if(lightestPos == heaviestPos) {
                boatCounter++;
                lightestPos++;
            } else {
                if((people[lightestPos] + people[heaviestPos]) <= limit) {
                    lightestPos++;
                    heaviestPos--;
                    boatCounter++;
                } else {
                    heaviestPos--;
                    boatCounter++;
                }
            }
        }

        return boatCounter;
    }
};