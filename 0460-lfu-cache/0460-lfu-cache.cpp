class LFUCache {
public:
    int capacity, minFreq;

    unordered_map<int, pair<int, int>> keyMap;
    unordered_map<int, list<int>> freqMap;
    unordered_map<int, list<int>::iterator> posMap;

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    void updateFreq(int key) {
        int freq = keyMap[key].second;

        freqMap[freq].erase(posMap[key]);

        if (freqMap[freq].empty()) {
            freqMap.erase(freq);

            if (minFreq == freq)
                minFreq++;
        }

        keyMap[key].second++;
        int newFreq = keyMap[key].second;

        freqMap[newFreq].push_front(key);
        posMap[key] = freqMap[newFreq].begin();
    }

    int get(int key) {
        if (keyMap.find(key) == keyMap.end())
            return -1;

        int value = keyMap[key].first;
        updateFreq(key);

        return value;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        if (keyMap.find(key) != keyMap.end()) {
            keyMap[key].first = value;
            updateFreq(key);
            return;
        }

        if (keyMap.size() == capacity) {
            int keyToRemove = freqMap[minFreq].back();

            freqMap[minFreq].pop_back();

            if (freqMap[minFreq].empty())
                freqMap.erase(minFreq);

            keyMap.erase(keyToRemove);
            posMap.erase(keyToRemove);
        }

        keyMap[key] = {value, 1};
        freqMap[1].push_front(key);
        posMap[key] = freqMap[1].begin();

        minFreq = 1;
    }
};