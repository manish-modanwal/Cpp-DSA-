class StockSpanner {
public:
    vector<int> stock;

    StockSpanner() {
    }
    
    int next(int price) {
        stock.push_back(price);

        int span = 1;
        int j = stock.size() - 2;  // previous element

        while (j >= 0 && stock[j] <= price) {
            span++;
            j--;
        }

        return span;
    }
};
