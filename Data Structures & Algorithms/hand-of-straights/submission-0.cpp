class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // So, we have a bunch of cards and we need to divide them into groups of pre-determined size and the values associated with the cards in a group must all be consecutive.
        // If all the cards can be put into groups like these we return true. each card must only belong in one group.
        // I guess, the approach is simple - we go through all the cards, we start from the first card we see ahead in the array if a consecutive value to this exists and this way we make different groups.
        // To avoid considering one element twice - we make a taken array which stores whether the card at that position is already taken or not.
        // And to make looking for consecutive elements easier we filter out unique elements out of the array and try to pair up the cards from that set only.

        if((hand.size() % groupSize) != 0) {
            return false;
        }

        sort(hand.begin(), hand.end());

        vector<int> uniqueHands;
        vector<int> handCount;

        int idx = 0;

        while(idx < hand.size()) {
            uniqueHands.push_back(hand[idx]);

            int count = 0;

            while((idx < hand.size()) && (hand[idx] == uniqueHands.back())) {
                idx++;
                count++;
            }

            handCount.push_back(count);

            // cout << "Hand is :" << uniqueHands.back() << endl;
            // cout << "Count is :" << handCount.back() << endl << endl;
        }

        idx = 0;

        int cardsUsed = 0;

        while(idx < (uniqueHands.size() - groupSize + 1)) {
            handCount[idx]--;
            cardsUsed++;
            for(int i = idx; i < (idx + groupSize - 1); i++) {
                if(((uniqueHands[i] + 1) != uniqueHands[i + 1]) || (handCount[i + 1] == 0)) {
                    return false;
                }

                handCount[i + 1]--;
                cardsUsed++;
            }

            while((idx < (uniqueHands.size() - groupSize + 1)) && (handCount[idx] == 0)) {
                idx++;
            }
        }

        // cout << "Cards used are : " << cardsUsed << endl;

        return (cardsUsed == hand.size()) ? true : false;
    }
};