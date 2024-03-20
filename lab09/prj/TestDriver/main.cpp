#include "ModulesKlui.h"
#include <iostream>

int main() {
    
    int total_sum = read_data();
    int total_bonus = number_bonus(total_sum);
    double total_discount = discount_bonuses(total_bonus);
    output_result(total_bonus, total_sum - total_discount);
    
    return 0;
}
