class Foo {
  condition_variable cv;
  int ready;
  mutex m;

public:
  Foo() { ready = 1; }

  void first(function<void()> printFirst) {
    unique_lock lock(m);
    cv.wait(lock, [&] { return ready == 1; });
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    ready = 2;
    cv.notify_all();
  }

  void second(function<void()> printSecond) {
    unique_lock lk(m);
    cv.wait(lk, [&] { return ready == 2; });
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    ready = 3;
    cv.notify_all();
  }

  void third(function<void()> printThird) {
    unique_lock lk(m);
    cv.wait(lk, [&] { return ready == 3; });
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }
};
