/*
 * @lc app=leetcode.cn id=641 lang=cpp
 *
 * [641] 设计循环双端队列
 */

// @lc code=start
class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    int maxi;
    vector<int> q;
    MyCircularDeque(int k) {
        maxi = k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (q.size() == maxi) {
            return false;
        }
        q.insert(q.begin(), value);
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (q.size() == maxi) {
            return false;
        }
        q.push_back(value);
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (q.size() == 0) {
            return false;
        }
        q.erase(q.begin());
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (q.size() == 0) {
            return false;
        }
        q.pop_back();
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (q.size() == 0) {
            return -1;
        }
        return q[0];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (q.size() == 0) {
            return -1;
        }
        return q.back();
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        if (q.size() == 0) {
            return true;
        }
        return false;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        if (q.size() == maxi) {
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end

