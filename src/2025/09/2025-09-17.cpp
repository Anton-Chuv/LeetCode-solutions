#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {

    }

    void changeRating(string food, int newRating) {

    }

    string highestRated(string cuisine) {

    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

 int main() {
    vector<string> foods = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
    vector<string> cuisines = {"korean", "japanese", "japanese", "greek", "japanese", "korean"};
    vector<int> ratings = {9, 12, 8, 15, 14, 7};
    FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
    obj->changeRating("sushi", 16);
    string param_2 = obj->highestRated("japanese");
    cout << param_2 << endl;
    return 0;
}
