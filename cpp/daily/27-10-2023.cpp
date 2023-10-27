
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  int minvalue = 0;
  int minDepth(TreeNode *root)
  {
    if (root == nullptr)
    {
      return 0;
    }
    minvalue = calcMinDepth(1, root);
    return minvalue;
  }
  int calcMinDepth(int count, TreeNode *node)
  {
    if (node->left != nullptr && node->right == nullptr)
      return calcMinDepth(count + 1, node->left);
    if (node->right != nullptr)
    {
      if (node->left != nullptr)
        minvalue = calcMinDepth(count + 1, node->left);
      return calcMinDepth(count + 1, node->right);
    }

    if (minvalue == 0 || count < minvalue)
      return count;

    return minvalue;
  }
};