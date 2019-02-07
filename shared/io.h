#include <iostream>

void optimize_iostream() {
    // Disable some useful safety features to make iostream faster
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

}
