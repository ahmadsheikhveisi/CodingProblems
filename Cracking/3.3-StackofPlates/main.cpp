/* COPYRIGHT
 * Imagine a stack of plates. if the stack gets too high, it might topple.
 * Therefore, in real life, we would likely start a new stack when the previous
 * stack exceeds some threshold. implement a data structure SetOfStacks that
 * mimics this. SetOfStacks should be composed of several stacks and should
 * create a new stack onces the previous one exceeds capacity.
 * SetOfStacks.push() and SetOfStacks.pop() should behave identically to a
 * single stack (that is pop should retrun the same values as it would if there
 * were just a single stack).
 *
 * follow up: implement a function popAt(int index) which performs a pop
 * operation on a specific sub-stack.
 *
 *
 * Note: case insensive, ignore white space, ASCII, UTF8
 * Palindrome has an even occurance of all charactors, except
 * it can have only one odd occurance.
 * 00010000 - 1 = 00001111
 * 00101000 - 1 = 00100111
 *
 * count if: count the elements between two iterators that satisfy a
 * condition.
 *
 * string find returns the index and it can be npos
 *
 * Mind the end of string, when searching.
 *
 * 'remove' moves up the elements in the sequence, overwriting the element
 * you wanted removed. (find and move)
 * 'erase' overwrite the elements and resize the sequence.
 * remove-erase idiom: to remove the matching elements from the container.
 * remove is independent of the container while erase depends how the
 * data is stored.
 *
 * inlining the ostream& operator<<(ostream& out, classtemplate) is the best
 * way.
 *
 * structured binding auto [a, b] = std::tuple
 * to use current variables: std::tie(a,b, _) = std::tuple
 *
 * in linked lists, if you can use the size, you can acheive O(1) space
 * complexity. otherwise, recursion gives O(N) space complexity. don't forget
 * the runner approach.
 *
 * to get the coredumps first add "* - core unlimited" to
 * /etc/security/limits.conf
 * change /proc/sys/kernel/core_pattern. | at the
 * begining means core dump is directed to stdout
 * sudo su
 * echo "/var/crash/core-%e-%p-%t" > /proc/sys/kernel/core_pattern
 * or premanently under /etc/sysctl.conf
 * kernel.core_pattern=/tmp/cores/core.%e.%p.%h.%t
 * remember %e truncates the filename to 15 chars
 * then you need a proper launch config
 */

#include <algorithm>
#include <iostream>
#include <list>
#include <memory>
#include <sstream>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "solution.hpp"
#include "stack.hpp"

int main() {
  SetOfStacks<int, 3> mstk;
  mstk.push(1);
  mstk.push(1);
  mstk.push(2);
  mstk.push(0);
  std::cout << mstk;
  std::cout << "pop " << mstk.pop() << '\n';
  std::cout << mstk;
  std::cout << "pop " << mstk.pop() << '\n';
  std::cout << mstk;
  std::cout << "1----\n";
  mstk.push(2);
  mstk.push(0);
  std::cout << mstk;
  std::cout << "2----\n";
  mstk.pushAt(0, 0);
  std::cout << mstk;
  std::cout << "3----\n";
  mstk.pushAt(3, 1);
  std::cout << mstk;
  std::cout << "++++\n";
  mstk.pushAt(4, 1);
  std::cout << mstk;
  std::cout << "++++\n";
  mstk.pushAt(1, 1);
  std::cout << mstk;
  std::cout << "4----\n";
  std::cout << "pop at 1: " << mstk.popAt(1) << '\n';
  // mstk.popAt(1);
  //  mstk.popAt(1);
  std::cout << mstk;
  std::cout << "----\n";
  return 0;
}
