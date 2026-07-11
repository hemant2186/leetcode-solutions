class LFUCache {
    struct Node {
        int value;
        int freq;
        list<int>::iterator it;
    };

    int cap;
    int minFreq;

    unordered_map<int, Node> keyTable;
    unordered_map<int, list<int>> freqTable;

public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (!keyTable.count(key))
            return -1;

        updateFreq(key);
        return keyTable[key].value;
    }

    void put(int key, int value) {
        if (cap == 0) return;

        if (keyTable.count(key)) {
            keyTable[key].value = value;
            updateFreq(key);
            return;
        }

        if (keyTable.size() == cap) {
            int delKey = freqTable[minFreq].back();
            freqTable[minFreq].pop_back();

            if (freqTable[minFreq].empty())
                freqTable.erase(minFreq);

            keyTable.erase(delKey);
        }

        freqTable[1].push_front(key);

        keyTable[key] = {value, 1, freqTable[1].begin()};

        minFreq = 1;
    }

private:
    void updateFreq(int key) {
        int f = keyTable[key].freq;

        freqTable[f].erase(keyTable[key].it);

        if (freqTable[f].empty()) {
            freqTable.erase(f);

            if (minFreq == f)
                minFreq++;
        }

        f++;

        freqTable[f].push_front(key);

        keyTable[key].freq = f;
        keyTable[key].it = freqTable[f].begin();
    }
};