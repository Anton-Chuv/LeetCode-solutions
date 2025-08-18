#include <iostream>

using namespace std;

class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<int> v = cards;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (j == i) continue;
                for (int k = 0; k < 4; k++) {
                    if (k == i || k == j) continue;
                    for (int l = 0; l < 4; l++) {
                        if (l == i || l == j || l == k) continue;
                        v = {cards[i], cards[j], cards[k], cards[l]};
                        cout << v[0] << v[1] << v[2] << v[3] << endl << endl;
                        if (check(v))
                            return true;
                    }
                }
            }
        }
        return false;
    }
private:
    bool check(vector<int>& cards) {
        double v[4];
        for (int i = 0; i < 4; i++)
            v[i] = static_cast<double>(cards[i]);

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (j == i) continue;
                for (int k1 = 0; k1 < 4; k1++) // + - * /
                    for (int k2 = 0; k2 < 4; k2++) // + - * /
                        for (int k3 = 0; k3 < 4; k3++) { // + - * /
                            int k[3] = {k1, k2, k3};
                            int order[2] = {i, j};
                            double x = this->calcexpr(v, k, order);
                            cout << x << " " << k[0] << " " << k[1] << " " << k[2] << " " << order[0] << " " << order[1] << endl;
                            if (x >= 24.0 - 0.001 && x <= 24.0 + 0.001)
                                return true;

                        }
            }
        }

        return false;
    }
    double calcexpr(double v[4], int oper[3], int order[2]) {
        double out;
        switch (order[0]) {
            case 0:
            switch (order[1]) {
                case 1:
                switch (oper[0]) {
                    case 0:
                    switch (oper[1]) {
                        case 0:
                        switch (oper[2]) {
                            case 0: out = ((v[0] + v[1]) + v[2]) + v[3]; break;
                            case 1: out = ((v[0] + v[1]) + v[2]) - v[3]; break;
                            case 2: out = ((v[0] + v[1]) + v[2]) * v[3]; break;
                            case 3: out = ((v[0] + v[1]) + v[2]) / v[3]; break;
                        }; break;
                        case 1:
                        switch (oper[2]) {
                            case 0: out = ((v[0] + v[1]) - v[2]) + v[3]; break;
                            case 1: out = ((v[0] + v[1]) - v[2]) - v[3]; break;
                            case 2: out = ((v[0] + v[1]) - v[2]) * v[3]; break;
                            case 3: out = ((v[0] + v[1]) - v[2]) / v[3]; break;
                        }; break;
                        case 2:
                        switch (oper[2]) {
                            case 0: out = ((v[0] + v[1]) * v[2]) + v[3]; break;
                            case 1: out = ((v[0] + v[1]) * v[2]) - v[3]; break;
                            case 2: out = ((v[0] + v[1]) * v[2]) * v[3]; break;
                            case 3: out = ((v[0] + v[1]) * v[2]) / v[3]; break;
                        }; break;
                        case 3:
                        switch (oper[2]) {
                            case 0: out = ((v[0] + v[1]) / v[2]) + v[3]; break;
                            case 1: out = ((v[0] + v[1]) / v[2]) - v[3]; break;
                            case 2: out = ((v[0] + v[1]) / v[2]) * v[3]; break;
                            case 3: out = ((v[0] + v[1]) / v[2]) / v[3]; break;
                        }; break;
                    };break;
                    case 1:
                    switch (oper[1]) {
                        case 0:
                        switch (oper[2]) {
                            case 0: out = ((v[0] - v[1]) + v[2]) + v[3]; break;
                            case 1: out = ((v[0] - v[1]) + v[2]) - v[3]; break;
                            case 2: out = ((v[0] - v[1]) + v[2]) * v[3]; break;
                            case 3: out = ((v[0] - v[1]) + v[2]) / v[3]; break;
                        }; break;
                        case 1:
                        switch (oper[2]) {
                            case 0: out = ((v[0] - v[1]) - v[2]) + v[3]; break;
                            case 1: out = ((v[0] - v[1]) - v[2]) - v[3]; break;
                            case 2: out = ((v[0] - v[1]) - v[2]) * v[3]; break;
                            case 3: out = ((v[0] - v[1]) - v[2]) / v[3]; break;
                        }; break;
                        case 2:
                        switch (oper[2]) {
                            case 0: out = ((v[0] - v[1]) * v[2]) + v[3]; break;
                            case 1: out = ((v[0] - v[1]) * v[2]) - v[3]; break;
                            case 2: out = ((v[0] - v[1]) * v[2]) * v[3]; break;
                            case 3: out = ((v[0] - v[1]) * v[2]) / v[3]; break;
                        }; break;
                        case 3:
                        switch (oper[2]) {
                            case 0: out = ((v[0] - v[1]) / v[2]) + v[3]; break;
                            case 1: out = ((v[0] - v[1]) / v[2]) - v[3]; break;
                            case 2: out = ((v[0] - v[1]) / v[2]) * v[3]; break;
                            case 3: out = ((v[0] - v[1]) / v[2]) / v[3]; break;
                        }; break;
                    };break;
                    case 2:
                    switch (oper[1]) {
                        case 0:
                        switch (oper[2]) {
                            case 0: out = ((v[0] * v[1]) + v[2]) + v[3]; break;
                            case 1: out = ((v[0] * v[1]) + v[2]) - v[3]; break;
                            case 2: out = ((v[0] * v[1]) + v[2]) * v[3]; break;
                            case 3: out = ((v[0] * v[1]) + v[2]) / v[3]; break;
                        }; break;
                        case 1:
                        switch (oper[2]) {
                            case 0: out = ((v[0] * v[1]) - v[2]) + v[3]; break;
                            case 1: out = ((v[0] * v[1]) - v[2]) - v[3]; break;
                            case 2: out = ((v[0] * v[1]) - v[2]) * v[3]; break;
                            case 3: out = ((v[0] * v[1]) - v[2]) / v[3]; break;
                        }; break;
                        case 2:
                        switch (oper[2]) {
                            case 0: out = ((v[0] * v[1]) * v[2]) + v[3]; break;
                            case 1: out = ((v[0] * v[1]) * v[2]) - v[3]; break;
                            case 2: out = ((v[0] * v[1]) * v[2]) * v[3]; break;
                            case 3: out = ((v[0] * v[1]) * v[2]) / v[3]; break;
                        }; break;
                        case 3:
                        switch (oper[2]) {
                            case 0: out = ((v[0] * v[1]) / v[2]) + v[3]; break;
                            case 1: out = ((v[0] * v[1]) / v[2]) - v[3]; break;
                            case 2: out = ((v[0] * v[1]) / v[2]) * v[3]; break;
                            case 3: out = ((v[0] * v[1]) / v[2]) / v[3]; break;
                        }; break;
                    };break;
                    case 3:
                    switch (oper[1]) {
                        case 0:
                        switch (oper[2]) {
                            case 0: out = ((v[0] / v[1]) + v[2]) + v[3]; break;
                            case 1: out = ((v[0] / v[1]) + v[2]) - v[3]; break;
                            case 2: out = ((v[0] / v[1]) + v[2]) * v[3]; break;
                            case 3: out = ((v[0] / v[1]) + v[2]) / v[3]; break;
                        }; break;
                        case 1:
                        switch (oper[2]) {
                            case 0: out = ((v[0] / v[1]) - v[2]) + v[3]; break;
                            case 1: out = ((v[0] / v[1]) - v[2]) - v[3]; break;
                            case 2: out = ((v[0] / v[1]) - v[2]) * v[3]; break;
                            case 3: out = ((v[0] / v[1]) - v[2]) / v[3]; break;
                        }; break;
                        case 2:
                        switch (oper[2]) {
                            case 0: out = ((v[0] / v[1]) * v[2]) + v[3]; break;
                            case 1: out = ((v[0] / v[1]) * v[2]) - v[3]; break;
                            case 2: out = ((v[0] / v[1]) * v[2]) * v[3]; break;
                            case 3: out = ((v[0] / v[1]) * v[2]) / v[3]; break;
                        }; break;
                        case 3:
                        switch (oper[2]) {
                            case 0: out = ((v[0] / v[1]) / v[2]) + v[3]; break;
                            case 1: out = ((v[0] / v[1]) / v[2]) - v[3]; break;
                            case 2: out = ((v[0] / v[1]) / v[2]) * v[3]; break;
                            case 3: out = ((v[0] / v[1]) / v[2]) / v[3]; break;
                        }; break;
                    };break;
                };break;
                case 2:
                switch (oper[0]) {
                    case 0:
                    switch (oper[1]) {
                        case 0:
                        switch (oper[2]) {
                            case 0: out = (v[0] + v[1]) + (v[2] + v[3]); break;
                            case 1: out = (v[0] + v[1]) + (v[2] - v[3]); break;
                            case 2: out = (v[0] + v[1]) + (v[2] * v[3]); break;
                            case 3: out = (v[0] + v[1]) + (v[2] / v[3]); break;
                        }; break;
                        case 1:
                        switch (oper[2]) {
                            case 0: out = (v[0] + v[1]) - (v[2] + v[3]); break;
                            case 1: out = (v[0] + v[1]) - (v[2] - v[3]); break;
                            case 2: out = (v[0] + v[1]) - (v[2] * v[3]); break;
                            case 3: out = (v[0] + v[1]) - (v[2] / v[3]); break;
                        }; break;
                        case 2:
                        switch (oper[2]) {
                            case 0: out = (v[0] + v[1]) * (v[2] + v[3]); break;
                            case 1: out = (v[0] + v[1]) * (v[2] - v[3]); break;
                            case 2: out = (v[0] + v[1]) * (v[2] * v[3]); break;
                            case 3: out = (v[0] + v[1]) * (v[2] / v[3]); break;
                        }; break;
                        case 3:
                        switch (oper[2]) {
                            case 0: out = (v[0] + v[1]) / (v[2] + v[3]); break;
                            case 1: out = (v[0] + v[1]) / (v[2] - v[3]); break;
                            case 2: out = (v[0] + v[1]) / (v[2] * v[3]); break;
                            case 3: out = (v[0] + v[1]) / (v[2] / v[3]); break;
                        }; break;
                    };break;
                    case 1:
                    switch (oper[1]) {
                        case 0:
                        switch (oper[2]) {
                            case 0: out = (v[0] - v[1]) + (v[2] + v[3]); break;
                            case 1: out = (v[0] - v[1]) + (v[2] - v[3]); break;
                            case 2: out = (v[0] - v[1]) + (v[2] * v[3]); break;
                            case 3: out = (v[0] - v[1]) + (v[2] / v[3]); break;
                        }; break;
                        case 1:
                        switch (oper[2]) {
                            case 0: out = (v[0] - v[1]) - (v[2] + v[3]); break;
                            case 1: out = (v[0] - v[1]) - (v[2] - v[3]); break;
                            case 2: out = (v[0] - v[1]) - (v[2] * v[3]); break;
                            case 3: out = (v[0] - v[1]) - (v[2] / v[3]); break;
                        }; break;
                        case 2:
                        switch (oper[2]) {
                            case 0: out = (v[0] - v[1]) * (v[2] + v[3]); break;
                            case 1: out = (v[0] - v[1]) * (v[2] - v[3]); break;
                            case 2: out = (v[0] - v[1]) * (v[2] * v[3]); break;
                            case 3: out = (v[0] - v[1]) * (v[2] / v[3]); break;
                        }; break;
                        case 3:
                        switch (oper[2]) {
                            case 0: out = (v[0] - v[1]) / (v[2] + v[3]); break;
                            case 1: out = (v[0] - v[1]) / (v[2] - v[3]); break;
                            case 2: out = (v[0] - v[1]) / (v[2] * v[3]); break;
                            case 3: out = (v[0] - v[1]) / (v[2] / v[3]); break;
                        }; break;
                    };break;
                    case 2:
                    switch (oper[1]) {
                        case 0:
                        switch (oper[2]) {
                            case 0: out = (v[0] * v[1]) + (v[2] + v[3]); break;
                            case 1: out = (v[0] * v[1]) + (v[2] - v[3]); break;
                            case 2: out = (v[0] * v[1]) + (v[2] * v[3]); break;
                            case 3: out = (v[0] * v[1]) + (v[2] / v[3]); break;
                        }; break;
                        case 1:
                        switch (oper[2]) {
                            case 0: out = (v[0] * v[1]) - (v[2] + v[3]); break;
                            case 1: out = (v[0] * v[1]) - (v[2] - v[3]); break;
                            case 2: out = (v[0] * v[1]) - (v[2] * v[3]); break;
                            case 3: out = (v[0] * v[1]) - (v[2] / v[3]); break;
                        }; break;
                        case 2:
                        switch (oper[2]) {
                            case 0: out = (v[0] * v[1]) * (v[2] + v[3]); break;
                            case 1: out = (v[0] * v[1]) * (v[2] - v[3]); break;
                            case 2: out = (v[0] * v[1]) * (v[2] * v[3]); break;
                            case 3: out = (v[0] * v[1]) * (v[2] / v[3]); break;
                        }; break;
                        case 3:
                        switch (oper[2]) {
                            case 0: out = (v[0] * v[1]) / (v[2] + v[3]); break;
                            case 1: out = (v[0] * v[1]) / (v[2] - v[3]); break;
                            case 2: out = (v[0] * v[1]) / (v[2] * v[3]); break;
                            case 3: out = (v[0] * v[1]) / (v[2] / v[3]); break;
                        }; break;
                    };break;
                    case 3:
                    switch (oper[1]) {
                        case 0:
                        switch (oper[2]) {
                            case 0: out = (v[0] / v[1]) + (v[2] + v[3]); break;
                            case 1: out = (v[0] / v[1]) + (v[2] - v[3]); break;
                            case 2: out = (v[0] / v[1]) + (v[2] * v[3]); break;
                            case 3: out = (v[0] / v[1]) + (v[2] / v[3]); break;
                        }; break;
                        case 1:
                        switch (oper[2]) {
                            case 0: out = (v[0] / v[1]) - (v[2] + v[3]); break;
                            case 1: out = (v[0] / v[1]) - (v[2] - v[3]); break;
                            case 2: out = (v[0] / v[1]) - (v[2] * v[3]); break;
                            case 3: out = (v[0] / v[1]) - (v[2] / v[3]); break;
                        }; break;
                        case 2:
                        switch (oper[2]) {
                            case 0: out = (v[0] / v[1]) * (v[2] + v[3]); break;
                            case 1: out = (v[0] / v[1]) * (v[2] - v[3]); break;
                            case 2: out = (v[0] / v[1]) * (v[2] * v[3]); break;
                            case 3: out = (v[0] / v[1]) * (v[2] / v[3]); break;
                        }; break;
                        case 3:
                        switch (oper[2]) {
                            case 0: out = (v[0] / v[1]) / (v[2] + v[3]); break;
                            case 1: out = (v[0] / v[1]) / (v[2] - v[3]); break;
                            case 2: out = (v[0] / v[1]) / (v[2] * v[3]); break;
                            case 3: out = (v[0] / v[1]) / (v[2] / v[3]); break;
                        }; break;
                    };break;
                };break;
            };break;
            case 1:
            switch (order[1]) {
                case 0:
                switch (oper[0]) {
                    case 0:
                    switch (oper[1]) {
                        case 0:
                        switch (oper[2]) {
                            case 0: out = (v[0] + (v[1] + v[2])) + v[3]; break;
                            case 1: out = (v[0] + (v[1] + v[2])) - v[3]; break;
                            case 2: out = (v[0] + (v[1] + v[2])) * v[3]; break;
                            case 3: out = (v[0] + (v[1] + v[2])) / v[3]; break;
                        }; break;
                        case 1:
                        switch (oper[2]) {
                            case 0: out = (v[0] + (v[1] - v[2])) + v[3]; break;
                            case 1: out = (v[0] + (v[1] - v[2])) - v[3]; break;
                            case 2: out = (v[0] + (v[1] - v[2])) * v[3]; break;
                            case 3: out = (v[0] + (v[1] - v[2])) / v[3]; break;
                        }; break;
                        case 2:
                        switch (oper[2]) {
                            case 0: out = (v[0] + (v[1] * v[2])) + v[3]; break;
                            case 1: out = (v[0] + (v[1] * v[2])) - v[3]; break;
                            case 2: out = (v[0] + (v[1] * v[2])) * v[3]; break;
                            case 3: out = (v[0] + (v[1] * v[2])) / v[3]; break;
                        }; break;
                        case 3:
                        switch (oper[2]) {
                            case 0: out = (v[0] + (v[1] / v[2])) + v[3]; break;
                            case 1: out = (v[0] + (v[1] / v[2])) - v[3]; break;
                            case 2: out = (v[0] + (v[1] / v[2])) * v[3]; break;
                            case 3: out = (v[0] + (v[1] / v[2])) / v[3]; break;
                        }; break;
                    };break;
                    case 1:
                    switch (oper[1]) {
                        case 0:
                        switch (oper[2]) {
                            case 0: out = (v[0] - (v[1] + v[2])) + v[3]; break;
                            case 1: out = (v[0] - (v[1] + v[2])) - v[3]; break;
                            case 2: out = (v[0] - (v[1] + v[2])) * v[3]; break;
                            case 3: out = (v[0] - (v[1] + v[2])) / v[3]; break;
                        }; break;
                        case 1:
                        switch (oper[2]) {
                            case 0: out = (v[0] - (v[1] - v[2])) + v[3]; break;
                            case 1: out = (v[0] - (v[1] - v[2])) - v[3]; break;
                            case 2: out = (v[0] - (v[1] - v[2])) * v[3]; break;
                            case 3: out = (v[0] - (v[1] - v[2])) / v[3]; break;
                        }; break;
                        case 2:
                        switch (oper[2]) {
                            case 0: out = (v[0] - (v[1] * v[2])) + v[3]; break;
                            case 1: out = (v[0] - (v[1] * v[2])) - v[3]; break;
                            case 2: out = (v[0] - (v[1] * v[2])) * v[3]; break;
                            case 3: out = (v[0] - (v[1] * v[2])) / v[3]; break;
                        }; break;
                        case 3:
                        switch (oper[2]) {
                            case 0: out = (v[0] - (v[1] / v[2])) + v[3]; break;
                            case 1: out = (v[0] - (v[1] / v[2])) - v[3]; break;
                            case 2: out = (v[0] - (v[1] / v[2])) * v[3]; break;
                            case 3: out = (v[0] - (v[1] / v[2])) / v[3]; break;
                        }; break;
                    };break;
                    case 2:
                    switch (oper[1]) {
                        case 0:
                        switch (oper[2]) {
                            case 0: out = (v[0] * (v[1] + v[2])) + v[3]; break;
                            case 1: out = (v[0] * (v[1] + v[2])) - v[3]; break;
                            case 2: out = (v[0] * (v[1] + v[2])) * v[3]; break;
                            case 3: out = (v[0] * (v[1] + v[2])) / v[3]; break;
                        }; break;
                        case 1:
                        switch (oper[2]) {
                            case 0: out = (v[0] * (v[1] - v[2])) + v[3]; break;
                            case 1: out = (v[0] * (v[1] - v[2])) - v[3]; break;
                            case 2: out = (v[0] * (v[1] - v[2])) * v[3]; break;
                            case 3: out = (v[0] * (v[1] - v[2])) / v[3]; break;
                        }; break;
                        case 2:
                        switch (oper[2]) {
                            case 0: out = (v[0] * (v[1] * v[2])) + v[3]; break;
                            case 1: out = (v[0] * (v[1] * v[2])) - v[3]; break;
                            case 2: out = (v[0] * (v[1] * v[2])) * v[3]; break;
                            case 3: out = (v[0] * (v[1] * v[2])) / v[3]; break;
                        }; break;
                        case 3:
                        switch (oper[2]) {
                            case 0: out = (v[0] * (v[1] / v[2])) + v[3]; break;
                            case 1: out = (v[0] * (v[1] / v[2])) - v[3]; break;
                            case 2: out = (v[0] * (v[1] / v[2])) * v[3]; break;
                            case 3: out = (v[0] * (v[1] / v[2])) / v[3]; break;
                        }; break;
                    };break;
                    case 3:
                    switch (oper[1]) {
                        case 0:
                        switch (oper[2]) {
                            case 0: out = (v[0] / (v[1] + v[2])) + v[3]; break;
                            case 1: out = (v[0] / (v[1] + v[2])) - v[3]; break;
                            case 2: out = (v[0] / (v[1] + v[2])) * v[3]; break;
                            case 3: out = (v[0] / (v[1] + v[2])) / v[3]; break;
                        }; break;
                        case 1:
                        switch (oper[2]) {
                            case 0: out = (v[0] / (v[1] - v[2])) + v[3]; break;
                            case 1: out = (v[0] / (v[1] - v[2])) - v[3]; break;
                            case 2: out = (v[0] / (v[1] - v[2])) * v[3]; break;
                            case 3: out = (v[0] / (v[1] - v[2])) / v[3]; break;
                        }; break;
                        case 2:
                        switch (oper[2]) {
                            case 0: out = (v[0] / (v[1] * v[2])) + v[3]; break;
                            case 1: out = (v[0] / (v[1] * v[2])) - v[3]; break;
                            case 2: out = (v[0] / (v[1] * v[2])) * v[3]; break;
                            case 3: out = (v[0] / (v[1] * v[2])) / v[3]; break;
                        }; break;
                        case 3:
                        switch (oper[2]) {
                            case 0: out = (v[0] / (v[1] / v[2])) + v[3]; break;
                            case 1: out = (v[0] / (v[1] / v[2])) - v[3]; break;
                            case 2: out = (v[0] / (v[1] / v[2])) * v[3]; break;
                            case 3: out = (v[0] / (v[1] / v[2])) / v[3]; break;
                        }; break;
                    };break;
                }break;
                case 2:
                switch (oper[0]) {
                    case 0:
                    switch (oper[1]) {
                        case 0:
                        switch (oper[2]) {
                            case 0: out = v[0] + ((v[1] + v[2]) + v[3]); break;
                            case 1: out = v[0] + ((v[1] + v[2]) - v[3]); break;
                            case 2: out = v[0] + ((v[1] + v[2]) * v[3]); break;
                            case 3: out = v[0] + ((v[1] + v[2]) / v[3]); break;
                        }; break;
                        case 1:
                        switch (oper[2]) {
                            case 0: out = v[0] + ((v[1] - v[2]) + v[3]); break;
                            case 1: out = v[0] + ((v[1] - v[2]) - v[3]); break;
                            case 2: out = v[0] + ((v[1] - v[2]) * v[3]); break;
                            case 3: out = v[0] + ((v[1] - v[2]) / v[3]); break;
                        }; break;
                        case 2:
                        switch (oper[2]) {
                            case 0: out = v[0] + ((v[1] * v[2]) + v[3]); break;
                            case 1: out = v[0] + ((v[1] * v[2]) - v[3]); break;
                            case 2: out = v[0] + ((v[1] * v[2]) * v[3]); break;
                            case 3: out = v[0] + ((v[1] * v[2]) / v[3]); break;
                        }; break;
                        case 3:
                        switch (oper[2]) {
                            case 0: out = v[0] + ((v[1] / v[2]) + v[3]); break;
                            case 1: out = v[0] + ((v[1] / v[2]) - v[3]); break;
                            case 2: out = v[0] + ((v[1] / v[2]) * v[3]); break;
                            case 3: out = v[0] + ((v[1] / v[2]) / v[3]); break;
                        }; break;
                    };break;
                    case 1:
                    switch (oper[1]) {
                        case 0:
                        switch (oper[2]) {
                            case 0: out = v[0] - ((v[1] + v[2]) + v[3]); break;
                            case 1: out = v[0] - ((v[1] + v[2]) - v[3]); break;
                            case 2: out = v[0] - ((v[1] + v[2]) * v[3]); break;
                            case 3: out = v[0] - ((v[1] + v[2]) / v[3]); break;
                        }; break;
                        case 1:
                        switch (oper[2]) {
                            case 0: out = v[0] - ((v[1] - v[2]) + v[3]); break;
                            case 1: out = v[0] - ((v[1] - v[2]) - v[3]); break;
                            case 2: out = v[0] - ((v[1] - v[2]) * v[3]); break;
                            case 3: out = v[0] - ((v[1] - v[2]) / v[3]); break;
                        }; break;
                        case 2:
                        switch (oper[2]) {
                            case 0: out = v[0] - ((v[1] * v[2]) + v[3]); break;
                            case 1: out = v[0] - ((v[1] * v[2]) - v[3]); break;
                            case 2: out = v[0] - ((v[1] * v[2]) * v[3]); break;
                            case 3: out = v[0] - ((v[1] * v[2]) / v[3]); break;
                        }; break;
                        case 3:
                        switch (oper[2]) {
                            case 0: out = v[0] - ((v[1] / v[2]) + v[3]); break;
                            case 1: out = v[0] - ((v[1] / v[2]) - v[3]); break;
                            case 2: out = v[0] - ((v[1] / v[2]) * v[3]); break;
                            case 3: out = v[0] - ((v[1] / v[2]) / v[3]); break;
                        }; break;
                    };break;
                    case 2:
                    switch (oper[1]) {
                        case 0:
                        switch (oper[2]) {
                            case 0: out = v[0] * ((v[1] + v[2]) + v[3]); break;
                            case 1: out = v[0] * ((v[1] + v[2]) - v[3]); break;
                            case 2: out = v[0] * ((v[1] + v[2]) * v[3]); break;
                            case 3: out = v[0] * ((v[1] + v[2]) / v[3]); break;
                        }; break;
                        case 1:
                        switch (oper[2]) {
                            case 0: out = v[0] * ((v[1] - v[2]) + v[3]); break;
                            case 1: out = v[0] * ((v[1] - v[2]) - v[3]); break;
                            case 2: out = v[0] * ((v[1] - v[2]) * v[3]); break;
                            case 3: out = v[0] * ((v[1] - v[2]) / v[3]); break;
                        }; break;
                        case 2:
                        switch (oper[2]) {
                            case 0: out = v[0] * ((v[1] * v[2]) + v[3]); break;
                            case 1: out = v[0] * ((v[1] * v[2]) - v[3]); break;
                            case 2: out = v[0] * ((v[1] * v[2]) * v[3]); break;
                            case 3: out = v[0] * ((v[1] * v[2]) / v[3]); break;
                        }; break;
                        case 3:
                        switch (oper[2]) {
                            case 0: out = v[0] * ((v[1] / v[2]) + v[3]); break;
                            case 1: out = v[0] * ((v[1] / v[2]) - v[3]); break;
                            case 2: out = v[0] * ((v[1] / v[2]) * v[3]); break;
                            case 3: out = v[0] * ((v[1] / v[2]) / v[3]); break;
                        }; break;
                    };break;
                    case 3:
                    switch (oper[1]) {
                        case 0:
                        switch (oper[2]) {
                            case 0: out = v[0] / ((v[1] + v[2]) + v[3]); break;
                            case 1: out = v[0] / ((v[1] + v[2]) - v[3]); break;
                            case 2: out = v[0] / ((v[1] + v[2]) * v[3]); break;
                            case 3: out = v[0] / ((v[1] + v[2]) / v[3]); break;
                        }; break;
                        case 1:
                        switch (oper[2]) {
                            case 0: out = v[0] / ((v[1] - v[2]) + v[3]); break;
                            case 1: out = v[0] / ((v[1] - v[2]) - v[3]); break;
                            case 2: out = v[0] / ((v[1] - v[2]) * v[3]); break;
                            case 3: out = v[0] / ((v[1] - v[2]) / v[3]); break;
                        }; break;
                        case 2:
                        switch (oper[2]) {
                            case 0: out = v[0] / ((v[1] * v[2]) + v[3]); break;
                            case 1: out = v[0] / ((v[1] * v[2]) - v[3]); break;
                            case 2: out = v[0] / ((v[1] * v[2]) * v[3]); break;
                            case 3: out = v[0] / ((v[1] * v[2]) / v[3]); break;
                        }; break;
                        case 3:
                        switch (oper[2]) {
                            case 0: out = v[0] / ((v[1] / v[2]) + v[3]); break;
                            case 1: out = v[0] / ((v[1] / v[2]) - v[3]); break;
                            case 2: out = v[0] / ((v[1] / v[2]) * v[3]); break;
                            case 3: out = v[0] / ((v[1] / v[2]) / v[3]); break;
                        }; break;
                    };break;
                };break;
            };break;
            case 2:
            switch (order[1]) {
                case 0:
                switch (oper[0]) {
                    case 0:
                    switch (oper[1]) {
                        case 0:
                        switch (oper[2]) {
                            case 0: out = (v[0] + v[1]) + (v[2] + v[3]); break;
                            case 1: out = (v[0] + v[1]) + (v[2] - v[3]); break;
                            case 2: out = (v[0] + v[1]) + (v[2] * v[3]); break;
                            case 3: out = (v[0] + v[1]) + (v[2] / v[3]); break;
                        }; break;
                        case 1:
                        switch (oper[2]) {
                            case 0: out = (v[0] + v[1]) - (v[2] + v[3]); break;
                            case 1: out = (v[0] + v[1]) - (v[2] - v[3]); break;
                            case 2: out = (v[0] + v[1]) - (v[2] * v[3]); break;
                            case 3: out = (v[0] + v[1]) - (v[2] / v[3]); break;
                        }; break;
                        case 2:
                        switch (oper[2]) {
                            case 0: out = (v[0] + v[1]) * (v[2] + v[3]); break;
                            case 1: out = (v[0] + v[1]) * (v[2] - v[3]); break;
                            case 2: out = (v[0] + v[1]) * (v[2] * v[3]); break;
                            case 3: out = (v[0] + v[1]) * (v[2] / v[3]); break;
                        }; break;
                        case 3:
                        switch (oper[2]) {
                            case 0: out = (v[0] + v[1]) / (v[2] + v[3]); break;
                            case 1: out = (v[0] + v[1]) / (v[2] - v[3]); break;
                            case 2: out = (v[0] + v[1]) / (v[2] * v[3]); break;
                            case 3: out = (v[0] + v[1]) / (v[2] / v[3]); break;
                        }; break;
                    };break;
                    case 1:
                    switch (oper[1]) {
                        case 0:
                        switch (oper[2]) {
                            case 0: out = (v[0] - v[1]) + (v[2] + v[3]); break;
                            case 1: out = (v[0] - v[1]) + (v[2] - v[3]); break;
                            case 2: out = (v[0] - v[1]) + (v[2] * v[3]); break;
                            case 3: out = (v[0] - v[1]) + (v[2] / v[3]); break;
                        }; break;
                        case 1:
                        switch (oper[2]) {
                            case 0: out = (v[0] - v[1]) - (v[2] + v[3]); break;
                            case 1: out = (v[0] - v[1]) - (v[2] - v[3]); break;
                            case 2: out = (v[0] - v[1]) - (v[2] * v[3]); break;
                            case 3: out = (v[0] - v[1]) - (v[2] / v[3]); break;
                        }; break;
                        case 2:
                        switch (oper[2]) {
                            case 0: out = (v[0] - v[1]) * (v[2] + v[3]); break;
                            case 1: out = (v[0] - v[1]) * (v[2] - v[3]); break;
                            case 2: out = (v[0] - v[1]) * (v[2] * v[3]); break;
                            case 3: out = (v[0] - v[1]) * (v[2] / v[3]); break;
                        }; break;
                        case 3:
                        switch (oper[2]) {
                            case 0: out = (v[0] - v[1]) / (v[2] + v[3]); break;
                            case 1: out = (v[0] - v[1]) / (v[2] - v[3]); break;
                            case 2: out = (v[0] - v[1]) / (v[2] * v[3]); break;
                            case 3: out = (v[0] - v[1]) / (v[2] / v[3]); break;
                        }; break;
                    };break;
                    case 2:
                    switch (oper[1]) {
                        case 0:
                        switch (oper[2]) {
                            case 0: out = (v[0] * v[1]) + (v[2] + v[3]); break;
                            case 1: out = (v[0] * v[1]) + (v[2] - v[3]); break;
                            case 2: out = (v[0] * v[1]) + (v[2] * v[3]); break;
                            case 3: out = (v[0] * v[1]) + (v[2] / v[3]); break;
                        }; break;
                        case 1:
                        switch (oper[2]) {
                            case 0: out = (v[0] * v[1]) - (v[2] + v[3]); break;
                            case 1: out = (v[0] * v[1]) - (v[2] - v[3]); break;
                            case 2: out = (v[0] * v[1]) - (v[2] * v[3]); break;
                            case 3: out = (v[0] * v[1]) - (v[2] / v[3]); break;
                        }; break;
                        case 2:
                        switch (oper[2]) {
                            case 0: out = (v[0] * v[1]) * (v[2] + v[3]); break;
                            case 1: out = (v[0] * v[1]) * (v[2] - v[3]); break;
                            case 2: out = (v[0] * v[1]) * (v[2] * v[3]); break;
                            case 3: out = (v[0] * v[1]) * (v[2] / v[3]); break;
                        }; break;
                        case 3:
                        switch (oper[2]) {
                            case 0: out = (v[0] * v[1]) / (v[2] + v[3]); break;
                            case 1: out = (v[0] * v[1]) / (v[2] - v[3]); break;
                            case 2: out = (v[0] * v[1]) / (v[2] * v[3]); break;
                            case 3: out = (v[0] * v[1]) / (v[2] / v[3]); break;
                        }; break;
                    };break;
                    case 3:
                    switch (oper[1]) {
                        case 0:
                        switch (oper[2]) {
                            case 0: out = (v[0] / v[1]) + (v[2] + v[3]); break;
                            case 1: out = (v[0] / v[1]) + (v[2] - v[3]); break;
                            case 2: out = (v[0] / v[1]) + (v[2] * v[3]); break;
                            case 3: out = (v[0] / v[1]) + (v[2] / v[3]); break;
                        }; break;
                        case 1:
                        switch (oper[2]) {
                            case 0: out = (v[0] / v[1]) - (v[2] + v[3]); break;
                            case 1: out = (v[0] / v[1]) - (v[2] - v[3]); break;
                            case 2: out = (v[0] / v[1]) - (v[2] * v[3]); break;
                            case 3: out = (v[0] / v[1]) - (v[2] / v[3]); break;
                        }; break;
                        case 2:
                        switch (oper[2]) {
                            case 0: out = (v[0] / v[1]) * (v[2] + v[3]); break;
                            case 1: out = (v[0] / v[1]) * (v[2] - v[3]); break;
                            case 2: out = (v[0] / v[1]) * (v[2] * v[3]); break;
                            case 3: out = (v[0] / v[1]) * (v[2] / v[3]); break;
                        }; break;
                        case 3:
                        switch (oper[2]) {
                            case 0: out = (v[0] / v[1]) / (v[2] + v[3]); break;
                            case 1: out = (v[0] / v[1]) / (v[2] - v[3]); break;
                            case 2: out = (v[0] / v[1]) / (v[2] * v[3]); break;
                            case 3: out = (v[0] / v[1]) / (v[2] / v[3]); break;
                        }; break;
                    };break;
                };break;
                case 1:
                switch (oper[0]) {
                    case 0:
                    switch (oper[1]) {
                        case 0:
                        switch (oper[2]) {
                            case 0: out = v[0] + (v[1] + (v[2] + v[3])); break;
                            case 1: out = v[0] + (v[1] + (v[2] - v[3])); break;
                            case 2: out = v[0] + (v[1] + (v[2] * v[3])); break;
                            case 3: out = v[0] + (v[1] + (v[2] / v[3])); break;
                        }; break;
                        case 1:
                        switch (oper[2]) {
                            case 0: out = v[0] + (v[1] - (v[2] + v[3])); break;
                            case 1: out = v[0] + (v[1] - (v[2] - v[3])); break;
                            case 2: out = v[0] + (v[1] - (v[2] * v[3])); break;
                            case 3: out = v[0] + (v[1] - (v[2] / v[3])); break;
                        }; break;
                        case 2:
                        switch (oper[2]) {
                            case 0: out = v[0] + (v[1] * (v[2] + v[3])); break;
                            case 1: out = v[0] + (v[1] * (v[2] - v[3])); break;
                            case 2: out = v[0] + (v[1] * (v[2] * v[3])); break;
                            case 3: out = v[0] + (v[1] * (v[2] / v[3])); break;
                        }; break;
                        case 3:
                        switch (oper[2]) {
                            case 0: out = v[0] + (v[1] / (v[2] + v[3])); break;
                            case 1: out = v[0] + (v[1] / (v[2] - v[3])); break;
                            case 2: out = v[0] + (v[1] / (v[2] * v[3])); break;
                            case 3: out = v[0] + (v[1] / (v[2] / v[3])); break;
                        }; break;
                    };break;
                    case 1:
                    switch (oper[1]) {
                        case 0:
                        switch (oper[2]) {
                            case 0: out = v[0] - (v[1] + (v[2] + v[3])); break;
                            case 1: out = v[0] - (v[1] + (v[2] - v[3])); break;
                            case 2: out = v[0] - (v[1] + (v[2] * v[3])); break;
                            case 3: out = v[0] - (v[1] + (v[2] / v[3])); break;
                        }; break;
                        case 1:
                        switch (oper[2]) {
                            case 0: out = v[0] - (v[1] - (v[2] + v[3])); break;
                            case 1: out = v[0] - (v[1] - (v[2] - v[3])); break;
                            case 2: out = v[0] - (v[1] - (v[2] * v[3])); break;
                            case 3: out = v[0] - (v[1] - (v[2] / v[3])); break;
                        }; break;
                        case 2:
                        switch (oper[2]) {
                            case 0: out = v[0] - (v[1] * (v[2] + v[3])); break;
                            case 1: out = v[0] - (v[1] * (v[2] - v[3])); break;
                            case 2: out = v[0] - (v[1] * (v[2] * v[3])); break;
                            case 3: out = v[0] - (v[1] * (v[2] / v[3])); break;
                        }; break;
                        case 3:
                        switch (oper[2]) {
                            case 0: out = v[0] - (v[1] / (v[2] + v[3])); break;
                            case 1: out = v[0] - (v[1] / (v[2] - v[3])); break;
                            case 2: out = v[0] - (v[1] / (v[2] * v[3])); break;
                            case 3: out = v[0] - (v[1] / (v[2] / v[3])); break;
                        }; break;
                    };break;
                    case 2:
                    switch (oper[1]) {
                        case 0:
                        switch (oper[2]) {
                            case 0: out = v[0] * (v[1] + (v[2] + v[3])); break;
                            case 1: out = v[0] * (v[1] + (v[2] - v[3])); break;
                            case 2: out = v[0] * (v[1] + (v[2] * v[3])); break;
                            case 3: out = v[0] * (v[1] + (v[2] / v[3])); break;
                        }; break;
                        case 1:
                        switch (oper[2]) {
                            case 0: out = v[0] * (v[1] - (v[2] + v[3])); break;
                            case 1: out = v[0] * (v[1] - (v[2] - v[3])); break;
                            case 2: out = v[0] * (v[1] - (v[2] * v[3])); break;
                            case 3: out = v[0] * (v[1] - (v[2] / v[3])); break;
                        }; break;
                        case 2:
                        switch (oper[2]) {
                            case 0: out = v[0] * (v[1] * (v[2] + v[3])); break;
                            case 1: out = v[0] * (v[1] * (v[2] - v[3])); break;
                            case 2: out = v[0] * (v[1] * (v[2] * v[3])); break;
                            case 3: out = v[0] * (v[1] * (v[2] / v[3])); break;
                        }; break;
                        case 3:
                        switch (oper[2]) {
                            case 0: out = v[0] * (v[1] / (v[2] + v[3])); break;
                            case 1: out = v[0] * (v[1] / (v[2] - v[3])); break;
                            case 2: out = v[0] * (v[1] / (v[2] * v[3])); break;
                            case 3: out = v[0] * (v[1] / (v[2] / v[3])); break;
                        }; break;
                    };break;
                    case 3:
                    switch (oper[1]) {
                        case 0:
                        switch (oper[2]) {
                            case 0: out = v[0] / (v[1] + (v[2] + v[3])); break;
                            case 1: out = v[0] / (v[1] + (v[2] - v[3])); break;
                            case 2: out = v[0] / (v[1] + (v[2] * v[3])); break;
                            case 3: out = v[0] / (v[1] + (v[2] / v[3])); break;
                        }; break;
                        case 1:
                        switch (oper[2]) {
                            case 0: out = v[0] / (v[1] - (v[2] + v[3])); break;
                            case 1: out = v[0] / (v[1] - (v[2] - v[3])); break;
                            case 2: out = v[0] / (v[1] - (v[2] * v[3])); break;
                            case 3: out = v[0] / (v[1] - (v[2] / v[3])); break;
                        }; break;
                        case 2:
                        switch (oper[2]) {
                            case 0: out = v[0] / (v[1] * (v[2] + v[3])); break;
                            case 1: out = v[0] / (v[1] * (v[2] - v[3])); break;
                            case 2: out = v[0] / (v[1] * (v[2] * v[3])); break;
                            case 3: out = v[0] / (v[1] * (v[2] / v[3])); break;
                        }; break;
                        case 3:
                        switch (oper[2]) {
                            case 0: out = v[0] / (v[1] / (v[2] + v[3])); break;
                            case 1: out = v[0] / (v[1] / (v[2] - v[3])); break;
                            case 2: out = v[0] / (v[1] / (v[2] * v[3])); break;
                            case 3: out = v[0] / (v[1] / (v[2] / v[3])); break;
                        }; break;
                    };break;
                };break;
            };break;
        }
        return out;
    }
};

int main(){
    Solution sol;
    vector<int> cards{24, 0, 0, 0};
    cout << sol.judgePoint24(cards);
    return 0;
}
