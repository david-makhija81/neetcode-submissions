class StockSpanner {
    List<Integer> prevPrices;
    Stack<Integer> lastGreaterPrice;

    public StockSpanner() {
        prevPrices = new ArrayList<>();
        lastGreaterPrice = new Stack<>();
    }
    
    public int next(int price) {
        int idx = prevPrices.size();

        prevPrices.add(price);

        while (
            (!lastGreaterPrice.empty()) && 
            (price >= prevPrices.get(lastGreaterPrice.peek()))
        ) {
            lastGreaterPrice.pop();
        }

        int ans;

        if (lastGreaterPrice.empty()) {
            ans = prevPrices.size();
        } else {
            ans = idx - lastGreaterPrice.peek();
        }

        lastGreaterPrice.push(idx);

        return ans;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */