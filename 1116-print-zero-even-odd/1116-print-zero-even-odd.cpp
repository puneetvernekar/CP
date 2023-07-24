class ZeroEvenOdd {
private:
    int n;
    int turn;
    int i;
    mutex m;
    condition_variable cv;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        turn=0;
        this->i=1;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while(i<=n)
        {
            unique_lock<mutex>lock(m);
            while(i<=n && turn!=0)
                cv.wait(lock);
            if(i>n)
                break;
            printNumber(0);
            if(i%2==0)
                turn=1;
            else
                turn=2;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while(i<=n)
        {   unique_lock<mutex>lock(m);
            while(i<=n && turn!=1)
                cv.wait(lock);
            if(i>n)
                break;
            printNumber(i);
            turn=0;
            i++;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        while(i<=n)
        {   unique_lock<mutex>lock(m);
            while(i<=n && turn!=2)
                cv.wait(lock);
            if(i>n)
                break;
            printNumber(i);
            turn=0;
            i++;
            cv.notify_all();
        }
    }
};