#include <iostream>
using namespace std;

/// Dice sum problem
#include <vector>
vector<int> current_dice;
void solve_dice_sum(int num_dice, int target_sum, int dice_count, int current_sum) {
    // Pruning
    int remaining_dice = num_dice - dice_count;
    // Bounding
    if(current_sum + (remaining_dice * 1) > target_sum) return;
    if(current_sum + (remaining_dice * 6) < target_sum) return;
    // Base case
    if(dice_count == num_dice) {
        for(int i = 0; i < num_dice; i++) cout << current_dice[i] << (i < num_dice - 1 ? " " : "");
        cout << '\n'; return;
    }
    // Build search space
    for(int face = 1; face <= 6; face++) {
        // Explore & Backtracking
        current_dice.push_back(face);                       // do
        solve_dice_sum(num_dice, target_sum, dice_count + 1, current_sum + face);          // explore
        current_dice.pop_back();                            // undo
    }
}
void main_1() {
    cout << "Dice sum problem\n----------------------------------------\n";
    int num_dice, target_sum; cin >> num_dice >> target_sum;
    // int num_dice = 3, target_sum = 14;
    cout << "Solutions:\n"; solve_dice_sum(num_dice, target_sum, 0, 0);
}

int main()
{
    main_1();
    return 0;
}
