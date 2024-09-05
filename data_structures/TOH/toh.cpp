#include <iostream>

void tower_of_hanoi(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        std::cout << "Move disk 1 from " << source << " to " << target << std::endl;
        return;
    } else {
        tower_of_hanoi(n-1, source, auxiliary, target);
        std::cout << "Move disk " << n << " from " << source << " to " << target << std::endl;
        tower_of_hanoi(n-1, auxiliary, target, source);
    }
}

int main() {
    int num_disks = 3;
    tower_of_hanoi(num_disks, 'A', 'C', 'B');
    return 0;
}
