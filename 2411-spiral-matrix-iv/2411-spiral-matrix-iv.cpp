/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        
        int t = 0, b = m - 1, l = 0, r = n - 1;
        
        while (head) {
           
            for (int col = l; col <= r && head; ++col) {
                matrix[t][col] = head->val;
                head = head->next;
            }
            t++;
            
          
            for (int row = t; row <= b && head; ++row) {
                matrix[row][r] = head->val;
                head = head->next;
            }
            r--;
           
            for (int col = r; col >= l && head; --col) {
                matrix[b][col] = head->val;
                head = head->next;
            }
            b--;
            
            for (int row = b; row >= t && head; --row) {
                matrix[row][l] = head->val;
                head = head->next;
            }
            l++;
        }
        
        return matrix;
    }
};