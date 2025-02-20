#include <stdio.h>
struct Item {
    int weight, value;
};
void swap(struct Item* a, struct Item* b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}
void sortItems(struct Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((double)items[j].value / items[j].weight < (double)items[j + 1].value / items[j + 1].weight) {
                swap(&items[j], &items[j + 1]);
            }
        }
    }
}
double fractionalKnapsack(struct Item items[], int n, int capacity) {
    sortItems(items, n);
    
    double totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            totalValue += capacity * ((double)items[i].value / items[i].weight);
            break;
        }
    }
    return totalValue;
}
int main() {
    int n, capacity;
    
    printf("Enter number of items: ");
    scanf("%d", &n);
    
    struct Item items[n];

    printf("Enter weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    printf("Maximum value that can be obtained: %.2lf\n", fractionalKnapsack(items, n, capacity));
    
    return 0;
}