
cpp_srcs = $(shell find src -name "*.cpp") # 所有的cpp文件路径
cpp_objs = $(patsubst src/%.cpp,objs/%.o,$(cpp_srcs)) # 编译成二进制文件

# 创建依赖关系，
objs/%.o : src/%.cpp
 	# $@ 获取前面的所有的路径, 创建文件	# 编译成二进制文件$^  所有的依赖项
	@mkdir -p $(dir $@)
	@g++ -c $^ -o $@

# 连接创建可执行文件
workspeace/exec : $(cpp_objs)
	@mkdir -p $(dir $@)
	@g++ $^ -o $@

# 执行可执行文件, $<是依赖项第一个
run : workspeace/exec
	@./$<    

debug :
	@echo $(cpp_srcs)
	@echo $(cpp_objs)

.PHONY :  run debug

