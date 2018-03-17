#include "binary_tree_node.h"
#include "test_framework/generic_test.h"

bool IsSymmetric(const unique_ptr<BinaryTreeNode<int>>& tree) {
  // Implement this placeholder.
  return true;
}

int main(int argc, char* argv[]) {
  // The timeout is set to 15 seconds for each test case.
  // If your program ends with TIMEOUT error, and you want to try longer time
  // limit, you can extend the limit by changing the following line.
  std::chrono::seconds timeout_seconds{15};

  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, timeout_seconds, "is_tree_symmetric.tsv",
                         &IsSymmetric, DefaultComparator{}, param_names);
}
