class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> remnantAsteroids = new Stack<>();

        for (int i = 0; i < asteroids.length; i++) {
            while (
                (!remnantAsteroids.empty()) && 
                (asteroids[remnantAsteroids.peek()] > 0) &&
                (asteroids[i] < 0) &&
                (Math.abs(asteroids[i]) > asteroids[remnantAsteroids.peek()])
            ) {
                remnantAsteroids.pop();
            }

            if (
                (asteroids[i] < 0) && 
                (!remnantAsteroids.empty()) && 
                (asteroids[remnantAsteroids.peek()] > 0)
            ) {
                if (Math.abs(asteroids[i]) == asteroids[remnantAsteroids.peek()]) {
                    remnantAsteroids.pop();
                }
            } else {
                remnantAsteroids.push(i);
            }
        }

        int[] includeIndices = new int[remnantAsteroids.size()];

        for (int i = 0; i < includeIndices.length; i++) {
            includeIndices[i] = remnantAsteroids.pop();
        }

        Arrays.sort(includeIndices);

        int[] res = new int[includeIndices.length];

        for (int i = 0; i < res.length; i++) {
            res[i] = asteroids[includeIndices[i]];
        }

        return res;
    }
}