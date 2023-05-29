// https://www.youtube.com/watch?v=VNb3VLIu1PA&list=PL43pGnjiVwgS5njI0HMGnqSH18tSSuLz_&index=11&ab_channel=CodeBeauty
#include <iostream>
#include <vector>


int main(){

    std::vector<int> numbers;
    numbers.push_back(0);

    for (int i = 1; i < 10; i++) {
        numbers.push_back(i);
    }

    /* for(auto it = numbers.begin(); it != numbers.end(); it++){
        //std::cout << it << std::endl;
        std::cout << *it << std::endl;
        std::cout << &it << std::endl;
        std::cout << &(*it) << std::endl;
    } */
    for(auto it = numbers.cbegin(); it != numbers.cend(); it++){ // constant begin, constant end
        std::cout << *it << std::endl;
    }

    
    /* auto it = numbers.begin();
    std::cout << *(it + 5) << std::endl; */

        
    return 0;
}