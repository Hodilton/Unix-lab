DIR_BUILD = ./bin
DIR_TASK1 = ./task_1
DIR_TASK2 = ./task_2
DIR_SRC = ./src


all:
	$(MAKE) create_dir
	$(MAKE) -C $(DIR_TASK1)
	$(MAKE) -C $(DIR_TASK2)
	$(MAKE) -C $(DIR_SRC)

clean: 
	$(MAKE) -C $(DIR_TASK1) clean
	$(MAKE) -C $(DIR_TASK2) clean
	$(MAKE) -C $(DIR_SRC) clean
	$(MAKE) remove_dir

create_dir:
	mkdir -p $(DIR_BUILD)

remove_dir:
	rm -rf $(DIR_BUILD)