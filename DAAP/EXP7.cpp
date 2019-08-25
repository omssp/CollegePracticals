//Knapsack algorithm
#include "iostream"
#include "vector"
#include "bits/stdc++.h"
struct Item{
	int value, weight;
	Item(int weight, int value) : weight(weight), value(value) {}
};
class Knapsack {
private:
	int W, n;
	std::vector<Item *> arr;
public:
	Knapsack(int W, int n) {
		this->n = n;
		this->W = W;
	}
	static bool max(struct Item *a, struct Item *b) {
		double r1 = (double)a->value / a->weight;
		double r2 = (double)b->value / b->weight;
		return r1 > r2;
	}
	void fractionalKnapsack() {
		std :: sort(arr.begin(), arr.end(), max);
		int currWeight = 0;
		double finalValue = 0.0;

		for (int i = 0; i < n; ++i) {
			if (currWeight + arr[i]->weight <= W) {
				currWeight += arr[i]->weight;
				finalValue += arr[i]->value;
			} else {
				finalValue += arr[i]->value * ((double) (W - currWeight) / arr[i]->weight);
				break;
			}
		}
		std :: cout << "Maximum value Knapsack can hold : " << finalValue << std :: endl;
	}
	void input() {
		std :: cout << "Enter the values-weights of Items\n";
		for (int i = 0; i < n; ++i) {
			int w, v;
			std :: cout << " Enter Item " << (i + 1) << " [V W] : ";
			std :: cin >> v >> w;
			arr.push_back(new Item(w,v));
		}
	}
};

int main() {
	int n, W;
	std :: cout << "Enter the capacity of Knapsack : ";
	std :: cin >> W;
	std :: cout << "Enter the total number of Items : ";
	std :: cin >> n;

	Knapsack a(W, n);

	a.input();
	a.fractionalKnapsack();
	
	return 0;
}
