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
  