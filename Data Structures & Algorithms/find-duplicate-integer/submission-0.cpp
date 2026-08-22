class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // So, the array contains elements ranging from 1 to n and each element occurs at least once, thus there's only one element that occurs twice and we have to figure out which element is that.
        // We can try sorting the elements in non-decreasing order and that pushes the elements having equal value consecutive to each other - thus, after that we can just traverse through the array looking for neighbours that are equal to each other. and then just return that.
        // This is an approach that requires O(n*log(n)) number of operations because of sorting.
        // Are there any other solutions that require lesser number of operations? For that we might have to eliminate sorting.
        // Another approach that does not involve sorting is to store element we come across while going through the array if we come across an element that we have already come across earlier then that element is the answer.
        // For this approach to be fast the lookup already seen elements must be fast - thus we use a hashset because it gives O(1) time lookup

        set<int> alreadySeen;

        for(int num: nums) {
            if(alreadySeen.find(num) != alreadySeen.end()) {
                return num;
            }

            alreadySeen.insert(num);
        }

        return 0;
    }
};