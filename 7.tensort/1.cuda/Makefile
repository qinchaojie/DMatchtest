# 定义cpp源码路径定义编译出来.o文件名和对应的存放路径
cpp_srcs := $(shell find src -name "*.cpp")
cpp_objs := $(patsubst %.cpp, %.o,$(cpp_srcs)) 
cpp_objs := $(subst src/,objs/,$(cpp_objs))

# 定义cu源码路径定义编译出来cuo文件名和对应的存放路径
cu_srcs := $(shell find src -name "*.cu")
cu_objs := $(patsubst %.cu,%.cuo,$(cu_srcs))
cu_objs := $(subst src/,objs/,$(cu_objs))

# 定义名称参数
workspace := workspace
binary := pro

# 定义头文件库文件和链接目标，后面用foreach一次性增加
include_paths := /usr/local/cuda-11.4/include src
library_paths := /usr/local/cuda-11.4/lib64
link_librarys := cudart

# 定义编译选项
cpp_compile_flags := -m64 -fPIC -g -O0 -std=c++11
cu_compile_flags := -m64 -g -O0 -std=c++11

# foreach一次性添加头文件，库文件，链接器目标, rpath: 查找文件路径 
rpath         := $(foreach item,$(link_librarys),-Wl,-rpath=$(item))
include_paths := $(foreach item,$(include_paths),-I$(item))
library_paths := $(foreach item,$(library_paths),-L$(item))
link_librarys := $(foreach item,$(link_librarys),-l$(item))

# 合并选项后丢给编译方式
cpp_compile_flags += $(include_paths)
cu_compile_flags += $(include_paths)
link_flags := $(rpath) $(library_paths) $(link_librarys)

# 定义cpp文件的编译方式，依赖项是*.cpp, 生成项是*.o 
objs/%.o : src/%.cpp
	@mkdir -p $(dir $@)
	@echo 编译 $^
	@g++ -c $< -o $@ $(cpp_compile_flags)


# 定义cu文件的编译方式，依赖项是*.cu,生成项是*.cuo
objs/%.cuo : src/%.cu
	@mkdir -p $(dir $@)
	@echo 编译 $^
	@nvcc -c $< -o $@ $(cu_compile_flags)

# 定义workspace/pro文件的编译, 依赖项是*.o,*.cuo文件
$(workspace)/$(binary) : $(cpp_objs) $(cu_objs)
	@mkdir -p $(dir $@)
	@echo 链接 $^
	@g++ $^ -o $@ $(link_flags) -L./objs

# 定义生成可执行文件的快捷指令
pro : $(workspace)/$(binary) 

# 定义执行可执行文件的快捷指令
run : pro 
	@cd $(workspace) && ./$(binary)

debug :
	@echo $(cpp_objs)
	@echo $(cu_objs)

clean : 
	@rm -rf objs $(workspace)/$(binary)

# 指定伪标签，作为指令
.PHONY : clean debug run pro