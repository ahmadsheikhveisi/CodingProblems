# Points

* Note: case insensive, ignore white space, ASCII, UTF8
* Palindrome has an even occurance of all charactors, except
  it can have only one odd occurance.
* 00010000 - 1 = 00001111
* 00101000 - 1 = 00100111

* count if: count the elements between two iterators that satisfy a
 condition.

* string find returns the index and it can be npos

* Mind the end of string, when searching.

* 'remove' moves up the elements in the sequence, overwriting the element
  you wanted removed. (find and move)
* 'erase' overwrite the elements and resize the sequence.
* remove-erase idiom: to remove the matching elements from the container.
* remove is independent of the container while erase depends how the
  data is stored.

* inlining the ostream& operator<<(ostream& out, classtemplate) is the best
  way.

* structured binding auto [a, b] = std::tuple
  to use current variables: std::tie(a,b, _) = std::tuple

* in linked lists, if you can use the size, you can acheive O(1) space
  complexity. otherwise, recursion gives O(N) space complexity. don't forget
  the runner approach.

* to get the coredumps first add "* - core unlimited" to
 /etc/security/limits.conf
* change /proc/sys/kernel/core_pattern. | at the
 begining means core dump is directed to stdout
* sudo su
* echo "/var/crash/core-%e-%p-%t" > /proc/sys/kernel/core_pattern
 or premanently under /etc/sysctl.conf
* kernel.core_pattern=/tmp/cores/core.%e.%p.%h.%t
* remember %e truncates the filename to 15 chars
 then you need a proper launch config
* Don't push_back in the range-loop over the vector
* you can't have std::optional< with the same type> as a member variable
* it is not possible to have a vector of references. you need reference wrapper.
* To access a method in dependent type base, you need this->. otherwise the type is not deduced.
* Mind the left shift overflow. gcc masks the left shift with 31 meaning any shift larger than
32 will have no effect. byte << (count - 1) check if count is zero
* std::byte is a replacement for uint8_t, but it is an enum class
* "If the operand passed to an arithmetic operator is integral or unscoped enumeration type, then before any other action (but after lvalue-to-rvalue conversion, if applicable), the operand undergoes integral promotion."
* P(B and A) = P(B given A) P(A) ; if A and B are independent (one can't say anything about the other), P(B given A) = P(B)
* P(B or A) = P(B) + P(A) - P(B and A) ; if A and B are mutually exclusive (if one happens the other can't), P(B and A) = 0
* Two events can't be both independent and mutually exclusive if both have non-zero probability.
* The key in many maximizing/minimizing problems is "worst cast balancing".
