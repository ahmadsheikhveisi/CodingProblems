/* COPYRIGHT
 */

#include <atomic>
#include <chrono>
#include <future>
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

class Worker {
 public:
  Worker() : mutex_{}, ready{false}, temp_async{} {}

  void Start() {
    temp_async = std::async(std::launch::async, [&]() { background_worker(); });
  }

  bool IsReady() const { return ready; }

 private:
  void background_worker() {
    constexpr int64_t sleep_duration{100};
    constexpr uint32_t count{10};
    uint32_t num{count};
    while (num > 0) {
      std::this_thread::sleep_for(std::chrono::milliseconds(sleep_duration));
      std::cout << num << "---Not ready yet!\n";
      --num;
    }
    ready = true;
    std::cout << "---Done!\n";
  }

  std::mutex mutex_;
  std::atomic<bool> ready;
  std::future<void> temp_async;
};

int main() {
  constexpr int64_t sleep_duration{150};
  std::cout << "creating obj\n";
  auto obj = std::make_unique<Worker>();
  std::this_thread::sleep_for(std::chrono::milliseconds(sleep_duration));
  std::cout << "obj created\n";
  {
    std::cout << "Running...\n";
    obj->Start();
    std::this_thread::sleep_for(std::chrono::milliseconds(sleep_duration));
  }
  std::cout << "exited scope\n";
  while (true) {
    // std::this_thread::sleep_for();
    // if (temp_async.wait_for(std::chrono::milliseconds(sleep_duration)) ==
    //    std::future_status::ready) {
    std::this_thread::sleep_for(std::chrono::milliseconds(sleep_duration));
    if (obj->IsReady()) {
      std::cout << "Yes\n";
      break;
    } else {
      std::cout << "No\n";
    }
  }
  return 0;
}
