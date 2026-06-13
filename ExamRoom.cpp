class ExamRoom {
private:
    int n;
    set<int> seats;

public:
    ExamRoom(int n) {
        this->n = n;
    }

    int seat() {
        if (seats.empty()) {
            seats.insert(0);
            return 0;
        }

        int dist = *seats.begin();
        int pos = 0;

        auto prev = seats.begin();
        auto curr = next(prev);

        while (curr != seats.end()) {
            int d = (*curr - *prev) / 2;

            if (d > dist) {
                dist = d;
                pos = *prev + d;
            }

            prev = curr;
            ++curr;
        }

        if ((n - 1 - *seats.rbegin()) > dist) {
            pos = n - 1;
        }

        seats.insert(pos);
        return pos;
    }

    void leave(int p) {
        seats.erase(p);
    }
};