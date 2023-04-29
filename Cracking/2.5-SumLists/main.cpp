/* COPYRIGHT
 * You have two numbers represented by a linked list. where each node contains a
 * single digit.The digits are stored in a reverse order, such that the 1's
 * digit is at the head of the list. Write a function that adds the two numbers
 * and returns the sum as a linked list.
 * Example:
 * Input: 7->1->6 + 5->9->2 (617+295)
 * Output: 2->1->9
 *
 * Follow Up:
 * Suppose the digits are stored in forward order. Repeat the problem.
 * Input: 6->1->7 + 2->9->5 (617+295)
 * Output: 9->1->2
 *
 *
 * Note: case insensive, ignore white space.
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
 */

#include <algorithm>
#include <iostream>
#include <list>
#include <sstream>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "singly_linked_list.hpp"

template <typename T>
void printCon(const T& vec) {
  for (const auto& num : vec) {
    std::cout << num << ' ';
  }
  std::cout << '\n';
}

template <typename T>
std::tuple<T, bool> calculateSumAndCarry(T sum, bool carry) {
  if (carry) {
    ++sum;
    carry = false;
  }
  if (sum >= 10) {
    carry = true;
    sum = sum - 10;
  }
  return {sum, carry};
}

template <typename T>
LinkedList<T> SumListRev(LinkedList<T> const& lst1, LinkedList<T> const& lst2) {
  LinkedList<T> res;
  auto p1 = lst1.front;
  auto p2 = lst2.front;
  auto res_back = res.front;
  bool carry{false};
  while (p1 != nullptr && p2 != nullptr) {
    auto sum = p1->data + p2->data;
    std::tie(sum, carry) = calculateSumAndCarry(sum, carry);
    res_back = res.insert_after(res_back, sum);
    p1 = p1->next;
    p2 = p2->next;
  }
  while (p1 != nullptr) {
    auto sum = p1->data;
    std::tie(sum, carry) = calculateSumAndCarry(sum, carry);
    res_back = res.insert_after(res_back, sum);
    p1 = p1->next;
  }
  while (p2 != nullptr) {
    auto sum = p2->data;
    std::tie(sum, carry) = calculateSumAndCarry(sum, carry);
    res_back = res.insert_after(res_back, sum);
    p2 = p2->next;
  }
  if (carry) {
    res_back = res.insert_after(res_back, 1);
  }

  return res;
}

template <typename T>
using NodePtr = std::shared_ptr<typename LinkedList<T>::Node>;

template <typename T>
std::tuple<bool, NodePtr<T>> sumNodes(NodePtr<T> p1, NodePtr<T> p2, bool carry,
                                      std::shared_ptr<LinkedList<T>> pRes,
                                      NodePtr<T> inserter) {
  if (p1 != nullptr && p2 != nullptr) {
    std::tie(carry, inserter) =
        sumNodes(p1->next, p2->next, carry, pRes, inserter);
    auto sum = p1->data + p2->data;
    std::tie(sum, carry) = calculateSumAndCarry(sum, carry);
    inserter = pRes->insert(inserter, sum);
  }
  return {carry, inserter};
}

template <typename T>
std::tuple<bool, NodePtr<T>> SumListsFwd(LinkedList<T> const& lst1,
                                         LinkedList<T> const& lst2,
                                         std::shared_ptr<LinkedList<T>> pRes,
                                         NodePtr<T> inserter) {
  LinkedList<T> diff_digits;
  auto diff_digit_inserter = diff_digits.front;
  LinkedList<T> zero_digits;
  auto zero_digit_inserter = zero_digits.front;
  auto const& larger = lst1.size() > lst2.size() ? lst1 : lst2;
  auto const& smaller = lst1.size() > lst2.size() ? lst2 : lst1;
  auto p1 = larger.front;
  auto p2 = smaller.front;
  auto size_diff{larger.size() - smaller.size()};
  while (size_diff != 0) {
    diff_digit_inserter =
        diff_digits.insert_after(diff_digit_inserter, p1->data);
    zero_digit_inserter = zero_digits.insert_after(zero_digit_inserter, 0);
    p1 = p1->next;
    --size_diff;
  }
  bool carry{false};
  std::tie(carry, inserter) = sumNodes(p1, p2, carry, pRes, inserter);
  if (diff_digits.size() != 0) {
    if (carry) {
      zero_digit_inserter->data = 1;
    }
    std::tie(carry, inserter) =
        SumListsFwd(diff_digits, zero_digits, pRes, inserter);
  } else {
    if (carry) {
      inserter = pRes->insert(inserter, 1);
      carry = false;
    }
  }
  return {carry, inserter};
}

template <typename T>
LinkedList<T> SumListsFwdMain(LinkedList<T> const& lst1,
                              LinkedList<T> const& lst2) {
  auto res = std::make_shared<LinkedList<T>>();
  auto inserter = res->front;
  SumListsFwd(lst1, lst2, res, inserter);
  return *res;
}

int main() {
  std::vector<std::tuple<LinkedList<int>, LinkedList<int>>> testlist{
      {{7, 1, 6}, {5, 9, 2}},       {{6, 1, 7}, {2, 9, 5}},
      {{9, 7, 8}, {6, 8, 5}},       {{6, 1, 7}, {2, 9, 5, 1}},
      {{9, 9, 7, 1, 0}, {2, 9, 5}}, {{9, 9, 9, 9, 9}, {1}}};
  for (auto& [lst1, lst2] : testlist) {
    std::cout << "Rev: " << '\n'
              << lst1 << '+' << lst2 << '=' << SumListRev(lst1, lst2);
    std::cout << '\n';
    std::cout << "Fwd: " << '\n'
              << lst1 << '+' << lst2 << '=' << SumListsFwdMain(lst1, lst2);
    std::cout << '\n';
  }
  return 0;
}
