class SnapshotArray {
public:
    map<int,map<int,int>>snapshot;
    int snap_id=0;
    SnapshotArray(int length) {
    
        for(int i=0;i<length;i++)
        {
            map<int,int>pa;
            pa[0]=0;
            snapshot[i]=pa;
        }
    }
    
    void set(int index, int val) {
        snapshot[index][snap_id]=val;
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        auto it=snapshot[index].upper_bound(snap_id);
        it--;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */