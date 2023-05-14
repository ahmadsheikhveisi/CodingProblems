/* COPYRIGHT
 * Write a program to sort a stack such that the smallest items are on the top.
 * you can use an additional temporary stack, but you may not copy the elements
 * into any other data structure (such as an array). The stack supports the
 * following operations: push, pop, peek, isEmpty().
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
  MyQueue<int> mque;
  mque.push(0);
  mque.push(1);
  mque.push(2);
  std::cout << mque << '\n';
  std::cout << "----\n";
  std::cout << "poped " << mque.pop() << '\n';
  std::cout << mque << '\n';
  std::cout << "----\n";
  mque.push(3);
  std::cout << "poped " << mque.pop() << '\n';
  std::cout << mque << '\n';
  std::cout << "----\n";
  return 0;
}
