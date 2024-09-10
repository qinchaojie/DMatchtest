cpp_files := $(shell find src -name "*.cpp")
o_files := $(patsubst src/%.cpp, objs/%.o, $(cpp_files))

include_dirs := ./include# 头文件路径
link_libs := # 库的名字
link_dirs :=  # 库路径

I_options := $(include_dirs:%=-I%) # 头文件 编译选项
l_options := $(link_libs:%=-l%) # 库名 链接选项
L_options := $(link_dirs:%=-L%) # 库路径 链接选项
r_options := $(link_dirs:%=-Wl,-rpath=%) # 动态库 链接选项

compile_options = -O3 -g -w -std=c++14 $(I_options) # 编译选项
linking_options = $(l_options) $(L_options) $(r_options) # 链接选项

# 编译和链接
objs/%.o : src/%.cpp
	@echo "[INFO] compile $^ to $@"
	@mkdir -p $(dir $@)
	@g++ -c $^ -o $@ $(compile_options)

workspeace/exec : $(o_files)
	@echo "[INFO] link $^ to $@"
	@mkdir -p $(dir $@)
	@g++ $^ -o $@ $(linking_options)

run : workspeace/exec
	@./$<

clean :
	@$(shell rm -rf objs workspeace/exec)

debug :
	@echo $(I_options)
	@echo $(linking_options)

.PHONY : debug clean run