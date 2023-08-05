struct Node{
    Node* links[2];

    bool containsBit(int n){
        return links[n] != NULL;
    }

    void put(int n, Node* node){
        links[n] = node; 
    }

    Node* get(int n){
        return links[n];
    }
};

class Trie{
    private:
        Node* root;
    public:
        Trie(){
            root = new Node();
        }

        void insert(int num){
            Node* node = root;
            for(int i = 31;i>=0;i--){
                int bit = (num>>i) & 1;
                if(!node->containsBit(bit)){
                    node->put(bit, new Node());
                }
                node = node->get(bit);
            }
        }

        int getMax(int num){
            Node* node = root;
            int mxXor = 0;
            for(int i=31;i>=0;i--){
                int bit = (num>>i) & 1;
                if(node->containsBit(1-bit)){
                    mxXor = mxXor | (1<<i);
                    node = node->get(1-bit);
                }
                else{
                    node = node->get(bit);
                }
            }
            return mxXor;
        }

};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        int mx = 0;
        for(int i=0;i<nums.size();i++) trie.insert(nums[i]);
        for(int i=0;i<nums.size();i++) mx = max(mx, trie.getMax(nums[i]));
        return mx;
        
    }
};