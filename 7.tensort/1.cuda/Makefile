

file_cu = $(shell find src -name "*.cu")



workspeace/exec : $(file_cu)
	@echo "compile $^ to $@"
	@mkdir $(dir $@)
	@nvcc $^ -o $@


run : workspeace/exec
	@./$<

debug :
	@echo $(file_cu)

clean :
	@$(shell rm -r ./workspeace)

.PHONY : run debug clean