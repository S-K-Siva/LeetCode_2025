class NumberContainers {
public:
    unordered_map<int, set<int>> findSmallestIndex;
    unordered_map<int, int> mapIndex;

    NumberContainers() {}

    void change(int index, int number) {
        if (mapIndex.find(index) != mapIndex.end()) {
            int oldNumber = mapIndex[index];
            if (findSmallestIndex[oldNumber].count(index)) {
                findSmallestIndex[oldNumber].erase(index);
            }
        }
        mapIndex[index] = number;
        findSmallestIndex[number].insert(index);
    }

    int find(int number) {
        if (findSmallestIndex.find(number) == findSmallestIndex.end() || findSmallestIndex[number].empty()) {
            return -1;
        }
        return *findSmallestIndex[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */