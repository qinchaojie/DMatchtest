// C++98 管理权转移 auto_ptr

#include <iostream>
#include <memory>
using namespace std;


// C++11 库才更新智能指针实现
// C++11 出来之前，boost 搞出了更好用的 scoped_ptr/shared_ptr/weak_ptr
// C++11 将 boost 库中智能指针精华部分吸收了过来
// C++11 -> unique_ptr/shared_ptr/weak_ptr

// unique_ptr/scoped_ptr
// 原理：简单粗暴 -- 防止拷贝
namespace tjq
{
	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr)
			: _ptr(ptr)
		{}

		unique_ptr(const unique_ptr<T>& ap) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>& ap) = delete;

		~unique_ptr()
		{
			cout << "delete: " << _ptr << endl;
			delete _ptr;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

	private:
		T* _ptr;
	};
}

int main()
{
	// tjq::unique_ptr<int> sp1(new int);
	// tjq::unique_ptr<int> sp2(sp1);

	std::unique_ptr<int> sp1(new int);
	std::unique_ptr<int> sp2(std::move(sp1));

	return 0;
}

