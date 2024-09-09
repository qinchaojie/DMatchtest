
cpp_files := $(shell find src -name "*.cpp")
o_files := $(patsubst src/%.cpp, objs/%.o, $(cpp_files))

# 编译选项

include_dirs := /22085400631/cpp/c++stores/lib-stores/opencv-3.4.8/include/opencv4/
link_libs := opencv_core opencv_imgcodecs opencv_imgproc# 库名字
link_dirs := /22085400631/cpp/c++stores/lib-stores/opencv-3.4.8/lib

I_options := $(include_dirs:%=-I%) # 头文件 编译选项
l_options := $(link_libs:%=-l%) # 库名 链接选项
L_options := $(link_dirs:%=-L%) # 库路径 链接选项

r_options := $(link_dirs:%=-Wl,-rpath=%) # 动态库 链接选项

compile_options = -O3 -g -w $(I_options) # 编译选项
linking_options = $(l_options) $(L_options) $(r_options) # 链接选项
# 编译
objs/%.o : src/%.cpp
	@echo "[INFO] compile $^ to $@"
	@mkdir -p $(dir $@)
	@g++ -c $^ -o $@ $(compile_options)


# 链接
workspeace/exec : $(o_files)
	@echo "[INFO] link $^ to $@"
	@mkdir -p $(dir $@)
	@g++ $^ -o $@ $(linking_options)

run : workspeace/exec
	@./$<

clean :
	@$(shell rm -rf objs workspeace/exec)

debug :
	@echo $(cpp_files)
	@echo $(o_files)
	@echo $(linking_options)

.PHONY : debug clean run