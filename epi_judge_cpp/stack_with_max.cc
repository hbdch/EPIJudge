#include <stdexcept>

#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/test_utils_serialization_traits.h"

using std::length_error;

class Stack {
 public:
  bool Empty() const {
    // Implement this placeholder.
    return true;
  }

  int Max() const {
    // Implement this placeholder.
    return 0;
  }

  int Pop() {
    // Implement this placeholder.
    return 0;
  }

  void Push(int x) {
    // Implement this placeholder.
    return;
  }
};

struct StackOp {
  std::string op;
  int argument;
};

template <>
struct SerializationTraits<StackOp> : UserSerTraits<StackOp, std::string, int> {
};

void StackTester(const std::vector<StackOp>& ops) {
  try {
    Stack s;
    for (auto& x : ops) {
      if (x.op == "Stack") {
        continue;
      } else if (x.op == "push") {
        s.Push(x.argument);
      } else if (x.op == "pop") {
        int result = s.Pop();
        if (result != x.argument) {
          throw TestFailure("Pop: expected " + std::to_string(x.argument) +
                            ", got " + std::to_string(result));
        }
      } else if (x.op == "max") {
        int result = s.Max();
        if (result != x.argument) {
          throw TestFailure("Max: expected " + std::to_string(x.argument) +
                            ", got " + std::to_string(result));
        }
      } else if (x.op == "empty") {
        int result = s.Empty();
        if (result != x.argument) {
          throw TestFailure("Empty: expected " + std::to_string(x.argument) +
                            ", got " + std::to_string(result));
        }
      } else {
        throw std::runtime_error("Unsupported stack operation: " + x.op);
      }
    }
  } catch (length_error&) {
    throw TestFailure("Unexpected length_error exception");
  }
}

int main(int argc, char* argv[]) {
  // The timeout is set to 15 seconds for each test case.
  // If your program ends with TIMEOUT error, and you want to try longer time
  // limit, you can extend the limit by changing the following line.
  std::chrono::seconds timeout_seconds{15};

  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"ops"};
  return GenericTestMain(args, timeout_seconds, "stack_with_max.tsv",
                         &StackTester, DefaultComparator{}, param_names);
}
