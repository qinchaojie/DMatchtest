
MAIN   := Examples/main.cpp
MAIN.o := objs/main.o

cpp_srcs := $(shell find src -name "*.cpp")
cpp_objs := $(patsubst src/%.cpp,objs/%.o,$(cpp_srcs))


include_dirs := ./include

I_options := $(include_dirs:%=-I%)


compile_options := -g -O3 -w -std=c++14 $(I_options)

$(MAIN.o) : $(MAIN)
	@echo [INFO]: Compile $< to $@
	@mkdir -p $(dir $@)
	@g++ -c $< -o $@ $(compile_options) 

objs/%.o : src/%.cpp
	@echo [INFO]: Compile $^ to $@
	@mkdir -p $(dir $@)
	@g++ -c $^ -o $@ $(compile_options) $(dynamic_options)




workspace/exec : $(cpp_objs) $(MAIN.o) 
	@echo [INFO]: Link $< to $@
	@mkdir -p $(dir $@)
	@g++ $^ -o $@  # all compile

run : workspace/exec
	@./$< 


debug :
	@echo $(MAIN)
	@echo $(MAIN.o)

clean :
	@rm -rf objs lib workspace/exec


.PHONY : run clean debug dynamic