#include <iostream>
#include <string>
#include <stack>
#include "tree_printer.hpp"

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
};


int sum(TreeNode *t) {
    if (t) 
        return t->data + sum(t->left) + sum(t->right);
    else
        return 0;
}


int sum_nonrecursive(TreeNode *t) {
    std::stack<TreeNode *> stack;
    stack.push(t);
    int sum = 0;
    while (!stack.empty()) {
        TreeNode *cursor = stack.top();
        stack.pop();
        if (cursor) {
            sum += cursor->data;  // Add in this node
            stack.push(cursor->left);
            stack.push(cursor->right);
        }
    }
    return sum;
}

void print(TreeNode *t) {
    print_tree(t, nullptr, false);
}

void free_tree(TreeNode *t) {
    if (t) {
        free_tree(t->left);
        free_tree(t->right);
        delete t;
    }
}

int main() {
    // Build a tree by hand
    TreeNode *tree = new TreeNode{
                        10, 
                        new TreeNode{
                             13,
                             new TreeNode{
                                 41,
                                 new TreeNode{
                                    5,
                                     nullptr, 
                                     nullptr
                                 },
                                 nullptr
                             },
                             new TreeNode{
                                  60,
                                  nullptr,
                                  new TreeNode{
                                     11,
                                     new TreeNode{
                                         75,
                                         nullptr,
                                         nullptr
                                     },
                                     nullptr
                                  }
                             }
                          },
                          new TreeNode{
                              12,
                              new TreeNode{
                                 2,
                                 nullptr,
                                 nullptr
                              },
                              nullptr
                          }
                };
    print(tree);
    std::cout << "Recursive sum   : " << sum(tree) << '\n';
    std::cout << "Nonrecursive sum: " << sum_nonrecursive(tree) << '\n';
    free_tree(tree);
     
}
