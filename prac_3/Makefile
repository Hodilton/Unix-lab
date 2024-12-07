DIR_BUILD = ./bin
DIR_TASK1 = ./task_mutex
DIR_TASK2 = ./task_semaphore
DIR_TASK3 = ./task_condition
DIR_SRC = ./src


all:
	$(MAKE) create_dir
	$(MAKE) -C $(DIR_TASK1)
	$(MAKE) -C $(DIR_TASK2)
	$(MAKE) -C $(DIR_TASK3)
	$(MAKE) -C $(DIR_SRC)

clean: 
	$(MAKE) -C $(DIR_TASK1) clean
	$(MAKE) -C $(DIR_TASK2) clean
	$(MAKE) -C $(DIR_TASK3) clean
	$(MAKE) -C $(DIR_SRC) clean
	$(MAKE) remove_dir

create_dir:
	mkdir -p $(DIR_BUILD)

remove_dir:
	rm -rf $(DIR_BUILD)