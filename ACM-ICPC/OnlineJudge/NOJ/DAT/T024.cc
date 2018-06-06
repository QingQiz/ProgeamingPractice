#include <iostream>
#include <string>

using namespace std;

class binTree {
protected:
    int val, maxval, minval;
    binTree *l, *r;
public:
    binTree(): val(0), l(NULL), r(NULL) {}

    void build() {
        cin >> val;
        maxval = minval = val;
        if (val == -1) return;
        
        l = new binTree;
        l -> build();
        r = new binTree;
        r -> build();

        if (l -> val != -1) maxval = max(maxval, r -> maxval);
        if (r -> val != -1) minval = min(minval, l -> minval);
    }

    bool suitable() {
        if (val == -1) return true;
        if (l) if (!(*l).suitable()) return false;
        if (r) if (!(*r).suitable()) return false;
        if (l -> val != -1) if (val < (*l).minval) return false;
        if (r -> val != -1) if (val > (*r).maxval) return false;
        return true;
    }
};

int main() {
    binTree t;
    t.build();
    if (t.suitable()) puts("yes");
    else puts("no");
}
