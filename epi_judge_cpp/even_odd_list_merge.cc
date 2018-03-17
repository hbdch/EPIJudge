
#include "list_node.h"
#include "test_framework/generic_test.h"

shared_ptr<ListNode<int>> EvenOddMerge(const shared_ptr<ListNode<int>>& L) {
  // Implement this placeholder.
  return nullptr;
}

int main(int argc, char* argv[]) {
  // The timeout is set to 15 seconds for each test case.
  // If your program ends with TIMEOUT error, and you want to try longer time
  // limit, you can extend the limit by changing the following line.
  std::chrono::seconds timeout_seconds{15};

  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L"};
  return GenericTestMain(args, timeout_seconds, "even_odd_list_merge.tsv",
                         &EvenOddMerge, DefaultComparator{}, param_names);
}
