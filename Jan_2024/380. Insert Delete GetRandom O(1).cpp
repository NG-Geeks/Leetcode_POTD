Question :: 380. Insert Delete GetRandom O(1)

Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
You must implement the functions of the class such that each function works in average O(1) time complexity.



Solution::
Complexity
Time complexity:
    O(N)
Space complexity:
    O(N)
Code
#pragma gcc optimize("03")
auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class RandomizedSet {
    unordered_set<int>s; // to store the integers
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(s.find(val)== s.end()){ // check if it exist's in our set
        s.insert(val); // val is not present so insert in set
        return 1; // return true after 
        }
        else return 0; // if present then return false 
    }
    
    bool remove(int val) {
        if(s.find(val)!=s.end()){
            s.erase(val);
            return 1;
        }
        else return 0; 
        
    }
    
    int getRandom() {
        if(s.size()==0)return 0;
        return  *next(s.begin(),rand()%s.size()); // return random integer from set
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */